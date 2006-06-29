# $Id$

SUBDIRS		= lib

ACLOCAL_FLAGS = -I .

EXTRA_DIST=package

bin_SCRIPTS = ptable-support-config

CLEANFILES = ptable-support-config ${PACKAGE}-${VERSION}.pkg

noinst_SCRIPTS = ${PACKAGE}-${VERSION}.pkg

${PACKAGE}-${VERSION}.pkg: package Makefile
	cp $< $@		

% : %.sh.src
	sed 's@__PREFIX__@$(prefix)@g' < $< > $@ && \
	chmod +x $@EXTRA_DIST+=Doxyfile.src  

if MAINTAINER_MODE

CLEANFILES+=Doxyfile

.PHONY: doc

doc: Doxyfile 
	doxygen

Doxyfile: Doxyfile.src
	sed 's@__PACKAGE__@${PACKAGE}@g' < $< > $@

endif
