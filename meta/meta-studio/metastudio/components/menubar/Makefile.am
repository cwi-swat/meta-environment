include ${top_srcdir}/make_rules

pkgdata_DATA = menubar.idef
EXTRA_DIST = ${java_JAVA} menubar.idef

CLASSPATH_ENV = CLASSPATH=${JAVAROOT}:${top_srcdir}/meta-studio:${EXTERNAL_JARS}

JAVAROOT = ${top_builddir}/meta-studio
javadir = ${prefix}/classes/metastudio

jtif: 
	${IDEF} menubar.idef
	${TOOLBUS}/bin/tifstojava -tool menu-bar -tifs menubar.tifs \
		-package metastudio.components.menubar -swing

java_JAVA = \
	MenuBar.java \
	MenuBarBridge.java \
	MenuBarTool.java \
	MenuBarTif.java
