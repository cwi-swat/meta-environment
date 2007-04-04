include $(top_srcdir)/Makefile.meta

pkgdata_DATA = removevarsyntax.idef
bin_PROGRAMS = removevarsyntax

removevarsyntax_SOURCES = \
	removevarsyntax.isrc \
	main.c \
	Remove-Var-Syntax.c 

AM_CPPFLAGS += \
  $(ASC_SUPPORT_CFLAGS) \
  $(SDF_SUPPORT_CFLAGS)

removevarsyntax_LDADD = \
  $(ASC_SUPPORT_LIBS) \
  $(SDF_SUPPORT_LIBS)

