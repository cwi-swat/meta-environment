/*{{{  includes */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>

#include <external-startup.h>

/*}}}  */

/*{{{  defines */

#define EDITOR "emacs" 

/*}}}  */

/*{{{  void startup(const char *filename, int read_from_hive_fd, int write_to_hive_fd) */

void startup(const char *filename, int read_from_hive_fd, int write_to_hive_fd)
{
  char evalargs[BUFSIZ];

  sprintf(evalargs,
	  "(init \"--read_from_hive_fd %d --write_to_hive_fd %d --filename %s\")",
	  read_from_hive_fd,
	  write_to_hive_fd,
	  filename);

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
