# $Id$

#AM_CFLAGS = -DDISABLE_DYNAMIC_CHECKING # During development, DO NOT COMMIT ME!

EXTRA_DIST = Sdf.label.def

lib_LIBRARIES = libSDFME.a libSDF2PT.a libPT2SDF.a

include_HEADERS = \
	PT2SDF.h \
	SDF2PT.h \
	SDFME-utils.h \
	SDFME.h \
	SDFME_dict.h

libSDFME_a_SOURCES = SDFME.c SDFME_dict.c ${UTILSRCS}

libSDF2PT_a_SOURCES = sdf2pt.c

libPT2SDF_a_SOURCES = pt2sdf.c

INCLUDES = \
	-I${ATERM}/include \
	-I${ERROR_SUPPORT}/include \
	-I${PT_SUPPORT}/include

UTILSRCS = \
	SDFME-utils.c \
	get-module-name.c \
	grammar.c \
	prio.c \
	prod.c \
	restrict.c \
	import-operations.c \
	sort.c 

LIBRARY = ../../asf-library/library
ATERM_SDF = $(shell ls ${LIBRARY}/languages/aterm/syntax/*.sdf)
SDF2_SDF = $(shell ls ${LIBRARY}/languages/sdf2/syntax/*.sdf)
BASIC_SDF = ${LIBRARY}/basic/Whitespace.sdf ${LIBRARY}/basic/Comments.sdf


# Developers only:
api:
	(echo definition; cat $(ATERM_SDF) $(SDF2_SDF) $(BASIC_SDF)) \
	> Sdf.label.def
	sdf2-to-c --input Sdf.label.def --prefix SDF_ --output SDFME

api-clean:
	rm -f Sdf.label.def SDFME.[ch] SDFME_dict.* SDFME.adt
