#
# vim:ts=8:sw=8:sts=0
#
# $Id$
#

bin_PROGRAMS		= flattenPT

flattenPT_SOURCES	= flattenPT-main.c
flattenPT_LDADD		= -L../libconversion -lconversion \
                          -L../libmept -lmept -L${ATERM}/lib -lATerm

CFLAGS			= -g -Wall -O2
INCLUDES		= -I${ATERM}/include -I../libconversion
