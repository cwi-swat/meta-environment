# $Id$

TBSCRIPTS     = meta-interface.tb error-display.tb

EXTRA_DIST    = meta-interface.tb.src error-display.tb \
		standard.asfsdf.buttons standard.asfsdf.buttons.src

pkgdata_DATA     = $(TBSCRIPTS) standard.asfsdf.buttons

%.tb : %.tb.src Makefile
	sed 's@__ASF__@${ASF}@g;\
	     s@__ASF_LIBRARY__@${ASF_LIBRARY}@g;\
	     s@__ASFSDF_META__@${prefix}/share/asfsdf-meta/@g;\
	     s@__META__@${META}@' < $< > $@

standard.asfsdf.buttons:  standard.asfsdf.buttons.src Makefile
	sed 's@__ASF_LIBRARY__@${prefix}/share/asf/library/@g' < $< > $@
