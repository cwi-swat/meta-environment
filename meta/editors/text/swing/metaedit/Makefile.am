include ${top_srcdir}/make_rules

SUBDIRS = images util style action toolbus

EXTRA_DIST = ${java_JAVA}

TEXTEDITORAPI = $(shell ${top_builddir}/editors/text/common/texteditorapi-config.local)
METACONFIGAPI = $(shell ${top_builddir}/configuration-manager/src/metaconfig-config.local)

CLASSPATH_ENV = CLASSPATH=${JAVAROOT}:${top_srcdir}/editors/text/swing:${EXTERNAL_JARS}:${TEXTEDITORAPI}:${METACONFIGAPI}

JAVAROOT = ${top_builddir}/editors/text/swing
javadir = ${prefix}/classes/metaedit

java_JAVA = \
	    Controller.java \
	    EditorModel.java \
	    Main.java \
	    SwingEditor.java
