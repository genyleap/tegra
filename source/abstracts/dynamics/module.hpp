/*!
 * @file        module.hpp
 * @brief       This file is part of the Tegra System.
 * @details     Module interface for system.
 * @author      <a href='https://www.kambizasadzadeh.com'>Kambiz Asadzadeh</a>
 * @package     The Genyleap
 * @since       29 Aug 2022
 * @copyright   Copyright (c) 2022 The Genyleap. All rights reserved.
 * @license     https://github.com/genyleap/tegra/blob/main/LICENSE.md
 *
 */

#ifndef MODULE_ABSTRACT_HPP
#define MODULE_ABSTRACT_HPP

#include "common.hpp"

TEGRA_USING_NAMESPACE Tegra::Types;

TEGRA_NAMESPACE_BEGIN(Tegra::Abstracts)

/*!
 * \brief The ModuleType enum
 */
__tegra_enum_class ModuleType : u8
{
    Index,      //!For global user service.
    Admin,      //!For administrator service.
    System,     //!For system service only.
    Service,    //!For external or internal service.
    Default,    //!For default global service.
    Custom      //!For custom global service.
};

/*!
 * \brief The PermissionType enum
 */
__tegra_enum_class PermissionType
{
    ReadOnly,
    EditableOnly,
    Restricted,
    FullAccess,
    ByService
};


/*!
 * \brief The ModuleInfo class
 */
struct ModuleInfo __tegra_final
{
    OptionalString              codeName        {}; ///< A unique code for module.
    OptionalString              name            {}; ///< A name for module.
    OptionalString              description     {}; ///< A description for explanation module.
    OptionalString              compiledDate    {}; ///< Compiled date for module.
    Optional<SystemLicense>     license         {}; ///< License type for module.
    ModuleType                  moduleType      {}; ///< The type of module.
    Optional<SemanticVersion>   version         {}; ///< Version of module.
    OptionalString              author          {}; ///< Author of module.
    OptionalString              url             {}; ///< Url of module.
};

/*!
 * \brief The AbstractBaseClass class
 */
class __tegra_export AbstractModule
{
public:
    TEGRA_DEFAULT_INTERFACE_OCTORS(AbstractModule)

    /*!
     * \brief getCodeName function returns a unique code of module.
     * \returns a code as unique type.
     */
    __tegra_no_discard_virtual OptionalString getCodeName()  __tegra_const_noexcept = __tegra_zero;

    /*!
     * \brief getName function returns name of module.
     * \returns a name as string.
     */
    __tegra_no_discard_virtual OptionalString getName()  __tegra_const_noexcept = __tegra_zero;

    /*!
     * \brief getDescription function returns description of module.
     * \returns a description about module as string.
     */
    __tegra_no_discard_virtual OptionalString getDescription()  __tegra_const_noexcept = __tegra_zero;

    /*!
     * \brief getCompiledDate function returns date of module's compile date.
     * \returns a name as string.
     */
    __tegra_no_discard_virtual OptionalString getCompiledDate()  __tegra_const_noexcept = __tegra_zero;

    /*!
     * \brief getLicense function returns license of module.
     * \returns a license as SystemLicense.
     */
    __tegra_no_discard_virtual Optional<SystemLicense> getLicense()  __tegra_const_noexcept = __tegra_zero;

    /*!
     * \brief getModuleType function returns type of module.
     * \returns a type as ModuleType.
     */
    __tegra_no_discard_virtual Optional<ModuleType> getModuleType()  __tegra_const_noexcept = __tegra_zero;

    /*!
     * \brief getVersion function returns version of module.
     * \returns a version as SemanticVersion.
     */
    __tegra_no_discard_virtual Optional<SemanticVersion> getVersion()  __tegra_const_noexcept = __tegra_zero;

    /*!
     * \brief getAuthor function returns author of module.
     * \returns a name as string.
     */
    __tegra_no_discard_virtual OptionalString getAuthor()  __tegra_const_noexcept = __tegra_zero;

    /*!
     * \brief getUrl function returns url of module.
     * \returns a url as string.
     */
    __tegra_no_discard_virtual OptionalString getUrl()  __tegra_const_noexcept = __tegra_zero;

    /*!
     * \brief run is action function for modules.
     */
    __tegra_virtual void run()  __tegra_const_noexcept = __tegra_zero;

    /*!
     * \brief runAsTemplate is action function for modules based on template.
     * \param val is a parameter as multi type support.
     */
    template <typename... Args>
    auto runAsTemplate(const auto& val)
    {
        return val;
    }

    /*!
     * \brief type function returns type of module.
     * \returns as ModuleType.
     */
    __tegra_virtual ModuleType type() __tegra_const_noexcept = __tegra_zero;

protected:
    ModuleInfo* m_moduleInfo;
    friend class AbstractModuleManager;
    void setCodeName(const OptionalString& codename);
    void setName(const OptionalString& name);
    void setDescription(const OptionalString& desc);
    void setCompiledDate(const OptionalString& compiledDate);
    void setLicense(const Optional<SystemLicense>& licese);
    void setModuleType(const ModuleType moduleType);
    void setVersion(const Optional<SemanticVersion>& version);
    void setAuthor(const OptionalString& author);
    void setUrl(const OptionalString& url);

private:
    TEGRA_DISABLE_COPY(AbstractModule)
};

TEGRA_NAMESPACE_END

#endif  // MODULE_ABSTRACT_HPP