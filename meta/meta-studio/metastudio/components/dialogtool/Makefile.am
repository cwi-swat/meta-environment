include ${top_srcdir}/make_rules

pkgdata_DATA = dialogtool.idef
EXTRA_DIST = ${java_JAVA} dialogtool.idef

CLASSPATH_ENV = CLASSPATH=${JAVAROOT}:${top_srcdir}/meta-studio:${EXTERNAL_JARS}

JAVAROOT = ${top_builddir}/meta-studio
javadir = ${prefix}/classes/metastudio

jtif: 
	${IDEF} dialogtool.idef
	${TOOLBUS}/bin/tifstojava -tool dialog-tool -tifs dialogtool.tifs \
		-package metastudio.components.dialogtool -swing

java_JAVA = \
	DialogTool.java \
	DialogToolBridge.java \
	DialogToolTool.java \
	DialogToolTif.java
