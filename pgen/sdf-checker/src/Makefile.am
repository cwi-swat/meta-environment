# $Id$

include $(top_srcdir)/Makefile.meta

bin_PROGRAMS = sdfchecker

pkgdata_DATA = sdfchecker.idef

AM_CPPFLAGS += $(ASC_SUPPORT_CFLAGS) -DASF_WITH_ANNOS
sdfchecker_SOURCES  = sdfchecker.idef main.c Sdf-Checker.c
sdfchecker_LDADD    = $(ASC_SUPPORT_LIBS)

asfc:
	asfc -va -i Sdf-Checker.eqs -o Sdf-Checker.c
