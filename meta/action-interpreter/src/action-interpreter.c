/* $Id$ */

/*{{{  includes */

#include "action-interpreter.tif.h"
#include "action-interpreter.h"
#include <ctype.h>
#include "Actions.h"
#include <unistd.h>
#include <assert.h>

/*}}}  */
/*{{{  variables */

static char myversion[] = "1.0";
static AC_Actions actions;
static AC_Stack stack;
static AC_Signature signature;

/*}}}  */
/*{{{  void rec_terminate(int cid, ATerm t) */

void rec_terminate(int cid, ATerm t)
{
  exit(0);
}

/*}}}  */
/*{{{  void usage(char *prg, ATbool is_err) */

void usage(char *prg, ATbool is_err)
{
  ATwarning("usage: %s [aterm-options] [toolbus-options]\n", prg);
  ATwarning("use '%s -at-help' to get more options.\n", prg);
  ATwarning("This program can only be used as a ToolBus tool!\n");
  exit(is_err ? 1 : 0);
}

/*}}}  */
/*{{{  void version(const char *msg) */

void version(const char *msg)
{
  ATwarning("%s v%s\n", msg, myversion);
  exit(1);
}

/*}}}  */
/*{{{  ATerm report_empty_stack() */

void report_end_of_actions(int cid)
{
  ATBwriteTerm(cid, ATmake("snd-event(done)"));
  ATBhandleOne(cid);
}
/*}}}  */
/*{{{  void send_action(int cid, AC_Message message) */

void send_action(int cid, AC_Message message)
{
  ATBwriteTerm(cid, ATmake("snd-event(action(<term>))",
                           AC_MessageToTerm(message)));
  ATBhandleOne(cid);
}
/*}}}  */
/*{{{  ATerm edit_term() */

void edit_term(int cid, char *fileName, char *moduleName)
{
  ATBwriteTerm(cid, ATmake("snd-event(action(new-edit-term(<str>,<str>)))",
                           fileName, moduleName));
  ATBhandleOne(cid);
}
/*}}}  */
/*{{{  void rec_ack_event(int cid, ATerm t) */

void rec_ack_event(int cid, ATerm t)
{
  return;
}

/*}}}  */
/*{{{  AC_Stack AC_pushOnStack(AC_Item head, AC_Stack tail) */

static AC_Stack AC_pushOnStack(AC_Item head, AC_Stack tail)
{
  return AC_makeStackMany(head, tail);
}

/*}}}  */
/*{{{  AC_Stack AC_popFromStack(AC_Stack tail) */

static AC_Stack AC_popFromStack(AC_Stack stck)
{
  return AC_getStackTail(stck);
}

/*}}}  */
/*{{{  static void actionApply(AC_Action action) */

static void actionApply(AC_Action action)
{
  int nrOfArgs = AC_getActionArgumentsNumber(action);
  char *name = AC_getActionFunctionName(action);
  char *sort = AC_getActionResultSort(action);
  PT_ParseTree newParseTree;
  PT_Args args = PT_makeArgsEmpty();
  while (nrOfArgs > 0) {
    if (!AC_isStackEmpty(stack)) {
      AC_Item head = AC_getStackHead(stack);
      PT_ParseTree parseTree = 
                         PT_ParseTreeFromTerm(ATBunpack(AC_ItemToTerm(head)));
      stack = AC_popFromStack(stack);
      args = PT_makeArgsMany(PT_getParseTreeTree(parseTree), args);
    }
    nrOfArgs--;
  }

  newParseTree = PT_applyFunctionToArgsParseTree(name, sort, args);
  stack = AC_pushOnStack(AC_ItemFromTerm(PT_ParseTreeToTerm(newParseTree)), 
                             stack);
}

/*}}}  */
/*{{{  static void actionCondition(AC_Action action) */

static void actionCondition(AC_Action action)
{
  if (!AC_isStackEmpty(stack)) {
    AC_Item head1 = AC_getStackHead(stack);
    stack = AC_popFromStack(stack);
    if (!AC_isStackEmpty(stack)) {
      AC_Item head2 = AC_getStackHead(stack);
      stack = AC_popFromStack(stack);
      if (AC_isEqualItem(head1, head2)) {
        AC_Actions thenActions = AC_getActionThenList(action);
        actions = AC_concatActions(actions, thenActions);
      }
      else {
        AC_Actions elseActions = AC_getActionElseList(action);
        actions = AC_concatActions(actions, elseActions);
      }
    }
  }
}

/*}}}  */
/*{{{  static void actionGeneric(AC_Action action) */

static ATbool actionGeneric(int cid, AC_Action action)
{
  ATerm name = AC_getActionName(action);
  AC_Descriptions descriptions = AC_getSignatureList(signature);
  ATbool found = ATfalse;
  AC_Description description = NULL;
  ATerm descName;

  while (!AC_isDescriptionsEmpty(descriptions) && !found) {
    description = AC_getDescriptionsHead(descriptions);
    descName = AC_getDescriptionName(description);

    if (ATisEqual(name, descName)) {
      found = ATtrue;
    }
    descriptions = AC_getDescriptionsTail(descriptions);
  }

  if (found) {
    AC_Arg arg;
    AC_Args args = AC_getDescriptionArguments(description);
    ATermList messageArgs = ATempty;
    ATerm message;
    AFun fun;

    while (!AC_isArgsEmpty(args)) {
      arg = AC_getArgsHead(args);
      args = AC_getArgsTail(args);
      if (!AC_isStackEmpty(stack)) {
        AC_Item head = AC_getStackHead(stack);
        if (AC_isArgString(arg)) {
          char *string = AC_getItemString(head);
 
          messageArgs = ATappend(messageArgs,
                                 ATmake("<str>", string));
        }
        else {
          messageArgs = ATappend(messageArgs, AC_ItemToTerm(head));
        }
        stack = AC_popFromStack(stack);
      }
    }
    fun = ATgetAFun((ATermAppl)name);
    message = (ATerm)ATmakeApplList(ATmakeAFun(ATgetName(fun), 
                                    ATgetLength(messageArgs), 
                                    ATfalse), messageArgs);
    send_action(cid, AC_MessageFromTerm(message));
    return ATtrue;
  }
  else {
ATwarning("Nothing found for %t\n", name);
    return ATfalse;
  }
}

/*}}}  */
/*{{{  void static processActions(int cid) */

static ATbool performActions(int cid)
{
  ATbool breakLoop = ATfalse;
  while (!AC_isActionsEmpty(actions) && !breakLoop) {
    AC_Action action = AC_getActionsHead(actions);

    if (AC_isActionApply(action)) {
      actionApply(action);
    }
    else if (AC_isActionDup(action)) {
      if (!AC_isStackEmpty(stack)) {
        AC_Item head = AC_getStackHead(stack);
        stack = AC_pushOnStack(head, stack);
      }
    }
    else if (AC_isActionPop(action)) {
      if (!AC_isStackEmpty(stack)) {
        stack = AC_getStackTail(stack);
      }
    }
    else if (AC_isActionCondition(action)) {
      actionCondition(action);
    }
    else if (AC_isActionPushFilename(action)) {
      char *string = AC_getActionString(action);
      AC_Item item = AC_makeItemString(string);
      stack = AC_pushOnStack(item, stack);
    }
    else if (AC_isActionPushModulename(action)) {
      char *string = AC_getActionString(action);
      AC_Item item = AC_makeItemString(string);
      stack = AC_pushOnStack(item, stack);
    }
    else if (AC_isActionPushString(action)) {
      char *string = AC_getActionString(action);
      AC_Item item = AC_makeItemString(string);
      stack = AC_pushOnStack(item, stack);
    }
    else if (AC_isActionPushTerm(action)) {
      ATerm tree = AC_getActionTerm(action);
      stack = AC_pushOnStack(AC_ItemFromTerm(tree), stack);
    }
    else if (AC_isActionGeneric(action)) {
      breakLoop = actionGeneric(cid, action);
    }
    else {
      ATwarning("unknown action = %t\n", action);
    }
    actions = AC_getActionsTail(actions);
  }
  return breakLoop;
}

/*}}}  */
/*{{{  void perform_actions(int cid, ATerm aScript, ATerm aStack) */

void perform_actions(int cid, ATerm aScript, ATerm aStack)
{
  ATbool ready;
  AC_Script script = AC_ScriptFromTerm(aScript);
  actions = AC_getScriptList(script);
 
  stack = AC_StackFromTerm(aStack);

  ready = performActions(cid);

  if (!ready) {
    report_end_of_actions(cid);
  }
}

/*}}}  */
/*{{{  void process_result(int cid, ATerm aResult) */

void process_result(int cid, ATerm aResult)
{
  ATbool ready = ATfalse;
  ATerm result, result1, result2, result3;

  if (ATmatch(aResult, "done")) {
    ready = performActions(cid);
  }
  else if (ATmatch(aResult, "result(<term>)", &result)) {
    stack = AC_pushOnStack(AC_ItemFromTerm(result), stack);
    ready = performActions(cid);
  }
  else if (ATmatch(aResult, "two-results(<term>,<term>)", 
                   &result1,&result2)) {
    stack = AC_pushOnStack(AC_ItemFromTerm(result1), stack);
    stack = AC_pushOnStack(AC_ItemFromTerm(result2), stack);
ATwarning("Halllo: result2 = %t\n", result2);
    ready = performActions(cid);
  }
  else if (ATmatch(aResult, "three-results(<term>,<term>,<term>)", 
                   &result1,&result2,&result3)) {
    stack = AC_pushOnStack(AC_ItemFromTerm(result1), stack);
    stack = AC_pushOnStack(AC_ItemFromTerm(result2), stack);
    stack = AC_pushOnStack(AC_ItemFromTerm(result3), stack);
    ready = performActions(cid);
  }
  else if (ATmatch(aResult, "failure")) {
    ready = ATfalse;
    stack = AC_makeStackEmpty();
  }
  
  if (!ready) {
    report_end_of_actions(cid);
  }
}

/*}}}  */
/*{{{  int main(int argc, char *argv[]) */

int main(int argc, char *argv[])
{
  int i, cid;
  ATerm bottomOfStack;
  ATerm aSignature;

  for (i=1; i<argc; i++) {
    if (strcmp(argv[i], "-h") == 0) {
      usage(argv[0], ATfalse);
    } else if (strcmp(argv[i], "-V") == 0) {
      version(argv[0]);
    }
  }

  ATBinit(argc, argv, &bottomOfStack);
  PT_initMEPTApi();
  AC_initActionsApi();

  cid = ATBconnect(NULL, NULL, -1, action_interpreter_handler);

  aSignature = ATparse("[action(add-import,[string]),\
                         action(add-posinfo,[tree]),\
                         action(asfsdfapigen,[string,string]),\
                         action(ask-question,[string]),\
                         action(activate-editor,[string,string,tree]),\
                         action(check-sort,[string,tree]),\
                         action(clear-all,[]),\
                         action(clear-history-list,[]),\
                         action(close-module,[tree,string]),\
                         action(compile-module,[string,string]),\
                         action(copy-module,[string,string,string]),\
                         action(create-module,[string]),\
                         action(debug-reduce,[string,tree]),\
                         action(debug-run-asf-tests,[string]),\
                         action(delete-module,[string]),\
                         action(display-message,[string]),\
                         action(dump-equations,[string,string]),\
                         action(dump-sdf-definition,[string,string]),\
                         action(dump-eqs-parse-table,[string,string]),\
                         action(dump-parse-table,[string,string]),\
                         action(edit-term,[string,string]),\
                         action(edit-syntax,[string]),\
                         action(edit-equations,[string]),\
                         action(exit,[]),\
                         action(execute-action,[string, tree]),\
                         action(get-focus,[]),\
                         action(get-focus-location,[]),\
                         action(get-focus-origin,[]),\
                         action(get-root,[string]),\
                         action(get-parsetree,[]),\
                         action(move-cursor,[tree]),\
                         action(new-module,[string,string,string]),\
                         action(open-module,[string,string,string]),\
                         action(pack-tree,[tree]),\
                         action(parse,[string,string,tree]),\
                         action(parse-action,[string]),\
                         action(parse-equations-action,[string]),\
                         action(parse-syntax-action,[]),\
                         action(print-module,[string,string]),\
                         action(pretty-print,[string,tree]),\
                         action(prompt-for-file,[string,string,string]),\
                         action(prompt-for-file-with-extension,[string,string,string]),\
                         action(push-active-module,[]),\
			 action(read-termstore,[string]),\
                         action(reduce,[string,tree]),\
                         action(refresh-actions,[]),\
                         action(remove-import,[string]),\
                         action(rename-module,[string,string,string]),\
                         action(run-asf-tests,[string]),\
                         action(save-termstore,[string]),\
                         action(set-root,[tree]),\
                         action(show-area,[string,tree]),\
                         action(show-feedback-location,[tree]),\
                         action(show-tree,[tree,string]),\
                         action(show-full-tree,[tree,string]),\
                         action(split-file-name,[string]),\
                         action(unpack-tree,[tree])]");
  signature = AC_SignatureFromTerm(aSignature);
  
  ATBeventloop();

  return 0;
}

/*}}}  */
