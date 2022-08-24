/*!
 * @file        core.hpp
 * @brief       This file is part of the Tegra System.
 * @details     System core.
 * @author      <a href='https://www.kambizasadzadeh.com'>Kambiz Asadzadeh</a>
 * @package     The Genyleap
 * @since       29 Aug 2022
 * @copyright   Copyright (c) 2022 The Genyleap. All rights reserved.
 * @license     https://github.com/genyleap/tegra/blob/main/LICENSE.md
 *
 */

#ifndef TEGRA_CORE_HPP
#define TEGRA_CORE_HPP

#include "common.hpp"
#include "logger.hpp"
#include "version.hpp"
#include "prestructure.hpp"
#include "translator/language.hpp"
#include "translator/translator.hpp"

TEGRA_USING_NAMESPACE Tegra::Types;

TEGRA_NAMESPACE_BEGIN(Tegra::System)

/*!
 * @brief The DeveloperMode is for enable or disable system debuging information.
 */
struct DeveloperMode {
#if defined(BUILD_DEBUG_MODE) || defined(ENABLE_DEVELOPER_MODE)
    inline static bool IsEnable = true;
#else
    inline static bool IsEnable = false;
#endif
};

template <typename T>
/*!
 * @brief isset — Determine if a variable is declared and is different than null
 * @returns true if var exists and has any value other than null. false otherwise.
 */
__tegra_no_discard_message("Checks if the variable has no value.")
    static auto isset(T t) __tegra_noexcept_expr(true)
{
    if (const auto it = t; it != T {})
        // on success
        return true;
    else
        // on false...
        return false;
}

/*!
 * @brief check if these two are equal
 */
template <typename T1, typename T2>
__tegra_no_discard constexpr bool equals(T1 const& first, T2 const& second) __tegra_noexcept
{
    return first == second;
}

/*!
 * \brief Replaces the value of obj with new_value and returns the old value of obj. like (std::exchange)
 * \param oldValue
 * \param newValue
 * \returns as replaced value.
 */
template <typename T, typename U = T>
__tegra_constexpr T exchange(T& t, U&& newValue)
{
    T old = std::move(t);
    t = std::forward<U>(newValue);
    return old;
}

template<typename ... Args>
std::string stringFormat(const std::string& format, Args ... args)
{
    s8 size = snprintf(nullptr, 0, format.c_str(), args ...) + 1; // Extra space for '\0'
    if (size <= 0)
    {
        throw std::runtime_error("Error during formatting.");
    }
    std::unique_ptr<char[]> buf(new char[size]);
    snprintf(buf.get(), size, format.c_str(), args ...);
    return std::string(buf.get(), buf.get() + size - 1); // We don't want the '\0' inside
}

/*!
 * @brief Invokes the command processor to execute a command.
 * @param cmd holds the commands for function.
 * @returns data from terminal.
 */
__tegra_maybe_unused std::string command(const std::string& cm);

/*!
 * @brief Maybe we need to convert stringstream to standard string.
 * @param data as stringstream content.
 * @returns as std::string output.
 */
__tegra_no_discard std::string convertStream(std::stringstream const& data) __tegra_noexcept;

/*!
 * @brief regen url by length fro, the first
 */
template <typename T1, typename T2>
__tegra_no_discard std::string_view regenUrl(T1 const& url, T2 const len) __tegra_noexcept
{
    if(!url.empty)
        return url.substr(len);
}

/*!
 * @brief The StorageType enum
 */
enum class StorageType : u8
{
    Empty           =   0x0,
    File            =   0x1,
    MemoryCard      =   0x2,
    Hdd             =   0x3,
    Ssd             =   0x4,
    Cache           =   0x5,
    Database        =   0x6,
    Network         =   0x7
};

enum class UserMode : u8
{
    Guest           =   0x0,
    User            =   0x1,
    Master          =   0x2,
    Customized      =   0x3
};

enum class SyncDevice : u8
{
    Unknown         =   0x0,
    WebOnly         =   0x1,
    Mobile          =   0x2,
    Desktop         =   0x3,
    CrossPlatform   =   0x4
};

enum class HostType : u8
{
    Unknown     =   0x0,
    Windows     =   0x1,
    macOS       =   0x2,
    Linux       =   0x3
};

enum class Service : u8
{
    Local       =   0x0,
    Installed   =   0x1,
    Closed      =   0x2,
    Running     =   0x3
};

enum class IconType : u8
{
    Png,
    Svg,
    FontIcon
};

enum class MediaType : u8
{
    Image,
    Video,
    Canvas
};

enum class ApiModel : u8
{
    Unknown,
    Json,
    Xml,
    GraphQl
};

enum class TerminateType : u8
{
    Unknown,
    Violation,
    UnexpectedError
};

enum class TableType : u8
{
    MixedStruct, ///<Key and Value table
    KeyStruct,   ///<Only key table
    ValueSturct  ///<Only value table [with suffix "l"]
};

struct Termination
{
    /*!
     * @brief It is sometimes necessary to force the system in runtime.
     * @param terminateType is based on reasons for action.
     */
    void terminate(TerminateType terminateType);
};

/*!
 * @brief The ExceptionMode enum
 */
enum class ExceptionMode : u8 { Default, StlException, TegraException };

/*!
 * @brief The ExceptionData class
 */
struct ExceptionData
{
    std::string message {}; //default message
    std::string file    {};
    uint line           {};
    std::string func    {};
    std::string info    {};
};

class Exception : public std::exception
{
public:
    enum Reason : u8
    {
        Core,
        Framework,
        IO,
        User,
        System,
        Other
    };

    Exception(const Reason& reason, const std::string& message);
    virtual ~Exception();
    virtual const char* what() const throw();
private:
    ExceptionData* m_exceptionData;
};

struct BootParameter final
{
    bool                            fastBoot       {};      ///<This property is set to true when the system is booted with the highest possible state.
    std::time_t                     initTime       {};      ///<The time spent on execution.
    std::optional<std::string>      saveState      {};      ///<The system save state applied during a save operation after execution or completion of the operation..
    std::optional<u32>              pageSize       {};      ///<The size of the requested page.
    std::time_t                     pageInitTime   {};      ///<The loading time of the requested page.
    std::optional<u32>              pageSpeed      {};      ///<The loading speed of the requested page.
    std::optional<s32>              stateIndex     {};      ///<The state of index for any page.
    std::optional<HostType>         hostType       {};      ///<This attribute specifies the type of site hosting. for example: Linux
    std::optional<StorageType>      storageType    {};      ///<This attribute specifies the type of storage to use.
    std::optional<UserMode>         userMode       {};      ///<This attribute specifies the type of user who uses the system.
    std::optional<SyncDevice>       syncDevice     {};      ///<This attribute specifies the type of devices that are integrated with the system.
    std::optional<SystemType>       systemType     {};      ///<This attribute determines the type of system consumption.
    std::optional<SystemLicense>    systemLicense  {};      ///<The type of license to use the system.
    std::optional<SystemStatus>     systemStatus   {};      ///<This attribute specifies the state the system is in.
};

class EngineInterface
{
public:
    EngineInterface();
    EngineInterface(const BootParameter& bootParameter);
    virtual ~EngineInterface();

    /*!
     * @brief initialize starter!
     * @returns true if the system starts successfully.
     */
    virtual bool initialize() = __tegra_zero;

    /*!
     * @brief Getting current fast boot status.
     * @returns true if system has been booted as fast as possible.
     */
    virtual bool                            getFastBoot         () final;

    /*!
     * @brief Getting current system init time duration.
     * @returns returns as time.
     */
    virtual std::time_t                     getInitTime         () final;

    /*!
     * @brief Getting current system state.
     * @returns returns string of system state, for example version and etc.
     */
    virtual std::optional<std::string>      getSaveState        () final;

    /*!
     * @brief Getting current loaded page size.
     * @returns returns as unsigned int 32 for page size.
     */
    virtual std::optional<u32>              getPageSize         () final;

    /*!
     * @brief Getting current system current page init time duration.
     * @returns returns as time.
     */
    virtual std::time_t                     getPageInitTime     () final;

    /*!
     * @brief Getting current page speed load.
     * @returns returns as counter of page speed.
     */
    virtual std::optional<u32>              getPageSpeed        () final;

    /*!
     * @brief Getting current system state index.
     * @returns returns as signed integer for state index.
     */
    virtual std::optional<s32>              getStateIndex       () final;

    /*!
     * @brief Getting current installed host type.
     * @returns returns as HostType enum.
     */
    virtual std::optional<HostType>         getHostType         () final;

    /*!
     * @brief Getting current system user mode.
     * @returns returns as UserMode enum.
     */
    virtual std::optional<UserMode>         getUserMode         () final;

    /*!
     * @brief Getting current system sync mode.
     * @returns returns as SyncDevice enum.
     */
    virtual std::optional<SyncDevice>       getSyncMode         () final;

    /*!
     * @brief Getting current system type.
     * @returns returns as SystemType enum.
     */
    virtual std::optional<SystemType>       getSystemType       () final;

    /*!
     * @brief Getting current system license.
     * @returns returns as SystemLicense enum.
     */
    virtual std::optional<SystemLicense>    getSystemLicense    () final;

    /*!
     * @brief Getting current state of the system.
     * @returns returns as SystemStatus enum.
     */
    virtual std::optional<SystemStatus>     getSystemStatus     () final;


private:
    BootParameter* m_bootParameter{nullptr};
    bool m_status{false};
};

/*!
 * @brief The Engine class
 */
class Engine : public EngineInterface
{
public:
    Engine();
    Engine(const Engine& rhsEngine) = delete;
    Engine(Engine&& rhsEngine) noexcept = delete;
    Engine& operator=(const Engine& rhsEngine) = delete;
    Engine& operator=(Engine&& rhsEngine) noexcept = delete;
    ~Engine();

    /*!
     * @brief initialize starter!
     * @returns true if the system starts successfully.
     */
    __tegra_no_discard bool initialize() override;

    /*!
     * System copyrights.
     * @brief Please do not delete or modify them, unless, of course, you have a little respect for the developers.
     * @returns output as static copyright by system.
     */
    __tegra_no_discard static std::string copyright() __tegra_noexcept;

    /*!
     * @brief Convert HTML entities to their corresponding characters.
     * @param The input string.
     * @returns output as string.
     */
    static std::string htmlEntityDecode(const std::string& content);

    /*!
     * @brief String find is used to find the first occurrence of sub-string in the specified string being called upon.
     * @param list contains of strings.
     * @param search is for searching as key.
     * @returns true if the desired content is found and replaced.
     */
    bool findSubString(const std::vector<std::string>& list, const std::string& search);

    /*!
     * @brief Replace all occurrences of a sub string with new string of data.
     * @param data is a full content.
     * @param toSearch is target.
     * @param replaceStr is string for replace with toSearch.
     */
    void findAndReplaceContent(std::string& data, std::string toSearch, std::string replaceStr);

    /*!
     * @brief Replace all links of a sub string with new link.
     * @param data is a full content.
     * @param toSearch is target.
     * @param replaceUrl is string for replace with toSearch.
     */
    void findAndReplaceLink(std::string& data, std::string toSearch, std::string replaceUrl);

    /*!
     * @brief Some links have symptoms that need to be corrected, this function can provide it.
     * @param uri for example [page_one+1] ~ should be page-page1
     * @returns string type of fixed link.
     */
    std::string linkConvertor(const std::string& uri);

    /*!
     * @brief There are some differences in the fields of queries for some drivers that we can filter them with this function.
     * @param fields is list of the fields.
     * @returns as filtered list of fields.
     */
    std::vector<std::string> filteredQueryFields(VectorString& fields);

    /*!
     * @brief The SepratorType enum
     */
    enum class SepratorType : u8
    {
        Comma,
        Dash,
        Slash,
        BackSlash,
        Dot,
        Equal,
        UnderLine,
        Quote,
        DoubleQuote,
        Apostrophe,
        Grave,
        Colon,
        SemiColon,
        Brvbar,
        Lt,
        Gt,
        Percent,
        And,
        Hat,
        Dollar,
        Question,
        Sim,
        Atsign,
        Sharp,
        Exclamation,
        LeftRoundBracket,
        RightRoundBracket,
        LeftSquareBracket,
        RightSquareBracket,
        LeftCurlyBracket,
        RightCurlyBracket
    };

    /*!
     * @brief The SepratorStyle enum
     */
    enum class SepratorStyle : u8 { WithSpace, Mixed };

    /*!
     * @brief join function will implode a vector of strings into a comma-separated.
     * @param strings are list of strings.
     * @param sep is character of seprator.
     * @param sepStyle is style of seprator.
     * @returns as string of result.
     */
    __tegra_no_discard std::string join(const VectorString& strings, const SepratorType& sep, const SepratorStyle& sepStyle) __tegra_noexcept;

    /*!
     * \brief elementErase function will removes certain characters from a string.
     * \param content is the main content of string.
     */
    void elementErase(std::string& content) __tegra_noexcept;

    /*!
     * \brief whiteSpaceLeading function will Reduce multiple whitespaces to a single white space.
     * \param input as string.
     * \return final content output after reducing single white space.
     */
    __tegra_no_discard std::string whiteSpaceReduce(std::string& input) __tegra_noexcept;

    /*!
     * \brief whiteSpaceLeading function will removes leading whitespace from content.
     * \param input as string.
     * \return final content output after leading white spaces.
     */
    __tegra_no_discard std::string whiteSpaceLeading(std::string& input) __tegra_noexcept;

    /*!
     * @brief  It may help to distinguish between tables and views depending on what your naming convention is.
     * @returns string name of prefix.
     */
    static std::string tablePrefix();

    /**
     * Table unicode base.
     * @brief   It may help to distinguish between tables and views depending on what your naming convention is.
     * @returns  string unicode of unicode.
     */
    static std::string tableUnicode();

    /**
     * @brief   It may help to mixing table prefixes for more details.
     * @returns  string final table name after mixed.
     */
    static std::string mixedTablePrefix(const std::string& p, const std::string& t);

    /**
     * @brief   It may help to mixing table prefixes for more details.
     * @returns  string final table name after mixed.
     */
    static std::string table(std::string_view tableName, TableType tableType);

    /**
     * @brief It may help to filter tables.
     * @returns as tables.
     */
    VectorString tableFilter(const VectorString& tables, TableType tableType);

    /*!
     * @brief Sometimes we need to remove dashes from the uri or content based data.
     * @param src is a content source.
     * @returns string of final output.
     */
    __tegra_no_discard std::string removeDashes(const std::string& src) __tegra_const_noexcept;

    /*!
     * @brief We need to get current language based on your selected translator value on page.
     * @returns string for name of language that is used.
     */
    static std::string defaultLanguage();

    /*!
     * @brief Before displaying the contents of the pages, we need to replace some characters.
     * @param content as raw content.
     * @param map as data for replacing.
     * @returns content as string.
     */
    std::string fullReplacer(const std::string& content, const MapString& map);

    /*!
     * @brief setLanguage function sets language from user.
     * @param l as language string.
     */
    void setLanguage(const std::string& l);

    /*!
     * @brief getLanguage function will returns language name as string.
     * @returns string.
     */
    std::string getLanguage();

    /*!
     * @brief A URI is an identifier of a specific resource. Like a page, or book, or a document.
     * @returns uri.
     */
    std::vector <std::string> langUri;

    /*!
     * @brief array Languages available on the system
     * @returns map of languages.
     */
    std::map <std::string, std::string> langs();

    /*!
     * @brief array getting language by path
     * @returns map of languages based on their path.
     */
    std::map <std::string, std::string> langsByPath(const std::string& path);

    /*!
     * @brief Path reducing function.
     * @returns string of reduced path.
     */
    std::string reducePath(const std::string& path);

    /*!
     * @brief Services name.
     * @returns string services name.
     */
    std::vector <std::string> services;

    /*!
     * @brief Recommended container for module settings.
     * @returns array of modules.
     */
    std::vector <std::string> module;

    /*!
     * \brief setIsMultilanguage function will sets bool value into the member.
     */
    void setIsMultilanguage(const bool value);

    /*!
     * \brief isMultilanguage function will returns true if the page url is based on multi-language method such as [en-us, fa-ir].
     * \return bool [true if it's true.]
     */
    bool isMultilanguage() __tegra_const_noexcept;

    /*!
     * \brief Lanuage translator engine.
     */
    Translation::Translator* translator{__tegra_nullptr};

    bool m_multilang {};

    std::string m_languageStr {__tegra_null_str};

    void setPath(const std::string& p);

    mutable std::string currentPath{};
};

/*!
 * \brief The ApplicationData class
 */
struct ApplicationData final
{
    SystemInfo systemInfo{};
    Multilangual::LanguageStruct languageStruct{};
    OptionalString path    {__tegra_unknown};
    OptionalString templateId  {__tegra_unknown};
    OptionalString templateErrorId  {__tegra_unknown};
    OptionalString module  {__tegra_unknown};
    SemanticVersion semanticVersion{};
    Version::ReleaseType releaseType{};
    ///ToDo... We need to add user info and extra data...
};

/*!
 * \brief The Application class
 */
class Application
{
public:
    Application() = default;
    Application(const ApplicationData& appData);
    ~Application();

    static Application* get(const ApplicationData& appData);

    /*!
     * \brief start
     */
    void start();

    OptionalString name() __tegra_const_noexcept;

    OptionalString codeName() __tegra_const_noexcept;

    OptionalString type() __tegra_const_noexcept;

    OptionalString license() __tegra_const_noexcept;

    OptionalString model() __tegra_const_noexcept;

    /*!
     * \brief path as string.
     * \returns string.
     */
    OptionalString path() __tegra_const_noexcept;

    /*!
     * \brief module as module name.
     * \returns string.
     */
    OptionalString module() __tegra_const_noexcept;

    /*!
     * \brief templateId will gets error template id.
     * \returns string.
     */
    OptionalString templateErrorId() __tegra_const_noexcept;

    /*!
     * \brief templateId will gets template id.
     * \returns string.
     */
    OptionalString templateId() __tegra_const_noexcept;

    Scope<Engine>   engine  {};
    Scope<Version>  version {};
    Scope<SystemInfo>  systemInfo {};

    Translation::Translator* translator{__tegra_nullptr}; //alternative translator for engine.
    Multilangual::Language* language{__tegra_nullptr};

private:
    static Application* appPtr;
    static ApplicationData* appDataPtr;
};

TEGRA_NAMESPACE_END

#endif // CORE_HPP
