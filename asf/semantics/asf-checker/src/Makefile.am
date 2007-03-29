# $Id$

include $(top_srcdir)/Makefile.meta

bin_PROGRAMS = asfchecker

pkgdata_DATA = asfchecker.idef

noinst_HEADERS 	= equationChecker.h statistics.h

AM_CPPFLAGS += \
	-I$(top_srcdir)/semantics/asf-operations/src \
	$(ASC_SUPPORT_CFLAGS)

asfchecker_SOURCES = \
	asfchecker.idef \
	main.c \
	equationChecker.c \
	statistics.c

asfchecker_LDADD   = \
	-L$(top_builddir)/semantics/asf-operations/src -lasfnormalization \
	$(ASC_SUPPORT_LIBS) \
	$(ERROR_SUPPORT_LIBS) 
