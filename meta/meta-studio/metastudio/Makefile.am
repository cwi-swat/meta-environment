
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

CLASSPATH_ENV	= CLASSPATH=${JAVAROOT}:${ATERM}/classes:${TOOLBUS}/classes


JAVAROOT	= ${top_builddir}/meta-studio
javadir		= ${prefix}/classes/metastudio

TYPES		= Module.ace

api: metastudio.ace ${TYPES}
	autocode \
		--application metastudio \
		--property "java->rootdir:=\"${JAVAROOT}\"" \
		metastudio.ace

${GENSOURCES}: meta-studio.tifs
	${TOOLBUS}/bin/tifstojava -tool user-interface -tifs $< \
		-package metastudio

%.tifs: %.idef
	$(TOOLBUS)/bin/idef2tif $<
	@if [ "a${VPATH}" != "a" ]; then \
		mv ${srcdir}/$@ $@ ;\
	fi
