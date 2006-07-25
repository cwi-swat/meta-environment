# $Id$

include $(top_srcdir)/Makefile.meta

SUBDIRS=snapshot


EXTRA_DIST = term-store.idef.src
pkgdata_DATA = term-store.idef

bin_PROGRAMS = term-store

term_store_SOURCES = \
	main.c \
	term-store.tif.c \
	table.c \
	table-store.c

term_store_LDADD = \
                   -L./snapshot -lsnapshot \
                   $(TOOLBUSLIB_LIBS) \
                   $(ATERM_LIBS) 

noinst_HEADERS		= table.h table-store.h term-store.tif.h

INCLUDES	        = $(ATERM_CFLAGS) \
                          $(TOOLBUSLIB_CFLAGS) \
			  -I$(srcdir)/snapshot

CLEANFILES = term-store.idef

%.idef: %.idef.src Makefile
	sed 's@__PREFIX__@${prefix}@g' < $< > $@
