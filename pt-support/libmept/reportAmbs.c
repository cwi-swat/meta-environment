
/*{{{  includes */

#include <MEPT-utils.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

/*}}}  */

/*{{{  typedef struct PT_Amb_Position_Tag */

typedef struct PT_Amb_Position_Tag {
  int line;
  int col;
  int offset;
} PT_Amb_Position;

/*}}}  */

/*{{{  static ATermList getAmbiguities(PT_Tree tree, PT_Amb_Position *current) */

static ATermList getAmbiguities(PT_Tree tree, PT_Amb_Position *current)
{
  ATermList result = ATempty;
  
  if (PT_isTreeChar(tree)) {
  /*{{{  handle single char */

    if (PT_getTreeCharacter(tree) == '\n') {
      current->col = 0;
      current->line++;
      current->offset++;
    }
    else {
      current->col++;
      current->offset++;
    }

  /*}}}  */
  }
  else if (PT_isTreeLit(tree)) {
  /*{{{  handle literal string */

    char *str = PT_getTreeString(tree);
    int len = strlen(str);
    
    while(--len >= 0) {
      if (str[len] == '\n') {
        current->col = 0;
        current->line++;
        current->offset++;
      } 
      else {
        current->col++;
        current->offset++;
      }
    }

  /*}}}  */
  }
  else if (PT_isTreeAppl(tree)) {
  /*{{{  handle normal application */

    PT_Args args = PT_getTreeArgs(tree);

    for(;PT_hasArgsHead(args); args = PT_getArgsTail(args)) {
      result = ATconcat(getAmbiguities(PT_getArgsHead(args),current), result);
    }

  /*}}}  */
  }
  else if (PT_isTreeAmb(tree)) {
  /*{{{  handle ambiguity cluster */

    PT_Args args = PT_getTreeArgs(tree); 
    PT_Args ambs = args;
    ATermList prods;
    ATerm ambWithPos;
    char *str;
    PT_Amb_Position here = *current;

    /* first collect nested ambiguities */
    for(;PT_hasArgsHead(args); args = PT_getArgsTail(args)) {
      *current = here;
      result = ATconcat(getAmbiguities(PT_getArgsHead(args),current), result);
    }

    for(prods = ATempty;PT_hasArgsHead(ambs); ambs = PT_getArgsTail(ambs)) {
      PT_Tree amb = PT_getArgsHead(ambs);
      PT_Production prod;

      assert(PT_hasTreeProd(amb));

      prod = PT_getTreeProd(amb);
      str = PT_yieldProduction(prod);
 
      prods = ATinsert(prods, ATmake("<str>",str));
    }

    ambWithPos = ATmake("ambiguity("
                        "  position(character(0),"
                        "           line(<int>),"
		        "	    col(<int>),"
		        "	    char(<int>)),"
                        "  productions([<list>]))",
                        here.line,
                        here.col,
                        here.offset,
                        prods); 
   
    result = ATinsert(result, ambWithPos); 
  /*}}}  */
  } 
  else {
    ATerror("getAmbiguities: unable to handle tree: %t\n", tree);
  }

  return result;
}

/*}}}  */

/*{{{  ATerm PT_reportTreeAmbiguities(PT_Tree tree) */

ATerm PT_reportTreeAmbiguities(PT_Tree tree)
{
  PT_Amb_Position pos = {1,0,0}; 
  ATermList ambs = getAmbiguities(tree,&pos);

  return ATmake("ambiguities(<int>,[<list>])", ATgetLength(ambs), ambs);
}

/*}}}  */
/*{{{  ATerm PT_reportParseTreeAmbiguities(PT_ParseTree parsetree) */

ATerm PT_reportParseTreeAmbiguities(PT_ParseTree parsetree)
{
  return PT_reportTreeAmbiguities(PT_getParseTreeTop(parsetree));
}

/*}}}  */
