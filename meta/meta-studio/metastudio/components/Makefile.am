include ${top_srcdir}/make_rules

SUBDIRS = \
	graphs \
	statusbar \
	menubar \
	toolbar \
	statushistory \
	errorlist \
	infolist \
	dialogtool \
	graphnodesizer \
	treebrowser \
	modulebrowser \
	.

CLASSPATH_ENV = CLASSPATH=${JAVAROOT}:${top_srcdir}/meta-studio:${EXTERNAL_JARS}

JAVAROOT = ${top_builddir}/meta-studio
javadir = ${prefix}/classes/metastudio

EXTRA_DIST = ${java_JAVA}

java_JAVA = \
	TideControl.java 
