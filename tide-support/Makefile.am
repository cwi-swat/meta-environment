
SUBDIRS		= lib

ACLOCAL_FLAGS = -I .

EXTRA_DIST      = package

noinst_SCRIPTS = ${PACKAGE}-${VERSION}.pkg

bin_SCRIPTS = ${PACKAGE}-config

${PACKAGE}-${VERSION}.pkg: package Makefile
	cp $< $@

${PACKAGE}-config: Makefile
	(echo "#! /bin/sh" ; echo "echo \"${prefix}\"" ) > $@ && chmod +x $@

CLEANFILES = ${PACKAGE}-${VERSION}.pkg ${PACKAGE}-config
