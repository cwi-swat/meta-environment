# $Id$

lib_LIBRARIES           = libptable.a
include_HEADERS         = ptable.h ptable-utils.h
libptable_a_SOURCES 	= ptable.c ptable-utils.c

CFLAGS += -DDISABLE_DYNAMIC_CHECKING                          
INCLUDES                = -I${ATERM}/include -I${PT_SUPPORT}/include


# Developers only, put location of ADT-support here:
ADT      = ${prefix}
NAME     = ptable
PREFIX   = PTA_

api: ${NAME}.c

${NAME}.c: ${NAME}.adt ${NAME}.pro
	adt-to-c --compat-term -i ${NAME}.adt --prefix ${PREFIX} -o ${NAME} \
                 --prologue ${NAME}.pro

clean:
	${RM} ${CLEANFILES} *.o ${NAME}.[ch] ${NAME}_dict.[ch] \
              ${NAME}.dict
