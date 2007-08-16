include $(top_srcdir)/Makefile.meta

pkgdata_DATA = rscriptcalculator.idef

EXTRA_DIST += rscriptcalculator.isrc

bin_PROGRAMS = rscriptcalculator

AM_CPPFLAGS += \
	$(ASC_SUPPORT_CFLAGS) \
	$(SDF_SUPPORT_CFLAGS) \
	-DASF_WITH_ANNOS \
	-DASF_MAIN

rscriptcalculator_SOURCES = Rscript-Calculator.c 

rscriptcalculator_LDADD = \
	$(SDF_SUPPORT_LIBS) \
	$(ASC_SUPPORT_LIBS)
