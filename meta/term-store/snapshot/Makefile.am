# $Id$

noinst_LIBRARIES = libsnapshot.a

noinst_HEADERS = \
	Snapshot.h \
	Snapshot_dict.h

libsnapshot_a_SOURCES = \
	Snapshot.c \
	Snapshot_dict.c 
                          
AM_CFLAGS = -DDISABLE_DYNAMIC_CHECKING
INCLUDES = -I${ATERM}/include

api: 
	adt-to-c \
		--input Snapshot.adt \
		--name Snapshot \
		--prefix SS_

api-clean:
	${RM} Snapshot.[ch] Snapshot_dict.[ch] Snapshot.dict
