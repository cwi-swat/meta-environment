/* $Id$ */

/*{{{  includes */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/select.h>
#include <netinet/in.h>

#include <aterm2.h>
#include <atb-tool.h>

#include <connector.h>
#include <TextEditor.h>

/*}}}  */

/*{{{  static int create_inet_socket(int port) */

static int create_inet_socket(int port)
{
  struct sockaddr_in addr;
  int attempts = 0;
  int sock;
  int opt;
  int retval;

  sock = socket(PF_INET, SOCK_STREAM, 0);
  if (sock < 0) {
    perror("swing-connector:socket");
    exit(1);
  }

  opt = 1;
  retval = setsockopt(sock, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));
  if (retval == -1) {
    perror("swing-connector:setsockopt SO_REUSEADDR");
  }

  memset((char *) &addr, 0, sizeof(addr));
  addr.sin_family = AF_INET;
  addr.sin_addr.s_addr = htonl(INADDR_ANY);
  addr.sin_port = htons(port);

  while (bind(sock, (struct sockaddr *)&addr, sizeof(addr)) < 0) {
    if (attempts > 1000) {
      return -1;
    }
    attempts++;
  }

  return sock; 
}

/*}}}  */
/*{{{  static int allocate_inet_socket() */

static int allocate_inet_socket()
{
  int try_port;
  int sock;

  for (try_port = 10000; try_port < 15000; try_port++) {
    sock = create_inet_socket(try_port);
    if (sock >= 0) {
      return sock;
    }
  }

  return -1;
}

/*}}}  */

/*{{{  static void hiveClosed(int write_to_editor_fd) */

static void hiveClosed(int write_to_editor_fd)
{
  ATBwriteTerm(write_to_editor_fd, ATparse("snd-terminate(\"hive closed\")"));
}

/*}}}  */
/*{{{  static void clearFocus(int write_to_editor_fd) */

static void clearFocus(int write_to_editor_fd)
{
  ATBwriteTerm(write_to_editor_fd, ATparse("clear-focus"));
}

/*}}}  */
/*{{{  static void moveToFront(int write_to_editor_fd) */

static void moveToFront(int write_to_editor_fd)
{
  ATBwriteTerm(write_to_editor_fd, ATparse("editor-to-front"));
}

/*}}}  */
/*{{{  static void writeContents(int write_to_editor_fd) */

static void writeContents(int write_to_editor_fd)
{
  ATBwriteTerm(write_to_editor_fd, ATparse("write-contents"));
}

/*}}}  */
/*{{{  static void rereadContents(int write_to_editor_fd) */

static void rereadContents(int write_to_editor_fd)
{
  ATBwriteTerm(write_to_editor_fd, ATparse("reread-contents"));
}

/*}}}  */
/*{{{  static void isModified(int write_to_editor_fd) */

static void isModified(int write_to_editor_fd)
{
  ATBwriteTerm(write_to_editor_fd, ATparse("is-modified"));
}

/*}}}  */
/*{{{  static void testSwingAction(int write_to_editor_fd, TE_Action action) */

static void addActions(int write_to_editor_fd, TE_Action action)
{
  ATerm t;

  t = ATmake("snd-do(add-actions(<term>))", TE_getActionActions(action));

  ATBwriteTerm(write_to_editor_fd, t);
}

/*}}}  */
/*{{{  static void displayMessage(int write_to_editor_fd, TE_Action action) */

static void displayMessage(int write_to_editor_fd, TE_Action action)
{
  ATerm t;

  t = ATmake("snd-do(display-message(<str>))", TE_getActionMessage(action));

  ATBwriteTerm(write_to_editor_fd, t);
}

/*}}}  */
/*{{{  static void setFocus(int write_to_editor_fd, TE_Action action) */

static void setFocus(int write_to_editor_fd, TE_Action action)
{
  ATerm t;

  t = ATmake("snd-do(set-focus(<term>))", TE_getActionFocus(action));

  ATBwriteTerm(write_to_editor_fd, t);
}

/*}}}  */
/*{{{  static void displayMessage(int write_to_editor_fd, TE_Action action) */

static void setCursorAtOffset(int write_to_editor_fd, TE_Action action)
{
  ATerm t;

  t = ATmake("snd-do(set-cursor-at-offset(<int>))", TE_getActionOffset(action));

  ATBwriteTerm(write_to_editor_fd, t);
}

/*}}}  */

/*{{{  static int handleEditorInput(TE_Pipe hiveToEditor, TE_Pipe editorToHive) */

static int handleEditorInput(TE_Pipe hiveToEditor, TE_Pipe editorToHive)
{
  ATerm t;
  ATerm event;
  int read_from_editor_fd;
  int write_to_hive_fd;
  int write_to_editor_fd;

  read_from_editor_fd = TE_getPipeRead(editorToHive);
  write_to_hive_fd = TE_getPipeWrite(editorToHive);
  write_to_editor_fd = TE_getPipeWrite(hiveToEditor);

  t = ATBreadTerm(read_from_editor_fd);

  if (ATmatch(t, "snd-event(<term>)", &event)) {
    ATBwriteTerm(write_to_hive_fd, event);
    ATBwriteTerm(write_to_editor_fd, ATmake("snd-ack-event(<term>)", event));
  }
  else {
    ATwarning("%s:handleEditorInput: ignored: %t\n", __FILE__, t);
  }

  return 0;
}

/*}}}  */

/*{{{  int main(int argc, char *argv[]) */

int main(int argc, char *argv[])
{
  ATerm bottomOfStack;
  int i;
  int editor_socket;
  int server_socket;
  int retval;
  int read_from_hive_fd = -1;
  int write_to_hive_fd = -1;
  const char *filename;
  TextEditor swingEditor;
  TE_Pipe hiveToEditor;
  TE_Pipe editorToHive;

  ATBinit(argc, argv, &bottomOfStack);
  TE_initTextEditorApi();

  for (i=1; i<argc; i++) {
    const char *cur = argv[i];
    if (strcmp(cur, "--read_from_hive_fd") == 0) {
      read_from_hive_fd = atoi(argv[++i]);
    }
    else if (strcmp(cur, "--write_to_hive_fd") == 0) {
      write_to_hive_fd = atoi(argv[++i]);
    }
    else if (strcmp(cur, "--filename") == 0) {
      filename = argv[++i];
    }
  }

  assert(read_from_hive_fd >= 0);
  assert(write_to_hive_fd >= 0);

  server_socket = allocate_inet_socket();
  if (server_socket == -1) {
    ATerror("unable to allocate inet socket, giving up.\n");
    exit(1);
  }

  retval = listen(server_socket, 1);
  if (retval == -1) {
    perror("listen");
    exit(1);
  }

  editor_socket = accept(server_socket, NULL, NULL);
  if (editor_socket == -1) {
    perror("accept");
    exit(1);
  }

  retval = close(server_socket);
  if (retval == -1) {
    perror("close:server_socket");
    exit(1);
  }

  swingEditor = initTextEditor(hiveClosed,
			       clearFocus,
			       moveToFront,
			       writeContents,
			       rereadContents,
			       displayMessage,
			       addActions,
			       setFocus,
			       setCursorAtOffset,
			       isModified);

  setEditorInputHandler(swingEditor, handleEditorInput);

  hiveToEditor = TE_makePipeDefault(read_from_hive_fd, editor_socket);
  editorToHive = TE_makePipeDefault(editor_socket, write_to_hive_fd);

  return eventloop(swingEditor, hiveToEditor, editorToHive);
}

/*}}}  */
