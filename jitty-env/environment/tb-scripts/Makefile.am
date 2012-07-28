# $Id$

TBSCRIPTS     = meta-interface.tb error-display.tb

EXTRA_DIST    = meta-interface.tb.src error-display.tb

pkgdata_DATA     = $(TBSCRIPTS) 

%.tb : %.tb.src Makefile
	sed 's@__ASF__@${ASF}@g;\
	     s@__JITTY_LIBRARY__@${prefix}/share/jitty-env/library@g;\
	     s@__META__@${META}@' < $< > $@
