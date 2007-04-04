include $(top_srcdir)/Makefile.meta

pkgdata_DATA = asfsdfchecker.idef

bin_PROGRAMS = asfsdfchecker

AM_CPPFLAGS += \
	   $(ASC_SUPPORT_CFLAGS)  \
	   $(SDF_SUPPORT_CFLAGS) \
	   -DASF_WITH_ANNOS

asfsdfchecker_SOURCES = AsfSdf-Checker.c asfsdfchecker.isrc main.c

asfsdfchecker_LDADD = \
	$(SDF_SUPPORT_LIBS) \
	$(ASC_SUPPORT_LIBS)

asfc: AsfSdf-Checker.eqs
	asfc -i $< -o AsfSdf-Checker.c -va
