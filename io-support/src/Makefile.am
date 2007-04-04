# $Id$

include $(top_srcdir)/Makefile.meta

bin_PROGRAMS = in-output
pkgdata_DATA = in-output.idef

INCLUDES = \
	-I$(top_srcdir)/lib \
	$(ERROR_SUPPORT_CFLAGS) \
	$(CONFIG_SUPPORT_CFLAGS) \
	$(TOOLBUSLIB_CFLAGS) \
	$(ATERM_CFLAGS) 

in_output_SOURCES = \
	in-output.isrc \
	main.c

in_output_LDADD = \
	-L$(top_builddir)/lib -lIOAPI \
	$(ERROR_SUPPORT_LIBS) \
	$(CONFIG_SUPPORT_LIBS) \
	$(TOOLBUSLIB_LIBS) \
	$(ATERM_LIBS) 
