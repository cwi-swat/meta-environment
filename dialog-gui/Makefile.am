# $Id$

include $(top_srcdir)/java_make_rules
include $(top_srcdir)/toolbus_make_rules

ACLOCAL_FLAGS = -I .

TOOLNAME = dialog
JAVA_PACKAGE = nl.cwi.sen1.gui.plugin
JARFILE = $(TOOLNAME).jar
MAIN_CLASS = $(JAVA_PACKAGE).Dialog

abstop_srcdir = $(shell cd ${top_srcdir}; pwd)

pkgdata_DATA = $(JARFILE) $(TOOLNAME).idef
bin_SCRIPTS = $(PACKAGE)-config
noinst_SCRIPTS = $(PACKAGE)-$(VERSION).pkg

EXTRA_DIST = package $(JARFILE) $(TOOLNAME).idef

CLEANFILES = $(PACKAGE)-config $(PACKAGE)-$(VERSION).pkg

$(PACKAGE)-config: Makefile
	@(	echo "#! /bin/sh";\
		echo "echo $(pkgdatadir)/$(JARFILE)" \
	) > $@ && chmod +x $@

$(PACKAGE)-$(VERSION).pkg: package Makefile
	cp $< $@

%.idef: %.idef.src Makefile
	sed -e 's@__PKGDATA__@$(pkgdatadir)@g'\
	    -e 's@__LOCAL_JARS__@$(LOCAL_JARS)@g'\
	    -e "s@__EXTERNAL_JARS__@$(EXTERNAL_JARS)@g"\
	    -e 's@__JARFILE__@$(JARFILE)@g'\
	     < $< > $@
