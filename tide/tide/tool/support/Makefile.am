
CLASSPATH_ENV	= CLASSPATH=${JAVAROOT}:${EXTERNAL_JARS}
javadir		= ${prefix}/classes/tide/tool/support
JAVAROOT	= ${top_builddir}

TOOL_GEN	= DebugToolTif.java DebugToolTool.java DebugToolBridge.java

JAVA		= Port.java Expr.java DebugTool.java DebugToolListener.java \
		DebugAdapter.java DebugAdapterListener.java \
		DebugProcess.java Info.java ProcessStatusChangeListener.java \
		Rule.java ProcessStatus.java DebugProcessListener.java \
		ExprFormat.java VarFormat.java

java_JAVA	= ${TOOL_GEN} ${JAVA}

EXTRA_DIST = ${java_JAVA}

tifs: 
	tifstojava \
		-tifs ${top_srcdir}/toolbus/tide.tifs \
		-tool debug-tool \
		-package tide.tool.support \
		-swing
