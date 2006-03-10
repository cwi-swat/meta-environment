# $Id$

include $(top_srcdir)/make_rules

USER_CONFIGURATION = "./meta.buttons"

INCLUDES = \
	-I$(ATERM)/include \
	-I$(TOOLBUSLIB)/include \
	-I$(CONFIG_SUPPORT)/include

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

if MAINTAINER_MODE
ATERM_LIB = ATerm-dbg
else
ATERM_LIB = ATerm
endif

configmanager_SOURCES = \
	configmanager.c \
	configuration-manager.tif.c

configmanager_LDADD = \
	-L$(CONFIG_SUPPORT)/lib -lConfigAPI \
	-L$(TOOLBUSLIB)/lib -lATB \
	-L$(ATERM)/lib -l$(ATERM_LIB) \
	$(SOCKLIBS)

absolute_srcdir=$(shell cd ${srcdir}; pwd)

%.tb: %.tb.src Makefile
	sed 's@__USER_CONFIGURATION__@$(USER_CONFIGURATION)@g;' < $< > $@
	   
%.idef: %.idef.src Makefile
	sed 's@__PREFIX__@${prefix}@g' < $< > $@

