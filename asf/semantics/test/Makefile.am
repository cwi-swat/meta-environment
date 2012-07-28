SUBDIRS=eqs input output c-code
EXTRA_DIST=README

TEST_MODULES=\
	AllLists \
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
	ReturnsList \
	SetAndElem \
	Specificity \
	StarStarVar \
	Traversal-Typecheck \
	Tuple

# TODO: maybe really remove this test
#	ListSpecific

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

ASFC=${top_builddir}/semantics/asfc/src/test-asfc
ASFE=${top_builddir}/semantics/asfe/src/asfe
ASFCHECKER=${top_builddir}/semantics/asf-checker/src/asfchecker
ATRMANNOS=${ATERM_PREFIX}/bin/atrmannos
ATDIFF=${ATERM_PREFIX}/bin/atdiff 
EQS=${srcdir}/eqs
IN=${srcdir}/input
OUT=${srcdir}/output
CODE=${srcdir}/c-code

CLEANFILES = *.o *.out *.c ${TEST_MODULES} *.sh .cvsignore

TESTS = \
	$(foreach f, ${TEST_MODULES}, $f.asfe.sh $f.asfc.sh ) \
	$(foreach f, ${TEST_MODULES_ASFE_ONLY}, $f.asfe.sh) 
#	$(foreach f, ${TEST_MODULES}, $f.asfe.sh $f.asfe-layout.sh $f.asfc.sh $f.asfc-layout.sh) 

%.asfc.sh: 
	@(echo '#!/bin/sh'  ; \
	 echo 'set -e' ; \
	 echo 'echo "Compiling $*"' ; \
	 echo '${ASFC} -c -i ${EQS}/$*.eqs -n $* -o $*.c'; \
	 echo 'for i in ${IN}/$*.*.pt; do ' ;\
	 echo ' echo "...Reducing $$i"' ; \
	 echo ' ./$* -i $$i -o `basename $$i`.asfc.out '; \
	 echo ' ${ATDIFF} `basename $$i`.asfc.out ${OUT}/`basename $$i` '; \
	 echo ' echo "...Succeeded $$i"' ; \
	 echo 'done' ) > $@ && chmod +x $@

%.asfc-layout.sh: 
	@(echo '#!/bin/sh'  ; \
	 echo 'set -e' ; \
	 echo 'echo "Compiling with layout $*"' ; \
	 echo '${ASFC} -L -c -i ${EQS}/$*.eqs -n $* -o $*.c'; \
	 echo 'for i in ${IN}/$*.*.pt; do ' ;\
	 echo ' echo "...Reducing $$i"' ; \
	 echo ' ./$* -i $$i -o `basename $$i`.asfc-layout.out '; \
	 echo ' ${ATDIFF} `basename $$i`.asfc-layout.out ${OUT}/layout-`basename $$i` '; \
	 echo ' echo "...Succeeded $$i"' ; \
	 echo 'done' ) > $@ && chmod +x $@
	
%.asfe.sh:
	@(echo '#!/bin/sh'  ; \
	 echo 'set -e'  ; \
	 echo 'echo "Interpreting $*"' ; \
	 echo 'for i in ${IN}/$*.*.pt; do' ; \
	 echo ' echo "...Reducing $$i"' ; \
	 echo '  ${ASFE} -l -e ${EQS}/$*.eqs -i $$i | \'; \
	 echo '  ${ATRMANNOS} -a -o `basename $$i`.asfe.out ' ; \
	 echo '  ${ATDIFF} `basename $$i`.asfe.out ${OUT}/`basename $$i`' ; \
	 echo ' echo "...Succeeded $$i"' ; \
	 echo 'done' ) > $@ && chmod +x $@

%.asfe-layout.sh:
	@(echo '#!/bin/sh'  ; \
	 echo 'set -e'  ; \
	 echo 'echo "Interpreting with layout $*"' ; \
	 echo 'for i in ${IN}/$*.*.pt; do' ; \
	 echo ' echo "...Reducing $$i"' ; \
	 echo '  ${ASFE} -e ${EQS}/$*.eqs -i $$i | \'; \
	 echo '  ${ATRMANNOS} -a -o `basename $$i`.asfe-layout.out ' ; \
	 echo '  ${ATDIFF} `basename $$i`.asfe-layout.out ${OUT}/layout-`basename $$i`' ; \
	 echo ' echo "...Succeeded $$i"' ; \
	 echo 'done' ) > $@ && chmod +x $@

