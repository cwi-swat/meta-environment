#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

#include <MEPT-utils.h>
#include "Slicing.h"

static ATermTable slices;

static void treeToSlices(PT_Tree tree);

/*{{{  static ATbool containsVisibles(PT_Tree tree)  */

static ATbool containsVisibles(PT_Tree tree) 
{
  PT_Args args;

  assert(PT_isTreeLayout(tree) && "expected layout tree");

  args = PT_getTreeArgs(tree);


  for (; !PT_isArgsEmpty(args); args = PT_getArgsTail(args)) {
    PT_Tree head = PT_getArgsHead(args);
    int ch;

    assert(PT_isTreeChar(head) && "expected list of chars");

    ch = PT_getTreeCharacter(tree);

    if (!isspace(ch)) {
      return ATtrue;
    }
  }

  return ATfalse;
}

/*}}}  */
/*{{{  static ATbool allAlphaNumeric(const char* str)  */

static ATbool allAlphaNumeric(const char* str) 
{
  int len = strlen(str);
  int i;


  for (i = 0; i < len ; i++) {
    if (!isalnum((unsigned int) str[i])) {
      return ATfalse;
    }
  }

  return ATtrue;
}

/*}}}  */

/*{{{  static void storeTree(PT_Tree tree, const char *category) */

static void storeTree(PT_Tree tree, const char *category)
{
  S_CategoryName name;
  ATerm key;
  S_Areas slice;
  LOC_Location location;

  name = S_makeCategoryNameExtern(category);
  key = S_CategoryNameToTerm(name);
  slice = S_AreasFromTerm(ATtableGet(slices, key));
  location = PT_getTreeLocation(tree);

  if (slice == NULL) {
    slice = S_makeAreasEmpty();
  }

  if (location != NULL && LOC_hasLocationArea(location)) {
    LOC_Area area = LOC_getLocationArea(location);

    slice = S_makeAreasMany((S_Area) area, slice);

    ATtablePut(slices, key, S_AreasToTerm(slice));
  }
}

/*}}}  */

/*{{{  static void argsToSlices(PT_Args args) */

static void argsToSlices(PT_Args args)
{
  for ( ; !PT_isArgsEmpty(args); args = PT_getArgsTail(args)) {
    PT_Tree arg = PT_getArgsHead(args);
    treeToSlices(arg);
  }
}

/*}}}  */
/*{{{  static void treeToSlices(PT_Tree tree) */

static void treeToSlices(PT_Tree tree)
{
  ATerm categoryAnno = NULL;

  if (PT_hasTreeArgs(tree)) {
    argsToSlices(PT_getTreeArgs(tree));
  }

  categoryAnno = PT_getTreeAnnotation(tree, ATparse("category"));
 
  if (categoryAnno != NULL) { /* we have a user defined category */
    storeTree(tree, ATwriteToString(categoryAnno)); 
  }
  else { 
    if (PT_isTreeLit(tree)) {
      const char *str = PT_getTreeString(tree);

      if (allAlphaNumeric(str)) {
	storeTree(tree, "AlphanumericLiterals"); 
      }
      else {
	storeTree(tree, "NonAlphanumericLiterals");
      }
    }
    else if (PT_isTreeVar(tree)) {
      storeTree(tree, "Variables");
    }
    else if (PT_isTreeLayout(tree) && containsVisibles(tree)) {
      storeTree(tree, "Comments");
    }
    else if (PT_isTreeLexical(tree)) {
      storeTree(tree, "Lexicals");
    }
  }
}

/*}}}  */

/*{{{  S_Slices TreeToSyntaxSlices(PT_Tree tree)  */

S_Slices TreeToSyntaxSlices(PT_Tree tree) 
{
  S_Slices result = S_makeSlicesEmpty();
  ATermList keys;

  slices = ATtableCreate(1024, 75);

  treeToSlices(tree);

  keys = ATtableKeys(slices);

  for ( ; !ATisEmpty(keys); keys = ATgetNext(keys)) {
    ATerm key = ATgetFirst(keys);
    S_CategoryName cat;
    S_Areas areas;
    S_Slice slice; 

    cat = S_CategoryNameFromTerm(ATgetFirst(keys));
    areas = S_AreasFromTerm(ATtableGet(slices, key));

    slice = S_makeSliceDefault(cat, areas);

    result = S_makeSlicesMany(slice, result);
  }

  ATtableDestroy(slices);
  slices = NULL;

  return result;
}

/*}}}  */
