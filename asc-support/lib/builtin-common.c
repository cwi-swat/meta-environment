
/* Most builtins are prefix functions, this c file contains
 * access functions on prefix functions that is used for almost 
 * all builtin functions
 */

#include <MEPT-utils.h> 
#include "builtin-common.h"
#include <assert.h>

/*{{{  PT_Tree CO_getFunctionArgument(PT_Tree function, int i) */

PT_Tree CO_getFunctionArgument(PT_Tree function, int i)
{
  /* "name" L "(" L <arg0> L "," L <arg1> L "," L <arg2> L  ... */
  /* |-----4------| |------4-----| |-----4------| |-------- ... */

  return PT_getArgsArgumentAt(PT_getTreeArgs(function),4 + 4 * i);
}

/*}}}  */

/*{{{  ATermAppl CO_unquoteAppl(ATermAppl appl)  */

ATerm CO_unquoteAppl(ATerm appl) 
{
  AFun fun;
  int arity;
  char *name = NULL;
  ATermList args = NULL;

  assert(ATgetType(appl) == AT_APPL);

  fun = ATgetAFun((ATermAppl) appl);
  arity = ATgetArity(fun);
  name = ATgetName(fun);
  args = ATgetArguments((ATermAppl) appl);
  fun = ATmakeAFun(name, arity, ATfalse);

  return (ATerm) ATmakeApplList(fun, args);
}

/*}}}  */
