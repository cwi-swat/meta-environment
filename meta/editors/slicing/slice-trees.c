#include <MEPT-utils.h>
#include <ctype.h>
#include <strings.h>

static ATermTable slices;

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

    ch = PT_getTreeChar(tree);

    if (!isspace(ch)) {
      return true;
    }
  }

  return false;
}

/*}}}  */
/*{{{  static ATbool allAlphaNumeric(const char* str)  */

static ATbool allAlphaNumeric(const char* str) 
{
  int len = strlen(str);
  int i;


  for (i = 0; i < len ; i++) {
    if (!isalnum((unsigned int) str[i])) {
      return false;
    }
  }

  return true;
}

/*}}}  */

/*{{{  static void storeTree(PT_Tree tree, const char *category) */

static void storeTree(PT_Tree tree, const char *category)
{
  SH_CategoryName name;
  ATerm key;
  SH_Areas slice;
  LOC_Location location;

  name = SH_makeCategoryNameExtern(category);
  key = SH_CategoryNameToTerm(name);
  slice = SH_AreasFromTerm(ATtableGet(slices, key));
  loc = PT_getTreeLocation(tree);

  if (slice == NULL) {
    slice = SH_makeAreasEmpty();
  }

  if (loc != NULLi && LOC_hasLocationArea(loc)) {
    LOC_Area area = LOC_getLocationArea(loc);

    slice = SH_makeAreasMany((SH_Area) area, slice);

    ATtablePut(slices, key, slice);
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

/*{{{  SH_Slices TreeToSyntaxSlices(PT_Tree tree)  */

SH_Slices TreeToSyntaxSlices(PT_Tree tree) 
{
  SH_Slices result = SH_makeSlicesEmpty();
  ATermList keys;

  slices = ATtableCreate(1024, 75);

  treeToSlices(tree);

  keys = ATgetTableKeys(slices);

  for ( ; !ATisEmpty(keys); keys = ATgetNext(keys)) {
    CategoryName cat;
    SH_Areas areas;
    SH_Slice slice; 

    cat = SH_CategoryNameFromTerm(ATgetFirst(keys));
    areas = SH_AreasFromTerm(ATtableGet(slices, key));

    slice = SH_makeSliceDefault(cat, areas);

    result = SH_makeSlicesMany(slice, result);
  }

  ATtableDestroy(slices);
  slices = NULL;

  return slices;
}

/*}}}  */
