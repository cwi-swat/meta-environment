include ${top_srcdir}/make_rules

pkgdata_DATA = graphnodesizer.idef
EXTRA_DIST = ${java_JAVA} graphnodesizer.idef

CLASSPATH_ENV = CLASSPATH=${JAVAROOT}:${top_srcdir}/meta-studio:${EXTERNAL_JARS}

JAVAROOT = ${top_builddir}/meta-studio
javadir = ${prefix}/classes/metastudio

jtif: 
	${IDEF} graphnodesizer.idef
	${TOOLBUS}/bin/tifstojava -tool graph-node-sizer -tifs graphnodesizer.tifs \
		-package metastudio.components.graphnodesizer -swing

java_JAVA = \
	GraphNodeSizer.java \
	GraphNodeSizerBridge.java \
	GraphNodeSizerTool.java \
	GraphNodeSizerTif.java
