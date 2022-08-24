#include "index.hpp"
#include "core/core.hpp"
#include "core/template.hpp"
#include "core/database.hpp"

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


TEGRA_NAMESPACE_END
