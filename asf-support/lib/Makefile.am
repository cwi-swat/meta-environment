# $Id$

lib_LIBRARIES		= libASFME.a
include_HEADERS		= ASFME.h ASFME-utils.h ASFME_dict.h
libASFME_a_SOURCES	= ASFME.c ASFME_dict.c ASFME-utils.c lex-cons.c \
		          ASFME_bottom.c

INCLUDES		= -I${ATERM}/include -I${PT_SUPPORT}/include
CFLAGS			+= -DDISABLE_DYNAMIC_CHECKING
#CFLAGS			+= -pg -DDISABLE_DYNAMIC_CHECKING


api: subst-eqs
	sdf2-to-adt -i Asf.label.def -o ASFME.raw
	sdf2-to-c -b -o ASFME --prefix ASF_
	./subst-eqs ASFME.raw > ASFME.adt
	echo "typedef ATerm ASF_Symbol;" >> ASFME.pro
	adt-to-c --compat-term -i ASFME.adt --prologue ASFME.pro \
		--prefix ASF_ -o ASFME

subst-eqs: subst-eqs.c
	${COMPILE} -o $@ $<  -I${ADT}/include -I${ATERM}/include \
                             -L${ATERM}/lib -lATerm -L${ADT}/lib -lADT

api-clean:
	${RM} ${CLEANFILES} *.o ASFME.[ch] ASFME_dict.[ch] ASFME.dict \
	ASFME.adt ASFME.raw  subst-eqs ASFME_bottom.c
