# $Id$

include $(top_srcdir)/make-rules

if BUILD_MANUAL
noinst_DATA = manual.pdf
endif

EXTRA_DIST = $(wildcard *.ltx) \
             $(wildcard *.ps) \
             $(wildcard *.pdf) \
             $(wildcard *.sty) \
             $(wildcard *.fig)


MANUAL	= manual.ltx

PSJES = Bool-example.asf.ps Bool-example.sdf2.ps Bool-example.trm.ps \
	Bool-example.trm2.ps Bool-example.trm3.ps Pico-Booleans.asf.ps \
	Pico-Booleans.sdf2.ps \
	debug-menu.ps edit-menu.ps file-menu.ps graph-menu.ps help-menu.ps \
	meta-Bool-example.ps meta-Pico-syntax.ps \
	meta-env-menu1.ps meta-env-menu2.ps meta-pico.ps \
	meta-start.ps module-menu.ps move-menu.ps new-open.ps open-file.ps \
	printer-setup.ps reduct.out.ps viewer.ps newarch.eps

PDFJES = Bool-example-asf.pdf Bool-example-sdf2.pdf Bool-example-trm.pdf \
	Bool-example-trm2.pdf Bool-example-trm3.pdf Pico-Booleans-asf.pdf \
	Pico-Booleans-sdf2.pdf \
	debug-menu.pdf edit-menu.pdf file-menu.pdf graph-menu.pdf help-menu.pdf \
	meta-Bool-example.pdf meta-Pico-syntax.pdf \
	meta-env-menu1.pdf meta-env-menu2.pdf meta-pico.pdf \
	meta-start.pdf module-menu.pdf move-menu.pdf new-open.pdf open-file.pdf \
	printer-setup.pdf reduct-out.pdf viewer.pdf newarch.pdf


CLEANFILES = manual.{aux,bbl,blg,dvi,ilg,ind,idx,log,ps,pdf,toc}

manual: asf+sdf-user-manual.pdf

manual.dvi: $(MANUAL)

spell:
	detex manual.ltx | spell -b +words.txt

asf+sdf-user-manual.ps: manual.dvi $(PSJES)
	makeindex manual.idx ;\
	latex manual.ltx ;\
	dvips -o $@ $<

asf+sdf-user-manual.pdf: $(MANUAL) $(PDFJES)
	makeindex manual.idx ;\
	pdflatex manual.ltx
