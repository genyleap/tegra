/*!
 * @file        cache.hpp
 * @brief       This file is part of the Tegra System.
 * @details     Cache interface for system.
 * @author      <a href='https://www.kambizasadzadeh.com'>Kambiz Asadzadeh</a>
 * @package     The Genyleap
 * @since       29 Aug 2022
 * @copyright   Copyright (c) 2022 The Genyleap. All rights reserved.
 * @license     https://github.com/genyleap/tegra/blob/main/LICENSE.md
 *
 */

#ifndef CACHE_ABSTRACT_HPP
#define CACHE_ABSTRACT_HPP

#include "common.hpp"

TEGRA_USING_NAMESPACE Tegra::Types;

TEGRA_NAMESPACE_BEGIN(Tegra::Abstracts)

struct CacheMembers __tegra_final
{
    OptionalString  storage   {}; ///< String path to the "eternal" storage files. About what "eternal cache" is, read below.
};

/*!
 * Caching class constructor.
 * \brief The AbstractCache class
 * @param string|null uniq prefix for external cache machine names.
 * @param string|null path path to store files for the internal cache machine (when there are no external ones).
 * @param string|null storage perpetual cache storage path. The eternal is distinguished by the fact that it is easy to rule and it
 * is not deleted along with the main one. As a rule, the generated data is stored in the eternal cache key => value when inaccessible generator.
 */
class __tegra_export AbstractCache
{
public:
    TEGRA_DEFAULT_INTERFACE_OCTORS(AbstractCache)

    /*!
     * \brief Write data to cache.
     * \param string key Key (name of cache storage location).
     * \param mixed value stored data.
     * \param int ttl storage time in seconds.
     * \param bool eternal write as "eternal" cache.
     * \param int|null insur Cache hopelessly expired. Used to prevent the dog-pile effect. Default is twice ttl.
     * \returns boolean.
     */
    __tegra_virtual OptionalBool put(const std::string& key, const bool value, const u32 ttl, const bool eternal, const int insur) = __tegra_zero;

    /*!
     * \brief Get data from the cache.
     * \param string key cache storage location name.
     * \param bool eternal eternal cache flag.
     * \returns string.
     */
    __tegra_virtual OptionalString get(const std::string& key, const bool eternal) = __tegra_zero;

    /*!
     * \brief Get data from the cache.
     * \param string key cache storage location name.
     * \param bool eternal flag to remove the cache from the "eternal" storage table.
     * \returns boolean.
     */
    __tegra_virtual OptionalBool deleteCache(const std::string& key, const bool eternal) = __tegra_zero;

    /*!
     * \brief Mark the cache as obsolete so it can be regenerated. Unlike delete.
     * \param string key cache storage location name.
     * \returns boolean.
     */
    __tegra_virtual OptionalBool obsolete(const std::string& key, const bool eternal) = __tegra_zero;

private:
    TEGRA_DISABLE_COPY(AbstractCache)
};

TEGRA_NAMESPACE_END

#endif  // CACHE_ABSTRACT_HPP
