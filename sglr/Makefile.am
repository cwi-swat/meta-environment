# $Id$

SUBDIRS     = doc libsglr sglr dump restorebrackets test

EXTRA_DIST  = make_rules reconf program-check.m4 $(wildcard *.pkg)

noinst_SCRIPS = ${PACKAGE}-${VERSION}.pkg

${PACKAGE}-${VERSION}.pkg: ${PACKAGE}.pkg Makefile
	sed 's#__VERSION__#${VERSION}#g;\
             s#__PACKAGE__#${PACKAGE}#g' < $< > $@

