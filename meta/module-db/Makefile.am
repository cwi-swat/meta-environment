# $Id$

include $(top_srcdir)/make_rules

bin_PROGRAMS		= module-db
data_DATA		= module-db.idef

EXTRA_DIST		= module-db.idef

CLEANFILES		= module-db.tifs module-db.tif.c module-db.tif.h

noinst_HEADERS		= module-db.tif.h module-db.h
module_db_SOURCES	= module-db.tif.c module-db.c renaming-symbols.c

module_db_LDADD		= -L$(SDF_SUPPORT)/lib -lSDFME \
			-L$(ASF_SUPPORT)/lib -lASFME \
			-L$(PT_SUPPORT)/lib -lmept \
			-L$(TOOLBUS)/lib -lATB \
			-L$(ATERM)/lib -lATerm \
			$(SOCKLIBS)

INCLUDES	        = -I$(PT_SUPPORT)/include \
			-I$(TOOLBUS)/include  \
			-I$(ATERM)/include  \
			-I$(ASF_SUPPORT)/include \
			-I$(SDF_SUPPORT)/include
