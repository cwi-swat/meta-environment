# $Id$

include $(top_srcdir)/Makefile.meta

USER_CONFIGURATION = "./meta.buttons"

INCLUDES = \
	$(ATERM_CFLAGS) \
	$(TOOLBUSLIB_CFLAGS) \
	$(CONFIG_SUPPORT_CFLAGS) 

EXTRA_DIST += \
	user-configuration.tb.src

bin_PROGRAMS = configmanager

noinst_HEADERS = \
	configmanager.h

pkgdata_DATA = \
	configuration-manager.idef \
	user-configuration.tb

CLEANFILES += \
	user-configuration.tb \
	${noinst_SCRIPTS} \
	${bin_SCRIPTS}

configmanager_SOURCES = \
	configuration-manager.idef \
	configmanager.c 

configmanager_LDADD = \
	$(CONFIG_SUPPORT_LIBS) \
	$(TOOLBUSLIB_LIBS) \
	$(ATERM_LIBS) 

%.tb: %.tb.src Makefile
	sed 's@__USER_CONFIGURATION__@$(USER_CONFIGURATION)@g;' < $< > $@
	   
