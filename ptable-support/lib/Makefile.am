# $Id$

lib_LIBRARIES           = libptable.a
include_HEADERS         = ptable.h ptable-utils.h ptable_dict.h
libptable_a_SOURCES 	= ptable.c ptable-utils.c ptable_dict.c

#CFLAGS += -DDISABLE_DYNAMIC_CHECKING                          
INCLUDES = -I${ATERM}/include -I${PT_SUPPORT}/include

EXTRA_DIST = ptable.adt


# Developers only, put location of ADT-support here:
ADT      = ${prefix}
NAME     = ptable
PREFIX   = PTBL_

api: ${NAME}.adt 
	adt-to-c \
		-i ${NAME}.adt \
		--name ${NAME} \
		--prefix ${PREFIX} 

