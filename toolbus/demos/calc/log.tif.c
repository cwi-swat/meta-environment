/* GENERATED AUTOMATICALLY, DO NOT MODIFY */
/* Tool Interface File for tool: log */

#include "TB.h"

/* Prototypes for functions used in event handler */
void   writeLog(char *, term *);
term * readLog(void);
void   rec_terminate(term *);

/* Event handler for tool: log */

term *log_handler(term *e){
	term *term_arg[1];
	char *str_arg[1];

	if(TBmatch(e, "rec-do(writeLog(%s, %t))", &str_arg[0], &term_arg[0])){
		writeLog(str_arg[0], term_arg[0]);
	return NULL;
	} else if(TBmatch(e, "rec-eval(readLog())" )){
		return readLog();
	} else if(TBmatch(e, "rec-terminate(%t)", &term_arg[0])){
		rec_terminate(term_arg[0]);
		return NULL;
	}  else  {
		TBprintf(stderr, "Ignored: %t\n", e);
		return NULL;
	}
}

/* Check input signature for tool: log
 * returns: NULL (requested input signature is subset of tool's input signature);
 *          non-null term: first element not in tool's input signature.
 * NOTE:    In the signature all terms have as first argument <log>, but this
 *          does NOT appear in the actual terms that will be sent to the tool.
 */

term *log_check_in_sign(term_list *reqs){
	char *in_sign[3];
	int i;

	in_sign[0] = "rec-do(<log>,writeLog(<str>,<term>))";
	in_sign[1] = "rec-eval(<log>,readLog)";
	in_sign[2] = "rec-terminate(<log>,<term>)";

	for( ; reqs; reqs = next(reqs)){
		for(i = 0; i < 3; i++){
			if(TBmatch(first(reqs), in_sign[i])) goto found;
		}
		return first(reqs);
		found:;
	}
	return NULL;
}
