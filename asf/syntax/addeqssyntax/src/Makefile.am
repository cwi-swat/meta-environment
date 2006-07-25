include ${top_srcdir}/Makefile.meta

INCLUDES = \
	   $(ASC_SUPPORT_CFLAGS) \
	   -I$(SDF_SUPPORT)/include

bin_PROGRAMS = addeqssyntax

pkgdata_DATA = addeqssyntax.idef

EXTRA_DIST = addeqssyntax.idef.src 

CLEANFILES = addeqssyntax.idef

noinst_HEADERS = addeqssyntax.tif.h

addeqssyntax_SOURCES = \
	addeqssyntax.c \
	Add-Eqs-Syntax.c \
	addeqssyntax.tif.c

addeqssyntax_LDADD = \
		     $(SDF_SUPPORT_LIBS) \
		     $(ASC_SUPPORT_LIBS)

asfc:
	asfc -i Add-Eqs-Syntax.eqs -o Add-Eqs-Syntax.c -v

%.idef: %.idef.src Makefile
	sed 's@__PREFIX__@${prefix}@g' < $< > $@
