include ${top_srcdir}/make_rules

INCLUDES = \
	   $(ASC_INCLUDES) \
	   -I$(SDF_SUPPORT)/include

bin_PROGRAMS = addeqssyntax

pkgdata_DATA = addeqssyntax.idef

EXTRA_DIST = addeqssyntax.idef.src 

noinst_HEADERS = addeqssyntax.tif.h

addeqssyntax_SOURCES = \
	addeqssyntax.c \
	Add-Eqs-Syntax.c \
	addeqssyntax.tif.c

addeqssyntax_LDADD = \
		     -L$(SDF_SUPPORT)/lib -lSDFME \
		     $(ASC_LD_FLAGS)

asfc:
	asfc -i Add-Eqs-Syntax.eqs -o Add-Eqs-Syntax.c -v

%.idef: %.idef.src Makefile
	sed 's@__PREFIX__@${prefix}@g' < $< > $@
