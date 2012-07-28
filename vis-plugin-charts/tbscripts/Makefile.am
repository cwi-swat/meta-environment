GENERATED_TBSCRIPTS = \
	vis-plugin-charts.tb 

EXTRA_DIST = \
	$(foreach i, $(GENERATED_TBSCRIPTS), $i.src) 

CLEANFILES = \
	$(GENERATED_TBSCRIPTS) 

pkgdata_DATA = \
	$(GENERATED_TBSCRIPTS)

%.tb : %.tb.src Makefile
	sed "s@__PKGDATA__@${datadir}@g; \
	     s@__LOCAL_JARS__@${LOCAL_JARS}@g; \
	     s@__EXTERNAL_JARS__@${EXTERNAL_JARS}@g; \
	     s@__JARFILE__@${JAVA_JAR}@g;" \
	     < $< \
	     > $@
