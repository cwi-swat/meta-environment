# $Id$

include $(top_srcdir)/java_make_rules
include $(top_srcdir)/toolbus_make_rules

ACLOCAL_FLAGS = -I .

SUBDIRS = lib

TOOLNAME = error-viewer
JAVA_PACKAGE = nl.cwi.sen1.error.viewer
JARFILE = $(TOOLNAME)-$(VERSION).jar
MAIN_CLASS = $(JAVA_PACKAGE).ErrorViewer

abstop_srcdir = $(shell cd ${top_srcdir}; pwd)
LOCAL_JARS = $(pkgdatadir)/lib/jlfgr-1_0.jar

pkgdata_DATA = $(JARFILE) $(TOOLNAME).idef
bin_SCRIPTS = $(PACKAGE)-config
noinst_SCRIPTS = $(PACKAGE)-$(VERSION).pkg

EXTRA_DIST = package $(JARFILE) $(TOOLNAME).idef.src

CLEANFILES = \
	     $(PACKAGE)-config \
	     $(PACKAGE)-$(VERSION).pkg \
	     $(TOOLNAME).idef

$(PACKAGE)-config: Makefile
	@(	echo "#! /bin/sh";\
		echo "echo $(pkgdatadir)/$(JARFILE):$(pkgdatadir)/jlfgr-1_0.jar" \
	) > $@ && chmod +x $@

$(PACKAGE)-$(VERSION).pkg: package Makefile
	cp $< $@

%.idef: %.idef.src Makefile
	sed -e 's@__PKGDATA__@$(pkgdatadir)@g'\
	    -e 's@__LOCAL_JARS__@$(LOCAL_JARS)@g'\
	    -e "s@__EXTERNAL_JARS__@$(EXTERNAL_JARS)@g"\
	    -e 's@__JARFILE__@$(JARFILE)@g'\
	     < $< > $@
