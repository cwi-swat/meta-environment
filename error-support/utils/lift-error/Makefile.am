
bin_PROGRAMS=lift-error

INCLUDES=\
	-I${ATERM}/include\
	-I${top_srcdir}/lib

lift_error_SOURCES=\
	lift-error.c

lift_error_LDADD=\
	-L${ATERM}/lib -lATerm\
	-L${top_builddir}/lib -lErrorAPI

ERRORS=example
EXTRA_DIST=$(wildcard *.ref) $(wildcard *.trm)
CLEANFILES=$(TESTS)

TESTS=$(foreach e, ${ERRORS}, $e.sh)

%.sh: Makefile
	@(	echo "#! /bin/sh";\
		echo "set -e";\
		echo "./lift-error -i ${srcdir}/$*.trm -o $*.tree";\
		echo "${ATERM}/bin/atdiff ${srcdir}/$*.ref $*.tree"\
	) > $@ && chmod +x $@	
