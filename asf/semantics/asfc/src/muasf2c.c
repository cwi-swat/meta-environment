#include <MuASF.h>

#include "muasf2c.h"
#include "asc-apply-me.h"
#include "asc-support2-me.h"
#include "asc-support-me.h"

PT_ParseTree muasfToC(MA_Module muasf)

{
  PT_Tree term;
  ATerm reduct;
  PT_ParseTree result;

  term = ASC_applyFunction("compile-muasf","Compiler","CProgram", 1, (PT_Tree) muasf);

  ASC_initRunTime(INITIAL_TABLE_SIZE);
  register_all();
  resolve_all();
  init_all();

  reduct = innermost(term);
  result = toasfix(reduct);

  return result;
}
