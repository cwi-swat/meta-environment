#
# vim:ts=8
#
# $Id$
#

TESTS			= grammars sorts

noinst_PROGRAMS		= ${TESTS}
CFLAGS			= -g -Wall -O2
INCLUDES		= -I$(ATERM)/include \
                          -I$(PT_SUPPORT)/include \
                          -I${top_srcdir}/lib \
                          -DSRC_DIR=\"${srcdir}\"

LDLIBS			= -L../libME -lSDFME \
                          -L$(PT_SUPPORT)/lib -lmept \
                          -L$(ATERM)/lib -lATerm

grammars_SOURCES	= grammars.c
grammars_LDADD		= $(LDLIBS)

sorts_SOURCES		= sorts.c
sorts_LDADD		= $(LDLIBS)

EXTRA_DIST             = Booleans.pt Layout.pt
