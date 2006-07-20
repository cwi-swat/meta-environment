# $Id$

SUBDIRS=terms

TESTS=mept-test

check_PROGRAMS=mept-test

if MAINTAINER_MODE
ATERM_LIB = ATerm-dbg
else
ATERM_LIB = ATerm
endif

mept_test_SOURCES=mept-test.c
mept_test_LDADD=\
	-L$(top_builddir)/libmept -lmept\
	-L$(ERROR_SUPPORT)/lib -lLocationAPI \
	-L$(top_builddir)/test/terms -ltestTerms \
	-L$(ATERM)/lib -l$(ATERM_LIB)

INCLUDES =\
	-I${top_srcdir}/libmept\
	-I${top_srcdir}/test/terms\
	-I${ERROR_SUPPORT}/include \
	-I${ATERM}/include
