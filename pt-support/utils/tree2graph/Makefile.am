# $Id$

lib_LIBRARIES = libGraph.a
include_HEADERS = Graph.h Graph_dict.h PT2graph.h

EXTRA_DIST = tree2graph.idef

bin_PROGRAMS = tree2graph

INCLUDES = \
  -I${top_srcdir}/libmept \
  -I${top_srcdir}/libasfix2 \
  -I${top_srcdir}/libconversion \
  -I${top_srcdir}/libptmept \
  -I${ATERM}/include \
  -I${TOOLBUSLIB}/include

pkgdata_DATA = tree2graph.idef

noinst_HEADERS = tree2graph.tif.h Graph.h Graph_dict.h

tree2graph_SOURCES = PT2graph.c tree2graph.tif.c tree2graph-main.c
tree2graph_LDADD = \
   -L${top_builddir}/libmept -lmept \
   -L${top_builddir}/utils/tree2graph -lGraph \
   -L${TOOLBUSLIB}/lib -lATB \
   -L${ATERM}/lib -lATerm \
   ${SOCKLIBS}

libGraph_a_SOURCES = Graph.c Graph_dict.c

IDEF=${TOOLBUS}/bin/idef2tif
TIFS=${TOOLBUS}/bin/tifstoc

tif:
	for i in `ls *.idef`; do \
	  ${IDEF} $$i; \
	  ${TIFS} -tool `basename $$i .idef` `basename $$i .idef`.tifs; \
	done

tif-clean:
	rm -f *.tifs *.tif.[ch]
