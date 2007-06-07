# $Id$

include $(top_srcdir)/Makefile.meta

bin_PROGRAMS = sdfchecker

pkgdata_DATA = sdfchecker.idef

AM_CPPFLAGS += \
	$(SDF_SUPPORT_CFLAGS) \
	$(ASC_SUPPORT_CFLAGS) \
	-DASF_WITH_ANNOS

sdfchecker_SOURCES  = sdfchecker.isrc main.c Sdf-Checker.c
sdfchecker_LDADD    = \
	$(SDF_SUPPORT_LIBS) \
	$(ASC_SUPPORT_LIBS)

asfc:
	asfc -va -i Sdf-Checker.eqs -o Sdf-Checker.c
