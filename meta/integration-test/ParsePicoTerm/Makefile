#$Id$

include ../Metarules.include

ASFIXTRMS = $(addsuffix .pico.asfix, $(PICOTRMS))

all:

test: $(ASFIXTRMS)
	@$(RM) Pico-syntax.tbl

clean:
	rm -f Pico-syntax.tbl

Pico-syntax.tbl : $(PICOSYNTAX)
	@sdf2table -i $< -o $@

%.pico.asfix: $(PICODIR)/%.pico Pico-syntax.tbl
	@sglr -v -p Pico-syntax.tbl -i $< > /dev/null

