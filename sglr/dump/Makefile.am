# $Id$

include $(top_srcdir)/make_rules

INCLUDES			= -I$(top_srcdir)/libsglr \
				-I$(ATERM)/include \
				-I${PT_SUPPORT}/include

bin_PROGRAMS			= dump-actions dump-gotos dump-priorities \
				dump-productions

dump_actions_SOURCES		= dump-actions.c dump-skel.c dump-skel.h

dump_gotos_SOURCES		= dump-gotos.c dump-skel.c dump-skel.h

dump_priorities_SOURCES		= dump-priorities.c dump-skel.c dump-skel.h

dump_productions_SOURCES	= dump-productions.c dump-skel.c dump-skel.h


LDADD     = -L$(top_srcdir)/libsglr -lsglr \
            -L$(top_srcdir)/libtree2dot -ltree2dot \
            -L$(PT_SUPPORT)/lib -lconversion -lmept -lasfix2 \
            -L$(ATERM)/lib -lATerm -lATB $(SOCKLIBS)

