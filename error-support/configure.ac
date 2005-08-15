dnl $Id$

AC_INIT
AC_CONFIG_SRCDIR([configure.ac])
GLT_INIT_PACKAGE
AC_PREREQ(2.59)

dnl Nota Bene:
dnl Do not add any dependencies on other packages here! 
dnl That would exclude such a package from using the ErrorAPI,
dnl because it would introduce a circular dependency.

AM_MAINTAINER_MODE

AC_AIX
AC_PROG_CC
AC_PROG_LIBTOOL

AC_ARG_WITH(cflags,
   [  --with-cflags=CFLAGS    standard options of c compiler],
   CFLAGS=${withval},
   if test "a${GCC}" = "ayes"; then
     CFLAGS="-Wall -g -O2"
   fi;
)
AC_SUBST(CFLAGS)

AC_PACKAGE_REQUIRE(aterm, baffle,
   [  --with-aterm=DIR        ATerm-library is in DIR])
AC_SUBST(ATERM)

dnl Require ToolBus library
AC_PACKAGE_REQUIRE(toolbuslib, toolbuslib-config,
   [  --with-toolbuslib=DIR   ToolBus library is in DIR])
AC_SUBST(TOOLBUSLIB)

dnl Require toolbus package
AC_PACKAGE_REQUIRE(toolbus, toolbus,
   [  --with-toolbus=DIR      ToolBus distribution is in DIR])
AC_SUBST(TOOLBUS)

NOSOCKLIBS=$LIBS
SOCKET_FOUND=no
SOCKLIBS=
AC_CHECK_LIB(sun,socket,[SOCKET_FOUND=yes;SOCKLIBS="-lsun"])
if test ${SOCKET_FOUND} = no; then
  AC_CHECK_LIB(socket, socket,[SOCKET_FOUND=yes;SOCKLIBS="-lsocket"])
fi

GHN_FOUND=no
AC_CHECK_LIB(sun,gethostname,[GHN_FOUND=yes])
if test ${GHN_FOUND} = no; then
  AC_CHECK_LIB(nsl,gethostname,[GHN_FOUND=yes;SOCKLIBS="$SOCKLIBS -lnsl"])
fi

AC_SUBST(SOCKLIBS)
LIBS=$NOSOCKLIBS

AC_PROG_MAKE_SET([])

AC_CONFIG_FILES([Makefile
  lib/Makefile
  doc/Makefile
  utils/Makefile
  utils/lift-error/Makefile
  utils/lower-error/Makefile
  utils/error-diff/Makefile
])
AC_OUTPUT
