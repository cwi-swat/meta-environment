#include <assert.h>

#include <aterm2.h>
#include <deprecated.h>
#include "Errors.h"

/*{{{  conversion functions */

ATerm ME_stringToChars(const char *str)
{
  int len = strlen(str);
  int i;
  ATermList result = ATempty;

  for (i = len - 1; i >= 0; i--) {
    result = ATinsert(result, (ATerm) ATmakeInt(str[i]));
  }

  return (ATerm) result;
}

char *ME_charsToString(ATerm arg)
{
  ATermList list = (ATermList) arg;
  int len = ATgetLength(list);
  int i;
  char *str;

  str = (char *) malloc(len+1);
  if (str == NULL) {
      return NULL;
  }

  for (i = 0; !ATisEmpty(list); list = ATgetNext(list), i++) {
    str[i] = (char) ATgetInt((ATermInt) ATgetFirst(list));
  }
  str[i] = '\0';

  return str;
}


/*}}}  */

/*{{{  typedefs */


/*}}}  */

/*{{{  void ME_initErrorsApi(void) */

void ME_initErrorsApi(void)
{
  init_Errors_dict();
}

/*}}}  */

/*{{{  term conversion functions */


/*}}}  */
/*{{{  list functions */


/*}}}  */
/*{{{  constructors */


/*}}}  */
/*{{{  equality functions */


/*}}}  */
/*{{{  sort visitors */


/*}}}  */
