/* Disclaimer: guaranteed to the spacebar */

#include <assert.h>
#include <string.h>
#include <MEPT-utils.h>

#include "pandora.h"

/*{{{  BOX_BoxList pandora(PT_ParseTree parsetree) */

BOX_Box treeToBox(PT_Tree tree) {
  if (PT_isTreeLexical(tree)) {
    BOX_StrCon strcon = BOX_makeStrConDefault(PT_yieldTree(tree)); 
    ATprintf("+- Lexical %t\n", strcon);
    return(BOX_makeBoxString(strcon)); 
  }
  else if (PT_isTreeLayout(tree)) {
    BOX_StrCon strcon = BOX_makeStrConDefault(PT_yieldTree(tree));
    ATprintf("+- Layout %t\n", strcon);
    return(BOX_makeBoxString(strcon));
  }
  else if (PT_isTreeLit(tree)) {
    BOX_StrCon strcon = BOX_makeStrConDefault(PT_yieldTree(tree));
    ATprintf("+- Literal %t\n", strcon);
    return(BOX_makeBoxString(strcon)); 
  }
  else if (PT_isTreeAppl(tree)) {
    PT_Args args = PT_getTreeArgs(tree);
    BOX_BoxList boxlist = BOX_makeBoxListEmpty();
    
    BOX_OptLayout optLayout = BOX_makeOptLayoutAbsent();
    BOX_SOptions soptions = BOX_makeSOptionsDefault(BOX_makeSOptionListEmpty()); 
    printf("+- TreeAppl\n"); 
    
    for (; !PT_isArgsEmpty(args); args = PT_getArgsTail(args)) {
      PT_Tree head = PT_getArgsHead(args);
      boxlist = BOX_makeBoxListMany(treeToBox(head), optLayout, boxlist); 
    }

    return(BOX_makeBoxH(optLayout, 
			soptions, 
			optLayout, 
			optLayout, 
			boxlist, 
			optLayout));
  } 
  else {
    printf("+- Error\n");
    return NULL;
  }
}

BOX_Box pandora(PT_ParseTree parsetree)
{
  PT_Tree tree = PT_getParseTreeTop(parsetree);
  return treeToBox(tree);
}

/*}}}  */
