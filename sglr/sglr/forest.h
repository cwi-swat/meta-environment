/*
  %% $Id$
  %% Parse forests

   The parser maintains a compact representation of a set of parse
   trees in the form of a parse forest. We use the generic terms to
   represent these.

   Parse forests are constructed using the functions |apply|, |NULL|,
   |cons| and |amb|. |apply| denotes the application of a function to
   a list of arguments. |NULL| denotes the empty list of
   arguments.|cons| adds a term in front of a list. The function |amb|
   actually constructs forests. It takes two trees and creates an
   ambiguous node \emph{at the same address as the first tree}. This
   means that all trees with a pointer to the first tree will share
   the newly created ambiguous node.

   The variable |nr_ambiguities| keeps track of the number of times an
   ambiguous node is created.
*/
extern int nr_ambiguities;
/*
  We use the |term_has_conds| fields of terms to indicate that a tree
  is invalid.
*/
#define cons(t, ts)       mk_list(t, ts)
term *apply(parse_table *, label , terms *);
void amb(term *, term *);
term *tree_type(term *);
term *term_yield(term *t);

term *dot_term_yield(term *);

