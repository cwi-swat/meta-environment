noinst_DATA = wave.tb.tex

EXTRA_DIST  = ui-wave.tcl wave.tb

%.tb.tex : %.tb
	$(top_builddir)/toolbus/script2latex  < $< > $@
