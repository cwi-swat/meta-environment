/* Disclaimer: guaranteed to the spacebar */

#include <assert.h>
#include <string.h>
#include <MEPT-utils.h>

#include "pandora.h"

/*{{{  static char *quoteString(const char *input)  */

static char *quoteString(const char *input) 
{
  static char *buf = NULL;
  char *s = NULL;
  const char *p = NULL;
  int len;
  
  len = strlen(input);
  /*ATwarning("About to allocate %d bytes\n", len + 2);*/
  buf = realloc(buf, len + 2);
  
  p = input;
  s = buf;
  *s++ = '"';
  while (p && *p) {
    *s++ = *p++;
  }
  *s++ = '"';
  *s++ = '\0';

  return buf;
}

/*}}}  */

/*{{{  static ATbool isIndentedType(PT_Production production) */

static ATbool isIndentedType(PT_Production production)
{
  int symbolCount;
  PT_Symbol symbol;
  PT_Symbols productionLhs; 


  productionLhs = PT_getProductionLhs(production);
  symbolCount = PT_getSymbolsLength(productionLhs);

  if (symbolCount > 1) 
  { 
    symbol = PT_getSymbolsSymbolAt(productionLhs, 0); 
    if (PT_isSymbolLit(symbol)) 
    {
      symbol = PT_getSymbolsSymbolAt(productionLhs, symbolCount-1);
      if (PT_isSymbolLit(symbol))
      {
	return ATtrue;
      }
      return ATfalse;
    } 
  }
  return ATfalse;
}

/*}}}  */
/*{{{  static ATbool isNonTerminal(PT_Tree tree) */

static ATbool isNonTerminal(PT_Tree tree)
{
  if (PT_isLexicalInjectionProd(PT_getTreeProd(tree))) {
    return ATfalse;
  }
  if (PT_isTreeLit(tree)) {
    return ATfalse;
  }
  if (PT_isTreeLayout(tree)) {
    return ATfalse;
  }
  return ATtrue;
}

/*}}}  */

/*{{{  static BOX_Box treeToBox(PT_Tree tree)  */

static BOX_Box treeToBox(PT_Tree tree) 
{
  if (PT_isLexicalInjectionProd(PT_getTreeProd(tree))) {
    BOX_StrCon strcon = BOX_makeStrConDefault(quoteString(PT_yieldTree(tree)));
    return BOX_makeBoxString(strcon); 
  }
  else if (PT_isTreeLayout(tree)) {
    BOX_StrCon strcon = BOX_makeStrConDefault(PT_yieldTree(tree));
    return BOX_makeBoxString(strcon);
  }
  else if (PT_isTreeLit(tree)) {
    BOX_StrCon strcon = BOX_makeStrConDefault(quoteString(PT_yieldTree(tree)));
    return BOX_makeBoxString(strcon); 
  }
  else if (PT_isTreeAppl(tree)) {
    PT_Args args = PT_getTreeArgs(tree);
    BOX_BoxList boxlist = BOX_makeBoxListEmpty();

    BOX_OptLayout optLayout = BOX_makeOptLayoutAbsent();
    BOX_SpaceOptionOptions soptions = BOX_makeSpaceOptionOptionsEmpty(); 

    /* if tree has one argument */
    if (PT_isProductionInjection(PT_getTreeProd(tree))) {
      PT_Tree head = PT_getArgsHead(args);
      return treeToBox(head);
    }
    
    for (; !PT_isArgsEmpty(args); args = PT_getArgsTail(args)) {
      PT_Tree head = PT_getArgsHead(args);
      BOX_Box prettyHead = treeToBox(head);
      
      if (isNonTerminal(head)) {
        prettyHead = BOX_makeBoxI(optLayout, 
				  soptions, 
				  optLayout, 
				  optLayout, 
				  prettyHead, 
				  optLayout);
      } 
      boxlist = BOX_makeBoxListMany(prettyHead, optLayout, boxlist); 
    }
    
    boxlist = BOX_reverseBoxList(boxlist);

    if (isIndentedType(PT_getTreeProd(tree))) {
      return BOX_makeBoxV(optLayout,
			  soptions,
			  optLayout,
			  optLayout,
			  boxlist,
			  optLayout);
    } else {
      return BOX_makeBoxHv(optLayout,
			   soptions,
			   optLayout, 
			   optLayout, 
			   boxlist, 
			   optLayout);
    }  
  } 
  else {
    ATwarning("+- Unhandled parsetree type: %t\n", tree);
    return NULL;
  }
}

/*}}}  */

/*{{{  BOX_Box pandora(PT_ParseTree parsetree) */

BOX_Box pandora(PT_ParseTree parsetree)
{
  PT_Tree tree = PT_getParseTreeTop(parsetree);
  return treeToBox(tree);
}

/*}}}  */
