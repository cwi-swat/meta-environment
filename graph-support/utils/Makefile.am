SUBDIRS = tree2graph layoutgraph

bin_SCRIPTS = graph-support-config

EXTRA_DIST = graph-support-config.sh.src

graph-support-config: graph-support-config.sh.src Makefile
	sed 's@__PREFIX__@${prefix}@g;\
	     s@__EXTERNAL_JARS__@${EXTERNAL_JARS}@g;\
             s@__VERSION__@${VERSION}@g' < $< > $@ \
	&& chmod +x $@

CLEANFILES = $(bin_SCRIPTS)
