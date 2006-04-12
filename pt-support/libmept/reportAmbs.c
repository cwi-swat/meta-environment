/*{{{  includes */

#include <stdlib.h>
#include <string.h>
#include <assert.h>

#include <MEPT-utils.h>
#include <Error-utils.h>

/*}}}  */

#define RECURSION_UPPERBOUND 5000

/*{{{  typedef struct PT_Amb_Position_Tag */

typedef struct PT_Amb_Position_Tag {
  int line;
  int col;
  int offset;
} PT_Amb_Position;

/*}}}  */

static ATermTable visited = NULL;

/*{{{  static ERR_SubjectList getAmbiguities(const char *path, */

static ERR_Location makeLocation(PT_Amb_Position from, PT_Amb_Position to,
				 const char* path)
{
  ERR_Area area;
  ERR_Location location;

  area = ERR_makeAreaArea(from.line, from.col,
			     to.line, to.col,
			     from.offset, (to.offset - from.offset));
  if (path != NULL) {
    location = ERR_makeLocationAreaInFile(path, area);
  } else {
    location = ERR_makeLocationArea(area);
  }

  return location;
}

static ERR_SubjectList getAmbiguities(const char *path,
                                      PT_Tree tree, 
				      int depth,
                                      PT_Amb_Position *current)
{
  ERR_SubjectList ambSubjects = ERR_makeSubjectListEmpty();
  ERR_Location end = (ERR_Location) ATtableGet(visited, (ATerm) tree);
  PT_Amb_Position here = *current;

  if (end != NULL) {
	  /* found in cache, so advance current and go on with the
	   * rest
	   */
	  ERR_Area area = ERR_getLocationArea(end);
	  current->col = ERR_getAreaEndColumn(area);
	  current->line = ERR_getAreaEndLine(area);
	  current->offset += ERR_getAreaLength(area);
	  return ambSubjects;
  }

  if (depth >= RECURSION_UPPERBOUND) {
    ERR_Subject subject = ERR_makeSubjectLocalized(
            "Tree is too deep to completely search for ambiguities."
	    "Consider using a list operator like * or + instead of recursion "
	    "to prevent this problem.",
	    makeLocation(*current,*current,path));

      ambSubjects = ERR_makeSubjectListMany(subject, ambSubjects);
  }
  else if (PT_isTreeChar(tree)) {
  /*{{{  handle single char */

	  
    if (PT_getTreeCharacter(tree) == '\n') {
	    ATwarning("NEWLINE\n");
      current->col = 0;
      (current->line)++;
      (current->offset)++;
    }
    else {
      (current->col)++;
      (current->offset)++;
    }

  /*}}}  */
  }
  else if (PT_isTreeAppl(tree)) {
  /*{{{  handle normal application */

    PT_Args args = PT_getTreeArgs(tree);

    for(;PT_hasArgsHead(args); args = PT_getArgsTail(args)) {
      PT_Tree arg = PT_getArgsHead(args);
      ERR_SubjectList argSubjects = getAmbiguities(path, arg, depth+1, current);
      ambSubjects = ERR_concatSubjectList(argSubjects, ambSubjects);
    }

  /*}}}  */
  }
  else if (PT_isTreeAmb(tree)) {
  /*{{{  handle ambiguity cluster */

    PT_Args args = PT_getTreeArgs(tree); 
    PT_Args ambs = args;
    const char *ambString;
    char ambCount[1024] = "#alternatives: ";
    ERR_Location ambLocation;
    ERR_Subject ambSubject;

    /* first collect nested ambiguities */
    for(;PT_hasArgsHead(args); args = PT_getArgsTail(args)) {
      *current = here;
      ambSubjects = ERR_concatSubjectList(getAmbiguities(path,
                                                         PT_getArgsHead(args),
							 depth + 1,
							 current), 
			                  ambSubjects);
    }

    PT_Tree amb = PT_getArgsHead(ambs);
    if (PT_hasTreeProd(amb)) {
	    ambString = PT_yieldSymbol(
			    PT_getProductionRhs(PT_getTreeProd(amb)));
    }
    else {
	    ambString = PT_yieldTree(amb);
    }

    sprintf(ambCount + strlen(ambCount),"%d", PT_getArgsLength(ambs));

    ambLocation = makeLocation(here, *current, path);
    ambSubject = ERR_makeSubjectLocalized(ambString, ambLocation);
    ambSubjects = ERR_makeSubjectListMany(ambSubject,ambSubjects);
    ambSubject = ERR_makeSubjectLocalized(ambCount, ambLocation);
    ambSubjects = ERR_makeSubjectListMany(ambSubject, ambSubjects);

  /*}}}  */
  } 

  {
	  /* TODO: serious bug here cause line numbers not to increase! */
	  ERR_Location loc = makeLocation(here, *current, path);
	  ATtablePut(visited, (ATerm) tree, (ATerm) loc);
  }
  return ambSubjects;
}

/*}}}  */

/*{{{  ATerm PT_reportTreeAmbiguities(PT_Tree tree) */

ATerm PT_reportTreeAmbiguities(const char *path, PT_Tree tree)
{
  PT_Amb_Position pos = {1, 0, 0}; 
  ERR_Error result = NULL;

  visited = ATtableCreate(1024, 75);

  ERR_SubjectList ambs = getAmbiguities(path, tree, 0, &pos);

  if (!ERR_isSubjectListEmpty(ambs)) {
    ERR_Error ambError = ERR_makeErrorError("Ambiguity", ambs);

    result = ambError;
  }

  ATtableDestroy(visited);
  return (ATerm) result;
}

/*}}}  */
/*{{{  ATerm PT_reportParseTreeAmbiguities(PT_ParseTree parsetree) */

ATerm PT_reportParseTreeAmbiguities(const char *path, PT_ParseTree parsetree)
{
  return PT_reportTreeAmbiguities(path, PT_getParseTreeTop(parsetree));
}

/*}}}  */

/*{{{  PT_Tree PT_findTopAmbiguity(PT_Tree tree) */

PT_Tree PT_findTopAmbiguity(PT_Tree tree)
{
  assert(tree != NULL);

  if (PT_isTreeAmb(tree)) {
    return tree;
  }
  else if (PT_isTreeAppl(tree)) {
    PT_Args args = PT_getTreeArgs(tree);

    while (!PT_isArgsEmpty(args)) {
      PT_Tree head = PT_getArgsHead(args);
      PT_Tree amb = PT_findTopAmbiguity(head);
      if (amb != NULL) {
	return amb;
      }
      args = PT_getArgsTail(args);
    }
  }

  return NULL;
}

/*}}}  */
