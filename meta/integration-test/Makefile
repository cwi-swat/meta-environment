#$Id$

SUBDIRS = ParsePicoTerm

include Metarules.include

all test clean: 
	@for DIR in $(SUBDIRS); \
	do \
		echo Make $@ in $$DIR; \
		cd $$DIR; \
		$(MAKE) -${MAKEFLAGS} $@; \
		cd ..; \
	done

install:
