# $Id$

lib_LIBRARIES = libslicing.a

include_HEADERS = \
	Slicing.h \
	Slicing-utils.h

libslicing_a_SOURCES = \
	Slicing.c  \
	slice-tree.c

INCLUDES = \
	-I${ATERM}/include \
	-I${ERROR_SUPPORT}/include

api: Slicing.adt
	adt-to-c \
		--prefix S_ \
		--name Slicing \
		--input Slicing.adt \
		--prologue Slicing.pro

api-clean:
	${RM} Slicing.[ch] Slicing_dict.[ch] Slicing.dict
