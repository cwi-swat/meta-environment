AC_INIT
AC_CONFIG_SRCDIR([configure])
AC_PREREQ(2.59)

GLT_INIT_PACKAGE

AC_PROG_CC
AC_PROG_CXX

dnl Require Boost include path
AC_ARG_WITH(boost-include,
  [  --with-boost-include=DIR    /path/to/include/boost-version],
  BOOST_INCLUDE=${withval},
  BOOST_INCLUDE="/usr/local/include"
)
AC_SUBST(BOOST_INCLUDE)

dnl Require Boost lib path
AC_ARG_WITH(boost-lib,
  [  --with-boost-lib=DIR    /path/to/boost/lib],
  BOOST_LIB=${withval},
  BOOST_LIB="/usr/local/lib"
)
AC_SUBST(BOOST_LIB)

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
  src/Makefile
  example/Makefile
  test/Makefile
  doc/Makefile
])
AC_OUTPUT
