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

# This is some kind of hack to make sure that generated Java files are
# generated before compiling all other java files but that it will
# not be included in the distribution nor that it will be generated
# during a make dist.
noinst_SCRIPTS  = ${ADAPTER_GEN}

${ADAPTER_GEN}: ${top_srcdir}/toolbus/tide.tifs 
	${TOOLBUS}/bin/tifstojava \
		-tifs ${top_srcdir}/toolbus/tide.tifs \
		-tool debug-adapter \
		-package tide.adapters 
