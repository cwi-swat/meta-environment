#include <string.h>
#include <aterm2.h>
#include "Booleans.h"

typedef struct ATerm _B_CHARLIST;

static ATermList B_convertStringToChars(char *str)
{
  int i;
  ATermList list = ATempty;

  for(i = strlen(str) - 1; i >= 0; i--) {
    list = ATinsert(list, (ATerm) ATmakeInt(str[i]));
  }

  return list;
}

static char * B_convertCharsToString(ATermList list)
{
  int i;
  char *tmp = (char*) malloc((1 + ATgetLength(list)) * sizeof(char));

  for(i = 0; !ATisEmpty(list); list = ATgetNext(list), i++) {
    tmp[i] = ATgetInt((ATermInt) ATgetFirst(list));
  }

  tmp[i] = '\0';
  return tmp;
}

ATbool B_isValidCHARLIST(B_CHARLIST arg)
{
  return ATtrue;
}

ATbool B_isCHARLISTString(B_CHARLIST arg)
{
  return ATtrue;
}

char*  B_getCHARLISTString(B_CHARLIST arg)
{
  return B_convertCharsToString((ATermList) arg);
}

B_CHARLIST  B_setCHARLISTString(B_CHARLIST arg, char *str)
{
  return (B_CHARLIST) B_convertStringToChars(str);
}

ATerm  B_CHARLISTToTerm(B_CHARLIST arg)
{
  return (ATerm) arg;
}

B_CHARLIST B_CHARLISTFromTerm(ATerm trm)
{
  return (B_CHARLIST) trm;
}

B_CHARLIST B_makeCHARLISTString(char *str)
{
  return (B_CHARLIST) B_convertStringToChars(str);
}
