#include <MEPT-utils.h>
#include "builtins.h"

/*{{{  ATerm getTreeBuiltin(PT_Tree tree) */

ATerm getTreeBuiltin(PT_Tree tree)
{
  ATerm pattern = ATparse("built-in(<term>)");

  if (PT_isTreeAppl(tree)) {
    PT_Production prod = PT_getTreeProd(tree);
    PT_Attributes attributes = PT_getProductionAttributes(prod);

    if (!PT_isAttributesNoAttrs(attributes)) {
      PT_Attrs attrs = PT_getAttributesAttrs(attributes);

      while (PT_hasAttrsHead(attrs)) {
	PT_Attr head = PT_getAttrsHead(attrs);

	if (PT_isAttrTerm(head)) {
	  ATerm term = PT_getAttrTerm(head);
	  ATerm name;

	  ATwarning("attr: %t\n", head); 
	  if (ATmatchTerm(term, pattern, &name)) {
	    return name;
	  }
	}


	if (!PT_hasAttrsTail(attrs)) {
	  break;
	}
	else {
	  attrs = PT_getAttrsTail(attrs);
	}
      } 

    }
  }

  return NULL;
}

/*}}}  */
