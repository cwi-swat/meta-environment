#include <string.h>
#include <aterm2.h>
#include "MuASF.h"

typedef struct ATerm _MA_CHARLIST;

static ATermList MA_convertStringToChars(char *str)
{
  int i;
  ATermList list = ATempty;

  for(i = strlen(str) - 1; i >= 0; i--) {
    list = ATinsert(list, (ATerm) ATmakeInt(str[i]));
  }

  return list;
}

static char * MA_convertCharsToString(ATermList list)
{
  int i;
  char *tmp = (char*) malloc((1 + ATgetLength(list)) * sizeof(char));

  for(i = 0; !ATisEmpty(list); list = ATgetNext(list), i++) {
    tmp[i] = ATgetInt((ATermInt) ATgetFirst(list));
  }

  tmp[i] = '\0';
  return tmp;
}

ATbool MA_isValidCHARLIST(MA_CHARLIST arg)
{
  return ATtrue;
}

ATbool MA_isCHARLISTString(MA_CHARLIST arg)
{
  return ATtrue;
}

char*  MA_getCHARLISTString(MA_CHARLIST arg)
{
  return MA_convertCharsToString((ATermList) arg);
}

MA_CHARLIST  MA_setCHARLISTString(MA_CHARLIST arg, char *str)
{
  return (MA_CHARLIST) MA_convertStringToChars(str);
}

ATerm  MA_CHARLISTToTerm(MA_CHARLIST arg)
{
  return (ATerm) arg;
}

MA_CHARLIST MA_CHARLISTFromTerm(ATerm trm)
{
  return (MA_CHARLIST) trm;
}

MA_CHARLIST MA_makeCHARLISTString(char *str)
{
  return (MA_CHARLIST) MA_convertStringToChars(str);
}
