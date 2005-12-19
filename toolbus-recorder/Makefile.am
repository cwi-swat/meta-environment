# $Id$

ACLOCAL_FLAGS = -I .

CLEANFILES = \
	${PACKAGE}-${VERSION}.pkg ${JARFILE}

SUBDIRS = 

noinst_SCRIPTS = ${PACKAGE}-${VERSION}.pkg

${PACKAGE}-${VERSION}.pkg: package Makefile
	cp $< $@

include $(top_srcdir)/java_make_rules

JARFILE = toolbus-recorder.jar

pkgdata_DATA = ${JARFILE}

EXTRA_DIST = package ${JARFILE}
