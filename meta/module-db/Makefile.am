# $Id$

include $(top_srcdir)/make_rules

bin_PROGRAMS		= module-db
pkgdata_DATA		= module-db.idef

EXTRA_DIST		= module-db.idef

CLEANFILES		= module-db.tifs module-db.tif.c module-db.tif.h

noinst_HEADERS		= module-db.tif.h module-db.h \
                          MDB.h MDB_dict.h renaming-imports.h
module_db_SOURCES	= module-db.tif.c module-db.c \
                          MDB.c MDB_dict.c renaming-imports.c

module_db_LDADD		= -L$(SDF_SUPPORT)/lib -lSDFME \
			-L$(ASF_SUPPORT)/lib -lASFME \
			-L$(PT_SUPPORT)/lib -lmept \
			-L$(TOOLBUSLIB)/lib -lATB \
			-L$(ATERM)/lib -lATerm \
			$(SOCKLIBS)

INCLUDES	        = -I$(PT_SUPPORT)/include \
			-I$(TOOLBUSLIB)/include  \
			-I$(ATERM)/include  \
			-I$(ASF_SUPPORT)/include \
			-I$(SDF_SUPPORT)/include
