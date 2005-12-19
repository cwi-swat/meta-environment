dnl Process this file with autoconf to produce a configure script.
AC_INIT
AC_CONFIG_SRCDIR([configure.ac])
GLT_INIT_PACKAGE
AC_PREREQ(2.59)

AM_MAINTAINER_MODE

dnl Require toolbus package
AC_PACKAGE_REQUIRE(toolbus, toolbus,
   [  --with-toolbus=DIR      ToolBus distribution is in DIR])
AC_SUBST(TOOLBUS)

AC_PATH_PROG(JAVA, java)
if test "x${JAVA}" = "x"; then
  AC_MSG_ERROR("make sure java version 1.4 or better is in your PATH")
fi

dnl What commands are needed to set the variable MAKE in Makefiles?
AC_PROG_MAKE_SET([])

dnl Which files need updating?
AC_CONFIG_FILES([
		 Makefile
])
AC_OUTPUT
