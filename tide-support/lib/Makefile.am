include $(top_srcdir)/Makefile.meta

EXTRA_DIST += TA.adt

pkgdata_DATA = debug-adapter.idef
lib_LTLIBRARIES = libtide-adapter.la
include_HEADERS	= \
	TA.h \
	TA_dict.h \
	tide-adapter.h \
	tide-common.h

AM_CPPFLAGS += $(ATERM_CFLAGS) $(TOOLBUSLIB_CFLAGS) -DDISABLE_DYNAMIC_CHECKING
libtide_adapter_la_LDFLAGS  = -avoid-version -no-undefined $(AM_LDFLAGS)
libtide_adapter_la_LIBADD   = $(ATERM_LIBS) $(TOOLBUSLIB_LIBS)
libtide_adapter_la_SOURCES = \
	debug-adapter.isrc \
	TA.c \
	TA_dict.c \
	tide-adapter.c \
	debug-tool.c

debug_adapter_TIF_OPTIONS=-prefix ta_

regen:
	adt-to-c -i TA.adt --prefix TA_ --name TA


