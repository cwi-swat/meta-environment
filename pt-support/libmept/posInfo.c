#include <MEPT-utils.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>


#define UNLIMITED_DEPTH -1

typedef struct PT_Position_Tag {
  char* path;
  int line;
  int col;

  int maxDepth;
  int curDepth;
} PT_Position;

static ATerm PT_makePosInfo(const char *path, int line1, int col1, 
                            int line2, int col2)
{
  return ATmake("area(<str>,<int>,<int>,<int>,<int>)",
                path, line1, col1, line2, col2);
}

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

  return PT_makeTreeFromTerm(
          ATsetAnnotation(
            PT_makeTermFromTree(tree),
            ATparse("pos-info"), 
            PT_makePosInfo(current->path, start_line, start_col, 
                                 current->line, current->col)));
}

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

PT_ParseTree PT_addParseTreePosInfo(char* path, PT_ParseTree parsetree)
{
  return  PT_addParseTreePosInfoToDepth(path, parsetree, UNLIMITED_DEPTH);
}

