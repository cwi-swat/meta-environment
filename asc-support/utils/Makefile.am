

bin_SCRIPTS = asc-support-config

CLEANFILES = asc-support-config

% : %.src
	sed 's@__PREFIX__@$(prefix)@g' < $< > $@ && \
	chmod +x $@
