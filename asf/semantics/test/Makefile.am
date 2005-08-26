SUBDIRS=eqs input output c-code
EXTRA_DIST=README

TEST_MODULES=\
	Concat \
	AllTraversals \
	EmptyTraversal \
	Tree \
	NoMatch \
	Builtins\
	Bracket \
	Collect \
	Combination-Typecheck \
	Func \
	LexConcat \
	List \
	Lookup \
	Memo-Pico-typecheck \
	NumberTree \
	OutermostList \
	Pico-eval \
	Pico-set \
	Pico-typecheck \
	Pico-Xml \
	PlusStarVar \
	RelationsTest \
	ReturnsList \
	SetAndElem \
	Specificity \
	StarStarVar \
	Traversal-Typecheck \
	Tuple

# TODO: maybe really remove this test
#	ListSpecific \

noinst_SCRIPTS=.cvsignore

IGNORES="\
	*.out\
	*.sh\
	Makefile.in\
	Makefile"

.cvsignore: Makefile
	(for i in ${TEST_MODULES}; do \
		echo "$$i"; \
		echo "$$i.c"; \
	done ;\
	for i in ${IGNORES}; do \
		echo "$$i"; \
	done) > $@

TEST_MODULES_ASFE_ONLY=

ASFC=${top_builddir}/semantics/asfc/src/asfc
ASFE=${top_builddir}/semantics/asfe/src/asfe
ASFCHECKER=${top_builddir}/semantics/asf-checker/src/asfchecker
ATRMANNOS=${ATERM}/bin/atrmannos
ATDIFF=${ATERM}/bin/atdiff
EQS=${srcdir}/eqs
IN=${srcdir}/input
OUT=${srcdir}/output
CODE=${srcdir}/c-code

CLEANFILES = *.out *.c ${TEST_MODULES} *.sh .cvsignore

TESTS = \
	$(foreach f, ${TEST_MODULES}, $f.asfe.sh $f.asfc.sh ) \
	$(foreach f, ${TEST_MODULES_ASFE_ONLY}, $f.asfe.sh) 

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
