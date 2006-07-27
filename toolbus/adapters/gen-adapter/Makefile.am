EXTRA_DIST = generic-adapter.idef.src gen-adapter.guide.tex

CLEANFILES = generic-adapter.idef

bin_PROGRAMS = gen-adapter bc-adapter
pkgdata_DATA = generic-adapter.idef

gen_adapter_SOURCES = gen-adapter.c
gen_adapter_LDADD = -L$(top_builddir)/libdeprecated-toolbus-adapter -ldeprecated-toolbus-adapter

bc_adapter_SOURCES = bc-adapter.c
bc_adapter_LDADD = -L$(top_builddir)/libdeprecated-toolbus-adapter -ldeprecated-toolbus-adapter

INCLUDES = -I$(top_srcdir)/libdeprecated-toolbus-adapter

%.idef: %.idef.src Makefile
	sed 's@__PREFIX__@${prefix}@g' < $< > $@



