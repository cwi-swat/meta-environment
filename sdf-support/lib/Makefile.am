# $Id$

lib_LIBRARIES		= libSDFME.a
include_HEADERS		= SDFME.h SDFME-utils.h SDFME_dict.h

libSDFME_a_SOURCES	= SDFME.c SDFME_dict.c ${UTILSRCS}

UTILSRCS		= get-module-name.c get-imports.c grammar.c prod.c \
			  sort.c prio.c restrict.c sdf2pt.c SDFME-utils.c

EXTRA_DIST		= SDFME.adt

CFLAGS			= -g -Wall -O2
INCLUDES		= -I${ATERM}/include \
                          -I${PT_SUPPORT}/include

# Developers only:
api: Sdf.label.def
	sdf2-to-adt -s -r -i $< -o SDFME.adt
	adt-to-c --compat-term -i SDFME.adt --prologue SDFME.pro \
                                --prefix SDF_ -o SDFME
