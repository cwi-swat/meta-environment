include ${top_srcdir}/make_rules

SUBDIRS = utils data components .

pkgdata_DATA = meta-studio.idef
EXTRA_DIST = ${java_JAVA} meta-studio.idef

CLASSPATH_ENV = CLASSPATH=${JAVAROOT}:${top_srcdir}/meta-studio:${EXTERNAL_JARS}

JAVAROOT = ${top_builddir}/meta-studio
javadir = ${prefix}/classes/metastudio

jtif: 
	${IDEF} meta-studio.idef
	${TOOLBUS}/bin/tifstojava -tool user-interface -tifs meta-studio.tifs \
		-package metastudio -swing

java_JAVA = \
	MetaStudio.java \
	MainTabs.java \
	MessageTabs.java \
	UserInterfaceBridge.java \
	UserInterfaceTif.java \
	UserInterfaceTool.java \
	ValueChangedListener.java
