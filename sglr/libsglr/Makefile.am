# $Id$

#CFLAGS	+= -DNO_SHARING

include $(top_srcdir)/make_rules
INCLUDES		= -I$(ATERM)/include \
			-I$(TOOLBUSLIB)/include \
			-I$(ERROR_SUPPORT)/include \
			-I$(PT_SUPPORT)/include

lib_LIBRARIES		= libsglr.a

include_HEADERS		= sglr.h parse-table.h

noinst_HEADERS		= forest.h mem-alloc.h parser.h \
			rsrc-usage.h sglr-strings.h sglr.h stack.h \
			bitmap.h ambi-tables.h marking.h posmap.h

libsglr_a_SOURCES	= sglr-interface.c forest.c parse-table.c parser.c \
			stack.c rsrc-usage.c stack-collect.c bitmap.c \
                        ambi-tables.c marking.c posmap.c

libsglr_a_INCLUDE       = $(INCLUDES)
