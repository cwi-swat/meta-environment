#include <string.h>
#include <aterm2.h>
#include "ParsedErrors.h"

typedef struct ATerm _PME_CHARLIST;

static ATermList PME_convertStringToChars(char *str)
{
  int i;
  ATermList list = ATempty;

  for(i = strlen(str) - 1; i >= 0; i--) {
    list = ATinsert(list, (ATerm) ATmakeInt(str[i]));
  }

  return list;
}

static char * PME_convertCharsToString(ATermList list)
{
  int i;
  char *tmp = (char*) malloc((1 + ATgetLength(list)) * sizeof(char));

  for(i = 0; !ATisEmpty(list); list = ATgetNext(list), i++) {
    tmp[i] = ATgetInt((ATermInt) ATgetFirst(list));
  }

  tmp[i] = '\0';
  return tmp;
}

ATbool PME_isValidCHARLIST(PME_CHARLIST arg)
{
  return ATtrue;
}

ATbool PME_isCHARLISTString(PME_CHARLIST arg)
{
  return ATtrue;
}

char*  PME_getCHARLISTString(PME_CHARLIST arg)
{
  return PME_convertCharsToString((ATermList) arg);
}

PME_CHARLIST  PME_setCHARLISTString(PME_CHARLIST arg, char *str)
{
  return (PME_CHARLIST) PME_convertStringToChars(str);
}

ATerm  PME_CHARLISTToTerm(PME_CHARLIST arg)
{
  return (ATerm) arg;
}

PME_CHARLIST PME_CHARLISTFromTerm(ATerm trm)
{
  return (PME_CHARLIST) trm;
}

PME_CHARLIST PME_makeCHARLISTString(char *str)
{
  return (PME_CHARLIST) PME_convertStringToChars(str);
}
