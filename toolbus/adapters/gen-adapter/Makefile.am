bin_PROGRAMS        = gen-adapter bc-adapter

EXTRA_DIST          = gen-adapter.guide.tex

gen_adapter_SOURCES = gen-adapter.c
gen_adapter_LDADD   = -L$(top_builddir)/libtb -ltb

bc_adapter_SOURCES  = bc-adapter.c
bc_adapter_LDADD    = -L$(top_builddir)/libtb -ltb

INCLUDES            = -I$(top_srcdir)/libtb

