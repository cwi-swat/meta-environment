#
# vim:ts=8
#
# $Id$
#

TESTS			= grammars sorts

noinst_PROGRAMS		= ${TESTS}
CFLAGS			= -g -Wall -O2
INCLUDES		= -I$(ATERM)/include \
                          -I${top_srcdir}/lib \
                          -DSRC_DIR=\"${srcdir}\"

LDLIBS			= -L$(ATERM)/lib -lATerm -L../lib -lSDF

grammars_SOURCES	= grammars.c
grammars_LDADD		= $(LDLIBS)

sorts_SOURCES		= sorts.c
sorts_LDADD		= $(LDLIBS)

EXTRA_DIST             = Booleans.pt Layout.pt
