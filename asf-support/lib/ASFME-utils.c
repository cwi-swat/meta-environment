
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
    ATbool result;

    const char *lex = PT_yieldTree((PT_Tree)tagId);
    result = streqn(lex, DEFAULT_TAG_PREFIX, strlen(DEFAULT_TAG_PREFIX)) 
           || streq(lex, DEFAULT_TAG);
    return result;
  } 
  return ATfalse;
}

/*}}}  */
/*{{{  ASF_ASFConditionalEquationList ASF_unionASFConditionalEquationList(ASF_ASFConditionalEquationList l1, l2) */

ASF_ASFConditionalEquationList ASF_unionASFConditionalEquationList(ASF_ASFConditionalEquationList cel1,
								   ASF_OptLayout separator,
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

      while (ASF_hasASFConditionalEquationListHead(cel1)) {
        ce = ASF_getASFConditionalEquationListHead(cel1);
        index = ATindexedSetPut(iSet, 
                                ASF_ASFConditionalEquationToTerm(ce),
                                NULL);
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
                                ASF_ASFConditionalEquationToTerm(ce),
                                NULL);
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
        ce = ASF_ASFConditionalEquationFromTerm(ATindexedSetGetElem(iSet, index));
        newCel = ASF_makeASFConditionalEquationListMany(ce,
							separator, 
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

ASF_OptLayout ASF_makeLayoutEmpty()
{
  return ASF_makeOptLayoutAbsent();
} 

/*}}}  */
/*{{{  ASF_OptLayout ASF_makeLayoutNewline() */

ASF_OptLayout ASF_makeLayoutNewline()
{
  return ASF_makeOptLayoutPresent(ASF_makeLayoutLexToCf(ASF_makeLexLayoutListSingle(ASF_makeLexLayoutWhitespace('\n'))));
} 

/*}}}  */
/*{{{  ASF_OptLayout ASF_makeLayoutSpace() */

ASF_OptLayout ASF_makeLayoutSpace()
{
  return ASF_makeOptLayoutPresent(ASF_makeLayoutLexToCf(ASF_makeLexLayoutListSingle(ASF_makeLexLayoutWhitespace(' '))));
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
                              (PT_AttrVisitorData) &data);

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

/*{{{  ASF_ASFConditionalEquationList ASF_getASFModuleEquationList(ASF_ASFModule module)  */

ASF_ASFConditionalEquationList ASF_getASFModuleEquationList(ASF_ASFModule module) 
{
  ASF_ASFSectionList sections = ASF_getASFModuleList(module);
  ASF_ASFConditionalEquationList eqs = 
    ASF_makeASFConditionalEquationListEmpty();

  for ( ; !ASF_isASFSectionListEmpty(sections);
	sections = ASF_getASFSectionListTail(sections)) {
    ASF_ASFSection section = ASF_getASFSectionListHead(sections);

    if (ASF_isASFSectionEquations(section)) {
      eqs = ASF_unionASFConditionalEquationList(eqs, ASF_makeLayoutNewline(),
						ASF_getASFSectionList(section));
    }


    if (!ASF_hasASFSectionListTail(sections)) {
      break;
    }
  }

  return eqs;
}

/*}}}  */
/*{{{  ASF_ASFTestEquationTestList ASF_getASFModuleTestList(ASF_ASFModule module)  */

ASF_ASFTestEquationTestList ASF_getASFModuleTestList(ASF_ASFModule module) 
{
  ASF_ASFSectionList sections = ASF_getASFModuleList(module);
  ASF_ASFTestEquationTestList tests = 
    ASF_makeASFTestEquationTestListEmpty();

  for ( ; !ASF_isASFSectionListEmpty(sections);
	sections = ASF_getASFSectionListTail(sections)) {
    ASF_ASFSection section = ASF_getASFSectionListHead(sections);

    if (ASF_isASFSectionTests(section)) {
      ASF_OptLayout ws = ASF_makeOptLayoutAbsent();
      tests = ASF_concatASFTestEquationTestList(tests, ws,
					    ASF_getASFSectionTestList(section));
    }


    if (!ASF_hasASFSectionListTail(sections)) {
      break;
    }
  }

  return tests;
}

/*}}}  */

/*{{{  ASF_ASFTagId ASF_makeTagId(const char* str) */

ASF_ASFTagId ASF_makeTagId(const char* str)
{
  ASF_LexASFTagId tag;

  if (strlen(str) == 1) {
    tag = ASF_makeLexASFTagIdOneChar(str[0]);
  }
  else {
    char *tmp = strdup(str);
    char last = tmp[strlen(str) - 1];
    tag = ASF_makeLexASFTagIdManyChars(tmp[0], tmp+1, last);
    free(tmp);
  }

  return ASF_makeASFTagIdLexToCf(tag);
}

/*}}}  */

				       
