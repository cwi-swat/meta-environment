/* $Id$ */

#include <stdlib.h>
#include <string.h>
#include <aterm1.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

#include "logging.h"

static const int BUFCHUNK = 65536;
static FILE  *log = NULL;

/* Open a named file for reading. */
FILE *LOG_OpenFile(const char *std_error, const char *FN) {
  FILE *file;

  if (!FN || !strcmp(FN, "") || !strcmp(FN, "-")) {
    if (!std_error || (FN && !strcmp(FN, "-"))) {
      return stdin;
    }

    return NULL;
  }

  if (!(file = fopen(FN, "rb"))) {
    ATwarning("Can't open file: %s\n", FN);
    return NULL;
  }
  return file;
}

void LOG_CloseFile(FILE *fd) {
  if(fd != stdin)
    fclose(fd);
}

FILE  *LOG_OpenLog(const char *prg, const char *fnam) {
  if (log) {
    return log;
  }

  if (!fnam || !strcmp(fnam, "")) {
    ATerror("Cannot create logfile without a filename\n", fnam);
  }
  
  if (!(log = fopen(fnam, "wb"))) {
    ATerror("Cannot create logfile %s\n", fnam);
  }
  

  return log;
}

FILE *LOG_log(void) {
  return log;
}

void LOG_CloseLog(void) {
  if(log) fclose(log);
}

size_t LOG_FileSize(const char *FN) {
  struct stat  statbuf;

  if (!FN || !strcmp(FN, "") || !strcmp(FN, "-"))
    return -1;  /* We can't tell how many tokens to read  */

  if(stat(FN, &statbuf) < 0) {
    return -1;  /* We can't tell how many tokens to read, and
                   may not be able to read anything... */
  }
  return statbuf.st_size;
}
