EXTRA_DIST = master.tcl bidder.tcl auction.tb bidder

CLEANFILES = auction.tb.tex

all: auction.tb.tex

%.tb.tex: %.tb
	$(top_builddir)/toolbus/script2latex < $< > $@
