# $Id$

include ../make_rules

bin_PROGRAMS = parse-client

EXTRA_DIST   = parse-client.tb

SRCS         = parse-client.c
HDRS         = 

parse_client_SOURCES = $(SRCS) $(HDRS)

LDADD        = -L$(ATERMLIB) -lATerm -lAsFix -lATB $(SOCKLIBS)

# make sure generates files are removed during "make clean"
CLEANFILES   = parse-client.tif.c parse-client.tif.h


# extra dependency for parse-client.c to generate parse-client.tif.[ch]
${srcdir}/parse-client.c : parse-client.tif.h parse-client.tif.c
