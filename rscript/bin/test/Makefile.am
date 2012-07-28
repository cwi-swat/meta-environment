include $(top_srcdir)/Makefile.meta

pkgdata_DATA = rscripttestsuite.idef

EXTRA_DIST += rscripttestsuite.isrc

bin_PROGRAMS = rscripttestsuite

AM_CPPFLAGS += \
	$(ASC_SUPPORT_CFLAGS) \
	$(SDF_SUPPORT_CFLAGS) \
	-DASF_WITH_ANNOS \
	-DASF_MAIN

rscripttestsuite_SOURCES = RScript-Test-Suite.c 

rscripttestsuite_LDADD = \
	$(SDF_SUPPORT_LIBS) \
	$(ASC_SUPPORT_LIBS)

asfc:
	asfc -i RScript-Test-Suite.eqs -o RScript-Test-Suite.c -va
