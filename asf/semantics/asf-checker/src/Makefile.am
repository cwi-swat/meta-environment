# $Id$

include ${top_srcdir}/make_rules

INCLUDES = \
	-I$(top_srcdir)/semantics/asf-operations/src \
	$(ASC_INCLUDES)

bin_PROGRAMS = asfchecker

pkgdata_DATA = asfchecker.idef

EXTRA_DIST = asfchecker.idef.src asfchecker.tif.c asfchecker.tif.h

CLEANFILES = asfchecker.idef

noinst_HEADERS 	= equationChecker.h asfchecker.tif.h statistics.h

asfchecker_SOURCES = \
	asfchecker.c \
	equationChecker.c \
	asfchecker.tif.c \
	statistics.c

asfchecker_DEPENDENCIES = \
	$(top_builddir)/semantics/asf-operations/src/libasfnormalization.a 

asfchecker_LDADD   = \
	-L$(top_builddir)/semantics/asf-operations/src -lasfnormalization \
	$(ASC_LD_FLAGS) \
	-L$(ERROR_SUPPORT)/lib -lLocationAPI \
	$(SOCKLIBS)

%.idef: %.idef.src Makefile
	sed 's@__PREFIX__@${prefix}@g' < $< > $@
