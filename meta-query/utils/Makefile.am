EXTRA_DIST = meta-query-config.src

bin_SCRIPTS = meta-query-config

CLEANFILES = meta-query-config

%: %.src
	sed 's@__PREFIX__@$(prefix)@g' < $< > $@ \
	&& chmod +x $@
