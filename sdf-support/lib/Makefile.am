# $Id$

lib_LIBRARIES		= libSDFME.a
noinst_HEADERS          = SDFME_dict.h
include_HEADERS		= SDFME.h SDFME-utils.h
libSDFME_a_SOURCES	= SDFME.c SDFME_dict.c ${UTILSRCS}

UTILSRCS		= get-module-name.c get-imports.c grammar.c prod.c \
			  sort.c prio.c restrict.c sdf2pt.c SDFME-utils.c

EXTRA_DIST		= SDFME.adt

CFLAGS			= -g -Wall -O2
INCLUDES		= -I${ATERM}/include \
                          -I${PT_SUPPORT}/include
