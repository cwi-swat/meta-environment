# $Id$

include $(top_srcdir)/java_make_rules
include $(top_srcdir)/toolbus_make_rules

ACLOCAL_FLAGS = -I .

TOOLNAME = editor-plugin
JAVA_PACKAGE = nl.cwi.sen1.gui.plugin
JARFILE = $(TOOLNAME)-$(VERSION).jar
MAIN_CLASS = $(JAVA_PACKAGE).EditorPlugin

abstop_srcdir = $(shell cd ${top_srcdir}; pwd)

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

%.idef: %.idef.src Makefile
	sed -e 's@__PKGDATA__@$(pkgdatadir)@g'\
	    -e 's@__LOCAL_JARS__@$(LOCAL_JARS)@g'\
	    -e "s@__EXTERNAL_JARS__@$(EXTERNAL_JARS)@g"\
	    -e 's@__JARFILE__@$(JARFILE)@g'\
	     < $< > $@
