# $Id$

lib_LIBRARIES = libmept.a

include_HEADERS = \
	MEPT.h \
	MEPT-utils.h \
	MEPT_dict.h

libmept_a_SOURCES = \
	MEPT.c \
	MEPT_dict.c \
	MEPT-utils.c  \
	flattenPT.c \
	implodePT.c \
	yieldPT.c \
	yieldProd.c \
	posInfo.c \
	reportAmbs.c \
	apply.c \
	symbol-renaming.c \
	ordering.c

AM_CFLAGS = -Wall -Werror -g -O2 -DDISABLE_DYNAMIC_CHECKING

INCLUDES = \
	-I${ATERM}/include \
	-I${ERROR_SUPPORT}/include

api: MEPT.adt
	adt-to-c \
		--prefix PT_ \
		--name MEPT \
		--input $<

api-clean:
	${RM} MEPT.[ch] MEPT_dict.[ch] MEPT.dict
