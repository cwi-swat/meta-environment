/* GENERATED AUTOMATICALLY, DO NOT MODIFY */
/* Tool Interface File for tool: calc */

#include "TB.h"

/* Prototypes for functions used in event handler */
term * expr(char *);
void   rec_terminate(term *);

/* Event handler for tool: calc */

term *calc_handler(term *e){
	term *term_arg[1];
	char *str_arg[1];

	if(TBmatch(e, "rec-eval(expr(%s))", &str_arg[0])){
		return expr(str_arg[0]);
	} else if(TBmatch(e, "rec-terminate(%t)", &term_arg[0])){
		rec_terminate(term_arg[0]);
		return NULL;
	}  else  {
		TBprintf(stderr, "Ignored: %t\n", e);
		return NULL;
	}
}

/* Check input signature for tool: calc
 * returns: NULL (requested input signature is subset of tool's input signature);
 *          non-null term: first element not in tool's input signature.
 * NOTE:    In the signature all terms have as first argument <calc>, but this
 *          does NOT appear in the actual terms that will be sent to the tool.
 */

term *calc_check_in_sign(term *reqs){
	char *in_sign[2];
	int i;

	in_sign[0] = "rec-eval(<calc>,expr(<str>))";
	in_sign[1] = "rec-terminate(<calc>,<term>)";

	for( ; reqs; reqs=list_next(reqs)) {
	  for(i=0; i<2; i++) {
	    if(TBmatch(list_first(reqs), in_sign[i])) goto found;
	  }
	  return list_first(reqs);
	  found:;
	}
	return NULL;
}
