
EXTRA_DIST=${wildcard *.sh.src}

bin_SCRIPTS=meta-logger meta-playback metageneratetest

% : %.sh.src
	sed 's@__EXTERNALS__@${EXTERNAL_JARS}@g' < $< > $@ && chmod +x $@
