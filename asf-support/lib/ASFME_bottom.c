#include <string.h>
#include <aterm2.h>
#include "ASFME.h"

typedef struct ATerm _ASF_CHARLIST;

static ATermList ASF_convertStringToChars(char *str)
{
  int i;
  ATermList list = ATempty;

  for(i = strlen(str) - 1; i >= 0; i--) {
    list = ATinsert(list, (ATerm) ATmakeInt(str[i]));
  }

  return list;
}

static char * ASF_convertCharsToString(ATermList list)
{
  int i;
  char *tmp = (char*) malloc((1 + ATgetLength(list)) * sizeof(char));

  for(i = 0; !ATisEmpty(list); list = ATgetNext(list), i++) {
    tmp[i] = ATgetInt((ATermInt) ATgetFirst(list));
  }

  tmp[i] = '\0';
  return tmp;
}

ATbool ASF_isValidCHARLIST(ASF_CHARLIST arg)
{
  return ATtrue;
}

ATbool ASF_isCHARLISTString(ASF_CHARLIST arg)
{
  return ATtrue;
}

char*  ASF_getCHARLISTString(ASF_CHARLIST arg)
{
  return ASF_convertCharsToString((ATermList) arg);
}

ASF_CHARLIST  ASF_setCHARLISTString(ASF_CHARLIST arg, char *str)
{
  return (ASF_CHARLIST) ASF_convertStringToChars(str);
}

ATerm  ASF_CHARLISTToTerm(ASF_CHARLIST arg)
{
  return (ATerm) arg;
}

ASF_CHARLIST ASF_CHARLISTFromTerm(ATerm trm)
{
  return (ASF_CHARLIST) trm;
}

ASF_CHARLIST ASF_makeCHARLISTString(char *str)
{
  return (ASF_CHARLIST) ASF_convertStringToChars(str);
}
