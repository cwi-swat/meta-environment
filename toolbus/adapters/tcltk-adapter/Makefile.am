bin_PROGRAMS = tcltk-adapter
data_DATA    = tcltk.tcl tide.tcl
noinst_DATA  = adapters.ps


EXTRA_DIST   = tcltk-adapter.c.tex tcltk-adapter.guide.tex test.tcl.nw \
               tide.tcl.nw adapters.fig standalone.tcl tcltk.tcl tide.tcl \
               adapters.ps

tcltk_adapter_SOURCES = tcltk-adapter.c tcltk-tide.c tcltk-tide.h
tcltk_adapter_LDADD   = -L$(TCLTK)/lib -ltk8.0 -ltcl8.0 \
                        -L$(x_libraries) -lX11 -ldl \
                        -L$(ATERM)/lib -lATB -lATerm

CLEANFILES   = adapters.ps
TCLTK_DEFS   = -DLIBDIR=\"$(datadir)\"

INCLUDES     = -I$(TCLTK)/include -I$(ATERM)/include $(TCLTK_DEFS) \
               $(TIDEINC) $(TIDEDEF)


% %.tex : %.nw
	$(NOWEB) $<

adapters.ps: adapters.fig
	fig2dev -Lps adapters.fig adapters.ps

