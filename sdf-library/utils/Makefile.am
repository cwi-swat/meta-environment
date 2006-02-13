
EXTRA_DIST = sdf-library-config.src

bin_SCRIPTS = sdf-library-config

CLEANFILES = sdf-library-config

% : %.src
	sed 's@__PREFIX__@$(prefix)@g' < $< > $@ && \
	chmod +x $@
