//! Tegra's Message.
#ifdef __has_include
# if __has_include("message.hpp")
#   include "message.hpp"
#else
#   error "Tegra's message was not found!"
# endif
#endif

TEGRA_USING_NAMESPACE Tegra;
TEGRA_USING_NAMESPACE Tegra::System;
TEGRA_USING_NAMESPACE Tegra::eLogger;

TEGRA_NAMESPACE_BEGIN(Tegra)

/*!
 * \brief Constructs message class.
 */
Message::Message()
{
    __tegra_safe_instance(m_messageData, MessageData);
}

/*!
 * \brief Destroys the message class.
 */
Message::~Message()
{
    __tegra_safe_delete(m_messageData);
}

bool Message::create(const MessageData& messageData) __tegra_const_noexcept
{
    if(DeveloperMode::IsEnable)
    {
        Log("Post ID:" + std::to_string(messageData.postId.value()), eLogger::LoggerType::Info);
        Log("Message:" + messageData.message.value(), eLogger::LoggerType::Info);
        Log("Author:" + messageData.author.value(), eLogger::LoggerType::Info);
        switch (messageData.style) {
        case MessageStyle::Information:
            ///ToDo...
            break;
        default:
            break;
        }
    }
    ///ToDo...
    return true;
}

bool Message::edit(const u32 id, const MessageData& messageData) __tegra_const_noexcept
{
    ///ToDo...
    return true;
}

bool Message::remove(const u32 id, const MessageData& messageData) __tegra_const_noexcept
{
    ///ToDo...
    return true;
}

TEGRA_NAMESPACE_END

