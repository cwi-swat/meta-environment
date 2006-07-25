# $Id$

include $(top_srcdir)/Makefile.meta

INCLUDES			= -I$(top_srcdir)/libsglr \
				$(ATERM_CFLAGS) \
				$(TOOLBUSLIB_CFLAGS) \
				$(ERROR_SUPPORT_CFLAGS) \
				${PT_SUPPORT_CFLAGS}

bin_PROGRAMS			= dump-actions dump-gotos dump-priorities \
				dump-productions

dump_actions_SOURCES		= dump-actions.c dump-skel.c dump-skel.h

dump_gotos_SOURCES		= dump-gotos.c dump-skel.c dump-skel.h

dump_priorities_SOURCES		= dump-priorities.c dump-skel.c dump-skel.h

dump_productions_SOURCES	= dump-productions.c dump-skel.c dump-skel.h

LDADD     = -L$(top_builddir)/libsglr -lsglr \
            $(PT_SUPPORT_LIBS) \
            $(TOOLBUSLIB_LIBS) \
            $(ERROR_SUPPORT_LIBS) \
            $(ATERM_LIBS) 
