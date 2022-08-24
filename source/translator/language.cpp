#include "language.hpp"
#include "core/core.hpp"
#include "core/config.hpp"
#include "core/logger.hpp"

TEGRA_USING_NAMESPACE Tegra;
TEGRA_USING_NAMESPACE Tegra::System;
TEGRA_USING_NAMESPACE Tegra::eLogger;

TEGRA_NAMESPACE_BEGIN(Tegra::Multilangual)

Language::Language()
{
    __tegra_safe_instance(m_languageStruct, LanguageStruct);

    Scope<Configuration> config(new Configuration(ConfigType::File));

    config->init(SectionType::SystemCore); //!System core for language.

    auto lcodes = LanguageCodes{}; //!Language codes.

    for(auto c : Configuration::GET[TEGRA_LANGS])
    {
        if(c["status"].asBool()) {
            lcodes.push_back(c["l"].asString().substr(0, 5));
        }
    }
    //!Register language code.
    registerLanguage(lcodes); //!Language register method.
}

/*! Implementation of language support */
Language::Language(const std::string& uri)
{
    __tegra_safe_instance(m_languageStruct, LanguageStruct);

    m_languageStruct->url.setLanguageUri(uri);

    Scope<Configuration> config(new Configuration(ConfigType::File));

    config->init(SectionType::SystemCore); //!System core for language.

    auto lcodes = LanguageCodes{}; //!Language codes.

    for(auto c : Configuration::GET[TEGRA_LANGS])
    {
        if(c["status"].asBool()) {
            lcodes.push_back(c["l"].asString().substr(0, 5));
        }
    }
    //!Register language code.
    registerLanguage(lcodes); //!Language register method.
}

Language::~Language()
{
    __tegra_safe_delete(m_languageStruct);
}


void Language::registerAll(const LanguageType& data)
{
    m_languageStruct->get = data;
}

LanguageType Language::get() __tegra_const_noexcept
{
    return m_languageStruct->get;
}

void Language::registerLanguage(const Types::LanguageCodes& code)
{
    m_languageStruct->languageSupport = code;
}

LanguageCodes Language::languageSupport() __tegra_const_noexcept
{
    return m_languageStruct->languageSupport;
}

std::string Language::getLanguageCode() __tegra_const_noexcept
{
    Scope<Configuration> config(new Configuration(ConfigType::File));
    config->init(SectionType::SystemCore);
    String path = { m_languageStruct->url.getLanguageUri().value_or("en-us") }; //!->/{language}/uri/
    std::string lcode{};
    for(auto c : Configuration::GET[TEGRA_LANGS]) {
        if(c["uri"] == path.substr(1, 5)) {
            lcode = c["l"].asString().substr(0,5);
        } else {
            if(c["code"].asString() == Configuration::GET[TEGRA_DEFAULT_LANG]) {
                lcode = c["l"].asString().substr(0,5);
            }
        }
    }
    return lcode;
}

std::string Language::getLanguage() __tegra_const_noexcept
{
    Scope<Configuration> config(new Configuration(ConfigType::File));
    config->init(SectionType::SystemCore);
    String path = { m_languageStruct->url.getLanguageUri().value_or("en-us") }; //!->/{language}/uri/
    std::string lcode{};
    for(auto c : Configuration::GET[TEGRA_LANGS]) {
        if(c["uri"] == path.substr(1, 5)) {
            lcode = c["code"].asString();
        } else {
            if(c["code"].asString() == Configuration::GET[TEGRA_DEFAULT_LANG]) {
                lcode = c["code"].asString();
            }
        }
    }
    return lcode;
}

TEGRA_NAMESPACE_END
