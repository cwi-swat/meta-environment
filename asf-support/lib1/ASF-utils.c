
#include <string.h>
#include "ASF-utils.h"

#define DEFAULT_TAG_PREFIX "default-"
#define DEFAULT_TAG "default"

ATbool 
ASF_isTagDefault(ASF_Tag tag)
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

int 
ASF_getCondEquationListLength(ASF_CondEquationList eqs)
{
   return (ATgetLength((ATermList)ASF_makeTermFromCondEquationList(eqs))/2)+1;
}

ASF_ConditionList 
ASF_foreachConditionInList(ASF_ConditionList list, ASF_ConditionVisitor visitor) 
{
  ATermList store;
  ASF_ConditionList newList;
  ASF_Separator sep = ASF_getConditionListSep(list);
  ASF_Layout layout = ASF_getConditionListWsAfterFirst(list);

  /* note that in the general case we have to save each layout node and
   * put it back after applying the visitor! (to be implemented)
   */
 
  /* apply func to each element */
  for (store = ATempty; 
      ASF_hasConditionListHead(list); 
      list = ASF_getConditionListTail(list)) {
    store = ATinsert(store, 
                     ASF_makeTermFromCondition(
                     visitor(ASF_getConditionListHead(list))));
  } 

  if(ATisEmpty(store)) {
    ATerror("foreachConditionInList: plus list contains no elements");
  }

  newList = ASF_makeConditionListSingle(
            ASF_makeConditionFromTerm(ATgetFirst(store)));
  store = ATgetNext(store);
 
  for (; !ATisEmpty(store); store = ATgetNext(store)) {
    ASF_Condition newCond = ASF_makeConditionFromTerm(ATgetFirst(store));
    newList = ASF_makeConditionListMany(newCond, layout, sep, layout, newList); 
  } 

  return newList;
}

ASF_CondEquationList
ASF_foreachCondEquationInList(ASF_CondEquationList list, 
                          ASF_CondEquationVisitor visitor)
{
  ATermList store;
  ASF_CondEquationList newList;
  ASF_Layout layout = ASF_getCondEquationListWsAfterFirst(list);

  /* note that in the general case we have to save each layout node and
   * put it back after applying the visitor! (to be implemented)
   */ 

  /* apply func to each element */
  for (store = ATempty;
      ASF_hasCondEquationListHead(list);
      list = ASF_getCondEquationListTail(list)) {
    store = ATinsert(store,
                     ASF_makeTermFromCondEquation(
                     visitor(ASF_getCondEquationListHead(list))));
  }

  if(ATisEmpty(store)) {
    return ASF_makeCondEquationListEmpty();
  }

  newList = ASF_makeCondEquationListSingle(
            ASF_makeCondEquationFromTerm(ATgetFirst(store)));

  for (; !ATisEmpty(store); store = ATgetNext(store)) {
    ASF_CondEquation newEqu = ASF_makeCondEquationFromTerm(ATgetFirst(store));
    newList = ASF_makeCondEquationListMany(newEqu, 
                                           layout, newList);
  }

  return newList;
}

int ASF_getCHARListLength(ASF_CHARList list)
{
  return (ATgetLength((ATermList) ASF_makeTermFromCHARList(list)) / 2) + 1;
}
