# $Id$

# During development, DO NOT COMMIT ME!
#CFLAGS += -DDISABLE_DYNAMIC_CHECKING

EXTRA_DIST = Sdf.label.def

lib_LIBRARIES = libSDFME.a libSDF2PT.a libPT2SDF.a

noinst_HEADERS = module-table.h

include_HEADERS = \
	PT2SDF.h \
	SDF2PT.h \
	SDFME-utils.h \
	SDFME.h \
	SDFME_dict.h

libSDFME_a_SOURCES = SDFME.c SDFME_dict.c SDFME_bottom.c ${UTILSRCS}

libSDF2PT_a_SOURCES = sdf2pt.c

libPT2SDF_a_SOURCES = pt2sdf.c

INCLUDES = \
	-I${ATERM}/include \
	-I${PT_SUPPORT}/include

UTILSRCS = \
	SDFME-utils.c \
	get-imports.c \
	get-module-name.c \
	grammar.c \
	prio.c \
	prod.c \
	renamings.c \
	restrict.c \
	sort.c \
        module-table.c

# Developers only:
api: Sdf.label.def
	sdf2-to-c -i $< -r --compat-term -P SDF_ -o SDFME

api-clean:
	rm -f SDFME.[ch] SDFME_dict.* SDFME.adt SDFME_bottom.c
