EXTRA_DIST   = TBmodule.c.tex TBmodule.c.nw \
               python-adapter.guide.tex TBmodule.c

dnl python_adapter_SOURCES = TBmodule.c
dnl python_adapter_LDADD   = -L$(top_builddir)/libtb -ltb

INCLUDES     = -I$(top_srcdir)/libtb

%.c %.c.tex : %.c.nw
	$(NOWEB) $<
