# $Id$


include $(top_srcdir)/make_rules

bin_PROGRAMS      = configmanager

data_DATA         = configmanager.idef

EXTRA_DIST        = configmanager.idef

CLEANFILES        = configmanager.tif.c configmanager.tif.h configmanager.tifs

configmanager_SOURCES = configmanager.c configmanager.h
configmanager_LDADD   = configmanager.tif.o \
			-L$(TOOLBUSLIB)/lib -lATB \
			-L$(ATERM)/lib -lATerm \
			$(SOCKLIBS)

INCLUDES		= -I$(ATERM)/include \
			-I$(TOOLBUSLIB)/include \
			-DBINDIR=\"$(bindir)\"

configmanager.o : configmanager.tif.h
