
/*{{{  includes */

#include <MEPT-utils.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

/*}}}  */
/*{{{  defines*/

#define UNLIMITED_DEPTH -1

/*}}}  */

/*{{{ globals  */

static ATbool label_layout = ATfalse;
static ATbool label_literals = ATfalse;
static ATbool in_layout = ATfalse;

/*}}}  */

/*{{{  typedef struct PT_Position_Tag */

typedef struct PT_Position_Tag {
  char* path;
  int line;
  int col;

  int maxDepth;
  int curDepth;
} PT_Position;

/*}}}  */

ATerm PT_getTreePosInfoArea(PT_Tree tree)
{
  return ATgetAnnotation(PT_TreeToTerm(tree), ATparse("pos-info"));
}

/*{{{  ATbool PT_getTreePosInfo(tree,path,start_line,start_col,end_line,end_col) */

ATbool PT_getTreePosInfo(PT_Tree tree, char **path,  int *start_line, int *start_col,
		       int *end_line, int *end_col)
{
  ATerm t = PT_getTreePosInfoArea(tree);

  if (!t) {
    return ATfalse;
  }

  return ATmatch(t, "area(<str>,<int>,<int>,<int>,<int>)", path,
		 start_line, start_col, end_line, end_col);
}

/*}}}  */
/*{{{  static ATerm PT_makePosInfo(path, line1, int col1, line2, col2) */

static ATerm PT_makePosInfo(const char *path, int line1, int col1, int line2, int col2)
{
  return ATmake("area(<str>,<int>,<int>,<int>,<int>)",
                path, line1, col1, line2, col2);
}

/*}}}  */
/*{{{  PT_Tree PT_setTreePosInfo(tree, path, from_line, from_col, to_line, to_col) */

PT_Tree PT_setTreePosInfo(PT_Tree tree, const char *path, 
			  int start_line, int start_col, int to_line, int to_col)
{
  ATerm t = PT_TreeToTerm(tree);

  t = ATsetAnnotation(t, ATparse("pos-info"), 
		      PT_makePosInfo(path, start_line, start_col, to_line, to_col));

  return PT_TreeFromTerm(t);
}

/*}}}  */
/*{{{  void PT_calcTreePosInfo(PT_Tree tree, int *lines, int *cols) */

void PT_calcTreePosInfo(PT_Tree tree, int *lines, int *cols)
{
  if (PT_isTreeChar(tree)) {
    if (PT_getTreeCharacter(tree) == '\n') {
      *cols = 0;
      (*lines)++;
    }
    else {
      (*cols)++;
    }
    return;
  }

  if (PT_isTreeAppl(tree)) {
    PT_Args args = PT_getTreeArgs(tree);
    while (!PT_isArgsEmpty(args)) {
      PT_calcTreePosInfo(PT_getArgsHead(args), lines, cols);
      args = PT_getArgsTail(args);
    }
  }
  else if (PT_isTreeLit(tree)) {
    char *str = PT_getTreeString(tree);
    while(*str != '\0') {
      if (*str == '\n') {
        *cols = 0;
        (*lines)++;
      } 
      else {
        (*cols)++;
      }
      str++;
    }
  }
}

/*}}}  */
/*{{{  static PT_Tree PT_addTreePosInfo(PT_Tree tree, PT_Position* current) */

static PT_Tree PT_addTreePosInfo(PT_Tree tree, PT_Position* current)
{
  int start_line = current->line;
  int start_col  = current->col;
  int len;

  /*ATwarning("adding pos-info at depth %d to %t\n", current->curDepth, tree);*/

  if (current->maxDepth == current->curDepth) {
    PT_calcTreePosInfo(tree, &current->line, &current->col);
    return tree;
  }

  if (PT_isTreeChar(tree)) {
    if (PT_getTreeCharacter(tree) == '\n') {
      current->col = 0;
      current->line++;
    }
    else {
      current->col++;
    }
    return tree;
  }

  if (PT_isTreeAppl(tree)) {
    ATbool outermost_layout = ATfalse;
    PT_Args args = PT_getTreeArgs(tree);
    (current->curDepth)++;

    if (PT_isTreeLayout(tree)) {
      in_layout = ATtrue;
      outermost_layout = ATtrue;
    }

    args = PT_foreachTreeInArgs(args, (PT_TreeVisitor) PT_addTreePosInfo, 
				(PT_TreeVisitorData) current);

    (current->curDepth)--;
    tree = PT_setTreeArgs(tree, args);

    if (!label_layout && outermost_layout) {
      in_layout = ATfalse;
      return tree;
    }
    else if (!label_layout && in_layout) {
      return tree;
    }
  }
  else if (PT_isTreeAmb(tree)) {
    PT_Args args = PT_getTreeArgs(tree);
    PT_Args new = PT_makeArgsEmpty();
    PT_Position save = *current;

    for (;!PT_isArgsEmpty(args); args = PT_getArgsTail(args)) {
      PT_Tree arg = PT_getArgsHead(args);
      *current = save;
      new = PT_makeArgsList(PT_addTreePosInfo(arg, current), new);
      
    }

    tree = PT_makeTreeAmb(PT_reverseArgs(new));
  }
  else if (PT_isTreeLit(tree)) {
    char *str = PT_getTreeString(tree);
    len = strlen(str);
    while(--len >= 0) {
      if (str[len] == '\n') {
        current->col = 0;
        current->line++;
      } 
      else {
        current->col++;
      }
    }

    if (!label_literals) {
      return tree;
    }
  } else {
    ATwarning("unhandled tree: %s (%t)\n", PT_yieldTree(tree), tree);
  }

  return PT_setTreePosInfo(tree, current->path, start_line, start_col,
			   current->line, current->col);
}

/*}}}  */
/*{{{  PT_ParseTree PT_addParseTreePosInfoToDepth(path, parsetree, maxDepth)  */

PT_ParseTree PT_addParseTreePosInfoToDepth(char* path, PT_ParseTree parsetree,
					   int maxDepth) 
{
  PT_Tree tree = PT_getParseTreeTop(parsetree);
  PT_Position current;


  assert(maxDepth >= 0 || maxDepth == UNLIMITED_DEPTH);

  current.path = path;
  current.line = 1;
  current.col  = 0;
  current.maxDepth = maxDepth;
  current.curDepth = 0;

  parsetree = PT_setParseTreeTop(parsetree, PT_addTreePosInfo(tree, &current));


  return parsetree;
}

/*}}}  */
/*{{{  PT_ParseTree PT_addTreePosInfoToDepth(path, tree, maxDepth, start_l, start_c) */

PT_Tree PT_addTreePosInfoToDepth(char* path, PT_Tree tree,
				 int maxDepth, int start_line, int start_col) 
{
  PT_Position current;
 
  assert(maxDepth >= 0 || maxDepth == UNLIMITED_DEPTH);

  current.path = path;
  current.line = start_line;
  current.col  = start_col;
  current.maxDepth = maxDepth;
  current.curDepth = 0;

  return PT_addTreePosInfo(tree, &current);
}

/*}}}  */
/*{{{  PT_Tree PT_addTreePosInfoSome(path, tree, dep, lay, lit, sl, sc) */

PT_Tree PT_addTreePosInfoSome(char *path, PT_Tree tree,
			      int depth, ATbool layout, ATbool literals,
			      int start_line, int start_col)
{
  PT_Tree result = NULL;
  label_layout = layout;
  label_literals = literals;

  result = PT_addTreePosInfoToDepth(path, tree, depth, start_line, start_col);
  
  label_layout = ATfalse;
  label_literals = ATfalse;

  return result;
}

/*}}}  */
/*{{{  PT_ParseTree PT_addParseTreePosInfo(char* path, PT_ParseTree parsetree) */

PT_ParseTree PT_addParseTreePosInfo(char* path, PT_ParseTree parsetree)
{
  return  PT_addParseTreePosInfoToDepth(path, parsetree, UNLIMITED_DEPTH);
}

/*}}}  */
/*{{{  PT_ParseTree PT_addParseTreePosInfoSome(char *path, PT_ParseTree parsetree, */

PT_ParseTree PT_addParseTreePosInfoSome(char *path, PT_ParseTree parsetree,
					int depth, 
					ATbool layout, 
					ATbool literals)
{
  PT_ParseTree result = NULL;
  label_layout = layout;
  label_literals = literals;

  result = PT_addParseTreePosInfoToDepth(path,parsetree,depth);
  
  label_layout = ATfalse;
  label_literals = ATfalse;

  return result;
}

/*}}}  */
