# $Id$

SUBDIRS = libmept libptmept utils  test doc

ACLOCAL_FLAGS = -I .

CLEANFILES = ${PACKAGE}-${VERSION}.pkg

EXTRA_DIST=package

noinst_SCRIPTS = ${PACKAGE}-${VERSION}.pkg

${PACKAGE}-${VERSION}.pkg: package Makefile
	cp $< $@

.PHONY: doc

doc:
	cd doc && $(MAKE) $(AM_MAKE_FLAGS) doc
