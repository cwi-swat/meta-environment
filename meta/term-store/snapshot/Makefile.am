# $Id$

noinst_LIBRARIES  = libsnapshot.a
noinst_HEADERS    = Snapshot.h
libsnapshot_a_SOURCES = Snapshot.c Snapshot_dict.c 
                          
CFLAGS			+= -DDISABLE_DYNAMIC_CHECKING
INCLUDES                = -I${ATERM}/include

api: 
	adt-to-c -i Snapshot.adt --prefix SS_ -o Snapshot

api-clean:
	${RM} Snapshot.[ch] Snapshot_dict.[ch] Snapshot.dict
