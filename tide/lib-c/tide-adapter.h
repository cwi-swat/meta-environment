#ifndef TIDE_ADAPTER_H
#define TIDE_ADAPTER_H

#include "tide-common.h"
#include <aterm1.h>

#include "TA.h"

typedef ATerm TA_Expr;
typedef ATermList TA_ExprList;

/* debug_adapter_handler is needed as an argument to TBconnect */
ATerm debug_adapter_handler(int conn, ATerm term);

/* tide functions */
typedef TA_Expr (*TA_Function)(int pid, AFun fun, TA_ExprList args);

void TA_connect();
ATbool TA_isConnected();
void TA_registerFunction(AFun name, TA_Function func);
void TA_disconnect(ATbool close);
void TA_handleOne();

int  TA_createProcess(char *name);
int  TA_createRule(int pid, TA_Port port, TA_Expr cond, TA_Expr act, ATerm tag,
		   ATbool enabled);
void TA_modifyRule(int pid, int rid, TA_Port port, TA_Expr cond,
		   TA_Expr act, ATbool enabled);
void TA_enableRule(int pid, int rid);
void TA_disableRule(int pid, int rid);
void TA_deleteRule(int pid, int rid);

void TA_atCPE(int pid, TA_Location cpe);
void TA_activateRules(int pid, TA_Port port);
int TA_getProcessState(int pid);
void TA_setProcessState(int pid, int state);

TA_Expr TA_evaluate(int pid, TA_Expr expr);

TA_Expr TA_makeExprError(char *msg, ATerm data);
TA_Expr TA_makeExprVarUnknown(char *msg);
TA_Expr TA_makeExprVar(char *var, TA_Expr value, int pos,
		       int line, int column, int length);

#endif
