//! Tegra's Tags.
#ifdef __has_include
# if __has_include("tags.hpp")
#   include "tags.hpp"
#else
#   error "Tegra's tags was not found!"
# endif
#endif

TEGRA_USING_NAMESPACE Tegra;

TEGRA_NAMESPACE_BEGIN(Tegra)

/*!
 * \brief Constructs an abstract tags class.
 */
Tags::Tags()
{
    __tegra_safe_instance(m_tagsData, TagsData);
    __tegra_safe_instance(m_tagList, TagList);
}

/*!
 * \brief Destroys the tags class.
 */
Tags::~Tags()
{
    __tegra_safe_delete(m_tagsData);
    __tegra_safe_delete(m_tagList);
}

void Tags::registerTag(const TagsData& tag) __tegra_const_noexcept
{
    {
        m_tagsData->id = tag.id;
        m_tagsData->title = tag.title;
    }
    //For tag list
    if(insertIntoDb(tag))
        m_tagList->push_back(tag);
    ///ToDo...
}

TagsData Tags::getTags() __tegra_const_noexcept
{
    return *m_tagsData;
}

TagList Tags::getList() __tegra_const_noexcept
{
    return *m_tagList;
}

bool Tags::removeTag(const u32 id) __tegra_const_noexcept
{
    ///ToDo...
    return false;
}

bool Tags::updateTag(const u32 id, const TagsData &tag) __tegra_const_noexcept
{
    ///ToDo...
    return false;
}

bool Tags::insertIntoDb(const TagsData& tag) __tegra_const_noexcept
{
    ///ToDo...
    return true;
}

TEGRA_NAMESPACE_END
