# $Id$

include ${top_srcdir}/make_rules

INCLUDES         = -I$(ASC_SUPPORT)/include \
                   -I$(TOOLBUSLIB)/include \
                   -I$(PT_SUPPORT)/include \
                   -I$(SDF_SUPPORT)/include \
                   -I$(ASF_SUPPORT)/include \
                   -I$(ATERM)/include

bin_PROGRAMS = addeqssyntax

pkgdata_DATA    = addeqssyntax.idef

EXTRA_DIST   = addeqssyntax.idef addeqssyntax.tif.c addeqssyntax.tif.h 

addeqssyntax_SOURCES = addeqssyntax.c Add-Eqs-Syntax.c
addeqssyntax_LDADD   = addeqssyntax.tif.o \
                       -L$(ASC_SUPPORT)/lib -lasc-support-me \
                       -L$(SDF_SUPPORT)/lib -lSDFME \
                       -L$(ASF_SUPPORT)/lib -lASFME \
                       -L$(PT_SUPPORT)/lib -lmept \
                       -L$(TOOLBUSLIB)/lib -lATB \
                       -L$(ATERM)/lib -lATerm \
			$(SOCKLIBS)

CLEANFILES = addeqssyntax.tifs 

addeqssyntax.o: addeqssyntax.tif.h
