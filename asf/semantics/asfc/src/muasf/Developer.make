#
# Developers.make
#
# This Makefile is used to generate the C library in this directory.
#

include ./Makefile

# Developers only, put location of ADT-support here:
ADT      = ${prefix}
NAME     = MuASF
PREFIX   = MA_
SOURCE   = MuASF.label.def

sdf2-to-adt=sdf2-to-adt
adt-to-c=adt-to-c

api: ${NAME}.c

${NAME}.adt: ${SOURCE}
	${sdf2-to-adt} -r -i $< -o ${NAME}.adt

${NAME}.c: ${NAME}.adt ${NAME}.pro
	${adt-to-c} -i ${NAME}.adt --prologue ${NAME}.pro \
                                --prefix ${PREFIX} -o ${NAME}

clean:
	${RM} ${CLEANFILES} *.o ${NAME}.[ch] ${NAME}_dict.[ch] ${NAME}.dict \
              ${NAME}.adt 
