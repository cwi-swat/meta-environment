include ${top_srcdir}/make_rules

pkgdata_DATA = treebrowser.idef
EXTRA_DIST = ${java_JAVA} treebrowser.idef

CLASSPATH_ENV = CLASSPATH=${JAVAROOT}:${top_srcdir}/meta-studio:${EXTERNAL_JARS}

JAVAROOT = ${top_builddir}/meta-studio
javadir = ${prefix}/classes/metastudio

jtif: 
	${IDEF} treebrowser.idef
	${TOOLBUS}/bin/tifstojava -tool tree-browser -tifs treebrowser.tifs \
		-package metastudio.components.treebrowser -swing

java_JAVA = \
	TreeBrowser.java \
	TreeBrowserBridge.java \
	TreeBrowserTool.java \
	TreeBrowserTif.java
