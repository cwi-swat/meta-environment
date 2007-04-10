
EXTRA_DIST=extract-sdf.isrc
bin_PROGRAMS=extractsdf
pkgdata_DATA=extract-sdf.idef

AM_CPPFLAGS=$(ASC_SUPPORT_CFLAGS) -DASF_MAIN -DASF_WITH_ANNOS
extractsdf_SOURCES=ExtractSDF.c
extractsdf_LDFLAGS=$(ASC_SUPPORT_LIBS)

CLEANFILES=extract-sdf.idef

%.idef: %.isrc
	sed 's@__PREFIX__@${prefix}@g' < $< > $@

asfc:
	asfc -i ExtractSDF.eqs -o ExtractSDF.c -va
