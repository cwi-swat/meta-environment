#include <stdlib.h>

#include <asc-support2-me.h>
#include <MEPT-utils.h>
#include "Library.h"

ATerm rec_terminate(int cid, char* message)
{
  exit(0);
}

ATerm rewrite(int cid, ATerm trm)
{
    PT_Tree tree = PT_getParseTreeTree((PT_ParseTree) ATBunpack(trm));
    ATerm reduct = innermost(tree);
    PT_ParseTree asfix = toasfix(reduct);
    return ATmake("snd-value(normalform(<term>))", ATBpack((ATerm)asfix));
}

ATerm apply_rewrite(int cid, char* function, char* sort,ATermList args)
{
  PT_Args ptargs = PT_makeArgsEmpty();
  for(;!ATisEmpty(args);args = ATgetNext(args)) {
    ATerm head = ATBunpack(ATgetFirst(args));
    PT_Tree arg;

    if (ATisQuoted(ATgetAFun((ATermAppl) head))) {
      arg = (PT_Tree) CO_makeStrConDefault(ATwriteToString(head));
    }
    else {
      arg = PT_getParseTreeTree((PT_ParseTree) head);
    }

    ptargs = PT_makeArgsList(arg, ptargs);
  }

  return rewrite(cid, 
		 PT_ParseTreeToTerm(
                   PT_applyFunctionToArgsParseTree(function,
						   sort, 
						   PT_reverseArgs(ptargs))));
}

