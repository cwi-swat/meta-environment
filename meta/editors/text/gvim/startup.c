/*{{{  includes */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>

#include <external-startup.h>

/*}}}  */

/*{{{  defines */

#define EDITOR "gvim-connector"

/*}}}  */

/*{{{  void startup(const char *filename, int read_from_hive_fd, int write_to_hive_fd) */

void startup(const char *filename, int read_from_hive_fd, int write_to_hive_fd)
{
  char fromHiveFD[BUFSIZ];
  char toHiveFD[BUFSIZ];

  sprintf(fromHiveFD, "%d", read_from_hive_fd);
  sprintf(toHiveFD, "%d", write_to_hive_fd);

  execlp(EDITOR, EDITOR,
	 "--read_from_hive_fd", fromHiveFD,
	 "--write_to_hive_fd", toHiveFD,
	 "--filename", filename,
	 NULL);

  /* only get here in case of error */
  perror("execlp:gvim/startup");
  exit(errno);
}

/*}}}  */
