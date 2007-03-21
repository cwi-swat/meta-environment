/* $Id$ */

#include <MEPT-utils.h>
#include "builtins.h"


ATerm getTreeBuiltin(PT_Tree tree) {
  AFun builtin = -1;
    
  if (builtin == -1) {
    builtin = ATmakeAFun("built-in", 1, ATfalse);
    ATprotectAFun(builtin);
  }

  if (PT_isTreeAppl(tree)) {
    PT_Production prod = PT_getTreeProd(tree);
    PT_Attributes attributes = PT_getProductionAttributes(prod);

    if (!PT_isAttributesNoAttrs(attributes)) {
      PT_Attrs attrs = PT_getAttributesAttrs(attributes);

      while (PT_hasAttrsHead(attrs)) {
	PT_Attr head = PT_getAttrsHead(attrs);

	if (PT_isAttrTerm(head)) {
	  ATerm term = PT_getAttrTerm(head);

	  if (ATgetType(term) == AT_APPL &&
	      ATgetAFun((ATermAppl) term) == builtin) {
	    return ATgetArgument((ATermAppl) term, 0);
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

