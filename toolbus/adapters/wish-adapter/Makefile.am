bin_PROGRAMS         = wish-adapter
data_DATA            = tb.tcl

EXTRA_DIST           = wish-adapter.c.tex wish-adapter.c.nw \
                       wish-adapter.guide.tex tb.tcl

wish_adapter_SOURCES = wish-adapter.c
wish_adapter_LDADD   = -L$(top_builddir)/libtb -ltb


WISH_DEFS            = -DWISH=\"$(WISH)\" \
                       -DTBTCL=\"$(datadir)/tb.tcl\" \
                       -DLIBDIR=\"$(datadir)\"

INCLUDES             = -I$(top_srcdir)/libtb $(WISH_DEFS)

%.c %.c.tex : %.c.nw
	$(NOWEB) $<
