# $Id$

TBSCRIPTS     = meta-interface.tb error-display.tb

EXTRA_DIST    = meta-interface.tb.src error-display.tb \
		meta.sh.src pt-dump.sh.src eqs-dump.sh.src

pkgdata_DATA     = $(TBSCRIPTS) 

bin_SCRIPTS = meta pt-dump eqs-dump


% : %.sh.src Makefile
	sed 's@__ASF__@${prefix}@g;\
	     s@__META__@${META}@' < $< > $@ && chmod +x $@


%.tb : %.tb.src Makefile
	sed 's@__ASF__@${prefix}@g;\
	     s@__ASF_LIBRARY__@${ASF_LIBRARY}/share/asf-library@g;\
	     s@__META__@${META}@' < $< > $@
