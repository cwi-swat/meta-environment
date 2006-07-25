
bin_PROGRAMS=lower-error

AM_CPPFLAGS = \
	-I${top_srcdir}/lib \
	${ATERM_CFLAGS}

lower_error_SOURCES=\
	lower-error.c

lower_error_LDADD=\
	-L${top_builddir}/lib -lErrorAPI \
	${ATERM_LIBS}

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
		echo "${ATERM_PREFIX}/bin/atdiff ${srcdir}/$*.ref $*.trm"\
	) > $@ && chmod +x $@	
