# $Id$

include $(top_srcdir)/make_rules

INCLUDES		= -I$(top_srcdir)/libsglr \
			-I$(top_srcdir)/libtree2dot \
			-I$(PT_SUPPORT)/include \
			-I$(TOOLBUS)/include \
			-I$(ATERM)/include

bin_PROGRAMS		= sglr 
sglr_SOURCES		= sglr-main.c getopt.c getopt1.c

data_DATA		= sglr.idef
noinst_HEADERS		= getopt.h

EXTRA_DIST		= sglr.idef sglr.tif.c sglr.tif.h
CLEANFILES		= sglr.tifs

#CFLAGS			+= -pg

sglr_LDADD		= -L$(top_builddir)/libsglr -lsglr \
			-L$(top_builddir)/libtree2dot -ltree2dot \
			-L$(PT_SUPPORT)/lib -lconversion -lmept -lasfix2 \
			-L$(TOOLBUS)/lib -lATB \
			-L$(ATERM)/lib -lATerm \
			$(SOCKLIBS)

sglr_INCLUDE            = $(INCLUDES)

# extra dependency for sglr-main.c to generate sglr.tif.[ch]
sglr-main.o : sglr.tif.c sglr.tif.h $(top_builddir)/libsglr/libsglr.a \
              $(top_builddir)/libtree2dot/libtree2dot.a
