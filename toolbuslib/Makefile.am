SUBDIRS    = libtb aterm

EXTRA_DIST = program-check.m4 reconf \
             toolbuslib-config.sh.src

bin_SCRIPTS = toolbuslib-config

CLEANFILES = toolbuslib-config

% : %.sh.src
	sed 's@__PREFIX__@$(prefix)@g' < $< > $@ && \
	chmod +x $@


