# $Id$

include $(top_srcdir)/make_rules

bin_PROGRAMS      = in-output
data_DATA         = in-output.idef

EXTRA_DIST        = in-output.idef

CLEANFILES        = in-output.tifs in-output.tif.c in-output.tif.h

in_output_SOURCES = in-output.c
in_output_LDADD   = in-output.tif.o -L$(ATERM)/lib -lATB -lATerm $(SOCKLIBS)

INCLUDES          = -I$(ATERM)/include

in-output.o: in-output.tif.h
