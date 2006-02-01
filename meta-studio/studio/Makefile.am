# $Id$

include $(top_srcdir)/java_make_rules
include $(top_srcdir)/toolbus_make_rules

TOOLNAME = gui
JAVA_PACKAGE = nl.cwi.sen1.gui
JARFILE = $(TOOLNAME).jar

LOCAL_JARS=$(top_srcdir)/util/gui-util.jar:$(top_srcdir)/lib/idw-gpl-1.4.0.jar

bin_SCRIPTS = $(TOOLNAME)-config
pkgdata_DATA = ${JARFILE} $(TOOLNAME).idef

EXTRA_DIST = ${JARFILE} $(TOOLNAME).idef.src

CLEANFILES = $(TOOLNAME)-config

$(TOOLNAME)-config: Makefile
	echo "#! /bin/sh" > $@
	echo "echo $(pkgdatadir)/$(JARFILE):$(pkgdatadir)/idw-gpl-1.4.0.jar:$(pkgdatadir)/gui-util.jar" >> $@
	chmod +x $@

%.idef: %.idef.src Makefile
	sed 's@__PREFIX__@${prefix}@g' < $< > $@
