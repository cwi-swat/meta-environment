AC_INIT
AC_CONFIG_SRCDIR([configure.ac])
GLT_INIT_PACKAGE
AC_PREREQ(2.59)

AC_PROG_MAKE_SET([])

dnl Require pgen package
AC_PACKAGE_REQUIRE(pgen, sdf2table,
  [  --with-pgen=DIR         pgen is in DIR])
AC_SUBST(PGEN)

dnl Require sdf-support package
AC_PACKAGE_REQUIRE(sdf-support, sdf-support-config,
  [  --with-sdf-support=DIR         sdf-support is in DIR])
AC_SUBST(SDF_SUPPORT)

dnl Require meta package
AC_PACKAGE_REQUIRE(meta, meta-config,
  [  --with-meta=DIR         Meta-Environment is in DIR])
AC_SUBST(META)

dnl Require SDF library
AC_PACKAGE_REQUIRE(sdf-library, sdf-library-config,
   [  --with-sdf-library=DIR           Sdf library is in DIR])
AC_SUBST(ASF_LIBRARY)

AC_PACKAGE_REQUIRE(toolbus, toolbus,
   [  --with-toolbus=DIR       ToolBus is in DIR])
AC_SUBST(TOOLBUS)

dnl add outputfiles as argument below
AC_CONFIG_FILES([
  Makefile
  src/Makefile
  tbscripts/Makefile
])
AC_OUTPUT 
