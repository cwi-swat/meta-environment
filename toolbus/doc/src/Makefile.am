#
#    ToolBus -- The ToolBus Application Architecture
#    Copyright (C) 1998-2000  Stichting Mathematisch Centrum, Amsterdam, 
#                             The  Netherlands.
#
#    This program is free software; you can redistribute it and/or modify
#    it under the terms of the GNU General Public License as published by
#    the Free Software Foundation; either version 2 of the License, or
#    (at your option) any later version.
#
#    This program is distributed in the hope that it will be useful,
#    but WITHOUT ANY WARRANTY; without even the implied warranty of
#    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
#    GNU General Public License for more details.
#
#    You should have received a copy of the GNU General Public License
#    along with this program; if not, write to the Free Software
#    Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307 USA
#
noinst_PROGRAMS      = script2latex verbatim

DOCS                 = Guide.ps Intro.ps pamflet.ps

EXTRA_DIST           = Adapter.pic Arch.pic Tifs.pic Tool.pic Guide.tex \
                       Intro.tex Syntax-T-scripts.tex pamflet.tex \
                       arch-simpel.fig auction.fig calc.fig zeeslag.fig \
                       auction-bidder.eps auction-master.eps battleships.eps \
                       calc-ui.eps

EXAMPLES             = hello1.tb.tex hello2.tb.tex hello3.tb.tex hello.c.tex \
                       hello-gen.c.tex hello.tif.c.tex pipe.tb.tex \
                       hello.tcl.tex hello.perl.tex Hello.java.tex \
                       HelloTool.java.tex hello.py.tex calc.tb.tex \
                       auction.tb.tex

CLEANFILES           = $(DOCS) *.dvi *.aux *.log *.toc adapters.tex \
                       Adapter.tex Arch.tex Tifs.tex Tool.tex \
                       arch-simpel.ps auction.ps calc.ps zeeslag.ps \
                       $(EXAMPLES)

verbatim_SOURCES     = verbatim.c
script2latex_SOURCES = script2latex.c

doc: $(DOCS) $(noinst_PROGRAMS)

Guide.dvi: everything \
	   $(EXAMPLES) Arch.tex Tifs.tex Tool.tex \
	   Adapter.tex  Guide.tex adapters.tex
	@TEXINPUTS=$(top_srcdir)/adapters:$(srcdir):$$TEXINPUTS:; \
	export TEXINPUTS; \
	latex Guide.tex; \
	latex Guide.tex; \
	latex Guide.tex

Intro.dvi: everything \
	   $(EXAMPLES) Intro.tex calc.ps auction.ps
	@TEXINPUTS=$(top_srcdir)/adapters:$(srcdir):$$TEXINPUTS:; \
	export TEXINPUTS; \
	latex Intro.tex; \
	latex Intro.tex

pamflet.dvi: everything \
	     pamflet.tex arch-simpel.ps battleships.eps zeeslag.ps
	@TEXINPUTS=$(srcdir):$$TEXINPUTS:; \
	export TEXINPUTS; \
	latex pamflet.tex ;\
	latex pamflet.tex

everything:
	cd $(top_builddir) ;\
	$(MAKE)

%.ps : %.dvi
	@TEXINPUTS=$(top_srcdir)/adapters:$(srcdir):$$TEXINPUTS:; \
	export TEXINPUTS; \
	dvips -o $@ $<

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

%.tb.tex : ${top_srcdir}/demos/hello/%.tb
	./script2latex <$< >$@

%.tex : ${top_srcdir}/demos/hello/%
	./verbatim < $< >  $@


auction.tb.tex : ${top_srcdir}/demos/auction/auction.tb
	./script2latex < $< >  $@

calc.tb.tex : ${top_srcdir}/demos/calc/calc.tb
	./script2latex < $< >  $@
