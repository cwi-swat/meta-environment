SUBDIRS		= tool .

CLASSPATH_ENV	= CLASSPATH=${JAVAROOT}:${EXTERNAL_JARS}

javadir		= ${prefix}/classes/tide
JAVAROOT	= ${top_builddir}

java_JAVA	= ${GENJAVA} \
		TideMainFrame.java TideControl.java PreferenceSet.java PreferenceListener.java

GENJAVA		= TideConfig.java ${CONTROL_GEN}

CONTROL_GEN     = TideControlTif.java TideControlTool.java \
		TideControlBridge.java

EXTRA_DIST	= TideConfig.java.src ${java_JAVA}
CLEANFILES 	= TideConfig.java

# This is some kind of hack to make sure that generated Java files are
# generated before compiling all other java files but that it will
# not be included in the distribution nor that it will be generated
# during a make dist.
noinst_SCRIPTS  = ${GENJAVA}

%.java : %.java.src Makefile
	sed 's@__DATADIR__@$(datadir)@g;\
            ' < $< > $@

${CONTROL_GEN}: ${top_builddir}/toolbus/tide.tifs
	${TOOLBUS}/bin/tifstojava \
		-tifs ${top_builddir}/toolbus/tide.tifs \
		-tool tide-control \
		-package tide \
		-swing

#%.class: %.java
#	$(CLASSPATH_ENV) $(JAVAC) $(JAVACFLAGS) -d $(JAVAROOT) $<

