dnl Process this file with autoconf to produce a configure script.
AC_INIT
AC_CONFIG_SRCDIR([configure.ac])
GLT_INIT_PACKAGE
AC_PREREQ(2.59)

AM_MAINTAINER_MODE

AC_PROG_CC

dnl Handle cflags option
AC_ARG_WITH(cflags,
  [  --with-cflags=CFLAGS    standard options of c compiler],
  CFLAGS=${withval},
  if test "a${GCC}" = "ayes"; then
    CFLAGS="-Wall -g -O2"
  fi;
)
AC_SUBST(CFLAGS)

dnl Require ATerm library
AC_PACKAGE_REQUIRE(aterm, baffle,
   [  --with-aterm=DIR        ATerm-library is in DIR])
AC_SUBST(ATERM)

dnl Require error-support library
AC_PACKAGE_REQUIRE(error-support, error-support-config,
   [  --with-error-support=DIR error-support is in DIR])
AC_SUBST(ERROR_SUPPORT)

dnl Require ATerm Java library
AC_PACKAGE_REQUIRE(aterm-java, aterm-java-config,
   [  --with-aterm-java=DIR   ATerm-javalibrary is in DIR])
dnl ATERM_JAVA is not allowed in Makefile.am's
JAVA_ATERM=\`${ATERM_JAVA}/bin/aterm-java-config\`
AC_SUBST(JAVA_ATERM)

dnl Require ToolBus library
AC_PACKAGE_REQUIRE(toolbuslib, toolbuslib-config,
   [  --with-toolbuslib=DIR   ToolBus library is in DIR])
AC_SUBST(TOOLBUSLIB)

dnl Require ToolBus Java Adapter
AC_PACKAGE_REQUIRE(toolbus-java-adapter, toolbus-java-adapter-config,
   [  --with-toolbus-java-adapter=DIR   ToolBus Java adapter is in DIR])
AC_SUBST(TOOLBUS_JAVA_ADAPTER)

dnl Require toolbus package
AC_PACKAGE_REQUIRE(toolbus, toolbus,
   [  --with-toolbus=DIR      ToolBus distribution is in DIR])
AC_SUBST(TOOLBUS)

dnl Require config-manager package
AC_PACKAGE_REQUIRE(config-manager, config-manager-config,
   [  --with-config-manager=DIR config-manager is in DIR])
AC_SUBST(CONFIG_MANAGER)

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

dnl Require graph-support package
AC_PACKAGE_REQUIRE(graph-support, tree2graph,
   [  --with-graph-support=DIR   graph-support is in DIR])
AC_SUBST(GRAPH_SUPPORT)

dnl This variable holds all external jarfiles
EXTERNAL_JARS=${JAVA_ATERM}:\`${TOOLBUS_JAVA_ADAPTER}/bin/toolbus-java-adapter-config\`:\`${ERROR_SUPPORT}/bin/error-support-config\`:${TIDE}/share/tide/tide.jar:\`${META_STUDIO}/bin/gui-config\`:\`${CONFIG_MANAGER}/bin/config-manager-config\`:\`${GRAPH_SUPPORT}/bin/graph-support-config\`
AC_SUBST(EXTERNAL_JARS)

dnl Require sglr package
AC_PACKAGE_REQUIRE(sglr, sglr,
   [  --with-sglr=DIR         sglr is in DIR])
AC_SUBST(SGLR)

dnl Require pgen package
AC_PACKAGE_REQUIRE(pgen, sdf2table,
   [  --with-pgen=DIR         pgen is in DIR])
AC_SUBST(PGEN)

dnl Require pt-support package
AC_PACKAGE_REQUIRE(pt-support, unparsePT,
   [  --with-pt-support=DIR   pt-support is in DIR])
AC_SUBST(PT_SUPPORT)


dnl Require sdf-support package

AC_PACKAGE_REQUIRE(sdf-support, sdf-support-config,
   [  --with-sdf-support=DIR  sdf-support is in DIR])
AC_SUBST(SDF_SUPPORT)

dnl Require pandora package
AC_PACKAGE_REQUIRE(pandora, pandora,
   [  --with-pandora=DIR         pandora is in DIR])
AC_SUBST(PANDORA)

dnl Handle --with-tide=... argument to configure
AC_ARG_WITH(tide,
   [  --with-tide             TIDE is in DIR],
   TIDEDEF=-Dtide.enabled=true
   USE_TIDE=1,
   USE_TIDE=0
)
AC_SUBST(TIDEDEF)
AC_SUBST(USE_TIDE)

AC_PATH_PROG(JAVA, java)
if test "x${JAVA}" = "x"; then
  AC_MSG_ERROR("make sure java version 1.4 or better is in your PATH")
fi

dnl Is ranlib needed on this system?
AC_PROG_RANLIB
AC_PATH_PROG(AR,ar,/usr/bin/ar)

dnl What commands are needed to set the variable MAKE in Makefiles?
AC_PROG_MAKE_SET([])

dnl Determine which libraries to use for programs using sockets
NOSOCKLIBS=$LIBS
dnl first, the socket functions
SOCKET_FOUND=no
SOCKLIBS=
AC_CHECK_LIB(sun,socket,[SOCKET_FOUND=yes;SOCKLIBS="-lsun"])
if test ${SOCKET_FOUND} = no; then
  AC_CHECK_LIB(socket, socket,[SOCKET_FOUND=yes;SOCKLIBS="-lsocket"])
  if test ${SOCKET_FOUND} = no; then
    AC_CHECK_LIB(bsd,socket,[SOCKET_FOUND=yes;SOCKLIBS="-lbsd";DEFS="$DEFS -D_BSD=43"])
  fi
fi

dnl then gethostname
GHN_FOUND=no
AC_CHECK_LIB(sun,gethostname,[GHN_FOUND=yes])
if test ${GHN_FOUND} = no; then
  AC_CHECK_LIB(nsl,gethostname,[GHN_FOUND=yes;SOCKLIBS="$SOCKLIBS -lnsl"])
fi

AC_SUBST(SOCKLIBS)

LIBS=$NOSOCKLIBS


dnl Checks for header files.
AC_CHECK_HEADER(getopt.h)

dnl Which files need updating?
AC_CONFIG_FILES([Makefile
   src/Makefile
   gui/Makefile
   gui/data/Makefile
   gui/lib/Makefile
   gui/util/Makefile
   gui/plugin/Makefile
   gui/plugin/navigator/Makefile
   gui/plugin/dialog/Makefile
   gui/plugin/graph-painter/Makefile
   in-output/Makefile
   in-output/src/Makefile
   term-store/Makefile
   term-store/snapshot/Makefile
   editors/Makefile
   editors/manager/Makefile
   editors/structure/Makefile
   tbscripts/Makefile
])
AC_OUTPUT
