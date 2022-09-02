//! Tegra's Url.
#ifdef __has_include
# if __has_include("url.hpp")
#   include "url.hpp"
#else
#   error "Tegra's url was not found!"
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

TEGRA_USING_NAMESPACE Tegra;
TEGRA_USING_NAMESPACE Tegra::System;

TEGRA_NAMESPACE_BEGIN(Tegra)

/*!
 * \brief Constructs url class.
 */
Url::Url()
{
    __tegra_safe_instance(m_urlStructure, UrlStructure);
    __tegra_safe_instance(m_languageUrl, LanguageUrl);
}

Url::Url(const std::string& uri)
{
    __tegra_safe_instance(m_urlStructure, UrlStructure);
    __tegra_safe_instance(m_languageUrl, LanguageUrl);

    if(!isset(m_languageUrl->uri.has_value()))
    {
        m_languageUrl->uri = uri;
    }
}

/*!
 * \brief Destroys the url class.
 */
Url::~Url()
{
    __tegra_safe_delete(m_urlStructure);
    __tegra_safe_delete(m_languageUrl);
}

void Url::registerUrl(const UrlStructure& urlStructure) __tegra_const_noexcept
{
    {
        m_urlStructure->scheme          =   urlStructure.scheme;
        m_urlStructure->subdomain       =   urlStructure.subdomain;
        m_urlStructure->secondLevel     =   urlStructure.secondLevel;
        m_urlStructure->topLevel        =   urlStructure.topLevel;
        m_urlStructure->subdirectory    =   urlStructure.subdirectory;
    }
}

UrlStructure Url::getAsStructure() __tegra_const_noexcept
{
    return *m_urlStructure;
}

OptionalString Url::getAsUrl() __tegra_const_noexcept
{
    std::string url {};
    if(!isset(m_languageUrl->uri.has_value()))
    {
        url.append(m_urlStructure->scheme.value());
        url.append(m_urlStructure->subdomain.value());
        url.append(m_urlStructure->secondLevel.value());
        url.append(m_urlStructure->topLevel.value());
        url.append(m_urlStructure->subdirectory.value());
    }
    return url;
}

void Url::setLanguageUri(const std::string& uri) __tegra_const_noexcept
{
    if(!isset(m_languageUrl->uri.has_value()))
    {
        m_languageUrl->uri = uri;
    }
}

OptionalString Url::getLanguageUri() __tegra_const_noexcept
{
    if (isset(m_languageUrl->uri.value())) {
        return m_languageUrl->uri.value();
    } else {
        return std::nullopt;
    }
}

TEGRA_NAMESPACE_END
