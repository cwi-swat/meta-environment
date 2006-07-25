# $Id$
#
include $(top_srcdir)/Makefile.meta

INCLUDES = $(ATERM_CFLAGS)

lib_LIBRARIES = libATB.a
include_HEADERS = atb-tool.h

libATB_a_SOURCES = atb-tool.c

bin_PROGRAMS = tbunpack

tbunpack_SOURCES = tbunpack.c atb-tool.c
tbunpack_LDADD = $(ATERM_LIBS)

