/*{{{  includes */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <assert.h>
#include <errno.h>

#include <aterm2.h>
#include <atb-tool.h>

#include <TextEditor.h>
#include <EditorData.h>

/*}}}  */
/*{{{  defines */

#define IN_FD "--in_fd"
#define OUT_FD "--out_fd"
#define FILENAME "--filename"

#define META_MENU_PREFIX "meta"

/*}}}  */

static FILE *log = NULL;

/*{{{  variables */

static char filename[BUFSIZ];

/*}}}  */

/*{{{  static void sendToHive(int out_fd, TE_Event event) */

static void sendToHive(int out_fd, TE_Event event)
{
  ATBwriteTerm(out_fd, TE_EventToTerm(event));
}

/*}}}  */
static void handleHiveInput(int out_fd, TE_Action action)
{
  ATfprintf(log, "handleHiveInput: action = %t\n", action);
  fflush(log);
}

/*{{{  static void handleXEmacsInput(int out_fd, const char *input) */

static void handleXEmacsInput(int out_fd, const char *input)
{
  TE_Event event;
  ATerm t;

  fprintf(log, "handleXEmacsInput: fd = %d, input = [%s]\n", out_fd, input);
  fflush(log);

  if (isdigit((int) *input)) {
    int loc = atoi(input);
    event = TE_makeEventMouse(loc);
  }
  else if (strcmp(input, "modified") == 0) {
    event = TE_makeEventModified();
  }
  else {
    t = ATparse(input);
    event = TE_makeEventMenu(TE_MenuFromTerm(t));
  }

  sendToHive(out_fd, event);
}

/*}}}  */

/*{{{  static int eventloop(int in_fd, int out_fd) */

static int eventloop(int in_fd, int out_fd)
{
  fd_set set;
  int max_fd;
  int retval;

  fprintf(log, "pre-while in_fd = %d, out_fd = %d\n", in_fd, out_fd);
  while (ATtrue) {
    FD_ZERO(&set);

    FD_SET(fileno(stdin), &set);
    max_fd = fileno(stdin);

    FD_SET(in_fd, &set);
    if (in_fd > max_fd) {
      max_fd = in_fd;
    }
    fprintf(log, "in-while in_fd = %d, out_fd = %d\n", in_fd, out_fd);

    fprintf(log, "entering select\n");
    sleep(10000);
    retval = select(max_fd+1, &set, NULL, NULL, NULL);
    if (retval == -1) {
      fprintf(log, "select: %s\n", strerror(errno));
      fflush(log);
    }

    if (FD_ISSET(fileno(stdin), &set)) {
      char buf[BUFSIZ];
      int nr_read;
      nr_read = read(fileno(stdin), buf, BUFSIZ);
      if (nr_read <= 0) {
	close(fileno(stdin));
	return 0;
      }
      buf[nr_read] = '\0';
      handleXEmacsInput(out_fd, buf);
    }

    if (FD_ISSET(in_fd, &set)) {
      ATerm t = ATBreadTerm(in_fd);
      if (t == NULL) {
	/*hiveClosed();*/
	return 0;
      }
      handleHiveInput(out_fd, TE_ActionFromTerm(t));
    }
  }
}

/*}}}  */
/*{{{  int main(int argc, char *argv[]) */

int main(int argc, char *argv[])
{
  ATerm bottomOfStack;
  int i;
  int in_fd = -1;
  int out_fd = -1;

  ATBinit(argc, argv, &bottomOfStack);
  TE_initTextEditorApi();
  SE_initEditorDataApi();

  for (i=1; i<argc; i++) {
    char *cur = argv[i];
    /*ATwarning("cur = [%s]\n", cur);*/
    if (strcmp(cur, IN_FD) == 0) {
      in_fd = atoi(argv[++i]);
    }
    else if (strcmp(cur, OUT_FD) == 0) {
      out_fd = atoi(argv[++i]);
    }
    else if (strcmp(cur, FILENAME) == 0) {
      strcpy(filename, argv[++i]);
    }
  }

  log = fopen("/tmp/xemacs-editor.log", "w");
  ATfprintf(log, "pid = %d\n", getpid());
  ATfprintf(log, "in_fd = %d, out_fd = %d\n", in_fd, out_fd);
  fflush(log);

  return eventloop(in_fd, out_fd);
}

/*}}}  */
