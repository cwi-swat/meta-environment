# $Id$

include $(top_srcdir)/java_make_rules

TOOLNAME = error-viewer
PACKAGE = nl.cwi.sen1.error
JARFILE = $(TOOLNAME).jar

ANT_ENV += LOCAL_JARS=$(top_srcdir)/lib/errorapi-$(VERSION).jar:$(top_srcdir)/gui/lib/jlfgr-1_0.jar

pkgdata_DATA = $(JARFILE) $(TOOLNAME).idef
bin_SCRIPTS = $(TOOLNAME)-config

EXTRA_DIST = $(JARFILE) $(TOOLNAME).idef

$(TOOLNAME)-config: Makefile
	@(	echo "#! /bin/sh";\
		echo "echo $(pkgdatadir)/$(JARFILE)" \
	) > $@ && chmod +x $@
