#include "muasf2c.h"
#include "asc-apply-me.h"
#include "asc-support2-me.h"

ATerm MuASF2C(MA_Module muasf)
{
  PT_Tree term;
  ATerm reduct;
  ATerm result;

  term = ASC_applyFunction("MuASF2C","Compiler","CProgram", 1, (PT_Tree) muasf);

  ASC_initRunTime(INITIAL_TABLE_SIZE);
  register_all();
  resolve_all();
  init_all();

  reduct = innermost(term);
  result = toasfix(reduct);

  return result;
}
