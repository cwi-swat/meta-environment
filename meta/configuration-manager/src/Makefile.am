# $Id$


include $(top_srcdir)/make_rules

bin_PROGRAMS      = configmanager

pkgdata_DATA         = configmanager.idef standard.buttons

EXTRA_DIST        = configmanager.idef standard.buttons standard.buttons.src

CFLAGS+= -DDISABLE_DYNAMIC_CHECKING

noinst_HEADERS = configmanager.tif.h configmanager.h
include_HEADERS = MetaButtons.h MetaButtons_dict.h 

configmanager_SOURCES = MetaButtons.c MetaButtons_dict.c \
                        configmanager.c  configmanager.tif.c
configmanager_LDADD   = -L$(TOOLBUSLIB)/lib -lATB \
			-L$(ATERM)/lib -lATerm \
			$(SOCKLIBS)

INCLUDES		= -I$(ATERM)/include \
			-I$(TOOLBUSLIB)/include \
			-DBINDIR=\"$(bindir)\" \
                        -DSTANDARD_BUTTONS=\"$(pkgdatadir)/standard.buttons\"
api:
	adt-to-c -i buttons.adt --prefix MB_ -o MetaButtons

standard.buttons:	standard.buttons.src Makefile
			sed 's@__ASF_LIBRARY__@${prefix}/share/asf/library/@g' < $< > $@

