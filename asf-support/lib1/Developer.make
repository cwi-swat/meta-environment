#
# Developers.make
#
# This Makefile is used to generate the C library in this directory.
#

include ./Makefile

# Developers only, put location of ADT-support here:
ADT      = ${prefix}

api: ASF.raw

ASF.raw: Asf.label.def
	sdf2-to-adt -r -i $< -o ASF.raw

ASF.adt: ASF.raw subst-eqs
	subst-eqs ASF.raw > ASF.adt

ASF.c: ASF.adt ASF.pro
	adt-to-c -i ASF.adt --prologue ASF.pro --prefix ASF_ -o ASF

subst-eqs: subst-eqs.c
	${COMPILE} -o $@ $<  -I${ADT}/include -I${ATERM}/include \
                             -L${ATERM}/lib -lATerm -L${ADT}/lib -lADT

clean:
	${RM} ${CLEANFILES} *.o ASF.[ch] ASF_dict.[ch] ASF.dict ASF.adt \
                            ASF.raw  subst-eqs
