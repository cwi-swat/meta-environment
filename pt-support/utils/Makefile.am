#
# vim:ts=8:sw=8:sts=0
#
# $Id$
#

bin_PROGRAMS		= a2metoa1 flattenPT unparsePT implodePT unparseProd \
                          addPosInfo

addPosInfo_SOURCES      = addPosInfo.c
addPosInfo_LDADD        = -L../libmept -lmept \
                          -L${ATERM}/lib -lATerm

flattenPT_SOURCES	= flattenPT-main.c
flattenPT_LDADD		= -L../libconversion -lconversion \
                          -L../libmept -lmept \
                          -L../libasfix2 -lasfix2 \
			  -L${ATERM}/lib -lATerm

a2metoa1_SOURCES	= a2metoa1-main.c
a2metoa1_LDADD		= -L../libconversion -lconversion \
                          -L../libmept -lmept \
			  -L${ATERM}/lib -lATerm

unparsePT_SOURCES	= unparsePT-main.c
unparsePT_LDADD		= -L../libmept -lmept \
			  -L${ATERM}/lib -lATerm

unparseProd_SOURCES	= unparseProd-main.c
unparseProd_LDADD	= -L../libmept -lmept \
			  -L${ATERM}/lib -lATerm

implodePT_SOURCES	= implodePT-main.c
implodePT_LDADD		= -L../libmept -lmept \
			  -L${ATERM}/lib -lATerm

CFLAGS			= -g -Wall -O2
INCLUDES		= -I${top_srcdir}/libmept \
                          -I${top_srcdir}/libasfix2 \
                          -I${top_srcdir}/libconversion \
			  -I${ATERM}/include
