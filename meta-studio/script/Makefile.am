EXTRA_DIST = gui.src

bin_SCRIPTS = gui

CLEANFILES = gui

%: %.src Makefile
	sed "\
	     s@__JAVA__@java@g;\
	     s@__JARDIR__@${datadir}@g;\
	     s@__JARFILE__@${JAVA_JAR}@g;\
	     s@__SVG_SUPPORT__@${SVG_SUPPORT_PREFIX}@g;\
	     s@__LOCALJARS__@${datadir}/idw-gpl-1.5.0.jar@g;\
	     s@__MAINCLASS__@${JAVA_MAIN_CLASS}@g;\
	     s@__EXTERNAL_JARS__@${EXTERNAL_INSTALLED_JARS}@g;\
	" < $< > $@ && chmod +x $@
