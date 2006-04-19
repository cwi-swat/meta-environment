# $Id$

GENERATED_TBSCRIPTS = \
	start-meta-studio.tb \
	start-eqs-dump.tb

TBSCRIPTS = \
	asf-actions.tb \
	asf-editor-actions.tb \
	asf-editor-listeners.tb \
	asf-editor-utils.tb \
	asf-language.tb \
	asf-listeners.tb \
	asf-progress-listener.tb \
	asf-utils.tb \
	asfsdf-meta.tb

EXTRA_DIST = \
	$(TBSCRIPTS) \
	$(foreach i, $(GENERATED_TBSCRIPTS), $i.src) \
	asf-namespace.h \
	standard.asfsdf.actions.src

CLEANFILES = \
	$(GENERATED_TBSCRIPTS) \
	standard.asfsdf.actions

pkgdata_DATA = \
	$(TBSCRIPTS) \
	$(GENERATED_TBSCRIPTS) \
	asf-namespace.h

%.tb : %.tb.src Makefile
	sed "s@__ASF__@${ASF}@g; \
	     s@__ASFSDF_META__@${prefix}/share/asfsdf-meta/@g; \
	     s@__ASF_LIBRARY__@${ASF_LIBRARY}/share/asf-library/library@g; \
	     s@__META__@${META}@g; \
	     s@__VERSION__@${VERSION}@g;" \
	     < $< \
	     > $@

standard.asfsdf.actions:  standard.asfsdf.actions.src Makefile
	sed "s@__SDF_META__@${SDF_META}@g; \
	     s@__ASF_LIBRARY__@${ASF_LIBRARY}/share/asf-library/library@g" < $< > $@

install-data-hook: standard.asfsdf.actions
	cp standard.asfsdf.actions ${HOME}/.metaenv  

uninstall-hook:
	rm standard.asfsdf.actions ${HOME}/.metaenv  
