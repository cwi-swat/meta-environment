#$Id$

DEMO	= $(NEWMETA)/demo/
PICO	= $(DEMO)/pico/Pico-syntax
SUBDIRS = GenerateParseTable

include Metarules.include

all test clean: 
	@for DIR in $(SUBDIRS); \
	do \
		echo Make $@ in $$DIR; \
		cd $$DIR; \
		$(MAKE) -${MAKEFLAGS} $@; \
		cd ..; \
	done
