SFILES = \
        trace-diff-s0 \
	trace-diff-s1 \
	trace-diff-s2 \
	trace-diff-s3 \
	trace-diff-s4

BFILES = \
        trace-diff-b0 \
	trace-diff-b1 \
	trace-diff-b2 \
	trace-diff-b3 \
	trace-diff-b4 \
	trace-diff-b5 \
	trace-diff-b6

all: $(SFILES) $(BFILES)

sglr-full-trace-s% : data/s%.str
	sglr -tvd -p grammars/Stratego.tbl -i $<
	cp .sglr-log $@

sglr-full-trace-b% : data/b%.txt
	sglr -tvd -p grammars/Booleans.tbl -i $<
	cp .sglr-log $@

sglr-trace-% : sglr-full-trace-%
	grep Goto $< > $@

jsglr-trace-% : jsglr-full-trace-%
	grep Goto $< > $@

trace-diff-% : sglr-trace-% jsglr-trace-%
	-diff $^ > $@

clean:
	rm -f sglr-trace-* jsglr-trace-* trace-diff-*

fullclean : clean
	rm -f sglr*full* jsglr*full*
