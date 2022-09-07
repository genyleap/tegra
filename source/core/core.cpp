#ifndef  TEGRA_KERNEL
#define TEGRA_KERNEL
#endif

//!Core feature
#ifdef TEGRA_KERNEL
#ifdef __has_include
# if __has_include("core.hpp")
#   include "core.hpp"
#else
#   error "Tegra's core was not found!"
# endif
#endif
#endif

//! Tegra's Core (Basic Requirements).
#ifdef __has_include
# if __has_include(<requirements>)
#   include <requirements>
#else
#   error "Tegra's requirements was not found!"
# endif
#endif

TEGRA_USING_NAMESPACE Tegra;
TEGRA_USING_NAMESPACE Tegra::System;
TEGRA_USING_NAMESPACE Tegra::View;
TEGRA_USING_NAMESPACE Tegra::eLogger;

TEGRA_NAMESPACE_BEGIN(Tegra::System)

Exception::Exception()
{
    __tegra_safe_instance(m_exceptionData, ExceptionData);
    m_exceptionData->message = "message";
}

Exception::Exception(const Reason& reason, const std::string& message)
{
    __tegra_safe_instance(m_exceptionData, ExceptionData);
    std::string eMessage{};
    switch (reason) {
    case Reason::Core:
        eMessage=":[Core]:";
        break;
    case Reason::Framework:
        eMessage=":[Framework]:";
        break;
    case Reason::IO:
        eMessage=":[IO]:";
        break;
    case Reason::User:
        eMessage=":[User]:";
        break;
    case Reason::System:
        eMessage=":[System]:";
        break;
    case Reason::Other:
        eMessage=":[Other]:";
        break;
    default:
        break;
    }
    m_exceptionData->message = eMessage + message;
}

Exception::~Exception()
{
    __tegra_safe_delete(m_exceptionData);
};

const char* Exception::what() const throw()
{
    return m_exceptionData->message.c_str();
}

void Termination::terminate(TerminateType terminateType)
{
    switch (terminateType) {
    case TerminateType::Unknown:
        Log("The system has been terminated for [Unknown] reason!", LoggerType::Info);
        std::exit(EXIT_FAILURE);
        ///ToDo for more handling...
        break;
    case TerminateType::UnexpectedError:
        Log("The system has been terminated for [UnexpectedError] reason!", LoggerType::Info);
        std::exit(EXIT_FAILURE);
        ///ToDo for more handling...
        break;
    case TerminateType::Violation:
        Log("The system has been terminated for [Violation] reason!", LoggerType::Info);
        std::exit(EXIT_FAILURE);
        ///ToDo for more handling...
        break;
    default:
        break;
    }
}

EngineInterface::EngineInterface()
{
    m_bootParameter = new BootParameter();

         //! Fast Boot
         //! ToDo...
    {
        if(!isset(m_bootParameter->fastBoot)) { m_bootParameter->fastBoot = true; }
    }

         //! System Type
         //! ToDo...
    {
        if(!isset(m_bootParameter->systemType)) { m_bootParameter->systemType = SystemType::Default; }
    }

         //! Page Init Time
         //! ToDo...
    {
        if(!isset(m_bootParameter->pageInitTime)) { m_bootParameter->pageInitTime = 1316615272; }
    }

         //! Page Size
         //! ToDo...
    {
        if(!isset(m_bootParameter->pageSize)) { m_bootParameter->pageSize = 0; }
    }

         //! Page Speed
         //! ToDo...
    {
        if(!isset(m_bootParameter->pageSpeed)) { m_bootParameter->pageSpeed = 0; }
    }

         //! Init Time
         //! ToDo...
    {
        if(!isset(m_bootParameter->initTime)) { m_bootParameter->initTime = 1316615272; }
    }

         //! User Mode
         //! ToDo...
    {
        if(!isset(m_bootParameter->userMode)) { m_bootParameter->userMode = UserMode::Guest; }
    }

         //! System License
         //! ToDo...
    {
        if(!isset(m_bootParameter->systemLicense)) { m_bootParameter->systemLicense = SystemLicense::Free; }
    }

         //! System Status
         //! ToDo...
    {
        if(!isset(m_bootParameter->systemStatus)) { m_bootParameter->systemStatus = SystemStatus::Unknown; }
    }


         //! Sync Device
         //! ToDo...
    {
        if(!isset(m_bootParameter->syncDevice)) { m_bootParameter->syncDevice = SyncDevice::WebOnly; }
    }

         //! Storage Type
         //! ToDo...
    {
        if(!isset(m_bootParameter->storageType)) { m_bootParameter->storageType = StorageType::Empty; }
    }

         //! State Index
         //! ToDo...
    {
        if(!isset(m_bootParameter->stateIndex)) { m_bootParameter->stateIndex = 0x1; }
    }

         //! Save State
         //! ToDo...
    {
        if(!isset(m_bootParameter->saveState)) { m_bootParameter->saveState = "0x9ax0000000"; }
    }

         //! Host Type
    {
#ifdef PLATFORM_WINDOWS
        m_bootParameter->hostType = HostType::Windows;
#elif defined(PLATFORM_LINUX)
        m_bootParameter->hostType = HostType::Linux;
#elif defined(PLATFORM_MAC)
        m_bootParameter->hostType = HostType::macOS;
#else
        m_bootParameter->hostType = HostType::Unknown;
#endif
    }

}

EngineInterface::~EngineInterface()
{
    __tegra_safe_delete(m_bootParameter);
}

std::time_t EngineInterface::getInitTime()
{

}

Optional<std::string> EngineInterface::getSaveState()
{
    if (isset(m_bootParameter->saveState)) {
        return m_bootParameter->saveState;
    } else {
        return std::nullopt;
    }
}

Optional<u32> EngineInterface::getPageSize()
{
    if (isset(m_bootParameter->pageSize)) {
        return m_bootParameter->pageSize;
    } else {
        return std::nullopt;
    }
}

std::time_t EngineInterface::getPageInitTime()
{
  //ToDo...
}

Optional<u32> EngineInterface::getPageSpeed()
{
    if (isset(m_bootParameter->pageSpeed)) {
        return m_bootParameter->pageSpeed;
    } else {
        return std::nullopt;
    }
}

Optional<s32> EngineInterface::getStateIndex()
{
    if (isset(m_bootParameter->stateIndex)) {
        return m_bootParameter->stateIndex;
    } else {
        return std::nullopt;
    }
}

bool EngineInterface::getFastBoot()
{
    return m_bootParameter->fastBoot;
}

Optional<HostType> EngineInterface::getHostType()
{
    if (isset(m_bootParameter->hostType)) {
        return m_bootParameter->hostType;
    } else {
        return std::nullopt;
    }
}

Optional<UserMode> EngineInterface::getUserMode()
{
    if (isset(m_bootParameter->userMode)) {
        return m_bootParameter->userMode;
    } else {
        return std::nullopt;
    }
}

Optional<SyncDevice> EngineInterface::getSyncMode()
{
    if (isset(m_bootParameter->syncDevice)) {
        return m_bootParameter->syncDevice;
    } else {
        return std::nullopt;
    }
}

Optional<SystemType> EngineInterface::getSystemType()
{
    if (isset(m_bootParameter->systemType)) {
        return m_bootParameter->systemType;
    } else {
        return std::nullopt;
    }
}

Optional<SystemLicense> EngineInterface::getSystemLicense()
{
    if (isset(m_bootParameter->systemLicense)) {
        return m_bootParameter->systemLicense;
    } else {
        return std::nullopt;
    }
}

Optional<SystemStatus> EngineInterface::getSystemStatus()
{
    if (isset(m_bootParameter->systemStatus)) {
        return m_bootParameter->systemStatus;
    } else {
        return std::nullopt;
    }
}

Engine::Engine()
{
    ///< New instances.
    __tegra_safe_instance(translator, Translation::Translator);
    __tegra_safe_instance(viewIndex, ViewIndex);
    Scope<Configuration> config(new Configuration(ConfigType::File));
    config->init(SectionType::SystemCore);
}

Engine::~Engine()
{
    __tegra_safe_delete(translator);
    __tegra_safe_delete(viewIndex);
}

bool Engine::initialize()
{
    bool res{false};
    auto config = Configuration(ConfigType::File);
    config.init(SectionType::SystemCore);
    //! Database Connection
    Scope<Database::Connection>con(new Database::Connection());
    ApplicationData appData;
    {
        appData.path    = "";
        appData.module  = "starter";
    }
    auto lang = Multilangual::Language(appData.path.value());
    {
        Application::get(appData)->engine->setLanguage(lang.getLanguage());
        Application::get(appData)->translatorPtr->setFile(lang.languageSupport());
    }
    ///< Parsing
    if(Application::get(appData)->translatorPtr->parse()) {
        res = true;
        if(System::DeveloperMode::IsEnable)
            Log("Language data has been parsed!", LoggerType::Done); ///< Parsing Done!
    } else {
        res = false;
        if(System::DeveloperMode::IsEnable)
            Log("No parsing...!", LoggerType::Failed);  ///< Parsing Failed!
    }
    return res;
}


std::string Engine::copyright() __tegra_noexcept
{
#if defined(TEGRA_COPYRIGHT)
    return TEGRA_COPYRIGHT;
#else
  // TODO... add output for html template.
    Termination t;
    t.terminate(TerminateType::Violation);
#endif
}

std::string command(const std::string& cmd) {
    // Support Unix base.
    std::string c = cmd;
    std::string data;
    FILE *stream;
    const int max_buffer = 256;
    char buffer[max_buffer];
    c.append(" 2>&1");
#ifdef PLATFORM_WINDOWS
    stream = _popen(c.c_str(), "r");
#else
    stream = popen(c.c_str(), "r");
#endif
    if (stream)
    {
        while (!feof(stream))
            if (fgets(buffer, max_buffer, stream) != nullptr)
                data.append(buffer);
#ifdef PLATFORM_WINDOWS
        _pclose(stream);
#else
        pclose(stream);
#endif
    }
    return data;
}

std::string convertStream(std::stringstream const& data) __tegra_noexcept
{
  //ToDo...
}

std::string Engine::htmlEntityDecode(const std::string& content)
{
    const std::string subs[] = {
        "& #34;",
        "&quot;",
        "& #39;",
        "&apos;",
        "& #38;",
        "&amp;",
        "& #60;",
        "&lt;",
        "& #62;",
        "&gt;",
        "&34;",
        "&39;",
        "&38;",
        "&60;",
        "&62;"
    };

    const std::string reps[] = {
        "\"",
        "\"",
        "'",
        "'",
        "&",
        "&",
        "<",
        "<",
        ">",
        ">",
        "\"",
        "'",
        "&",
        "<",
        ">"
    };

    std::string process = content;
    size_t found;

    for (int j = 0; j < 15; j++) {
        do {
            found = process.find(subs[j]);
            if (found != std::string::npos)
                process.replace(found, subs[j].length(), reps[j]);
        } while (found != std::string::npos);
    }

    return process;
}

bool Engine::findSubString(const std::vector<std::string>& list, const std::string& search)
{
    for (const std::string& str : list) {
        if (str.find(search) != std::string::npos) {
            return true;
        }
    }
    return false;
}

void Engine::findAndReplaceContent(std::string& data, std::string toSearch, std::string replaceStr)
{
    //! Get the first occurrence
    size_t pos = data.find(toSearch);
    //! Repeat till end is reached
    while (pos != std::string::npos) {
        // Replace this occurrence of Sub String
        data.replace(pos, toSearch.size(), replaceStr);
        // Get the next occurrence from the current position
        pos = data.find(toSearch, pos + replaceStr.size());
    }
}

void Engine::findAndReplaceLink(std::string& data, std::string toSearch, std::string replaceUrl)
{
    //! Get the first occurrence
    size_t pos = data.find(toSearch);
    //! Repeat till end is reached
    while (pos != std::string::npos) {
        // Replace this occurrence of Sub String
        data.replace(pos, toSearch.size(), replaceUrl);
        // Get the next occurrence from the current position
        pos = data.find(toSearch, pos + replaceUrl.size());
    }
}

std::string Engine::linkConvertor(const std::string& uri)
{
    //! Get the String
    std::string str = uri;
    // Traverse the string character by character.
    for (int i = 0; i < str.length(); ++i) {
        // Changing the ith character
        // to '-' if it's a space.
        if (str[i] == ' ' || str[i] == '_' || str[i] == ',') {
            str[i] = '-';
        } else if (str[i] == '.') {
            str[i] = '_';
        } else if (str[i] == '+') {
            str[i] = 'plus';
        }
    }
    std::for_each(str.begin(), str.end(), [](char& c) { c = std::tolower(c); });
    return str;
}

std::vector<std::string> Engine::filteredQueryFields(VectorString& fields)
{
    Scope<Configuration> config(new Configuration(ConfigType::File));
    if(config->currentRdbms() == Database::TEGRA_RDBMS::PostgreSQL)
        ///!Nothing...
        if(config->currentRdbms() == Database::TEGRA_RDBMS::MySQL)
        {
            std::for_each(fields.begin(), fields.end(), [](auto& s){ s.insert(0, "`");});
            for(auto& s : fields)
            {
                s+="`";
            }
        }
    return fields;
}

std::string Engine::tablePrefix()
{
    //Table prefix
    std::string prefix = Configuration::GET["table_prefix"].asString();
    if(!isset(prefix)) {
        if(System::DeveloperMode::IsEnable)
            Log("Table prefix not found!", LoggerType::Warning);
    }
    return prefix;
}

std::string Engine::tableUnicode()
{
    //Table unicode
    std::string unicode = Configuration::GET["table_unicode"].asString();
    if(!isset(unicode)) {
        if(System::DeveloperMode::IsEnable)
            Log("Table unicode not found!", LoggerType::Warning);
    }
    return unicode;
}

std::string Engine::mixedTablePrefix(const std::string& p, const std::string& t)
{
    std::string res;
    res = FROM_TEGRA_STRING(p) + FROM_TEGRA_STRING(t);
    if(!isset(res)) {
        if(System::DeveloperMode::IsEnable)
            Log("Table prefix not found!", LoggerType::Warning);
    }
    return res;
}

std::string Engine::table(std::string_view tableName, TableType tableType)
{
    std::string res{};
    res = FROM_TEGRA_STRING(mixedTablePrefix(tablePrefix(), tableName.data()));
    if(!isset(res)) {
        if(System::DeveloperMode::IsEnable)
            Log("Table not found!", LoggerType::Warning);
    }
    return res;
}

VectorString Engine::tableFilter(const std::vector<std::string>& tables, TableType tableType)
{
    std::string valueStruct = Configuration::GET["table_value_struct"].asString();
    std::vector<std::string> res{};
    switch (tableType)
    {
    case TableType::MixedStruct:
        res=tables;
        break;
    case TableType::KeyStruct:
        res=tables;
        for(const auto& t : tables) {
            if(t.ends_with(valueStruct)) {
                res.erase(std::remove(res.begin(), res.end(), t), res.end());
            }
        }
        break;
    case TableType::ValueSturct:
        res=tables;
        for(const auto& t : tables) {
            if(!t.ends_with(valueStruct)) {
                res.erase(std::remove(res.begin(), res.end(), t), res.end());
            }
        }
        break;
    default:
        res=tables;
        break;
    }

    return res;
}

std::string Engine::fullReplacer(const std::string& content, const MapString& map)
{
    std::string rawContent = content;
    // Get the first occurrence
    size_t pos;
    for(const auto& r : map) {
        pos = rawContent.find(r.first);
        // Repeat till end is reached
        while( pos != std::string::npos)
        {
            // Replace this occurrence of Sub String
            rawContent.replace(pos, r.first.size(), r.second);
            // Get the next occurrence from the current position
            pos = rawContent.find(r.first, pos + r.first.size());
        }
    }
    return rawContent;
}

void Engine::setLanguage(const std::string& l)
{
    m_languageStr = l;
}

std::string Engine::getLanguage()
{
    return m_languageStr;
}

std::map <std::string, std::string> Engine::langs()
{
    std::map<std::string, std::string> l = {};
    //!Getting language from configuration file
    for(auto &var : Configuration::GET["langs"]) {
        l.insert(PairString(var["uri"].asString(),var["code"].asString()));
        this->langUri.push_back("/" + std::string(var["uri"].asString()));
        this->langUri.push_back("/" + std::string(var["uri"].asString()) + "/");
    }
    return l;
}

std::map <std::string, std::string> Engine::langsByPath(const std::string& path)
{
    std::map<std::string, std::string> l = {};
    //!Getting language from configuration file
    for(auto &var : Configuration::GET["langs"]) {
        l.insert(PairString(var["uri"].asString(),var["code"].asString()));
        this->langUri.push_back("/" + std::string(var["uri"].asString()));
        this->langUri.push_back("/" + std::string(var["uri"].asString()) + "/");
        this->langUri.push_back("/" + std::string(var["uri"].asString()) + "/" + std::string(path.empty() ? "" : path));
        this->langUri.push_back("/" + std::string(var["uri"].asString()) + "/" + std::string(path.empty() ? "" : path + "/"));
    }
    return l;
}

std::string Engine::reducePath(const std::string& path)
{
    std::string pathEnd{};
    std::string cl = defaultLanguage();
    for (const auto& l: langsByPath(path))
    {
        if (path.ends_with("/"))
        {
            pathEnd = {
                "/" + l.first + "/"
            };
        } else {
            pathEnd = {
                "/" + l.first + ""
            };
        }
        if (path == pathEnd) {
            cl = l.second;
        }
    }
    return cl;
}

std::string Engine::removeDashes(const std::string& src) __tegra_const_noexcept
{
    std::string command = src;
    command.erase(std::remove(command.begin(), command.end(), '/'), command.end());
    return command;
}

std::string Engine::defaultLanguage()
{
    //Default language
    std::string def = Configuration::GET["default_lang"].asString();
    return def;
}

std::string Engine::join(const std::vector<std::string>& strings,  const SepratorType& sep, const SepratorStyle& sepStyle) __tegra_noexcept
{
    std::string delim{__tegra_null_str};
    switch (sep) {
    case SepratorType::Comma:
        delim=",";
        break;
    case SepratorType::Dash:
        delim="-";
        break;
    case SepratorType::Slash:
        delim="/";
        break;
    case SepratorType::BackSlash:
        delim="\\";
        break;
    case SepratorType::Dot:
        delim=".";
        break;
    case SepratorType::Equal:
        delim="=";
        break;
    case SepratorType::Quote:
        delim="'";
        break;
    case SepratorType::Apostrophe:
        delim="'";
        break;
    case SepratorType::Grave:
        delim="`";
        break;
    case SepratorType::DoubleQuote:
        delim="\"";
        break;
    case SepratorType::Colon:
        delim=":";
        break;
    case SepratorType::SemiColon:
        delim=";";
        break;
    case SepratorType::Brvbar:
        delim="¦";
            break;
    case SepratorType::Lt:
        delim="<";
        break;
    case SepratorType::Gt:
        delim=">";
        break;
    case SepratorType::Percent:
        delim="%";
        break;
    case SepratorType::And:
        delim="&";
        break;
    case SepratorType::Sharp:
        delim="#";
        break;
    case SepratorType::Dollar:
        delim="$";
        break;
    case SepratorType::Atsign:
        delim="@";
        break;
    case SepratorType::Sim:
        delim="~";
        break;
    case SepratorType::Question:
        delim="?";
        break;
    case SepratorType::Exclamation:
        delim="!";
        break;
    case SepratorType::Hat:
        delim="^";
        break;
    case SepratorType::LeftCurlyBracket:
        delim="[";
        break;
    case SepratorType::RightCurlyBracket:
        delim="]";
        break;
    case SepratorType::LeftSquareBracket:
        delim="{";
        break;
    case SepratorType::RightSquareBracket:
        delim="}";
        break;
    case SepratorType::LeftRoundBracket:
        delim="(";
        break;
    case SepratorType::RightRoundBracket:
        delim=")";
        break;
    default:
        delim=",";
        break;
    }

    switch (sepStyle) {
    case SepratorStyle::WithSpace:
        delim.append(" ");
        break;
    case SepratorStyle::Mixed:
        delim.append("");
        break;
    default:
        break;
    }

    const auto res = std::accumulate(
        strings.begin(), strings.end(),
        std::string(),[&delim, sepStyle](const std::string& x, const std::string& y)
        {
            return x.empty() ? y : x + delim + y;
        });

    return res;
}

void Engine::elementErase(std::string& content) noexcept
{
    try {
        std::erase_if(content, [](const char c) {
            return c == '`' or c == '/' or c =='\\' or c == '~' or c == '?'
                   or c == '|' or c == '(' or c == ')' or c == '[' or c == ']'
                   or c == '{' or c == '}' or c == '-';
        });
    }
    catch(const Exception& e) {
        if(DeveloperMode::IsEnable) {
            Log(FROM_TEGRA_STRING(e.what()), eLogger::LoggerType::Critical);
        }
    }
}

std::string Engine::whiteSpaceReduce(std::string& input) noexcept
{
    try {
        if(!input.empty()) {
            input.erase(std::remove(input.begin(), input.end(), ' '), input.end());
        }
    }
    catch(const Exception& e) {
        if(DeveloperMode::IsEnable) {
            Log(FROM_TEGRA_STRING(e.what()), eLogger::LoggerType::Critical);
        }
    }
    return input;
}

std::string Engine::whiteSpaceLeading(std::string& input) noexcept
{
    try {
        if(!input.empty()) {
            while (std::isspace(*input.begin())) {
                input.erase(input.begin());
            }
        }
    }
    catch(const Exception& e) {
        if(DeveloperMode::IsEnable) {
            Log(FROM_TEGRA_STRING(e.what()), eLogger::LoggerType::Critical);
        }
    }
    return input;
}

void Engine::setIsMultilanguage(const bool value)
{
    m_multilang = value;
}

bool Engine::isMultilanguage() const noexcept
{
    bool ret = {false};
    isset(m_multilang) ? ret = true : false;
    return ret;
}

void Engine::setPath(const std::string &p)
{
    currentPath = p;
}

Technique::Technique(const Framework::HttpRequestPtr& request)
{
    const auto r = request->getParameter(FROM_TEGRA_STRING(Technique::method));
    if(r == Technique::NONE) {
        registerMethod(true, false, false);
    } else if(r == Technique::AJAX) {
        registerMethod(false, true, false);
    } else if(r == Technique::ANGULAR) {
        registerMethod(false, false, true);
    }
}

bool Technique::none()
{
    if (isset(m_none)) {
        return m_none;
    } else {
        return false;
    }
}

bool Technique::ajax()
{
    if (isset(m_ajax)) {
        return m_ajax;
    } else {
        return false;
    }
}

bool Technique::angular()
{
    if (isset(m_angular)) {
        return m_angular;
    } else {
        return false;
    }
}

Technique::~Technique()
{

}

void Technique::registerMethod(bool none, bool ajax, bool angular)
{
    m_none      =   none;
    m_ajax      =   ajax;
    m_angular   =   angular;
}

TEGRA_NAMESPACE_END
