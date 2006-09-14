# $Id$

lib_LTLIBRARIES         = libptable.la
include_HEADERS         = ptable.h ptable-utils.h ptable_dict.h
libptable_la_LDFLAGS    = -avoid-version -no-undefined $(AM_LDFLAGS)
libptable_la_SOURCES 	= ptable.c ptable-utils.c ptable_dict.c

libmept_la_CPPFLAGS = $(PT_SUPPORT_CFLAGS) -DDISABLE_DYNAMIC_CHECKING

# Developers only, put location of ADT-support here:
ADT      = ${prefix}
NAME     = ptable
PREFIX   = PTBL_

api: ${NAME}.adt 
	adt-to-c \
		-i ${NAME}.adt \
		--name ${NAME} \
		--prefix ${PREFIX} 

api-clean:
	$(RM) ${NAME}.[ch] ${NAME}_dict.[ch] ${NAME}.dict
