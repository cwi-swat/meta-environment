# $Id$

include ${top_srcdir}/make_rules

INCLUDES         = -I$(ASC_SUPPORT)/include \
                   -I$(TOOLBUSLIB)/include \
                   -I$(PT_SUPPORT)/include \
                   -I$(SDF_SUPPORT)/include \
                   -I$(ASF_SUPPORT)/include \
                   -I$(ATERM)/include

bin_PROGRAMS = addeqssyntax
man_MANS     = addeqssyntax.1

pkgdata_DATA    = addeqssyntax.idef

EXTRA_DIST   = addeqssyntax.idef addeqssyntax.tif.c addeqssyntax.tif.h \
	       addeqssyntax.pod addeqssyntax.1

addeqssyntax_SOURCES = addeqssyntax.c Add-Eqs-Syntax.c
addeqssyntax_LDADD   = addeqssyntax.tif.o \
                       -L$(ASC_SUPPORT)/lib -lasc-support-me \
                       -L$(SDF_SUPPORT)/lib -lSDFME \
                       -L$(ASF_SUPPORT)/lib -lASFME \
                       -L$(PT_SUPPORT)/lib -lmept \
                       -L$(TOOLBUSLIB)/lib -lATB \
                       -L$(ATERM)/lib -lATerm \
			$(SOCKLIBS)


CLEANFILES = addeqssyntax.tifs addeqssyntax.1

addeqssyntax.o: addeqssyntax.tif.h
