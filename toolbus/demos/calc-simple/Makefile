# Generated automatically from Makefile.in by configure.
# Generated automatically from Makefile.in by configure.
# demos/calc

PRODUCT		= ToolBus
VERSION		= 0.9.16c

srcdir		= .
top_srcdir	= ../..
prefix		= /nfs/adam/ada1/olivierp/ToolBus-0.9.16c
exec_prefix	= ${prefix}
bindir 		= $(exec_prefix)/bin
libdir		= $(exec_prefix)/lib
includedir	= $(prefix)/include

CC		= gcc
SHELL		= /bin/sh
CFLAGS		= 
INCLUDES	=  -I$(includedir)
LIBS		=  -lsocket -lnsl -lm
TBLIB		= $(libdir)/libtb.a

CLEAN		= rm -f *~ a.out core y.tab.c lex.yy.c *.o; 	rm -f *.chly.tex *.dvi *.log *.aux

COMPILE = $(CC) $(DEFS) $(INCLUDES) $(CPPFLAGS) $(CFLAGS) $@.c -o $@ $(TBLIB) $(LIBS)

.SUFFIXES:
.SUFFIXES: .c .o

PROGRAMS	= calc

DISTFILES	= Makefile.in calc.tb calc.tif.c calc.c\
		  delay.h ui-calc.tcl

all:    ${PROGRAMS}

clean:
	${CLEAN} batch.out ${PROGRAMS}

distclean: clean
	rm -f Makefile

clock:	clock.tif.c clock.c 
	${COMPILE}

clock.tif.c: calc.tifs
	${bindir}/ctif -tool clock -tifs calc.tifs

log:	log.tif.c log.c
	${COMPILE}

log.tif.c: calc.tifs
	${bindir}/ctif -tool log -tifs calc.tifs

calc:	calc.tif.c calc.c
	${COMPILE}
calc.tif.c: calc.tifs
	${bindir}/ctif -tool calc -tifs calc.tifs

batch:	batch.tif.c batch.c
	${COMPILE}

batch.tif.c: calc.tifs
	${bindir}/ctif -tool batch -tifs calc.tifs

calc.tifs: calc.tb
	${bindir}/toolbus -gentifs calc.tb

calc.tb.tex: calc.tb
	${bindir}/script2latex <calc.tb >calc.tb.tex

 
dist: $(DISTFILES)
	@for file in $(DISTFILES); do \
	  ln $(srcdir)/$$file $(top_srcdir)/../$(PRODUCT)-$(VERSION)/demos/calc 2> /dev/null \
	  || cp $(srcdir)/$$file $(top_srcdir)/../$(PRODUCT)-$(VERSION)/demos/calc; \
	done




