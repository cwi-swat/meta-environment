#
# vim:ts=8
#
# $Id$
#

TESTS			= grammars sorts

noinst_PROGRAMS		= ${TESTS}
CFLAGS			= -g -Wall -O2
INCLUDES		= -I../lib -I$(ATERM)/include
LDLIBS			= -L../lib -lSDF -L$(ATERM)/lib -lATerm

grammars_SOURCES	= grammars.c
grammars_LDADD		= $(LDLIBS)

sorts_SOURCES		= sorts.c
sorts_LDADD		= $(LDLIBS)
