# $Id$

SUBDIRS = lib utils

ACLOCAL_FLAGS = -I .

CLEANFILES = ${PACKAGE}-${VERSION}.pkg

EXTRA_DIST = program-check.m4 package

noinst_SCRIPTS = ${PACKAGE}-${VERSION}.pkg

${PACKAGE}-${VERSION}.pkg: package Makefile
	cp $< $@

