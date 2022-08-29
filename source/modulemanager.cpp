#include "modulemanager.hpp"
#include "core/logger.hpp"

TEGRA_USING_NAMESPACE Tegra;
TEGRA_USING_NAMESPACE Tegra::System;
TEGRA_USING_NAMESPACE Tegra::eLogger;

#if defined(PLATFORM_MAC) || defined(PLATFORM_LINUX)
#include <dlfcn.h>
#elif defined(PLATFORM_WINDOWS)
#include <Windows.h>
#endif

using ModuleMap  =  std::map<std::string, AbstractModule*>;

using LibraryMap =  std::map<std::string, void*>;

class ModuleManagerPimpl
{
public:
    ModuleMap m_modules;
    LibraryMap m_libs;
};

ModuleManager::ModuleManager()
{
    m_implementation = CreateScope<ModuleManagerPimpl>();
}

ModuleManager::~ModuleManager()
{
}

ModuleManager& ModuleManager::instance()
{
    static ModuleManager moduleManager;
    return moduleManager;
}

__tegra_no_discard AbstractModule* ModuleManager::load(const std::string& name)
{
    AbstractModule* module = nullptr;
    ModuleMap::iterator iter = m_implementation->m_modules.find(name);
    try {
        if (iter == m_implementation->m_modules.end())
        {
            // Try to load the module library
#if defined(PLATFORM_WINDOWS)
            void *hModule;
            hModule = LoadLibraryW(name.c_str());
#elif defined(PLATFORM_MAC)
            void *hModule;
            hModule = dlopen(name.c_str(), RTLD_LAZY);
#elif defined(PLATFORM_LINUX)
            void *hModule;
            hModule = dlopen(name.c_str(), RTLD_LAZY);
#endif
            if (hModule != nullptr)
            {
#if defined(PLATFORM_WINDOWS)
                fnCreateModule CreateModule = (fnCreateModule)GetProcAddress(hModule, "CreateModule");
#elif defined(PLATFORM_MAC)
                fnCreateModule CreateModule = (fnCreateModule)dlsym(hModule, "CreateModule");
#elif defined(PLATFORM_LINUX)
                fnCreateModule CreateModule = (fnCreateModule)dlsym(hModule, "CreateModule");
#endif
                if (CreateModule != nullptr)
                {
                    // Invoke the function to get the module from the DLL.
                    module = CreateModule();
                    if (module != nullptr)
                    {
                        //module->setName(moduleName); set real name not a name!
                        // Add the module and library18 to the maps.
                        m_implementation->m_modules.insert(ModuleMap::value_type(name, module));
                        m_implementation->m_libs.insert(LibraryMap::value_type(name, hModule));
                    }
                    else
                    {
                        Log("ERROR: Could not load module from " + name.c_str(), LoggerType::Critical);
                        // Unload the library.
#if defined(PLATFORM_WINDOWS)
                        FreeLibrary(hModule);
#elif defined(PLATFORM_MAC)
                        dlclose(hModule);
#elif defined(PLATFORM_LINUX)
                        dlclose(hModule);
#endif
                    }
                }
                else
                {
                    Log("ERROR: Could not find symbol \"CreateModule\" in " + name.c_str(), LoggerType::Critical);
#if defined(PLATFORM_WINDOWS)
                    FreeLibrary(hModule);
#elif defined(PLATFORM_MAC)
                    dlclose(hModule);
#elif defined(PLATFORM_LINUX)
                    dlclose(hModule);
#endif
                }
            }
            else
            {
                Log("ERROR: Could not load module library: " + name.c_str(), LoggerType::Critical);
                m_status = {false};
            }
        }
        else
        {
            Log("INFO: Module: " + name.c_str() + " already loaded.", LoggerType::Info);
            module = iter->second;
            m_status = {true};
        }

    } catch (...) {
    }
    return module;
}

void ModuleManager::unload(AbstractModule *&module)
{
    if (module != nullptr)
    {
        LibraryMap::iterator iter = m_implementation->m_libs.find(module->getName().value());
        if(iter != m_implementation->m_libs.end())
        {
            // Remove the module from our module map.
            m_implementation->m_modules.erase(module->getName().value());
            void* hModule = iter->second;
#if defined(PLATFORM_WINDOWS)
            fnDestroyModule DestroyModule = (fnDestroyModule)GetProcAddress(hModule, "DestroyModule");
#elif defined(PLATFORM_MAC)
            fnDestroyModule DestroyModule = (fnDestroyModule)dlsym(hModule, "DestroyModule");
#elif defined(PLATFORM_LINUX)
            fnDestroyModule DestroyModule = (fnDestroyModule)dlsym(hModule, "DestroyModule");
#endif
            if (DestroyModule != nullptr)
            {
                DestroyModule();
            }
            else
            {
                Log("ERROR: Unable to find symbol \"DestroyModule\" in library " + module->getName().value().c_str(, LoggerType::Critical);
            }
            // Unload the library and remove the library from the map.
#if defined(PLATFORM_WINDOWS)
            FreeLibrary(hModule);
#elif defined(PLATFORM_MAC)
            dlclose(hModule);
#elif defined(PLATFORM_LINUX)
            dlclose(hModule);
#endif
            m_implementation->m_libs.erase(iter);
        }
        else
        {
            Log("WARNING: Trying to unload a module that is already unloaded or has never been loaded.", LoggerType::Warning);
        }
        module = nullptr;
    }
}

__tegra_no_discard bool ModuleManager::isLoaded()
{
    return m_status;
}
