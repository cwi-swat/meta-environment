# $Id$

include ${top_srcdir}/make_rules

ACLOCAL_FLAGS = -I .

CLEANFILES = ${PACKAGE}-${VERSION}.pkg

SUBDIRS = lib src script

EXTRA_DIST = reconf program-check.m4 make_rules package

noinst_SCRIPTS = ${PACKAGE}-${VERSION}.pkg

${PACKAGE}-${VERSION}.pkg: package Makefile
	cp $< $@


EXTRA_DIST+=Doxyfile.src  

if MAINTAINER_MODE

CLEANFILES+=Doxyfile

.PHONY: doc

doc: Doxyfile 
	doxygen

Doxyfile: Doxyfile.src
	sed 's@__PACKAGE__@${PACKAGE}@g' < $< > $@

endif
