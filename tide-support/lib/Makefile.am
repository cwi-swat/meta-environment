
INCLUDES = \
	-I${ATERM}/include \
	-I${TOOLBUSLIB}/include \
	-DDISABLE_DYNAMIC_CHECKING

lib_LIBRARIES = libtide-adapter.a

include_HEADERS	= \
	TA.h \
	TA_dict.h \
	tide-adapter.h \
	tide-common.h

libtide_adapter_a_SOURCES = \
	TA.c \
	TA_dict.c \
	tide-adapter.c \
	debug-adapter.tif.c \
	debug-adapter.tif.h \
	debug-adapter.c

pkgdata_DATA = adapter.idef

tifs:
	toolbus -gentifs adapter.idef -output adapter.idef.tifs
	tifstoc	-tool debug-adapter \
		-prefix ta_ \
		adapter.idef.tifs

regen:
	adt-to-c -i TA.adt --prefix TA_ --name TA


CLEANFILES	= *.tifs

EXTRA_DIST = \
	TA.adt \
	adapter.idef

