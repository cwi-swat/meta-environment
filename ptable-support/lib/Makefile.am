# $Id$

lib_LIBRARIES           = libptable.a
include_HEADERS         = ptable.h ptable-utils.h
libptable_a_SOURCES 	= ptable.c ptable-utils.c ptable_dict.c

noinst_HEADERS = ptable_dict.h

CFLAGS += -DDISABLE_DYNAMIC_CHECKING                          
INCLUDES = -I${ATERM}/include -I${PT_SUPPORT}/include

EXTRA_DIST = ptable.adt


# Developers only, put location of ADT-support here:
ADT      = ${prefix}
NAME     = ptable
PREFIX   = PTA_

api: ${NAME}.adt ${NAME}.pro
	adt-to-c --compat-term -i ${NAME}.adt --prefix ${PREFIX} -o ${NAME} \
                 --prologue ${NAME}.pro
