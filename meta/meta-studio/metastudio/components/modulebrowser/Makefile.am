include ${top_srcdir}/make_rules

pkgdata_DATA = modulebrowser.idef
EXTRA_DIST = ${java_JAVA} modulebrowser.idef

CLASSPATH_ENV = CLASSPATH=${JAVAROOT}:${top_srcdir}/meta-studio:${EXTERNAL_JARS}

JAVAROOT = ${top_builddir}/meta-studio
javadir = ${prefix}/classes/metastudio

jtif: 
	${IDEF} modulebrowser.idef
	${TOOLBUS}/bin/tifstojava -tool module-browser -tifs modulebrowser.tifs \
		-package metastudio.components.modulebrowser -swing

java_JAVA = \
	ModuleBrowser.java \
	ModuleBrowserBridge.java \
	ModuleBrowserTool.java \
	ModuleBrowserTif.java \
	ModuleInfoPanel.java \
	ModulePopupMenu.java \
	ModuleSelectionListener.java \
	ModuleTree.java
