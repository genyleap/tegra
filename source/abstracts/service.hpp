/*!
 * @file        service.hpp
 * @brief       This file is part of the Tegra System.
 * @details     Service interface for system.
 * @author      <a href='https://www.kambizasadzadeh.com'>Kambiz Asadzadeh</a>
 * @package     The Genyleap
 * @since       29 Aug 2022
 * @copyright   Copyright (c) 2022 The Genyleap. All rights reserved.
 * @license     https://github.com/genyleap/tegra/blob/main/LICENSE.md
 *
 */

#ifndef TEGRA_SERVICE_ABSTRACT_HPP
#define TEGRA_SERVICE_ABSTRACT_HPP

//! Tegra's Common.
#ifdef __has_include
# if __has_include(<common>)
#   include <common>
#else
#   error "Tegra's common was not found!"
# endif
#endif

TEGRA_USING_NAMESPACE Tegra::Types;

TEGRA_NAMESPACE_BEGIN(Tegra::Abstracts)

/*!
 * \brief The ServiceType enum
 * \details Each part of the system can be provided according to the purpose of the service.
 */
__tegra_enum_class ServiceType : u8
{
    Self        =   0x1,  ///< This option enables the system to use the desired feature for system's internal purposes only.
    Api         =   0x2,  ///< This option enables the system to use the desired feature for output api purposes only.
    Multi       =   0x3,  ///< This option enables the system to use the desired feature for internal and external purposes only.
    Limited     =   0x4,  ///< This option enables the system to use the desired feature for limited purposes only.
    Customized  =   0x5   ///< This option enables the system to use the desired feature for customized purposes only.
};

/*!
 * \brief The LicenseType enum
 */
__tegra_enum_class LicenseType : u8
{
    Free            =   0x0,  ///< Making items as a service based on love <3! (Full Free).
    Commercial      =   0x1,  ///< Making items as a service based on commercial goals.
    Customized      =   0x2   ///< Making items as a service based on terms and conditions.
};

/*!
 * \brief The Status enum
 */
__tegra_enum_class Status : u8
{
    Disabled        =   0x0,  ///< Disabled.
    InDevelopment   =   0x2,  ///< In Development.
    Suspended       =   0x3,  ///< Hidden.
    Active          =   0x4   ///< Active.
};

/*!
 * \brief The ActivityType enum
 */
__tegra_enum_class ActivityType : u8
{
    DefaultAsNull           =   0x0,    ///< Activated by no limitation.
    BasedOnIp               =   0x1,    ///< Active based on IP Address.
    BasedOnMacAddress       =   0x2,    ///< Active based on Mac Address.
    BasedOnDNS              =   0x3,    ///< Active based on DNS Address [NS1, NS2, ...].
    BasedOnDomainAddress    =   0x4,    ///< Active based on Domain Address [domainname.com].
    BasedOnCustomProperty   =   0x5     ///< Active based on custom propery.
};

/*!
 * \brief The ActivityStruct class
 */
struct ActivityStruct __tegra_final { Optional<ActivityType> activityType; };

class __tegra_export AbstractActivity
{
public:
    TEGRA_DEFAULT_INTERFACE_OCTORS(AbstractActivity)

    /*!
     * \brief activeType will gets activated mode for service.
     * \returns ActivityType's options.
     */
    __tegra_virtual ActivityType activeType() = __tegra_zero;

    /*!
     * \brief registerActiveType will sets active type for service.
     * \param act as ActivityType.
     */
    __tegra_virtual void registerActiveType(const ActivityType& act) = __tegra_zero;

private:
    TEGRA_DISABLE_COPY(AbstractActivity)
};

/*!
 * \brief The SettingData class
 */
struct ServiceData __tegra_final
{
    OptionalNumeric         uid        {};   ///< Unique identifier.
    OptionalString          title      {};   ///< Title.
    OptionalString          descr      {};   ///< Description.
    Optional<ServiceType>   type       {};   ///< Type based on optional ServiceType.
    Optional<Status>        status     {};   ///< Status of service.
};

/*!
 * \brief The ServiceInfo class
 */
struct ServiceInfo __tegra_final
{
    SemanticVersion         version    {};   ///< Version number.
    Optional<LicenseType>   license    {};   ///< Type of license.
};

/*!
 * \brief The AbstractService class
 */
class __tegra_export AbstractService : protected AbstractActivity
{
public:
    TEGRA_DEFAULT_INTERFACE_OCTORS(AbstractService)

    /*!
     * \brief The UID enum
     */
    enum UID : u8 { Numeric, String, Complex };

    /*!
     * \brief uid is unique number for each service.
     * \returns random number.
     */
    __tegra_constexpr_virtual OptionalNumeric uid() __tegra_const = __tegra_zero;

    /*!
     * \brief title is subject of setting option.
     * \returns string.
     */
    __tegra_virtual OptionalString title() = __tegra_zero;

    /*!
     * \brief descr is description of setting option.
     * \returns string.
     */
    __tegra_virtual OptionalString descr() = __tegra_zero;

    /*!
     * \brief service will gets service type value.
     * \returns one of the service types.
     */
    __tegra_virtual Optional<ServiceType> service() = __tegra_zero;

    /*!
     * \brief status will gets license type.
     * \returns one of the licenses.
     */
    __tegra_virtual Optional<LicenseType> license() = __tegra_zero;

    /*!
     * \brief version will gets full version of service.
     * \returns based on SemanticVersion class.
     */
    __tegra_virtual SemanticVersion version() = __tegra_zero;

    /*!
     * \brief status will gets status value from service.
     * \returns one of the Status.
     */
    __tegra_virtual Optional<Status> status() = __tegra_zero;

    /*!
     * \brief setUid generates unique id for service.
     * \param uid is a numerical type for inserting values into the function.
     */
    __tegra_constexpr_virtual void setUid() __tegra_const = __tegra_zero;

    /*!
     * \brief SetTitle inserts data for the option's title.
     * \param title is a string type for inserting values into the function.
     */
    __tegra_virtual void setTitle(const std::string& title) = __tegra_zero;

    /*!
     * \brief setDescr inserts data for the option's description.
     * \param descr is a string type for inserting values into the function.
     */
    __tegra_virtual void setDescr(const std::string& descr) = __tegra_zero;

    /*!
     * \brief setService sets service type for service.
     * \param service is a ServiceType for setting into the function.
     */
    __tegra_virtual void setService(const Optional<ServiceType>& service) = __tegra_zero;

    /*!
     * \brief setLicense sets license for the service.
     * \param license is a LicenseType for setting into the function.
     */
    __tegra_virtual void setLicense(const Optional<LicenseType>& license) = __tegra_zero;

    /*!
     * \brief setStatus will change option's status.
     * \param status is a Status type for change the option status.
     */
    __tegra_virtual void setStatus(const Optional<Status> status) = __tegra_zero;

    /*!
     * \brief setStatus will sets service's version.
     * \param version is a SemanticVersion type.
     */
    __tegra_virtual void setVersion(const SemanticVersion& version) = __tegra_zero;

private:
    TEGRA_DISABLE_COPY(AbstractService)
};

TEGRA_NAMESPACE_END

#endif  // TEGRA_SERVICE_ABSTRACT_HPP
