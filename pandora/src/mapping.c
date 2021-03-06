/* Disclaimer: guaranteed to the spacebar(tm) */

#include <ctype.h>
#include <string.h>
#include <MEPT-utils.h>
#include <PTMEPT-utils.h>

#include "mapping.h"

/*{{{ Defines */
#define SEPLISTELEMLENGTH 4
#define HSOPTION "0"
/* }}} */
/*{{{  Declarations */
static BOX_Box treeToBox(PT_Tree tree, ATbool isLex);
static PT_Tree getTree(PT_Tree tree);
/*}}}  */

/*{{{  BOX_LexStrCon BOX_makeLexStrCon(const char *str) */

BOX_LexStrCon BOX_makeLexStrCon(const char *str)
{
  /* notice the hack */
  return (BOX_LexStrCon) PTPT_makeLexStrCon(str);
}

/*}}}  */
/*{{{  BOX_StrCon BOX_makeStrCon(const char *str) */

BOX_StrCon BOX_makeStrCon(const char *str)
{
  return BOX_makeStrConLexToCf(BOX_makeLexStrCon(str));
}

/*}}}  */
/*{{{  BOX_NatCon BOX_makeNatCon(int val) */

BOX_NatCon BOX_makeNatCon(int val)
{
  return (BOX_NatCon) PTPT_liftNatCon(val);
}

/*}}}  */

/*{{{  static ATbool hasProductionFromBoxAttribute(PT_Production prod) */

static ATbool hasProductionFromBoxAttribute(PT_Production prod)
{
  return PT_hasProductionCertainAttr(prod,
				     PT_makeAttrTerm(ATparse("from-box")));
}

/*}}}  */
/*{{{  static ATbool hasProductionToBoxAttribute(PT_Production prod) */

static ATbool hasProductionToBoxAttribute(PT_Production prod)
{
  return PT_hasProductionCertainAttr(prod,
				     PT_makeAttrTerm(ATparse("to-box")));
}

/*}}}  */
/*{{{  static ATbool hasProductionToBoxAttribute(PT_Production prod) */

static ATbool hasProductionLayoutToBoxAttribute(PT_Production prod)
{
  return PT_hasProductionCertainAttr(prod,
				     PT_makeAttrTerm(ATparse("layout-to-box")));
}

/*}}}  */
 
/*{{{  static ATbool isIndentedType(PT_Production production) */

static ATbool isIndentedType(PT_Production production)
{
  ATbool expectTerminal = ATtrue;
  PT_Symbol symbol;
  PT_Symbols productionLhs; 

  if (!PT_hasProductionLhs(production)) {
    return ATfalse;
  }
  
  productionLhs = PT_getProductionLhs(production);

  if (PT_getSymbolsLength(productionLhs) < 3) {
    return ATfalse;
  }

  while (!PT_isSymbolsEmpty(productionLhs)) {
    symbol = PT_getSymbolsHead(productionLhs);
    if (!PT_isOptLayoutSymbol(symbol)) {
      if (expectTerminal) {
	if (!PT_isSymbolLit(symbol)) {
	  return ATfalse;
	}
	expectTerminal = ATfalse;
      } else {
	if (PT_isSymbolLit(symbol)) {
	  return ATfalse;
	}
	expectTerminal = ATtrue;
      }	
    }
    productionLhs = PT_getSymbolsTail(productionLhs);
  }

  return ATtrue;
}

/*}}}  */
/*{{{  static ATbool isNonTerminal(PT_Tree tree) */

static ATbool isNonTerminal(PT_Tree tree)
{
  return !PT_isTreeChar(tree) && !PT_isTreeLit(tree);
}

/*}}}  */
/*{{{  static ATbool isWhitespace(PT_Tree tree) */

static ATbool isWhitespace(PT_Tree tree)
{
  if (PT_isTreeChar(tree)) {
    return isspace(PT_getTreeCharacter(tree)); 
  } 
  else if (PT_hasTreeArgs(tree)) {
    PT_Args args = PT_getTreeArgs(tree);

    while (!PT_isArgsEmpty(args)) {
      PT_Tree head = PT_getArgsHead(args);
      if (!isWhitespace(head)) {
	return ATfalse;
      }
      args = PT_getArgsTail(args);
    }
  }

  return ATtrue;
}

/*}}}  */

/*{{{  static BOX_Box argsSingleToBox(PT_Args arg, ATbool isLex) */

static BOX_Box argsSingleToBox(PT_Args arg, ATbool isLex)
{
  PT_Tree head = PT_getArgsHead(arg);
  return treeToBox(head, isLex);
}

/*}}}  */
/*{{{  static BOX_BoxList argsManyToBox(PT_Args args, ATbool isLex, ATbool indent) */

static BOX_BoxList argsManyToBox(PT_Args args, ATbool isLex, ATbool indent)
{
  BOX_BoxList boxList = BOX_makeBoxListEmpty();
  BOX_OptLayout optLayout = BOX_makeOptLayoutAbsent();
  
  while (!PT_isArgsEmpty(args)) {
    PT_Tree head = PT_getArgsHead(args);
    BOX_Box prettyHead = treeToBox(head, isLex);

    if (prettyHead != NULL && prettyHead != BOX_makeEmptyHBox()) {
      if (isNonTerminal(head) && indent) {
	prettyHead = BOX_makeIBox(prettyHead);
      } 
      boxList = BOX_makeBoxListMany(prettyHead, optLayout, boxList); 
    }

    args = PT_getArgsTail(args);
  }

  return BOX_reverseBoxList(boxList);
}

/*}}}  */
/*{{{  static BOX_BoxList argsManyToBox(PT_Args args, ATbool isLex, ATbool indent) */

static BOX_BoxList argsManySpliceToBox(PT_Args args, ATbool isLex)
{
  BOX_BoxList boxList = BOX_makeBoxListEmpty();
  BOX_OptLayout optLayout = BOX_makeOptLayoutAbsent();
  
  while (!PT_isArgsEmpty(args)) {
    PT_Tree head = PT_getArgsHead(args);
    BOX_Box prettyHead = treeToBox(head, isLex);

    if (prettyHead != NULL) {
      boxList = BOX_makeBoxListMany(prettyHead, optLayout, boxList); 
    }

    args = PT_getArgsTail(args);
  }

  return BOX_reverseBoxList(boxList);
}

/*}}}  */

/*{{{  static BOX_Box applToBox(PT_Tree tree, ATbool isLex) */

static BOX_Box applToBox(PT_Tree tree, ATbool isLex)
{
  PT_Args args = PT_getTreeArgs(tree);
  BOX_BoxList boxList;
  ATbool indent;

  if (PT_getArgsLength(args) == 1) {
    return argsSingleToBox(args, isLex);
  }
  
  indent = isIndentedType(PT_getTreeProd(tree));
  boxList = argsManyToBox(args, isLex, indent);

  if (!isLex) {
    if (indent) {
      return BOX_makeVBox(boxList);
    } else {
      return BOX_makeHVBox(boxList);
    }  
  }

  return BOX_makeHBoxWithHs(boxList, HSOPTION);
}

/*}}}  */

/*{{{  static BOX_BoxList sepListToBox(PT_Args args, ATbool isLex, ATbool indent) */

static BOX_BoxList sepListToBox(PT_Args args, ATbool isLex, ATbool indent)
{
  BOX_OptLayout optLayout = BOX_makeOptLayoutAbsent();
  BOX_BoxList boxList = BOX_makeBoxListEmpty();

  while (!PT_isArgsEmpty(args)) {
    BOX_Box listArgBox; 

    if (PT_getArgsLength(args) >= SEPLISTELEMLENGTH) {
      int i;
      PT_Args slice = PT_sliceArgs(args, 0, SEPLISTELEMLENGTH);
      BOX_BoxList elem = argsManyToBox(slice, isLex, indent);
      listArgBox = BOX_makeHBoxWithHs(elem, HSOPTION);

      for (i = 0; i < SEPLISTELEMLENGTH; i++) {
	args = PT_getArgsTail(args);
      }
    }
    else {
      listArgBox = treeToBox(PT_getArgsHead(args), isLex);
      args = PT_getArgsTail(args);
    }

    boxList = BOX_makeBoxListMany(listArgBox, optLayout, boxList);
  }

  return BOX_reverseBoxList(boxList);
}

/*}}}  */
/*{{{  static BOX_Box listToBox(PT_Tree tree, ATbool isLex) */

static BOX_Box listToBox(PT_Tree tree, ATbool isLex)
{
  PT_Production production = PT_getTreeProd(tree);
  PT_Args args = PT_getTreeArgs(tree);
  PT_Symbol symbol = PT_getProductionRhs(production);
  ATbool indent;

  BOX_BoxList boxList = BOX_makeBoxListEmpty();
  
  if (PT_isArgsEmpty(args)) {
      return BOX_makeHBox(boxList);
  }

  symbol = PT_getSymbolSymbol(symbol);
  indent = isIndentedType(production);

  if (PT_isSymbolIterStarSep(symbol) || PT_isSymbolIterPlusSep(symbol)) {
    boxList = sepListToBox(args, isLex, indent);
  } else {
    boxList = argsManyToBox(args, isLex, indent);
  }

  if (BOX_isBoxListEmpty(boxList)) {
    return BOX_makeEmptyHBox();
  }

  if (isLex) {
    return BOX_makeHBoxWithHs(boxList, HSOPTION);
  } else {
    return BOX_makeVBox(boxList);
  }
}

/*}}}  */
/*{{{  static BOX_Box listSpliceToBox(PT_Tree tree, ATbool isLex) */

static BOX_BoxList listSpliceToBox(PT_Tree tree, ATbool isLex)
{
  PT_Production production = PT_getTreeProd(tree);
  PT_Args args = PT_getTreeArgs(tree);
  PT_Symbol symbol = PT_getProductionRhs(production);
  BOX_BoxList boxList = BOX_makeBoxListEmpty();
  
  if (PT_isArgsEmpty(args)) {
      return boxList;
  }

  symbol = PT_getSymbolSymbol(symbol);

  boxList = argsManySpliceToBox(args, isLex);

  return boxList;
}

/*}}}  */

/*{{{  static PT_Tree getTree(PT_Tree tree) */

static PT_Tree getTree(PT_Tree tree)
{
  PT_Args args = PT_getTreeArgs(tree);
  PT_Tree treeTree = NULL;

  /* JURGEN: This does not work with productions like:
   * "box2" `X` "(" Box ")" -> X   {from-box}
   * `X` "2box" "(" X   ")" -> Box {to-box}
   */

  while (!PT_isArgsEmpty(args)) {
    PT_Tree arg = PT_getArgsHead(args);

    if (!PT_isTreeLayout(arg) && !PT_isTreeLit(arg)) {
      treeTree = arg;
    }
    args = PT_getArgsTail(args);
  }

  return treeTree;
}

/*}}}  */
/*{{{  static PT_Tree getTree(PT_Tree tree) */

static PT_Tree getLayoutTree(PT_Tree tree)
{
  PT_Args args = PT_getTreeArgs(tree);
  PT_Tree treeTree = NULL;

  while (!PT_isArgsEmpty(args) && treeTree == NULL) {
    PT_Tree arg = PT_getArgsHead(args);

    if (PT_isTreeLayout(arg)) {
      treeTree = arg;
    }
    args = PT_getArgsTail(args);
  }

  return treeTree;
}

/*}}}  */

/*{{{  static BOX_Box processTree(PT_Tree tree, ATbool isLex) */

static BOX_Box processTree(PT_Tree tree, ATbool isLex)
{
  PT_Tree treeTree = getTree(tree);

  if (treeTree) {
    return treeToBox(treeTree, isLex);
  }
  else {
    return BOX_makeEmptyHBox();
  }
}

/*}}}  */
/*{{{  static BOX_Box processTree(PT_Tree tree, ATbool isLex) */

static BOX_Box processLayoutTree(PT_Tree tree, ATbool isLex)
{
  PT_Tree treeTree = getLayoutTree(tree);

  if (treeTree) {
    return treeToBox(treeTree, isLex);
  }
  else {
    return BOX_makeEmptyHBox();
  }
}

/*}}}  */

/*{{{  static PT_Tree transformBox(PT_Tree tree, ATbool isLex) */

static PT_Tree transformBox(PT_Tree tree, ATbool isLex)
{
  PT_Production  boxProd = PT_getTreeProd(tree);
  PT_Args args = PT_getTreeArgs(tree);
  PT_Args boxArgs = PT_makeArgsEmpty();

  /* TODO: rewrite use of append (very expensive!) */
  while (!PT_isArgsEmpty(args)) {
    PT_Tree arg = PT_getArgsHead(args);
    
    if (PT_isTreeLexical(arg) || PT_isTreeLayout(arg) || PT_isTreeLit(arg)) {
      boxArgs = PT_appendArgs(boxArgs, arg);
    } 
    else if (PT_isTreeAppl(arg)) {
      PT_Production prod = PT_getTreeProd(arg);

      if (hasProductionToBoxAttribute(prod)) {
	if (PT_prodHasIterAsRhs(prod)) {
	  PT_Tree listTree = getTree(arg);

	  if (PT_isTreeApplList(listTree)) {
	    /* splice in the elements of the list */
	    boxArgs = PT_concatArgs(boxArgs, 
				    (PT_Args) listSpliceToBox(getTree(arg), 
							      isLex));
	  }
	  else {
	    ATwarning("pandora: ignoring wrong to-box tree, to Box* does not have a list as argument.\n");
	  }

	}
	else {
	  BOX_Box boxArg = processTree(arg, isLex);

	  if (boxArg != NULL) {
	    boxArgs = PT_appendArgs(boxArgs, 
				    PT_TreeFromTerm(BOX_BoxToTerm(boxArg)));
	  }
	}
      }
      else if (hasProductionLayoutToBoxAttribute(prod)) {
	  BOX_Box boxArg = processLayoutTree(arg, isLex);

	  if (boxArg != NULL) {
	    boxArgs = PT_appendArgs(boxArgs, 
				    PT_TreeFromTerm(BOX_BoxToTerm(boxArg)));
	  }
      }	
      else {
        boxArgs = PT_appendArgs(boxArgs, transformBox(arg, isLex));
      }
    }
    else if (PT_isTreeAmb(arg)) {
      return transformBox(PT_getArgsHead(PT_getTreeArgs(arg)), isLex);
    }
    else {
      PT_Tree res = transformBox(arg, isLex);
      boxArgs = PT_appendArgs(boxArgs, res);
    }
    args = PT_getArgsTail(args);
  }

  return PT_makeTreeAppl(boxProd, boxArgs);
}

/*}}}  */
/*{{{  static BOX_Box processBox(PT_Tree tree, ATbool isLex) */

static BOX_Box processBox(PT_Tree tree, ATbool isLex)
{
  PT_Args args = PT_getTreeArgs(tree);

  while (!PT_isArgsEmpty(args)) {
    PT_Tree arg = PT_getArgsHead(args);

    if (!PT_isTreeLayout(arg) && !PT_isTreeLit(arg)) {
      PT_Symbol sym = PT_getProductionRhs(PT_getTreeProd(arg));

      if (PT_isEqualSymbol(sym, PT_makeSymbolCf(PT_makeSymbolSort("Box")))) {
	return BOX_BoxFromTerm(PT_TreeToTerm(transformBox(arg, isLex)));
      }
      else {
	ATwarning("FromBox production is wrong (no Box child): %t\n", PT_getTreeProd(arg));
	return BOX_makeEmptyHBox();
      }
    }
    args = PT_getArgsTail(args);
  }

  return BOX_makeEmptyHBox();
}

/*}}}  */
/*{{{  static BOX_Box treeToBox(PT_Tree tree)  */

static BOX_Box treeToBox(PT_Tree tree, ATbool isLex) 
{
  if (PT_isTreeChar(tree)) {
    char ch = PT_getTreeCharacter(tree);
    const char yield[2] = {ch, '\0'};
    BOX_StrCon strcon = BOX_makeStrCon(yield);
    return BOX_makeBoxString(strcon);
  }
  else if (PT_isArgsEmpty(PT_getTreeArgs(tree))) {
    return BOX_makeEmptyHBox();
  }
  else if (hasProductionFromBoxAttribute(PT_getTreeProd(tree))) {
    return processBox(tree, isLex);
  }
  else if (PT_isProductionList(PT_getTreeProd(tree))) {
    return listToBox(tree, isLex); 
  }
  else if (!isLex && (PT_isTreeLexical(tree) || PT_isTreeLit(tree))) {
    if (isWhitespace(tree)) {
      return NULL;
    } else {
      return treeToBox(tree, ATtrue); 
    }
  }
  else if (PT_isTreeLayout(tree)) {
    BOX_Box result = applToBox(tree, isLex);
    if (result == NULL) {
      return BOX_makeEmptyHBox();
    }
    else {
      return result;
    }
  }
  else if (PT_isTreeAppl(tree)) {
    return applToBox(tree, isLex);
  } 
  else if (PT_isTreeAmb(tree)) {
    PT_Args ambs;

    ambs = PT_getTreeArgs(tree);

    if (PT_getArgsLength(ambs) > 0) {
      ATwarning("pandora: warning: choosing first alternative of ambiguity node\n");
      return treeToBox(PT_getArgsHead(ambs),isLex);
    }
    else {
      ATwarning("pandora: ignoring empty ambiguity cluster\n");
      return NULL;
    }
  }
  else {
    ATwarning("Unhandled parsetree type: %t\n", tree);
    return NULL;
  }
}

/*}}}  */

/*{{{  BOX_Start pandora(PT_ParseTree parsetree) */

BOX_Start pandora(PT_ParseTree parsetree)
{
  PT_Tree tree = PT_getParseTreeTop(parsetree);
  BOX_OptLayout optLayout = BOX_makeOptLayoutAbsent();
  BOX_Start start = BOX_makeStartBox(optLayout, treeToBox(tree, ATfalse), 
				     optLayout, 0);
  return start;
}

/*}}}  */
