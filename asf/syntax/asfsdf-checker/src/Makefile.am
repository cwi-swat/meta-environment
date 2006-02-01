include ${top_srcdir}/make_rules

INCLUDES = \
	   $(ASC_INCLUDES)  \
	   -I$(SDF_SUPPORT)/include  \
	   -DASF_WITH_ANNOS

bin_PROGRAMS = asfsdfchecker

pkgdata_DATA = asfsdfchecker.idef

EXTRA_DIST = asfsdfchecker.idef.src 
noinst_HEADERS = asfsdfchecker.tif.h

asfsdfchecker_SOURCES = asfsdfchecker.c AsfSdf-Checker.c asfsdfchecker.tif.c
asfsdfchecker_LDADD = \
	-L$(SDF_SUPPORT)/lib -lSDFME \
	$(ASC_LD_FLAGS)

asfc: AsfSdf-Checker.eqs
	asfc -i $< -o AsfSdf-Checker.c -va

%.idef: %.idef.src Makefile
	sed 's@__PREFIX__@${prefix}@g' < $< > $@
