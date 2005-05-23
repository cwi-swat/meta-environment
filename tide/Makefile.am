
SUBDIRS	= toolbus scripts .

include $(top_srcdir)/java_make_rules

TOOLNAME = tide
JAVA_PACKAGE = nl.cwi.sen1.tide
JARFILE = $(TOOLNAME).jar
MAIN_CLASS = $(JAVA_PACKAGE).TideMainFrame

pkgdata_DATA = ${JARFILE}

ACLOCAL_FLAGS = -I .

EXTRA_DIST = build.xml package $(JARFILE)

noinst_SCRIPTS = ${PACKAGE}-${VERSION}.pkg

${PACKAGE}-${VERSION}.pkg: package Makefile
	cp $< $@

CLEANFILES = tide.jar ${PACKAGE}-${VERSION}.pkg
