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

	    if (ATmatchTerm(PT_getAttrValue(head), categoryPattern,&cat)) {
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

/*{{{  static const char* getProductionCategoryName(PT_Tree tree)  */

static const char* getProductionCategoryName(PT_Tree tree) 
{
  ATerm cat = getProductionCategory(tree);

  if (cat != NULL) {
    return ATgetName(ATgetAFun((ATermAppl) cat));
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

/*{{{  static const char* getAnnotationCategoryName(PT_Tree tree) */

static const char* getAnnotationCategoryName(PT_Tree tree)
{
  ATerm cat = getAnnotationCategory(tree);

  if (cat != NULL) {
    return ATgetName(ATgetAFun((ATermAppl) cat));
  }

  return NULL;
}

/*}}}  */

/*{{{  static void storeTree(PT_Tree tree, const char *category) */

static void storeTree(PT_Tree tree, const char *category)
{
  ATerm key;
  ERR_AreaAreas slice;
  ERR_Location location;

  if (category[0] == '\"') {
    key = ATparse(category);
  }
  else {
    key = ATmake("<str>",category);
  }

  slice = ERR_AreaAreasFromTerm(ATtableGet(slices, key));

  if (slice == NULL) {
    slice = ERR_makeAreaAreasEmpty();
  }

  location = PT_getTreeLocation(tree);
  if (location != NULL && ERR_hasLocationArea(location)) {
    ERR_Area area = ERR_getLocationArea(location);
    slice = ERR_makeAreaAreasMany((ERR_Area) area, slice);
    ATtablePut(slices, key, ERR_AreaAreasToTerm(slice));
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
  else if (PT_isTreeCycle(tree)) {
    storeTree(tree, "MetaCycle");
  }
  else if ((categoryAnno = getAnnotationCategory(tree)) != NULL) {
    storeTree(tree, ATwriteToString(categoryAnno)); 
  }
  else if ((categoryAnno = getProductionCategory(tree)) != NULL) {
    storeTree(tree, ATwriteToString(categoryAnno)); 
  }
  else {
    /* Check var before lit, since there could be a variable
     * of type lit.
     */
    if (PT_isTreeVar(tree)) {
      storeTree(tree, "MetaVariable");
      ATtablePut(visited, (ATerm) tree, (ATerm) tree);
      return;
    }
    else if (PT_isTreeLit(tree) || PT_isTreeCilit(tree)) {
      PT_Args chars = PT_getTreeArgs(tree);

      if (hasAlphanumericChars(chars)) {
	storeTree(tree, "MetaKeyword"); 
	ATtablePut(visited, (ATerm) tree, (ATerm) tree);
	return;
      }
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
    ERR_AreaAreas areas;
    ERR_Slice slice; 

    areas = ERR_AreaAreasFromTerm(ATtableGet(slices, key));

    slice = ERR_makeSliceSlice(cat, areas);

    result = ATinsert(result, ERR_SliceToTerm(slice));
  }

  ATtableDestroy(slices);
  ATtableDestroy(visited);
  slices = NULL;

  return result;
}

/*}}}  */

static ATermList tokenizeTreeRec(PT_Tree tree) 
{
  ERR_Location loc = PT_getTreeLocation(tree);
  ERR_AreaAreas area = NULL;
  const char* category= NULL;
   
  if (loc != NULL && ERR_hasLocationArea(loc)) {
    area =  ERR_makeAreaAreasSingle(ERR_getLocationArea(loc));
  }

  if (PT_isTreeAmb(tree)) {
    return ATmakeList1((ATerm) ERR_makeSliceSlice("MetaAmbiguity", area));
  }
  else if (PT_isTreeCycle(tree)) {
    return ATmakeList1((ATerm) ERR_makeSliceSlice("MetaCycle", area));
  }
  else if ((category = getAnnotationCategoryName(tree)) != NULL) {
    return ATmakeList1((ATerm)  ERR_makeSliceSlice(category, area));
  }
  else if ((category = getProductionCategoryName(tree)) != NULL) {
    return ATmakeList1((ATerm)  ERR_makeSliceSlice(category, area));
  }
  else {
    /* Check var before lit, since there could be a variable
     * of type lit.
     */
    if (PT_isTreeVar(tree)) {
      return ATmakeList1((ATerm)  ERR_makeSliceSlice("MetaVariable", area));
    }
    else if (PT_isTreeLit(tree) || PT_isTreeCilit(tree)) {
      PT_Args chars = PT_getTreeArgs(tree);
      if (hasAlphanumericChars(chars)) {
	return ATmakeList1((ATerm)  ERR_makeSliceSlice("MetaKeyword", area));
      }
    }
    else if (PT_isTreeLexicalInjection(tree)) {
	return ATmakeList1((ATerm)  ERR_makeSliceSlice("MetaLexical", area));
    }
  }

  if (PT_isTreeAppl(tree)) {
    ATermList result = ATempty;
    PT_Args args = PT_getTreeArgs(tree);

    for ( ; !PT_isArgsEmpty(args); args = PT_getArgsTail(args)) {
      ATermList arg = tokenizeTreeRec(PT_getArgsHead(args));
      result = ATconcat(arg, result);
    }

    return result;
  }

  return ATempty;
}

ATermList tokenizeTree(PT_Tree tree)
{
  ATprotect(&category);
  category = ATparse("category");

  ATprotect(&categoryPattern);
  categoryPattern = ATparse("category(<term>)");

  return tokenizeTreeRec(tree);
}


