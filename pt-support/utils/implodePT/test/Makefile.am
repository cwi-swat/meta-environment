# GT -- Grammar Tools
# Copyright (C) 2000 Merijn de Jonge <mdejonge@cwi.nl>
#                    Eelco Visser <visser@acm.org>
#                    Joost Visser <jvisser@cwi.nl>
#
# This program is free software; you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation; either version 2, or (at your option)
# any later version.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with this program; if not, write to the Free Software
# Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA
# 02111-1307, USA.

# $Id$

TEST_SET = Iter Iter-sep Iter-star Iter-star-sep Nesting-iter-sep1 \
           Nesting-iter-sep2 Nesting-iter-star-sep Empty-iter-star-sep \
	   Alt1a Alt1b Alt2a Alt2b Alt3a Alt3b Alt4a SeqOpt1 SeqOpt2 SeqOpt3 \
	   Seq Var1 Var2

Iter_flags= -X -l -p 
Iter_sep_flags= -X -l -p 
Iter_star_flags= -X -l -p 
Iter_star_sep_flags= -X -l -p 
Nesting_iter_sep1_flags= -X -l -p 
Nesting_iter_sep2_flags= -X -l -p 
Nesting_iter_star_sep_flags= -X -l -p 
Empty_iter_star_sep_flags= -X -l -p 
Alt1a_flags= -X -l -L -c -I -p -A -q -O
Alt1b_flags= -X -l -L -c -I -p -A -q -O
Alt2a_flags= -X -l -L -c -I -p -A -q -O
Alt2b_flags= -X -l -L -c -I -p -A -q -O
Alt3a_flags= -X -l -L -c -I -p -A -q -O
Alt3b_flags= -X -l -L -c -I -p -A -q -O
Alt4a_flags= -X -l -L -c -I -p -A -q -O
SeqOpt1_flags = -X -l -L -c -I -p -A -q -O
SeqOpt2_flags = -X -l -L -c -I -p -A -q -O
SeqOpt3_flags = -X -l -L -c -I -p -A -q -O
Seq_flags = -X -l -L -c -I -p -A -q -O

Var1_flags= -X -l -L  -c -I  -p  -A -q -O
Var2_flags= -X -l -L  -c -I -p -A -q -O

EXTRA_DIST = tests.def \
	     $(TEST_SET:%=%.trm) $(TEST_SET:%=%.in) \
             $(TEST_SET:%=%.out) \
             tiny.tree tiny.trm 

TESTS = $(TEST_SET:%=%.sh)

IMPLODE=$(top_builddir)/utils/flattenPT | \
        $(top_builddir)/utils/implodePT/implodePT

CLEANFILES += $(TEST_SET:%=%.tested) $(TEST_SET:%=%.in)

.PRECIOUS: tests.tbl

testset: tests.tbl $(TEST_SET:%=%.sh) $(TEST_SET:%=%.in) $(TEST_SET:%=%.out)

testsetclean:
	$(RM) tests.tbl testset \
	      $(TEST_SET:%=%.in) $(TEST_SET:%=%.out) $(TEST_SET:%=%.tested) \
	      $(TEST_SET:%=%.sh)
%.sh :
	(\
	   echo 'set -e' ;\
	   echo 'gmake tests.tbl $*.in' ;\
	   echo 'cat $(srcdir)/$*.in | \
                 ${IMPLODE} $($(subst -,_,$*)_flags) -o $*.tested' ;\
	   echo 'atdiff $*.tested $(srcdir)/$*.out' ;\
	) > $@ && chmod +x $@

%.in :
	PATH=$(SGLR)/bin:$${PATH} sglr -2 -s $* -p tests.tbl -i $*.trm -o $@

%.tbl : %.def
	PATH=$(PGEN)/bin:$${PATH} sdf2table -i $< -o $@

%.out :
	../implode-asfix $($(subst -,_,$*)_flags) -i $*.in -o $@
