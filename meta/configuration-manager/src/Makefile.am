# $Id$

include $(top_srcdir)/make_rules

KERNEL_CONFIGURATION = "$(pkgdatadir)/meta-kernel.properties"
USER_CONFIGURATION = "./meta.buttons"
LIBRARY_PATH = 

AM_CFLAGS = -DDISABLE_DYNAMIC_CHECKING

INCLUDES = \
	-I$(ATERM)/include \
	-I$(TOOLBUSLIB)/include

bin_PROGRAMS = configmanager

pkgdata_DATA = \
	configuration-manager.idef \
	kernel-configuration.tb \
	user-configuration.tb \
	meta-kernel.properties

EXTRA_DIST = \
	configuration-manager.idef \
	kernel-configuration.tb.src \
	user-configuration.tb.src \
	meta-kernel.properties

noinst_HEADERS = \
	configuration-manager.tif.h \
	configmanager.h

include_HEADERS = \
	MetaConfig.h \
	MetaConfig_dict.h 

configmanager_SOURCES = \
	MetaConfig.c \
	MetaConfig_dict.c \
	configmanager.c \
	configuration-manager.tif.c

configmanager_LDADD = \
	-L$(TOOLBUSLIB)/lib -lATB \
	-L$(ATERM)/lib -lATerm \
	$(SOCKLIBS)

%.tb: %.tb.src Makefile
	sed 's@__KERNEL_CONFIGURATION__@$(KERNEL_CONFIGURATION)@g;\
	    s@__USER_CONFIGURATION__@$(USER_CONFIGURATION)@g;' < $< > $@

api:
	adt-to-c \
		--input configuration.adt \
		--name MetaConfig \
		--prefix MC_ \
		--output . \
		--version 1.1
