SUBDIRS		= spec utils test

ACLOCAL_FLAGS = -I .

EXTRA_DIST	= make_rules $(wildcard *.pkg) program-check.m4

CLEANFILES = ${PACKAGE}-*.pkg

noinst_SCRIPTS = ${PACKAGE}-${VERSION}.pkg

${PACKAGE}-${VERSION}.pkg: ${PACKAGE}.pkg Makefile
	sed 's#__VERSION__#${VERSION}#g;\
             s#__PACKAGE__#${PACKAGE}#g' < $< > $@

