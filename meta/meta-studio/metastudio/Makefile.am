include ${top_srcdir}/make_rules

SUBDIRS		= graph

ACSOURCES	= Module.java
java_JAVA	= \
	ExtensionFilter.java \
	ListListModel.java \
	MetaStudio.java \
	ModuleGraphPanel.java \
	ModuleManager.java \
	ModuleSelectionListener.java \
	ModuleStatusPanel.java \
	Preferences.java \
	${ACSOURCES} \
	${GENSOURCES}

GENSOURCES	= UserInterfaceTif.java UserInterfaceTool.java \
		UserInterfaceBridge.java

pkgdata_DATA	= meta-studio.idef
EXTRA_DIST	= meta-studio.idef

CLASSPATH_ENV	= CLASSPATH=${JAVAROOT}:${SHARED_OBJECTS}:${JAVA_ATERM}:${TOOLBUS}/classes


JAVAROOT	= ${top_builddir}/meta-studio
javadir		= ${prefix}/classes/metastudio

TYPES		= Module.ace

api: metastudio.ace ${TYPES}
	autocode \
		--application metastudio \
		--property "java->rootdir:=\"${JAVAROOT}\"" \
		metastudio.ace

jtif: 
	${IDEF} meta-studio.idef
	${TOOLBUS}/bin/tifstojava -tool user-interface -tifs meta-studio.tifs \
		-package metastudio
