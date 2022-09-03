//! Tegra's Seo.
#ifdef __has_include
# if __has_include("seo.hpp")
#   include "seo.hpp"
#else
#   error "Tegra's seo was not found!"
# endif
#endif

//! Tegra's Database.
#ifdef __has_include
# if __has_include(<database>)
#   include <database>
#else
#   error "The database of Tegra was not found!"
# endif
#endif

TEGRA_USING_NAMESPACE Tegra;
TEGRA_USING_NAMESPACE Tegra::System;

TEGRA_NAMESPACE_BEGIN(Tegra::SEO)

using iterMap = std::map<std::string, std::string>::iterator;

MetaTag::MetaTag()
{
    __tegra_safe_instance(m_metaStruct, MetaStruct);
}

MetaTag::~MetaTag()
{
    __tegra_safe_delete(m_metaStruct);
}

VectorString MetaTag::tags() const
{
    return m_metaStruct->tags;
}

void MetaTag::registerTags(const MetaType& type, const MapString& item)
{
    std::stringstream stream;
    switch (type) {
    case MetaType::Name:
        for(const auto& i : item) {
            stream << "<meta name=" << '"' << i.first << '"' << ' ' << "content=" << '"' << i.second << '"' << "/>" << __tegra_newline;
            m_metaStruct->tags.push_back(stream.str());
            stream.str("");
        }
        break;
    case MetaType::Property:
        for(const auto& i : item) {
            stream << "<meta property=" << '"' << i.first << '"' << ' ' << "content=" << '"' << i.second << '"' << "/>" << __tegra_newline;
            m_metaStruct->tags.push_back(stream.str());
            stream.str("");
        }
        break;
    case MetaType::Extra:
        for(const auto& i : item) {
            stream << "<meta " << i.first << "=" << '"' << i.second << '"' << "/>" << __tegra_newline;
            m_metaStruct->tags.push_back(stream.str());
            stream.str("");
        }
        break;
    }
}

StaticMeta::StaticMeta(const ApplicationData& appData)
{
    __tegra_safe_instance_rhs(app, Application, appData);
    __tegra_safe_instance(m_staticStruct, StaticStruct);
    __tegra_safe_instance(m_staticPrivateMembers, StaticPrivateMembers);
    {
        app->path() = appData.path;
        app->module() = appData.module;
    }
    if(app->module().has_value()) {
        registerModule(app->module().value());
    } else {
        registerModule(__tegra_null_str);
    }
}

StaticMeta::~StaticMeta()
{
    __tegra_safe_delete(app);
    __tegra_safe_delete(m_staticStruct);
    __tegra_safe_delete(m_staticPrivateMembers);
}

VectorString StaticMeta::metaData()
{
    return m_staticStruct->items;
}

void StaticMeta::setDefault(const std::string& path)
{
    Scope<MetaTag> meta(new MetaTag());

    m_staticPrivateMembers->config      = {};
    m_staticPrivateMembers->baseTags    = {};
    m_staticPrivateMembers->staticExtra = {};

    m_staticPrivateMembers->developer       = { System::CONFIG::DEVELOPER };
    m_staticPrivateMembers->generator       = { System::CONFIG::FULL_NAME };
    m_staticPrivateMembers->version         = { System::CONFIG::FULL_VERSION };
    m_staticPrivateMembers->releaseMode     = { System::CONFIG::RELEASE_MODE };
    m_staticPrivateMembers->releaseNumber   = { System::CONFIG::RELEASE_NUMBER };
    m_staticPrivateMembers->copyright       = { System::CONFIG::FULL_NAME };

    if(Database::Connection::isConnected())
    {
        try
        {
            auto clientPtr = AppFramework::application().getDbClient();
            auto result = clientPtr->execSqlSync("SELECT * FROM " + app->engine->tablePrefix()
                                                 + "config AS c INNER JOIN " + app->engine->tablePrefix()
                                                 + "config_l AS cl ON cl.id = c.id WHERE language='"
                                                 + app->language->getLanguage() + "'");
            for (const auto &row : result)
            {
                m_staticPrivateMembers->config.insert(PairString(row["name"].as<std::string>(), row["value"].as<std::string>()));
            }
            // Basic HTML Meta Tags
            // Site static data
            iterMap siteViewport     = m_staticPrivateMembers->config.find("viewport");
            iterMap siteName         = m_staticPrivateMembers->config.find("site_name");
            iterMap siteDescription  = m_staticPrivateMembers->config.find("site_description");
            iterMap siteLocale       = m_staticPrivateMembers->config.find("site_locale");
            iterMap siteLastUpdate   = m_staticPrivateMembers->config.find("last_update");
            iterMap siteUrl          = m_staticPrivateMembers->config.find("url");
            iterMap siteKeywords     = m_staticPrivateMembers->config.find("keywords");
            iterMap siteAuthor       = m_staticPrivateMembers->config.find("author");

            String siteCharset    = Configuration::GET["system"]["encoding"].asString();
            String siteLanguage   = Configuration::GET["language"].asString();
            String siteGenerator;

            siteGenerator.append(m_staticPrivateMembers->generator.data());
            siteGenerator.append(" ");
            siteGenerator.append(m_staticPrivateMembers->version.data());
            siteGenerator.append("-");
            siteGenerator.append(m_staticPrivateMembers->releaseMode.data());
            siteGenerator.append(m_staticPrivateMembers->releaseNumber.data());

            String siteDeveloper  = m_staticPrivateMembers->developer.data();
            // Page data
            if (m_staticPrivateMembers->config.end() != siteViewport)     { m_staticPrivateMembers->baseTags.insert(PairString("viewport"   , siteViewport->second)); }
            if (m_staticPrivateMembers->config.end() != siteName)         { m_staticPrivateMembers->baseTags.insert(PairString("title"      , siteName->second)); }
            if (m_staticPrivateMembers->config.end() != siteDescription)  { m_staticPrivateMembers->baseTags.insert(PairString("description", siteDescription->second)); }
            if (m_staticPrivateMembers->config.end() != siteKeywords)     { m_staticPrivateMembers->baseTags.insert(PairString("keywords"   , siteKeywords->second)); }
            if (m_staticPrivateMembers->config.end() != siteAuthor)       { m_staticPrivateMembers->baseTags.insert(PairString("author"     , siteAuthor->second)); }

            m_staticPrivateMembers->baseTags.insert(PairString("generator", siteGenerator));
            m_staticPrivateMembers->baseTags.insert(PairString("author", siteDeveloper));
            m_staticPrivateMembers->baseTags.insert(PairString("copyright", m_staticPrivateMembers->copyright));
            m_staticPrivateMembers->baseTags.insert(PairString("language", siteLanguage));
            m_staticPrivateMembers->extra.insert(PairString("charset", siteCharset));
            /// ======== The Open Graph protocol ======== ]
            //! The title, headline or name of the object.
            //! A short description or summary of the object. [Between 2 and 4 sentences.]
            //! The URL of the image for your object. It should be at least 600×315 pixels, but 1200×630 or larger is preferred (up to 5MB). Stay close to a 1.91:1 aspect ratio to avoid cropping.
            //! The canonical URL for your page. This should be the undecorated URL, without session variables, user identifying parameters, or counters.
            if (m_staticPrivateMembers->config.end() != siteName)           { m_staticPrivateMembers->openGraph.insert(PairString("og:site_name"   , siteName->second)); }
            if (m_staticPrivateMembers->config.end() != siteLocale)         { m_staticPrivateMembers->openGraph.insert(PairString("og:locale"      , siteLocale->second)); }
            if (m_staticPrivateMembers->config.end() != siteUrl)            { m_staticPrivateMembers->openGraph.insert(PairString("og:url"         , siteUrl->second)); }
            if (m_staticPrivateMembers->config.end() != siteLastUpdate)     { m_staticPrivateMembers->openGraph.insert(PairString("og:updated_time", siteLastUpdate->second)); }
            // Basic Data
            meta->registerTags(MetaType::Name, m_staticPrivateMembers->baseTags);
            meta->registerTags(MetaType::Extra, m_staticPrivateMembers->extra);

            for(const auto& c : meta->tags()) {
                m_staticStruct->items.push_back(c);
            }

        } catch (const SqlException& e) {
            eLogger::Log("Database Error: " + FROM_TEGRA_STRING(e.base().what()), eLogger::LoggerType::Critical);
        }
    }

}

void StaticMeta::setData(const MetaType& type, const MapString& data)
{
    //MetaTag
    Scope<MetaTag> meta(new MetaTag());

    m_staticPrivateMembers->config      = {};
    m_staticPrivateMembers->baseTags    = {};
    m_staticPrivateMembers->metaTag     = data;
    m_staticPrivateMembers->openGraph   = data;
    m_staticPrivateMembers->extra       = data;
    m_staticPrivateMembers->staticExtra = {};

    m_staticPrivateMembers->developer       = { System::CONFIG::DEVELOPER };
    m_staticPrivateMembers->generator       = { System::CONFIG::FULL_NAME };
    m_staticPrivateMembers->version         = { System::CONFIG::FULL_VERSION };
    m_staticPrivateMembers->releaseMode     = { System::CONFIG::RELEASE_MODE };
    m_staticPrivateMembers->releaseNumber   = { System::CONFIG::RELEASE_NUMBER };
    m_staticPrivateMembers->copyright       = { System::CONFIG::FULL_NAME };

    try
    {
        auto clientPtr = AppFramework::application().getDbClient();

        if(!m_staticStruct->module.empty()) {
            if(Database::Connection::isConnected()) {
                auto result = clientPtr->execSqlSync("SELECT * FROM "
                                                     + app->engine->tablePrefix() + m_staticStruct->module
                                                     + " AS c INNER JOIN "
                                                     + app->engine->tablePrefix() + m_staticStruct->module
                                                     + "_l AS cl ON cl.id = c.id WHERE language='" + app->language->getLanguage() + "'");
                for (const auto& row : result)
                {
                    m_staticPrivateMembers->config.insert(PairString(row["name"].as<std::string>(), row["value"].as<std::string>()));
                }
            }
        }
        // Site static data
        iterMap siteViewport     =  m_staticPrivateMembers->config.find("viewport");
        iterMap siteName         =  m_staticPrivateMembers->config.find("site_name");
        iterMap siteDescription  =  m_staticPrivateMembers->config.find("site_description");
        iterMap siteLocale       =  m_staticPrivateMembers->config.find("site_locale");
        iterMap siteLastUpdate   =  m_staticPrivateMembers->config.find("last_update");
        iterMap siteUrl          =  m_staticPrivateMembers->config.find("url");
        iterMap siteKeywords     =  m_staticPrivateMembers->config.find("keywords");
        iterMap siteAuthor       =  m_staticPrivateMembers->config.find("author");

        String siteCharset    =  Configuration::GET["system"]["encoding"].asString();
        String siteLanguage   =  Configuration::GET["language"].asString();
        String siteGenerator  =  m_staticPrivateMembers->generator.data();
        String siteDeveloper  =  m_staticPrivateMembers->developer.data();
        // Page data
        if (m_staticPrivateMembers->config.end() != siteViewport)     { m_staticPrivateMembers->baseTags.insert(PairString("viewport"   , siteViewport->second    ));}
        if (m_staticPrivateMembers->config.end() != siteName)         { m_staticPrivateMembers->baseTags.insert(PairString("title"      , siteName->second        ));}
        if (m_staticPrivateMembers->config.end() != siteDescription)  { m_staticPrivateMembers->baseTags.insert(PairString("description", siteDescription->second ));}
        if (m_staticPrivateMembers->config.end() != siteKeywords)     { m_staticPrivateMembers->baseTags.insert(PairString("keywords"   , siteKeywords->second    ));}
        if (m_staticPrivateMembers->config.end() != siteAuthor)       { m_staticPrivateMembers->baseTags.insert(PairString("author"     , siteAuthor->second      ));}
        // Static Basic
        m_staticPrivateMembers->baseTags.insert(PairString("generator", siteGenerator));
        m_staticPrivateMembers->baseTags.insert(PairString("author", siteDeveloper));
        m_staticPrivateMembers->baseTags.insert(PairString("copyright", m_staticPrivateMembers->copyright));
        m_staticPrivateMembers->baseTags.insert(PairString("language", siteLanguage));
        // Static Extra [default generator]
        m_staticPrivateMembers->staticExtra.insert(PairString("charset", siteCharset));
        /// ======== The Open Graph protocol ======== ]
        //! The title, headline or name of the object.
        //! A short description or summary of the object. [Between 2 and 4 sentences.]
        //! The URL of the image for your object. It should be at least 600×315 pixels, but 1200×630 or larger is preferred (up to 5MB). Stay close to a 1.91:1 aspect ratio to avoid cropping.
        //! The canonical URL for your page. This should be the undecorated URL, without session variables, user identifying parameters, or counters.
        if (m_staticPrivateMembers->config.end() != siteName)           { m_staticPrivateMembers->openGraph.insert(PairString("og:site_name"   , siteName->second       ));}
        if (m_staticPrivateMembers->config.end() != siteLocale)         { m_staticPrivateMembers->openGraph.insert(PairString("og:locale"      , siteLocale->second     ));}
        if (m_staticPrivateMembers->config.end() != siteUrl)            { m_staticPrivateMembers->openGraph.insert(PairString("og:url"         , siteUrl->second        ));}
        if (m_staticPrivateMembers->config.end() != siteLastUpdate)     { m_staticPrivateMembers->openGraph.insert(PairString("og:updated_time", siteLastUpdate->second ));}
        //!Dynamic data
        switch (type)
        {
        case MetaType::Name:
            meta->registerTags(MetaType::Name, m_staticPrivateMembers->baseTags);
            meta->registerTags(MetaType::Name, m_staticPrivateMembers->metaTag);
            break;
        case MetaType::Property:
            meta->registerTags(MetaType::Property, m_staticPrivateMembers->openGraph);
            break;
        case MetaType::Extra:
            meta->registerTags(MetaType::Property, m_staticPrivateMembers->extra);
            break;
        }
        // This is default static meta data that always produced by staticEx.
        meta->registerTags(MetaType::Extra, m_staticPrivateMembers->staticExtra);

        for(const auto& c : meta->tags()) {
            m_staticStruct->items.push_back(c);
        }

    }
    catch (const SqlException& e)
    {
        eLogger::Log("Database Error: " + FROM_TEGRA_STRING(e.base().what()), eLogger::LoggerType::Critical);
    }
}

void StaticMeta::registerModule(const std::string& module)
{
    m_staticStruct->module = module;
}

std::string StaticMeta::module() const
{
    return m_staticStruct->module;
}

TEGRA_NAMESPACE_END
