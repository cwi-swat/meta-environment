#
# vim:ts=8
#
# $Id$
#

TESTS			= grammars sorts

noinst_PROGRAMS		= ${TESTS}
CFLAGS			= -g -Wall -O2
INCLUDES		= -I.. -I$(ATERMINC)
LDLIBS			= -L.. -lSDF -L$(ATERMLIB) -lATerm

grammars_SOURCES	= grammars.c
grammars_LDADD		= $(LDLIBS)

sorts_SOURCES		= sorts.c
sorts_LDADD		= $(LDLIBS)
