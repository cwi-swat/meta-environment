EXTRA_DIST = \
	meta-query-config.src \
	extract-relations

bin_SCRIPTS = \
	meta-query-config \
	extract-relations

CLEANFILES = meta-query-config

%: %.src
	sed 's@__PREFIX__@$(prefix)@g' < $< > $@ \
	&& chmod +x $@
