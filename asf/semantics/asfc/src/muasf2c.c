#include <MuASF.h>

#include "muasf2c.h"
#include "asc-support2-me.h"
#include "asc-support-me.h"

extern void register_Compiler();
extern void resolve_Compiler();
extern void init_Compiler();

PT_ParseTree muasfToC(MA_Module muasf)

{
  PT_Tree term;
  ATerm reduct;
  PT_Tree result;

  term = PT_applyFunctionToTree("compile-muasf", "CProgram", 1, (PT_Tree)muasf);

  ASC_initRunTime(INITIAL_TABLE_SIZE);

  register_Compiler();
  resolve_Compiler();
  init_Compiler();

  reduct = innermost(term);
  result = toasfix(reduct);

  return PT_makeValidParseTreeFromTree(result);
}
