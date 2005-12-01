# $Id$

TBSCRIPTS = \
	meta-interface.tb \
	error-display.tb \
	graph-arbiter.tb \
	asfsdfapigen.tb

EXTRA_DIST = \
	meta-interface.tb.src \
	error-display.tb \
	asfsdfapigen.tb \
	graph-arbiter.tb \
	standard.asfsdf.buttons \
	standard.asfsdf.buttons.src

CLEANFILES = \
	meta-interface.tb \
	standard.asfsdf.buttons

pkgdata_DATA = \
	$(TBSCRIPTS) \
	standard.asfsdf.buttons

LIBRARY_LOCATION = \
	${ASF_LIBRARY}/share/asf-library/library

%.tb : %.tb.src Makefile
	sed 's@__ASF__@${ASF}@g; \
	     s@__ASFSDF_META__@${prefix}/share/asfsdf-meta/@g; \
	     s@__ASF_LIBRARY__@${LIBRARY_LOCATION}@g; \
	     s@__META__@${META}@g; \
	     s@__VERSION__@${VERSION}@g;' \
	     < $< \
	     > $@

standard.asfsdf.buttons:  standard.asfsdf.buttons.src Makefile
	sed 's@__ASF_LIBRARY__@${LIBRARY_LOCATION}@g;\
	     s@__PGEN__@${PGEN}@g;\
	     s@__ASF__@${ASF}@g;' < $< > $@
