#include <asc-support2-me.h>
#include <MEPT-utils.h>

ATerm rewrite(int cid, ATerm trm)
{
    PT_Tree tree = PT_getParseTreeTree((PT_ParseTree) trm);
    ATerm reduct = innermost(tree);
    PT_ParseTree asfix = toasfix(reduct);
    return ATmake("snd-result(normalform(<term>))", (ATerm) asfix);
}

ATerm apply(int cid, char* function, char* sort,ATermList args)
{
  PT_Args ptargs = PT_makeArgsEmpty();
  for(;!ATisEmpty(args);args = ATgetNext(args)) {
    PT_Tree arg = PT_getParseTreeTree((PT_ParseTree)ATgetFirst(args));
    ptargs = PT_makeArgsList(arg, ptargs);
  }

  return rewrite(cid, PT_ParseTreeToTerm(
 PT_applyFunctionToArgsParseTree(function,sort, PT_reverseArgs(ptargs))));
}

