include $(top_srcdir)/Makefile.meta

EXTRA_DIST+=extract-sdf.isrc
CLEANFILES+=extract-sdf.idef
AM_CPPFLAGS+=$(ASC_SUPPORT_CFLAGS) -DASF_MAIN -DASF_WITH_ANNOS

bin_PROGRAMS=extractsdf
pkgdata_DATA=extract-sdf.idef
lib_LTLIBRARIES=libextractsdf.la

include_HEADERS= \
	sdfMetrics.h

libextractsdf_la_SOURCES= \
	sdfMetrics.c 
libextractsdf_la_LIBADD= \
	$(ASC_SUPPORT_LIBS)

extractsdf_SOURCES= \
	ExtractSDF.c
extractsdf_LDADD= \
	-L$(top_builddir)/src -lextractsdf
	$(ASC_SUPPORT_LIBS)


%.idef: %.isrc
	sed 's@__PREFIX__@${prefix}@g' < $< > $@

ExtractSDF.eqs:
	eqs-dump -m languages/sdf2/extract/Sdf2 -o $@

asfc: ExtractSDF.eqs
	asfc -i ExtractSDF.eqs -o ExtractSDF.c -va
