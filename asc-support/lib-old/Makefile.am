# $Id$

include make_rules

lib_LIBRARIES            = libasc-support.a libasc-support-gcc.a \
                           libasc-support-cc.a libasc-support-dbg.a \
                           libasc-support-prof.a 

include_HEADERS          = asc-support.h
EXTRA_DIST               = rewriter.tb

SRCS = asc-support.c asc-support.h rewriter.c
ALLSRCS = asc-support.c asc-support.h rewriter.c rewriter.tif.c

libasc_support_a_SOURCES = $(SRCS)
libasc_support_a_LIBADD  = rewriter.tif.o

libasc_support_gcc_a_SOURCES = 
libasc_support_gcc_a_LIBADD = $(ALLSRCS:.c=-gcc.o)

libasc_support_cc_a_SOURCES = 
libasc_support_cc_a_LIBADD = $(ALLSRCS:.c=-cc.o)

libasc_support_dbg_a_SOURCES = 
libasc_support_dbg_a_LIBADD = $(ALLSRCS:.c=-dbg.o)

libasc_support_prof_a_SOURCES = 
libasc_support_prof_a_LIBADD = $(ALLSRCS:.c=-prof.o)


BUILT_SOURCES            = rewriter.tif.c rewriter.tif.h

# Default include directories
INCLUDES   = -I. -I$(ATERMINC)

CLEANFILES = rewriter.tif.c rewriter.tif.h

${srcdir}/rewriter.c: rewriter.tif.h

# The output of toolbus is moved to $@ to make sure the generated
# .tifs file exists in the current directory. The ToolBus idef2tif by
# default uses the dirname of its file name argument to determine the
# location the output. This does not work correct when using VPATH in
# the Makefile.
%.tifs: %.tb
	$(TOOLBUSBIN)/toolbus -gentifs $<
	@if [ "a${VPATH}" != "a" ]; then \
	   mv ${srcdir}/$@ $@ ;\
	fi

%.tif.c %.tif.h: %.tifs
	$(ATERMBIN)/tifstoc -tool $* $<

