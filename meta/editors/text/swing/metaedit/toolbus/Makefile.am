include ${top_srcdir}/make_rules

EXTRA_DIST = ${java_JAVA}

CLASSPATH_ENV = CLASSPATH=${JAVAROOT}:${top_srcdir}/editors/text/swing:${EXTERNAL_JARS}

JAVAROOT = ${top_builddir}/editors/text/swing
javadir = ${prefix}/classes/metaedit/toolbus

jtif:
	${IDEF} editor-swing.idef
	${TOOLBUS}/bin/tifstojava \
		-tool swing-editor \
		-tifs editor-swing.tifs \
                -package metaedit.toolbus \
		-swing

java_JAVA = \
	    SwingEditorBridge.java \
	    SwingEditorTif.java \
	    SwingEditorTool.java
