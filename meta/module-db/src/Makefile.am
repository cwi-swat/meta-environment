# $Id$

include $(top_srcdir)/make_rules

bin_PROGRAMS		= term-base
pkgdata_DATA		= term-base.idef

EXTRA_DIST		= term-base.idef

noinst_HEADERS		= term-base.tif.h module-store.h
term_base_SOURCES	= term-base.tif.c term-base.c module-store.c

term_base_LDADD	= -L./tables -ltables \
	   	  -L$(TOOLBUSLIB)/lib -lATB \
	    	  -L$(ATERM)/lib -lATerm \
		  $(SOCKLIBS)

INCLUDES	        =  -I./tables \
                        -I$(PT_SUPPORT)/include \
			-I$(TOOLBUSLIB)/include  \
			-I$(ATERM)/include  \
			-I$(SDF_SUPPORT)/include
