#
# vim:ts=8:sw=8:sts=0
#
# $Id$
#

lib_LIBRARIES		= libSDF.a
include_HEADERS		= SDF.h SDF_dict.h SDF-utils.h
libSDF_a_SOURCES	= SDF.c SDF_dict.c ${UTILSRCS}

UTILSRCS		= get-imports.c get-module-name.c grammar.c prod.c \
			sort.c prio.c restrict.c SDF-utils.c

EXTRA_DIST		= SDF.adt

regen:
	adt-to-c --compat-term -i SDF.adt --prefix SDF_ --prologue SDF.pro \
		-o SDF

CFLAGS			= -g -Wall -O2
INCLUDES		= -I${ATERM}/include
LDFLAGS			= -L${ATERM}/lib
LDADD			= -lATerm
