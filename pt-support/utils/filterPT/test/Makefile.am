# $Id: Makefile.am,v 1.1.2.7 2004/10/18 13:12:17 uid507 Exp $

SUBDIRS = sdf terms in out

TEST_SET = \
	Nested \
	Simple \
	Overlapping \
	Ambiguous

Nested_flags= -n Water
Nested_sort= Input

Simple_flags= -n Water
Simple_sort= Input

Overlapping_flags= -N Island
Overlapping_sort= Input

Ambiguous_flags= -n ThisNonterminalDoesNotExist
Ambiguous_sort= Input

TESTS = $(TEST_SET:%=%.sh)

FILTER=$(top_builddir)/utils/filterPT/filterPT
IMPLODE=$(top_builddir)/utils/implodePT/implodePT
ATDIFF=${ATERM_PREFIX}/bin/atdiff

EXTRA_DIST = template.sh

CLEANFILES = *.tested $(TEST_SET:%=%.sh)

#use this target to regenerate the regression tests:
testset: $(TEST_SET:%=%.tbl) \
         $(TEST_SET:%=%.in) \
         $(TEST_SET:%=%.out)

testsetclean:
	$(RM) sdf/*.def sdf/*.tbl in/*.in out/*.out 

%.sh : 
	sed 	"s@__GRAMMAR__@$*@g;\
	 	 s@__GRAMMAR_FLAGS__@$($*_flags)@g;\
		 s@__FILTER__@${FILTER}@g;\
		 s@__IMPLODE__@${IMPLODE}@g;\
		 s@__SRCDIR__@${srcdir}@g;\
		 s@__ATDIFF__@${ATDIFF}@g;" < ${srcdir}/template.sh > $@ && chmod +x $@

# To use these targets you need to have sglr and sdf2table in your path
# These targets are used at 'testset-generation-time' only!
%.in :
	for i in terms/$*.[0-9].trm; do \
		sglr 	-s $($*_sort) \
			-p sdf/$*.tbl \
			-i $$i \
			-fe -fi \
			-o in/`basename $$i .trm`.in; \
	done

%.tbl : 
	(echo "definition"; \
	cat sdf/Water.sdf sdf/Layout.sdf sdf/$*.sdf) > sdf/$*.def
	sdf2table -i sdf/$*.def -m $* -o sdf/$@

%.out :
	for i in in/$*.[0-9].in; do \
		${FILTER} \
			$($*_flags) \
			-i $$i \
	| ${IMPLODE} -t	-o out/`basename $$i .in`.out; \
	done
