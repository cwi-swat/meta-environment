bin_SCRIPTS=java-adapter tifstojava ${PACKAGE}-config

EXTRA_DIST=java-adapter tifstojava.sh.src

% : %.sh.src Makefile
	sed	's@__EXTERNAL_JARS__@${EXTERNAL_JARS}@g;\
		 s@__PREFIX__@${prefix}@g;' < $< > $@
	chmod +x $@

CLEANFILES=tifstojava ${PACKAGE}-config

${PACKAGE}-config: ${PACKAGE}-config.sh.src Makefile
	sed 's@__PREFIX__@${prefix}@g;\
             s@__EXTERNAL_JARS__@${EXTERNAL_JARS}@g;\
             s@__VERSION__@${VERSION}@g' < $< > $@ && chmod +x $@
