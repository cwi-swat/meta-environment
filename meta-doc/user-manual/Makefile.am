
include ${top_srcdir}/doc/general-make

MANUAL		= manual.ltx

INPUTS = ${srcdir}/doc/user-manual

PSJES = Bool-example.asf.ps Bool-example.sdf2.ps Bool-example.trm.ps \
	Bool-example.trm2.ps Bool-example.trm3.ps Pico-Booleans.asf.ps \
	Pico-Booleans.sdf2.ps compiler-dir.ps compiler-warning.ps \
	debug-menu.ps edit-menu.ps file-menu.ps graph-menu.ps help-menu.ps \
	meta-Bool-example.ps meta-Pico-syntax.ps meta-booleans.ps \
	meta-env-menu.ps meta-env-menu1.ps meta-env-menu2.ps meta-pico.ps \
	meta-start.ps module-menu.ps move-menu.ps new-open.ps open-file.ps \
	printer-setup.ps reduct.out.ps viewer.ps CobolEditor.ps newarch.eps

ELDERS = $(patsubst %,$(srcdir)/%,$(PSJES))

EXTRA_DIST	= $(MANUAL) $(PSJES) manual.ps
CLEANFILES	= manual.{aux,bbl,blg,dvi,ilg,ind,idx,log,ps,toc}

all:

doc: manual.ps

manual.dvi: $(MANUAL)

spell:
	detex manual.ltx | spell -b +words.txt

# when manual.dvi is up-to-date, it will have created manual.idx
# we need to run makeindex on this file, then re-latex and convert
# the dvi to postscript
manual.ps: manual.dvi $(PSJES)
	@if [ "a$(VPATH)" != "a" ]; then \
		cp -f ${ELDERS} . ;\
	fi
	TEXINPUTS=$$TEXINPUTS:${srcdir};\
	makeindex manual.idx ;\
	latex ${srcdir}/manual.ltx ;\
	dvips -o $@ $<

dist: manual.ps
	cp manual.ps ${DISTDIR}
