# $Id$

SUBDIRS = doc libsglr sglr dump restorebrackets test

ACLOCAL_FLAGS = -I .

CLEANFILES = ${PACKAGE}-${VERSION}.pkg

EXTRA_DIST  = make_rules reconf program-check.m4 package

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
