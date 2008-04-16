/* $Id: posInfo.c 18292 2006-04-12 02:08:09Z jurgenv $ */

/**
 * \file
 * Position information is an important feature in software analysis,
 * transformation and visualization. The Location data-structure standardizes
 * this in Location.h. This file contains algorithms to annotate parse forests
 * with the absolute locations of each node. The benefit is that each node,
 * individually carries the information where it came from. This is useful
 * in source code analysis, and in error reporting etc. See also MEPT-origins.h.
 *
 * The drawback of this distribution of location information is that it
 * makes each node unique: effectively killing the maximal sharing of parse
 * tree nodes. Note that it does NOT have an effect on the sharing of the
 * (redundant) representation of productions and symbols. 
 */
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#include <MEPT-posinfo.h>
#include <MEPT-layout.h>
#include <MEPT-visitors.h>
#include <MEPT-yield.h>

#define POS_INFO_ANNO "pos-info"
#define UNLIMITED_DEPTH -1



static ATbool label_layout = ATfalse;
static ATbool label_literals = ATfalse;
static ATbool in_layout = ATfalse;
static ATermTable cache = NULL;


static ATerm makeKey(int offset, PT_Tree tree)
{
	return (ATerm) ATmakeAppl2(ATmakeAFun("key",2,ATfalse), PT_TreeToTerm(tree), 
			(ATerm) ATmakeInt(offset));
}

static void initCache() 
{
	cache = ATtableCreate(1024, 75);
}

static void cleanupCache()
{
	ATtableDestroy(cache);
}

static void cacheTree(int offset, PT_Tree tree, PT_Tree annotated)
{
	ATtablePut(cache, makeKey(offset, tree), PT_TreeToTerm(annotated));
}

static PT_Tree getCachedTree(int offset, PT_Tree tree)
{
	return PT_TreeFromTerm(ATtableGet(cache, makeKey(offset, tree)));
}

	

typedef struct PT_Position_Tag {
  const char* path;
  int line;
  int col;
  int offset;

  int maxDepth;
  int curDepth;
} PT_Position;


typedef struct PT_PosInFile {
  int line;
  int col;
  int offset;
} PT_PosInFile;



ATbool PT_hasTreeLocation(PT_Tree tree)
{
  return ATgetAnnotation(PT_TreeToTerm(tree), ATparse(POS_INFO_ANNO)) != NULL;
}


ERR_Location PT_getTreeLocation(PT_Tree tree)
{
  return ERR_LocationFromTerm(
           ATgetAnnotation(PT_TreeToTerm(tree), ATparse(POS_INFO_ANNO)));
}


PT_Tree PT_removeTreeLocation(PT_Tree tree)
{
  return PT_TreeFromTerm(ATremoveAnnotation(PT_TreeToTerm(tree), ATparse(POS_INFO_ANNO)));
}



ATbool PT_getTreePosInfo(PT_Tree tree, char **path,  int *start_line, int *start_col,
		       int *end_line, int *end_col)
{
  ERR_Location location = PT_getTreeLocation(tree);
  ERR_Area area;

  if (!location) {
    return ATfalse;
  }

  area = ERR_getLocationArea(location);
  *path = ERR_getLocationFilename(location);
  *start_line= ERR_getAreaBeginLine(area);
  *start_col= ERR_getAreaBeginColumn(area);
  *end_line= ERR_getAreaEndLine(area);
  *end_col= ERR_getAreaEndColumn(area);

  return ATtrue;
}


static ATerm PT_makePosInfo(const char *path, int line1, int col1, 
                                              int line2, int col2,
                                              int offset, int length)
{
  ERR_Area area = ERR_makeAreaArea(line1, col1, line2, col2, offset, length);
  ERR_Location location = ERR_makeLocationAreaInFile(path, area);

  return (ATerm) location;
}


static PT_Tree PT_setTreePosInfo(PT_Tree tree, const char *path, 
			  int start_line, int start_col, 
                          int to_line, int to_col,
                          int offset, int length)
{
  ATerm t = PT_TreeToTerm(tree);

  t = ATsetAnnotation(t, ATparse(POS_INFO_ANNO), 
		      PT_makePosInfo(path, start_line, start_col, 
                                           to_line, to_col, 
                                           offset, length));

  return PT_TreeFromTerm(t);
}


static void PT_calcTreePosInfo(PT_Tree tree, int *lines, int *cols, int *offset)
{
  if (PT_isTreeChar(tree)) {
    (*offset)++;

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
      PT_calcTreePosInfo(PT_getArgsHead(args), lines, cols, offset);
      args = PT_getArgsTail(args);
    }
  }
}

/* The volatile attribute fixes a bug (#674) on Darwin; but we do not know 
 * why. The bug dissappears when instruction scheduling optimizations are
 * turned off, which inspired us to try volatile. 
 * The volatile was removed now, since apigen generates casts via a union
 * that fixes problems with type punned aliasing. 
 */ 
static PT_Tree PT_addTreePosInfo(/*volatile*/ PT_Tree tree, PT_Position* current)
{
  PT_Tree input = tree;
  int start_line = current->line;
  int start_col  = current->col;
  int start_offset  = current->offset;
  PT_Tree result = getCachedTree(current->offset, tree);

  if (result != NULL) {
	  ERR_Location loc = PT_getTreeLocation(result);
	  ERR_Area area = ERR_getLocationArea(loc);
	  current->col = ERR_getAreaEndColumn(area);
	  current->line = ERR_getAreaEndLine(area);
	  current->offset += ERR_getAreaLength(area);
	  return result;
  }

  if (current->maxDepth == current->curDepth) {
    PT_calcTreePosInfo(tree, &current->line, &current->col, &current->offset);
    return tree;
  }

  if (PT_isTreeChar(tree)) {
    current->offset++;
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
    PT_Position newPos = save;
    PT_Args cycles = PT_makeArgsEmpty();

    for (;!PT_isArgsEmpty(args); args = PT_getArgsTail(args)) {
      PT_Tree arg = PT_getArgsHead(args);
      PT_Tree newArg;
      *current = save;
      newArg = PT_addTreePosInfo(arg, current);

      if (current->offset != save.offset) {
	/* only update newPos if this amb was not a cycle */
	newPos = *current;
	/* add the non-cycle */
	new = PT_makeArgsMany(newArg, new);
      }
      else if (newPos.offset == save.offset) {
	/* did not process a non-cycle yet, so this cycle has to be
	 * revisited.
	 */
	/* delay the not correctly annotated cycle */
	cycles = PT_makeArgsMany(arg, cycles);
      }
      else {
	/* add the correctly annotated cycles */
	new = PT_makeArgsMany(newArg, new);
      }
    }

    /* if the last amb was a cycle, we want the positions after
     * an amb that was not a cycle
     */
    *current = newPos;

    /* now re-annotate the not correctly annotated cycles */
    for ( ; !PT_isArgsEmpty(cycles); cycles = PT_getArgsTail(cycles)) {
      PT_Tree arg = PT_getArgsHead(cycles);
      new = PT_makeArgsMany(PT_addTreePosInfo(arg, current), new);
    }


    tree = PT_makeTreeAmb(PT_reverseArgs(new));
  }
  else if (!PT_isTreeCycle(tree)) {
    ATwarning("unhandled tree: %s (%t)\n",
	      PT_yieldTreeToString(tree, ATfalse),
	      tree);
  }

  result = PT_setTreePosInfo(tree, current->path, start_line, start_col,
			   current->line, current->col, 
                            start_offset, (current->offset - start_offset));

  assert(PT_getTreeLocation(result) != NULL);
  cacheTree(start_offset, input, result);

  return result;
}


PT_ParseTree PT_addParseTreePosInfoToDepth(const char* path,
					   PT_ParseTree parseTree,
					   int maxDepth) 
{
  PT_Tree tree;
  PT_Position current;

  assert(maxDepth >= 0 || maxDepth == UNLIMITED_DEPTH);
  assert(PT_isValidParseTree(parseTree));

  tree = PT_getParseTreeTop(parseTree);

  initCache();

  current.path = path;
  current.line = 1;
  current.col  = 0;
  current.offset  = 0;
  current.maxDepth = maxDepth;
  current.curDepth = 0;

  parseTree = PT_setParseTreeTop(parseTree, PT_addTreePosInfo(tree, &current));

  cleanupCache();

  return parseTree;
}


PT_Tree PT_addTreePosInfoToDepth(const char* path, PT_Tree tree,
				 int maxDepth, int start_line, int start_col) 
{
  PT_Position current;
  PT_Tree result;
 
  assert(maxDepth >= 0 || maxDepth == UNLIMITED_DEPTH);

  initCache();

  current.path = path;
  current.line = start_line;
  current.col  = start_col;
  current.offset  = 0;
  current.maxDepth = maxDepth;
  current.curDepth = 0;


  result = PT_addTreePosInfo(tree, &current);
  cleanupCache();
  return result;
}


PT_Tree PT_addTreePosInfoSome(const char *path, PT_Tree tree,
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


PT_ParseTree PT_addParseTreePosInfo(const char* path, PT_ParseTree parsetree)
{
  return  PT_addParseTreePosInfoToDepth(path, parsetree, UNLIMITED_DEPTH);
}


PT_ParseTree PT_addParseTreePosInfoSome(const char *path,
					PT_ParseTree parsetree,
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



static ATbool PT_containsAreaOffset(ERR_Area haystack, PT_PosInFile *needle)
{
  int start = ERR_getAreaOffset(haystack);
  int end = start + ERR_getAreaLength(haystack);

  return (start < needle->offset) && (needle->offset <= end);
}


static ATbool PT_containsAreaLineColumn(ERR_Area haystack, PT_PosInFile *needle)
{
  int beginLine = ERR_getAreaBeginLine(haystack);
  int endLine = ERR_getAreaEndLine(haystack);
  int beginCol = ERR_getAreaBeginColumn(haystack);
  int endCol = ERR_getAreaEndColumn(haystack);

  if (beginLine <= needle->line && endLine >= needle->line) {
    if (beginLine == endLine) {
      return (beginCol <= needle->col && endCol >= needle->col);
    }
    else if (beginLine == needle->line) {
      return (beginCol <= needle->col);
    }
    else if (endLine == needle->line) {
      return (endCol >= needle->col);
    }
    else {
      return ((beginLine <= needle->line) && (endLine >= needle->line));
    }
  }

  return ATfalse;
}



PT_Tree PT_findTreeAtPosition(PT_Tree tree, ATbool (*contain)(ERR_Area area, PT_PosInFile *position), PT_PosInFile pos)
{
  ERR_Area area;
  ERR_Location location;
  PT_Args args;

  assert(tree != NULL);

  location = PT_getTreeLocation(tree);
  if (location == NULL) {
    return NULL;
  }

  area = ERR_getLocationArea(location);
  if (!contain(area, &pos)) {
    return NULL;
  }

  if (PT_isTreeAppl(tree)) {
    args = PT_getTreeArgs(tree);
    while (!PT_isArgsEmpty(args)) {
      PT_Tree child = PT_findTreeAtPosition(PT_getArgsHead(args), contain, pos);
      if (child != NULL) {
	return child;
      }
      args = PT_getArgsTail(args);
    }
  }

  return tree;
}



PT_Tree PT_findTreeAtOffset(PT_Tree tree, int offset)
{
  PT_PosInFile pos;

  pos.offset = offset;
  
  return PT_findTreeAtPosition(tree, PT_containsAreaOffset, pos);
}


PT_Tree PT_findTreeAtLineColumn(PT_Tree tree, int line, int col)
{
  PT_PosInFile pos;

  pos.line = line;
  pos.col = col;
  
  return PT_findTreeAtPosition(tree, PT_containsAreaLineColumn, pos);
}



PT_Args PT_findArgsWithLocation(PT_Args args)
{
  assert(args != NULL);

  while (!PT_isArgsEmpty(args)) {
    if (PT_hasTreeLocation(PT_getArgsHead(args))) {
      return args;
    }
    args = PT_getArgsTail(args);
  }

  return args;
}

