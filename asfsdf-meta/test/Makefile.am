EXTRA_DIST = $(wildcard *.sdf *.asf)

TEST_SPECS=Basic

TESTS=$(foreach s, ${TEST_SPECS}, $s.dump.sh)

EQSDUMP=${top_builddir}/src/eqs-dump
PTDUMP=${top_builddir}/src/pt-dump

%.dump.sh: Makefile
	@(echo '#! /bin/sh';\
	echo 'set -e' ;\
	echo '${EQSDUMP} -m $* -o $*.eqs' ;\
	echo '${PTDUMP} -m $* -o $*.trm.tbl') > $@ && chmod +x $@

CLEANFILES=*.sh *.eqs *.tbl
