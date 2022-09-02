//! Tegra's Template.
#ifdef __has_include
# if __has_include("template.hpp")
#   include "template.hpp"
#else
#   error "Tegra's template was not found!"
# endif
#endif

TEGRA_USING_NAMESPACE Tegra;
TEGRA_USING_NAMESPACE Tegra::SEO;
TEGRA_NAMESPACE_BEGIN(Tegra::System)

Template::Template(const UserType& usertype, const ApplicationData& appData) : utype(usertype)
{
    __tegra_safe_instance_rhs(staticMeta, StaticMeta, appData); //SEO
    //!Getting system language by redirecting url.
    languagePtr = CreateScope<Multilangual::Language>(appData.path.value());
    //! Create a new instance of the class Configuration
    Scope<Configuration>config(new Configuration(ConfigType::File));
    {
        config->init(SectionType::SystemCore);
    }

    Scope<Engine> engine(new Engine());

    Scope<ApplicationData> appDataPtr(new ApplicationData());
    {
        appDataPtr->path            = appData.path;
        appDataPtr->module          = "index";
    }

    auto baseUrl = config->getBaseUrl();
    //!Check the direction of template.
    std::string direction{};
    for(auto c : Configuration::GET[TEGRA_LANGS])
    {
        if(STRCOMBINER(c, "uri") == appData.path.value().substr(1, 5))
        {
            direction = STRCOMBINER(c, "direction");
        } else {
            if(STRCOMBINER(c, "code") == Configuration::GET[TEGRA_DEFAULT_LANG])
            {
                direction = STRCOMBINER(c, "direction");
            }
        }
    }
    for(auto c : Configuration::GET["langs"])
    {
        if(STRCOMBINER(c, "uri") == appData.path.value().substr(1, 5))
        {
            direction = STRCOMBINER(c, "direction");
            if(direction == "rtl") {
                systemSheet.push_back(FROM_TEGRA_STRING("body {font-family: Samim, sans-serif; direction: rtl; }"));
            } else {
                systemSheet.push_back(FROM_TEGRA_STRING("body { direction: ltr; }"));
            }
        }
    }
    //! Default static page link setting.
    linkSheet.push_back("<link rel=\"apple-touch-icon\" href=\"" + baseUrl + "/templates/assets/images/favicons/favicon.ico\" sizes=\"180x180\">");
    linkSheet.push_back("<link rel=\"icon\" href=\"" + baseUrl + "/templates/assets/images/favicons/favicon-16x16.png\" sizes=\"16x16\" type=\"image/png\">");
    linkSheet.push_back("<link rel=\"icon\" href=\"" + baseUrl + "/templates/assets/images/favicons/favicon-32x32.png\" sizes=\"32x32\" type=\"image/png\">");
    linkSheet.push_back("<link rel=\"manifest\" href=\"" + baseUrl + "/templates/assets/images/favicons/manifest.json\">");
    linkSheet.push_back("<link rel=\"mask-icon\" href=\"" + baseUrl + "/templates/assets/images/favicons/safari-pinned-tab.svg\">");
    linkSheet.push_back("<link rel=\"icon\" href=\"" + baseUrl + "/templates/assets/images/favicons/favicon.ico\">");

    /* =====================================================================================================================================
    / A content delivery network (CDN) refers to a geographically distributed group of servers which work together to provide fast delivery of Internet content.
    / A CDN allows for the quick transfer of assets needed for loading Internet content including HTML pages, javascript files, stylesheets, images, and videos.
    / The popularity of CDN services continues to grow, and today the majority of web traffic is served through CDNs, including traffic from major sites like Facebook, Netflix, and Amazon.
    / Here we can get the cdn mode from the system core to config and auto generation files inside site pages.
    / ==============================================System has two option CDN and Local model==============================================
    / 1) If the configuration variable in the setting file is [system->cdn] == true, then cdn delivery will be enabled.
    / 2) Local-Self Hosted: If the CDN mode is not enabled, then all content delivery files will be loaded from the self-hosting mode.
    / ===================================================================================================================================== */
    if(isset(Configuration::GET["system"]["cdn"].asBool()))
    {
        //!Engine
        for(const auto& var : Configuration::GET["templates"]["engine"])
        {
            for(const auto& array : var["css"])
            {
                if(engine->isMultilanguage())
                {
                    if(array["type"] == "cdn" && array["direction"] == direction && array["status"] == true)
                        styleSheet.push_back(FROM_TEGRA_STRING(array["value"].asString()));
                } else {
                    if(array["type"] == "cdn" && array["direction"] == direction && array["status"] == true)
                        styleSheet.push_back(FROM_TEGRA_STRING(array["value"].asString()));
                }
            }
            for(const auto& array : var["js"]) {
                if(array["type"] == "cdn" && array["status"] == true)
                {
                    javaScript.push_back(FROM_TEGRA_STRING(array["value"].asString()));
                }
            }
        }
        //!Third-Party
        for(const auto& var : Configuration::GET["templates"]["thirdparty"])
        {
            for(const auto& array : var["css"])
            {
                if(engine->isMultilanguage())
                {
                    if(array["type"] == "cdn" && array["direction"] == direction && array["status"] == true)
                        styleSheet.push_back(FROM_TEGRA_STRING(array["value"].asString()));
                } else {
                    if(array["type"] == "cdn" && array["direction"] == direction && array["status"] == true)
                        styleSheet.push_back(FROM_TEGRA_STRING(array["value"].asString()));
                }
            }
            for(const auto& array : var["js"]) {
                if(array["type"] == "cdn" && array["status"] == true)
                {
                    javaScript.push_back(FROM_TEGRA_STRING(array["value"].asString()));
                }
            }
        }
    } //!Self-Hosted Mode
    else {
        //!Engine
        for(const auto& var : Configuration::GET["templates"]["engine"])
        {
            for(const auto& array : var["css"])
            {
                if(engine->isMultilanguage()) {
                    if(array["type"] == "local" && array["direction"] == direction && array["status"] == true)
                        styleSheet.push_back(baseUrl + "/templates/" + FROM_TEGRA_STRING(array["value"].asString()));
                } else {
                    if(array["type"] == "local" && array["direction"] == direction && array["status"] == true)
                        styleSheet.push_back(baseUrl + "/templates/" + FROM_TEGRA_STRING(array["value"].asString()));
                }
            }
            for(const auto& array : var["js"]) {
                if(array["type"] == "local" && array["status"] == true)
                {
                    javaScript.push_back(baseUrl + "/templates/" + FROM_TEGRA_STRING(array["value"].asString()));
                }
            }
        }
        //!Third-Party
        for(const auto& var : Configuration::GET["templates"]["thirdparty"])
        {
            for(const auto& array : var["css"])
            {
                if(engine->isMultilanguage()) {
                    if(array["type"] == "local" && array["direction"] == direction && array["status"] == true) {
                        styleSheet.push_back(baseUrl + "/templates/" + FROM_TEGRA_STRING(array["value"].asString()));
                    }
                } else {
                    if(array["type"] == "local" && array["direction"] == direction && array["status"] == true) {
                        styleSheet.push_back(baseUrl + "/templates/" + FROM_TEGRA_STRING(array["value"].asString()));
                    }
                }
            }
            for(const auto& array : var["js"])
            {
                if(array["type"] == "local" && array["status"] == true)
                {
                    javaScript.push_back(baseUrl + "/templates/" + FROM_TEGRA_STRING(array["value"].asString()));
                }
            }
        }
    }
    //!Static Data
    viewData.insert("site-title", TEGRA_TRANSLATOR("global", "name"));
    viewData.insert("site-slogen", TEGRA_TRANSLATOR("global", "slogan"));
    viewData.insert("site-slogen-desc", TEGRA_TRANSLATOR("global", "slogan_desc"));
    //!Static Files
    viewData.insert("logo-user", baseUrl + "/templates/assets/images/logo/logo-user.svg");
    viewData.insert("logo-admin", baseUrl + "/templates/assets/images/logo/logo-admin.svg");
    //!Dynamic Generation
    viewData.insert(SYSTEM_THIRD_PARTY_CSS, styleSheet); //!CSS Files
    viewData.insert(SYSTEM_THIRD_PARTY_JAVASCRIPT, javaScript); //!JavaScript
    viewData.insert(SYSTEM_SYSTEM_SHEET, systemSheet); //!System Sheets
    viewData.insert(SYSTEM_LINK_SHEET, linkSheet); //!Links
    viewData.insert(SYSTEM_META_SHEET, staticMeta->metaData()); //!Metadata [SEO]
}


Template::~Template()
{
    __tegra_safe_delete(staticMeta);
}

bool Template::fileExist(const std::string& file)
{
    bool file_status;
    try {
        file_status = std::filesystem::exists(file);
    } catch (const std::system_error& e)
    {
        if(isset(DeveloperMode::IsEnable))
        {
            eLogger::Log("Template\t" + FROM_TEGRA_STRING(file) + "\twas not found!", eLogger::LoggerType::Info);
            eLogger::Log(e.what(), eLogger::LoggerType::Critical);
        }
    }
    if(const auto it = isset(file_status); it == true)
    {
        return true;
    } else {
        return false;
    }
    return false;
}

std::string Template::theme() const
{
    std::string t{};
    switch (utype)
    {
    //!Administrator Template
    case UserType::Admin:
        t = "/" + Source + "/" + Admin + "/";
        break;
        //!User Template
    case UserType::User:
        t = "/" + Source + "/" + User + "/";
        break;
        //!Moderator Template
    case UserType::Moder:
        t = "/" + Source + "/" + Moder + "/";
        break;
        //!Guest Template
    case UserType::Guest:
        t = "/" + Source + "/" + User + "/";
        break;
    default:
        break;
    }
    return t;
}

std::string Template::font() const
{
    return "fonts";
}
std::string Template::css() const
{
    return "css";
}
std::string Template::script() const
{
    return "js";
}

LoadListTemplate::LoadListTemplate(const std::string &l, const std::string &p)
{
  //ToDo...
}

LoadListTemplate::~LoadListTemplate()
{
  //ToDo...
}

void LoadListTemplate::setTitle(const std::string& val)
{
    m_title = val;
}

void LoadListTemplate::setDescription(const std::string& val)
{
    m_description = val;
}

void LoadListTemplate::setSiteSeprator(const std::string& val)
{
    m_siteSeprator = val;
}

void LoadListTemplate::setFullSiteTitle(const std::string& val)
{
    m_fullSiteTitle = val;
}

std::optional<std::string> LoadListTemplate::title() const
{
    if (isset(m_title)) {
        return m_title;
    } else {
        return std::nullopt;
    }
}

std::optional<std::string> LoadListTemplate::description() const
{
    if (isset(m_description)) {
        return m_description;
    } else {
        return std::nullopt;
    }
}

std::optional<std::string> LoadListTemplate::siteSeprator() const
{
    if (isset(m_siteSeprator)) {
        return m_siteSeprator;
    } else {
        return std::nullopt;
    }
}

std::optional<std::string> LoadListTemplate::fullSiteTitle() const
{
    if (isset(m_fullSiteTitle)) {
        return m_fullSiteTitle;
    } else {
        return std::nullopt;
    }
}

TEGRA_NAMESPACE_END
