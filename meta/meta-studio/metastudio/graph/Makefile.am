
java_JAVA	= $(wildcard *.java)

JAVAROOT	= ${top_builddir}/meta-studio
javadir		= ${prefix}/classes/metastudio/graph

CLASSPATH_ENV	= CLASSPATH=${JAVAROOT}:${top_srcdir}/meta-studio:${JAVA_ATERM}:${SHARED_OBJECTS}

api:
	adt-to-java \
		--input ${TOOLBUS}/share/toolbus/Graph.adt \
		--folding \
		--package metastudio.graph \
		--name MetaGraph \
		--verbose
