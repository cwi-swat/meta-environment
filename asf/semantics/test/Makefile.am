SUBDIRS=eqs input output c-code

TEST_MODULES=Bracket \
             Collect \
             Func \
             IterN \
             LexConcat \
             List \
             Memo-Pico-typecheck \
             NumberTree \
             OutermostList \
             Perm \
             Pico-typecheck \
             Pico-eval \
             Pico-set \
             ReturnsList \
             SetAndElem \
             Traversal-Typecheck \
             Tuple

TEST_MODULES_ASFE_ONLY=Combination-Typecheck

ASFC=${top_builddir}/asfc/src/asfc
ASFE=${top_builddir}/asfe/src/asfe
ATRMANNOS=${ATERM}/bin/atrmannos
ATDIFF=${ATERM}/bin/atdiff
EQS=${srcdir}/eqs
IN=${srcdir}/input
OUT=${srcdir}/output
CODE=${srcdir}/c-code

EXTRA_DIST=README
CLEANFILES = *.out *.c ${TEST_MODULES}

check: ${TEST_MODULES:=.test} ${TEST_MODULES_ASFE_ONLY:=.asfe.test}
	rm -f *.out *.c

asfe.test: ${TEST_MODULES:=.asfe.test} ${TEST_MODULES_ASFE_ONLY:=.asfe.test}
asfc.test: ${TEST_MODULES:=.asfc.test} 

%.test: %.asfe.test %.asfc.test
	@printf "Testing $*, comparing asfe and asfc: "
	@set -e; for i in *.asfc.out; do \
          ${ATDIFF} $$i `basename $$i .asfc.out`.asfe.out ;\
          printf "."; \
	done;
	@printf "\n"
	rm -f $* *.out *.c

%.asfe.test: 
	@printf "Testing $* with asfe: "
	@set -e; for i in ${IN}/$*.*.pt; do \
	  ${ASFE} -l -e ${EQS}/$*.eqs -i $$i | \
          ${ATRMANNOS} -a -o `basename $$i`.asfe.out; \
          ${ATDIFF} `basename $$i`.asfe.out ${OUT}/`basename $$i` ; \
          printf "."; \
	done;
	@printf "\n"

%.asfc.test: 
	@printf "Testing $* with asfc: "
	@${ASFC} -c -i ${EQS}/$*.eqs -n $* -o $*.c
#	@diff $*.c ${CODE}/$*.c 
	@set -e; for i in ${IN}/$*.*.pt; do \
	  $* -i $$i -o `basename $$i`.asfc.out; \
          ${ATDIFF} `basename $$i`.asfc.out ${OUT}/`basename $$i` ; \
          printf "."; \
        done;
	@printf "\n"
