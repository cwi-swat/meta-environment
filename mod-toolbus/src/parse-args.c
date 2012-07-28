#include <aterm2.h>
#include <string.h>
#include <stdio.h>

static ATerm parseHTTPArg(char* arg)
{
  char *sentence = arg;
  char delim = '=';
  char *sep = NULL;

  sep = strchr(arg, delim);

  if (sep != NULL) {
    *sep = '\0';
    return ATmake("[<str>,<str>]", sentence, sep+1);
  }

  return NULL;
}

ATerm parseHTTPArgs(char *args)
{
  char *sentence = args;
  char *sep = NULL;
  char delim = '&';
  ATerm tuple = NULL;
  ATermList result = ATempty;

  if (sentence == NULL) {
    return NULL;
  }

  while (*sentence != '\0' && (sep = strchr(sentence, delim)) != NULL) {
    *sep = '\0';
    tuple = parseHTTPArg(sentence);
   
    sentence = sep + 1;

    if (tuple != NULL) {
      result = ATinsert(result, tuple);
    }
  }

  if (*sentence != '\0') {
    tuple = parseHTTPArg(sentence);
    if (tuple != NULL) {
      result = ATinsert(result, tuple);
    }
  }

  return (ATerm) result;
}
