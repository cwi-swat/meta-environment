# $Id: Makefile.am,v 1.15 2003/08/14 11:01:05 jurgenv Exp $

include MetaGraphMakeRules.am

EXTRA_DIST = MetaGraphMakeRules.am

JAVAROOT = ${top_builddir}/meta-studio
javadir = ${prefix}/classes/metastudio/graph

CLASSPATH_ENV=CLASSPATH=${JAVAROOT}:${top_srcdir}/meta-studio:${EXTERNAL_JARS}

java_JAVA = ${MetaGraphAPI}

api:
	upgrade-adt \
		-i ${GRAPH_SUPPORT}/share/graph-support/Graph.adt \
		-o Graph.adt
	adt-to-java \
		--input Graph.adt \
		--folding \
		--package metastudio.graph \
		--name MetaGraph \
		--import 'aterm.*' \
		--verbose
	mv ${srcdir}/MetaGraphMakeRules ${srcdir}/MetaGraphMakeRules.am
