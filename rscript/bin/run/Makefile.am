include $(top_srcdir)/Makefile.meta

pkgdata_DATA = rscriptcalculator.idef

EXTRA_DIST += rscriptcalculator.isrc

bin_PROGRAMS = rscriptcalculator

AM_CPPFLAGS += \
	$(ASC_SUPPORT_CFLAGS) \
	$(SDF_SUPPORT_CFLAGS) \
	-DASF_MAIN

rscriptcalculator_SOURCES = RScript-Calculator.c 

rscriptcalculator_LDADD = \
	$(SDF_SUPPORT_LIBS) \
	$(ASC_SUPPORT_LIBS)

asfc:
	asfc -i RScript-Calculator.eqs -o RScript-Calculator.c -va

