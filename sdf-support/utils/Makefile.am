

bin_SCRIPTS = sdf-support-config

CLEANFILES = sdf-support-config

% : %.src
	sed 's@__PREFIX__@$(prefix)@g' < $< > $@ && \
	chmod +x $@
