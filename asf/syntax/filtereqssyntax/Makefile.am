# $Id$

include ${top_srcdir}/make_rules

bin_PROGRAMS	= filtereqssyntax filtereqssyntaxtool

noinst_HEADERS	= filtereqssyntaxtool.tif.h filtereqssyntax.h

pkgdata_DATA	= filtereqssyntaxtool.idef
EXTRA_DIST	= $(pkgdata_DATA)

INCLUDES	= \
		-I${ATERM}/include \
		-I${TOOLBUSLIB}/include \
		-I${PT_SUPPORT}/include \
		-I${ASF_SUPPORT}/include

GENERIC_SOURCES	= filtereqssyntax.c

GENERIC_LDADD	= \
		-L${ASF_SUPPORT}/lib -lASFME \
		-L${PT_SUPPORT}/lib -lmept \
		-L${ATERM}/lib -lATerm 


filtereqssyntax_SOURCES		= main.c ${GENERIC_SOURCES}
filtereqssyntax_LDADD		= ${GENERIC_LDADD}

filtereqssyntaxtool_SOURCES	= filtereqssyntaxtool.tif.c \
				tool.c \
				${GENERIC_SOURCES}

filtereqssyntaxtool_LDADD	= -L${TOOLBUSLIB}/lib -lATB \
				${GENERIC_LDADD} \
				$(SOCKLIBS)
