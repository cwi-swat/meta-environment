EXTRA_DIST = \
	meta-query-config.src \
	extract-relations \
	evaluate-query

bin_SCRIPTS = \
	meta-query-config \
	extract-relations \
	evaluate-query

CLEANFILES = meta-query-config

%: %.src
	sed 's@__PREFIX__@$(prefix)@g' < $< > $@ \
	&& chmod +x $@
