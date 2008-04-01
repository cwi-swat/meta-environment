EXTRA_DIST = tifstojava.sh.src

CLEANFILES = tifstojava 

bin_SCRIPTS = tifstojava

% : %.sh.src Makefile
	sed "s@__EXTERNAL_JARS__@$(EXTERNAL_JARS)@g;\
	s@__JARFILE__@$(prefix)/share/$(JAVA_JAR)@g;" < $< > $@ && chmod +x $@

