# $Id$

include ../make_rules

lib_LIBRARIES          = libsglr.a
# noinst_LIBRARIES       = libsglr-prof.a

EXTRA_LIBRARIES        = libsglr-gc.a libsglr-prof.a

HDRS                   = forest.h mem-alloc.h parse-table.h parser.h \
                         rsrc-usage.h sglr-strings.h sglr.h stack.h

SRCS                   = sglr-interface.c forest.c parse-table.c parser.c \
                         stack.c rsrc-usage.c stack-collect.c

libsglr_a_SOURCES      = $(SRCS) $(HDRS)

libsglr_prof_a_SOURCES = $(HDRS)
libsglr_prof_a_LIBADD  = $(SRCS:.c=-prof.o)

libsglr_gc_a_SOURCES   = $(HDRS)
libsglr_gc_a_LIBADD    = $(SRCS:.c=-gc.o) -lgc
