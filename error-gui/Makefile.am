# $Id$

include $(top_srcdir)/Makefile.java.meta

SUBDIRS=lib

ACLOCAL_AMFLAGS = -I .

pkgdata_DATA = error-viewer.idef

EXTRA_DIST += error-viewer.idef.src

CLEANFILES += error-viewer.idef

%.idef: %.idef.src Makefile
	sed -e 's@__PKGDATA__@$(datadir)@g'\
	    -e 's@__LOCAL_JARS__@$(prefix)/share/jlfgr-1_0.jar@g'\
	    -e "s@__EXTERNAL_JARS__@$(EXTERNAL_JARS)@g"\
	    -e 's@__JARFILE__@$(JAVA_JAR)@g'\
	     < $< > $@
