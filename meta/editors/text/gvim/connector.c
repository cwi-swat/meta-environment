/* $Id$ */

/*{{{  includes */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <pwd.h>
#include <errno.h>
#include <assert.h>

#include <aterm2.h>
#include <atb-tool.h>
#include <connector.h>
#include <TextEditor.h>
#include <EditorData.h>

#include "protocol.h"

/*}}}  */
/*{{{  defines */

#define ANONYMOUS "anonymous"

#define READ_FROM_HIVE "--read_from_hive_fd"
#define WRITE_TO_HIVE "--write_to_hive_fd"
#define FILENAME "--filename"

#define PIPE_READ 0
#define PIPE_WRITE 1

/*}}}  */
/*{{{  variables */

static char *path_lib = LIBDIR "/lib_gvim.so";
static char *path_vim = DATADIR "/meta.vim";

static char *id = NULL;
static int read_from_editor_fd = -1;
static char filename[BUFSIZ] = { 0 };

/*}}}  */

/*{{{  static char *escapeSpaces(const char *input) */

static char *escapeSpaces(const char *input)
{
  static char buf[BUFSIZ*3];
  const char *p;
  char *s;

  assert(strlen(input) < BUFSIZ);

  p = input;
  s = buf;
  while (p && *p) {
    if (*p == ' ') {
      *s++ = '\\';
      *s++ = '\\';
    }
    *s++ = *p++;
  }
  *s++ = '\0';

  return buf;
}

/*}}}  */
/*{{{  static char *escapeQuotes(const char *input) */

static char *escapeQuotes(const char *input)
{
  static char *buf = NULL;
  const char *p;
  int len;
  char *s;

  len = strlen(input);
  buf = realloc(buf, len*4 + 1);

  p = input;
  s = buf;
  while (p && *p) {
    if (*p == '"') {
      *s++ = '\\';
      *s++ = '\\';
      *s++ = '\\';
    }
    *s++ = *p++;
  }
  *s++ = '\0';

  return buf;
}

/*}}}  */
/*{{{  static char *menuToString(TE_Menu menu) */

static char *menuToString(TE_Menu menu)
{
  static char buf[BUFSIZ];
  int len;
  ATerm t;

  t = TE_MenuToTerm(menu);
  len = ATcalcTextSize(t);
  assert(len < BUFSIZ);
  AT_writeToStringBuffer(t, buf);
  buf[len] ='\0';

  return buf;
}

/*}}}  */

/*{{{  static void sendToVimVerbatim(const char *cmd) */

static void sendToVimVerbatim(const char *cmd)
{
  char buf[BUFSIZ];
  sprintf(buf, "gvim --servername %s --remote-send '%s'", id, cmd);
  system(buf);
}

/*}}}  */
/*{{{  static void sendToVim(const char *cmd) */

static void sendToVim(const char *cmd)
{
  char buf[BUFSIZ];
  sprintf(buf, "%s<Cr>", cmd);
  sendToVimVerbatim(buf);
}

/*}}}  */

/*{{{  static void makeVimMenuItem(char *menu, char *item) */

static void makeVimMenuItem(char *menu, char *item)
{
  char buf[BUFSIZ];
  TE_Menu menuAction;

  menuAction = TE_makeMenuDefault(menu, item);

  sprintf(buf, ":call AddMenu(tb_pipe, \"");
  strcat(buf, escapeSpaces(menu));
  strcat(buf, "\", \"");
  strcat(buf, escapeSpaces(item));
  strcat(buf, "\", \"");
  strcat(buf, escapeQuotes(menuToString(menuAction)));
  strcat(buf, "\")");

  sendToVim(buf);
  sendToVimVerbatim("");
}

/*}}}  */
/*{{{  static void hiveClosed(int write_to_editor_fd) */

static void hiveClosed(int write_to_editor_fd)
{
  assert(write_to_editor_fd == -1);

  sendToVim(":qa!");
}

/*}}}  */
/*{{{  static void moveToFront(int write_to_editor_fd) */

static void moveToFront(int write_to_editor_fd)
{
  sendToVim(":call foreground()");
}

/*}}}  */
/*{{{  static void setActions(int write_to_editor_fd, TE_Action edAction) */

static void setActions(int write_to_editor_fd, TE_Action edAction)
{
  TE_ActionList actionList;

  actionList = TE_getActionActions(edAction);
  while (!TE_isActionListEmpty(actionList)) {
    TE_Menu menu = TE_getActionListHead(actionList);
    assert(TE_isValidMenu(menu));
    makeVimMenuItem(TE_getMenuMain(menu), TE_getMenuSub(menu));
    actionList = TE_getActionListTail(actionList);
  }
}

/*}}}  */
/*{{{  static void getContents(int write_to_hive_fd, TE_Action edAction) */

static void getContents(int write_to_hive_fd, TE_Action edAction)
{
  static char *contents = NULL;
  struct stat statrec;
  int size;

  if (stat(filename, &statrec) == -1) {
    perror("stat");
    size = 0;
  }
  else {
    size = statrec.st_size;
  }

  if (size > 0) {
    FILE *f;
    int needed = size + 1; /* for terminating '\0' */

    contents = realloc(contents, needed);
    if (contents == NULL) {
      ATerror("getContents: failed to realloc to %d bytes\n", needed);
    }

    f = fopen(filename, "rb");
    if (f == NULL) {
      ATwarning("getContents: failed to read %s\n", filename);
      strcpy(contents, "");
    }
    else {
      int nr_read = fread(contents, sizeof(char), size, f);
      if (nr_read == size) {
	fclose(f);
	contents[size] = '\0';
      }
      else {
	perror("fread");
      }
    }
  }

  if (contents == NULL) {
    ATwarning("gvim-editor: No focus text available, winging it.\n");
    contents = strdup("");
  }

  sendToHive(write_to_hive_fd, TE_makeEventContents(contents));
}

/*}}}  */
/*{{{  static void rereadContents(int write_to_editor_fd) */

static void rereadContents(int write_to_editor_fd)
{
  sendToVim(":e!");
}

/*}}}  */
/*{{{  static void clearFocus(int write_to_editor_fd) */

static void clearFocus(int write_to_editor_fd)
{
  sendToVim(":echo \"Focus symbol: <none>\"");
}

/*}}}  */
/*{{{  static void setFocus(int write_to_editor_fd, TE_Action edAction) */

static void setFocus(int write_to_editor_fd, TE_Action edAction)
{
  ATerm focusTerm = TE_getActionFocus(edAction);
  SE_Focus focus = SE_FocusFromTerm(focusTerm);
  SE_Area area = SE_getFocusArea(focus);
  int start = SE_getAreaStart(area);
  int length = SE_getAreaLength(area);
  char *s = SE_getFocusSort(focus);
  char buf[BUFSIZ];
  char sort[BUFSIZ];
  char *p;
  int i;

  for (i=0, p=s; p && *p; p++) {
    if (*p == '"' || *p == '\\') {
      sort[i++] = '\\';
    }
    sort[i++] = *p;
  }
  sort[i++] = '\0';

  sprintf(buf, ":goto %d", start);
  sendToVim(buf);

  sprintf(buf, ":echo \"Focus symbol: %s\"", sort);
  sendToVim(buf);

  /* activate visual selection mode */
  sendToVimVerbatim("v");

  /* emulate focus by "selecting" all the characters in it */
  if (length > 1) {
    sprintf(buf, "%d ", length-1);
    sendToVimVerbatim(buf);
  }
}

/*}}}  */
/*{{{  static void displayMessage(int write_to_editor_fd, TE_Action edAction) */

static void displayMessage(int write_to_editor_fd, TE_Action edAction)
{
  char buf[BUFSIZ];

  sprintf(buf, ":echo \"%s\"", TE_getActionMessage(edAction));
  sendToVim(buf);
}

/*}}}  */
/*{{{  static void gotoCursorAtLocation(int write_to_editor_fd, int location) */

static void gotoCursorAtLocation(int write_to_editor_fd, int location)
{
  char cmd[BUFSIZ];
  sprintf(cmd, ":goto %d", location);
  sendToVim(cmd);
}

/*}}}  */
/*{{{  static void setCursorAtLocation(int write_to_editor_fd, TE_Action edAction) */

static void setCursorAtLocation(int write_to_editor_fd, TE_Action edAction)
{
  gotoCursorAtLocation(write_to_editor_fd, TE_getActionLocation(edAction));
}

/*}}}  */
/*{{{  static void setCursorAtFocus(int write_to_editor_fd, TE_Action edAction) */

static void setCursorAtFocus(int write_to_editor_fd, TE_Action edAction)
{
  ATerm focusTerm = TE_getActionFocus(edAction);
  SE_Focus focus = SE_FocusFromTerm(focusTerm);
  SE_Area area = SE_getFocusArea(focus);

  gotoCursorAtLocation(write_to_editor_fd, SE_getAreaStart(area));
}

/*}}}  */

/*{{{  static void protocol_expect(int fd, const char *expected) */

static void protocol_expect(int fd, const char *expected)
{
  char buf[BUFSIZ];
  int len = strlen(expected);

  if (read(fd, buf, len) != len) {
    perror("protocol_expect:read");
    exit(errno);
  }
  else if (strncmp(buf, expected, len)) {
    ATabort("protocol error: expecting %s, got: %s\n", expected, buf);
  }
}

/*}}}  */

/*{{{  int main(int argc, char *argv[]) */

int main(int argc, char *argv[])
{
  ATerm bottomOfStack;
  char buf[BUFSIZ];
  char *p;
  struct passwd *pwent;
  int from_vim[2] = {-1, -1};
  int pid;
  int i;
  int read_from_hive_fd = -1;
  int write_to_hive_fd = -1;
  TextEditor gvimEditor;

  ATBinit(argc, argv, &bottomOfStack);
  TE_initTextEditorApi();
  SE_initEditorDataApi();

  for (i=1; i<argc; i++) {
    char *cur = argv[i];
    if (strcmp(cur, READ_FROM_HIVE) == 0) {
      read_from_hive_fd = atoi(argv[++i]);
    }
    else if (strcmp(cur, WRITE_TO_HIVE) == 0) {
      write_to_hive_fd = atoi(argv[++i]);
    }
    else if (strcmp(cur, FILENAME) == 0) {
      strcpy(filename, argv[++i]);
    }
  }

  gvimEditor = initTextEditor(hiveClosed,
			      clearFocus,
			      moveToFront,
			      rereadContents,
			      displayMessage,
			      setCursorAtLocation,
			      setCursorAtFocus,
			      setActions,
			      setFocus,
			      getContents);

  pwent = getpwuid(getuid());

  sprintf(buf, "meta:%s:%d", pwent ? pwent->pw_name : ANONYMOUS, (int)getpid());
  id = strdup(buf);
  for (p=id; *p; p++) {
    *p = (char)toupper((int)*p);
  }

  if (pipe(from_vim) == -1) {
    perror("pipe");
    return -1;
  }
  /*ATwarning("from_vim={%d,%d}\n", from_vim[0], from_vim[1]);*/

  pid = fork();
  if (pid < 0) {
    perror("fork");
    return -1;
  }
  else if (pid > 0) {
    /* parent */
    TE_Pipe hiveToEditor;
    TE_Pipe editorToHive;

    close(from_vim[PIPE_WRITE]);
    read_from_editor_fd = from_vim[PIPE_READ];

    protocol_expect(read_from_editor_fd, CONNECTED);

    sprintf(buf, ":source %s", path_vim);
    sendToVim(buf);

    protocol_expect(read_from_editor_fd, HANDSHAKE);

    hiveToEditor = TE_makePipeDefault(read_from_hive_fd, -1);
    editorToHive = TE_makePipeDefault(read_from_editor_fd, write_to_hive_fd);
    return eventloop(gvimEditor, hiveToEditor, editorToHive);
  }
  else {
    /* child */
    close(from_vim[PIPE_READ]);

    sprintf(buf,
	    "let tb_pipe = %d"
	    "| call libcallnr(\"%s\", \"connected\", tb_pipe)",
	    from_vim[PIPE_WRITE], path_lib);

    execlp("gvim", "gvim", "--servername", id, "-c", buf, filename, NULL);

    /* only get here in case of error */
    perror("execlp-vim");
    return -1;
  }
}

/*}}}  */
