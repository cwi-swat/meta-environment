# $Id$

#AM_CFLAGS = -DDISABLE_DYNAMIC_CHECKING # During development, DO NOT COMMIT ME!

include $(top_srcdir)/Makefile.meta

EXTRA_DIST += Sdf.label.def

lib_LTLIBRARIES = libSDFME.la libSDF2PT.la libPT2SDF.la

include_HEADERS = \
	PT2SDF.h \
	SDF2PT.h \
	SDFME-utils.h \
	SDFME.h \
	SDFME_dict.h

AM_CPPFLAGS += $(ATERM_CFLAGS) $(ERROR_SUPPORT_CFLAGS) $(PT_SUPPORT_CFLAGS)

libSDFME_la_SOURCES = SDFME.c SDFME_dict.c $(UTILSRCS)
libSDFME_la_LDFLAGS = -avoid-version -no-undefined $(AM_LDFLAGS)
libSDFME_la_LIBADD  = $(ATERM_LIBS) $(ERROR_SUPPORT_LIBS) $(PT_SUPPORT_LIBS)

libSDF2PT_la_SOURCES  = sdf2pt.c
libSDF2PT_la_LDFLAGS  = -avoid-version -no-undefined $(AM_LDFLAGS)
libSDF2PT_la_LIBADD  = $(ATERM_LIBS) $(ERROR_SUPPORT_LIBS) $(PT_SUPPORT_LIBS) ./libSDFME.la

libPT2SDF_la_SOURCES  = pt2sdf.c
libPT2SDF_la_LDFLAGS  = -avoid-version -no-undefined $(AM_LDFLAGS)
libPT2SDF_la_LIBADD  = $(ATERM_LIBS) $(ERROR_SUPPORT_LIBS) $(PT_SUPPORT_LIBS) ./libSDFME.la

UTILSRCS = \
	SDFME-utils.c \
	get-module-name.c \
	grammar.c \
	prio.c \
	prod.c \
	restrict.c \
	import-operations.c \
	sort.c 

LIBRARY = ../../sdf-library/library
ATERM_SDF = $(shell ls $(LIBRARY)/languages/aterm/syntax/*.sdf)
SDF2_SDF = $(shell ls $(LIBRARY)/languages/sdf2/syntax/*.sdf)
BASIC_SDF = \
	$(LIBRARY)/basic/Whitespace.sdf \
	$(LIBRARY)/basic/StrCon.sdf \
	$(LIBRARY)/basic/NatCon.sdf \
	$(LIBRARY)/basic/IdentifierCon.sdf \
	$(LIBRARY)/basic/Comments.sdf

# Developers only:
api:
	(echo definition; cat $(ATERM_SDF) $(SDF2_SDF) $(BASIC_SDF)) \
	> Sdf.label.def
	sdf2-to-c --input Sdf.label.def --prefix SDF_ --output SDFME

api-clean:
	rm -f Sdf.label.def SDFME.[ch] SDFME_dict.* SDFME.adt
