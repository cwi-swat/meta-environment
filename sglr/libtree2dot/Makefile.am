# $Id$

include ../make_rules

lib_LIBRARIES    = libtree2dot.a
noinst_LIBRARIES = libtree2dot-prof.a

SRCS             = tree-to-dot.c
HDRS             = tree-to-dot.h

libtree2dot_a_SOURCES      = $(SRCS) $(HDRS)

libtree2dot_prof_a_SOURCES = $(HDRS)
libtree2dot_prof_a_LIBADD  = $(SRCS:.c=-prof.o)
