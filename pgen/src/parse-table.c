#include "ksdf2table.h"

extern ATermTable state_nr_pairs;
extern ATermTable nr_state_pairs;

extern int nr_of_states;

extern ATermList ATunion(ATermList l1, ATermList l2);

/*{{{  ATerm update_states(ATermList vertex) */

ATerm update_states(ATermList vertex)
{
  ATerm nr;
	ATermList orig;

	orig = ATsosInsert(state_sos, vertex);
	
  nr = ATtableGet(state_nr_pairs, (ATerm)orig);
  if(!nr) {
    nr = (ATerm)ATmakeInt(nr_of_states);
    ATtablePut(state_nr_pairs,(ATerm)orig,nr);
    ATtablePut(nr_state_pairs,nr,(ATerm)orig);
    nr_of_states++;
  }
  return nr;
}

/*}}}  */



