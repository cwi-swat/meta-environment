
EXTRA_DIST = asf-library-config.src

bin_SCRIPTS = asf-library-config

CLEANFILES = asf-library-config

% : %.src
	sed 's@__PREFIX__@$(prefix)@g' < $< > $@ && \
	chmod +x $@
