include ${top_srcdir}/make_rules

SUBDIRS = graph

EXTRA_DIST = ${java_JAVA}

CLASSPATH_ENV = CLASSPATH=${JAVAROOT}:${top_srcdir}/meta-studio:${EXTERNAL_JARS}

JAVAROOT = ${top_builddir}/meta-studio
javadir = ${prefix}/classes/metastudio

java_JAVA = \
	AbstractModuleTreeModel.java \
	FeedbackItem.java \
	FeedbackListModel.java \
	FeedbackSummaryIdentifier.java \
	ListModel.java \
	Module.java \
	ModuleSelectionModel.java \
	ModuleTreeModel.java \
	ModuleTreeNode.java
