# $Id$

include $(top_srcdir)/make_rules

bin_PROGRAMS = configmanager

pkgdata_DATA  = configuration-manager.idef standard.meta.buttons

EXTRA_DIST = configuration-manager.idef standard.meta.buttons

#CFLAGS+= -DDISABLE_DYNAMIC_CHECKING

noinst_HEADERS = configmanager.tif.h configmanager.h
include_HEADERS = MetaButtons.h MetaButtons_dict.h 

configmanager_SOURCES = \
	MetaButtons.c \
	MetaButtons_dict.c \
	configmanager.c \
	configmanager.tif.c

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
	/users/jive/PROGRAMS/apigen-1.5/bin/adt-to-c -i buttons.adt --prefix MB_ -o MetaButtons
