/* GENERATED AUTOMATICALLY, DO NOT MODIFY */
/* Tool Interface File for tool: clock */

#include "TB.h"

/* Prototypes for functions used in event handler */
term * readTime(void);
void   rec_terminate(term *);

/* Event handler for tool: clock */

term *clock_handler(term *e){
	term *term_arg[1];

	if(TBmatch(e, "rec-eval(readTime())" )){
		return readTime();
	} else if(TBmatch(e, "rec-terminate(%t)", &term_arg[0])){
		rec_terminate(term_arg[0]);
		return NULL;
	}  else  {
		TBprintf(stderr, "Ignored: %t\n", e);
		return NULL;
	}
}

/* Check input signature for tool: clock
 * returns: NULL (requested input signature is subset of tool's input signature);
 *          non-null term: first element not in tool's input signature.
 * NOTE:    In the signature all terms have as first argument <clock>, but this
 *          does NOT appear in the actual terms that will be sent to the tool.
 */

term *clock_check_in_sign(term *reqs){
	char *in_sign[2];
	int i;

	in_sign[0] = "rec-eval(<clock>,readTime)";
	in_sign[1] = "rec-terminate(<clock>,<term>)";

	for( ; reqs; reqs=list_next(reqs)) {
	  for(i=0; i<2; i++) {
	    if(TBmatch(list_first(reqs), in_sign[i])) goto found;
	  }
	  return list_first(reqs);
	  found:;
	}
	return NULL;
}
