#$Id$

include ../Metarules.include

all test: $(addsuffix .pico.asfix, $(PICOTRMS))

clean:
	rm -f $(PICO).tbl $(addsuffix .pico.asfix, $(PICOTRMS))

%.pico.asfix: %.pico $(PICO).tbl
	sglr -v -p $(PICO).tbl -i $< -o $@

