/* $Id$ */

/*{{{  includes */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#include "protocol.h"

/*}}}  */

/*{{{  int handshake(int fd) */

int handshake(int fd)
{
  return write(fd, HANDSHAKE, strlen(HANDSHAKE));
}

/*}}}  */
/*{{{  int connected(int fd) */

int connected(int fd)
{
  return write(fd, CONNECTED, strlen(CONNECTED));
}

/*}}}  */
/*{{{  int send(const char *cmd) */

int send(const char *cmd)
{
  char *p;
  int fd;
  int len;

  fd = atoi(cmd);
  if (fd <= 0) {
    return 1;
  }

  p = strchr(cmd, '#');
  if (p == NULL) {
    return 2;
  }

  p++; /* skip separator */
  len = strlen(p) + 1;

  return write(fd, p, len) == len;
}

/*}}}  */
