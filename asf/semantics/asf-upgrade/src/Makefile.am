# $Id$

include ${top_srcdir}/make_rules

INCLUDES		= -I$(PT_SUPPORT)/include \
			-I$(ASF_SUPPORT)/include \
			-I$(TOOLBUSLIB)/include \
			-I$(ATERM)/include

bin_PROGRAMS = asfupgrader

pkgdata_DATA    = asfupgrader.idef

EXTRA_DIST   = asfupgrader.idef asfupgrader.tif.c asfupgrader.tif.h

noinst_HEADERS 	= equationUpgrader.h asfupgrader.tif.h

asfupgrader_SOURCES = asfupgrader.c equationUpgrader.c asfupgrader.tif.c
asfupgrader_LDADD   = -L$(ASF_SUPPORT)/lib -lASFME \
                -L$(PT_SUPPORT)/lib -lmept \
                -L$(TOOLBUSLIB)/lib -lATB \
                -L$(ATERM)/lib -lATerm \
                 $(SOCKLIBS)

