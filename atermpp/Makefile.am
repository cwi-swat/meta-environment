SUBDIRS = src test example doc

ACLOCAL_FLAGS = -I .

EXTRA_DIST = package

CLEANFILES = ${PACKAGE}-${VERSION}.pkg

noinst_SCRIPTS = ${PACKAGE}-${VERSION}.pkg

${PACKAGE}-${VERSION}.pkg: package Makefile
	cp $< $@
