#include "common.h"
#include <atb-tool.h>

/* From the interpreter */
extern int toolbus_id;

/*{{{  static void post_event(ATerm label, ATerm event) */

static void post_event(ATerm label, ATerm event, char *msg)
{
  ATBpostEvent(toolbus_id, ATmake("event(<term>,<term>,<str>)",
				  label, event, msg));
}

/*}}}  */


/*{{{  PT_Tree toolbus_event(ATerm builtin, PT_Tree input) */

PT_Tree toolbus_event(ATerm builtin, PT_Tree input)
{
  PT_Tree name = CO_getFunctionArgument(input,0);
  PT_Tree event = CO_getFunctionArgument(input,1);
  ATerm label = CO_unquoteAppl(ATparse(PT_yieldTree(name))); 

  post_event(label, (ATerm) event, PT_yieldTree(event));

  return event;
}

/*}}}  */
/*{{{  PT_Tree toolbus_term_event(ATerm builtin, PT_Tree input) */

PT_Tree toolbus_term_event(ATerm builtin, PT_Tree input)
{
  PT_Tree name = CO_getFunctionArgument(input,0);
  PT_Tree event = CO_getFunctionArgument(input,1);
  ATerm label = CO_unquoteAppl(ATparse(PT_yieldTree(name))); 
  ATerm term = ATparse(PT_yieldTree(event));

  if (term == NULL) {
    ATwarning("toolbus_term_event: %s is not a proper ATerm\n",
	      PT_yieldTree(event));

    return input;
  }

  post_event(label, term, "term-event"); 

  return event;
}

/*}}}  */
