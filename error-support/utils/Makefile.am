include $(top_srcdir)/Makefile.meta

SUBDIRS = lift-error lower-error error-diff

pkgdata_DATA = error-support.idef

bin_PROGRAMS = \
	error-support \
	display-error

AM_CPPFLAGS += \
	-I$(top_srcdir)/lib \
	$(ATERM_CFLAGS) \
	$(TOOLBUSLIB_CFLAGS)

error_support_SOURCES = \
	error-support.isrc \
	main.c 

error_support_LDADD = \
	-L../lib -lErrorAPI \
	$(TOOLBUSLIB_LIBS) \
	$(ATERM_LIBS)

display_error_SOURCES = \
	display-error.c

display_error_LDADD = \
	-L../lib -lErrorAPI \
	$(ATERM_LIBS)
