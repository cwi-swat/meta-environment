lib_LIBRARIES = libGraph.a
include_HEADERS = Graph.h Graph_dict.h
noinst_HEADERS = Graph.h Graph_dict.h

bin_PROGRAMS = dot-adapter
pkgdata_DATA = dot-adapter.idef Graph.adt

EXTRA_DIST = dot-adapter.idef dot.l dot.y

CLEANFILES = lex.yy.c y.tab.c y.tab.h

YFLAGS = -d

INCLUDES = \
	-DDOT_COMMAND=\"${DOT}/bin/dot\" \
	-I${ATERM}/include \
	-I${top_srcdir}/aterm \
	-I${TOOLBUSLIB}/include

dot_adapter_SOURCES = dot-adapter.c dot-adapter.tif.c dot-adapter.tif.h
dot_adapter_LDADD = \
	lex.yy.o y.tab.o \
	-L${top_builddir}/adapters/dot-adapter -lGraph \
	-L${TOOLBUSLIB}/lib -lATB \
	-L$(ATERM)/lib -lATerm

#	/export/scratch1/olivierp/efence/libefence.a

libGraph_a_SOURCES = Graph.c Graph_dict.c

api: graph-api

graph-api: Graph.adt
	adt-to-c -i $<

y.tab.c y.tab.h: dot.y
	$(YACC) -v $(AM_YFLAGS) $(YFLAGS) $<

lex.yy.c : dot.l y.tab.h
	$(LEX) $(AM_LFLAGS) $(LFLAGS) $<

%.tif.c %.tif.h: %.tifs
	$(top_builddir)/aterm/tifstoc -tool $* $<

%.tifs: %.idef
	${top_builddir}/toolbus/idef2tif $<


