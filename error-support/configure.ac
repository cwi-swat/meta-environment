dnl $Id$

AC_INIT
META_SETUP

dnl Nota Bene:
dnl Do not add any dependencies on other packages here! 
dnl That would exclude such a package from using the ErrorAPI,
dnl because it would introduce a circular dependency.

AC_AIX
AC_PROG_CC
AC_LIBTOOL_WIN32_DLL
AC_PROG_LIBTOOL

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
