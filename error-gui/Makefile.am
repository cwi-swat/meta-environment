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
LOCAL_JARS = $(abstop_srcdir)/lib/jlfgr-1_0.jar

pkgdata_DATA = $(JARFILE) $(TOOLNAME).idef
bin_SCRIPTS = $(TOOLNAME)-config
noinst_SCRIPTS = $(TOOLNAME)-$(VERSION).pkg

EXTRA_DIST = package $(JARFILE) $(TOOLNAME).idef

CLEANFILES = $(TOOLNAME)-config $(TOOLNAME)-$(VERSION).pkg

$(TOOLNAME)-config: Makefile
	@(	echo "#! /bin/sh";\
		echo "echo $(pkgdatadir)/$(JARFILE):$(pkgdatadir)/jlfgr-1_0.jar" \
	) > $@ && chmod +x $@

$(TOOLNAME)-$(VERSION).pkg: package Makefile
	cp $< $@

%.idef: %.idef.src Makefile
	sed -e 's@__PKGDATA__@$(pkgdatadir)@g'\
	    -e 's@__LOCAL_JARS__@$(LOCAL_JARS)@g'\
	    -e "s@__EXTERNAL_JARS__@$(EXTERNAL_JARS)@g"\
	    -e 's@__JARFILE__@$(JARFILE)@g'\
	     < $< > $@
