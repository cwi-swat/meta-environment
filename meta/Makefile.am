# $Id$

ACLOCAL_FLAGS = -I .

include ${top_srcdir}/make_rules

EXTRA_DIST = make_rules program-check.m4 package libltdl/config-h.in

CLEANFILES = \
	${PACKAGE}-${VERSION}.pkg \
	libltdl/config.log \
	libltdl/config.h \
	libltdl/config.status \
	libltdl/stamp-h1

SUBDIRS = \
	src \
	gui \
	in-output \
	action-interpreter \
	term-store \
	tbscripts \
	configuration-manager \
	editors

noinst_SCRIPTS = ${PACKAGE}-${VERSION}.pkg

${PACKAGE}-${VERSION}.pkg: package Makefile
	cp $< $@
