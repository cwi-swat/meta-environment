include $(top_srcdir)/Makefile.meta

pkgdata_DATA = rscriptcalculator.idef

bin_PROGRAMS = rscriptcalculator

AM_CPPFLAGS += \
	$(ASC_SUPPORT_CFLAGS) \
	$(SDF_SUPPORT_CFLAGS) \
	-DASF_WITH_ANNOS \
	-DASF_MAIN

rscriptchecker_SOURCES = Rscript-Calculator.c 

rscriptchecker_LDADD = \
	$(SDF_SUPPORT_LIBS) \
	$(ASC_SUPPORT_LIBS)
