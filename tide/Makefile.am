
SUBDIRS		= toolbus lib-c tide META-INF images examples .

EXTRA_DIST	= tide.sh.src

bin_SCRIPTS	= tide.sh

data_DATA	= tide.jar

JARCLASSDIRS	= tide/tool tide/tool/support \
		tide/tool/proclist tide/tool/ruleinspector tide/tool/srcviewer \
		tide/tool/prefeditor

JARCLASSES	= ${JARCLASSDIRS:%=%/*.class}
JARIMAGES	= ${srcdir}/images/*.gif
JARFILES	= META-INF/MANIFEST.MF META-INF/tide-defaults.properties \
		${JARIMAGES}  ${JARCLASSES}

tide.jar: ${JARFILES}
	FILES="${JARFILES}"; \
	jar cf tide.jar $$FILES

%.sh: %.sh.src Makefile
	sed 's@__JARDIR__@${datadir}@g;\
	     s@__TBDIR__@${datadir}@g;\
	' < $< > $@ && chmod +x $@


