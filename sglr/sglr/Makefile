#! GNU Makefile
#
# $Id$
#
# For SGLR parser
# 
# Eelco Visser
# Programming Research Group, University of Amsterdam
# email: visser@fwi.uva.nl
#
# JS
# To be placed under autoconf real soon
# Quick & Dirty hack for now
#

# ---- PARAMETERS ---------------------------------

# directories

PETR 		:= $(HOME)/petr
BINDIR  	:= $(PETR)/bin
GEL 		:= $(PETR)/gel
# TOOLBUS		:= $(PETR)/toolbus
TOOLBUS		:= $(PETR)
GRAMMARS	:= ../../grammars/

# C parameters

CC 		= gcc 

CFLAGS 		:= $(CFLAGS) -I$(GEL) -L$(GEL) -I$(TOOLBUS)/include -L$(TOOLBUS)/lib 

# LDFLAGS 	:= -lsocket -lnsl -ldl
LDFLAGS 	:= -L$(TOOLBUS)/lib -ltb

CFLAGS 		:= $(CFLAGS)  -g
LDFLAGS 	:= $(LDFLAGS) -g

#CFLAGS 		:= $(CFLAGS)  -pg
#LDFLAGS 	:= $(LDFLAGS) -pg

#CFLAGS 	:= $(CFLAGS) -O
#LDFLAGS 	:= $(LDFLAGS) -s 
		# for smaller (stripped) executables on many UNIX systems

# add -pg to CFLAGS for profiling (?)

# RM and CP are used below in case rm and cp are aliased
RM		= /bin/rm
CP		= /bin/cp

# CWEB

CWEAVE 		= cweave
CTANGLE 	= ctangle

# ---- VARIABLES ------------------------------------

sources 	= 
pics 		= architecture.pic 
all 		= $(sources) $(pics) Makefile README
csources 	= main.c getopt.c getopt1.c parse-table.c parser.c \
		  forest.c stack.c longest_match.c tree-to-dot.c
headers		= bool.h parse-table.h parser.h filter.h \
			forest.h stack.h
objects 	:= $(subst .c,.o,$(csources))
litcsources	:= $(subst .c,.ctx,$(csources)) $(subst .h,.htx,$(headers)) \
		   parse-table.gtx sglr.tbtx
libraries 	= -lmalloc -lgel -ltb

programs 	= sglr


tests		= $(GRAMMARS)/smaller/smaller.tst \
		  $(GRAMMARS)/small/small.tst	  \
		  $(GRAMMARS)/bool/Booleans.tst

# ---- RULES  ------------------------------------

all: $(programs)

sglr: $(csources) $(objects)
	$(CC) $(CFLAGS) $(LDFLAGS) $(objects) $(libraries) -o sglr
#	cp $@ $(BINDIR)

longest_match: longest_match.c
	$(CC) $(CFLAGS) $(LDFLAGS) -DMAIN $^ $(libraries) -o $@
#	cp $@ $(BINDIR)

TermIO: TermIO.o
	$(CC) $(CFLAGS) $(objects) $(libraries) -o TermIO

main.o: sglr.tif.c

parse-table.o: parse-table.h

%.tif.c: %.tifs
	ctif -tifs $< -tool $*

%.tifs: %.tb
	toolbus -gentifs $<
	
%.tst: %.tbl %.trm sglr
	sglr -p $< -i $*.trm -o $*.tst
	sglr -p $< -i $*.trm -o $*.a.tst -a

SGLR.dvi: sglr.dvi 
	cp $< $@

sglr.dvi: sglr.ltx $(wildcard *.ltx) $(litcsources)
	$(LATEX) $<

# ---- PHONEY RULES  ------------------------------------

test: $(tests)

install: $(programs)
	cp $^ $(BINDIR)
#	cp $^ /home/visser/syntax/bin/

doc: SGLR.ps
	cp $< ../doc

clean:
#	$(MAKE) texclean
	rm -f core sglr.pic sglr.tex sglr.c \
	   *~ $(objects) $(tests) $(litcsources) *.o

tar: $(all)
	tar cvhf sglr.tar $(all)

dist:

# ---- DEFAULT RULES  ------------------------------------

%.tbtx: %.tb litc
	./litc < $< > $@

%.gtx: %.gram litc
	./litc < $< > $@

%.ctx: %.c litc
	./litc < $< > $@

%.htx: %.h litc
	./litc < $< > $@

%.c: %.cw
	-$(CTANGLE) $<

litc:  litc.p
	pc $< -o $@

# include /home/visser/tex/LaTeX-Make
