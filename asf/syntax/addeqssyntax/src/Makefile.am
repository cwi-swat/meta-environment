include $(top_srcdir)/Makefile.meta


bin_PROGRAMS = addeqssyntax

pkgdata_DATA = addeqssyntax.idef

EXTRA_DIST = addeqssyntax.idef.src 

CLEANFILES += addeqssyntax.idef

noinst_HEADERS = addeqssyntax.tif.h

addeqssyntax_CPPFLAGS = \
	   $(ASC_SUPPORT_CFLAGS) \
	   $(SDF_SUPPORT_CFLAGS)
addeqssyntax_SOURCES = \
	addeqssyntax.c \
	Add-Eqs-Syntax.c \
	addeqssyntax.tif.c

addeqssyntax_LDADD = \
		     $(SDF_SUPPORT_LIBS) \
		     $(ASC_SUPPORT_LIBS)

asfc:
	which asfc
	asfc -i Add-Eqs-Syntax.eqs -o Add-Eqs-Syntax.c -v

%.idef: %.idef.src Makefile
	sed 's@__PREFIX__@${prefix}@g' < $< > $@
