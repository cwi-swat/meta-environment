include $(top_srcdir)/Makefile.meta

bin_PROGRAMS=extract-sdf
pkgdata_DATA=extract-sdf.idef

AM_CPPFLAGS+=$(ASC_SUPPORT_CFLAGS) -DASF_MAIN -DASF_WITH_ANNOS
extract_sdf_SOURCES=ExtractSDF.c extract-sdf.isrc
extract_sdf_LDFLAGS=$(ASC_SUPPORT_LIBS)

asfc:
	asfc -i ExtractSDF.eqs -o ExtractSDF.c -va
