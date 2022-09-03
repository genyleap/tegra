//! Tegra's LinkParser.
#ifdef __has_include
# if __has_include("linkparser.hpp")
#   include "linkparser.hpp"
#else
#   error "Tegra's linkparser was not found!"
# endif
#endif

TEGRA_USING_NAMESPACE Tegra;

TEGRA_NAMESPACE_BEGIN(Tegra)

LinkParser::LinkParser()
{
}

LinkParser::~LinkParser()
{
}

void LinkParser::parse(std::string& url)
{
    std::size_t pos   = std::string::npos;
    std::string http  = "http://";
    std::string https = "https://";
    // Search for the substring in string in a loop untill nothing is found
    while((pos = url.find(http))!= std::string::npos || (pos = url.find(https))!= std::string::npos)
    {
        // If found then erase it from string
        if(!url.find(http))
        {
            url.erase(pos, http.length());
        }
        if(!url.find(https))
        {
            url.erase(pos, https.length());
        }

    }
    std::stringstream s(url.starts_with("/") ? url.substr(1,url.length()) : url);
    while (s.good()) {
        std::string substr;
        std::getline(s, substr, '/');
        m_item.push_back(substr);
    }
}

VectorString LinkParser::items()
{
    return m_item;
}

TEGRA_NAMESPACE_END
