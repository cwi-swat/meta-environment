# $Id$

include $(top_srcdir)/make_rules

EXTRA_DIST		= se.idef

bin_PROGRAMS		= se
pkgdata_DATA		= se.idef

noinst_HEADERS		= area.h editor.h focus.h path.h sort.h tree.h \
			EditorData.h EditorData_dict.h length.h

CLEANFILES		= se.tifs se.tif.c se.tif.h

se_SOURCES		= se.tif.c EditorData.c EditorData_dict.c se.c \
			area.c editor.c focus.c path.c sort.c tree.c length.c

se_LDADD		= -L$(PT_SUPPORT)/lib -lmept \
			-L$(TOOLBUSLIB)/lib -lATB \
			-L$(ATERM)/lib -lATerm \
			$(SOCKLIBS)

INCLUDES		= -I$(PT_SUPPORT)/include \
			-I$(ATERM)/include \
			-I$(TOOLBUSLIB)/include

# Only useful for maintainers having 'apigen'
api: EditorData.adt
	adt-to-c \
	--compat-term \
	--prefix SE_  \
	--prologue EditorData.pro  \
	--input $<
