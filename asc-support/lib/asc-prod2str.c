#include <string.h>
#include <stdlib.h>

#include <aterm1.h>

#include "asc-prod2str.h"

/* Warning this piece of code was copied from the asfc compiler source 
 * FIX THIS DUPLICATION
 */

/*{{{  static char* escape(const char* str, const char* escaped_chars) */

static char* escape(const char* str, const char* escaped_chars)
{
  int i,j,e;
  int len = strlen(str);

  /*char *escaped = (char*) malloc(2 * len * sizeof(char) + 3);*/
  char *escaped = calloc(10000, 1);

  if (escaped == NULL) {
    ATerror("escape: could not allocate enough memory for escaping:\n%s\n",str);
    return NULL;
  }

  i = 0;
  j = 0;

  escaped[j++] = '\"';

  for (; i < len; i++, j++) {
    for (e = 0; escaped_chars[e]; e++) {
      if (str[i] == escaped_chars[e]) {
        escaped[j++] = '\\';
      }
    }
    escaped[j] = str[i];
  }

  escaped[j++] = '\"';

  escaped[j] = '\0';

  return escaped;
}

/*}}}  */
/*{{{  char* prodToEscapedString(PT_Production prod) */

char* prodToEscapedString(PT_Production prod)
{
    char *strProd = ATwriteToString((ATerm) prod);
    return escape(strProd,"\"\\");
}

/*}}}  */

