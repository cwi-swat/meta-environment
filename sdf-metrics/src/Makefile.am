include $(top_srcdir)/Makefile.meta

EXTRA_DIST=extract-sdf.isrc
bin_PROGRAMS=extractsdf
pkgdata_DATA=extract-sdf.idef

AM_CPPFLAGS+=$(ASC_SUPPORT_CFLAGS) -DASF_MAIN -DASF_WITH_ANNOS
extractsdf_SOURCES=ExtractSDF.c
extractsdf_LDFLAGS=$(ASC_SUPPORT_LIBS)

asfc:
	asfc -i ExtractSDF.eqs -o ExtractSDF.c -va
