#ifndef ENVIRONMENT_H
#define ENVIRONMENT_H

#include "values.h"

extern ATerm fail_env;

#define is_fail_env(env)	(ATisEqual(env,fail_env))
#define get_term(cenv)		(PT_makeTreeFromTerm(ATgetFirst(cenv)))
#define get_env(cenv)		(ATgetFirst(ATgetNext(cenv)))
#define make_cenv(t,e)		(ATmakeList(2, PT_makeTermFromTree(t), e))

PT_Tree getVariableValue(ATerm env, PT_Tree var);
ATbool isBoundVariable(ATerm env, PT_Tree var);
ATbool no_new_vars(PT_Tree trm, ATerm env);
ATerm putVariableValue(ATerm env, PT_Tree var, PT_Tree value);
ATerm putListVariableValue(ATerm env, PT_Tree var, PT_Args start, PT_Args end);
Slice getListVariableValue(ATerm env, PT_Tree var);

#endif
