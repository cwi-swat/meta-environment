include ${top_srcdir}/make_rules

pkgdata_DATA = statusbar.idef
EXTRA_DIST = ${java_JAVA} statusbar.idef

CLASSPATH_ENV = CLASSPATH=${JAVAROOT}:${top_srcdir}/meta-studio:${EXTERNAL_JARS}

JAVAROOT = ${top_builddir}/meta-studio
javadir = ${prefix}/classes/metastudio

jtif: 
	${IDEF} statusbar.idef
	${TOOLBUS}/bin/tifstojava -tool status-bar -tifs statusbar.tifs \
		-package metastudio.components.statusbar -swing

java_JAVA = \
	StatusBar.java \
	StatusBarBridge.java \
	StatusBarTool.java \
	StatusBarTif.java
