
/*{{{  includes */

#include <string.h>
#include <MEPT-utils.h>  

#include "ASFME-utils.h"

/*}}}  */
/*{{{  defines */

#define DEFAULT_TAG_PREFIX "default-"
#define DEFAULT_TAG "default"


/*}}}  */

#define streqn(s1,s2,n) (!strncmp(s1,s2,n))
#define streq(s1,s2) (!strcmp(s1,s2))

/*{{{  ATbool ASF_isTagDefault(ASF_Tag tag) */

ATbool ASF_isTagDefault(ASF_ASFTag tag)
{
  if (ASF_isASFTagNotEmpty(tag)) {
    ASF_ASFTagId tagId = ASF_getASFTagASFTagId(tag);

    char *lex = ASF_getCHARLISTString(ASF_getASFTagIdChars(tagId));
    return streqn(lex, DEFAULT_TAG_PREFIX, strlen(DEFAULT_TAG_PREFIX)) 
           ||
           streq(lex, DEFAULT_TAG);
  } 
  return ATfalse;
}

/*}}}  */
/*{{{  int ASF_getASFConditionalEquationListLength(ASF_ASFConditionalEquationList eqs) */

int ASF_getASFConditionalEquationListLength(ASF_ASFConditionalEquationList eqs)
{
   return (ATgetLength((ATermList)ASF_makeTermFromASFConditionalEquationList(eqs))/2)+1;
}

/*}}}  */
/*{{{  int ASF_getCHARListLength(ASF_CHARList list) */

int ASF_getCHARListLength(ASF_CHARList list)
{
  return (ATgetLength((ATermList) ASF_makeTermFromCHARList(list)) / 2) + 1;
}

/*}}}  */
/*{{{  int ASF_getConditionListLength(ASF_ConditionList list) */

int ASF_getConditionListLength(ASF_ASFConditionList list)
{
  return (ATgetLength((ATermList) ASF_makeTermFromASFConditionList(list)) / 2) + 1;
}

/*}}}  */
/*{{{  ASF_ASFConditionalEquationList ASF_concatASFConditionalEquationList(ASF_ASFConditionalEquationList l1, l2) */

ASF_ASFConditionalEquationList ASF_concatASFConditionalEquationList(ASF_ASFConditionalEquationList l1,
						ASF_ASFConditionalEquationList l2)
{
  if (!ASF_isASFConditionalEquationListEmpty(l2)) {
    if (ASF_hasASFConditionalEquationListHead(l1)) {
      ASF_ASFConditionalEquation head = ASF_getASFConditionalEquationListHead(l1);
      if (ASF_hasASFConditionalEquationListTail(l1)) {
        ASF_ASFConditionalEquationList tail = ASF_getASFConditionalEquationListTail(l1);
      
        return ASF_makeASFConditionalEquationListMany(head, ASF_makeLayoutEmpty(),
                 ASF_concatASFConditionalEquationList(tail, l2));
      }
      else {
        return ASF_makeASFConditionalEquationListMany(head, ASF_makeLayoutEmpty(), l2);
      }
    }
    else {
      return l2;
    }
  } 

  return l1;
}

/*}}}  */
/*{{{  ASF_ASFConditionalEquationList ASF_unionASFConditionalEquationList(ASF_ASFConditionalEquationList l1, l2) */

ASF_ASFConditionalEquationList ASF_unionASFConditionalEquationList(ASF_ASFConditionalEquationList cel1,
                                               ASF_ASFConditionalEquationList cel2)
{
  if (!ASF_isASFConditionalEquationListEmpty(cel2)) {
    if (!ASF_isASFConditionalEquationListEmpty(cel1)) {
      int len1 = ASF_getASFConditionalEquationListLength(cel1);
      int len2 = ASF_getASFConditionalEquationListLength(cel2);
      ATermIndexedSet iSet = ATindexedSetCreate((len1+len2)*2, 75);
      ASF_ASFConditionalEquation ce;
      ASF_ASFConditionalEquationList newCel = ASF_makeASFConditionalEquationListEmpty();
      int maxIndex = 0, index;
      ATbool ignored;

      while (ASF_hasASFConditionalEquationListHead(cel1)) {
        ce = ASF_getASFConditionalEquationListHead(cel1);
        index = ATindexedSetPut(iSet, 
                                ASF_makeTermFromASFConditionalEquation(ce),
                                &ignored);
        if (index > maxIndex) {
          maxIndex = index;
        }
                                   
        if (ASF_hasASFConditionalEquationListTail(cel1)) {
          cel1 = ASF_getASFConditionalEquationListTail(cel1);
        }
        else {
          break;
        }
      }
      while (ASF_hasASFConditionalEquationListHead(cel2)) {
        ce = ASF_getASFConditionalEquationListHead(cel2);
        index = ATindexedSetPut(iSet, 
                                ASF_makeTermFromASFConditionalEquation(ce),
                                &ignored);
        if (index > maxIndex) {
          maxIndex = index;
        }
                                   
        if (ASF_hasASFConditionalEquationListTail(cel2)) {
          cel2 = ASF_getASFConditionalEquationListTail(cel2);
        }
        else {
          break;
        }
      }
      
      for (index=0; index <= maxIndex; index++) {
        ce = ASF_makeASFConditionalEquationFromTerm(ATindexedSetGetElem(iSet, index));
        newCel = ASF_makeASFConditionalEquationListMany(ce,
                                              ASF_makeLayoutEmpty(), 
                                              newCel);
      }
      ATindexedSetDestroy(iSet);
      return newCel;
    }
    return cel2;
  } 

  return cel1;
}

/*}}}  */
/*{{{  ASF_ASFConditionalEquationList ASF_makeASFConditionalEquationListFromParseTrees(ATermList l) */

ASF_ASFConditionalEquationList ASF_makeASFConditionalEquationListFromParseTrees(ATermList l)
{
  ASF_ASFConditionalEquationList alleqs = ASF_makeASFConditionalEquationListEmpty();

  for(; !ATisEmpty(l); l = ATgetNext(l)) {
    PT_ParseTree parseTree = PT_makeParseTreeFromTerm(ATgetFirst(l));
    PT_Tree  tree = PT_getParseTreeTree(parseTree);
    ASF_ASFConditionalEquationList list;
    ASF_ASFEquations equations;

    equations = ASF_makeASFEquationsFromTerm(PT_makeTermFromTree(tree));

    list = ASF_getASFEquationsList(equations);
    alleqs = ASF_unionASFConditionalEquationList(list,alleqs);
  }

  return alleqs;
}

/*}}}  */

/*{{{  ASF_Layout ASF_makeLayoutEmpty() */

ASF_OptLayout ASF_makeLayoutEmpty()
{
  return ASF_makeOptLayoutAbsent();
} 

/*}}}  */

/*{{{  ATbool ASF_isTreeLexicalConstructorFunction(ASF_Tree tree) */

ATbool ASF_isTreeLexicalConstructorFunction(ASF_Tree tree)
{
  extern ATerm ASF_patternTreeLexicalConstructor;

  if (ATmatchTerm(ASF_TreeToTerm(tree), ASF_patternTreeLexicalConstructor,
                  NULL, NULL, NULL, NULL, NULL, NULL, NULL)) {
    return ATtrue;
  }

  return ATfalse;
}

/*}}}  */

/*{{{  ATbool ASF_isTreeAmbConstructorFunction(ASF_Tree tree) */

ATbool ASF_isTreeAmbConstructorFunction(ASF_Tree tree)
{
  extern ATerm ASF_patternTreeAmbiguityConstructor;

  if (ATmatchTerm(ASF_TreeToTerm(tree), ASF_patternTreeAmbiguityConstructor,
                  NULL, NULL, NULL, NULL, NULL, NULL, NULL)) {
    return ATtrue;
  }

  return ATfalse;
}

/*}}}  */

/*{{{  static PT_Attr isAttrTraversal(PT_Attr attr, PT_AttrVisitorData data) */

static PT_Attr isAttrTraversal(PT_Attr attr, PT_AttrVisitorData data)
{
  ATbool* bool;

  bool = (ATbool*) data;
  
  if (PT_isAttrTerm(attr)) {
    ATerm term = PT_getAttrTerm(attr);

    if (ATgetType(term) == AT_APPL) {
      char *fun = ATgetName(ATgetSymbol(term));

      if (!strcmp(fun,"traverse") ||
          !strcmp(fun,"traversal")) {
        *bool = ATtrue;
      } 
    }
  }     
                              
  return attr;
}       

/*}}}  */
/*{{{  ATbool ASF_isTreeTraversalFunction(PT_Tree trm) */

ATbool ASF_isTreeTraversalFunction(ASF_Tree tree)
{
  PT_Tree trm = (PT_Tree) tree;

  if (PT_hasTreeProd(trm)) {
    PT_Production prod = PT_getTreeProd(trm);

    if (PT_hasProductionAttributes(prod)) {
      PT_Attributes attributes = PT_getProductionAttributes(prod);

      if (PT_hasAttributesAttrs(attributes)) {
        PT_Attrs attrs = PT_getAttributesAttrs(attributes);
        ATbool data = ATfalse;

        PT_foreachAttrInAttrs(attrs, isAttrTraversal,
                              (PT_AttrVisitorData*) &data);

        return data;
      }
    }
  }

  return ATfalse;
}

/*}}}  */

/*{{{  ATbool ASF_isTreeGetterFunction(ASF_Tree tree) */

ATbool ASF_isTreeGetterFunction(ASF_Tree tree)
{
  PT_Tree ptree = (PT_Tree) tree;

  if (PT_hasTreeProd(ptree)) {
    PT_Production prod = PT_getTreeProd(ptree);
    PT_Attr attr = PT_makeAttrTerm(ATparse("asf-getter"));

    return PT_hasProductionCertainAttr(prod, attr);
  }

  return ATfalse;
}

/*}}}  */

