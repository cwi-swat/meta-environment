include $(top_srcdir)/Makefile.meta

pkgdata_DATA = addeqssyntax.idef

bin_PROGRAMS = addeqssyntax

AM_CPPFLAGS += \
	   $(ASC_SUPPORT_CFLAGS) \
	   $(SDF_SUPPORT_CFLAGS)

addeqssyntax_SOURCES = \
	addeqssyntax.isrc \
	main.c \
	Add-Eqs-Syntax.c 

addeqssyntax_LDADD = \
		     $(SDF_SUPPORT_LIBS) \
		     $(ASC_SUPPORT_LIBS)

asfc:
	which asfc
	asfc -i Add-Eqs-Syntax.eqs -o Add-Eqs-Syntax.c -v
