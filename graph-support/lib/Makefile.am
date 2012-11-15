# $Id$

include $(top_srcdir)/Makefile.meta

lib_LTLIBRARIES = libGraph.la
include_HEADERS = Graph.h Graph_dict.h
noinst_HEADERS = Graph.h Graph_dict.h
pkgdata_DATA = Graph.adt graph.jar 
data_DATA = graph.jar
EXTRA_DIST += Graph.adt graph.jar

libGraph_la_SOURCES = Graph.c Graph_dict.c
libGraph_la_CPPFLAGS = $(ATERM_CFLAGS)
libGraph_la_LDFLAGS  = -avoid-version -no-undefined $(AM_LDFLAGS)
libGraph_la_LIBADD = $(ATERM_LIBS)

if MAINTAINER_MODE
api: c-api java-api

c-api: Graph.adt
	adt-to-c --input $< --name Graph

java-api: Graph.adt
	adt-to-java \
		--input Graph.adt \
		--package nl.cwi.sen1 \
		--name graph \
		--version ${VERSION}
	mv graph-${VERSION}.jar graph.jar
endif
