# $Id$

include ../make_rules

bin_PROGRAMS     = tree2dot

SRCS             = tree2dot-main.c
HDRS             =

tree2dot_SOURCES = $(SRCS) $(HDRS)

LDADD            =  -L${top_builddir}/libtree2dot -ltree2dot \
                    -L${top_builddir}/libsglr -lsglr \
                    -L${top_builddir}/liba2toa1 -la2toa1 \
                    -L$(ATERMLIB) -lATerm-${CC} -lAsFix-${CC} -lATB-${CC} \
                    $(SOCKLIBS)

TESTS = not_implemented_yet
