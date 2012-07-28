#include <PTMEPT-utils.h>
#include <Library.h>
#include "builtin-common.h"
#include <asc-support-me.h>
#include <MEPT-utils.h>

#include <stdlib.h>
#include <unistd.h>
#include <assert.h>
#include <aterm2.h>
#include <atb-tool.h>
#include <Error-utils.h>
#include <tide-adapter.h>

static int pid;


/*{{{  static TA_Expr eval_resume(int pid, AFun fun, TA_ExprList args) */

static TA_Expr eval_resume(int pid, AFun fun, TA_ExprList args)
{
  TA_setProcessState(pid, STATE_RUNNING);
ATwarning("eval resume");
  return ATparse("true");
}

/*}}}  */
/*{{{  static TA_Expr eval_break(int pid, AFun fun, TA_ExprList args) */

static TA_Expr eval_break(int pid, AFun fun, TA_ExprList args)
{
  TA_setProcessState(pid, STATE_STOPPED);
ATwarning("eval break\n");

  return ATparse("true");
}

/*}}}  */
/*{{{  static TA_Location tree_to_ta_location(PT_Tree tree) */

static TA_Location tree_to_ta_location(PT_Tree tree)
{
  PERR_Location pLoc;
  ERR_Location loc;

  pLoc = PERR_LocationFromTerm(PT_TreeToTerm(tree));
  loc = PERR_lowerLocation(pLoc);

  return TA_LocationFromTerm(ERR_LocationToTerm(loc));
}

/*}}}  */

/*{{{  static PT_Tree tide_connect(PT_Tree name, PT_Tree init_location) */

static PT_Tree tide_connect(PT_Tree name, PT_Tree init_location)
{
  int cid;
  char* str = PT_yieldTreeToString(name, ATfalse);

  cid = TA_connect(ATBgetPort(getCid()));
  pid = TA_createProcess(cid, str);

  TA_registerFunction(pid, ATmakeAFun("resume", 0, ATfalse), eval_resume);
  TA_registerFunction(pid, ATmakeAFun("break",  0, ATfalse), eval_break);

  TA_atCPE(pid, tree_to_ta_location(init_location), 0);
		  
  return (PT_Tree)CO_makeBooleanConstant(CO_makeBoolConTrue());
}

/*}}}  */
/*{{{  static PT_Tree tide_disconnect() */

static PT_Tree tide_disconnect()
{
  if (TA_isConnected()) {
    TA_disconnect(ATtrue, pid);
  }

  return (PT_Tree)CO_makeBooleanConstant(CO_makeBoolConTrue());
}

/*}}}  */
/*{{{  static PT_Tree tide_step(PT_Tree tLoc) */

static PT_Tree tide_step(PT_Tree tLoc)
{
  if (TA_isConnected()) {
    int old_state = TA_getProcessState(pid);

    old_state = TA_getProcessState(pid);

    TA_atCPE(pid, tree_to_ta_location(tLoc), 0);
    TA_activateRules(pid, TA_makePortStep());

    if (TA_getProcessState(pid) == STATE_STOPPED) {
      if (old_state != STATE_STOPPED) {
        TA_activateRules(pid, TA_makePortStopped());
      }

      while (TA_getProcessState(pid) == STATE_STOPPED) {
        TA_handleAny(pid);
      }
      /* process has been set to STATE_RUNNING */
      if (TA_isConnected()) {
        TA_activateRules(pid, TA_makePortStarted());
      }
    }
  }

  return (PT_Tree)CO_makeBooleanConstant(CO_makeBoolConTrue());
}

/*}}}  */

/*{{{  PT_Tree ASFE_tide_connect(PT_Symbol type, PT_Tree name, PT_Tree init_location) */

PT_Tree ASFE_tide_connect(PT_Symbol type, PT_Tree name, PT_Tree init_location)
{
  return tide_connect(name, init_location);
}

/*}}}  */
/*{{{  PT_Tree ASFE_tide_disconnect(PT_Symbol type, PT_Tree dummy) */

PT_Tree ASFE_tide_disconnect(PT_Symbol type, PT_Tree dummy)
{
  return tide_disconnect();
}

/*}}}  */
/*{{{  PT_Tree ASFE_tide_step(PT_Symbol type, PT_Tree location) */

PT_Tree ASFE_tide_step(PT_Symbol type, PT_Tree location)
{
  return tide_step(location);
}

/*}}}  */

/*{{{  PT_Tree ASC_tide_connect(ATerm type, ATerm name, ATerm init_location) */

PT_Tree ASC_tide_connect(ATerm type, ATerm name, ATerm init_location)
{
  return tide_connect(muASFToTree(name), muASFToTree(init_location));
}

/*}}}  */
/*{{{  PT_Tree ASC_tide_disconnect(ATerm type, ATerm dummy) */

PT_Tree ASC_tide_disconnect(ATerm type, ATerm dummy)
{
  return tide_disconnect();
}

/*}}}  */
/*{{{  PT_Tree ASC_tide_step(ATerm type, ATerm location) */

PT_Tree ASC_tide_step(ATerm type, ATerm location)
{
  return tide_step(muASFToTree(location));
}

/*}}}  */


