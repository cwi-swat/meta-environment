# $Id$

include ${top_srcdir}/make_rules

SUBDIRS    = src grammar sdf-checker test sdf-upgrade

EXTRA_DIST = reconf program-check.m4 make_rules $(wildcard *.pkg)

noinst_SCRIPTS = ${PACKAGE}-${VERSION}.pkg

${PACKAGE}-${VERSION}.pkg: ${PACKAGE}.pkg Makefile
	sed 's#__VERSION__#${VERSION}#g;\
             s#__PACKAGE__#${PACKAGE}#g' < $< > $@

