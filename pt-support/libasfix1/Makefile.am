#
# vim:ts=8:sw=8:sts=0
#
# $Id$
#

lib_LIBRARIES		= libPT.a
include_HEADERS		= PT.h PT_dict.h
libPT_a_SOURCES		= PT.c PT_dict.c

EXTRA_DIST		= AsFix.adt

CFLAGS			= -g -Wall -O2
INCLUDES		= -I${ATERMINC}
LDFLAGS			= -L${ATERMLIB}
LDADD			= -lATerm
