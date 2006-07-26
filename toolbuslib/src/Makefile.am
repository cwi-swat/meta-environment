# $Id$
#
include $(top_srcdir)/Makefile.meta

AM_CPPFLAGS += $(ATERM_CFLAGS)

lib_LTLIBRARIES = libATB.la
include_HEADERS = atb-tool.h

libATB_la_SOURCES  = atb-tool.c
libATB_la_CPPFLAGS = $(ATERM_CFLAGS)
libATB_la_LDFLAGS  = -avoid-version -no-undefined $(AM_LDFLAGS)
libATB_la_LIBADD   = $(ATERM_LIBS) $(SOCKETLIBS)

bin_PROGRAMS = tbunpack

tbunpack_SOURCES = tbunpack.c atb-tool.c
tbunpack_LDADD = $(ATERM_LIBS)
