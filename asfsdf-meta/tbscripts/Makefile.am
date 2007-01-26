# $Id$

GENERATED_TBSCRIPTS = \
	asf-initialize.tb \
	start-meta-studio.tb \
	start-eqs-dump.tb \
	start-test-eqs-dump.tb \
	sdf-pretty.tb

TBSCRIPTS = \
	asf-actions.tb \
	asf-editor-actions.tb \
	asf-editor-listeners.tb \
	asf-editor-utils.tb \
	asf-language.tb \
	asf-listeners.tb \
	asf-progress-listener.tb \
	asf-utils.tb \
	asf-pretty-print.tb \
	asfsdf-meta.tb \
	asf-gui-listeners.tb

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
	asf-namespace.h \
	standard.asfsdf.actions

%.tb : %.tb.src Makefile
	sed "s@__ASF__@${ASF_PREFIX}@g; \
	     s@__ASFSDF_META__@${prefix}/share/asfsdf-meta/@g; \
	     s@__SDF2_PRETTY__@${SDF_PRETTY_PREFIX}/share/sdf-pretty/Sdf2-pretty.eqs@g; \
	     s@__META__@${META_PREFIX}@g; \
	     s@__VERSION__@${VERSION}@g;" \
	     < $< \
	     > $@

standard.asfsdf.actions:  standard.asfsdf.actions.src Makefile
	sed "s@__SDF_META__@${SDF_META_PREFIX}@g; \
	     s@__PREFIX__@${prefix}@g" < $< > $@
