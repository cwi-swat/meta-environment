EXTRA_DIST = $(wildcard *.sdf *.asf) meta.conf.src

TEST_SPECS=Basic Demo

TESTS=$(foreach s, ${TEST_SPECS}, $s.dump.sh)

GENMETA=${META}/bin/generic-meta -I ${ASF}/share/asf -p ${ASF}/bin \
	-I ${top_builddir}/meta-scripts -I ${top_srcdir}/meta-scripts
TIMEOUT=-t 300
EQSDUMP=${GENMETA} ${TIMEOUT} -S ${META}/share/meta/start-meta-eqs-dumper.tb
PTDUMP=${GENMETA} ${TIMEOUT} -S ${META}/share/meta/start-meta-pt-dumper.tb

%.dump.sh: Makefile meta.conf
	@(echo '#! /bin/sh';\
	echo 'set -e' ;\
	echo 'rm -f $*.eqs $*.trm.tbl' ;\
	echo '${EQSDUMP} -m $* -o $*.eqs' ;\
	echo '${PTDUMP} -m $* -o $*.trm.tbl' ;\
	echo 'test -f $*.eqs';\
	echo 'test -f $*.trm.tbl') > $@ && chmod +x $@

meta.conf: meta.conf.src Makefile
	sed 's@__SRCDIR__@${srcdir}@g' < $< > $@

CLEANFILES=*.sh *.eqs *.tbl meta.conf
