SUBDIRS		= tool .

CLASSPATH_ENV	= CLASSPATH=${JAVAROOT}:${EXTERNAL_JARS}

javadir		= ${prefix}/classes/tide
JAVAROOT	= ${top_builddir}

java_JAVA	= \
	${GENJAVA} \
	TideMainFrame.java \
	TideControl.java \
	PreferenceSet.java \
	PreferenceListener.java

GENJAVA		= ${CONTROL_GEN}

CONTROL_GEN     = \
	TideControlTif.java \
	TideControlTool.java \
	TideControlBridge.java

EXTRA_DIST	= ${java_JAVA}

tifs: 
	tifstojava \
		-tifs ${top_builddir}/toolbus/tide.tifs \
		-tool tide-control \
		-package tide \
		-swing

