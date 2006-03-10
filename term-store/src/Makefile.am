# $Id$

SUBDIRS=snapshot

include $(top_srcdir)/make_rules

EXTRA_DIST = term-store.idef.src
pkgdata_DATA = term-store.idef

bin_PROGRAMS = term-store

if MAINTAINER_MODE
ATERM_LIB = ATerm-dbg
else
ATERM_LIB = ATerm
endif

term_store_SOURCES = \
	main.c \
	term-store.tif.c \
	table.c \
	table-store.c

term_store_LDADD = \
                   -L./snapshot -lsnapshot \
                   -L$(TOOLBUSLIB)/lib -lATB \
                   -L$(ATERM)/lib -l$(ATERM_LIB) \
		   $(SOCKLIBS)

noinst_HEADERS		= table.h table-store.h term-store.tif.h

INCLUDES	        = -I$(ATERM)/include \
                          -I$(TOOLBUSLIB)/include \
			  -I$(srcdir)/snapshot

CLEANFILES = term-store.idef

%.idef: %.idef.src Makefile
	sed 's@__PREFIX__@${prefix}@g' < $< > $@
