DOCS       = Guide.ps.gz Intro.ps.gz pamflet.ps.gz

EXTRA_DIST = $(DOCS) \
             Adapter.pic Arch.pic Tifs.pic Tool.pic \
             Guide.tex Intro.tex Syntax-T-scripts.tex pamflet.tex \
             arch-simpel.fig auction.fig calc.fig zeeslag.fig \
             auction-bidder.eps auction-master.eps battleships.eps calc-ui.eps


CLEANFILES = $(DOCS) *.dvi *.aux *.log *.toc \
             adapters.tex Adapter.tex Arch.tex Tifs.tex Tool.tex \
             arch-simpel.ps auction.ps calc.ps zeeslag.ps

doc: $(DOCS)

Guide.dvi: Arch.tex Tifs.tex Tool.tex Adapter.tex  Guide.tex adapters.tex
	@TEXINPUTS=$(top_srcdir)/adapters:$(srcdir):$$TEXINPUTS:; \
	export TEXINPUTS; \
	latex Guide.tex; \
	latex Guide.tex; \
	latex Guide.tex

Intro.dvi: Intro.tex calc.ps auction.ps
	@TEXINPUTS=$(top_srcdir)/adapters:$(srcdir):$$TEXINPUTS:; \
	export TEXINPUTS; \
	latex Intro.tex; \
	latex Intro.tex

pamflet.dvi: pamflet.tex arch-simpel.ps battleships.eps zeeslag.ps
	@TEXINPUTS=$(srcdir):$$TEXINPUTS:; \
	export TEXINPUTS; \
	latex pamflet.tex ;\
	latex pamflet.tex

%.ps : %.dvi
	dvips -o $@ $<

%.ps.gz : %.ps
	$(RM) $@
	gzip $<

%.tex : %.pic
	gpic -t $< > $@

%.ps : %.fig
	fig2dev -Lps $< >$@

adapters.tex:
	@(for adapter in $(ALL_ADAPTERS) ;\
	do \
	   if [ -f $(top_srcdir)/adapters/$${adapter}/$${adapter}.guide.tex ]; then \
		echo \\input{$(top_srcdir)/adapters/$${adapter}/$${adapter}.guide.tex} ;\
	   fi\
	done ) > $@
	