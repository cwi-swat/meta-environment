# $Id$

include ${top_srcdir}/make_rules

EXTRA_DIST = \
	${java_JAVA} \
	sdf-import-graph.sh.src \
	sdf-import-graph.idef

CLEANFILES = sdf-import-graph

bin_SCRIPTS = sdf-import-graph

pkgdata_DATA = sdf-import-graph.idef

java_JAVA = \
	SdfImportGraph.java \
	SdfImportGraphTif.java \
	SdfImportGraphTool.java \
	SdfImportGraphBridge.java

CLASSPATH_ENV = CLASSPATH=${JAVAROOT}:${top_srcdir}/utils/import-graph/sdf:${EXTERNAL_JARS}

JAVAROOT = ${top_builddir}/utils/import-graph

javadir = ${prefix}/classes/sdf

jtif:
	${TOOLBUS}/bin/idef2tif sdf-import-graph.idef
	${TOOLBUS}/bin/tifstojava \
		-tool sdf-import-graph \
		-tifs sdf-import-graph.tifs \
		-package sdf

%: %.sh.src Makefile
	sed -e 's@__EXTERNAL_JARS__@${EXTERNAL_JARS}@g' \
	    -e 's@__INSTALL_DIR__@${prefix}/classes@g' \
	    -e 's@__JAVA__@${JAVA}@g' \
	< $< > $@
	chmod +x $@
