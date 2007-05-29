GENERATED_TBSCRIPTS = \
	fbi.tb \
	fbmp.tb \
	vis-plugin-table.tb \
	vis-plugin-scatterchart.tb \
	vis-plugin-piechart.tb \
	vis-plugin-graph.tb \
	vis-plugin-csv.tb \
	vis-plugin-barchart.tb \
	vpcp.tb \
	vpcp-config.tb

EXTRA_DIST = \
	$(foreach i, $(GENERATED_TBSCRIPTS), $i.src) \
	start-vis.tb \
	fbmp-open-location.tb 

CLEANFILES = \
	$(GENERATED_TBSCRIPTS) 

pkgdata_DATA = \
	$(GENERATED_TBSCRIPTS) \
        start-vis.tb \
        fbmp-open-location.tb

%.tb : %.tb.src Makefile
	sed "s@__PKGDATA__@${datadir}@g; \
	     s@__LOCAL_JARS__@${LOCAL_JARS}@g; \
	     s@__EXTERNAL_JARS__@${EXTERNAL_JARS}@g; \
	     s@__JARFILE__@${JAVA_JAR}@g;" \
	     < $< \
	     > $@
