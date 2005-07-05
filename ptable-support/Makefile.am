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
	chmod +x $@