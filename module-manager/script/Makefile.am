EXTRA_DIST = module-manager.src

bin_SCRIPTS = module-manager

CLEANFILES = module-manager

%: %.src Makefile
	sed "\
	     s@__JAVA__@${JAVA}@g;\
	     s@__JARDIR__@${pkgdatadir}@g;\
	     s@__EXTERNAL_JARS__@${EXTERNAL_JARS}@g;\
	" < $< > $@ && chmod +x $@
