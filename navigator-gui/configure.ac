dnl Process this file with autoconf to produce a configure script.
AC_INIT
AC_CONFIG_SRCDIR([configure.ac])
GLT_INIT_PACKAGE
AC_PREREQ(2.59)

AM_MAINTAINER_MODE

dnl Require ATerm Java library
AC_PACKAGE_REQUIRE(aterm-java, aterm-java-config,
   [  --with-aterm-java=DIR   ATerm-javalibrary is in DIR])
dnl ATERM_JAVA is not allowed in Makefile.am's
JAVA_ATERM=\`${ATERM_JAVA}/bin/aterm-java-config\`
AC_SUBST(JAVA_ATERM)

dnl Require ToolBus Java Adapter
AC_PACKAGE_REQUIRE(toolbus-java-adapter, toolbus-java-adapter-config,
   [  --with-toolbus-java-adapter=DIR   ToolBus Java adapter is in DIR])
AC_SUBST(TOOLBUS_JAVA_ADAPTER)

dnl Require toolbus package
AC_PACKAGE_REQUIRE(toolbus, toolbus,
   [  --with-toolbus=DIR      ToolBus distribution is in DIR])
AC_SUBST(TOOLBUS)

dnl Require module-support package
AC_PACKAGE_REQUIRE(module-support, module-support-config,
   [  --with-module-support=DIR      Module-support is in DIR])
AC_SUBST(MODULE_SUPPORT)

dnl Require graph-support package
AC_PACKAGE_REQUIRE(graph-support, tree2graph,
   [  --with-graph-support=DIR   graph-support is in DIR])
AC_SUBST(GRAPH_SUPPORT)

dnl Require meta-studio package
AC_PACKAGE_REQUIRE(meta-studio, gui-config,
   [  --with-meta-studio=DIR meta-studio is in DIR])
AC_SUBST(META_STUDIO)

dnl This variable holds all external jarfiles
EXTERNAL_JARS=${JAVA_ATERM}:\`${TOOLBUS_JAVA_ADAPTER}/bin/toolbus-java-adapter-config\`:\`${MODULE_SUPPORT}/bin/module-support-config\`:\`${GRAPH_SUPPORT}/bin/graph-support-config\`:\`${META_STUDIO}/bin/gui-config\`
AC_SUBST(EXTERNAL_JARS)

AC_PATH_PROG(JAVA, java)
if test "x${JAVA}" = "x"; then
  AC_MSG_ERROR("make sure java version 1.4 or better is in your PATH")
fi

dnl What commands are needed to set the variable MAKE in Makefiles?
AC_PROG_MAKE_SET([])

dnl Which files need updating?
AC_CONFIG_FILES([
  Makefile
  lib/Makefile
])
AC_OUTPUT
