# $Id$

include $(top_srcdir)/make_rules

INCLUDES		= -I${top_srcdir}/libsglr \
			-I${top_srcdir}/libtree2dot \
			-I$(ATERM)/include \
			-I${PT_SUPPORT}/include

bin_PROGRAMS		= tree2dot
tree2dot_SOURCES	= tree2dot-main.c

tree2dot_LDADD		= -L${top_srcdir}/libtree2dot -ltree2dot \
			-L${top_srcdir}/libsglr -lsglr \
			-L$(PT_SUPPORT)/lib -lconversion -lmept -lasfix2 \
			-L$(ATERM)/lib -lATerm -lATB $(SOCKLIBS)
