SUBDIRS    = toolbus aterm adapters tbviz doc demos test

EXTRA_DIST = program-check.m4 reconf DEVELOPERS-INFO

noinst_SCRIPTS = ${PACKAGE}-${VERSION}.pkg

${PACKAGE}-${VERSION}.pkg: ${PACKAGE}.pkg Makefile
	sed 's#__VERSION__#${VERSION}#g;\
             s#__PACKAGE__#${PACKAGE}#g' < $< > $@

