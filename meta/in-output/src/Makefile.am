# $Id$

include $(top_srcdir)/make_rules

bin_PROGRAMS = in-output
pkgdata_DATA = in-output.idef

EXTRA_DIST = in-output.idef

noinst_HEADERS = in-output.tif.h 

INCLUDES = \
	-I$(ERROR_SUPPORT)/include \
	-I$(TOOLBUSLIB)/include \
	-I$(ATERM)/include

in_output_SOURCES = \
	in-output.tif.c \
	main.c

in_output_LDADD = \
	-L$(ERROR_SUPPORT)/lib -lErrorAPI \
	-L$(TOOLBUSLIB)/lib -lATB \
	-L$(ATERM)/lib -lATerm \
	$(SOCKLIBS)
