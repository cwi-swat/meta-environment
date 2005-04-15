# $Id$

include $(top_srcdir)/java_make_rules
include $(top_srcdir)/toolbus_make_rules

TOOLNAME = gui
PACKAGE = nl.cwi.sen1.gui.studio
JARFILE = $(TOOLNAME).jar

ANT_ENV += LOCAL_JARS=$(top_srcdir)/gui/data/gui-data.jar:$(top_srcdir)/gui/util/gui-util.jar:$(top_srcdir)/gui/lib/idw-gpl-1.3.0.jar

pkgdata_DATA = ${JARFILE} $(TOOLNAME).idef

EXTRA_DIST = ${JARFILE} $(TOOLNAME).idef
