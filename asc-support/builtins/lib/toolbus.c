#include "common.h"
#include <atb-tool.h>

/* From the interpreter */
extern int toolbus_id;
extern ATerm acknowledgement;

/*{{{  static void post_event(ATerm label, ATerm event) */

static void post_event(ATerm label, ATerm event, char *msg)
{
  assert(ATBisValidConnection(toolbus_id));

  ATBpostEvent(toolbus_id, ATmake("event(<term>,<term>,<str>)",
				  label, event, msg));
}

/*}}}  */
/*{{{  static ATerm receive_ack(void) */

static ATerm receive_ack(void)
{
  ATerm ack;

  assert(ATBisValidConnection(toolbus_id));

  while (!ATBpeekOne(toolbus_id));
  ATBhandleOne(toolbus_id);

  /* get acknowledgement from global variable because 
   * the rec_ack_event in the interpreter put it there
   */
  ack = acknowledgement;

  /* reset the acknowledgement for the next time */
  acknowledgement = NULL;

  return ack;
}

/*}}}  */

/*{{{  PT_Tree toolbus_event(PT_Tree input) */

PT_Tree toolbus_event(PT_Tree input)
{
  PT_Tree name = CO_getFunctionArgument(input,0);
  PT_Tree event = CO_getFunctionArgument(input,1);
  ATerm label = CO_unquoteAppl(ATparse(PT_yieldTree(name))); 
  ATerm ack = NULL;

  post_event(label, (ATerm) event, PT_yieldTree(event));
  ack = receive_ack();

  if (ack == NULL) {
    return input; 
  }
  else {
    return event;
  }
}

/*}}}  */
/*{{{  PT_Tree toolbus_term_event(PT_Tree input) */

PT_Tree toolbus_term_event(PT_Tree input)
{
  PT_Tree name = CO_getFunctionArgument(input,0);
  PT_Tree event = CO_getFunctionArgument(input,1);
  ATerm label = CO_unquoteAppl(ATparse(PT_yieldTree(name))); 
  ATerm term = ATparse(PT_yieldTree(event));
  ATerm ack = NULL;
  PT_Tree result = event;

  if (term == NULL) {
    ATwarning("toolbus_term_event: %s is not a proper ATerm\n",
	      PT_yieldTree(event));

    return input;
  }

  post_event(label, term, "term-event"); 
  ack = receive_ack();

  if (ack == NULL) {
    return input; 
  }
  else {
    return result;
  }
}

/*}}}  */
