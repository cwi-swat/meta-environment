# $Id$

include ${top_srcdir}/make_rules

EXTRA_DIST = tree2graph.idef

bin_PROGRAMS = tree2graph

INCLUDES = \
  -I${top_srcdir}/lib \
  -I${PT_SUPPORT}/include \
  -I${ATERM}/include \
  -I${TOOLBUSLIB}/include

pkgdata_DATA = tree2graph.idef

noinst_HEADERS = tree2graph.tif.h PT2graph.h

tree2graph_SOURCES = PT2graph.c tree2graph.tif.c tree2graph-main.c
tree2graph_LDADD = \
   -L${top_builddir}/lib/ -lGraph \
   -L${PT_SUPPORT}/lib -lmept \
   -L${TOOLBUSLIB}/lib -lATB \
   -L${ATERM}/lib -lATerm \
   ${SOCKLIBS}
