/*!
 * @file        system.hpp
 * @brief       This file is part of the Tegra System.
 * @details     Share structure for content sharing.
 * @author      <a href='https://www.kambizasadzadeh.com'>Kambiz Asadzadeh</a>
 * @package     The Genyleap
 * @since       29 Aug 2022
 * @copyright   Copyright (c) 2022 The Genyleap. All rights reserved.
 * @license     https://github.com/genyleap/tegra/blob/main/LICENSE.md
 *
 */

#ifndef SHARE_HPP
#define SHARE_HPP

#include "common.hpp"

TEGRA_USING_NAMESPACE Tegra::Types;

TEGRA_NAMESPACE_BEGIN(Tegra)

/*!
 * \brief The ShareMethod enum
 */
__tegra_enum_class ShareMethod : u8
{
    InSelf,
    SocialNetwork,
    ByEmail,
    BySms,
    ForApi,
    Custom
};

struct ShareData final
{
    ShareMethod method  {};
    OptionalString link {};
};

/*!
 * \brief The AbstractTags class
 */
class __tegra_export Share
{
public:
    TEGRA_DEFAULT_INTERFACE_OCTORS(Share)

    /*!
     * \brief registerToShare function will share post via share methods.
     * \param shareData is data for sharing.
     */
    void registerToShare(const ShareData& shareData) __tegra_const_noexcept;

private:
    TEGRA_DISABLE_COPY(Share)
    ShareData* m_shareData;
};

TEGRA_NAMESPACE_END

#endif  // SHARE_HPP
