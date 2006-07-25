# $Id$

include ${top_srcdir}/Makefile.meta

EXTRA_DIST = graph-converter.idef.src

CLEANFILES = graph-converter.idef

bin_PROGRAMS = tree2graph

INCLUDES = \
  -I${top_srcdir}/lib \
  ${PT_SUPPORT_CFLAGS} \
  ${ERROR_SUPPORT_CFLAGS} \
  ${ATERM_CFLAGS} \
  ${TOOLBUSLIB_CFLAGS}

pkgdata_DATA = graph-converter.idef

noinst_HEADERS = \
	graph-converter.tif.h \
	PT2graph.h

tree2graph_SOURCES = \
	PT2graph.c \
	graph-converter.tif.c \
	tree2graph-main.c

tree2graph_LDADD = \
   -L${top_builddir}/lib/ -lGraph \
   $(PT_SUPPORT_LIBS) \
   $(TOOLBUSLIB_LIBS) \
   $(ERROR_SUPPORT_LIBS) \
   $(ERROR_SUPPORT_LIBS) \
   $(ATERM_LIBS) \
   ${SOCKLIBS}

%.idef: %.idef.src Makefile
	sed 's@__PREFIX__@${prefix}@g' < $< > $@
