# $Id$

TBSCRIPTS     = meta-interface.tb error-display.tb

EXTRA_DIST    = meta-interface.tb.src error-display.tb

pkgdata_DATA     = $(TBSCRIPTS) 

bin_SCRIPTS = meta
EXTRA_DIST = meta.sh.src

% : %.sh.src Makefile
	sed 's@__ASF__@${prefix}@g;\
	     s@__META__@${META}@' < $< > $@ && chmod +x $@


%.tb : %.tb.src Makefile
	sed 's@__ASF__@${prefix}@g;\
	     s@__ASF_LIBRARY__@${ASF_LIBRARY}/share/asf-library@g;\
	     s@__META__@${META}@' < $< > $@
