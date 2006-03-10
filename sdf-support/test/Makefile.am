#
# vim:ts=8
#
# $Id$
#

TESTS = pt2sdf grammars sorts

EXTRA_DIST = Booleans.pt Layout.pt BoolTerm.pt

noinst_PROGRAMS = ${TESTS}

AM_CFLAGS = -g -Wall -O2

INCLUDES = \
	-I${top_srcdir}/lib \
	-I$(PT_SUPPORT)/include \
	-I$(ERROR_SUPPORT)/include \
	-I$(ATERM)/include \
	-DSRC_DIR=\"${srcdir}\"

pt2sdf_SOURCES = pt2sdf-test.c

if MAINTAINER_MODE
ATERM_LIB = ATerm-dbg
else
ATERM_LIB = ATerm
endif

pt2sdf_LDADD = \
	-L${top_builddir}/lib -lPT2SDF -lSDFME \
	-L$(PT_SUPPORT)/lib -lmept \
	-L$(ERROR_SUPPORT)/lib -lErrorAPI \
	-L$(ATERM)/lib -l$(ATERM_LIB)

LDLIBS = \
	-L../lib -lSDFME \
	-L$(PT_SUPPORT)/lib -lmept \
	-L$(ATERM)/lib -l$(ATERM_LIB)

grammars_SOURCES = grammars.c
grammars_LDADD = $(LDLIBS)

sorts_SOURCES = sorts.c
sorts_LDADD = $(LDLIBS)

