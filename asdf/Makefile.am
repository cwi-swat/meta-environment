SUBDIRS = meta-scripts src

ACLOCAL_FLAGS = -I .

CLEANFILES = ${PACKAGE}-${VERSION}.pkg

noinst_SCRIPTS = ${PACKAGE}-${VERSION}.pkg

EXTRA_DIST=$(wildcard *.pkg)

${PACKAGE}-${VERSION}.pkg: ${PACKAGE}.pkg Makefile
	sed 's#__VERSION__#${VERSION}#g;\
             s#__PACKAGE__#${PACKAGE}#g' < $< > $@
