# $Id$

TBSCRIPTS = \
	asf-actions.tb \
	asf-editor-actions.tb \
	asf-editor-utils.tb \
	asf-language.tb \
	asf-listeners.tb \
	asf-utils.tb 

EXTRA_DIST = \
	$(TBSCRIPTS) \
	asf-initialize.tb.src \
	standard.asfsdf.buttons \
	standard.asfsdf.buttons.src

CLEANFILES = \
	asf-initialize.tb \
	standard.asfsdf.buttons

pkgdata_DATA = \
	$(TBSCRIPTS) \
	asf-initialize.tb \
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
