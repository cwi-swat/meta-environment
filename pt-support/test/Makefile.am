# $Id$

SUBDIRS=terms

TESTS=mept-test

noinst_PROGRAMS=mept-test

mept_test_SOURCES=mept-test.c
mept_test_LDADD=\
	-L$(top_builddir)/libmept -lmept\
	-L$(ERROR_SUPPORT)/lib -lLocationAPI \
	-L$(top_builddir)/test/terms -ltestTerms \
	-L$(ATERM)/lib -lATerm

INCLUDES =\
	-I${top_srcdir}/libmept\
	-I${top_srcdir}/test/terms\
	-I${ERROR_SUPPORT}/include \
	-I${ATERM}/include
