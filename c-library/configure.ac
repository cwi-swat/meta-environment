dnl $Id$

dnl Process this file with autoconf to produce a configure script.
AC_INIT
AC_CONFIG_SRCDIR([configure.ac])
GLT_INIT_PACKAGE
AC_PREREQ(2.59)

GLT_INIT_PACKAGE
#Allows use of --enable-maintatiner-mode to be used in Makefiles.
AM_MAINTAINER_MODE

dnl Which compiler to use?
AC_PROG_CC
AC_PROG_LIBTOOL

dnl Check for required packages and perform version check when needed.

dnl Require ATerm library
AC_PACKAGE_REQUIRE(aterm, baffle,
   [  --with-aterm=DIR        ATerm-library is in DIR])
AC_SUBST(ATERM)

dnl What commands are needed to set the variable MAKE in Makefiles?
AC_PROG_MAKE_SET([])

dnl Which files need updating?
AC_CONFIG_FILES([
  Makefile
  logging/Makefile
  statistics/Makefile
])
AC_OUTPUT
