
bin_PROGRAMS=lower-error

INCLUDES=\
	-I${top_srcdir}/lib \
	-I${ATERM}/include

if MAINTAINER_MODE
ATERM_LIB = ATerm-dbg
else
ATERM_LIB = ATerm
endif

lower_error_SOURCES=\
	lower-error.c

lower_error_LDADD=\
	-L${top_builddir}/lib -lErrorAPI \
	-L${ATERM}/lib -l$(ATERM_LIB)

ERRORS=example
EXTRA_DIST=$(wildcard *.ref) $(wildcard *.tree)

GENERATED_BY_TESTS = \
	example.trm

CLEANFILES = $(TESTS) $(GENERATED_BY_TESTS)

TESTS=$(foreach e, ${ERRORS}, $e.sh)

%.sh: Makefile
	@(	echo "#! /bin/sh";\
		echo "set -e";\
		echo "./lower-error -i ${srcdir}/$*.tree -o $*.trm";\
		echo "${ATERM}/bin/atdiff ${srcdir}/$*.ref $*.trm"\
	) > $@ && chmod +x $@	
