#
# vim:ts=8:sw=8:sts=0
#
# $Id$
#

lib_LIBRARIES		= libPT.a
include_HEADERS		= PT.h PT_dict.h PT-utils.h
libPT_a_SOURCES		= PT.c PT_dict.c PT-utils.c yieldPT.c yieldProd.c

bin_PROGRAMS		= get-parsetree

get_parsetree_SOURCES	= get-parsetree.c
get_parsetree_LDADD	= libPT.a ${LDFLAGS} ${LDADD}

EXTRA_DIST		= AsFix.adt

CFLAGS			= -g -Wall -O2
INCLUDES		= -I${ATERM}/include
LDFLAGS			= -L${ATERM}/lib
LDADD			= -lATerm
