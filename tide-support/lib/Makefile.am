include $(top_srcdir)/Makefile.meta

CLEANFILES += $(wildcard *.tifs)
EXTRA_DIST = TA.adt adapter.idef

pkgdata_DATA = adapter.idef
lib_LTLIBRARIES = libtide-adapter.la
include_HEADERS	= \
	TA.h \
	TA_dict.h \
	tide-adapter.h \
	tide-common.h

libtide_adapter_la_CPPFLAGS = $(ATERM_CFLAGS) $(TOOLBUSLIB_CFLAGS) -DDISABLE_DYNAMIC_CHECKING
libtide_adapter_la_LDFLAGS  = -avoid-version -no-undefined $(AM_LDFLAGS)
libtide_adapter_la_LIBADD   = $(ATERM_LIBS) $(TOOLBUSLIB_LIBS)
libtide_adapter_la_SOURCES = \
	TA.c \
	TA_dict.c \
	tide-adapter.c \
	debug-adapter.tif.c \
	debug-adapter.tif.h \
	debug-adapter.c

tifs:
	toolbus -gentifs adapter.idef -output adapter.idef.tifs
	tifstoc	-tool debug-adapter \
		-prefix ta_ \
		adapter.idef.tifs

regen:
	adt-to-c -i TA.adt --prefix TA_ --name TA


