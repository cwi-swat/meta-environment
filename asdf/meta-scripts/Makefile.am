# $Id$

TBSCRIPTS = \
	meta-interface.tb \
	error-display.tb \
	asdf-modules.tb

EXTRA_DIST = \
	meta-interface.tb.src \
	error-display.tb \
	asdf-modules.tb \
	standard.asdf.buttons \
	standard.asdf.buttons.src

CLEANFILES = \
	meta-interface.tb \
	standard.asdf.buttons

pkgdata_DATA     = $(TBSCRIPTS) standard.asdf.buttons

LIBRARY_LOCATION =${ASF_LIBRARY}/share/asf-library/library

%.tb : %.tb.src Makefile
	sed 's@__ASF__@${ASF}@g;\
	     s@__ASDF__@${prefix}/share/asdf@g;\
	     s@__ASDF_BIN__@${prefix}/bin@g;\
	     s@__ASDF_PT__@${prefix}/share/asdf/asdf-pt@g;\
	     s@__ASF_LIBRARY__@${LIBRARY_LOCATION}@g;\
	     s@__META__@${META}@g' < $< > $@

standard.asdf.buttons:  standard.asdf.buttons.src Makefile
	sed 's@__ASF_LIBRARY__@${LIBRARY_LOCATION}@g;\
	     s@__PGEN__@${PGEN}@g;\
	     s@__ASF__@${ASF}@g;' < $< > $@
