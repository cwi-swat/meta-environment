#include "common.h"


PT_Tree asf_normalize(PT_Tree input)
{
  return rewrite(CO_getFunctionArgument(input,0));
}
