
bin_PROGRAMS = layoutgraph graph2dot
pkgdata_DATA = layoutgraph.idef 

EXTRA_DIST = layoutgraph.idef dot.l dot.y

CLEANFILES = lex.yy.c y.tab.c y.tab.h y.output

YFLAGS = -d

INCLUDES = \
	-DDOT_COMMAND=\"${GRAPHVIZ}/bin/dot\" \
	-I${ATERM}/include \
        -I${top_srcdir}/lib \
	-I${TOOLBUSLIB}/include

noinst_HEADERS = dot.h graph2dot.h layoutgraph.h
layoutgraph_SOURCES = layoutgraph.c layoutgraph.tif.c layoutgraph.tif.h \
                      graph2dot.c layoutgraph-main.c

layoutgraph_LDADD = \
	lex.yy.o y.tab.o \
	-L${TOOLBUSLIB}/lib -lATB \
	-L$(ATERM)/lib -lATerm \
	-L${top_builddir}/lib -lGraph \
        ${SOCKLIBS}

graph2dot_SOURCES = graph2dot.c graph2dot-main.c
graph2dot_LDADD = -L${top_builddir}/lib -lGraph \
                  -L${ATERM}/lib -lATerm

y.tab.c y.tab.h: dot.y
	$(YACC) -v $(AM_YFLAGS) $(YFLAGS) $<

lex.yy.c : dot.l y.tab.h
	$(LEX) $(AM_LFLAGS) $(LFLAGS) $<

IDEF=idef2tif
TIFS=tifstoc

tif:
	for i in `ls *.idef`; do \
          ${IDEF} $$i; \
          ${TIFS} -tool `basename $$i .idef` `basename $$i .idef`.tifs; \
        done

tif-clean:
	rm -f *.tifs *.tif.[ch]
