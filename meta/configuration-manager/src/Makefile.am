# $Id$

include $(top_srcdir)/make_rules

bin_PROGRAMS = configmanager

pkgdata_DATA  = configuration-manager.idef standard.meta.buttons

EXTRA_DIST = configuration-manager.idef standard.meta.buttons

CFLAGS+= -DDISABLE_DYNAMIC_CHECKING

noinst_HEADERS = configuration-manager.tif.h configmanager.h
include_HEADERS = MetaConfig.h MetaConfig_dict.h 

configmanager_SOURCES = \
	MetaConfig.c \
	MetaConfig_dict.c \
	configmanager.c \
	configuration-manager.tif.c

configmanager_LDADD = \
	-L$(TOOLBUSLIB)/lib -lATB \
	-L$(ATERM)/lib -lATerm \
	$(SOCKLIBS)

INCLUDES = \
	-I$(ATERM)/include \
	-I$(TOOLBUSLIB)/include \
	-DBINDIR=\"$(bindir)\" \
	-DSTANDARD_META_BUTTONS=\"$(pkgdatadir)/standard.meta.buttons\"

api:
	adt-to-c \
		--input configuration.adt \
		--name MetaConfig \
		--prefix MC_ \
		--output . \
		--verbose
