EXTRA_DIST = \
	merge-rstores \
	meta-query-config.src \
	tbscan

bin_SCRIPTS = \
	merge-rstores \
	meta-query-config \
	tbscan

CLEANFILES = meta-query-config

%: %.src
	sed 's@__PREFIX__@$(prefix)@g' < $< > $@ \
	&& chmod +x $@
