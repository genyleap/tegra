/*!
 * MIT License
 *
 * Copyright (c) 2022 The Genyleap. All rights reserved.
 * Copyright (c) 2022 Kambiz Asadzadeh.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

#ifndef TEGRA_LINK_PARSER_HPP
#define TEGRA_LINK_PARSER_HPP

//! Tegra's Core (Basic Requirements).
#ifdef __has_include
# if __has_include(<requirements>)
#   include <requirements>
#else
#   error "Tegra's requirements was not found!"
# endif
#endif

TEGRA_NAMESPACE_BEGIN(Tegra)

/*!
 * \brief The LinkParser class
 */
class LinkParser
{
public:
    LinkParser();
    ~LinkParser();
    /*!
     * \brief parse function will parse the simple url.
     * \param url is the url string.
     */
    void parse(std::string& url);

    /*!
     * \brief items will returns elements of link.
     * \return as array.
     */
    VectorString items();

private:
    VectorString m_item{};
};

TEGRA_NAMESPACE_END

#endif // TEGRA_LINK_PARSER_HPP
