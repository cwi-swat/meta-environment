include ${top_srcdir}/make_rules

INCLUDES = \
	   -I$(SDF_SUPPORT)/include \
	   $(ASC_INCLUDES)

EXTRA_DIST = removevarsyntax.idef.src 

pkgdata_DATA = removevarsyntax.idef
noinst_HEADERS = removevarsyntax.tif.h
bin_PROGRAMS = removevarsyntax

removevarsyntax_SOURCES = \
	removevarsyntax.c \
	Remove-Var-Syntax.c \
	removevarsyntax.tif.c

removevarsyntax_LDADD   = \
                       -L$(SDF_SUPPORT)/lib -lSDFME \
                       $(ASC_LD_FLAGS) 

%.idef: %.idef.src Makefile
	sed 's@__PREFIX__@${prefix}@g' < $< > $@
