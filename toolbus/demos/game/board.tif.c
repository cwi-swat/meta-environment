/* GENERATED AUTOMATICALLY, DO NOT MODIFY */
/* Tool Interface File for tool: board */

#include "TB.h"

/* Prototypes for functions used in event handler */
term * push(char *, int, int);
void   rec_terminate(term *);

/* Event handler for tool: board */

term *board_handler(term *e){
	term *term_arg[1];
	int int_arg[2];
	char *str_arg[1];

	if(TBmatch(e, "rec-eval(push(%s, %d, %d))", &str_arg[0], &int_arg[0], &int_arg[1])){
		return push(str_arg[0], int_arg[0], int_arg[1]);
	} else if(TBmatch(e, "rec-terminate(%t)", &term_arg[0])){
		rec_terminate(term_arg[0]);
		return NULL;
	}  else  {
		TBprintf(stderr, "Ignored: %t\n", e);
		return NULL;
	}
}

/* Check input signature for tool: board
 * returns: NULL (requested input signature is subset of tool's input signature);
 *          non-null term: first element not in tool's input signature.
 * NOTE:    In the signature all terms have as first argument <board>, but this
 *          does NOT appear in the actual terms that will be sent to the tool.
 */

term *board_check_in_sign(term_list *reqs){
	char *in_sign[2];
	int i;

	in_sign[0] = "rec-eval(<board>,push(<str>,<int>,<int>))";
	in_sign[1] = "rec-terminate(<board>,<term>)";

	for( ; reqs; reqs = next(reqs)){
		for(i = 0; i < 2; i++){
			if(TBmatch(first(reqs), in_sign[i])) goto found;
		}
		return first(reqs);
		found:;
	}
	return NULL;
}
