# $Id$

include $(top_srcdir)/make_rules
INCLUDES		= -I$(ATERM)/include \
			-I$(TOOLBUS)/include \
			-I$(PT_SUPPORT)/include

lib_LIBRARIES		= libsglr.a

include_HEADERS		= sglr.h

noinst_HEADERS		= forest.h mem-alloc.h parse-table.h parser.h \
			rsrc-usage.h sglr-strings.h sglr.h stack.h \
			multisets.h bitmap.h

libsglr_a_SOURCES	= sglr-interface.c forest.c parse-table.c parser.c \
			stack.c rsrc-usage.c stack-collect.c multisets.c \
			bitmap.c

libsglr_a_INCLUDE       = $(INCLUDES)
