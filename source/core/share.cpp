//! Tegra's Share.
#ifdef __has_include
# if __has_include("share.hpp")
#   include "share.hpp"
#else
#   error "Tegra's share was not found!"
# endif
#endif

TEGRA_USING_NAMESPACE Tegra;

TEGRA_NAMESPACE_BEGIN(Tegra)

/*!
 * \brief Constructs an abstract share class.
 */
Share::Share()
{
    __tegra_safe_instance(m_shareData, ShareData);
}

/*!
 * \brief Destroys the share class.
 */
Share::~Share()
{
    __tegra_safe_delete(m_shareData);
}

void Share::registerToShare(const ShareData &shareData) const noexcept
{
    //Test link...
    std::cout << shareData.link.value() << std::endl;

    switch (shareData.method) {
    case ShareMethod::InSelf:
        ///ToDo...
        break;
    case ShareMethod::SocialNetwork:
        ///ToDo...
        break;
    case ShareMethod::ByEmail:
        ///ToDo...
        break;
    case ShareMethod::BySms:
        ///ToDo...
        break;
    case ShareMethod::ForApi:
        ///ToDo...
        break;
    case ShareMethod::Custom:
        ///ToDo...
        break;
    default:
        break;
    }
}

TEGRA_NAMESPACE_END

