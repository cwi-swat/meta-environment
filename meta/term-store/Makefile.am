# $Id$

SUBDIRS=snapshot

include $(top_srcdir)/make_rules

EXTRA_DIST = term-store.idef
pkgdata_DATA = term-store.idef

bin_PROGRAMS = term-store

term_store_SOURCES = main.c term-store.tif.c
term_store_LDADD = -L$(ATERM)/lib -lATerm \
                   -L$(TOOLBUSLIB)/lib -lATB \
                   -L. -ltables \
                   -L./snapshot -lsnapshot
		   $(SOCKLIBS)

noinst_LIBRARIES	= libtables.a

noinst_HEADERS		= table.h table-store.h term-store.tif.h

libtables_a_SOURCES	= table.c table-store.c 

INCLUDES	        = -I$(ATERM)/include \
                          -I$(TOOLBUSLIB)/include \
			  -I./snapshot
