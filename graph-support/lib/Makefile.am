
lib_LIBRARIES = libGraph.a
include_HEADERS = Graph.h Graph_dict.h
noinst_HEADERS = Graph.h Graph_dict.h
pkgdata_DATA = Graph.adt
data_DATA = ${JARFILE}

EXTRA_DIST = Graph.adt

libGraph_a_SOURCES = Graph.c Graph_dict.c

INCLUDES = -I${ATERM}/include 
JARFILE = ${top_srcdir}/lib/graph-${VERSION}.jar

c-api: Graph.adt
	upgrade-adt -i $< -o $<.upgraded
	adt-to-c --input $<.upgraded --output Graph
	rm -f $<.upgraded

java-api: Graph.adt
	adt-to-java \
		--input Graph.adt \
		--package nl.cwi.sen.api.graph \
		--name graph \
		--import 'aterm.*' \
		--version ${VERSION}
