EXTRA_DIST = generic-adapter.idef gen-adapter.guide.tex

bin_PROGRAMS = gen-adapter bc-adapter
pkgdata_DATA = generic-adapter.idef

gen_adapter_SOURCES = gen-adapter.c
gen_adapter_LDADD = -L$(TOOLBUSLIB)/lib -ltb

bc_adapter_SOURCES = bc-adapter.c
bc_adapter_LDADD = -L$(TOOLBUSLIB)/lib -ltb

INCLUDES = -I$(TOOLBUSLIB)/include

