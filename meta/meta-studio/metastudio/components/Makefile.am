include ${top_srcdir}/make_rules

SUBDIRS = graphs statusbar errorlist infolist filedialog .

CLASSPATH_ENV = CLASSPATH=${JAVAROOT}:${top_srcdir}/meta-studio:${EXTERNAL_JARS}

JAVAROOT = ${top_builddir}/meta-studio
javadir = ${prefix}/classes/metastudio

EXTRA_DIST = ${java_JAVA}

java_JAVA = \
	HistoryPanel.java \
	MainTabs.java \
	MenuBar.java \
	MessageTabs.java \
	ModuleBrowser.java \
	ModuleInfoPanel.java \
	ModulePopupMenu.java \
	ModuleSelectionListener.java \
	ModuleTree.java \
	ParseTreeBrowser.java \
	ToolBar.java \
	TideControl.java 
