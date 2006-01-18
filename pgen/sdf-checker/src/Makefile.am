# $Id$

include ${top_srcdir}/make_rules

INCLUDES = \
	   $(ASC_INCLUDES) \
	   -DASF_WITH_ANNOS

bin_PROGRAMS = sdfchecker

pkgdata_DATA = sdfchecker.idef

EXTRA_DIST = sdfchecker.idef 

noinst_HEADERS = sdfchecker.tif.h
sdfchecker_SOURCES = sdfchecker.c Sdf-Checker.c sdfchecker.tif.c
sdfchecker_LDADD = $(ASC_LD_FLAGS)
