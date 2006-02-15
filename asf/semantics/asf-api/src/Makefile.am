include ${top_srcdir}/make_rules

pkgdata_DATA = $(wildcard *.idef)

EXTRA_DIST = $(wildcard *.idef.src)

noinst_HEADERS = toolASFSDFApigen.tif.h

bin_PROGRAMS=ASFSDFApigen

ASFSDFApigen_SOURCES = \
	ASFSDFApigen.c \
	toolASFSDFApigen.tif.c

ASFSDFApigen_LDADD = $(ASC_LD_FLAGS)

INCLUDES = \
	-DASF_MAIN \
	-DTOOLBUS \
	$(ASC_INCLUDES)

asfc: ${top_builddir}/semantics/asf-api/spec/ASFSDFApigen.eqs
	asfc -i $< -o ASFSDFApigen.c -t -v -c 

%.idef: %.idef.src Makefile
	sed 's@__PREFIX__@${prefix}@g' < $< > $@
