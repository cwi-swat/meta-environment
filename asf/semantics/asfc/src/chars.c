#include <malloc.h>
#include <string.h>
#include "chars.h"
#include <aterm1.h>


char* escape(const char* str, const char* escaped_chars)
{
  int i,j,e;
  int len = strlen(str);
  char *escaped = (char*) malloc(2 * len * sizeof(char) + 1);

  if (escaped == NULL) {
    ATerror("escape: could not allocate enough memory for escaping:\n%s\n",str);
    return NULL;
  }

  for (i = 0, j = 0; i < len; i++, j++) {
    for (e = 0; escaped_chars[e]; e++) {
      if (str[i] == escaped_chars[e]) {
        escaped[j++] = '\\';
      }
    }
    escaped[j] = str[i];
  }
  escaped[j] = '\0';

  return escaped;
}

char *unquotedStrDup(char *str)
{
  char *new;
  int len;

  if (strlen(str) > 0) {
    new = strdup(str+1);
    if (new == NULL) {
      ATerror("Could not allocate memory to copy string\n");
      return NULL;
    }

    len = strlen(new);
    if (len > 0) {
      new[len - 1] = '\0';
    }
    return new;
  }
  else {
    return str;
  }
}

