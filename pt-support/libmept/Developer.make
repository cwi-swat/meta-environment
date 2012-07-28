#
# Developers.make
#
# This Makefile is used to generate the C library in this directory.
#

include ./Makefile

# Developers only, put location of ADT-support here:
ADT      = ${prefix}
NAME     = MEPT
PREFIX   = PT_

api: ${NAME}.c

${NAME}.c: ${NAME}.adt 
	adt-to-c --compat-term -i ${NAME}.adt --prefix ${PREFIX} -o ${NAME}

clean:
	${RM} ${CLEANFILES} *.o ${NAME}.[ch] ${NAME}_dict.[ch] \
              ${NAME}.dict
