include ${top_srcdir}/Makefile.meta

INCLUDES = \
	   $(SDF_SUPPORT_CFLAGS) \
	   $(ASC_SUPPORT_CFLAGS)

EXTRA_DIST = removevarsyntax.idef.src 

CLEANFILES = removevarsyntax.idef

pkgdata_DATA = removevarsyntax.idef
noinst_HEADERS = removevarsyntax.tif.h
bin_PROGRAMS = removevarsyntax

removevarsyntax_SOURCES = \
	removevarsyntax.c \
	Remove-Var-Syntax.c \
	removevarsyntax.tif.c

removevarsyntax_LDADD   = \
                       $(SDF_SUPPORT_LIBS) \
                       $(ASC_SUPPORT_LIBS) 

%.idef: %.idef.src Makefile
	sed 's@__PREFIX__@${prefix}@g' < $< > $@
