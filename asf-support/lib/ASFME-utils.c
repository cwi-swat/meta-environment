
/*{{{  includes */

#include <string.h>
#include <MEPT-utils.h>  

#include "ASFME-utils.h"

/*}}}  */
/*{{{  defines */

#define DEFAULT_TAG_PREFIX "default-"
#define DEFAULT_TAG "default"


/*}}}  */

/*{{{  ATbool ASF_isTagDefault(ASF_Tag tag) */

ATbool ASF_isTagDefault(ASF_Tag tag)
{
  if (ASF_isTagNotEmpty(tag)) {
    ASF_TagId tagId = ASF_getTagTagId(tag);

    if (ASF_isTagIdLexToCf(tagId)) {
      char* lex = PT_yieldTree(PT_TreeFromTerm(
                                 ASF_TagIdToTerm(tagId)));
      return !strncmp(lex, DEFAULT_TAG_PREFIX, strlen(DEFAULT_TAG_PREFIX)) 
               ||
               !strcmp(lex, DEFAULT_TAG);
    }
  } 
  return ATfalse;
}

/*}}}  */
/*{{{  int ASF_getCondEquationListLength(ASF_CondEquationList eqs) */

int ASF_getCondEquationListLength(ASF_CondEquationList eqs)
{
   return (ATgetLength((ATermList)ASF_makeTermFromCondEquationList(eqs))/2)+1;
}

/*}}}  */
/*{{{  int ASF_getCHARListLength(ASF_CHARList list) */

int ASF_getCHARListLength(ASF_CHARList list)
{
  return (ATgetLength((ATermList) ASF_makeTermFromCHARList(list)) / 2) + 1;
}

/*}}}  */
/*{{{  int ASF_getConditionListLength(ASF_ConditionList list) */

int ASF_getConditionListLength(ASF_ConditionList list)
{
  return (ATgetLength((ATermList) ASF_makeTermFromConditionList(list)) / 2) + 1;
}

/*}}}  */
/*{{{  ASF_CondEquationList ASF_concatCondEquationList(ASF_CondEquationList l1, l2) */

ASF_CondEquationList ASF_concatCondEquationList(ASF_CondEquationList l1,
						ASF_CondEquationList l2)
{
  if (!ASF_isCondEquationListEmpty(l2)) {
    if (ASF_hasCondEquationListHead(l1)) {
      ASF_CondEquation head = ASF_getCondEquationListHead(l1);
      if (ASF_hasCondEquationListTail(l1)) {
        ASF_CondEquationList tail = ASF_getCondEquationListTail(l1);
      
        return ASF_makeCondEquationListMany(head, ASF_makeLayoutEmpty(),
                 ASF_concatCondEquationList(tail, l2));
      }
      else {
        return ASF_makeCondEquationListMany(head, ASF_makeLayoutEmpty(), l2);
      }
    }
    else {
      return l2;
    }
  } 

  return l1;
}

/*}}}  */
/*{{{  ASF_CondEquationList ASF_unionCondEquationList(ASF_CondEquationList l1, l2) */

ASF_CondEquationList ASF_unionCondEquationList(ASF_CondEquationList cel1,
                                               ASF_CondEquationList cel2)
{
  if (!ASF_isCondEquationListEmpty(cel2)) {
    if (!ASF_isCondEquationListEmpty(cel1)) {
      int len1 = ASF_getCondEquationListLength(cel1);
      int len2 = ASF_getCondEquationListLength(cel2);
      ATermIndexedSet iSet = ATindexedSetCreate((len1+len2)*2, 75);
      ASF_CondEquation ce;
      ASF_CondEquationList newCel = ASF_makeCondEquationListEmpty();
      int maxIndex = 0, index;
      ATbool ignored;

      while (ASF_hasCondEquationListHead(cel1)) {
        ce = ASF_getCondEquationListHead(cel1);
        index = ATindexedSetPut(iSet, 
                                ASF_makeTermFromCondEquation(ce),
                                &ignored);
        if (index > maxIndex) {
          maxIndex = index;
        }
                                   
        if (ASF_hasCondEquationListTail(cel1)) {
          cel1 = ASF_getCondEquationListTail(cel1);
        }
        else {
          break;
        }
      }
      while (ASF_hasCondEquationListHead(cel2)) {
        ce = ASF_getCondEquationListHead(cel2);
        index = ATindexedSetPut(iSet, 
                                ASF_makeTermFromCondEquation(ce),
                                &ignored);
        if (index > maxIndex) {
          maxIndex = index;
        }
                                   
        if (ASF_hasCondEquationListTail(cel2)) {
          cel2 = ASF_getCondEquationListTail(cel2);
        }
        else {
          break;
        }
      }
      
      for (index=0; index <= maxIndex; index++) {
        ce = ASF_makeCondEquationFromTerm(ATindexedSetGetElem(iSet, index));
        newCel = ASF_makeCondEquationListMany(ce,
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
/*{{{  ASF_Layout ASF_makeLayoutEmpty() */

ASF_Layout ASF_makeLayoutEmpty()
{
  return (ASF_Layout)PT_makeTermFromTree(PT_makeTreeLayoutEmpty());
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
  extern ATerm ASF_patternTreeAmbConstructor;

  if (ATmatchTerm(ASF_TreeToTerm(tree), ASF_patternTreeAmbConstructor,
                  NULL, NULL, NULL, NULL, NULL, NULL)) {
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
