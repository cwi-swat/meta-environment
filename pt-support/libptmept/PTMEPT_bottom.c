#include <string.h>
#include <aterm2.h>
#include "PTMEPT.h"

typedef struct ATerm _PTPT_CHARLIST;

static ATermList PTPT_convertStringToChars(char *str)
{
  int i;
  ATermList list = ATempty;

  for(i = strlen(str) - 1; i >= 0; i--) {
    list = ATinsert(list, (ATerm) ATmakeInt(str[i]));
  }

  return list;
}

static char * PTPT_convertCharsToString(ATermList list)
{
  int i;
  char *tmp = (char*) malloc((1 + ATgetLength(list)) * sizeof(char));

  for(i = 0; !ATisEmpty(list); list = ATgetNext(list), i++) {
    tmp[i] = ATgetInt((ATermInt) ATgetFirst(list));
  }

  tmp[i] = '\0';
  return tmp;
}

ATbool PTPT_isValidCHARLIST(PTPT_CHARLIST arg)
{
  return ATtrue;
}

ATbool PTPT_isCHARLISTString(PTPT_CHARLIST arg)
{
  return ATtrue;
}

char*  PTPT_getCHARLISTString(PTPT_CHARLIST arg)
{
  return PTPT_convertCharsToString((ATermList) arg);
}

PTPT_CHARLIST  PTPT_setCHARLISTString(PTPT_CHARLIST arg, char *str)
{
  return (PTPT_CHARLIST) PTPT_convertStringToChars(str);
}

ATerm  PTPT_CHARLISTToTerm(PTPT_CHARLIST arg)
{
  return (ATerm) arg;
}

PTPT_CHARLIST PTPT_CHARLISTFromTerm(ATerm trm)
{
  return (PTPT_CHARLIST) trm;
}

PTPT_CHARLIST PTPT_makeCHARLISTString(char *str)
{
  return (PTPT_CHARLIST) PTPT_convertStringToChars(str);
}
