
/*{{{  includes */

#include <MEPT-utils.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

/*}}}  */
/*{{{  defines*/

#define UNLIMITED_DEPTH -1

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

/*{{{  ATbool PT_getTreePosInfo(tree,path,start_line,start_col,end_line,end_col) */

ATbool PT_getTreePosInfo(PT_Tree tree, char **path,  int *start_line, int *start_col,
		       int *end_line, int *end_col)
{
  ATerm t = PT_TreeToTerm(tree);

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
    while(*str != 0) {
      if (*str++ == '\n') {
        *cols = 0;
        (*lines)++;
      } 
      else {
        (*cols)++;
      }
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

  if (current->maxDepth == current->curDepth) {
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
    PT_Args args = PT_getTreeArgs(tree);
    (current->curDepth)++;
    args = PT_foreachTreeInArgs(args, (PT_TreeVisitor) PT_addTreePosInfo, 
				(PT_TreeVisitorData) current);
    (current->curDepth)--;
    tree = PT_setTreeArgs(tree, args);
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

  return PT_setParseTreeTop(parsetree, PT_addTreePosInfo(tree, &current));
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
/*{{{  PT_ParseTree PT_addParseTreePosInfo(char* path, PT_ParseTree parsetree) */

PT_ParseTree PT_addParseTreePosInfo(char* path, PT_ParseTree parsetree)
{
  return  PT_addParseTreePosInfoToDepth(path, parsetree, UNLIMITED_DEPTH);
}

/*}}}  */

