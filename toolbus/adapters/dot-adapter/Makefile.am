lib_LIBRARIES = libGraph.a
include_HEADERS = Graph.h Graph_dict.h
noinst_HEADERS = Graph.h Graph_dict.h

bin_SCRIPTS = dot2term.pl term2dot2term
bin_PROGRAMS = term2dot
data_DATA = dot-adapter.idef

EXTRA_DIST = dot2term.pl.src term2dot2term.src dot-adapter.idef

CLEANFILES = dot2term.pl term2dot2term

INCLUDES = \
	-I${ATERM}/include \
	-I${top_srcdir}/aterm \
	-I${TOOLBUSLIB}/include

term2dot_SOURCES = term2dot.c
term2dot_LDADD = \
	-L${top_builddir}/adapters/dot-adapter -lGraph \
	-L${TOOLBUSLIB}/lib -lATB \
	-L$(ATERM)/lib -lATerm

libGraph_a_SOURCES = Graph.c Graph_dict.c

api: graph-api

graph-api: Graph.adt
	adt-to-c -i $<

term2dot2term: term2dot2term.src
	sed 's#__BINDIR__#${bindir}#g;s#__DOT__#${DOT}#g;' < $< > $@ \
	&& chmod +x $@

dot2term.pl: dot2term.pl.src
	sed 's#__PERL__#$(PERL)#g;s#__DOT__#$(DOT)#g;' < $< > $@ \
	&& chmod +x $@
