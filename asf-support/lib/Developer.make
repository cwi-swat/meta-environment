#
# Developers.make
#
# This Makefile is used to generate the C library in this directory.
#

include ./Makefile

# Developers only, put location of ADT-support here:
ADT      = ${prefix}

api: ASFME.raw

ASFME.raw: Asf.label.def
	sdf2-to-adt -r -i $< -o ASFME.raw

ASFME.adt: ASFME.raw subst-eqs
	./subst-eqs ASFME.raw > ASFME.adt

ASFME.c: ASFME.adt ASFME.pro
	adt-to-c --compat-term -i ASFME.adt --prologue ASFME.pro \
		--prefix ASF_ -o ASFME

subst-eqs: subst-eqs.c
	${COMPILE} -o $@ $<  -I${ADT}/include -I${ATERM}/include \
                             -L${ATERM}/lib -lATerm -L${ADT}/lib -lADT

clean:
	${RM} ${CLEANFILES} *.o ASFME.[ch] ASFME_dict.[ch] ASFME.dict ASFME.adt \
                            ASFME.raw  subst-eqs
