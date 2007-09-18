include $(top_srcdir)/Makefile.meta

pkgdata_DATA = rscripttestsuite.idef

EXTRA_DIST += rscripttestsuite.isrc

bin_PROGRAMS = rscripttestsuite

AM_CPPFLAGS += \
	$(ASC_SUPPORT_CFLAGS) \
	$(SDF_SUPPORT_CFLAGS) \
	-DASF_WITH_ANNOS \
	-DASF_MAIN

rscripttestsuite = RScript-Test-Suite.c 

rscripttestsuite = \
	$(SDF_SUPPORT_LIBS) \
	$(ASC_SUPPORT_LIBS)

asfc:
	asfc -i Rscript-Test-Suite.eqs -o Rscript-Test-Suite.c -va
