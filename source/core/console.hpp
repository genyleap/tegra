#ifndef TEGRA_CONSOLE_HPP
#define TEGRA_CONSOLE_HPP

//! Tegra's Core (Basic Requirements).
#ifdef __has_include
# if __has_include(<requirements>)
#   include <requirements>
#else
#   error "Tegra's requirements are not found!"
# endif
#endif

TEGRA_NAMESPACE_BEGIN(Tegra::Console)

class Output {
 public:
  Output();
  ~Output();
}; ///ToDo...

/*
 * The standard output stream is the default destination of characters
 * determined by the environment. This destination may be shared with more
 * standard objects (such as cerr or clog).
 */

#define tegraPrint(x) printf(#x "\n")

#define paster(n) printf("token" #n " = %d", token##n)

static std::ostream print(std::cout.rdbuf());

/*
 * The standard input stream is a source of characters determined by the
 * environment. It is generally assumed to be input from an external source,
 * such as the keyboard or a file.
 */

static std::istream get(std::cin.rdbuf());

/*
 * The standard error stream is a destination of characters determined by the
 * environment. This destination may be shared by more than one standard object
 * (such as cout or clog).
 */

static std::ostream error(std::cerr.rdbuf());

/*
 * The standard logging stream is a destination of characters determined by the
 * environment. This destination may be shared by more than one standard object
 * (such as cout or cerr).
 */

static std::ostream log(std::clog.rdbuf());

/*
 * The standard input stream is a source of characters determined by the
 * environment. It is generally assumed to be input from an external source,
 * such as the keyboard or a file.
 */

static std::wistream get_wide(std::wcin.rdbuf());

/*
 * The standard input stream is a source of characters determined by the
 * environment. It is generally assumed to be input from an external source,
 * such as the keyboard or a file.
 */

static std::wostream print_wide(std::wcout.rdbuf());

/*
 * The standard error stream is a destination of characters determined by the
 * environment. This destination may be shared by more than one standard object
 * (such as wcout or wclog).
 */

static std::wostream error_wide(std::wcerr.rdbuf());

/*
 * The standard logging stream is a destination of characters determined by the
 * environment. This destination may be shared by more than one standard object
 * (such as wcout or wcerr).
 */

static std::wistream log_wide(std::wclog.rdbuf());

#define newline '\n'

TEGRA_NAMESPACE_END

#endif  // TEGRA_CONSOLE_HPP
