# $Id$

lib_LIBRARIES = libASFME.a

include_HEADERS = \
	ASFME.h \
	ASFME-utils.h \
	ASFME_dict.h

libASFME_a_SOURCES = \
	ASFME.c \
	ASFME_dict.c \
	ASFME-utils.c  \
	lift.c \
	lower.c

INCLUDES = \
	-I${ATERM}/include \
	-I${ERROR_SUPPORT}/include \
	-I${PT_SUPPORT}/include

AM_CFLAGS = -DDISABLE_DYNAMIC_CHECKING

LIBRARY=../../asf-library/library

Asf.label.def:
	(echo "definition";\
         cat \
	     ${LIBRARY}/languages/asf/syntax/*.sdf \
	     ${LIBRARY}/basic/Whitespace.sdf \
	     ${LIBRARY}/languages/sdf2/syntax/Character.sdf) > $@

api: Asf.label.def
	sdf2-to-c \
		--input Asf.label.def \
		--output ASFME \
		--prefix ASF_

api-clean:
	${RM} \
		${CLEANFILES} \
		*.o \
		ASFME.[ch] \
		ASFME_dict.[ch] \
		ASFME.dict \
		ASFME.adt 

asfc:
	asfc -i ASF-Normalization.eqs -o ASF-Normalization.c -v
