m4_pattern_forbid([^META_])
AC_INIT
META_SETUP
META_C_SETUP
AC_PROG_LIBTOOL

AC_CHECK_HEADER([assert.h],[:],[AC_MSG_ERROR("*** no assert.h")])
AC_CHECK_HEADER([errno.h],[:],[AC_MSG_ERROR("*** no errno.h")])
AC_CHECK_HEADER([netdb.h],[:],[AC_MSG_ERROR("*** no netdb.h")])
AC_CHECK_HEADER([netinet/in.h],[:],[AC_MSG_ERROR("*** no netinet/in.h")])
AC_CHECK_HEADER([netinet/tcp.h],[:],[AC_MSG_ERROR("*** no netinet/tcp.h")])
AC_CHECK_HEADER([sys/param.h],[:],[AC_MSG_ERROR("*** no sys/param.h")])
AC_CHECK_HEADER([sys/socket.h],[:],[AC_MSG_ERROR("*** no sys/socket.h")])
AC_CHECK_HEADER([sys/time.h],[:],[AC_MSG_ERROR("*** no sys/time.h")])
AC_CHECK_HEADER([sys/un.h],[:],[AC_MSG_ERROR("*** no sys/un.h")])
AC_CHECK_HEADER([unistd.h],[:],[AC_MSG_ERROR("*** no unistd.h")])

AC_CHECK_FUNCS([strerror])
AC_CHECK_FUNCS([strdup])

dnl Find out which libraries we need

SOCKET_FOUND=no
AC_CHECK_LIB(sun,socket,[SOCKET_FOUND=yes;LIBS="$LIBS -lsun"])
if test ${SOCKET_FOUND} = no; then
   AC_CHECK_LIB(socket, socket,[SOCKET_FOUND=yes;LIBS="$LIBS -lsocket"])
   if test ${SOCKET_FOUND} = no; then
      AC_CHECK_LIB(bsd,
                   socket,
                   [SOCKET_FOUND=yes;LIBS="$LIBS -lbsd";DEFS="$DEFS -D_BSD=43"])
   fi
fi

GETHOSTNAME_FOUND=no
AC_CHECK_LIB(sun,gethostname,[GETHOSTNAME_FOUND=yes])
if test ${GETHOSTNAME_FOUND} = no; then
   AC_CHECK_LIB(nsl,gethostname,[GETHOSTNAME_FOUND=yes;LIBS="$LIBS -lnsl"])
fi

SOCKETLIBS=$LIBS
AC_SUBST(SOCKETLIBS)

AC_OUTPUT 
