# $Id$

include MetaGraphMakeRules.am

JAVAROOT = ${top_builddir}/meta-studio
javadir = ${prefix}/classes/metastudio/graph

CLASSPATH_ENV = \
	CLASSPATH=${JAVAROOT}:${top_srcdir}/meta-studio:${JJTRAVELER}:${JAVA_ATERM}:${SHARED_OBJECTS}

java_JAVA = ${MetaGraphAPI}

api:
	adt-to-java \
		--input ${TOOLBUS}/share/toolbus/Graph.adt \
		--folding \
		--package metastudio.graph \
		--name MetaGraph \
		--verbose
	mv ${srcdir}/MetaGraphMakeRules ${srcdir}/MetaGraphMakeRules.am
