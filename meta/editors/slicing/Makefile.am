# $Id$

lib_LIBRARIES = libslicing.a

include_HEADERS = \
	Slicing.h \
	Slicing-utils.h

libmept_a_SOURCES = \
	Slicing.c  \
	slice-tree.c

INCLUDES = \
	-I${ATERM}/include \
	-I${ERROR_SUPPORT}/include

api: slicing.adt
	adt-to-c \
		--prefix S_ \
		--name Slicing \
		--input $<

api-clean:
	${RM} Slicing.[ch] Slicing_dict.[ch] Slicing.dict
