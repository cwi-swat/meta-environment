DEFINITIONS = \
	Block.def \
	Pico.def \
	Sdf2.def \
	Simple.def

TESTS = $(foreach i, ${DEFINITIONS} , $i.check.sh)

INDIR=${srcdir}
REFDIR=${srcdir}
RULESDIR=${srcdir}
PTPRETTY=${top_builddir}/src/ptpretty
ATDIFF=${ATERM}/bin/atdiff

%.check.sh: Makefile
	@(echo '#!/bin/sh'  ; \
         echo 'set -e'  ; \
         echo "for i in ${INDIR}/`basename $* .def`.*.trm.pt; do" ; \
         echo '  out=`basename $$i .pt`.out'; \
         echo '  ${PTPRETTY} -s ${RULESDIR}/$*.rules -i $$i -o $${out}' ; \
         echo '  ${ATDIFF} $$i.ref $${out}' ; \
         echo 'done' ) > $@ && chmod +x $@

# This assumes sdf2table and parse-sdf2 in your PATH
regenerate:
	for i in ${srcdir}/definitions/*.def; do \
	  sdf2table -i $$i -o $$i.tbl; \
	  parse-sdf2 -i $$i -o $$i.rules; \
          for j in ${srcdir}/terms/`basename $$i .def`.*.trm; do \
            sglr -p $$i.tbl -i $$j -o $$j.pt ;\
          done; \
	done

CLEANFILES=*.check.sh *.out

EXTRA_DIST = \
	${DEFINITIONS} \
	$(wildcard *.rules)\
	$(wildcard *.pt)\
	$(wildcard *.trm)\
	$(wildcard *.ref)
