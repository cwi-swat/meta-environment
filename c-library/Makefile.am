# $Id$

SUBDIRS	= \
	logging \
	statistics

ACLOCAL_FLAGS = -I .

EXTRA_DIST=package

bin_SCRIPTS = c-library-config

CLEANFILES = c-library-config ${PACKAGE}-${VERSION}.pkg

noinst_SCRIPTS = ${PACKAGE}-${VERSION}.pkg

${PACKAGE}-${VERSION}.pkg: package Makefile
	cp $< $@		

${PACKAGE}-config: Makefile
	@(echo "#! /bin/sh";) > $@ && chmod +x $@

