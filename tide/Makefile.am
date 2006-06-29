
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
JAVA_PACKAGES=nl,nl.cwi,nl.cwi.sen1,nl.cwi.sen1.tide,nl.cwi.sen1.tide.adapters,nl.cwi.sen1.tide.adapters.gdb,nl.cwi.sen1.tide.tool,nl.cwi.sen1.tide.tool.proclist,nl.cwi.sen1.tide.tool.prefeditor,nl.cwi.sen1.tide.tool.stackviewer,nl.cwi.sen1.tide.tool.srcviewer,nl.cwi.sen1.tide.tool.support,nl.cwi.sen1.tide.tool.ruleinspector
