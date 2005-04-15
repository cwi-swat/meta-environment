EXTRA_DIST = gui.src

bin_SCRIPTS = gui

CLEANFILES = gui

%: %.src Makefile
	sed "\
	     s@__JAVA__@${JAVA}@g;\
	     s@__JARDIR__@${pkgdatadir}@g;\
	     s@__EXTERNAL_JARS__@${EXTERNAL_JARS}@g;\
	" < $< > $@ && chmod +x $@
