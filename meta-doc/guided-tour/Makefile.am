# $Id$

include $(top_srcdir)/make-rules

if BUILD_MANUAL
noinst_DATA = asf+sdf-guided-tour.pdf
endif

EXTRA_DIST = $(wildcard *.ltx) \
             $(wildcard *.ps) \
             $(wildcard *.pdf) \
             $(wildcard *.sty) \
             $(wildcard *.fig)

MANUAL	= guided-tour.ltx

PSJES = Bool-example-asf.ps Bool-example-sdf.ps Bool-example-trm.ps \
	Bool-example-trm2.ps Bool-example-ambtrm.ps \
	pico-syntax-term-actions-menu.ps  Pico-menu.ps \
	open-library.ps open-file.ps file-menu.ps export-menu.ps \
	refactor-menu.ps select-window.ps \
	meta-Bool-example.ps meta-Pico-syntax.ps \
	meta-pico.ps meta-amb-parsetree.ps \
	meta-parsetree.ps meta-start.ps module-menu.ps move-menu.ps \
	reduct-out.ps viewer.ps newarch.eps new-file.ps \
	cache-menu.ps open-termstore.ps save-termstore.ps \
	tools-menu.ps imports-panel.ps ruler.ps \
	edit-menu.ps check-menu.ps tools2-menu.ps \
	meta-env-menu-syntax.ps meta-env-menu-equation.ps \
	meta-env-menu-term.ps meta-full-parsetree.ps \
	log-message-tab.ps info-message-tab.ps error-message-tab.ps

EPSJES = ${PSJES:.ps=.eps}
PDFJES = ${EPSJES:.eps=.pdf}

CLEANFILES = guided-tour.aux guided-tour.bbl guided-tour.blg guided-tour.dvi \
             guided-tour.ilg guided-tour.ind guided-tour.idx guided-tour.log \
             guided-tour.ps  guided-tour.pdf guided-tour.toc guided-tour.out \
             $(PDFJES)

guided-tour: asf+sdf-guided-tour.pdf

guided-tour.ps: $(MANUAL)
	pdflatex guided-tour.ltx
	makeindex guided-tour.idx
	bibtex guided-tour
	pdflatex guided-tour.ltx
	pdflatex guided-tour.ltx
	acroread -toPostScript guided-tour.pdf

spell:
	detex guided-tour.ltx | spell -b +words.txt

asf+sdf-guided-tour.ps: guided-tour.dvi $(PSJES)
	dvips -o $@ $<

asf+sdf-guided-tour.pdf: $(MANUAL) $(PDFJES)
	latex guided-tour.ltx
	makeindex guided-tour.idx
	bibtex guided-tour
	latex guided-tour.ltx
	latex guided-tour.ltx
	dvipdf guided-tour.dvi
