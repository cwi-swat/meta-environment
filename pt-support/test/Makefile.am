# $Id$


TESTS=mept-test

noinst_PROGRAMS=mept-test

mept_test_SOURCES=mept-test.c
mept_test_LDADD=\
	-L$(ATERM)/lib -lATerm\
	-L$(top_builddir)/libmept -lmept                          

INCLUDES =\
	-I${top_srcdir}/libmept/include\
	-I${ATERM}/include
