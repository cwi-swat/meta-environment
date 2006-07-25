# $Id$

include $(top_srcdir)/Makefile.meta

bin_PROGRAMS = in-output
pkgdata_DATA = in-output.idef

EXTRA_DIST = in-output.idef.src

noinst_HEADERS = in-output.tif.h 

INCLUDES = \
	-I$(top_srcdir)/lib \
	$(ERROR_SUPPORT_CFLAGS) \
	$(CONFIG_SUPPORT_CFLAGS) \
	$(TOOLBUSLIB_CFLAGS) \
	$(ATERM_CFLAGS) 

in_output_SOURCES = \
	in-output.tif.c \
	main.c

in_output_LDADD = \
	-L$(top_builddir)/lib -lIOAPI \
	$(ERROR_SUPPORT_LIBS) \
	$(CONFIG_SUPPORT_LIBS) \
	$(TOOLBUSLIB_LIBS) \
	$(ATERM_LIBS) 

%.idef: %.idef.src Makefile
	sed 's@__PREFIX__@${prefix}@g' < $< > $@

if MAINTAINER_MODE

CLEANFILES = in-output.tifs in-output.idef

else

CLEANFILES = in-output.idef

endif
