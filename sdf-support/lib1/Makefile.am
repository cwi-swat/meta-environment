#
# vim:ts=8:sw=8:sts=0
#
# $Id$
#

lib_LIBRARIES		= libSDF.a
include_HEADERS		= SDF.h SDF_dict.h SDF-utils.h
libSDF_a_SOURCES	= SDF.c SDF_dict.c ${UTILSRCS}

UTILSRCS		= get-imports.c get-module-name.c grammar.c lexprod.c \
			sort.c

EXTRA_DIST		= SDF.adt

CFLAGS			= -g -Wall -O2
INCLUDES		= -I${ATERM}/include
LDFLAGS			= -L${ATERM}/lib
LDADD			= -lATerm
