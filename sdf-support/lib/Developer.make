#
# Developers.make
#
# This Makefile is used to generate the C library in this directory.
#

include ./Makefile

# Developers only, put location of ADT-support here:
ADT      = ${prefix}
NAME     = SDFME
PREFIX   = SDF_
SOURCE   = Sdf.label.def

api: ${NAME}.adt

${NAME}.adt: ${SOURCE}
	sdf2-to-adt -2 -r -i $< -o ${NAME}.adt

${NAME}.c: ${NAME}.adt ${NAME}.pro
	adt-to-c --compat-term -i ${NAME}.adt --prologue ${NAME}.pro \
                                --prefix ${PREFIX} -o ${NAME}

clean:
	${RM} ${CLEANFILES} *.o ${NAME}.[ch] ${NAME}_dict.[ch] ${NAME}.dict \
              ${NAME}.adt 
