include ${top_srcdir}/make_rules

pkgdata_DATA = infolist.idef
EXTRA_DIST = ${java_JAVA} infolist.idef

CLASSPATH_ENV = CLASSPATH=${JAVAROOT}:${top_srcdir}/meta-studio:${EXTERNAL_JARS}

JAVAROOT = ${top_builddir}/meta-studio
javadir = ${prefix}/classes/metastudio

jtif: 
	${IDEF} infolist.idef
	${TOOLBUS}/bin/tifstojava -tool info-list -tifs infolist.tifs \
		-package metastudio.components.infolist -swing

java_JAVA = \
	InfoList.java \
	InfoListBridge.java \
	InfoListTool.java \
	InfoListTif.java
