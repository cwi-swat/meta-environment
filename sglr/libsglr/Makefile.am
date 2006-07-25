# $Id$

include $(top_srcdir)/Makefile.meta

lib_LTLIBRARIES = libsglr.la

include_HEADERS		= sglr.h parse-table.h

noinst_HEADERS		= forest.h mem-alloc.h parser.h \
			rsrc-usage.h sglr-strings.h sglr.h stack.h \
			bitmap.h ambi-tables.h marking.h posmap.h levels.h

libsglr_la_SOURCES	= sglr-interface.c forest.c parse-table.c parser.c \
			stack.c rsrc-usage.c stack-collect.c bitmap.c \
                        ambi-tables.c marking.c posmap.c levels.c

libsglr_la_CPPFLAGS = \
  $(ATERM_CFLAGS) \
  $(TOOLBUSLIB_CFLAGS) \
  $(ERROR_SUPPORT_CFLAGS) \
  $(PT_SUPPORT_CFLAGS)

libsglr_la_LDFLAGS = -avoid-version -no-undefined $(AM_LDFLAGS)
libsglr_la_LIBADD  = \
  $(ATERM_LIBADD) \
  $(TOOLBUSLIB_LIBADD) \
  $(ERROR_SUPPORT_LIBADD) \
  $(PT_SUPPORT_LIBADD)
