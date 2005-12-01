# $Id$

include $(top_srcdir)/java_make_rules
include $(top_srcdir)/toolbus_make_rules

TOOLNAME = progress
JAVA_PACKAGE = nl.cwi.sen1.gui.plugin
JARFILE = $(TOOLNAME).jar
MAIN_CLASS = $(JAVA_PACKAGE).viewer.Progress

ANT_ENV += LOCAL_JARS=$(top_srcdir)/gui/data/gui-data.jar:$(top_srcdir)/gui/util/gui-util.jar:$(top_srcdir)/gui/studio/gui.jar

pkgdata_DATA = ${JARFILE} $(TOOLNAME).idef

EXTRA_DIST = ${JARFILE} $(TOOLNAME).idef
