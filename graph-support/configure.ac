dnl $Id$

dnl Process this file with autoconf to produce a configure script.
AC_INIT
META_SETUP
META_C_SETUP
AC_PROG_LIBTOOL

META_REQUIRE_SOFTWARE(graphviz, dot)

AM_PROG_LEX
AC_PROG_YACC
AC_CHECK_LIB(y,yyerror,YACCLIB="-ly",YACCLIB="")
AC_SUBST(YACCLIB)

AC_OUTPUT
