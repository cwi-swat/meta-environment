# $Id$

include MetaGraphMakeRules.am

JAVAROOT = ${top_builddir}/meta-studio
javadir = ${prefix}/classes/metastudio/graph

CLASSPATH_ENV=CLASSPATH=${JAVAROOT}:${top_srcdir}/meta-studio:${EXTERNAL_JARS}

java_JAVA = ${MetaGraphAPI}

api:
	adt-to-java \
		--input ${GRAPH_SUPPORT}/share/graph-support/Graph.adt \
		--folding \
		--package metastudio.graph \
		--name MetaGraph \
		--verbose
	mv ${srcdir}/MetaGraphMakeRules ${srcdir}/MetaGraphMakeRules.am
