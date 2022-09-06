//! Tegra's Index.
#ifdef __has_include
# if __has_include("index.hpp")
#   include "index.hpp"
#else
#   error "Tegra's index was not found!"
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

//! Tegra's Config.
#ifdef __has_include
# if __has_include(<config>)
#   include <config>
#else
#   error "Tegra's config was not found!"
# endif
#endif

//! Tegra's Template.
#ifdef __has_include
# if __has_include(<templates>)
#   include <templates>
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

//! Tegra's View.
#ifdef __has_include
# if __has_include(<view>)
#   include <view>
#else
#   error "Tegra's view was not found!"
# endif
#endif

//!Tegra
TEGRA_USING_NAMESPACE Tegra;
TEGRA_USING_NAMESPACE Tegra::System;
TEGRA_USING_NAMESPACE Tegra::View;
TEGRA_USING_NAMESPACE Tegra::Database;
TEGRA_USING_NAMESPACE Framework;

TEGRA_NAMESPACE_BEGIN(Tegra::Default)

void DefIndex::index(const HttpRequestPtr& req, std::function<void(const HttpResponsePtr &)>&& callback) __tegra_const
{
    auto engine = Engine();

    Scope<ApplicationData> appDataPtr(new ApplicationData());

    auto config = Configuration(ConfigType::File);

    config.init(SectionType::SystemCore);

    {
        appDataPtr->path                    =   req->getPath();                     // Path
        appDataPtr->module                  =   SYSTEM_VIEW_INDEX::INDEX.data();    // Index, Preinstall
        appDataPtr->templateViewId          =   __tegra_null_str;                   // User Root {templates::{user}}
        appDataPtr->templateViewErrorId     =   __tegra_null_str;                   // User Root {templates::{user}}

        if(!isset(config.isInstalled())) {
            for(const auto& t : engine.viewIndex->defaultView(UserViewType::User))
            {
                std::clog << t.second << std::endl;
                if(t.first == "preinstall") appDataPtr->templateViewId->append(t.second);
                if(t.first == "error") appDataPtr->templateViewErrorId->append(t.second);
            }
        } else {
            for(const auto& t : engine.viewIndex->defaultView(UserViewType::User))
            {
                if(t.first == "home") appDataPtr->templateViewId->append(t.second);
                if(t.first == "error") appDataPtr->templateViewErrorId->append(t.second);
            }
        }
    }

    PageProperties pageProperties;
    pageProperties.id = 1;
    pageProperties.title = "Page Zero";
    pageProperties.accessByApi = true;
    pageProperties.inclueInSitemap = false;
    pageProperties.priority  = 1;
    pageProperties.url = "install";

    auto pagez = Page(pageProperties);

    Application::get(*appDataPtr)->pageArchivePtr->registerPage(pagez);

    Scope<Template> theme(new Template(UserType::User, *appDataPtr)); // Set user type for remplate.

    Scope<Multilangual::Language> languagePtr(new Multilangual::Language(appDataPtr->path.value()));

    Scope<LoadListTemplate>templateList(new LoadListTemplate(languagePtr->getLanguage(), appDataPtr->path.value()));

    auto currentPath = appDataPtr->path.value();

    engine.langsByPath(__tegra_null_str);

    /* Check the page path for find by language. */
    auto page = std::find(std::begin(engine.langUri), std::end(engine.langUri), currentPath);
    if (page != std::end(engine.langUri)) {
        engine.setIsMultilanguage(true);
    }

    theme->staticMeta->setDefault(languagePtr->getLanguage()); //Getting default meta data for home page!

    theme->viewData.insert("meta", theme->staticMeta->metaData()); //!Metadata

    /* Custom Translate Section */
    theme->viewData.insert("title"          , templateList->title().value_or(TEGRA_TRANSLATOR("global", "name")));
    theme->viewData.insert("description"    , templateList->description().value_or(TEGRA_TRANSLATOR("global", "slogan_desc")));
    theme->viewData.insert("copyright"      , TEGRA_TRANSLATOR("sideblock", "copyright"));
    theme->viewData.insert("home"           , TEGRA_TRANSLATOR("menu", "home"));
    theme->viewData.insert("feature"        , TEGRA_TRANSLATOR("menu", "features"));
    theme->viewData.insert("contact"        , TEGRA_TRANSLATOR("menu", "contactus"));
    theme->viewData.insert("source"         , TEGRA_TRANSLATOR("menu", "source"));
    theme->viewData.insert("setup"          , TEGRA_TRANSLATOR("setup", "setup"));

    /* Dynamic Translate Section */
    SheetList sheets {"global", "dialog", "account"};
    languagePtr->registerSheet(sheets);
    auto l = languagePtr->getLanguageCode();
    for(const auto& key : languagePtr.get()->sheets())
    {
        for(const auto& s : Application::get(*appDataPtr)->translator->data(key))
        {
            if(s.first == l)
                theme->viewData.insert(s.second.first, s.second.second);
        }
    }

    if (engine.isMultilanguage() && IsConnected) {
        //Multi-Language logic code here...
        auto resp = HttpResponse::newHttpViewResponse(appDataPtr->templateViewId.value(), theme->viewData);
        callback(resp);
    } else if(currentPath == "/" && IsConnected) {
        //Single-Language logic code here...
        auto resp = HttpResponse::newHttpViewResponse(appDataPtr->templateViewId.value(), theme->viewData);
        callback(resp);
    } else {
        //Page not found!
        if(!isset(IsConnected)) {
            theme->viewData.insert("title",        templateList->title().value_or(TEGRA_TRANSLATOR("exceptions", "empty")));
            theme->viewData.insert("description",  templateList->description().value_or(TEGRA_TRANSLATOR("exceptions", "empty")));
            theme->viewData.insert("full_title",   templateList->fullSiteTitle().value_or(TEGRA_TRANSLATOR("exceptions", "empty")));
            theme->viewData.insert("copyright",    TEGRA_TRANSLATOR("sideblock", "copyright"));
            theme->viewData.insert("subject",      TEGRA_TRANSLATOR("exceptions", "db_connection_error"));
            theme->viewData.insert("image",        FROM_TEGRA_STRING("<svg xmlns=\"http://www.w3.org/2000/svg\" width=\"128\" height=\"128\" fill=\"currentColor\" class=\"bi bi-server\" viewBox=\"0 0 16 16\"> <path d=\"M1.333 2.667C1.333 1.194 4.318 0 8 0s6.667 1.194 6.667 2.667V4c0 1.473-2.985 2.667-6.667 2.667S1.333 5.473 1.333 4V2.667z\"/> <path d=\"M1.333 6.334v3C1.333 10.805 4.318 12 8 12s6.667-1.194 6.667-2.667V6.334a6.51 6.51 0 0 1-1.458.79C11.81 7.684 9.967 8 8 8c-1.966 0-3.809-.317-5.208-.876a6.508 6.508 0 0 1-1.458-.79z\"/> <path d=\"M14.667 11.668a6.51 6.51 0 0 1-1.458.789c-1.4.56-3.242.876-5.21.876-1.966 0-3.809-.316-5.208-.876a6.51 6.51 0 0 1-1.458-.79v1.666C1.333 14.806 4.318 16 8 16s6.667-1.194 6.667-2.667v-1.665z\"/> </svg>"));
            theme->viewData.insert("description",  TEGRA_TRANSLATOR("exceptions", "db_connection_error_desc"));
            theme->viewData.insert("goback",       TEGRA_TRANSLATOR("dialog", "goback"));

        } else {
            theme->viewData.insert("title",        templateList->title().value_or(TEGRA_TRANSLATOR("exceptions", "empty")));
            theme->viewData.insert("description",  templateList->description().value_or(TEGRA_TRANSLATOR("exceptions", "empty")));
            theme->viewData.insert("full_title",   templateList->fullSiteTitle().value_or(TEGRA_TRANSLATOR("exceptions", "empty")));
            theme->viewData.insert("copyright",    TEGRA_TRANSLATOR("sideblock", "copyright"));
            theme->viewData.insert("subject",      TEGRA_TRANSLATOR("exceptions", "page_not_found"));
            theme->viewData.insert("image",        FROM_TEGRA_STRING("<svg xmlns=\"http://www.w3.org/2000/svg\" width=\"128\" height=\"128\" fill=\"currentColor\" class=\"bi bi-x-circle-fill text-secondary\" viewBox=\"0 0 16 16\"><path d=\"M16 8A8 8 0 1 1 0 8a8 8 0 0 1 16 0zM5.354 4.646a.5.5 0 1 0-.708.708L7.293 8l-2.647 2.646a.5.5 0 0 0 .708.708L8 8.707l2.646 2.647a.5.5 0 0 0 .708-.708L8.707 8l2.647-2.646a.5.5 0 0 0-.708-.708L8 7.293 5.354 4.646z\"/></svg>"));
            theme->viewData.insert("description",  TEGRA_TRANSLATOR("exceptions", "page_not_found_desc"));
            theme->viewData.insert("goback",       TEGRA_TRANSLATOR("dialog", "goback"));
        }

        auto resp = HttpResponse::newHttpViewResponse(appDataPtr->templateViewErrorId.value(), theme->viewData);
        callback(resp);
    }

}

TEGRA_NAMESPACE_END
