#
# vim:ts=8:sw=8:sts=0
#
# $Id$
#

lib_LIBRARIES		= libSDF.a
include_HEADERS		= SDF.h SDF_dict.h
libSDF_a_SOURCES	= SDF.c SDF_dict.c

EXTRA_DIST		= SDF.adt

CFLAGS			= -g -Wall -O2
INCLUDES		= -I${ATERMINC}
LDFLAGS			= -L${ATERMLIB}
LDADD			= -lATerm
