#include <string.h>
#include <aterm2.h>
#include "SDFME.h"

typedef struct ATerm _SDF_CHARLIST;

static ATermList SDF_convertStringToChars(char *str)
{
  int i;
  ATermList list = ATempty;

  for(i = strlen(str) - 1; i >= 0; i--) {
    list = ATinsert(list, (ATerm) ATmakeInt(str[i]));
  }

  return list;
}

static char * SDF_convertCharsToString(ATermList list)
{
  int i;
  char *tmp = (char*) malloc((1 + ATgetLength(list)) * sizeof(char));

  for(i = 0; !ATisEmpty(list); list = ATgetNext(list), i++) {
    tmp[i] = ATgetInt((ATermInt) ATgetFirst(list));
  }

  tmp[i] = '\0';
  return tmp;
}

ATbool SDF_isValidCHARLIST(SDF_CHARLIST arg)
{
  return ATtrue;
}

ATbool SDF_isCHARLISTString(SDF_CHARLIST arg)
{
  return ATtrue;
}

char*  SDF_getCHARLISTString(SDF_CHARLIST arg)
{
  return SDF_convertCharsToString((ATermList) arg);
}

SDF_CHARLIST  SDF_setCHARLISTString(SDF_CHARLIST arg, char *str)
{
  return (SDF_CHARLIST) SDF_convertStringToChars(str);
}

ATerm  SDF_CHARLISTToTerm(SDF_CHARLIST arg)
{
  return (ATerm) arg;
}

SDF_CHARLIST SDF_CHARLISTFromTerm(ATerm trm)
{
  return (SDF_CHARLIST) trm;
}

SDF_CHARLIST SDF_makeCHARLISTString(char *str)
{
  return (SDF_CHARLIST) SDF_convertStringToChars(str);
}
