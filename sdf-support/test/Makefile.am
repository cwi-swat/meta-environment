#
# vim:ts=8
#
# $Id$
#

TESTS			= pt2sdf grammars sorts

noinst_PROGRAMS		= ${TESTS}
CFLAGS			= -g -Wall -O2

LDLIBS			= -L../lib -lSDFME \
                          -L$(ATERM)/lib -lATerm
INCLUDES = \
	-I${top_srcdir}/lib \
	-I$(PT_SUPPORT)/include \
	-I$(ATERM)/include \
	-DSRC_DIR=\"${srcdir}\"

pt2sdf_SOURCES = pt2sdf-test.c
pt2sdf_LDADD = \
	-L${top_builddir}/lib -lPT2SDF -lSDFME \
	-L$(PT_SUPPORT)/lib -lmept \
	-L$(ATERM)/lib -lATerm

grammars_SOURCES	= grammars.c
grammars_LDADD		= $(LDLIBS)

sorts_SOURCES		= sorts.c
sorts_LDADD		= $(LDLIBS)

EXTRA_DIST             = Booleans.pt Layout.pt
