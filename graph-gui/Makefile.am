# $Id$

include $(top_srcdir)/java_make_rules
include $(top_srcdir)/toolbus_make_rules

TOOLNAME = graph-painter
JAVA_PACKAGE = nl.cwi.sen1.gui.plugin
JARFILE = $(TOOLNAME).jar
MAIN_CLASS = $(JAVA_PACKAGE).GraphPainter

LOCAL_JARS=$(top_srcdir)/gui/data/gui-data.jar:$(top_srcdir)/gui/util/gui-util.jar:$(top_srcdir)/gui/studio/gui.jar:$(top_srcdir)/gui/lib/prefuse.jar

pkgdata_DATA = ${JARFILE} $(TOOLNAME).idef

EXTRA_DIST = ${JARFILE} $(TOOLNAME).idef
