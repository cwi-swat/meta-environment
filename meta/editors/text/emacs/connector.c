/* $Id$ */

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

#include <connector.h>
#include <TextEditor.h>
#include <EditorData.h>

/*}}}  */
/*{{{  defines */

#define READ_FROM_HIVE "--read_from_hive_fd"
#define WRITE_TO_HIVE "--write_to_hive_fd"
#define FILENAME "--filename"

#define META_MENU_PREFIX "meta"

#define ILLEGAL_MENU_CHARS " ()"
#define ESCAPE_CHAR '\\'
#define QUOTE '"'

/*}}}  */
/*{{{  variables */

static char filename[BUFSIZ] = { 0 };

/*}}}  */

/*{{{  static char *escapeQuotes(const char *input) */

static char *escapeQuotes(const char *input)
{
  static char buf[BUFSIZ*3];
  const char *p;
  char *s;

  assert(strlen(input) < BUFSIZ);

  p = input;
  s = buf;
  while (p && *p) {
    if (strchr("\\\"", *p)) {
      *s++ = ESCAPE_CHAR;
    }
    *s++ = *p++;
  }
  *s++ = '\0';

  return buf;
}

/*}}}  */
/*{{{  static char *stripIllegalMenuChars(const char *input) */

static char *stripIllegalMenuChars(const char *input)
{
  static char buf[BUFSIZ];
  const char *p;
  char *s;

  assert(strlen(input) < BUFSIZ);

  p = input;
  s = buf;

  while (p && *p) {
    if (strchr(ILLEGAL_MENU_CHARS, *p)) {
      *s++ = '_';  /* we could decide to remove them altogether */
    }
    else {
      *s++ = *p;
    }
    p++;
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

/*{{{  static void sendToEmacs(int write_to_editor_fd, const char *cmd) */

static void sendToEmacs(int write_to_editor_fd, const char *cmd)
{
  write(write_to_editor_fd, cmd, strlen(cmd));
  write(write_to_editor_fd, "\n", 1);
}

/*}}}  */

/*{{{  static void addTopMenu(int write_to_editor_fd, const char *menu) */

static void addTopMenu(int write_to_editor_fd, const char *menu)
{
  /* Since creating the same top-menu a second time overwrites anything
   * that is present in that top-menu at the time, we keep track of the
   * most recently added top-menu.
   * TODO: improve this.
   */
  static char mostRecentMenu[BUFSIZ];

  if (strcmp(mostRecentMenu, menu) != 0) {
    char strippedMenu[BUFSIZ];
    char buf[BUFSIZ];

    strcpy(strippedMenu, stripIllegalMenuChars(menu));
    strcpy(mostRecentMenu, menu);
    sprintf(buf,
	  "(define-key-after"
	  "  (lookup-key global-map [menu-bar])"
	  "  [%s-%s]"
	  "  (cons \"%s\" (make-sparse-keymap)))"
	  , META_MENU_PREFIX, strippedMenu
	  , menu
	  );
    sendToEmacs(write_to_editor_fd, buf);
    sendToEmacs(write_to_editor_fd, "(redraw-display)");
  }

}

/*}}}  */
/*{{{  static void addSubMenu(int write_to_editor_fd, char *menu, char *item) */

static void addSubMenu(int write_to_editor_fd, char *menu, char *item)
{
  char buf[BUFSIZ];
  char strippedMenu[BUFSIZ];
  char strippedItem[BUFSIZ];
  char menuString[BUFSIZ];
  char escapedMenu[BUFSIZ];

  strcpy(strippedMenu, stripIllegalMenuChars(menu));
  strcpy(strippedItem, stripIllegalMenuChars(item));
  strcpy(menuString, menuToString(TE_makeMenuDefault(menu, item)));
  strcpy(escapedMenu, escapeQuotes(menuString));

  sprintf(buf,
	  "(define-key-after"
	  "  (lookup-key global-map [menu-bar %s-%s])"
	  "  [%s-%s-%s]"
	  "  (cons \"%s\""
	  "    (lambda () (interactive) (meta-menu-event \"%s\")))"
	  ")"
	  , META_MENU_PREFIX, strippedMenu
	  , META_MENU_PREFIX, strippedMenu, strippedItem
	  , item
	  , escapedMenu
	  );
  sendToEmacs(write_to_editor_fd, buf);
  sendToEmacs(write_to_editor_fd, "(redraw-display)");
}

/*}}}  */
/*{{{  static void makeEmacsMenuItem(int write_to_editor_fd, char *menu, char *item) */

static void makeEmacsMenuItem(int write_to_editor_fd, char *menu, char *item)
{
  addTopMenu(write_to_editor_fd, menu);
  addSubMenu(write_to_editor_fd, menu, item);
}

/*}}}  */

/*{{{  static void hiveClosed(int write_to_editor_fd) */

static void hiveClosed(int write_to_editor_fd)
{
  sendToEmacs(write_to_editor_fd, "(save-buffers-kill-emacs)");
}

/*}}}  */
/*{{{  static void moveToFront(int write_to_editor_fd) */

static void moveToFront(int write_to_editor_fd)
{
  sendToEmacs(write_to_editor_fd, "(raise-frame)");
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
    makeEmacsMenuItem(write_to_editor_fd,
		      TE_getMenuMain(menu),
		      TE_getMenuSub(menu));
    actionList = TE_getActionListTail(actionList);
  }
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

  sprintf(buf, "(set-focus %d %d)", start, start+length);
  sendToEmacs(write_to_editor_fd, buf);

  sprintf(buf,
	  "  (display-message-or-buffer (concat \"Focus symbol: \" \"%s\"))",
	  escapeQuotes(s));
  sendToEmacs(write_to_editor_fd, buf);
}

/*}}}  */
/*{{{  static void clearFocus(int write_to_editor_fd) */

static void clearFocus(int write_to_editor_fd)
{
  sendToEmacs(write_to_editor_fd, "(clear-focus)");
  sendToEmacs(write_to_editor_fd,
	      "(display-message-or-buffer (concat \"Focus symbol: <none>\"))");
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
    ATwarning("emacs-editor: No focus text available, winging it.\n");
    contents = strdup("");
  }

  sendToHive(write_to_hive_fd, TE_makeEventContents(contents));
}

/*}}}  */
/*{{{  static void displayMessage(int write_to_editor_fd, TE_Action edAction) */

static void displayMessage(int write_to_editor_fd, TE_Action edAction)
{
  char buf[BUFSIZ];

  sprintf(buf,
	  "(display-message-or-buffer \"%s\")",
	  TE_getActionMessage(edAction));

  sendToEmacs(write_to_editor_fd, buf);
}

/*}}}  */
/*{{{  static void gotoCursorAtLocation(int write_to_editor_fd, int location) */

static void gotoCursorAtLocation(int write_to_editor_fd, int location)
{
  char buf[BUFSIZ];

  sprintf(buf, "(goto-char %d)", location);
  sendToEmacs(write_to_editor_fd, buf);
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
/*{{{  static void rereadContents(int write_to_editor_fd) */

static void rereadContents(int write_to_editor_fd)
{
  sendToEmacs(write_to_editor_fd, "(revert-buffer nil t)");
}

/*}}}  */

/*{{{  int main(int argc, char *argv[]) */

int main(int argc, char *argv[])
{
  ATerm bottomOfStack;
  int i;
  TE_Pipe hiveToEditor;
  TE_Pipe editorToHive;
  TextEditor emacsEditor;
  int read_from_hive_fd = -1;
  int write_to_hive_fd = -1;

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

  emacsEditor = initTextEditor(hiveClosed,
			       clearFocus,
			       moveToFront,
			       rereadContents,
			       displayMessage,
			       setCursorAtLocation,
			       setCursorAtFocus,
			       setActions,
			       setFocus,
			       getContents);

  hiveToEditor = TE_makePipeDefault(read_from_hive_fd, fileno(stdout));
  editorToHive = TE_makePipeDefault(fileno(stdin), write_to_hive_fd);

  return eventloop(emacsEditor, hiveToEditor, editorToHive);
}

/*}}}  */
