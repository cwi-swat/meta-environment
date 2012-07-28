
#include "debug-adapter.h"
#include "tide-adapter.h"

/*{{{  ATerm ta_create_rule(int conn, int pid, ATerm port, cond, act, tag) */

ATerm ta_create_rule(int conn, int pid, ATerm port, ATerm cond,
		     ATerm act, ATerm tag, ATerm enabled)
{
  TA_Port the_port = TA_PortFromTerm(port);
  TA_Expr the_cond = cond;
  TA_Expr the_act  = act;
  
  int rid = TA_createRule(pid, the_port, the_cond, the_act, tag,
			  ATisEqual(enabled, ATparse("true")));

  return ATmake("snd-value(rule-created(<int>))", rid);
}

/*}}}  */
/*{{{  ATerm ta_enable_rule(int conn, int pid, int rid) */

ATerm ta_enable_rule(int conn, int pid, int rid)
{
  TA_enableRule(pid, rid);
  return ATmake("snd-value(rule-enabled)");
}

/*}}}  */
/*{{{  ATerm ta_disable_rule(int conn, int pid, int rid) */

ATerm ta_disable_rule(int conn, int pid, int rid)
{
  TA_disableRule(pid, rid);
  return ATmake("snd-value(rule-disabled)");
}

/*}}}  */
/*{{{  ATerm ta_modify_rule(int conn, int pid, int rid, port, cond, ATerm act, en) */

ATerm ta_modify_rule(int conn, int pid, int rid, ATerm port, ATerm cond,
		     ATerm act, ATerm enabled)
{
  TA_Port the_port = TA_PortFromTerm(port);
  TA_Expr the_cond = cond;
  TA_Expr the_act  = act;

  TA_modifyRule(pid, rid, the_port, the_cond, the_act,
		ATisEqual(enabled, ATparse("true")));

  return ATparse("snd-value(rule-modified)");
}

/*}}}  */
/*{{{  ATerm ta_delete_rule(int conn, int pid, int rid) */

ATerm ta_delete_rule(int conn, int pid, int rid)
{
  TA_deleteRule(pid, rid);

  return ATparse("snd-value(rule-deleted)");
}

/*}}}  */

/*{{{  void ta_rec_ack_event(int conn, ATerm event) */

void ta_rec_ack_event(int conn, ATerm event)
{
}

/*}}}  */
/*{{{  void ta_rec_terminate(int conn, ATerm event) */

void ta_rec_terminate(int conn, ATerm event){}

/*}}}  */
/*{{{  ATerm ta_evaluate(int conn, int pid, ATerm expr) */

ATerm ta_evaluate(int conn, int pid, ATerm expr)
{
  return ATmake("snd-value(evaluated(<term>))", TA_evaluate(pid, expr));
}

/*}}}  */

