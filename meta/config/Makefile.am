# $Id$

include $(top_srcdir)/java_make_rules

TOOLNAME = plugin-config
JAVA_PACKAGE = nl.cwi.sen1.meta.pluginconfiguration
JARFILE = $(TOOLNAME).jar

bin_SCRIPTS = $(TOOLNAME)
pkgdata_DATA = ${JARFILE}

EXTRA_DIST = \
	$(TOOLNAME).sh.src \
	${JARFILE}

CLEANFILES = $(TOOLNAME)

%: %.sh.src Makefile
	sed -e 's@__EXTERNAL_JARS__@$(EXTERNAL_JARS)@g'\
	    -e 's@__JARFILE__@$(pkgdatadir)/$(JARFILE)@g'\
	    -e 's@__PKGDATADIR__@$(pkgdatadir)@g'\
            < $< > $@ && chmod +x $@
