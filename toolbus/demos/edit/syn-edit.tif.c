/* GENERATED AUTOMATICALLY, DO NOT MODIFY */
/* Tool Interface File for tool: syn-edit */

#include "TB.h"

/* Prototypes for functions used in event handler */
term * edit(char *);
term * tree_up(char *);
term * tree_down(char *);
term * tree_next(char *);
term * mouse(char *, int, int);
void   close_editor(char *);
void   rec_terminate(term *);

/* Event handler for tool: syn-edit */

term *syn_edit_handler(term *e){
	term *term_arg[1];
	int int_arg[2];
	char *str_arg[1];

	if(TBmatch(e, "rec-eval(edit(%s))", &str_arg[0])){
		return edit(str_arg[0]);
	} else if(TBmatch(e, "rec-eval(tree-up(%s))", &str_arg[0])){
		return tree_up(str_arg[0]);
	} else if(TBmatch(e, "rec-eval(tree-down(%s))", &str_arg[0])){
		return tree_down(str_arg[0]);
	} else if(TBmatch(e, "rec-eval(tree-next(%s))", &str_arg[0])){
		return tree_next(str_arg[0]);
	} else if(TBmatch(e, "rec-eval(mouse(%s, %d, %d))", &str_arg[0], &int_arg[0], &int_arg[1])){
		return mouse(str_arg[0], int_arg[0], int_arg[1]);
	} else if(TBmatch(e, "rec-do(close-editor(%s))", &str_arg[0])){
		close_editor(str_arg[0]);
	return NULL;
	} else if(TBmatch(e, "rec-terminate(%t)", &term_arg[0])){
		rec_terminate(term_arg[0]);
		return NULL;
	}  else  {
		TBprintf(stderr, "Ignored: %t\n", e);
		return NULL;
	}
}

/* Check input signature for tool: syn-edit
 * returns: NULL (requested input signature is subset of tool's input signature);
 *          non-null term: first element not in tool's input signature.
 * NOTE:    In the signature all terms have as first argument <syn-edit>, but this
 *          does NOT appear in the actual terms that will be sent to the tool.
 */

term *syn_edit_check_in_sign(term_list *reqs){
	char *in_sign[7];
	int i;

	in_sign[0] = "rec-eval(<syn-edit>,edit(<str>))";
	in_sign[1] = "rec-eval(<syn-edit>,tree-up(<str>))";
	in_sign[2] = "rec-eval(<syn-edit>,tree-down(<str>))";
	in_sign[3] = "rec-eval(<syn-edit>,tree-next(<str>))";
	in_sign[4] = "rec-eval(<syn-edit>,mouse(<str>,<int>,<int>))";
	in_sign[5] = "rec-do(<syn-edit>,close-editor(<str>))";
	in_sign[6] = "rec-terminate(<syn-edit>,<term>)";

	for( ; reqs; reqs = next(reqs)){
		for(i = 0; i < 7; i++){
			if(TBmatch(first(reqs), in_sign[i])) goto found;
		}
		return first(reqs);
		found:;
	}
	return NULL;
}
