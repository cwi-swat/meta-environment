#
# vim:ts=8
#
# $Id$
#

TESTS			= grammars

noinst_PROGRAMS		= ${TESTS}
CFLAGS			= -g -Wall -O2
INCLUDES		= -I.. -I$(ATERMINC)
LDLIBS			= -L.. -lSDF -L$(ATERMLIB) -lATerm

grammars_SOURCES	= grammars.c
grammars_LDADD		= $(LDLIBS)
