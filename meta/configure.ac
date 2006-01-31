dnl Process this file with autoconf to produce a configure script.
AC_INIT
AC_CONFIG_SRCDIR([configure.ac])
GLT_INIT_PACKAGE
AC_PREREQ(2.59)

AM_MAINTAINER_MODE

dnl Require error-support library
AC_PACKAGE_REQUIRE(error-support, error-support-config,
   [  --with-error-support=DIR error-support is in DIR])
AC_SUBST(ERROR_SUPPORT)

dnl Require error-gui package
AC_PACKAGE_REQUIRE(error-gui, error-gui-config,
   [  --with-error-gui=DIR error-gui is in DIR])
AC_SUBST(ERROR_GUI)

dnl Require error-gui package
AC_PACKAGE_REQUIRE(editor-plugin, editor-plugin-config,
   [  --with-editor-plugin=DIR editor-plugin is in DIR])
AC_SUBST(ERROR_GUI)

dnl Require graph-gui package
AC_PACKAGE_REQUIRE(graph-gui, graph-gui-config,
   [  --with-graph-gui=DIR graph-gui is in DIR])
AC_SUBST(GRAPH_GUI)

dnl Require progress-gui package
AC_PACKAGE_REQUIRE(progress-gui, progress-gui-config,
   [  --with-progress-gui=DIR progress-gui is in DIR])
AC_SUBST(PROGRESS_GUI)

dnl Require dialog-gui package
AC_PACKAGE_REQUIRE(dialog-gui, dialog-gui-config,
   [  --with-dialog-gui=DIR dialog-gui is in DIR])
AC_SUBST(DIALOG_GUI)

dnl Require module-details-gui package
AC_PACKAGE_REQUIRE(module-details-gui, module-details-gui-config,
   [  --with-module-details-gui=DIR module-details-gui is in DIR])
AC_SUBST(MODULE_DETAILS_GUI)

dnl Require navigator-gui package
AC_PACKAGE_REQUIRE(navigator-gui, navigator-gui-config,
   [  --with-navigator-gui=DIR navigator-gui is in DIR])
AC_SUBST(NAVIGATOR_GUI)

dnl Require config-manager package
AC_PACKAGE_REQUIRE(config-manager, config-manager-config,
   [  --with-config-manager=DIR config-manager is in DIR])
AC_SUBST(CONFIG_MANAGER)

dnl Require module-manager package
AC_PACKAGE_REQUIRE(module-manager, module-manager-config,
   [  --with-module-manager=DIR module-manager is in DIR])
AC_SUBST(MODULE_MANAGER)

dnl Require meta-studio package
AC_PACKAGE_REQUIRE(meta-studio, gui-config,
   [  --with-meta-studio=DIR meta-studio is in DIR])
AC_SUBST(META_STUDIO)

dnl Require Tide package
AC_PACKAGE_REQUIRE(tide, tide,
   [  --with-tide=DIR      Tide distribution is in DIR])
AC_SUBST(TIDE)

dnl Require Tide-support package
AC_PACKAGE_REQUIRE(tide-support, tide-support-config,
   [  --with-tide-support=DIR      Tide-support distribution is in DIR])
AC_SUBST(TIDE_SUPPORT)

dnl Require term-store package
AC_PACKAGE_REQUIRE(term-store, term-store,
   [  --with-term-store=DIR      term-store distribution is in DIR])
AC_SUBST(TERM_STORE)

dnl Require io-support package
AC_PACKAGE_REQUIRE(io-support, in-output,
   [  --with-io-support=DIR      io-support distribution is in DIR])
AC_SUBST(IO_SUPPORT)

dnl Require graph-support package
AC_PACKAGE_REQUIRE(graph-support, tree2graph,
   [  --with-graph-support=DIR   graph-support is in DIR])
AC_SUBST(GRAPH_SUPPORT)

dnl Require sglr package
AC_PACKAGE_REQUIRE(sglr, sglr,
   [  --with-sglr=DIR         sglr is in DIR])
AC_SUBST(SGLR)

dnl Require pt-support package
AC_PACKAGE_REQUIRE(pt-support, unparsePT,
   [  --with-pt-support=DIR   pt-support is in DIR])
AC_SUBST(PT_SUPPORT)

dnl Require pandora package
AC_PACKAGE_REQUIRE(pandora, pandora,
   [  --with-pandora=DIR         pandora is in DIR])
AC_SUBST(PANDORA)

dnl What commands are needed to set the variable MAKE in Makefiles?
AC_PROG_MAKE_SET([])

dnl Which files need updating?
AC_CONFIG_FILES([Makefile
   src/Makefile
   tbscripts/Makefile
])
AC_OUTPUT
