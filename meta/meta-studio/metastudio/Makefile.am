include ${top_srcdir}/make_rules

SUBDIRS = graph

pkgdata_DATA = meta-studio.idef
EXTRA_DIST = meta-studio.idef

CLASSPATH_ENV = CLASSPATH=${JAVAROOT}:${top_srcdir}/meta-studio:${SHARED_OBJECTS}:${JAVA_ATERM}:${TOOLBUS}/classes


JAVAROOT = ${top_builddir}/meta-studio
javadir = ${prefix}/classes/metastudio

TYPES = Module.ace

api: metastudio.ace ${TYPES}
	autocode \
		--application metastudio \
		--property "java->rootdir:=\"${JAVAROOT}\"" \
		metastudio.ace

jtif: 
	${IDEF} meta-studio.idef
	${TOOLBUS}/bin/tifstojava -tool user-interface -tifs meta-studio.tifs \
		-package metastudio -swing

ACSOURCES = Module.java

GENSOURCES = \
	UserInterfaceTif.java \
	UserInterfaceTool.java \
	UserInterfaceBridge.java

java_JAVA = \
	${ACSOURCES} \
	${GENSOURCES} \
	ExtensionFilter.java \
	GraphPanel.java \
	GraphWrapper.java \
	ImportGraphPanel.java \
	ListListModel.java \
	MetaStudio.java \
	Module.java \
	ModuleManager.java \
	ModuleSelectionListener.java \
	ModuleStatusPanel.java \
	NodeSizer.java \
	ParseTreePanel.java \
	Preferences.java \
	UserInterfaceBridge.java \
	UserInterfaceTif.java \
	UserInterfaceTool.java
