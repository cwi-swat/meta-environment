# $Id$

include $(top_srcdir)/make_rules

EXTRA_DIST		= parse-client.tb

CLEANFILES		= parse-client.tifs parse-client.tif.c \
			parse-client.tif.h

INCLUDES		= -I$(ATERM)/include -I$(TOOLBUS)/include

bin_PROGRAMS		= parse-client
parse_client_SOURCES	= parse-client.c
parse_client_LDADD	= -L$(PT_SUPPORT)/lib -lconversion -lmept -lasfix2 \
			-L$(TOOLBUS)/lib -lATB \
			-L$(ATERM)/lib -lATerm \
			$(SOCKLIBS)

# extra dependency for parse-client.c to generate parse-client.tif.[ch]
parse-client.o : parse-client.tif.h parse-client.tif.c
