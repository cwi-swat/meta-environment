# Generated automatically from Makefile.in by configure.
# $Id$
# Directory: sglr/src

# Configure variable substitutions
PRODUCT		= new-meta
VERSION		= 0.02



srcdir		= .
top_srcdir	= ../..
prefix		= /home/markvdb/NEW-META/new-meta/..
exec_prefix	= ${prefix}
bindir		= $(exec_prefix)/bin
libdir		= $(exec_prefix)/lib
includedir	= $(prefix)/include
docdir		= $(top_srcdir)/docs

SHELL		= /bin/sh
CC		= gcc
MAKE		= gmake
CFLAGS		= -g -pedantic -Wall ${XCFLAGS}
CPP		= gcc -E
CPPFLAGS	= gcc -E ${XCPPFLAGS}
DEFS		=  -DHAVE_LIBDL=1  ${XDEFS}
INCLUDES	=  ${XINCLUDES}
LIBS		= -ldl  ${XLIBS}
SOCKLIBS	= -lsocket -lnsl

INSTALL		= $(top_srcdir)/install-sh
INSTALL_DATA	= $(top_srcdir)/install-data-sh
INSTALL_PROG	= $(top_srcdir)/install-prog-sh
UNINSTALL	= $(top_srcdir)/uninstall-sh

TOOLBUS         = ${prefix}


# The eXtra parts of some variables
XCFLAGS		=
XCPPFLAGS	=
XINCLUDES	= -I$(TOOLBUS)/include
XLIBS		= -L$(TOOLBUS)/lib $(SOCKLIBS) -ltb


PROGS           = sglr
CSRC            = main.c getopt.c getopt1.c parse-table.c parser.c \
                  forest.c stack.c longest_match.c tree-to-dot.c
OBJ             = $(subst .c,.o,$(CSRC)) ../../a2toa1/a2toa1.o

all:	$(PROGS)

install:	all
	@for PROG in $(PROGS);	\
	do \
		$(INSTALL_PROG) $(INSTALL) $(bindir) $$PROG; \
	done

uninstall:
	@for PROG in $(PROGS);	\
	do \
		echo $@ $$PROG from $(bindir); \
		rm -f $(bindir)/$$PROG; \
	done

distclean realclean:	clean
	rm -f $(PROGS) longest_match

clean:
	rm -f core sglr.tif.c $(OBJ)


# Generic rules

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $<

%.tif.c: %.tifs
	$(TOOLBUS)/bin/ctif -tifs $< -tool $*

%.tifs: %.tb
	$(TOOLBUS)/bin/toolbus -gentifs $<


# Specific dependencies

sglr:	$(CSRC) $(OBJ)
	$(CC) $(LDFLAGS) $(OBJ) $(LIBS) -o $@

main.o:	sglr.tif.c

parse-table.o: parse-table.h

longest_match: longest_match.c
	$(CC) $(CFLAGS) $(INCLUDES) $(LDFLAGS) -DMAIN $^ $(LIBS) -o $@
