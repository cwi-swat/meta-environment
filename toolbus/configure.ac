AC_INIT
META_SETUP
META_C_SETUP

dnl CPP and FLAGS are needed by toolbus for calling preprocessor as 
dnl configured correctly:
AC_SUBST(CPP)
AC_SUBST(CPPFLAGS)

AM_PROG_LEX
AC_PROG_YACC
AC_CHECK_LIB(y,yyerror,YACCLIB="-ly",YACCLIB="")
AC_SUBST(YACCLIB)

AC_PATH_X
AC_SUBST(x_includes)
AC_SUBST(x_libraries)

AC_CHECK_PROG(NOWEB,noweb,noweb,true)
AC_SUBST(NOWEB)

AC_PROG_MAKE_SET([])

ALL_ADAPTERS="gen-adapter emacs-adapter perl-adapter \
              python-adapter tcltk-adapter"
AC_SUBST(ALL_ADAPTERS)

dnl Default adapters
EMACS_ADAPTER=emacs-adapter
AC_SUBST(EMACS_ADAPTER)

PERL_ADAPTER=perl-adapter
AC_SUBST(PERL_ADAPTER)

PYTHON_ADAPTER=python-adapter
AC_SUBST(PYTHON_ADAPTER)

WISH_ADAPTER=wish-adapter
AC_SUBST(WISH_ADAPTER)

AC_ARG_WITH(trans,
   [  --with-trans-adapter    transparently connects to another toolbus],
   TRANS_ADAPTER=trans-adapter)
AC_SUBST(TRANS_ADAPTER)

AC_ARG_WITH(tcltk,
   [  --with-tcltk            include Tcl/Tk support (tcltk-adapter)],
   TCLTK_ADAPTER=tcltk-adapter)
AC_SUBST(TCLTK_ADAPTER)

AC_CHECK_HEADER([arpa/inet.h],[:],[AC_MSG_ERROR("*** no arpa/inet.h")])
AC_CHECK_HEADER([assert.h],[:],[AC_MSG_ERROR("*** no assert.h")])
AC_CHECK_HEADER([ctype.h],[:],[AC_MSG_ERROR("*** no ctype.h")])
AC_CHECK_HEADER([errno.h],[:],[AC_MSG_ERROR("*** no errno.h")])
AC_CHECK_HEADER([netdb.h],[:],[AC_MSG_ERROR("*** no netdb.h")])
AC_CHECK_HEADER([netinet/in.h],[:],[AC_MSG_ERROR("*** no netinet/in.h")])
AC_CHECK_HEADER([netinet/tcp.h],[:],[AC_MSG_ERROR("*** no netinet/tcp.h")])
AC_CHECK_HEADER([signal.h],[:],[AC_MSG_ERROR("*** no signal.h")])
AC_CHECK_HEADER([stdarg.h],[:],[AC_MSG_ERROR("*** no stdarg.h")])
AC_CHECK_HEADER([stdio.h],[:],[AC_MSG_ERROR("*** no stdio.h")])
AC_CHECK_HEADER([stdlib.h],[:],[AC_MSG_ERROR("*** no stdlib.h")])
AC_CHECK_HEADER([string.h],[:],[AC_MSG_ERROR("*** no string.h")])
AC_CHECK_HEADER([fcntl.h],[:],[AC_MSG_ERROR("*** no fcntl.h")])
AC_CHECK_HEADER([sys/ioctl.h],[:],[AC_MSG_ERROR("*** no sys/ioctl.h")])
AC_CHECK_HEADER([sys/param.h],[:],[AC_MSG_ERROR("*** no sys/param.h")])
AC_CHECK_HEADER([sys/socket.h],[:],[AC_MSG_ERROR("*** no sys/socket.h")])
AC_CHECK_HEADER([sys/stat.h],[:],[AC_MSG_ERROR("*** no sys/stat.h")])
AC_CHECK_HEADER([sys/time.h],[:],[AC_MSG_ERROR("*** no sys/time.h")])
AC_CHECK_HEADER([sys/types.h],[:],[AC_MSG_ERROR("*** no sys/types.h")])
AC_CHECK_HEADER([sys/uio.h],[:],[AC_MSG_ERROR("*** no sys/uio.h")])
AC_CHECK_HEADER([sys/un.h],[:],[AC_MSG_ERROR("*** no sys/un.h")])
AC_CHECK_HEADER([unistd.h],[:],[AC_MSG_ERROR("*** no unistd.h")])
AC_CHECK_HEADER([math.h],[:],[AC_MSG_ERROR("*** no math.h")])

AC_CHECK_FUNCS([mkdtemp])
AC_CHECK_FUNCS([strerror])
AC_CHECK_FUNCS([strdup])
AC_CHECK_FUNCS([yywrap])
AC_CHECK_FUNCS([lrand48 srand48])

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

dnl Of course, the latest version of wish is not always called "wish". :-(
dnl If we can't find something called wish 8.3, wish8.2 or wish8.1, we'll
dnl assume that "wish" is at version 8 or higher.

AC_PATH_PROGS(WISH,wish8.3 wish8.2 wish8.1 wish, /usr/local/bin/wish)

dnl Where is perl5?
AC_PATH_PROGS(PERL,perl5 perl, /usr/bin/perl)

# Check for math lib (-lm), use arbitrary function (atof) from
# C library, since using, e.g., sin leads to compilation errors
AC_CHECK_LIB(m,atof,[LIBS="$LIBS -lm"])

AC_OUTPUT 
