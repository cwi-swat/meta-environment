#include <string.h>
#include <MEPT-utils.h>  

#include "ASFME-utils.h"

#define DEFAULT_TAG_PREFIX "default-"
#define DEFAULT_TAG "default"

ATbool 
ASF_isTagDefault(ASF_Tag tag)
{
  if (ASF_isTagNotEmpty(tag)) {
    ASF_TagId tagId = ASF_getTagTagId(tag);

    if (ASF_isTagIdLexToCf(tagId)) {
      char* lex = PT_yieldTree(PT_makeTreeFromTerm(
                                 ASF_makeTermFromTagId(tagId)));
      return !strncmp(lex, DEFAULT_TAG_PREFIX, strlen(DEFAULT_TAG_PREFIX)) 
               ||
               !strcmp(lex, DEFAULT_TAG);
    }
  } 
  return ATfalse;
}

int 
ASF_getCondEquationListLength(ASF_CondEquationList eqs)
{
   return (ATgetLength((ATermList)ASF_makeTermFromCondEquationList(eqs))/2)+1;
}

int ASF_getCHARListLength(ASF_CHARList list)
{
  return (ATgetLength((ATermList) ASF_makeTermFromCHARList(list)) / 2) + 1;
}

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

ASF_Layout ASF_makeLayoutEmpty()
{
  return (ASF_Layout)PT_makeTermFromTree(PT_makeTreeLayoutEmpty());
} 
