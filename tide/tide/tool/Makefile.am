
SUBDIRS		= support proclist ruleinspector srcviewer .

javadir		= ${prefix}/classes/tide/tool
JAVAROOT	= ${top_builddir}

java_JAVA	= ${CONTROL_GEN} \
		TideControl.java ToolManager.java TideTool.java \
		AdapterToolFactory.java AdapterTool.java \
		ProcessToolFactory.java ProcessTool.java \
		AdapterAction.java ProcessAction.java


CONTROL_GEN	= TideControlTif.java TideControlTool.java \
		TideControlBridge.java 

JARCLASSES	= ${SUBDIRS:%=%/*.class}
JARIMAGES	= images/*.gif

JARFILES	= META-INF/MANIFEST.MF ${JARIMAGES} ${JARCLASSES}

# This is some kind of hack to make sure that generated Java files are
# generated before compiling all other java files but that it will
# not be included in the distribution nor that it will be generated
# during a make dist.
noinst_SCRIPTS	= ${CONTROL_GEN}

data_DATA	= tide.jar

${noinst_SCRIPTS}: ../../tide.tifs
	tifstojava -tifs ../../tide.tifs -tool tide-control -package tide.tool

%.class: %.java
	$(CLASSPATH_ENV) $(JAVAC) $(JAVACFLAGS) -d $(JAVAROOT) $<

tide.jar: ${JARFILES}
	jar cf tide.jar $^
	cp tide.jar ${datadir}

