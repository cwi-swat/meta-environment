dnl $Id$

AC_INIT
AC_CONFIG_SRCDIR([configure.ac])
GLT_INIT_PACKAGE
AC_PREREQ(2.59)

AM_MAINTAINER_MODE

AC_PROG_CC

AC_ARG_WITH(cflags,
   [  --with-cflags=CFLAGS    standard options of c compiler],
   CFLAGS=${withval},
   if test "a${GCC}" = "ayes"; then
     CFLAGS="-Wall -g -O2"
   fi;
)
AC_SUBST(CFLAGS)

AC_PROG_MAKE_SET([])

AC_CONFIG_FILES([Makefile
  lib/Makefile
  script/Makefile
])
AC_OUTPUT
