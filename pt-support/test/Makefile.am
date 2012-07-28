# $Id$

include $(top_srcdir)/Makefile.meta

SUBDIRS=terms

TESTS=mept-test

check_PROGRAMS=mept-test

mept_test_SOURCES=mept-test.c
mept_test_LDADD=\
	-L$(top_builddir)/libmept -lmept\
	$(ERROR_SUPPORT_LIBS) \
	-L$(top_builddir)/test/terms -ltestTerms \
	$(ATERM_LIBS) 

INCLUDES =\
	-I$(top_srcdir)/libmept\
	-I$(top_builddir)/test/terms\
	$(ERROR_SUPPORT_CFLAGS) \
	$(ATERM_CFLAGS)
