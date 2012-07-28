# $Id: Makefile.am 18008 2006-02-28 10:17:06Z kooiker $

include $(top_srcdir)/java_make_rules
include $(top_srcdir)/toolbus_make_rules

ACLOCAL_FLAGS = -I .

SUBDIRS = 

TOOLNAME = diff-gui
JAVA_PACKAGE = nl.cwi.sen.diff
JARFILE = $(TOOLNAME)-$(VERSION).jar
MAIN_CLASS = $(JAVA_PACKAGE).DiffViewer
LOCAL_JARS = ${top_srcdir}/diffapi-0.1.jar
INSTALLED_JARS = ${pkgdatadir}/diffapi-0.1.jar

abstop_srcdir = $(shell cd ${top_srcdir}; pwd)

pkgdata_DATA = $(JARFILE) $(LOCAL_JARS) $(TOOLNAME).idef
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
	    -e 's@__LOCAL_JARS__@$(INSTALLED_JARS)@g'\
	    -e "s@__EXTERNAL_JARS__@$(EXTERNAL_JARS)@g"\
	    -e 's@__JARFILE__@$(JARFILE)@g'\
	     < $< > $@
