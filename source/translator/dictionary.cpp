//! Tegra's Dictionary.
#ifdef __has_include
# if __has_include("dictionary.hpp")
#   include "dictionary.hpp"
#else
#   error "Tegra's dictionary was not found!"
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

TEGRA_NAMESPACE_BEGIN(Tegra::Translation)
TEGRA_USING_NAMESPACE Tegra::eLogger;

LanguageTemplate::LanguageTemplate()
{

}

LanguageTemplate::LanguageTemplate(
        const std::string& word_key,
        const std::string& module,
        const std::string& default_value,
        const std::string& custom_value
        )
    : m_wordKey(word_key),
      m_module(module),
      m_defaultValue(default_value),
      m_customValue(custom_value)
{

}

LanguageTemplate::~LanguageTemplate()
{
}

std::string LanguageTemplate::wordKey() __tegra_const_noexcept {
    if(!m_wordKey.empty()) {
        return m_wordKey;
    } else {
        return "unknown key";
    }
}

std::string LanguageTemplate::module() __tegra_const_noexcept {
    return m_module;
}

std::string LanguageTemplate::defaultValue() __tegra_const_noexcept {
    if(!m_defaultValue.empty()) {
        return m_defaultValue;
    } else {
        return "there is no default value of key [" + wordKey() + "]";
        Log("there is no default value of key [" + wordKey() + "]", LoggerType::Warning);
    }
}

std::string LanguageTemplate::customValue() __tegra_const_noexcept {
    if(!m_customValue.empty()) {
        return m_customValue;
    } else {
        Log("here is no custom value of key [" + wordKey() + "]", LoggerType::Warning);
        return "there is no custom value of key [" + wordKey() + "]";
    }
}

TEGRA_NAMESPACE_END
