# $Id$

GENERATED_TBSCRIPTS = \
	asf-initialize.tb \
	start-meta-studio.tb 

TBSCRIPTS = \
	asf-actions.tb \
	asf-editor-actions.tb \
	asf-editor-utils.tb \
	asf-language.tb \
	asf-listeners.tb \
	asf-utils.tb \
	term-actions.tb \
	term-editor-actions.tb \
	term-editor-utils.tb \
	term-parsetable.tb \
	term-utils.tb

EXTRA_DIST = \
	$(TBSCRIPTS) \
	$(foreach i, $(GENERATED_TBSCRIPTS), $i.src) \
	asf-namespace.h \
	standard.asfsdf.buttons \
	standard.asfsdf.buttons.src

CLEANFILES = \
	$(GENERATED_TBSCRIPTS) \
	standard.asfsdf.buttons

pkgdata_DATA = \
	$(TBSCRIPTS) \
	$(GENERATED_TBSCRIPTS) \
	asf-namespace.h \
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
	     s@__ASF__@${ASF}@g;' < $< > $@
