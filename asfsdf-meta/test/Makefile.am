EXTRA_DIST = $(wildcard *.sdf *.asf) meta.conf.src

TEST_SPECS=Basic Demo

TESTS=$(foreach s, ${TEST_SPECS}, $s.dump.sh)

EQSDUMP=${top_builddir}/src/eqs-dump
PTDUMP=${top_builddir}/src/pt-dump

%.dump.sh: Makefile meta.conf
	@(echo '#! /bin/sh';\
	echo 'set -e' ;\
	echo '${EQSDUMP} -m $* -o $*.eqs' ;\
	echo '${PTDUMP} -m $* -o $*.trm.tbl') > $@ && chmod +x $@

meta.conf: meta.conf.src Makefile
	sed 's@__SRCDIR__@${srcdir}@g' < $< > $@

CLEANFILES=*.sh *.eqs *.tbl meta.conf
