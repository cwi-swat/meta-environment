include make_rules

MAIN = fmco02
SOURCES = $(MAIN).ltx $(MAIN).bib
FIGURES = $(wildcard figs/*.eps)
BUILDFILES = Makefile make_rules
STYLEFILES = llncs.cls splncs.bst
DELIVERABLES = $(DVI) $(PS) $(PDF)

DISTDIR = $(MAIN)-dist
DISTFILE = $(MAIN).tar.gz

DVI = $(MAIN).dvi
PS = $(MAIN).ps
PDF = $(MAIN).pdf

all: $(DELIVERABLES)

doc: all

dist: all
	@rm -rf $(DISTDIR)
	@mkdir -p $(DISTDIR)
	@cp $(DELIVERABLES) $(DISTDIR)
	@mkdir -p $(DISTDIR)/src
	@cp $(SOURCES) $(DISTDIR)/src
	@cp $(STYLEFILES) $(DISTDIR)/src
	@cp $(BUILDFILES) $(DISTDIR)/src
	@mkdir -p $(DISTDIR)/src/figs
	@cp $(FIGURES) $(DISTDIR)/src/figs
	@tar zcf $(DISTFILE) $(DISTDIR)
	@echo Distribution ready: `ls -l $(DISTFILE)`

fmco02.ps: fmco02.dvi
fmco.dvi: $(SOURCES)

clean:
	rm -f $(MAIN).{aux,bbl,blg,dvi,log,pdf,ps,toc}
