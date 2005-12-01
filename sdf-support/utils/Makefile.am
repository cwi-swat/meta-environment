
SUBDIRS = sdf-modules sdf-renaming

EXTRA_DIST = sdf-support-config.src

bin_SCRIPTS = sdf-support-config

CLEANFILES = sdf-support-config

% : %.src
	sed 's@__PREFIX__@$(prefix)@g' < $< > $@ && \
	chmod +x $@
