# $Id$

include $(top_srcdir)/Makefile.meta

lib_LTLIBRARIES = libLogging.la
include_HEADERS = logging.h 

libLogging_la_CPPFLAGS = \
        $(ATERM_CFLAGS) -DDISABLE_DYNAMIC_CHECKING

libLogging_la_LDFLAGS = -avoid-version -no-undefined $(AM_LDFLAGS)
libLogging_la_LIBADD = $(ATERM_LIBS)
libLogging_la_SOURCES = logging.c



