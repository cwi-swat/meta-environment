# $Id$

include $(top_srcdir)/make_rules

bin_PROGRAMS		= module-db
pkgdata_DATA		= module-db.idef

EXTRA_DIST		= module-db.idef

noinst_HEADERS		= module-db.tif.h module-db.h \
                          MDB.h MDB_dict.h module-refactorings.h
module_db_SOURCES	= module-db.tif.c module-db.c \
                          MDB.c MDB_dict.c module-refactorings.c

module_db_LDADD		= -L$(SDF_SUPPORT)/lib -lSDFME \
			-L$(PT_SUPPORT)/lib -lmept \
			-L$(TOOLBUSLIB)/lib -lATB \
			-L$(ATERM)/lib -lATerm \
			$(SOCKLIBS)

INCLUDES	        = -I$(PT_SUPPORT)/include \
			-I$(TOOLBUSLIB)/include  \
			-I$(ATERM)/include  \
			-I$(SDF_SUPPORT)/include
