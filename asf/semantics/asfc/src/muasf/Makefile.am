#
# vim:ts=8:sw=8:sts=0
#
# $Id$
#

noinst_LIBRARIES	= libMuASF.a
noinst_HEADERS		= MuASF.h MuASF_dict.h
libMuASF_a_SOURCES	= MuASF.c MuASF_dict.c 

EXTRA_DIST		= MuASF.label.def

CFLAGS			= -g -Wall -O2
INCLUDES		= -I${ATERM}/include
LDFLAGS			= -L${ATERM}/lib
LDADD			= -lATerm
