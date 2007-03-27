# $Id$

include $(top_srcdir)/Makefile.meta

bin_PROGRAMS = tree2graph

INCLUDES = \
  -I$(top_srcdir)/lib \
  ${PT_SUPPORT_CFLAGS} \
  ${ERROR_SUPPORT_CFLAGS} \
  ${ATERM_CFLAGS} \
  ${TOOLBUSLIB_CFLAGS}

pkgdata_DATA = graph-converter.idef

noinst_HEADERS = \
	PT2graph.h

tree2graph_SOURCES = \
	PT2graph.c \
	graph-converter.idef \
	tree2graph-main.c

tree2graph_LDADD = \
   -L${top_builddir}/lib/ -lGraph \
   $(PT_SUPPORT_LIBS) \
   $(TOOLBUSLIB_LIBS) \
   $(ERROR_SUPPORT_LIBS) \
   $(ERROR_SUPPORT_LIBS) \
   $(ATERM_LIBS) \
   ${SOCKLIBS}

