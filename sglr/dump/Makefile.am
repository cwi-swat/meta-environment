# $Id$

include ../make_rules

bin_PROGRAMS             = dump-actions dump-gotos dump-priorities \
                           dump-productions

dump_actions_SOURCES     = dump-actions.c dump-skel.c dump-skel.h

dump_gotos_SOURCES       = dump-gotos.c dump-skel.c dump-skel.h

dump_priorities_SOURCES  = dump-priorities.c dump-skel.c dump-skel.h

dump_productions_SOURCES = dump-productions.c dump-skel.c dump-skel.h


LDADD     = -L${top_builddir}/libsglr -lsglr \
            -L${top_builddir}/libtree2dot -ltree2dot \
            -L${top_builddir}/liba2toa1 -la2toa1 \
            -L$(ATERMLIB) -lATerm-${CC} -lAsFix-${CC} -lATB-${CC} \
            $(SOCKLIBS)

test: all
	for prg in ${bin_PROGRAMS}; \
	do \
		${top_srcdir}/test-help ./$$prg; \
	done
