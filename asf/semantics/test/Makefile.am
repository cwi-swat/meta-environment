SUBDIRS=eqs input output c-code
EXTRA_DIST=README

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
             Tuple \
             Combination-Typecheck

ASFC=${top_builddir}/asfc/src/asfc
ASFE=${top_builddir}/asfe/src/asfe
ATRMANNOS=${ATERM}/bin/atrmannos
ATDIFF=${ATERM}/bin/atdiff
EQS=${srcdir}/eqs
IN=${srcdir}/input
OUT=${srcdir}/output
CODE=${srcdir}/c-code

CLEANFILES = *.out *.c ${TEST_MODULES} *.sh

TESTS = $(foreach f, ${TEST_MODULES}, $f.asfe.sh $f.asfc.sh $f.diff.sh ) 

%.diff.sh: 
	@(echo 'set -e' ; \
         echo 'for i in $*.*.asfc.out; do'; \
         echo ' ${ATDIFF} $$i `basename $$i .asfc.out`.asfe.out ' ;\
         echo ' rm -f $$i `basename $$i .asfc.out`.asfe.out ' ;\
	 echo 'done' ) > $@ && chmod +x $@

%.asfe.sh:
	@(echo 'set -e'  ;\
         echo 'for i in ${IN}/$*.*.pt; do' ; \
	 echo '  ${ASFE} -l -e ${EQS}/$*.eqs -i $$i | \'; \
         echo '  ${ATRMANNOS} -a -o `basename $$i`.asfe.out ' ; \
         echo '  ${ATDIFF} `basename $$i`.asfe.out ${OUT}/`basename $$i`' ; \
	 echo 'done' ) > $@ && chmod +x $@

%.asfc.sh: 
	@(echo 'set -e' ; \
         echo '${ASFC} -c -i ${EQS}/$*.eqs -n $* -o $*.c'; \
	 echo 'for i in ${IN}/$*.*.pt; do ' ;\
	 echo ' $* -i $$i -o `basename $$i`.asfc.out '; \
         echo ' ${ATDIFF} `basename $$i`.asfc.out ${OUT}/`basename $$i` '; \
         echo 'done' ) > $@ && chmod +x $@
