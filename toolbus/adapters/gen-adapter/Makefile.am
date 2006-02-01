EXTRA_DIST = generic-adapter.idef.src gen-adapter.guide.tex

CLEAN_FILES = generic-adapter.idef

bin_PROGRAMS = gen-adapter bc-adapter
pkgdata_DATA = generic-adapter.idef

gen_adapter_SOURCES = gen-adapter.c
gen_adapter_LDADD = -L$(top_builddir)/libtb -ltb

bc_adapter_SOURCES = bc-adapter.c
bc_adapter_LDADD = -L$(top_builddir)/libtb -ltb

INCLUDES = -I$(top_srcdir)/libtb

%.idef: %.idef.src Makefile
	sed 's@__PREFIX__@${prefix}@g' < $< > $@



