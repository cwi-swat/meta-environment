# $Id$

include $(top_srcdir)/Makefile.java.meta

ACLOCAL_FLAGS = -I .

pkgdata_DATA += error-viewer.idef

EXTRA_DIST += error-viewer.idef.src

CLEANFILES += error-viewer.idef

%.idef: %.idef.src Makefile
	sed -e 's@__PKGDATA__@$(pkgdatadir)@g'\
	    -e 's@__LOCAL_JARS__@$(INSTALLED_JARS)@g'\
	    -e "s@__EXTERNAL_JARS__@$(EXTERNAL_JARS)@g"\
	    -e 's@__JARFILE__@$(JARFILE)@g'\
	     < $< > $@
