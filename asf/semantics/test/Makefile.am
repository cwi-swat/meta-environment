SUBDIRS=eqs input output c-code
EXTRA_DIST=README

TEST_MODULES=Bracket \
	Collect \
	Combination-Typecheck \
	Func \
	IterN \
	LexConcat \
	List \
	Lookup \
	Memo-Pico-typecheck \
	NumberTree \
	OutermostList \
	Perm \
	Pico-eval \
	Pico-set \
	Pico-typecheck \
	Pico-Xml \
	RelationsTest \
	ReturnsList \
	SetAndElem \
	Specificity \
	StarStarVar \
	Traversal-Typecheck \
	Tuple

TEST_MODULES_ASFE_ONLY=BoolAPI BoolPos Tree

ASFC=${top_builddir}/semantics/asfc/src/asfc
ASFE=${top_builddir}/semantics/asfe/src/asfe
ASFCHECKER=${top_builddir}/semantics/asf-checker/src/asfchecker
ATRMANNOS=${ATERM}/bin/atrmannos
ATDIFF=${ATERM}/bin/atdiff
EQS=${srcdir}/eqs
IN=${srcdir}/input
OUT=${srcdir}/output
CODE=${srcdir}/c-code

CLEANFILES = *.out *.c ${TEST_MODULES} *.sh

TESTS = \
	$(foreach f, ${TEST_MODULES}, $f.check.sh $f.asfe.sh $f.asfc.sh) \
	$(foreach f, ${TEST_MODULES_ASFE_ONLY}, $f.check.sh $f.asfe.sh)

%.check.sh:
	@(echo '#!/bin/sh'  ; \
	 echo 'set -e'  ; \
	 echo 'for i in ${EQS}/$*.eqs; do' ; \
	 echo '  ${ASFCHECKER} -i $$i' ; \
	 echo 'done' ) > $@ && chmod +x $@

%.asfc.sh: 
	@(echo '#!/bin/sh'  ; \
	 echo 'set -e' ; \
	 echo '${ASFC} -c -i ${EQS}/$*.eqs -n $* -o $*.c'; \
	 echo 'for i in ${IN}/$*.*.pt; do ' ;\
	 echo ' ./$* -i $$i -o `basename $$i`.asfc.out '; \
	 echo ' ${ATDIFF} `basename $$i`.asfc.out ${OUT}/`basename $$i` '; \
	 echo 'done' ) > $@ && chmod +x $@
	
%.asfe.sh:
	@(echo '#!/bin/sh'  ; \
	 echo 'set -e'  ; \
	 echo 'for i in ${IN}/$*.*.pt; do' ; \
	 echo '  ${ASFE} -l -e ${EQS}/$*.eqs -i $$i | \'; \
	 echo '  ${ATRMANNOS} -a -o `basename $$i`.asfe.out ' ; \
	 echo '  ${ATDIFF} `basename $$i`.asfe.out ${OUT}/`basename $$i`' ; \
	 echo 'done' ) > $@ && chmod +x $@

%.asfc.sh: 
	@(echo '#!/bin/sh'  ; \
	 echo 'set -e' ; \
	 echo '${ASFC} -c -i ${EQS}/$*.eqs -n $* -o $*.c'; \
	 echo 'for i in ${IN}/$*.*.pt; do ' ;\
	 echo ' ./$* -i $$i -o `basename $$i`.asfc.out '; \
	 echo ' ${ATDIFF} `basename $$i`.asfc.out ${OUT}/`basename $$i` '; \
	 echo 'done' ) > $@ && chmod +x $@
