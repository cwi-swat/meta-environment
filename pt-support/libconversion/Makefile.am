#
# vim:ts=8:sw=8:sts=0
#
# $Id$
#

lib_LIBRARIES           = libconversion.a
include_HEADERS         = conversion.h
libconversion_a_SOURCES = flattenPT.c inflatePT.c a2metoa1.c

CFLAGS                  = -g -Wall -O2
INCLUDES		= -I${top_srcdir}/libmept \
                          -I${top_srcdir}/libasfix2 \
			  -I${ATERM}/include
