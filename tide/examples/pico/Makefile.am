

noinst_PROGRAMS	= fac

fac_SOURCES	= fac.c pico-support.c pico-support.h
fac_LDADD	= -L../../lib-c -ltide-adapter \
		-L${TOOLBUSLIB}/lib -lATB \
		-L${ATERM}/lib -lATerm

EXTRA_DIST	= fac.pico

INCLUDES	= -I${top_srcdir}/lib-c \
		-I${ATERM}/include \
		-I${TOOLBUSLIB}/include \
                -D__SRCDIR__="\"`cd ${srcdir}; pwd`\""
