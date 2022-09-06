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
    mTagsData.id = 1;
    mTagsData.title = "test";
}

/*!
 * \brief Destroys the tags class.
 */
Tags::~Tags()
{
}

void Tags::registerTag(const TagsData& tag) __tegra_noexcept
{
    mTagsData.id = tag.id.value();
    mTagsData.title = tag.title.value();
    //For tag list
        if(insertIntoDb(tag))
        mTagList.push_back(tag);
    ///ToDo...
}

TagsData Tags::getTags() __tegra_const_noexcept
{
    //    return *mTagsDataPtr;
}

TagList Tags::getList() __tegra_const_noexcept
{
  //return *mTagListPtr;
}

bool Tags::removeTag(const u32 id) __tegra_const_noexcept
{
  ///ToDo...
    //    return false;
}

bool Tags::updateTag(const u32 id, const TagsData &tag) __tegra_const_noexcept
{
  ///ToDo...
    //    return false;
}

bool Tags::insertIntoDb(const TagsData& tag) __tegra_const_noexcept
{
  ///ToDo...
    //    return true;
}

TEGRA_NAMESPACE_END
