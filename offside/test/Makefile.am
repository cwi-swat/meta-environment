EXTRA_DIST = $(wildcard *.sdf) $(wildcard *.out) meta.conf

DEFS=Definitions

TESTS=$(foreach f, ${DEFS}, $f.sh)

%.sh: Makefile
	@(echo "set -e" ; \
	echo "${META}/bin/pt-dump -m $* -o $*.trm.tbl" ;\
	echo "${SGLR}/bin/sglr -p $*.trm.tbl -i $*.trm | \
              ../src/offside -o $*.tst" ;\
        echo "${ATERM}/bin/atdiff $*.tst $*.out" ) > $@ && chmod +x $@

CLEANFILES += $(TESTS) $(foreach f, ${DEFS}, $f.trm.tbl)
         
