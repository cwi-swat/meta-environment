#
# vim:ts=8:sw=8:sts=0
#
# $Id$
#

lib_LIBRARIES		= libSDFME.a
include_HEADERS		= SDFME.h SDFME_dict.h SDFME-utils.h
libSDFME_a_SOURCES	= SDFME.c SDFME_dict.c ${UTILSRCS}

UTILSRCS		= get-module-name.c get-imports.c grammar.c prod.c \
			sort.c prio.c restrict.c convert-sdf2pt.c SDFME-utils.c

EXTRA_DIST		= SDFME.adt

CFLAGS			= -g -Wall -O2
INCLUDES		= -I${ATERM}/include \
                          -I${PT_SUPPORT}/include
