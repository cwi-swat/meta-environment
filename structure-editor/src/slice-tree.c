#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

#include <MEPT-utils.h>
#include <Location.h>

static ATermTable slices;
static ATermTable visited;

static void treeToSlices(PT_Tree tree);
static ATerm category = NULL;
static ATerm categoryPattern = NULL;

/*{{{  static ATbool hasAlphanumericChars(PT_Args chars) */

static ATbool hasAlphanumericChars(PT_Args chars)
{
  for ( ; !PT_isArgsEmpty(chars) ; chars = PT_getArgsTail(chars)) {
    int val = PT_getTreeCharacter(PT_getArgsHead(chars));
    if (isalnum((unsigned int) val)) {
      return ATtrue;
    }
  }

  return ATfalse;
}

/*}}}  */
/*{{{  static char* getProductionCategory(PT_Tree tree) */

static ATerm getProductionCategory(PT_Tree tree)
{
  if (PT_isTreeAppl(tree)) {
    PT_Production prod = PT_getTreeProd(tree);

    if (PT_isProductionDefault(prod)) {
      PT_Attributes attributes = PT_getProductionAttributes(prod);

      if (PT_isAttributesAttrs(attributes)) {
	PT_Attrs attrs = PT_getAttributesAttrs(attributes);

	for ( ; !PT_isAttrsEmpty(attrs); attrs = PT_getAttrsTail(attrs)) {
	  PT_Attr head = PT_getAttrsHead(attrs);

	  if (PT_isAttrTerm(head)) {
	    ATerm cat = NULL;

	    if (ATmatchTerm(PT_getAttrTerm(head), categoryPattern,&cat)) {
	      return cat;
	    }
	  }
	}
      }
    }
  }

  return NULL;
}


/*}}}  */
/*{{{  static ATerm getAnnotationCategory(PT_Tree tree) */

static ATerm getAnnotationCategory(PT_Tree tree)
{
  return PT_getTreeAnnotation(tree, category);
}

/*}}}  */

/*{{{  static void storeTree(PT_Tree tree, const char *category) */

static void storeTree(PT_Tree tree, const char *category)
{
  ATerm key;
  LOC_AreaAreas slice;
  LOC_Location location;

  if (category[0] == '\"') {
    key = ATparse(category);
  }
  else {
    key = ATmake("<str>",category);
  }

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
  ATerm cached = ATtableGet(visited, (ATerm) tree);

  if (cached != NULL) {
	  return;
  }

  /* We have three levels: default, production attribute, term annotation.
   * Annotations have preference, then production attributes, then the
   * default highlighting kicks in. However, the fourth level is 
   * the ambiguity (level 0), which has preference above all and
   * stops the recursion immediately.
   */
  if (PT_isTreeAmb(tree)) {
    storeTree(tree, "MetaAmbiguity");
  }
  else if ((categoryAnno = getAnnotationCategory(tree)) != NULL) {
    storeTree(tree, ATwriteToString(categoryAnno)); 
  }
  else if ((categoryAnno = getProductionCategory(tree)) != NULL) {
    storeTree(tree, ATwriteToString(categoryAnno)); 
  }
  else {
    if (PT_isTreeLit(tree) || PT_isTreeCilit(tree)) {
      PT_Args chars = PT_getTreeArgs(tree);

      if (hasAlphanumericChars(chars)) {
	storeTree(tree, "MetaKeyword"); 
      }
    }
    else if (PT_isTreeVar(tree)) {
      storeTree(tree, "MetaVariable");
    }
  }

  if (PT_isTreeAppl(tree)) {
    argsToSlices(PT_getTreeArgs(tree));
  }

  ATtablePut(visited, (ATerm) tree, (ATerm) tree);
}

/*}}}  */

/*{{{  ATermList TreeToSyntaxSlices(PT_Tree tree)  */

ATermList TreeToSyntaxSlices(PT_Tree tree) 
{
  ATermList result = ATempty;
  ATermList keys;

  slices = ATtableCreate(1024, 75);
  visited = ATtableCreate(1024, 75);

  ATprotect(&category);
  category = ATparse("category");

  ATprotect(&categoryPattern);
  categoryPattern = ATparse("category(<term>)");

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
  ATtableDestroy(visited);
  slices = NULL;

  return result;
}

/*}}}  */
