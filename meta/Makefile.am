# $Id$

include ${top_srcdir}/make_rules

EXTRA_DIST = make_rules

SUBDIRS = \
	config \
	editors \
	meta-studio \
	src \
	in-output \
        term-store \
	utils \
	tbscripts \
	configuration-manager

noinst_SCRIPTS = ${PACKAGE}-${VERSION}.pkg

${PACKAGE}-${VERSION}.pkg: ${PACKAGE}.pkg Makefile
	sed 's#__VERSION__#${VERSION}#g;\
             s#__PACKAGE__#${PACKAGE}#g' < $< > $@

