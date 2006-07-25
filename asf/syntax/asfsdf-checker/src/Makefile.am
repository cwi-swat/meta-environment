include ${top_srcdir}/Makefile.meta

INCLUDES = \
	   $(ASC_SUPPORT_CFLAGS)  \
	   $(SDF_SUPPORT_CFLAGS) \
	   -DASF_WITH_ANNOS

bin_PROGRAMS = asfsdfchecker

pkgdata_DATA = asfsdfchecker.idef

EXTRA_DIST = asfsdfchecker.idef.src 

CLEANFILES = asfsdfchecker.idef

noinst_HEADERS = asfsdfchecker.tif.h

asfsdfchecker_SOURCES = asfsdfchecker.c AsfSdf-Checker.c asfsdfchecker.tif.c
asfsdfchecker_LDADD = \
	$(SDF_SUPPORT_LIBS) \
	$(ASC_SUPPORT_LIBS)

asfc: AsfSdf-Checker.eqs
	asfc -i $< -o AsfSdf-Checker.c -va

%.idef: %.idef.src Makefile
	sed 's@__PREFIX__@${prefix}@g' < $< > $@
