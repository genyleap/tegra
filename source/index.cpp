//! Tegra's Index.
#ifdef __has_include
# if __has_include("index.hpp")
#   include "index.hpp"
#else
#   error "Tegra's index was not found!"
# endif
#endif

//! Tegra's Installer/Setup.
#ifdef __has_include
# if __has_include("installer/setup.hpp")
#   include "installer/setup.hpp"
#else
#   error "Tegra's installer/setup was not found!"
# endif
#endif

//! Tegra's Core.
#ifdef __has_include
# if __has_include(<core>)
#   include <core>
#else
#   error "Tegra's core was not found!"
# endif
#endif

//! Tegra's Template.
#ifdef __has_include
# if __has_include(<template>)
#   include <template>
#else
#   error "Tegra's template was not found!"
# endif
#endif

//! Tegra's Database.
#ifdef __has_include
# if __has_include(<database>)
#   include <database>
#else
#   error "Tegra's database was not found!"
# endif
#endif

//!Tegra
TEGRA_USING_NAMESPACE Tegra;
TEGRA_USING_NAMESPACE Tegra::System;
TEGRA_USING_NAMESPACE Tegra::Database;
TEGRA_USING_NAMESPACE Framework;

TEGRA_NAMESPACE_BEGIN(Pages)

void Home::index(const Framework::HttpRequestPtr& req, std::function<void(const HttpResponsePtr &)>&& callback) const
{
    auto engine = Engine();

    Scope<ApplicationData> appDataPtr(new ApplicationData());
    {
        appDataPtr->path            = req->getPath();
        appDataPtr->module          = "index";
        appDataPtr->templateId      = "templates::user::home";
        appDataPtr->templateErrorId = "templates::user::error";
    }

    ///!Installer
    Installer::InstallerData installerData;
    installerData.level = Installer::SetupLevel::Install;
    Scope<Installer::Setup> installer(new Installer::Setup(*appDataPtr, installerData));

    //Installer::SetupLevelInfo setupLevelInfo;

    if(installer->installation())
    {
        auto resp = HttpResponse::newHttpResponse();
        for(const auto& c : installer->requirementList())
        {
            //std::cout << c.first << ":" << c.second << std::endl;
        }

        
        
        
        std::cout << "name:" << installer->setupLevelInfo().name.value() << std::endl;
        std::cout << "title:" << installer->setupLevelInfo().title.value() << std::endl;



        std::map<std::string, bool> apps{};
        apps.insert(std::pair<std::string, bool>("core", false));
        apps.insert(std::pair<std::string, bool>("blog", false));
        apps.insert(std::pair<std::string, bool>("statics", false));
        installer->application(apps);
        std::string key{};
        std::string value{};
        std::string checkMode{};
        std::string enableMode{};
        std::string r;

        Installer::SetupAppData setupAppData{};

        for(const auto& appList : installer->defaultAppsList())
        {
            if(appList.first == "core" || appList.first == "blog" || appList.first == "statics") {
                setupAppData.status = false;
            } else {
                setupAppData.status = true;
            }

            setupAppData.name = appList.first;
            setupAppData.value = appList.second;

            key = appList.first;
            value = appList.second ? "1" : "0";
            checkMode = appList.second ? "checked" : "";
            enableMode = setupAppData.status ? "" : "disabled";
            r += "<input type=\"checkbox\" value=\"" + value + "\" name=\"" + key + " \" " + checkMode + " " + enableMode + "/>";
        }
        
        resp->setBody(r);

        for(const auto& i : installer->installableApps())
        {
            std::cout << i.first << ":" << i.second << std::endl;
        }
        
        callback(resp);

    } else {

        Scope<Multilangual::Language> languagePtr(new Multilangual::Language(appDataPtr->path.value()));

        Scope<Template> theme(new Template(UserType::User, *appDataPtr)); // Set user type for remplate.

        Scope<LoadListTemplate>templateList(new LoadListTemplate(languagePtr->getLanguage(), appDataPtr->path.value()));

        //!Set the current path to language based on path.
        engine.langsByPath(__tegra_null_str);

        //!Check the page path for find by language.
        auto page = std::find(std::begin(engine.langUri), std::end(engine.langUri), appDataPtr->path.value());
        if (page != std::end(engine.langUri))
        {
            engine.setIsMultilanguage(true);
        }

        theme->staticMeta->setDefault(languagePtr->getLanguage()); //Getting default meta data for home page!


        /* Custom Translate Section */
        theme->viewData.insert("title",        templateList->title().value_or(TEGRA_TRANSLATOR("global", "name")));
        theme->viewData.insert("description",  templateList->description().value_or(TEGRA_TRANSLATOR("global", "slogan_desc")));
        theme->viewData.insert("copyright", TEGRA_TRANSLATOR("sideblock", "copyright"));
        theme->viewData.insert("home", TEGRA_TRANSLATOR("menu", "home"));
        theme->viewData.insert("feature", TEGRA_TRANSLATOR("menu", "features"));
        theme->viewData.insert("contact", TEGRA_TRANSLATOR("menu", "contactus"));
        theme->viewData.insert("source", TEGRA_TRANSLATOR("menu", "source"));

        /* Dynamic Translate Section */
        SheetType sheets {"global", "dialog", "account"};
        for(const auto& key : sheets) {
            for(const auto& s : engine.translator->data(key)) {
                if(s.first == engine.getLanguage()) {
                    theme->viewData.insert(s.second.first, s.second.second);
                }
            }
        }


        if (engine.isMultilanguage() && IsConnected)
        {
            //Multi-Language logic code here...
            auto resp = HttpResponse::newHttpViewResponse(appDataPtr->templateId.value(), theme->viewData);
            callback(resp);
        } else if(appDataPtr->path == "/" && IsConnected)
        {
            //Single-Language logic code here...
            auto resp = HttpResponse::newHttpViewResponse(appDataPtr->templateId.value(), theme->viewData);
            callback(resp);
        } else {
            auto resp = HttpResponse::newHttpViewResponse(appDataPtr->templateId.value(), theme->viewData);
            callback(resp);
        }
    }

}


TEGRA_NAMESPACE_END
