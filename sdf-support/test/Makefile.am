#
# vim:ts=8
#
# $Id$
#

TESTS			= grammars sorts

noinst_PROGRAMS		= ${TESTS}
CFLAGS			= -g -Wall -O2
INCLUDES		= -I../lib -I$(ATERM)/include -DSRC_DIR=\"${srcdir}\"
LDLIBS			= $(ATERM)/lib/libATerm.a ../lib/libSDF.a

grammars_SOURCES	= grammars.c
grammars_LDADD		= $(LDLIBS)

sorts_SOURCES		= sorts.c
sorts_LDADD		= $(LDLIBS)

EXTRA_DIST             = Booleans.pt Layout.pt
