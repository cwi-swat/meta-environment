# $Id$

include $(top_srcdir)/Makefile.meta

USER_CONFIGURATION = "./meta.buttons"

INCLUDES = \
	$(ATERM_CFLAGS) \
	$(TOOLBUSLIB_CFLAGS) \
	$(CONFIG_SUPPORT_CFLAGS) \

EXTRA_DIST = \
	configuration-manager.idef.src \
	user-configuration.tb.src

bin_PROGRAMS = configmanager

noinst_HEADERS = \
	configuration-manager.tif.h \
	configmanager.h

pkgdata_DATA = \
	configuration-manager.idef \
	user-configuration.tb

CLEANFILES = \
	user-configuration.tb \
	configuration-manager.idef \
	${noinst_SCRIPTS} \
	${bin_SCRIPTS}

configmanager_SOURCES = \
	configmanager.c \
	configuration-manager.tif.c

configmanager_LDADD = \
	$(CONFIG_SUPPORT_LIBS) \
	$(TOOLBUSLIB_LIBS) \
	$(ATERM_LIBS) 

absolute_srcdir=$(shell cd ${srcdir}; pwd)

%.tb: %.tb.src Makefile
	sed 's@__USER_CONFIGURATION__@$(USER_CONFIGURATION)@g;' < $< > $@
	   
%.idef: %.idef.src Makefile
	sed 's@__PREFIX__@${prefix}@g' < $< > $@

