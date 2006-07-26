include $(top_srcdir)/Makefile.meta

EXTRA_DIST = removevarsyntax.idef.src 

CLEANFILES += removevarsyntax.idef

pkgdata_DATA = removevarsyntax.idef
noinst_HEADERS = removevarsyntax.tif.h
bin_PROGRAMS = removevarsyntax

removevarsyntax_SOURCES = \
	removevarsyntax.c \
	Remove-Var-Syntax.c \
	removevarsyntax.tif.c

AM_CPPFLAGS += \
  $(ASC_SUPPORT_CFLAGS) \
  $(SDF_SUPPORT_CFLAGS)

removevarsyntax_LDADD = \
  $(ASC_SUPPORT_LIBS) \
  $(SDF_SUPPORT_LIBS)

%.idef: %.idef.src Makefile
	sed 's@__PREFIX__@${prefix}@g' < $< > $@
