bin_SCRIPTS=java-adapter tifstojava

% : %.src
	sed	's@__EXTERNAL_JARS__@${EXTERNAL_JARS}@g;\
		 s@__PREFIX__@${prefix}@g;' < $< > $@
