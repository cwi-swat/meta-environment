SUBDIRS = meta-scripts src demo 

ACLOCAL_FLAGS = -I .

CLEANFILES = ${PACKAGE}-${VERSION}.pkg

noinst_SCRIPTS = ${PACKAGE}-${VERSION}.pkg

EXTRA_DIST=package

${PACKAGE}-${VERSION}.pkg: package Makefile
	cp $< $@

