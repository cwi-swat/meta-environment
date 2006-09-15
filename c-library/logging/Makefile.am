# $Id$

include $(top_srcdir)/Makefile.meta

lib_LTLIBRARIES = liblogging.la
include_HEADERS = logging.h 

liblogging_la_CPPFLAGS = \
        $(ATERM_CFLAGS) -DDISABLE_DYNAMIC_CHECKING

liblogging_la_LDFLAGS = -avoid-version -no-undefined $(AM_LDFLAGS)
liblogging_la_LIBADD = $(ATERM_LIBS)
liblogging_la_SOURCES = logging.c



