
#include <string.h>
#include <ASF.h>

#define DEFAULT_TAG_PREFIX "default-"
#define DEFAULT_TAG "default"

ATbool ASF_isTagDefault(ASF_Tag tag)
{
  char *str;

  if (ASF_isTagNotEmpty(tag)) {
    ASF_TagId tagId = ASF_getTagTagId(tag);

    if (ASF_isTagIdManyChars(tagId)) {
      ASF_Lexical lex = ASF_getTagIdLex(tagId);
      if (ATmatch(lex, "<str>", &str)) { 
        return !strncmp(str, DEFAULT_TAG_PREFIX, strlen(DEFAULT_TAG_PREFIX)) 
               ||
               !strcmp(str, DEFAULT_TAG);
      }
    }
  } 
  return ATfalse;
}

int ASF_getCondEquationListLength(ASF_CondEquationList eqs)
{
   return (ATgetLength((ATermList)ASF_makeTermFromCondEquationList(eqs))/2)+1;
}

