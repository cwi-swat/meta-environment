#
# vim:ts=8
#
# $Id$
#

include $(top_srcdir)/Makefile.meta

TESTS = $(check_PROGRAMS)
check_PROGRAMS = pt2sdf grammars sorts 

EXTRA_DIST += Booleans.pt Layout.pt BoolTerm.pt

AM_CPPFLAGS += \
	-I$(top_srcdir)/lib \
	$(PT_SUPPORT_CFLAGS) \
	$(ERROR_SUPPORT_CFLAGS) \
	$(ATERM_CFLAGS) \
	-DSRC_DIR=\"$(srcdir)\"

pt2sdf_SOURCES = pt2sdf-test.c

pt2sdf_LDADD = \
	-L$(top_builddir)/lib -lPT2SDF -lSDFME \
	$(PT_SUPPORT_LIBS) \
	$(ERROR_SUPPORT_LIBS) \
	$(ATERM_LIBS) 

LDLIBS = \
	-L$(top_builddir)/lib -lSDFME \
	$(PT_SUPPORT_LIBS) \
	$(ATERM_LIBS)

grammars_SOURCES = grammars.c
grammars_LDADD = $(LDLIBS)

sorts_SOURCES = sorts.c
sorts_LDADD = $(LDLIBS)
