# $Id$

include $(top_srcdir)/make_rules

INCLUDES		= -I${top_srcdir}/libsglr \
			-I$(ATERM)/include \
			-I$(TOOLBUS)/include \
			-I${PT_SUPPORT}/include

bin_PROGRAMS		= ambtracker
ambtracker_SOURCES	= ambtracker.c

ambtracker_LDADD	= -L${top_builddir}/libsglr -lsglr \
			-L${top_builddir}/libtree2dot -ltree2dot \
			-L$(PT_SUPPORT)/lib -lconversion -lmept -lasfix2 \
			-L$(TOOLBUS)/lib -lATB \
			-L$(ATERM)/lib -lATerm \
			$(SOCKLIBS)

