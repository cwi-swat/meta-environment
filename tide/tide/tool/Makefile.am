
SUBDIRS				= support proclist ruleinspector

javadir				= ${prefix}/classes/tide/tool
JAVAROOT			= ${top_builddir}/..

java_JAVA			= ${CONTROL_GEN} \
					TideControl.java ToolManager.java \
					AdapterToolFactory.java AdapterTool.java \
					ProcessToolFactory.java ProcessTool.java \
					AdapterAction.java ProcessAction.java


CONTROL_GEN			= TideControlTif.java TideControlTool.java \
					TideControlBridge.java 

# This is some kind of hack to make sure that generated Java files are
# generated before compiling all other java files but that it will
# not be included in the distribution nor that it will be generated
# during a make dist.
noinst_SCRIPTS = ${CONTROL_GEN}


${noinst_SCRIPTS}: ../tide.tifs
	tifstojava -tifs ../tide.tifs -tool tide-control -package tide.tool

%.class: %.java
	$(CLASSPATH_ENV) $(JAVAC) $(JAVACFLAGS) -d $(JAVAROOT) $<

