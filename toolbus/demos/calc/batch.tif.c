/* GENERATED AUTOMATICALLY, DO NOT MODIFY */
/* Tool Interface File for tool: batch */

#include "TB.h"

/* Prototypes for functions used in event handler */
term * fromFile(void);
void   toFile(char *, int);
void   rec_terminate(term *);

/* Event handler for tool: batch */

term *batch_handler(term *e){
	term *term_arg[1];
	int int_arg[1];
	char *str_arg[1];

	if(TBmatch(e, "rec-eval(fromFile())" )){
		return fromFile();
	} else if(TBmatch(e, "rec-do(toFile(%s, %d))", &str_arg[0], &int_arg[0])){
		toFile(str_arg[0], int_arg[0]);
	return NULL;
	} else if(TBmatch(e, "rec-terminate(%t)", &term_arg[0])){
		rec_terminate(term_arg[0]);
		return NULL;
	}  else  {
		TBprintf(stderr, "Ignored: %t\n", e);
		return NULL;
	}
}

/* Check input signature for tool: batch
 * returns: NULL (requested input signature is subset of tool's input signature);
 *          non-null term: first element not in tool's input signature.
 * NOTE:    In the signature all terms have as first argument <batch>, but this
 *          does NOT appear in the actual terms that will be sent to the tool.
 */

term *batch_check_in_sign(term *reqs){
	char *in_sign[3];
	int i;

	in_sign[0] = "rec-eval(<batch>,fromFile)";
	in_sign[1] = "rec-do(<batch>,toFile(<str>,<int>))";
	in_sign[2] = "rec-terminate(<batch>,<term>)";

	for( ; reqs; reqs=list_next(reqs)) {
	  for(i=0; i<3; i++) {
	    if(TBmatch(list_first(reqs), in_sign[i])) goto found;
	  }
	  return list_first(reqs);
	  found:;
	}
	return NULL;
}
