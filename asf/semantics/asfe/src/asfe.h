/*
  $Id$
 */

#include <ASFME-utils.h>
#include <MEPT.h>

#define MAX_DEPTH 2000

ATerm evaluator(char *name, PT_ParseTree parseTree, ASF_CondEquationList eqs, 
		ATerm debug, ATbool remove_layout, ATbool allow_ambs);

/* toolbus interface */
ATerm interpret(int cid, char *modname, ATerm trm, ATerm eqs, ATerm debug);

/* error interface */
void RWsetError(const char *message, ATerm subject);
ATerm RWgetError();
void  RWclearError();

/* Variables */
extern ATbool runVerbose;
extern ATerm equations_db;
extern ATerm fail_env;
extern ATerm posinfo;
extern ATerm rewrite_error;
extern ASF_Tag tagCurrentRule;
extern AFun list_var, plain_var;

/* variable environment interface */
PT_Tree getVariableValue(ATerm env, PT_Tree var, PT_Symbol symbol);
#define is_fail_env(env)	(ATisEqual(env,fail_env))
#define get_term(cenv)		(PT_makeTreeFromTerm(ATgetFirst(cenv)))
#define get_env(cenv)		(ATgetFirst(ATgetNext(cenv)))
#define make_cenv(t,e)		(ATmakeList(2, PT_makeTermFromTree(t), e))

typedef ATermAppl Slice;
PT_Args appendSlice(PT_Args list, Slice slice);
