# $Id$

include ${top_srcdir}/make_rules

bin_PROGRAMS = filtereqssyntax filtereqssyntaxtool

noinst_HEADERS  = filtereqssyntaxtool.tif.h filtereqssyntax.h

GENERIC_SOURCES = filtereqssyntax.c
GENERIC_LDADD   = -L${ASF_SUPPORT}/lib -lASFME \
                  -L${PT_SUPPORT}/lib -lmept \
                  -L${ATERM}/lib -lATerm 

INCLUDES = -I${ATERM}/include \
           -I${PT_SUPPORT}/include \
           -I${ASF_SUPPORT}/include


filtereqssyntax_SOURCES = main.c ${GENERIC_SOURCES}
filtereqssyntax_LDADD   = ${GENERIC_LDADD}

filtereqssyntaxtool_SOURCES = filtereqssyntaxtool.tif.c \
                              tool.c \
                              ${GENERIC_SOURCES}
filtereqssyntaxtool_LDADD = -L{TOOLBUS}/lib -lATB \
                            ${GENERIC_LDADD}
