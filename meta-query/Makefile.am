SUBDIRS = utils relations

ACLOCAL_FLAGS = -I .

CLEANFILES = ${PACKAGE}-*.pkg

EXTRA_DIST=$(wildcard *.pkg) $(wildcard *.m4)

noinst_SCRIPTS = ${PACKAGE}-${VERSION}.pkg

${PACKAGE}-${VERSION}.pkg: ${PACKAGE}.pkg Makefile
	sed 's#__VERSION__#${VERSION}#g;\
             s#__PACKAGE__#${PACKAGE}#g' < $< > $@

