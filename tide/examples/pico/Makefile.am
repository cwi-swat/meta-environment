
include $(top_srcdir)/Makefile.meta

noinst_PROGRAMS	= fac

fac_SOURCES	= fac.c pico-support.c pico-support.h
fac_LDADD	= -L../../lib-c -ltide-adapter \
		$(TOOLBUSLIB_LIBS) \
		$(ATERM_LIBS) \

EXTRA_DIST	= fac.pico

INCLUDES	= -I${top_srcdir}/lib-c \
		${ATERM_CFLAGS} \
		${TOOLBUSLIB_CFLAGS} \
                -D__SRCDIR__="\"`cd ${srcdir}; pwd`\""
