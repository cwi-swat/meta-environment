# $Id$

include $(top_srcdir)/Makefile.meta

EXTRA_DIST = term-store.idef.src
pkgdata_DATA = term-store.idef

bin_PROGRAMS = term-store

AM_CPPFLAGS = -DDISABLE_DYNAMIC_CHECKING

term_store_SOURCES = \
	main.c \
	term-store.tif.c \
	table.c \
	table-store.c \
	Snapshot.c \
	Snapshot_dict.c 

term_store_LDADD = \
                   $(TOOLBUSLIB_LIBS) \
                   $(ATERM_LIBS) 

noinst_HEADERS=\
	table.h \
	table-store.h \
	term-store.tif.h \
	Snapshot.h \
	Snapshot_dict.h

INCLUDES	        = $(ATERM_CFLAGS) \
                          $(TOOLBUSLIB_CFLAGS) \
			  -I$(srcdir)/snapshot

CLEANFILES += term-store.idef

%.idef: %.idef.src Makefile
	sed 's@__PREFIX__@${prefix}@g' < $< > $@

if MAINTAINER_MODE 
                          
api: 
	adt-to-c \
		--input Snapshot.adt \
		--name Snapshot \
		--prefix SS_

api-clean:
	${RM} Snapshot.[ch] Snapshot_dict.[ch] Snapshot.dict

endif
