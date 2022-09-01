/*!
 * @file        filesystem.hpp
 * @brief       This file is part of the Tegra System.
 * @details     Filesystem manager.
 * @author      <a href='https://www.kambizasadzadeh.com'>Kambiz Asadzadeh</a>
 * @package     The Genyleap
 * @since       29 Aug 2022
 * @copyright   Copyright (c) 2022 The Genyleap. All rights reserved.
 * @license     https://github.com/genyleap/tegra/blob/main/LICENSE.md
 *
 */

#ifndef TEGRA_FILESYSTEM_HPP
#define TEGRA_FILESYSTEM_HPP

//! Tegra's Core (Basic Requirements).
#ifdef __has_include
# if __has_include(<requirements>)
#   include <requirements>
#else
#   error "Tegra's requirements are not found!"
# endif
#endif

TEGRA_NAMESPACE_BEGIN(Tegra::FileSystem)

class Path
{
public:
  Path();
  ~Path();

  /*!
   * \brief getExecutablePath
   * \return current executable file path.
   */
  __tegra_no_discard static std::string getExecutablePath();

  /*!
   * \brief exists
   * \return true if file is exist in the path.
   */
  __tegra_no_discard static bool exists(const std::string& file);

};

TEGRA_NAMESPACE_END

#endif // TEGRA_FILESYSTEM_HPP
