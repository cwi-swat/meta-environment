/*{{{  includes */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>

#include <external-startup.h>

/*}}}  */

/*{{{  defines */

#define EDITOR "xemacs"

/*}}}  */

/*{{{  void startup(const char *filename, int in_fd, int out_fd) */

void startup(const char *filename, int in_fd, int out_fd)
{
  char evalargs[BUFSIZ];

  sprintf(evalargs,
	  "(init \"--in_fd %d --out_fd %d --filename %s\")",
	  in_fd, out_fd, filename);

  execlp(EDITOR, EDITOR,
	 filename,
	 "-load", STARTUP_SCRIPT,
	 "-eval", evalargs,
	 NULL);

  /* only get here in case of error */
  perror("execlp");
  exit(errno);
}

/*}}}  */
