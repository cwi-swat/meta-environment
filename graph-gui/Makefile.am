# $Id$

include $(top_srcdir)/java_make_rules
include $(top_srcdir)/toolbus_make_rules

SUBDIRS = script

ACLOCAL_FLAGS = -I .

TOOLNAME = graph-painter
JAVA_PACKAGE = nl.cwi.sen1.gui.plugin
JARFILE = $(TOOLNAME).jar
MAIN_CLASS = $(JAVA_PACKAGE).GraphPainter

LOCAL_JARS=$(top_srcdir)/gui/data/gui-data.jar:$(top_srcdir)/gui/util/gui-util.jar:$(top_srcdir)/gui/studio/gui.jar:$(top_srcdir)/gui/lib/prefuse.jar

abstop_srcdir = $(shell cd ${top_srcdir}; pwd)

pkgdata_DATA = $(JARFILE) $(TOOLNAME).idef

EXTRA_DIST = ${JARFILE} $(TOOLNAME).idef

CLEANFILES = $(TOOLNAME)-config $(TOOLNAME)-$(VERSION).pkg

$(TOOLNAME)-config: Makefile
	@( echo "#! /bin/sh";\
	   echo "echo $(pkgdatadir)/$(JARFILE)" \
	) > $@ && chmod +x $@

$(TOOLNAME)-$(VERSION).pkg: package Makefile
    cp $< $@
