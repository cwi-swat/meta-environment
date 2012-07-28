# $Id$

include $(top_srcdir)/Makefile.java.meta

EXTRA_DIST+=gui.idef.src

pkgdata_DATA=gui.idef

CLEANFILES += gui.idef

ACLOCAL_AMFLAGS = -I .

SUBDIRS = \
	lib \
	script


%.idef: %.idef.src Makefile
	sed -e 's@__PKGDATA__@$(pkgdatadir)@g'\
	    -e 's@__LOCAL_JARS__@$(INSTALLED_JARS)@g'\
	    -e 's@__PREFIX__@$(prefix)@g'\
	    -e "s@__EXTERNAL_JARS__@$(EXTERNAL_JARS)@g"\
	    -e 's@__JARFILE__@$(JARFILE)@g'\
	     < $< > $@
