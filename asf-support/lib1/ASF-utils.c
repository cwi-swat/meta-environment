
#include <string.h>
#include "ASF-utils.h"

#define DEFAULT_TAG_PREFIX "default-"
#define DEFAULT_TAG "default"

ATbool 
ASF_isTagDefault(ASF_Tag tag)
{
  if (ASF_isTagNotEmpty(tag)) {
    ASF_TagId tagId = ASF_getTagTagId(tag);

    if (ASF_isTagIdManyChars(tagId)) {
      char* lex = ASF_getTagIdLex(tagId);
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
