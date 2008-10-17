include $(top_srcdir)/Makefile.meta

pkgdata_DATA = 

EXTRA_DIST += 

bin_PROGRAMS = DeFacto

AM_CPPFLAGS += \
	$(ASC_SUPPORT_CFLAGS) \
	$(SDF_SUPPORT_CFLAGS) \
	-DASF_MAIN

DeFacto_SOURCES = DeFacto.c

DeFacto_LDADD = \
	$(SDF_SUPPORT_LIBS) \
	$(ASC_SUPPORT_LIBS)

asfc:
	asfc -i ../grammar/DeFacto.eqs -o DeFacto.c -v
