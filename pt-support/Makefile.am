# $Id$

SUBDIRS		= libmept libptmept utils  test

CLEANFILES = ${PACKAGE}-${VERSION}.pkg

EXTRA_DIST=$(wildcard *.pkg)

noinst_SCRIPTS = ${PACKAGE}-${VERSION}.pkg

${PACKAGE}-${VERSION}.pkg: ${PACKAGE}.pkg Makefile
	sed 's#__VERSION__#${VERSION}#g;\
             s#__PACKAGE__#${PACKAGE}#g' < $< > $@
