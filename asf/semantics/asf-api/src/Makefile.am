include $(top_srcdir)/Makefile.meta

pkgdata_DATA = ASFSDFApigen.idef

bin_PROGRAMS=ASFSDFApigen

ASFSDFApigen_SOURCES = \
	main.c \
	ASFSDFApigen.c \
	ASFSDFApigen.isrc

AM_CPPFLAGS += -DASF_MAIN -DTOOLBUS $(ASC_SUPPORT_CFLAGS)
ASFSDFApigen_LDADD = $(ASC_SUPPORT_LIBS)

asfc: ${top_builddir}/semantics/asf-api/spec/ASFSDFApigen.eqs
	asfc -i $< -o ASFSDFApigen.c -t -v -c 

