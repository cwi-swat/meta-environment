#include <MEPT-utils.h>
#include "common.h"
#include "Library.h"


PT_Tree unparse(PT_Tree input)
{
  PT_Tree tree = CO_getFunctionArgument(input,0);

  return PT_makeTreeLexToCf(PT_makeSymbolSort("Bytes"), 
	  PT_makeTreeFlatLexicalFromString(PT_yieldTree(tree)));
}

