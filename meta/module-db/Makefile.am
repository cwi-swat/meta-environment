
# $Id$

include $(top_srcdir)/make_rules

SUBDIRS			= test

bin_PROGRAMS		= module-db
data_DATA		= module-db.idef

EXTRA_DIST		= module-db.idef

CLEANFILES		= module-db.tifs module-db.tif.c module-db.tif.h

module_db_SOURCES	= module-db.c module-db.h renaming-symbols.c
module_db_LDADD		= module-db.tif.o \
			-L$(SDF_SUPPORT)/lib -lSDFME \
			-L$(ASF_SUPPORT)/lib -lASFME \
			-L$(PT_SUPPORT)/lib -lmept -lconversion \
			-L$(ATERM)/lib -lATB -lATerm $(SOCKLIBS)

INCLUDES	        = -I$(PT_SUPPORT)/include -I$(ATERM)/include  \
                          -I$(ASF_SUPPORT)/include -I$(SDF_SUPPORT)/include

module-db.o : module-db.tif.h renaming-symbols.c
