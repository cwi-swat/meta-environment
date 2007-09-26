# $Id$

include $(top_srcdir)/Makefile.meta

lib_LTLIBRARIES = libASFME.la

include_HEADERS = \
	ASFME.h \
	ASFME-utils.h \
	ASFME_dict.h

libASFME_la_SOURCES = \
	ASFME.c \
	ASFME_dict.c \
	ASFME-utils.c  \
	lift.c \
	lower.c

libASFME_la_CPPFLAGS = $(ATERM_CFLAGS) $(ERROR_SUPPORT_CFLAGS) $(PT_SUPPORT_CFLAGS)
libASFME_la_CFLAGS   = -DDISABLE_DYNAMIC_CHECKING
libASFME_la_LDFLAGS  = -avoid-version -no-undefined $(AM_LDFLAGS)
libASFME_la_LIBADD   = $(PT_SUPPORT_LIBS) $(ERROR_SUPPORT_LIBS) $(ATERM_LIBS)

LIBRARY=../../sdf-library/library

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
