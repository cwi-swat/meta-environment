AC_INIT
AC_CONFIG_SRCDIR([configure.ac])
GLT_INIT_PACKAGE
AC_PREREQ(2.59)

AC_PROG_MAKE_SET([])

dnl Require pgen package
AC_PACKAGE_REQUIRE(pgen, sdf2table,
  [  --with-pgen=DIR         pgen is in DIR])
AC_SUBST(PGEN)

dnl Require meta package
AC_PACKAGE_REQUIRE(meta, generic-meta,
  [  --with-meta=DIR         Meta-Environment is in DIR])
AC_SUBST(META)

AC_PACKAGE_REQUIRE(structure-editor, structure-editor,
   [  --with-structure-editor=DIR         structure-editor is in DIR])
AC_SUBST(STRUCTURE_EDITOR)

AC_PACKAGE_REQUIRE(editor-manager, editor-manager,
   [  --with-editor-manager=DIR         editor-manager is in DIR])
AC_SUBST(EDITOR_MANAGER)

dnl add outputfiles as argument below
AC_CONFIG_FILES([
  Makefile
  tbscripts/Makefile
])
AC_OUTPUT 
