include ${top_srcdir}/make_rules

pkgdata_DATA = statushistory.idef
EXTRA_DIST = ${java_JAVA} statushistory.idef

CLASSPATH_ENV = CLASSPATH=${JAVAROOT}:${top_srcdir}/meta-studio:${EXTERNAL_JARS}

JAVAROOT = ${top_builddir}/meta-studio
javadir = ${prefix}/classes/metastudio

jtif: 
	${IDEF} statushistory.idef
	${TOOLBUS}/bin/tifstojava -tool status-history -tifs statushistory.tifs \
		-package metastudio.components.statushistory -swing

java_JAVA = \
	StatusHistory.java \
	StatusHistoryBridge.java \
	StatusHistoryTool.java \
	StatusHistoryTif.java
