SUBDIRS		= spec utils test

ACLOCAL_FLAGS = -I .

EXTRA_DIST	= make_rules package program-check.m4

CLEANFILES = ${PACKAGE}-*.pkg

noinst_SCRIPTS = ${PACKAGE}-${VERSION}.pkg

${PACKAGE}-${VERSION}.pkg: package Makefile
	cp $ < $@


