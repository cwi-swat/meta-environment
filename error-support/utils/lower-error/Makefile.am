
bin_PROGRAMS=lower-error

INCLUDES=\
	-I${ATERM}/include\
	-I${top_srcdir}/lib

lower_error_SOURCES=\
	lower-error.c

lower_error_LDADD=\
	-L${top_builddir}/lib -lErrorAPI \
	-L${ATERM}/lib -lATerm

ERRORS=example
EXTRA_DIST=$(wildcard *.ref) $(wildcard *.tree)
CLEANFILES=$(TESTS)

TESTS=$(foreach e, ${ERRORS}, $e.sh)

%.sh: Makefile
	@(	echo "#! /bin/sh";\
		echo "set -e";\
		echo "./lower-error -i ${srcdir}/$*.tree -o $*.trm";\
		echo "${ATERM}/bin/atdiff ${srcdir}/$*.ref $*.trm"\
	) > $@ && chmod +x $@	
