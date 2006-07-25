
AC_INIT
AC_CONFIG_SRCDIR([configure.in])
GLT_INIT_PACKAGE
AC_PREREQ(2.59)

AM_MAINTAINER_MODE

ACLOCAL="${ACLOCAL} -I ."

AC_AIX
AC_PROG_CC
AC_PROG_LIBTOOL

AC_PROG_MAKE_SET([])

dnl Handle --with-cflags option
AC_ARG_WITH(cflags,
   [  --with-cflags=CFLAGS    standard options of c compiler],
   CFLAGS=${withval},
   if test "a${GCC}" = "ayes"; then
     CFLAGS="-Wall -g -O2"
   fi;
)
AC_SUBST(CFLAGS)

dnl Development mode
AC_ARG_WITH(develop,
   [  --with-develop          Enable development mode (extra dbg prints etc.)],
   DEVELOP_DEF=-DDEVELOP=1,
)
AC_SUBST(DEVELOP_DEF)


dnl Require ATerm library
AC_PACKAGE_REQUIRE(aterm, baffle,
   [  --with-aterm=DIR        Specify location of the ATerm library])
AC_SUBST(ATERM)

dnl Require ToolBus library
AC_PACKAGE_REQUIRE(toolbuslib, toolbuslib-config,
   [  --with-toolbuslib=DIR      ToolBus library is in DIR])
AC_SUBST(TOOLBUSLIB)

dnl Find out which libraries we need
SOCKET_FOUND=no
AC_CHECK_LIB(sun,socket,[SOCKET_FOUND=yes;LIBS="$LIBS -lsun"])
if test ${SOCKET_FOUND} = no; then
   AC_CHECK_LIB(socket, socket,[SOCKET_FOUND=yes;LIBS="$LIBS -lsocket"])
   if test ${SOCKET_FOUND} = no; then
      AC_CHECK_LIB(bsd,
                   socket,
                   [SOCKET_FOUND=yes;LIBS="$LIBS -lbsd";DEFS="$DEFS -D_BSD=43"]
)
   fi
fi

GETHOSTNAME_FOUND=no
AC_CHECK_LIB(sun,gethostname,[GETHOSTNAME_FOUND=yes])
if test ${GETHOSTNAME_FOUND} = no; then
   AC_CHECK_LIB(nsl,gethostname,[GETHOSTNAME_FOUND=yes;LIBS="$LIBS -lnsl"])
fi

AC_CONFIG_FILES([\
	Makefile \
	lib/Makefile \
	])
AC_OUTPUT
