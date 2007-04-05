
include $(top_srcdir)/Makefile.meta

bin_PROGRAMS = layoutgraph graph2dot
pkgdata_DATA = layoutgraph.idef 

EXTRA_DIST += dot.l dot.y

CLEANFILES += lex.yy.c y.tab.c y.tab.h y.output

YFLAGS = -d

INCLUDES = \
	-DDOT_COMMAND=\"${GRAPHVIZ_PREFIX}/bin/dot\" \
        -I$(top_srcdir)/lib \
	${ATERM_CFLAGS} \
	${TOOLBUSLIB_CFLAGS}

noinst_HEADERS = dot.h graph2dot.h layoutgraph.h layout.h

layoutgraph_SOURCES = \
	layout.c \
	layoutgraph.isrc \
	graph2dot.c \
	layoutgraph-main.c

layoutgraph_LDADD = \
	lex.yy.o y.tab.o \
	-L${top_builddir}/lib -lGraph \
	$(ATERM_LIBS) \
	$(TOOLBUSLIB_LIBS) 

graph2dot_SOURCES = \
	graph2dot.c \
	graph2dot-main.c

graph2dot_LDADD = \
	-L${top_builddir}/lib -lGraph \
	$(ATERM_LIBS) 

y.tab.c y.tab.h: dot.y
	$(YACC) -v $(AM_YFLAGS) $(YFLAGS) $<

lex.yy.c : dot.l y.tab.h
	$(LEX) $(AM_LFLAGS) $(LFLAGS) $<

