# $Id$

include $(top_srcdir)/make_rules

bin_PROGRAMS = in-output
pkgdata_DATA = in-output.idef

EXTRA_DIST = in-output.idef.src

noinst_HEADERS = in-output.tif.h 

INCLUDES = \
	-I$(ERROR_SUPPORT)/include \
	-I$(CONFIG_SUPPORT)/include \
	-I$(TOOLBUSLIB)/include \
	-I$(ATERM)/include

in_output_SOURCES = \
	in-output.tif.c \
	main.c

in_output_LDADD = \
	-L$(ERROR_SUPPORT)/lib -lErrorAPI \
	-L$(CONFIG_SUPPORT)/lib -lConfigAPI \
	-L$(TOOLBUSLIB)/lib -lATB \
	-L$(ATERM)/lib -lATerm \
	$(SOCKLIBS)

%.idef: %.idef.src Makefile
	sed 's@__PREFIX__@${prefix}@g' < $< > $@

if MAINTAINER_MODE

CLEANFILES = in-output.tifs

endif
