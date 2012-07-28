# $Id$

SUBDIRS=terms grammar in out 

TEST_SET = Iter Iter-sep Iter-star Iter-star-sep Nesting-iter-sep1 \
           Nesting-iter-sep2 Nesting-iter-star-sep Empty-iter-star-sep \
	   Alt1a Alt1b Alt2a Alt2b Alt3a Alt3b Alt4a SeqOpt1 SeqOpt2 SeqOpt3 \
	   Seq Var1 Var2 ListVar

Iter_flags= -X -l -p 
Iter_sep_flags= -X -l -p 
Iter_star_flags= -X -l -p 
Iter_star_sep_flags= -X -l -p 
Nesting_iter_sep1_flags= -X -l -p 
Nesting_iter_sep2_flags= -X -l -p 
Nesting_iter_star_sep_flags= -X -l -p 
Empty_iter_star_sep_flags= -X -l -p 
ListVar_flags = -p -A -c -l -O -I -q -X


TESTS = $(TEST_SET:%=%.sh)

IMPLODE=$(top_builddir)/utils/flattenPT | \
        $(top_builddir)/utils/implodePT/implodePT

CLEANFILES = $(TEST_SET:%=%.tested) $(TEST_SET:%=%.sh)

#use this target to regenerate the regression tests:
testset: grammar/tests.tbl \
         $(TEST_SET:%=%.in) \
         $(TEST_SET:%=%.ref)

testsetclean:
	$(RM) grammar/tests.tbl in/*.in out/*.ref

%.sh :
	(\
	   echo '#!/bin/sh' ;\
	   echo 'set -e' ;\
	   echo 'cat $(srcdir)/in/$*.in | \
                 $(IMPLODE) $($(subst -,_,$*)_flags) -o $*.tested' ;\
	   echo '$(ATERM_PREFIX)/bin/atdiff $*.tested $(srcdir)/out/$*.ref' ;\
	) > $@ && chmod +x $@

# To use these targets you need to have sglr and sdf2table in your path
# These targets are used at 'testset-generation-time' only!
%.in :
	sglr -2 -s $* -p grammar/tests.tbl -i terms/$*.trm \
             -o in/$@

%.tbl : %.def
	sdf2table -i $< -o $@

%.ref :
	cat in/$*.in | $(IMPLODE) $($(subst -,_,$*)_flags) -o out/$@
