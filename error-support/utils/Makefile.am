include $(top_srcdir)/Makefile.meta

SUBDIRS = lift-error lower-error error-diff

pkgdata_DATA = error-support.idef

bin_PROGRAMS = \
	error-support

AM_CPPFLAGS += \
	-I$(top_srcdir)/lib \
	$(ATERM_CFLAGS) \
	$(TOOLBUSLIB_CFLAGS)

error_support_SOURCES = \
	error-support.idef \
	main.c 


error_support_LDADD = \
	-L../lib -lErrorAPI \
	$(TOOLBUSLIB_LIBS) \
	$(ATERM_LIBS)

