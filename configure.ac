#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ(2.61)
AC_INIT([pwantools], 0.1.0)
AC_CONFIG_SRCDIR([src/main.h])
AC_CONFIG_HEADER([config.h])
AM_INIT_AUTOMAKE([-Wall -Werror])


# Checks for programs.
AC_PROG_CXX
AC_PROG_CC
AC_PROG_CXXCPP
AC_PROG_INSTALL
AX_BOOST_BASE([1.37.0])
AX_BOOST_THREAD
AX_BOOST_FILESYSTEM

CFLAGS="$CFLAGS -Wall -Werror -Wextra -pedantic"
CXXFLAGS="$CXXFLAGS -Wall -Werror -Wextra -pedantic"

# Checks for libraries.

# Checks for header files.

# Checks for typedefs, structures, and compiler characteristics.

# Checks for library functions.

AC_CONFIG_FILES([Makefile
                 src/Makefile])
AC_OUTPUT
