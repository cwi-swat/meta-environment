include $(top_srcdir)/Makefile.meta

pkgdata_DATA = 

EXTRA_DIST += 

bin_PROGRAMS = DeFactoSpec SortsToIds

AM_CPPFLAGS += \
	$(ASC_SUPPORT_CFLAGS) \
	$(SDF_SUPPORT_CFLAGS) \
	-DASF_MAIN

DeFactoSpec_SOURCES = DeFacto.c

DeFactoSpec_LDADD = \
	$(SDF_SUPPORT_LIBS) \
	$(ASC_SUPPORT_LIBS)

SortsToIds_SOURCES = SortsToIds.c

SortsToIds_LDADD = \
	$(SDF_SUPPORT_LIBS) \
	$(ASC_SUPPORT_LIBS)

asfc:
	asfc -i ../grammar/DeFacto.eqs -o DeFacto.c -v
