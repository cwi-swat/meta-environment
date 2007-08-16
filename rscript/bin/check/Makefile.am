include $(top_srcdir)/Makefile.meta

pkgdata_DATA = rscriptchecker.idef

EXTRA_DIST += rscriptchecker.isrc

bin_PROGRAMS = rscriptchecker

AM_CPPFLAGS += \
	$(ASC_SUPPORT_CFLAGS) \
	$(SDF_SUPPORT_CFLAGS) \
	-DASF_WITH_ANNOS \
	-DASF_MAIN

rscriptchecker_SOURCES = Rscript-Checker.c 

rscriptchecker_LDADD = \
	$(SDF_SUPPORT_LIBS) \
	$(ASC_SUPPORT_LIBS)
