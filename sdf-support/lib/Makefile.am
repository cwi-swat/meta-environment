# $Id$

lib_LIBRARIES		= libSDFME.a libSDF2PT.a libPT2SDF.a

include_HEADERS		= SDFME.h SDFME-utils.h SDFME_dict.h SDF2PT.h

libSDFME_a_SOURCES	= SDFME.c SDFME_dict.c SDFME_bottom.c ${UTILSRCS}

libSDF2PT_a_SOURCES     = sdf2pt.c

libPT2SDF_a_SOURCES     = pt2sdf.c

UTILSRCS		= get-module-name.c get-imports.c grammar.c prod.c \
			  sort.c prio.c restrict.c SDFME-utils.c renamings.c

EXTRA_DIST		= Sdf.label.def

INCLUDES		= -I${ATERM}/include \
                          -I${PT_SUPPORT}/include

CFLAGS                  += -DDISABLE_DYNAMIC_CHECKING

# Developers only:
api: Sdf.label.def
	sdf2-to-c -i $< -r --compat-term -P SDF_ -o SDFME

api-clean:
	rm -f SDFME.[ch] SDFME_dict.* SDFME.adt SDFME_bottom.c
