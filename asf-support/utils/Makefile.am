EXTRA_DIST = asf-support-config.src

bin_SCRIPTS = asf-support-config

CLEANFILES = asf-support-config

% : %.src
	sed 's@__PREFIX__@$(prefix)@g' < $< > $@ && \
	chmod +x $@
