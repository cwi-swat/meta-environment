# $Id$

lib_LIBRARIES = libGraph.a
include_HEADERS = Graph.h Graph_dict.h
noinst_HEADERS = Graph.h Graph_dict.h
pkgdata_DATA = Graph.adt
data_DATA = ${JARFILE}

EXTRA_DIST = Graph.adt graph-${VERSION}.jar

libGraph_a_SOURCES = Graph.c Graph_dict.c

JARFILE = ${top_srcdir}/lib/graph-${VERSION}.jar
INCLUDES = -I${ATERM}/include 

if MAINTAINER_MODE
c-api: Graph.adt
	adt-to-c --input $< --name Graph

java-api: Graph.adt
	adt-to-java \
		--input Graph.adt \
		--package nl.cwi.sen1 \
		--name graph \
		--import 'aterm.*' \
		--version ${VERSION}
endif
