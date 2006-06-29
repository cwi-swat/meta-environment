# $Id$

SUBDIRS = libmept libptmept utils  test 

ACLOCAL_FLAGS = -I .

CLEANFILES = ${PACKAGE}-${VERSION}.pkg

EXTRA_DIST=package 

noinst_SCRIPTS = ${PACKAGE}-${VERSION}.pkg

${PACKAGE}-${VERSION}.pkg: package Makefile
	cp $< $@

EXTRA_DIST+=Doxyfile.src  
CLEANFILES+=Doxyfile

if MAINTAINER_MODE

.PHONY: doc

doc: Doxyfile 
	doxygen

Doxyfile: Doxyfile.src
	sed 's@__PACKAGE__@${PACKAGE}@g' < $< > $@

endif
