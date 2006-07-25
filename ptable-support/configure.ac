dnl $Id$

AC_INIT
AC_CONFIG_SRCDIR([configure.in])
GLT_INIT_PACKAGE
AC_PREREQ(2.59)

AC_PROG_CC

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

AC_PROG_RANLIB
AC_PATH_PROG(AR,ar,/usr/bin/ar)

AC_SUBST(INSTLIBDIR)
INSTLIBDIR="$libdir"

AC_SET_MAKE

AC_CONFIG_FILES([
  Makefile
  lib/Makefile
])
AC_OUTPUT
