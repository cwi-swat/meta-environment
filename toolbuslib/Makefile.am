SUBDIRS    = libtb aterm

EXTRA_DIST = program-check.m4 reconf \
             toolbuslib-config.sh.src \
	     $(wildcard *.pkg)

bin_SCRIPTS = toolbuslib-config

CLEANFILES = toolbuslib-config

% : %.sh.src
	sed 's@__PREFIX__@$(prefix)@g' < $< > $@ && \
	chmod +x $@

noinst_SCRIPTS = ${PACKAGE}-${VERSION}.pkg

${PACKAGE}-${VERSION}.pkg: ${PACKAGE}.pkg Makefile
	sed 's#__VERSION__#${VERSION}#g;\
             s#__PACKAGE__#${PACKAGE}#g' < $< > $@
