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

#include "text-editor.tif.h"

/*}}}  */
/*{{{  defines */

#define SEPARATOR '#'
#define HANDSHAKE "handshake"
#define ANONYMOUS "anonymous"

#define PIPE_READ 0
#define PIPE_WRITE 1

/*}}}  */
/*{{{  variables */

static char *path_lib = LIBDIR "/libmeta_gvim.so";
static char *path_vim = DATADIR "/meta.vim";

static char *id = NULL;
static int vim_fd = -1;
static int tb_fd = -1;
static char filename[BUFSIZ] = { 0 };

static char parseMenuName[BUFSIZ];

/*}}}  */

/*{{{  static void sendToVimVerbatim(const char *cmd) */

static void sendToVimVerbatim(const char *cmd)
{
  char buf[BUFSIZ];
  sprintf(buf, "gvim --servername %s --remote-send '%s'", id, cmd);
  /*fprintf(stderr, "system call: [%s]\n", buf);*/
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
/*{{{  static void makeVimMenuItem(const char *menu, const char *item) */

static void makeVimMenuItem(const char *menu, const char *item)
{
  char buf[BUFSIZ];

  sprintf(buf, ":call AddMetaMenu(tb_pipe, \"%s\", \"%s\")", menu, item);
  sendToVim(buf);
}

/*}}}  */
/*{{{  static void handleVimInput(const char *s) */

static void handleVimInput(const char *cmd)
{
  char buf[BUFSIZ];
  char *fid;
  char *p;
  ATerm event;

  strcpy(buf, cmd);

  fid = buf;
  p = strchr(buf, SEPARATOR);
  if (p == NULL) {
    ATwarning("handleVimInput: bogus input [%s]\n", buf);
    return;
  }

  /* terminate string at separator */
  *p++ = '\0';

  if (isdigit((int)*p)) {
    int loc = atoi(p);
    event = ATmake("set-current-location(<str>,<int>)", fid, loc);
  }
  else if (*p == '_') {
    p++;
    if (strcmp(p, "modified") == 0) {
      event = ATmake("modified(<str>)", fid);
    }
    else if (strcmp(p, "parse") == 0) {
      event = ATmake("menu-event(<str>,<str>,<str>)",
		     parseMenuName, "Parse", fid);
    }
    else {
      ATwarning("unrecognized input: [%s]\n", p);
      return;
    }
  }
  else { /* Handle generic menu event */
    char *item;
    char *menu = p;
    p = strchr(p, SEPARATOR);
    if (p == NULL) {
      ATwarning("handleVimInput: bogus input [%s]\n", buf);
      return;
    }

    *p = '\0';
    item = ++p;

    event = ATmake("menu-event(<str>,<str>,<str>)", menu, item, fid);
  }


  ATBpostEvent(tb_fd, event);
}

/*}}}  */

/*{{{  void tb_unset_focus(int conn, char *s) */

void tb_unset_focus(int conn, char *s)
{
  sendToVim(":echo \"FocusSort: <none>\"");
}

/*}}}  */
/*{{{  void tb_set_focus(int conn, char *fid, char *s, int start, int len) */

void tb_set_focus(int conn, char *fid, char *s, int start, int len)
{
  char buf[BUFSIZ];
  char sort[BUFSIZ];
  char *p;
  int i;

  /*ATwarning("tb_set_focus: [%s], %d, %d\n", s, start, len);*/

  for (i=0, p=s; p && *p; p++) {
    if (*p == '"' || *p == '\\') {
      sort[i++] = '\\';
    }
    sort[i++] = *p;
  }
  sort[i++] = '\0';

  sprintf(buf, ":goto %d", start);
  sendToVim(buf);

  sprintf(buf, ":echo \"FocusSort: %s\"", sort);
  sendToVim(buf);

  sprintf(buf, "v%d ", len);
  sendToVimVerbatim(buf);
}

/*}}}  */
/*{{{  void tb_set_focus_unchanged(int conn, char *fid, char *s, int start, int len) */

void tb_set_focus_unchanged(int conn, char *fid, char *s, int start, int len)
{
  ATwarning("tb_set_focus_unchanged not yet implemented in gvim-adapter!\n");
}

/*}}}  */
/*{{{  ATerm tb_get_focus_text(int conn, char *fid, int start, int len) */

ATerm tb_get_focus_text(int conn, char *fid, int start, int len)
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
      ATerror("tb_get_focus_text: failed to realloc to %d bytes\n", needed);
    }

    f = fopen(filename, "rb");
    if (f == NULL) {
      ATwarning("tb_get_focus_text: failed to read %s\n", filename);
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
    ATwarning("meta-gvim: No focus text available, winging it so we don't crash.\n");
    contents = strdup("");
  }

  /*fprintf(stderr, "focus-text(%d,%d) = [%s]\n", start, len, contents);*/

  return ATmake("snd-value(focus-text(<str>,<str>))", fid, contents);
}

/*}}}  */
/*{{{  void tb_add_menu_item(int conn, char *menu, char *entry) */

void tb_add_menu_item(int conn, char *menu, char *item)
{
  /*ATwarning("tb_add_menu_item: menu=%s, item=%s\n", menu, item);*/
  makeVimMenuItem(menu, item);

  if (strcmp(item, "Parse") == 0) {
    strcpy(parseMenuName, menu);
  }
}

/*}}}  */
/*{{{  void tb_set_char_pos(int conn, char *s, int i) */

void tb_set_char_pos(int conn, char *s, int i)
{
  char cmd[BUFSIZ];
  sprintf(cmd, ":goto %d", i);
  sendToVim(cmd);
}

/*}}}  */
/*{{{  void tb_set_msg(int conn, char *msg) */

void tb_set_msg(int conn, char *msg)
{
  char buf[BUFSIZ];

  sprintf(buf, ":echo \"%s\"", msg);
  sendToVim(buf);
}

/*}}}  */
/*{{{  ATerm edit_file(int conn, char *s) */

ATerm edit_file(int conn, char *s)
{
  char cmd[BUFSIZ];

  strcpy(filename, s);

  sprintf(cmd, ":e %s", s);
  sendToVim(cmd);

  return ATmake("snd-value(file-id(<str>))", id);
}

/*}}}  */
/*{{{  void reload_file(int conn, char *s) */

void reload_file(int conn, char *s)
{
  sendToVim(":e!");
}

/*}}}  */

/*{{{  void move_editor_to_front(int conn, char *s) */

void move_editor_to_front(int conn, char *s)
{
  sendToVim(":call foreground()");
}

/*}}}  */
/*{{{  void rec_ack_event(int conn, ATerm t) */

void rec_ack_event(int conn, ATerm t)
{
  /*ATwarning("rec_ack_event %t\n", t);*/
}

/*}}}  */
/*{{{  void rec_terminate(int conn, ATerm t) */

void rec_terminate(int conn, ATerm t)
{
  sendToVim(":qa");
  exit(0);
}

/*}}}  */

/*{{{  static int eventloop() */

static int eventloop()
{
  char buf[BUFSIZ];
  fd_set set;
  int max_fd;
  int retval;

  while (ATtrue) {
    FD_ZERO(&set);
    max_fd = ATBgetDescriptors(&set);

    FD_SET(vim_fd, &set);
    if (vim_fd > max_fd) {
      max_fd = vim_fd;
    }

    retval = select(max_fd+1, &set, NULL, NULL, NULL);
    if (retval == -1) {
      perror("select");
    }

    if (FD_ISSET(vim_fd, &set)) {
      int nr_read = read(vim_fd, buf, BUFSIZ-1);
      if (nr_read <= 0) {
	close(vim_fd);
	ATBwriteTerm(tb_fd, ATparse("snd-disconnect"));
	return -1;
      }
      buf[nr_read+1] = '\0';
      handleVimInput(buf);
    }
    else {
      ATBhandleAny();
    }
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

  ATBinit(argc, argv, &bottomOfStack);

  pid = fork();
  if (pid < 0) {
    perror("fork");
    return -1;
  }
  else if (pid == 0) {
    /* parent */
    int handshake_length = strlen(HANDSHAKE);

    close(from_vim[PIPE_WRITE]);
    vim_fd = from_vim[PIPE_READ];
    if (read(vim_fd, buf, handshake_length) != handshake_length) {
      perror("read");
      return -1;
    }
    else if (strncmp(buf, HANDSHAKE, handshake_length)) {
      ATerror("%s: protocol error in handshake.\n", argv[0]);
      return -1;
    }
    sprintf(buf, ":source %s", path_vim);
    sendToVim(buf);

    tb_fd = ATBconnect(NULL, NULL, -1, text_editor_handler);
    return eventloop();
  }
  else {
    /* child */
    close(from_vim[PIPE_READ]);
    /*ATwarning("forking, pid=%d, servername=\"%s\"\n", pid, id);*/

    sprintf(buf,
	    "let tb_pipe = %d"
	    "| call libcallnr(\"%s\", \"handshake\", tb_pipe)",
	    from_vim[PIPE_WRITE], path_lib);

    execlp("gvim", "gvim", "--servername", id, "-c", buf, NULL);

    /* only get here in case of error */
    perror("execlp");
    return -1;
  }
}

/*}}}  */
