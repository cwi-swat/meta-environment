# $Id$

include $(top_srcdir)/java_make_rules
include $(top_srcdir)/toolbus_make_rules

TOOLNAME = dialog
JAVA_PACKAGE = nl.cwi.sen1.gui.plugin
JARFILE = $(TOOLNAME).jar
MAIN_CLASS = $(JAVA_PACKAGE).Dialog

ANT_ENV += LOCAL_JARS=$(top_srcdir)/gui/studio/gui.jar

pkgdata_DATA = ${JARFILE} $(TOOLNAME).idef

EXTRA_DIST = ${JARFILE} $(TOOLNAME).idef
