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
	asf-utils.tb 

EXTRA_DIST = \
	$(TBSCRIPTS) \
	$(foreach i, $(GENERATED_TBSCRIPTS), $i.src) \
	standard.asfsdf.buttons \
	standard.asfsdf.buttons.src

CLEANFILES = \
	asf-initialize.tb \
	standard.asfsdf.buttons

pkgdata_DATA = \
	$(TBSCRIPTS) \
	$(GENERATED_TBSCRIPTS) \
	standard.asfsdf.buttons

LIBRARY_LOCATION = \
	${ASF_LIBRARY}/share/asf-library/library

%.tb : %.tb.src Makefile
	sed 's@__ASF__@${ASF}@g; \
	     s@__ASFSDF_META__@${prefix}/share/asfsdf-meta/@g; \
	     s@__ASF_LIBRARY__@${LIBRARY_LOCATION}@g; \
	     s@__EXTERNAL_JARS__@$(shell echo "$(EXTERNAL_JARS)")@g;\
	     s@__PKGDATA__@$(pkgdatadir)@g; \
	     s@__META__@${META}@g; \
	     s@__VERSION__@${VERSION}@g;' \
	     < $< \
	     > $@

standard.asfsdf.buttons:  standard.asfsdf.buttons.src Makefile
	sed 's@__ASF_LIBRARY__@${LIBRARY_LOCATION}@g;\
	     s@__PGEN__@${PGEN}@g;\
	     s@__ASF__@${ASF}@g;' < $< > $@
