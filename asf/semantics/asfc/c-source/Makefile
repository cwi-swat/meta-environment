include Make.modules

ATERM	= /home/markvdb/NEW-META/new-meta/..
#CC	= gcc
CC	= cc
INCLUDE = -I$(ATERM)/include -I../support
#CFLAGS	= -g -Wall -pedantic $(INCLUDE)
CFLAGS	= -O $(INCLUDE)
#CFLAGS	= -pg $(INCLUDE)
#LIBS	= -L$(ATERM)/lib -laterm-dbg -lasfix-dbg -ltoolbus -lgel -lsocket -lnsl
LIBS	= -L$(ATERM)/lib -laterm-cc -lasfix-cc -ltoolbus-cc -lgel -lsocket -lnsl
#LIBS	= -L$(ATERM)/lib -laterm-prof -lasfix-prof -ltoolbus -lgel -lsocket -lnsl -ldl
#LFLAGS	= -g 
LFLAGS	=  
#LFLAGS	= -pg
AR	= ar

BASE	= ..
PPC	= $(BASE)/clib/ppc

FILES	:= $(notdir $(ASFIX))
NAMES   := $(patsubst %.asfix,%,$(FILES))
CSRC	:= $(patsubst %.asfix,%.c,$(FILES)) 
MODS	:= init.o $(patsubst %.asfix,%.o,$(FILES))
INIT	:= $(patsubst %.asfix,%();,$(FILES))
REGALL	:= $(patsubst %,register_%,$(INIT))
EREGALL	:= $(patsubst %,extern void register_%,$(INIT))
RESALL	:= $(patsubst %,resolve_%,$(INIT))
ERESALL := $(patsubst %,extern void resolve_%,$(INIT))

all: asfix2c libasfix2c.a


asfix2c: $(MODS) ../support/support.o ../support/rewriter.o
	$(CC) $(LFLAGS) -o asfix2c ../support/support.o ../support/rewriter.o $(MODS) $(LIBS)

libasfix2c.a: $(MODS)
	$(AR) cr libasfix2c.a $(MODS)
%.o: %.c
	$(CC) $(CFLAGS) -c $<

init.o: init.c

init.c:
	for file in $(NAMES); do \
	  echo "extern void register_$$file();" | sed "s/\-/_/g" >> $@ ; \
	  echo "extern void resolve_$$file();"  | sed "s/\-/_/g" >> $@ ; \
	done
	echo "void register_all() {" >> $@
	for file in $(NAMES); do \
	  echo "  register_$$file();" | sed "s/\-/_/g" >> $@ ; \
	done
	echo "}" >> $@
	echo "void resolve_all() {" >> $@
	for file in $(NAMES); do \
	  echo "  resolve_$$file();" | sed "s/\-/_/g" >> $@ ; \
	done
	echo "}" >> $@









