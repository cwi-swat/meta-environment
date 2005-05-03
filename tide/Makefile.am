
SUBDIRS		= toolbus images scripts .

include $(top_srcdir)/java_make_rules

TOOLNAME = tide
JAVA_PACKAGE = nl.cwi.sen1.tide
JARFILE = $(TOOLNAME).jar
MAIN_CLASS = $(JAVA_PACKAGE).TideMainFrame

pkgdata_DATA = ${JARFILE}

ACLOCAL_FLAGS = -I .

EXTRA_DIST      = package

noinst_SCRIPTS = ${PACKAGE}-${VERSION}.pkg

${PACKAGE}-${VERSION}.pkg: package Makefile
	cp $< $@

CLEANFILES = tide.jar ${PACKAGE}-${VERSION}.pkg
