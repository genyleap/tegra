/*!
 * @file        index.hpp
 * @brief       This file is part of the Tegra System.
 * @details     Index page.
 * @author      <a href='https://www.kambizasadzadeh.com'>Kambiz Asadzadeh</a>
 * @package     The Genyleap
 * @since       29 Aug 2022
 * @copyright   Copyright (c) 2022 The Genyleap. All rights reserved.
 * @license     https://github.com/genyleap/tegra/blob/main/LICENSE.md
 *
 */

#ifndef TEGRA_INDEX_HPP
#define TEGRA_INDEX_HPP

//! Tegra's Common.
#ifdef __has_include
# if __has_include(<common>)
#   include <common>
#else
#   error "Tegra's common was not found!"
# endif
#endif

TEGRA_NAMESPACE_BEGIN(Tegra::Default)

class DefIndex : public Framework::HttpController<DefIndex>
{
public:
    METHOD_LIST_BEGIN
    {
        ADD_METHOD_TO(DefIndex::index, "", {Framework::Get});
        ADD_METHOD_TO(DefIndex::index, "/", {Framework::Get});
        ADD_METHOD_VIA_REGEX(DefIndex::index,  "/([a-z]*-[a-z]*)/", Framework::Get, Framework::Post);
        ADD_METHOD_VIA_REGEX(DefIndex::index,  "/([a-z]*-[a-z]*)", Framework::Get, Framework::Post);
    }
    METHOD_LIST_END

    /*!
    * \brief index is the first page of web root.
    * \param req for Http request.
    * \param callback for Http response.
    */
    void index(const Framework::HttpRequestPtr& req, std::function<void(const Framework::HttpResponsePtr&)>&& callback) __tegra_const;
};


TEGRA_NAMESPACE_END

#endif // TEGRA_INDEX_HPP
