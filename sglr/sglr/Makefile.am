# $Id$

include ${top_srcdir}/make_rules

EXTRA_DIST		= sglr.idef
CLEANFILES		= sglr.tifs sglr.tif.[ch]

INCLUDES		= -I$(top_srcdir)/libsglr \
			-I$(top_srcdir)/libtree2dot \
			-I$(PT_SUPPORT)/include \
			-I$(TOOLBUS)/include \
			-I$(ATERM)/include

data_DATA		= sglr.idef
noinst_HEADERS		= getopt.h

bin_PROGRAMS		= sglr 

sglr_SOURCES		= sglr.tif.c sglr.tif.h sglr-main.c getopt.c getopt1.c
sglr_LDADD		= -L$(top_builddir)/libsglr -lsglr \
			-L$(top_builddir)/libtree2dot -ltree2dot \
			-L$(PT_SUPPORT)/lib -lconversion -lmept -lasfix2 \
			-L$(TOOLBUS)/lib -lATB \
			-L$(ATERM)/lib -lATerm \
			$(SOCKLIBS)
