include ${top_srcdir}/make_rules

pkgdata_DATA = errorlist.idef
EXTRA_DIST = ${java_JAVA} errorlist.idef

CLASSPATH_ENV = CLASSPATH=${JAVAROOT}:${top_srcdir}/meta-studio:${EXTERNAL_JARS}

JAVAROOT = ${top_builddir}/meta-studio
javadir = ${prefix}/classes/metastudio

jtif: 
	${IDEF} errorlist.idef
	${TOOLBUS}/bin/tifstojava -tool error-list -tifs errorlist.tifs \
		-package metastudio.components.errorlist -swing

java_JAVA = \
	ErrorList.java \
	ErrorListCellRenderer.java \
	ErrorListBridge.java \
	ErrorListTool.java \
	ErrorListTif.java
