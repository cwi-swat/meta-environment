# $Id$

#CFLAGS	+= -DNO_SHARING

lib_LIBRARIES           = libconversion.a
include_HEADERS         = conversion.h
libconversion_a_SOURCES = flattenPT.c inflatePT.c

INCLUDES		= -I${top_srcdir}/libmept \
                          -I${top_srcdir}/libasfix2 \
			  -I${ATERM}/include
