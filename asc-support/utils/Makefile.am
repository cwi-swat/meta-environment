
EXTRA_DIST = asc-support-config.src $(wildcard *.sh)

bin_SCRIPTS = asc-support-config
noinst_SCRIPTS = gen-forward.sh gen-protos.sh gen-link-test.sh


CLEANFILES = asc-support-config

% : %.src
	sed 's@__PREFIX__@$(prefix)@g' < $< > $@ && \
	chmod +x $@
