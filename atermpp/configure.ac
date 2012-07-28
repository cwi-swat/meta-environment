AC_INIT
AC_CONFIG_SRCDIR([configure])
AC_PREREQ(2.59)

GLT_INIT_PACKAGE

AC_AIX
AC_PROG_CC
AC_PROG_LIBTOOL
AC_PROG_CXX

dnl Require Boost path
AC_ARG_WITH(boost,
  [  --with-boost=DIR    /path/to/boost],
  BOOST=${withval},
  BOOST="/usr/local/boost"
)
AC_SUBST(BOOST)

BOOST_INCLUDE=${BOOST}/include
AC_SUBST(BOOST_INCLUDE)

dnl Require ATerm library
AC_PACKAGE_REQUIRE(aterm, baffle,
   [  --with-aterm=DIR        ATerm-library is in DIR])
AC_SUBST(ATERM)

ATERM_INCLUDE=${ATERM}/include
AC_SUBST(ATERM_INCLUDE)

ATERM_LIB=${ATERM}/lib
AC_SUBST(ATERM_LIB)

AC_CONFIG_FILES([
  Makefile
  atermpp/Makefile
  example/Makefile
  test/Makefile
  doc/Makefile
])
AC_OUTPUT
