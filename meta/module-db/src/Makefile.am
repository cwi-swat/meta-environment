# $Id$

include $(top_srcdir)/make_rules

SUBDIRS = tables sdf-operations

bin_PROGRAMS		= module-db
pkgdata_DATA		= module-db.idef

EXTRA_DIST		= module-db.idef

noinst_HEADERS		= module-db.h module-db.tif.h module-store.h \
                          extension-store.h
module_db_SOURCES	= main.c module-db.tif.c module-db.c \
                          module-store.c \
                          extension-store.c

module_db_LDADD	= -L./tables -ltables \
                  -L./sdf-operations -lsdf-operations \
                  -L$(SDF_SUPPORT)/lib -lSDFME \
                  -L$(PT_SUPPORT)/lib -lmept \
	   	  -L$(TOOLBUSLIB)/lib -lATB \
	    	  -L$(ATERM)/lib -lATerm \
		  $(SOCKLIBS)

INCLUDES	        =  -I./tables \
                  	-I./sdf-operations \
                        -I$(PT_SUPPORT)/include \
			-I$(TOOLBUSLIB)/include  \
			-I$(ATERM)/include  \
			-I$(SDF_SUPPORT)/include
