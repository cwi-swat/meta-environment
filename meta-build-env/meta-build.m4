
# META_ left in configure is the sign a macro was not defined, or there was 
# a typo in a macro invocation.
m4_pattern_forbid([^META_])

# Invokes all macros that always need to be invoked for a package.
AC_DEFUN([META_SETUP],
[
  AM_INIT_AUTOMAKE(esyscmd([grep "name[:blank:]*=.*" package | cut -f2 -d= | tr -d '[:blank:]']),esyscmd([grep "version[:blank:]*=.*" package | cut -f2 -d= | tr -d '[:blank:]']))
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
  $1[]_FOUND_PREFIX=`$PKG_CONFIG --variable=prefix "$2"`
  if test -z "$$1[]_FOUND_PREFIX"; then
    AC_MSG_ERROR([package $2 does not specify its prefix in the pkg-config file.
           Report this error to the maintainer of this package.])
  fi

  if test "${$1[]_PREFIX:+set}" = set; then
    if test "x$$1[]_PREFIX" = "x$$1[]_FOUND_PREFIX"; then
      AC_MSG_RESULT([explicitly set: $$1[]_PREFIX])
    else
      AC_MSG_ERROR([prefix of $2 explicitly set to $$1[]_PREFIX,
            but pkg-config found $2 at $$1[]_FOUND_PREFIX.
            Please check your PKG_CONFIG_PATH, or remove $2 from $$1[]_FOUND_PREFIX, 
            or install the packages at a unique location.])
    fi
  else
    AC_MSG_RESULT([$$1[]_PREFIX])
  fi

  $1[]_PREFIX="$1[]_FOUND_PREFIX"

  AC_SUBST([$1_CFLAGS])
  AC_SUBST([$1_LIBS])
  AC_SUBST([$1_PREFIX])
])
