bin_SCRIPTS = java-adapter tifstojava

EXTRA_DIST = java-adapter tifstojava.sh.src

% : %.sh.src Makefile
	sed	's@__EXTERNAL_JARS__@${EXTERNAL_JARS}@g;\
		 s@__PREFIX__@${prefix}@g;' < $< > $@
	chmod +x $@

CLEANFILES = tifstojava
