# $Id$

lib_LIBRARIES = libASFME.a

include_HEADERS = \
	ASFME.h \
	ASFME-utils.h \
	ASFME_dict.h

libASFME_a_SOURCES = \
	ASFME.c \
	ASFME_dict.c \
	ASFME-utils.c \
	lex-cons.c

INCLUDES = \
	-I${ATERM}/include \
	-I${ERROR_SUPPORT}/include \
	-I${PT_SUPPORT}/include

AM_CFLAGS = -DDISABLE_DYNAMIC_CHECKING

#ADT = /ufs/sen1/software/installed/apigen-bundle-1.5/linux/i386
ADT = /ufs/jurgenv/glt/installed/apigen

Asf.label.def:
	(echo "definition";\
         cat ../../asf-library/library/languages/asf/syntax/*.sdf ) > $@

api: subst-eqs
	${ADT}/bin/sdf2-to-adt -i Asf.label.def -o ASFME.raw
	./subst-eqs ASFME.raw > ASFME.adt
	echo "typedef ATerm ASF_Symbol;" >> ASFME.pro
	${ADT}/bin/adt-to-c \
		--input ASFME.adt \
		--name ASFME \
		--prologue ASFME.pro \
		--prefix ASF_

subst-eqs: subst-eqs.c
	${COMPILE} -o $@ $<  -I${ADT}/include -I${ATERM}/include \
                             -L${ATERM}/lib -lATerm -L${ADT}/lib -lADT

api-clean:
	${RM} \
		${CLEANFILES} \
		*.o \
		ASFME.[ch] \
		ASFME_dict.[ch] \
		ASFME.dict \
		ASFME.adt \
		ASFME.pro \
		ASFME.raw \
		subst-eqs
