

lib_LIBRARIES			= libtide-adapter.a

include_HEADERS			= TA.h TA_dict.h tide-adapter.h tide-common.h
libtide_adapter_a_SOURCES	= TA.c TA_dict.c tide-adapter.c \
				debug-adapter.tif.c debug-adapter.tif.h \
				debug-adapter.c

debug-adapter.tif.c debug-adapter.tif.h: ../toolbus/tide.tifs
	tifstoc -tool debug-adapter ../toolbus/tide.tifs -prefix ta_

TA.h TA.c TA_dict.c TA_dict.h: TA.adt
	adt-to-c -i TA.adt --prefix TA_

EXTRA_DIST	= TA.adt TA.h TA.c TA_dict.h TA_dict.c

CFLAGS		= -g -Wall -O2
INCLUDES	= -I${ATERM}/include

