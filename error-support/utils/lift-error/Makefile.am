# $Id$

bin_PROGRAMS = lift-error

INCLUDES= \
	-I${top_srcdir}/lib \
	-I${ATERM}/include

if MAINTAINER_MODE
ATERM_LIB = ATerm-dbg
else
ATERM_LIB = ATerm
endif

lift_error_SOURCES=\
	lift-error.c

lift_error_LDADD=\
	-L${ATERM}/lib -l$(ATERM_LIB)\
	-L${top_builddir}/lib -lErrorAPI

ERRORS=example
EXTRA_DIST=$(wildcard *.ref) $(wildcard *.trm)

GENERATED_BY_TESTS = \
	example.tree

CLEANFILES=$(TESTS) $(GENERATED_BY_TESTS)

TESTS=$(foreach e, ${ERRORS}, $e.sh)

%.sh: Makefile
	@(	echo "#! /bin/sh";\
		echo "set -e";\
		echo "./lift-error -i ${srcdir}/$*.trm -o $*.tree";\
		echo "${ATERM}/bin/atdiff ${srcdir}/$*.ref $*.tree"\
	) > $@ && chmod +x $@	
