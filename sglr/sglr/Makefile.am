# $Id$

include ../make_rules

bin_PROGRAMS      = sglr
pkgdata_DATA      = sglr.idef
# noinst_PROGRAMS   = sglr-prof

SRCS              = sglr-main.c  getopt.c getopt1.c 
HDRS              = getopt.h

sglr_SOURCES      = $(SRCS) $(HDRS)
sglr_LDADD        = -L${top_builddir}/libsglr -lsglr \
                    -L${top_builddir}/libtree2dot -ltree2dot \
                    -L${top_builddir}/liba2toa1 -la2toa1 \
                    -L$(ATERMLIB) -lATerm-${CC} -lAsFix-${CC} -lATB-${CC} \
                    $(SOCKLIBS)

# sglr_prof_SOURCES = $(HDRS)
# sglr_prof_LDFLAGS = -pg
# sglr_prof_LDADD   = $(SRCS:.c=-prof.o) \
#                     -L${top_builddir}/libsglr -lsglr-prof \
#                     -L${top_builddir}/libtree2dot -ltree2dot-prof \
#                     -L${top_builddir}/liba2toa1 -la2toa1-prof \
#                     -L$(ATERMLIB) -lATerm-prof -lAsFix-prof -lATB-prof \
#                     $(SOCKLIBS)

EXTRA_DIST = sglr.idef

# remove built files during "make clean"
CLEANFILES = sglr.tif.c sglr.tif.h

# extra dependency for sglr-main.c to generate sglr.tif.[ch]
${srcdir}/sglr-main.c : sglr.tif.c sglr.tif.h
