
# META_ left in configure is the sign a macro was not defined, or there was 
# a typo in a macro invocation.
m4_pattern_forbid([^META_])

# Invokes all macros that always need to be invoked for a package.
AC_DEFUN([META_SETUP],
[
  AC_PREREQ([2.59])
  AC_CONFIG_SRCDIR([configure])

  AM_INIT_AUTOMAKE(esyscmd([grep "name[:blank:]*=.*" package | cut -f2 -d= | tr -d '[:blank:]']),esyscmd([grep "version[:blank:]*=.*" package | cut -f2 -d= | tr -d '[:blank:]']))
  AC_CONFIG_FILES(esyscmd([printf $(grep "name[:blank:]*=.*" package | cut -f2 -d= | tr -d '[:blank:]')]).pc)

  AM_MAINTAINER_MODE

  AC_MSG_CHECKING([whether CFLAGS is set])
  if test "${CFLAGS+set}" = set; then
    AC_MSG_RESULT([yes])
  else
    if  test "$USE_MAINTAINER_MODE" = "yes"; then
      CFLAGS="-Wall -Werror -g -O2"
      AC_MSG_RESULT([no, setting to maintainer default ($CFLAGS)])
    else
      AC_MSG_RESULT([no])
    fi
  fi

  META_BUNDLE_PKG_CONFIG_PATH
])

# META_REQUIRE_PACKAGE(OPTION)
# --------------
# Check for another package
# Declaring the option --with-OPTION=ARGNAME to specify the location of
# the package NAME.
#
# Store the result in the variable which name is OPTION upper cased,
# using underscore for non letters.  $DEFAULT (note the $) is its
# default value.
#
AC_DEFUN([META_REQUIRE_PACKAGE],
[m4_pushdef([AC_Var], AS_TR_CPP([$1]))dnl
AC_ARG_WITH([$1],
            [AS_HELP_STRING([--with-$1=DIR], [use $1 at DIR @<:@find with pkg-config@:>@])],
	    [AC_Var[]_PREFIX=$withval],
	    [])

  AC_MSG_CHECKING([whether location of $1 is explicitly set using --with-$1])
  if test "${AC_Var[]_PREFIX:+set}" = set; then
    AC_MSG_RESULT([yes])
    PKG_CONFIG_PATH="$AC_Var[]_PREFIX/lib/pkgconfig:${PKG_CONFIG_PATH}"
    export PKG_CONFIG_PATH
  else
    AC_MSG_RESULT([no])
  fi

  META_REQUIRE_PACKAGE_USING_PKGCONFIG(AC_Var,[$1])

m4_popdef([AC_Var])dnl
])

# META_REQUIRE_PACKAGE_USING_PKGCONFIG(VARIABLE,MODULE)
#
# Checks the existance of package 'MODULE' and sets the 
# variables VARIABLE_PREFIX, VARIABLE_CFLAGS, and VARIABLE_LIBS
#
# ------------------
AC_DEFUN([META_REQUIRE_PACKAGE_USING_PKGCONFIG],
[AC_ARG_VAR([$1][_PREFIX], [prefix for $1, overriding pkg-config])dnl
 PKG_CHECK_MODULES([$1],[$2])

  AC_MSG_CHECKING([prefix of package $2])
  $1[]_FOUND_PREFIX=$($PKG_CONFIG --variable=prefix "$2")
  if test -z "$$1[]_FOUND_PREFIX"; then
    AC_MSG_ERROR([package $2 does not specify its prefix in the pkg-config file.
           Report this error to the maintainer of this package.])
  fi

  if test "${$1[]_PREFIX:+set}" = set; then
    AC_MSG_RESULT([explicitly set: $$1[]_PREFIX])

    AC_MSG_CHECKING([if package $2 at this prefix equals the explicitly set package])
    # in a bundle, the package will not yet be installed.
    if test "${meta_bundled_packages:+set}" = set; then
        AC_MSG_RESULT([skipped (bundle)])
    else
      # compare found prefix to the actual prefix out of the .pc file at the given prefix
      if test -e "$$1[]_PREFIX/lib/pkgconfig/$2.pc"; then
        $1[]_ACTUAL_PREFIX="$(grep 'prefix=.*' $$1[]_PREFIX/lib/pkgconfig/$2.pc | cut -f2 -d= | tr -d '@<:@:blank:@:>@')"
        if test "x$$1[]_ACTUAL_PREFIX" = "x$$1[]_FOUND_PREFIX"; then
          AC_MSG_RESULT([yes])
        else
          AC_MSG_RESULT([no])
          AC_MSG_ERROR([prefix of $2 explicitly set to $$1[]_PREFIX,
            but pkg-config found $2 at $$1[]_FOUND_PREFIX.
            Please check your PKG_CONFIG_PATH, or remove $2 from $$1[]_FOUND_PREFIX, 
            or install the packages at a unique location.])
        fi
      else
        AC_MSG_RESULT([cannot check])
        AC_MSG_ERROR([$2 does not provide a pkg-config file at $$1[]_PREFIX/lib/pkgconfig/$2.pc. Please check your installation.])
      fi
    fi
  else
    AC_MSG_RESULT([$$1[]_FOUND_PREFIX])
  fi

  $1[]_PREFIX="$1[]_FOUND_PREFIX"

  AC_SUBST([$1_CFLAGS])
  AC_SUBST([$1_LIBS])
  AC_SUBST([$1_PREFIX])
])

# Sets the PKG_CONFIG_PATH if this package is in a bundle.
AC_DEFUN([META_BUNDLE_PKG_CONFIG_PATH],
[
  AC_ARG_WITH([bundled-packages],
    [AS_HELP_STRING([--with-bundled-packages=PKGS], [package is installed from a bundle of PKGS @<:@none@:>@])],
    [meta_bundled_packages=$withval],
    [meta_bundled_packages=])

  AC_MSG_CHECKING([if PKG_CONFIG_PATH needs to be extended for bundled packages])
  if test "${meta_bundled_packages:+set}" = set; then
    for pkg in $meta_bundled_packages; do
      PKG_CONFIG_PATH="$(dirname $(pwd))/$pkg:${PKG_CONFIG_PATH}"
    done
    AC_MSG_RESULT([yes])
  else
    AC_MSG_RESULT([no])
  fi
])
