

bin_PROGRAMS			= fac

fac_SOURCES				= fac.c pico-support.c pico-support.h
fac_LDFLAGS				= -L${ATERM}/lib
fac_LDADD				= -L../../lib-c -ltide-adapter \
						  -lATB -lATerm

EXTRA_DIST				= fac.pico

CFLAGS					= -g -Wall -O2
INCLUDES				= -I${top_srcdir}/lib-c \
						  -I${ATERM}/include

LDFLAGS					= -L${ATERM}/lib
LDADD					= -lATB -lATerm

