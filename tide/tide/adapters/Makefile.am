SUBDIRS		= gdb

CLASSPATH_ENV	= CLASSPATH=${top_builddir}:${top_srcdir}:${JAVAROOT}:${EXTERNAL_JARS}

javadir		= ${prefix}/classes/tide
JAVAROOT	= ${top_builddir}

ADAPTER_GEN = \
	DebugAdapterTif.java \
	DebugAdapterTool.java \
	DebugAdapterBridge.java
	
java_JAVA = \
	${ADAPTER_GEN} \
	DebugAdapterProcess.java \
	DebugAdapterRule.java \
	DebugAdapter.java
	 

EXTRA_DIST	= ${java_JAVA}

tifs:
	tifstojava \
		-tifs ${top_srcdir}/toolbus/tide.tifs \
		-tool debug-adapter \
		-package tide.adapters 
