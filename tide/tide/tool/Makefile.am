
SUBDIRS		= support proclist ruleinspector srcviewer prefeditor

javadir		= ${prefix}/classes/tide/tool
JAVAROOT	= ${top_builddir}

java_JAVA	= ToolManager.java TideToolFactory.java TideTool.java \
		AdapterToolFactory.java AdapterTool.java \
		ProcessToolFactory.java ProcessTool.java \
		AdapterAction.java ProcessAction.java \
		TideDialog.java

%.class: %.java
	$(CLASSPATH_ENV) $(JAVAC) $(JAVACFLAGS) -d $(JAVAROOT) $<

