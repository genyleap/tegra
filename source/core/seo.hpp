/*!
 * @file        seo.hpp
 * @brief       This file is part of the Tegra System.
 * @details     Seo manager for content optimization.
 * @author      <a href='https://www.kambizasadzadeh.com'>Kambiz Asadzadeh</a>
 * @package     The Genyleap
 * @since       29 Aug 2022
 * @copyright   Copyright (c) 2022 The Genyleap. All rights reserved.
 * @license     https://github.com/genyleap/tegra/blob/main/LICENSE.md
 *
 */

#ifndef SEO_HPP
#define SEO_HPP

//! Tegra's Core (Basic Requirements).
#ifdef __has_include
# if __has_include(<requirements>)
#   include <requirements>
#else
#   error "Tegra's requirements are not found!"
# endif
#endif

//! Tegra's Abstraction (Interfaces).
#ifdef __has_include
# if __has_include(<interface>)
#   include <interface>
#else
#   error "The abstractions of Tegra are not found!"
# endif
#endif

//! Tegra's Application.
#ifdef __has_include
# if __has_include(<application>)
#   include <application>
#else
#   error "The application of Tegra was not found!"
# endif
#endif

TEGRA_USING_NAMESPACE Tegra;
TEGRA_USING_NAMESPACE Tegra::System;
TEGRA_USING_NAMESPACE Tegra::Types;

TEGRA_NAMESPACE_BEGIN(Tegra::SEO)

/*!
 * \brief The MetaType enum
 */
enum MetaType : u8
{
  Name      = 0x1,  ///< This attribute is basically used to explain the name of the property.
  Property  = 0x2,  ///< This attribute is used to explain more properties if a tag.
  Extra     = 0x3   ///< This attribute is used to add other and extra.
};

/*!
 * \brief The MetaStruct class
 */
struct MetaStruct final
{
    MetaType        type    {};
    VectorString    tags    {};
    MapString       items   {};
    String          stream  {};
};

/*!
 * \brief The MetaTag class
 */
class MetaTag
{
public:
  MetaTag();
  ~MetaTag();

  /*!
   * @brief tags will returns list of meta tags.
   * @returns list of array.
   */
  std::vector<std::string> tags() const;

  /*!
   * @brief registerTags will sets meta data into list.
   * @param type gets meta types as [Name, Property].
   * @param item gets meta data key and value.
   */
  void registerTags(const MetaType& type, const MapString& item);

private:
  MetaStruct* m_metaStruct;
};

/*!
 * \brief The StaticStruct class
 */
struct StaticStruct final
{
    VectorString    data    {};
    VectorString    items   {};
    String          module  {};
};

/*!
 * \brief The StaticPrivateMembers class
 */
struct StaticPrivateMembers final
{
    MapString config       {};
    MapString baseTags     {};
    MapString metaTag      {};
    MapString openGraph    {};
    MapString extra        {};
    MapString staticExtra  {};

    std::string_view developer      {};
    std::string_view generator      {};
    std::string_view version        {};
    std::string_view releaseMode    {};
    std::string_view releaseNumber  {};
    std::string_view copyright      {};
};

class StaticMeta
{
public:
  StaticMeta() = delete;
  StaticMeta(const ApplicationData& appData);
  ~StaticMeta();

  /*!
   * \brief setDefault
   * \param lng
   */
  void setDefault(const std::string& path);

  /*!
   * \brief metaData
   * \return
   */
  std::vector<std::string> metaData();

  /*!
   * \brief setData
   * \param type
   * \param data
   */
  void setData(const MetaType& type, const MapString& data);

  /*!
   * \brief registerModule
   * \param module
   */
  void registerModule(const std::string& module);

  /*!
   * \brief module
   * \return
   */
  std::string module() const;

private:
  Application* app{};
  StaticStruct* m_staticStruct{};
  StaticPrivateMembers* m_staticPrivateMembers{};
};

TEGRA_NAMESPACE_END

#endif // SEO_HPP
