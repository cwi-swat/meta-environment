GENERATED_TBSCRIPTS = \
	vis-plugin-generic.tb \
	vis-plugin-text-unparsing.idef

EXTRA_DIST = \
	$(foreach i, $(GENERATED_TBSCRIPTS), $i.src) 

CLEANFILES = \
	$(GENERATED_TBSCRIPTS) 

pkgdata_DATA = \
	$(GENERATED_TBSCRIPTS) 

%.idef: %.idef.src Makefile
	sed -e 's@__PKGDATA__@$(datadir)@g'\
            -e 's@__LOCAL_JARS__@$(LOCAL_JARS)@g'\
            -e "s@__EXTERNAL_JARS__@$(EXTERNAL_JARS)@g"\
            -e 's@__JARFILE__@$(JAVA_JAR)@g'\
             < $< > $@

%.tb : %.tb.src Makefile
	sed "s@__PKGDATA__@${datadir}@g; \
	     s@__LOCAL_JARS__@${LOCAL_JARS}@g; \
	     s@__EXTERNAL_JARS__@${EXTERNAL_JARS}@g; \
	     s@__JARFILE__@${JAVA_JAR}@g;" \
	     < $< \
	     > $@
