
EXTRA_DIST = $(wildcard *.src) $(wildcard *.sh)

bin_SCRIPTS = asf-library-config 
noinst_SCRIPTS = gen-protos.sh gen-forward.sh

CLEANFILES = $(bin_SCRIPTS)

% : %.src
	sed 's@__PREFIX__@$(prefix)@g' < $< > $@ && \
	chmod +x $@
