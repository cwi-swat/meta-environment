EXTRA_DIST = ${java_JAVA}

METACONFIGAPI = $(shell ${top_builddir}/configuration-manager/src/metaconfig-config.local)

CLASSPATH_ENV = CLASSPATH=${JAVAROOT}:${top_srcdir}/editors/text/swing:${EXTERNAL_JARS}:${METACONFIGAPI}

JAVAROOT = ${top_builddir}/editors/text/swing
javadir = ${prefix}/classes/metaedit/style

java_JAVA = \
	    EditorStyle.java \
	    Focuser.java \
	    NormalStyle.java
