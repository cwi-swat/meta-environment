#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

#include <MEPT-utils.h>
#include <Location.h>

static ATermTable slices;

static void treeToSlices(PT_Tree tree);

/*{{{  static ATbool allAlphaNumeric(const char* str)  */

static ATbool allAlphaNumeric(PT_Args chars)
{
  for ( ; !PT_isArgsEmpty(chars) ; chars = PT_getArgsTail(chars)) {
    int val = PT_getTreeCharacter(PT_getArgsHead(chars));
    if (!isalnum((unsigned int) val)
	&& val != '-' 
	&& val != '_') {
      return ATfalse;
    }
  }

  return ATtrue;
}

/*}}}  */

/*{{{  static void storeTree(PT_Tree tree, const char *category) */

static void storeTree(PT_Tree tree, const char *category)
{
  ATerm key;
  LOC_AreaAreas slice;
  LOC_Location location;

  key = ATmake("<str>",category);
  slice = LOC_AreaAreasFromTerm(ATtableGet(slices, key));

  if (slice == NULL) {
    slice = LOC_makeAreaAreasEmpty();
  }

  location = PT_getTreeLocation(tree);
  if (location != NULL && LOC_hasLocationArea(location)) {
    LOC_Area area = LOC_getLocationArea(location);

    slice = LOC_makeAreaAreasMany((LOC_Area) area, slice);
    ATtablePut(slices, key, LOC_AreaAreasToTerm(slice));
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


  if (PT_isTreeAmb(tree)) {
    storeTree(tree, "Ambiguous");
    return;
  }

  categoryAnno = PT_getTreeAnnotation(tree, ATparse("category"));
 
  if (categoryAnno != NULL) { /* we have a user defined category */
    storeTree(tree, ATwriteToString(categoryAnno)); 
  }
  else {
    if (PT_isTreeLit(tree)) {
      PT_Args chars = PT_getTreeArgs(tree);

      if (allAlphaNumeric(chars)) {
	storeTree(tree, "AlphanumericLiterals"); 
      }
      else {
	storeTree(tree, "NonAlphanumericLiterals");
      }

      return;
    }
    else if (PT_isTreeVar(tree)) {
      storeTree(tree, "Variables");
      return;
    }
    /*else if (PT_isTreeLayout(tree)) {*/
/* TODO: too much slices here! */
      /*storeTree(tree, "Comments"); */
      /*return;*/
    /*}*/
    else if (PT_isTreeLexical(tree)) {
      storeTree(tree, "Lexicals");
      return;
    }
  }

  if (PT_isTreeAppl(tree)) {
    argsToSlices(PT_getTreeArgs(tree));
  }
}

/*}}}  */

/*{{{  ATermList TreeToSyntaxSlices(PT_Tree tree)  */

ATermList TreeToSyntaxSlices(PT_Tree tree) 
{
  ATermList result = ATempty;
  ATermList keys;

  slices = ATtableCreate(1024, 75);

  treeToSlices(tree);

  keys = ATtableKeys(slices);


  for ( ; !ATisEmpty(keys); keys = ATgetNext(keys)) {
    ATerm key = ATgetFirst(keys);
    const char* cat = ATgetName(ATgetAFun((ATermAppl) key));
    LOC_AreaAreas areas;
    LOC_Slice slice; 

    areas = LOC_AreaAreasFromTerm(ATtableGet(slices, key));

    slice = LOC_makeSliceSlice(cat, areas);

    result = ATinsert(result, LOC_SliceToTerm(slice));

  }

  ATtableDestroy(slices);
  slices = NULL;

  return result;
}

/*}}}  */
