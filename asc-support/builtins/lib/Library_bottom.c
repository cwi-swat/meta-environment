#include <string.h>
#include <aterm2.h>
#include "Library.h"

typedef struct ATerm _CO_CHARLIST;

static ATermList CO_convertStringToChars(char *str)
{
  int i;
  ATermList list = ATempty;

  for(i = strlen(str) - 1; i >= 0; i--) {
    list = ATinsert(list, (ATerm) ATmakeInt(str[i]));
  }

  return list;
}

static char * CO_convertCharsToString(ATermList list)
{
  int i;
  char *tmp = (char*) malloc((1 + ATgetLength(list)) * sizeof(char));

  for(i = 0; !ATisEmpty(list); list = ATgetNext(list), i++) {
    tmp[i] = ATgetInt((ATermInt) ATgetFirst(list));
  }

  tmp[i] = '\0';
  return tmp;
}

ATbool CO_isValidCHARLIST(CO_CHARLIST arg)
{
  return ATtrue;
}

ATbool CO_isCHARLISTString(CO_CHARLIST arg)
{
  return ATtrue;
}

char*  CO_getCHARLISTString(CO_CHARLIST arg)
{
  return CO_convertCharsToString((ATermList) arg);
}

CO_CHARLIST  CO_setCHARLISTString(CO_CHARLIST arg, char *str)
{
  return (CO_CHARLIST) CO_convertStringToChars(str);
}

ATerm  CO_CHARLISTToTerm(CO_CHARLIST arg)
{
  return (ATerm) arg;
}

CO_CHARLIST CO_CHARLISTFromTerm(ATerm trm)
{
  return (CO_CHARLIST) trm;
}

CO_CHARLIST CO_makeCHARLISTString(char *str)
{
  return (CO_CHARLIST) CO_convertStringToChars(str);
}
