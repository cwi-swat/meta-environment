# $Id$

include $(top_srcdir)/make_rules

INCLUDES		= -I$(top_srcdir)/libsglr \
			-I$(ATERM)/include \
			-I$(TOOLBUS)/include \
			-I$(PT_SUPPORT)/include

lib_LIBRARIES		= libtree2dot.a
libtree2dot_a_SOURCES	= tree-to-dot.c sg_growbuf.c

include_HEADERS		= tree-to-dot.h
noinst_HEADERS		= sg_growbuf.h
