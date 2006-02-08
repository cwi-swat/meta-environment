dnl $Id$

AC_INIT
AC_CONFIG_SRCDIR([configure.ac])
GLT_INIT_PACKAGE
AC_PREREQ(2.59)

dnl What commands are needed to set the variable MAKE in Makefiles?
AC_PROG_MAKE_SET([])

AC_PACKAGE_REQUIRE(sdf-meta, sdf-meta-config,
   [  --with-sdf-meta=DIR          sdf-meta is in DIR])
AC_SUBST(SDF_META)

AC_PACKAGE_REQUIRE(asf, asfc,
   [  --with-asf=DIR           Asf is in DIR])
AC_SUBST(ASF)

AC_PACKAGE_REQUIRE(toolbus, toolbus,
   [  --with-toolbus=DIR       ToolBus is in DIR])
AC_SUBST(TOOLBUS)

dnl Which files need updating?
AC_CONFIG_FILES([Makefile
  tbscripts/Makefile
  src/Makefile
  demo/Makefile
  demo/old-pico/Makefile
  demo/user-manual-examples/Makefile
])
AC_OUTPUT
