# $Id$

include ${top_srcdir}/make_rules

EXTRA_DIST = ${java_JAVA} sdf-import-graph.idef

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
	${IDEF2TIF} sdf-import-graph.idef
	${TOOLBUS}/bin/tifstojava \
		-tool sdf-import-graph \
		-tifs sdf-import-graph.tifs \
		-package sdf
