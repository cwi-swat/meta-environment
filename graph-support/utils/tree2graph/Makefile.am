# $Id$

include ${top_srcdir}/make_rules

EXTRA_DIST = graph-converter.idef.src

CLEANFILES = graph-converter.idef

bin_PROGRAMS = tree2graph

INCLUDES = \
  -I${top_srcdir}/lib \
  -I${PT_SUPPORT}/include \
  -I${ERROR_SUPPORT}/include \
  -I${ATERM}/include \
  -I${TOOLBUSLIB}/include

pkgdata_DATA = graph-converter.idef

noinst_HEADERS = \
	graph-converter.tif.h \
	PT2graph.h

if MAINTAINER_MODE
ATERM_LIB = ATerm-dbg
else
ATERM_LIB = ATerm
endif

tree2graph_SOURCES = \
	PT2graph.c \
	graph-converter.tif.c \
	tree2graph-main.c

tree2graph_LDADD = \
   -L${top_builddir}/lib/ -lGraph \
   -L${PT_SUPPORT}/lib -lmept \
   -L${TOOLBUSLIB}/lib -lATB \
   -L$(ERROR_SUPPORT)/lib -lLocationAPI \
   -L$(ERROR_SUPPORT)/lib -lErrorAPI \
   -L${ATERM}/lib -l$(ATERM_LIB) \
   ${SOCKLIBS}

%.idef: %.idef.src Makefile
	sed 's@__PREFIX__@${prefix}@g' < $< > $@
