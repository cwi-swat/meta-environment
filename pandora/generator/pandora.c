/* Disclaimer: guaranteed to the spacebar(tm) */

#include <assert.h>
#include <ctype.h>
#include <string.h>
#include <MEPT-utils.h>

#include "pandora.h"

/*{{{  Declarations */
static BOX_Box treeToBox(PT_Tree tree);
/*}}}  */

/*{{{  static char *escapeQuotes(const char *input) */

static char *escapeQuotes(const char *input)
{
  static char *buf = NULL;
  const char *p;
  int len;
  char *s;

  len = strlen(input);
  buf = realloc(buf, len*2 + 1);

  p = input;
  s = buf;
  while (p && *p) {
    if (*p == '"' || *p == '\\') {
      *s++ = '\\';
    }
    *s++ = *p++;
  }
  *s++ = '\0';

  return buf;
}

/*}}}  */
/*{{{  static char *quoteString(const char *input)  */

static char *quoteString(char *input) 
{
  static char *buf = NULL;
  char *s = NULL;
  const char *p = NULL;
  int len;
  
  len = strlen(input) + 3;
  buf = realloc(buf, len);
  
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

/*{{{  static ATbool isLayout(const char *input) */

static ATbool isLayout(const char *input)
{
  const char *p = NULL;

  p = input;
  while (p && *p) {
    if (!isspace((int)*p++))
    {
      return ATfalse;
    }
  }
  return ATtrue;
}

/*}}}  */
/*{{{  static char *stripLayout(const char *input) */

static char *stripLayout(const char *input)
{
  static char *buf = NULL;
  const char *s = NULL, *f = NULL;
  int len;

  if (input == NULL)
  {
    return NULL;
  }

  len = strlen(input);
  if (len == 0 || isLayout(input))
  {
    return "";
  }

  buf = realloc(buf, len + 1);

  s = input;
  while (isspace((int)*s))
  {
    s++;
  }

  f = input + len - 1;
  while (f > s && isspace((int)*f))
  {
    f--;
  }

  len = f - s + 1;
  strncpy(buf, s, len);
  buf[len] = '\0';

  return buf;
}

/*}}}  */

/*{{{  static ATbool isIndentedType(PT_Production production) */

static ATbool isIndentedType(PT_Production production)
{
  PT_Symbol symbol;
  PT_Symbols productionLhs; 

  if (!PT_hasProductionLhs(production)) 
  {
    return ATfalse;
  }

  productionLhs = PT_getProductionLhs(production);

  ATwarning("ProductionLhs: [%t]\n", productionLhs);
  
  while (!PT_isSymbolsEmpty(productionLhs)) 
  {
    symbol = PT_getSymbolsHead(productionLhs);
    if (!PT_isOptLayoutSymbol(symbol))
    {

      ATwarning("Symbol = %t\n", symbol);
      productionLhs = PT_getSymbolsTail(productionLhs);
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

/*{{{  static BOX_Box argsSingleToBox(PT_Args arg) */

static BOX_Box argsSingleToBox(PT_Args arg)
{
  PT_Tree head = PT_getArgsHead(arg);
  return treeToBox(head);
}

/*}}}  */
/*{{{  static BOX_Box argsManyToBox(PT_Tree tree) */

static BOX_Box argsManyToBox(PT_Tree tree)
{
  BOX_BoxList boxlist = BOX_makeBoxListEmpty();
  BOX_OptLayout optLayout = BOX_makeOptLayoutAbsent();
  BOX_SpaceOptionOptions spaceOptions = BOX_makeSpaceOptionOptionsEmpty(); 
  
  PT_Args args = PT_getTreeArgs(tree);

  for (; !PT_isArgsEmpty(args); args = PT_getArgsTail(args)) 
  {
    PT_Tree head = PT_getArgsHead(args);
    BOX_Box prettyHead = treeToBox(head);

    if (isNonTerminal(head) 
	&& isIndentedType(PT_getTreeProd(tree))) 
    {
      prettyHead = BOX_makeBoxI(optLayout, 
				spaceOptions, 
				optLayout, 
				optLayout, 
				prettyHead, 
				optLayout);
    } 
    boxlist = BOX_makeBoxListMany(prettyHead, optLayout, boxlist); 
  }
  boxlist = BOX_reverseBoxList(boxlist);

  if (isIndentedType(PT_getTreeProd(tree))) 
  {
    return BOX_makeBoxV(optLayout,
			spaceOptions,
			optLayout,
			optLayout,
			boxlist,
			optLayout);
  } 
  else 
  {
    return BOX_makeBoxHv(optLayout,
			 spaceOptions,
			 optLayout, 
			 optLayout, 
			 boxlist, 
			 optLayout);
  }  
}

/*}}}  */

/*{{{  static BOX_Box terminalToBox(PT_Tree tree) */

static BOX_Box terminalToBox(PT_Tree tree)
{
  char *yield = PT_yieldTree(tree);
  char *escaped = escapeQuotes(yield);
  char *quoted = quoteString(escaped);
  BOX_StrCon strcon = BOX_makeStrConDefault(quoted);
  return BOX_makeBoxString(strcon);
}

/*}}}  */
/*{{{  static BOX_Box layoutToBox(PT_Tree tree) */

static BOX_Box layoutToBox(PT_Tree tree)
{
  BOX_BoxList boxlist = BOX_makeBoxListEmpty();
  BOX_OptLayout optLayout = BOX_makeOptLayoutAbsent();
  BOX_SpaceOptionOptions soptions = BOX_makeSpaceOptionOptionsEmpty(); 
  char *yield = PT_yieldTree(tree);

  if (!isLayout(yield)) {
    char *comment = stripLayout(yield);
    char *escaped = escapeQuotes(comment);
    char *quoted = quoteString(escaped);
    BOX_StrCon strcon = BOX_makeStrConDefault(quoted);
    return BOX_makeBoxString(strcon);
  }

  return BOX_makeBoxH(optLayout,
		      soptions,
		      optLayout,
		      optLayout,
		      boxlist,
		      optLayout);
}

/*}}}  */
/*{{{  static BOX_Box applToBox(PT_Tree tree) */

static BOX_Box applToBox(PT_Tree tree)
{
  PT_Args args = PT_getTreeArgs(tree);

  if (PT_getArgsLength(args) == 1) 
  {
    return argsSingleToBox(args);
  }

  return argsManyToBox(tree);
}

/*}}}  */

/*{{{  static BOX_Box treeToBox(PT_Tree tree)  */

static BOX_Box treeToBox(PT_Tree tree) 
{
  if (PT_isLexicalInjectionProd(PT_getTreeProd(tree))
      || PT_isTreeLit(tree)) {
    return terminalToBox(tree); 
  }
  else if (PT_isTreeLayout(tree)) {
    return layoutToBox(tree);
  }
  else if (PT_isTreeAppl(tree)) {
    return applToBox(tree);
  } 
  else {
    ATwarning("+- Unhandled parsetree type: %t\n", tree);
    return NULL;
  }
}

/*}}}  */

/*{{{  BOX_Start pandora(PT_ParseTree parsetree) */

BOX_Start pandora(PT_ParseTree parsetree)
{
  PT_Tree tree = PT_getParseTreeTop(parsetree);
  BOX_OptLayout optLayout = BOX_makeOptLayoutAbsent();
  BOX_Start start = BOX_makeStartBox(optLayout, treeToBox(tree), optLayout, 0);
  return start;
}

/*}}}  */
