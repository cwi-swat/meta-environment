/*{{{  includes */

#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "chars.h"
#include <aterm1.h>


/*}}}  */

/*{{{  char* escape(const char* str, const char* escaped_chars, QuotedOption quoted) */

char* escape(const char* str, const char* escaped_chars, QuotedOption quoted)
{
  int i,j,e;
  int len = strlen(str);
  char *escaped = (char*) malloc(2 * len * sizeof(char) + (quoted ? 2 : 0) + 1);

  if (escaped == NULL) {
    ATerror("escape: could not allocate enough memory for escaping:\n%s\n",str);
    return NULL;
  }

  i = 0;
  j = 0;

  if (quoted == QUOTED) {
    escaped[j++] = '\"';
  }

  for (; i < len; i++, j++) {
    for (e = 0; escaped_chars[e]; e++) {
      if (str[i] == escaped_chars[e]) {
        escaped[j++] = '\\';
      }
    }
    escaped[j] = str[i];
  }

  if (quoted == QUOTED) {
    escaped[j++] = '\"';
  }

  escaped[j] = '\0';

  return escaped;
}

/*}}}  */
/*{{{  char* toalfanum(const char* str) */

char* toalfanum(const char* str)
{
  int len = strlen(str);
  char *new = malloc(3 * sizeof(char) * len + 1);
  int i,j;

  if (new == NULL) {
    ATerror("Could not allocate memory to copy string\n");
    return NULL;
  }

  for(i = 0, j = 0; i < len; i++, j++) {
    if (isalpha(str[i])) {
      new[j] = str[i];
    }
    else if (str[i] == '_') {
      new[j] = '_';
    }
    else {
      sprintf(new+j,"%03d",str[i]);
      j += 2;
    }
  } 

  new[j] = '\0';
  return new;
}

/*}}}  */
/*{{{  char* dashesToUnderscores(const char *str) */

char* dashesToUnderscores(const char *str)
{
  char *tmp = strdup(str);
  int i;

  if (tmp == NULL) {
    ATerror("Could not allocate memory to copy string\n");
    return NULL;
  }

  for (i = 0; i < strlen(tmp); i++) {
    if (tmp[i] == '-') {
      tmp[i] = '_';
    } else if (tmp[i] == '/') {
      tmp[i] = '_';
    }
  }

  return tmp;
}

/*}}}  */



