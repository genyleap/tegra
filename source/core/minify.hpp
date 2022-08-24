/*!
 * @file        minify.hpp
 * @brief       This file is part of the Tegra System.
 * @details     Minify system for file and contents.
 * @author      <a href='https://www.kambizasadzadeh.com'>Kambiz Asadzadeh</a>
 * @package     The Genyleap
 * @since       29 Aug 2022
 * @copyright   Copyright (c) 2022 The Genyleap. All rights reserved.
 * @license     https://github.com/genyleap/tegra/blob/main/LICENSE.md
 *
 */

#ifndef MINIFY_HPP
#define MINIFY_HPP

#include "common.hpp"

TEGRA_NAMESPACE_BEGIN(Tegra)

struct MinifyStruct final
{
    /** @var string Path to a directory on the server */
    std::string path{};

    /** @var string HTTP directory path */
    std::string http{};
};

/*!
 * \brief JS and CSS obfuscator minifier
 */
class Minify
{
public:
    Minify();
    Minify(const Minify& rhsMinify) = delete;
    Minify(Minify&& rhsMinify) noexcept = delete;
    Minify& operator=(const Minify& rhsMinify) = delete;
    Minify& operator=(Minify&& rhsMinify) noexcept = delete;
    ~Minify();

    /** Obfuscation css handler
     * @param array source Files to be compressed
     * @param string dest The file where you want to put the result
     */
    void cssGenerator(const std::vector<std::string>& source, const std::string& dest);

    /** Javascript obfuscator
     * @param string|array source Files to be compressed
     * @returns string Path to compressed file for HTTP access
     */

    std::string script(const std::vector<std::string>& source);

    /** Obfuscation js handler
     * @param array source Files to be compressed
     * @param string dest The file where you want to put the result
     */
    void scriptGenerator(const std::string& source, const std::string& dest);

    /** Create a cache for arbitrary files (compressed css, javascript, images, etc.)
     * @param string file Name of the file where the result will be stored
     * @param string|array List of source files for which fileMtime will be checked (last modification time of the file)
     * @param callback generator Cache generator, the method will receive 2 variables as input: source and the full path to the file where the result should be saved.
     * @returns string */
    void getFile(const std::string& file,const std::vector<std::string>& source, const std::string& generator);

    /** Generate a relative path to navigate from one directory to another
     * @param string a Path to the first directory
     * @param string b Path to second directory
     * @returns string For example: ../../aa/bb/cc
     */
    std::string shortPathTo(const std::string& a, const std::string& b);

private:
    MinifyStruct* m_minifyStruct;

};

TEGRA_NAMESPACE_END

#endif  // MINIFY_HPP
