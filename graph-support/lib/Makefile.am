
lib_LIBRARIES = libGraph.a
include_HEADERS = Graph.h Graph_dict.h
noinst_HEADERS = Graph.h Graph_dict.h

EXTRA_DIST = Graph.adt
pkgdata_DATA = Graph.adt

INCLUDES = -I${ATERM}/include 

libGraph_a_SOURCES = Graph.c Graph_dict.c

api: Graph.adt
	adt-to-c -i $<
