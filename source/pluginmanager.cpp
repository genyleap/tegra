//! Tegra's Pluginmanager.
#ifdef __has_include
# if __has_include("pluginmanager.hpp")
#   include "pluginmanager.hpp"
#else
#   error "Tegra's pluginmanager was not found!"
# endif
#endif

//! Tegra's eLogger.
#ifdef __has_include
# if __has_include(<logger>)
#   include <logger>
#else
#   error "Tegra's logger was not found!"
# endif
#endif

TEGRA_USING_NAMESPACE Tegra;
TEGRA_USING_NAMESPACE Tegra::System;
TEGRA_USING_NAMESPACE Tegra::eLogger;

#if defined(PLATFORM_MAC) || defined(PLATFORM_LINUX)
#include <dlfcn.h>
#elif defined(PLATFORM_WINDOWS)
#include <Windows.h>
#endif

using PluginMap  =  std::map<std::string, AbstractPlugin*>;

using LibraryMap =  std::map<std::string, void*>;

class PluginManagerPimpl
{
public:
    PluginMap m_plugins;
    LibraryMap m_libs;
};

PluginManager::PluginManager()
{
    m_implementation = CreateScope<PluginManagerPimpl>();
}

PluginManager::~PluginManager()
{

}

PluginManager& PluginManager::instance()
{
    static PluginManager pluginManager;
    return pluginManager;
}

__tegra_no_discard AbstractPlugin* PluginManager::load(const std::string& name)
{
    AbstractPlugin* plugin = nullptr;
    PluginMap::iterator iter = m_implementation->m_plugins.find(name);
    try {
        if (iter == m_implementation->m_plugins.end())
        {
            // Try to load the plugin library
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
                fnCreatePlugin CreatePlugin = (fnCreatePlugin)GetProcAddress(hModule, "CreatePlugin");
#elif defined(PLATFORM_MAC)
                fnCreatePlugin CreatePlugin = (fnCreatePlugin)dlsym(hModule, "CreatePlugin");
#elif defined(PLATFORM_LINUX)
                fnCreatePlugin CreatePlugin = (fnCreatePlugin)dlsym(hModule, "CreatePlugin");
#endif

                if (CreatePlugin != nullptr)
                {
                    // Invoke the function to get the plugin from the DLL.
                    plugin = CreatePlugin();

                    if (plugin != nullptr)
                    {
                        //plugin->setName(pluginName); set real name not a name!
                        // Add the plugin and library18 to the maps.
                        m_implementation->m_plugins.insert(PluginMap::value_type(name, plugin));
                        m_implementation->m_libs.insert(LibraryMap::value_type(name, hModule));
                    }
                    else
                    {
                        Log("ERROR: Could not load plugin from " + FROM_TEGRA_STRING(name.c_str()), LoggerType::Critical);
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
                    Log("ERROR: Could not find symbol \"CreatePlugin\" in " + FROM_TEGRA_STRING(name.c_str()), LoggerType::Critical);
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
                Log("ERROR: Could not load library: " + FROM_TEGRA_STRING(name.c_str()), LoggerType::Critical);
                m_status = {false};
            }
        }
        else
        {
            Log("INFO: Library \"" + FROM_TEGRA_STRING(name.c_str()) + "\" already loaded.", LoggerType::Info);
            plugin = iter->second;
            m_status = {true};
        }

    } catch (...) {
    }
    return plugin;
}

void PluginManager::unload(AbstractPlugin *&plugin)
{
    if (plugin != nullptr)
    {
        LibraryMap::iterator iter = m_implementation->m_libs.find(plugin->getName().value());
        if(iter != m_implementation->m_libs.end())
        {
            // Remove the plugin from our plugin map.
            m_implementation->m_plugins.erase(plugin->getName().value());
            void* hModule = iter->second;
#if defined(PLATFORM_WINDOWS)
            fnDestroyPlugin DestroyPlugin = (fnDestroyPlugin)GetProcAddress(hModule, "DestroyPlugin");
#elif defined(PLATFORM_MAC)
            fnDestroyPlugin DestroyPlugin = (fnDestroyPlugin)dlsym(hModule, "DestroyPlugin");
#elif defined(PLATFORM_LINUX)
            fnDestroyPlugin DestroyPlugin = (fnDestroyPlugin)dlsym(hModule, "DestroyPlugin");
#endif
            if (DestroyPlugin != nullptr)
            {
                DestroyPlugin();
            }
            else
            {
                Log("ERROR: Unable to find symbol [DestroyPlugin] in library " + FROM_TEGRA_STRING(plugin->getName().value().c_str()), LoggerType::Critical);
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
            Log("WARNING: Trying to unload a plugin that is already unloaded or has never been loaded.", LoggerType::Warning);
        }
        plugin = nullptr;
    }
}

__tegra_no_discard bool PluginManager::isLoaded()
{
    return m_status;
}
