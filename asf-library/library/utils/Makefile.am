
EXTRA_DIST = asf-library-config.src

bin_SCRIPTS = asf-library-config

CLEANFILES = $(bin_SCRIPTS)

% : %.src
	sed 's@__PREFIX__@$(prefix)@g' < $< > $@ && \
	chmod +x $@
