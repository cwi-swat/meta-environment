# $Id$

include $(top_srcdir)/java_make_rules
include $(top_srcdir)/toolbus_make_rules

ACLOCAL_FLAGS = -I .

SUBDIRS = lib

TOOLNAME = error-viewer
PACKAGE = nl.cwi.sen1.error
JARFILE = $(TOOLNAME)-$(VERSION).jar

ANT_ENV += LOCAL_JARS=$(top_srcdir)/lib/jlfgr-1_0.jar

pkgdata_DATA = $(JARFILE) $(TOOLNAME).idef
bin_SCRIPTS = $(TOOLNAME)-config
noinst_SCRIPTS = $(TOOLNAME)-$(VERSION).pkg

EXTRA_DIST = package $(JARFILE) $(TOOLNAME).idef

CLEANFILES = $(TOOLNAME)-config $(TOOLNAME)-$(VERSION).pkg

$(TOOLNAME)-config: Makefile
	@(	echo "#! /bin/sh";\
		echo "echo $(pkgdatadir)/$(JARFILE)" \
	) > $@ && chmod +x $@

$(TOOLNAME)-$(VERSION).pkg: package Makefile
	cp $< $@
