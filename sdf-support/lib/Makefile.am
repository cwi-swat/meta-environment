# $Id$

lib_LIBRARIES		= libSDFME.a
include_HEADERS		= SDFME.h SDFME-utils.h SDFME_dict.h

libSDFME_a_SOURCES	= SDFME.c SDFME_dict.c SDFME_bottom.c ${UTILSRCS}

UTILSRCS		= get-module-name.c get-imports.c grammar.c prod.c \
			  sort.c prio.c restrict.c sdf2pt.c SDFME-utils.c \
			  renamings.c

EXTRA_DIST		= Sdf.label.def

CFLAGS			= -g -Wall -O2
INCLUDES		= -I${ATERM}/include \
                          -I${PT_SUPPORT}/include

# Developers only:
api: Sdf.label.def
	sdf2-to-c -i $< -r --compat-term -P SDF_ -o SDFME

api-clean:
	rm -f SDFME.[ch] SDFME_dict.* SDFME.adt SDFME_bottom.c
