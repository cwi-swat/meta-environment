include ${top_srcdir}/make_rules

pkgdata_DATA = toolbar.idef
EXTRA_DIST = ${java_JAVA} toolbar.idef

CLASSPATH_ENV = CLASSPATH=${JAVAROOT}:${top_srcdir}/meta-studio:${EXTERNAL_JARS}

JAVAROOT = ${top_builddir}/meta-studio
javadir = ${prefix}/classes/metastudio

jtif: 
	${IDEF} toolbar.idef
	${TOOLBUS}/bin/tifstojava -tool tool-bar -tifs toolbar.tifs \
		-package metastudio.components.toolbar -swing

java_JAVA = \
	ToolBar.java \
	ToolBarBridge.java \
	ToolBarTool.java \
	ToolBarTif.java
