
CLASSPATH_ENV	= CLASSPATH=${JAVAROOT}:${EXTERNAL_JARS}
javadir		= ${prefix}/classes/tide/tool/support
JAVAROOT	= ${top_builddir}

TOOL_GEN	= DebugToolTif.java DebugToolTool.java DebugToolBridge.java

JAVA		= Port.java Expr.java DebugTool.java DebugToolListener.java \
		DebugAdapter.java DebugAdapterListener.java \
		DebugProcess.java Info.java ProcessStatusChangeListener.java \
		Rule.java ProcessStatus.java DebugProcessListener.java \
		ExprFormat.java VarFormat.java

# This is some kind of hack to make sure that generated Java files are
# generated before compiling all other java files but that it will
# not be included in the distribution nor that it will be generated
# during a make dist.
noinst_SCRIPTS = ${TOOL_GEN}

java_JAVA	= ${TOOL_GEN} ${JAVA}

${TOOL_GEN}: ${top_builddir}/toolbus/tide.tifs
	${TOOLBUS}/bin/tifstojava \
		-tifs ${top_builddir}/toolbus/tide.tifs \
		-tool debug-tool \
		-package tide.tool.support

#ADT	= ${top_srcdir}/lib-c/TA.adt
#regen:
#	adt-to-java -i ${ADT} -o ${JAVAROOT} -p tide.tool.support -v
