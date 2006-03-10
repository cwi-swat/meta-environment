# $Id$

include $(top_srcdir)/make_rules

INCLUDES			= -I$(top_srcdir)/libsglr \
				-I$(ATERM)/include \
				-I$(TOOLBUSLIB)/include \
				-I$(ERROR_SUPPORT)/include \
				-I${PT_SUPPORT}/include

bin_PROGRAMS			= dump-actions dump-gotos dump-priorities \
				dump-productions

dump_actions_SOURCES		= dump-actions.c dump-skel.c dump-skel.h

dump_gotos_SOURCES		= dump-gotos.c dump-skel.c dump-skel.h

dump_priorities_SOURCES		= dump-priorities.c dump-skel.c dump-skel.h

dump_productions_SOURCES	= dump-productions.c dump-skel.c dump-skel.h

if MAINTAINER_MODE
ATERM_LIB = ATerm-dbg
else
ATERM_LIB = ATerm
endif

LDADD     = -L$(top_builddir)/libsglr -lsglr \
            -L$(PT_SUPPORT)/lib -lmept \
            -L$(TOOLBUSLIB)/lib -lATB \
            -L$(ERROR_SUPPORT)/lib -lErrorAPI \
            -L$(ATERM)/lib -l$(ATERM_LIB) \
            $(SOCKLIBS)
