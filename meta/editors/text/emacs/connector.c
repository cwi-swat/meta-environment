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
#include <Location.h>
#include <MetaConfig.h>

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

#define RGB "\"RGB:%02x/%02x/%02x\""

/*{{{  static char *attributesToProperties(MC_TextAttributes attributes) */

static char *attributesToProperties(MC_TextAttributes attributes)
{
  static char buffer[BUFSIZ];
  buffer[0] = '\0';

  for ( ; !MC_isTextAttributesEmpty(attributes); 
	attributes = MC_getTextAttributesTail(attributes)) {
    MC_TextAttribute attr = MC_getTextAttributesHead(attributes);
    char *end = buffer+strlen(buffer);
    int len = strlen(buffer);
    int spaceLeft = BUFSIZ - len - 1;

    if (MC_isTextAttributeForegroundColor(attr)) {
      MC_Color color = MC_getTextAttributeColor(attr);
      assert(MC_isColorRgb(color));
      snprintf(end, spaceLeft, " :foreground " RGB,
	      MC_getColorRed(color),
	      MC_getColorGreen(color),
	      MC_getColorBlue(color));
    }
    else if (MC_isTextAttributeBackgroundColor(attr)) {
      MC_Color color = MC_getTextAttributeColor(attr);
      assert(MC_isColorRgb(color));
      snprintf(end, spaceLeft," :background " RGB,
	      MC_getColorRed(color),
	      MC_getColorGreen(color),
	      MC_getColorBlue(color));
    }
    else if (MC_isTextAttributeStyle(attr)) {
      MC_TextStyle style = MC_getTextAttributeStyle(attr);

      if (MC_isTextStyleBold(style)) {
	snprintf(end, spaceLeft, " :weight 'bold");
      }
      else if (MC_isTextStyleItalics(style)) {
	snprintf(end, spaceLeft, " :slant 'italic");
      }
      else if (MC_isTextStyleUnderlined(style)) {
	snprintf(end, spaceLeft, " :underline t");
      }
    }
    else if (MC_isTextAttributeSize(attr)) {
      snprintf(end, spaceLeft, " :height %d", 
	       10*MC_getTextAttributePoints(attr));
    }
    else if (MC_isTextAttributeFont(attr)) {
      snprintf(end, spaceLeft, 
	       " :family \"%s\"", MC_getTextAttributeName(attr));
    }
  }

  return buffer;
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
/*{{{  static void addSubMenu(int write_to_editor_fd, const char *top, const char *sub, TE_Menu menu) */

static void addSubMenu(int write_to_editor_fd, const char *top, const char *sub, TE_Menu menu)
{
  char buf[BUFSIZ];
  char strippedTop[BUFSIZ];
  char strippedSub[BUFSIZ];
  char menuString[BUFSIZ];
  char escapedMenu[BUFSIZ];

  strcpy(strippedTop, stripIllegalMenuChars(top));
  strcpy(strippedSub, stripIllegalMenuChars(sub));

  strcpy(menuString, menuToString(menu));
  strcpy(escapedMenu, escapeQuotes(menuString));

  sprintf(buf,
	  "(define-key-after"
	  "  (lookup-key global-map [menu-bar %s-%s])"
	  "  [%s-%s-%s]"
	  "  (cons \"%s\""
	  "    (lambda () (interactive) (meta-menu-event \"%s\")))"
	  ")"
	  , META_MENU_PREFIX, strippedTop
	  , META_MENU_PREFIX, strippedTop, strippedSub
	  , sub
	  , escapedMenu
	  );
  sendToEmacs(write_to_editor_fd, buf);
  sendToEmacs(write_to_editor_fd, "(redraw-display)");
}

/*}}}  */
/*{{{  static void makeEmacsMenuItem(int write_to_editor_fd, TE_Menu menu) */

static void makeEmacsMenuItem(int write_to_editor_fd, TE_Menu menu)
{
  TE_Items items;
  const char *top;
  const char *sub;

  items = TE_getMenuItems(menu);
  top = TE_getItemsHead(items);
  addTopMenu(write_to_editor_fd, top);

  items = TE_getItemsTail(items);
  sub = TE_getItemsHead(items);
  addSubMenu(write_to_editor_fd, top, sub, menu);
}

/*}}}  */

/*{{{  static void makeEmacsShortcut(int write_to_editor_fd, TE_Menu menu) */

static void makeEmacsShortcut(int write_to_editor_fd, TE_Menu menu)
{
  char buf[BUFSIZ];
  char escapedMenu[BUFSIZ];

  strcpy(escapedMenu, escapeQuotes(menuToString(menu)));

  sprintf(buf, 
	  "(define-key global-map (edmacro-parse-keys \"%s\")"
	  " (lambda () (interactive) (meta-menu-event \"%s\")))"
	  , TE_getMenuShortcut(menu)
	  , escapedMenu
	  );
  sendToEmacs(write_to_editor_fd, buf);
  /*sendToEmacs(write_to_editor_fd, "(redraw-display)"); Needed ??? */
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
/*{{{  static void addActions(int write_to_editor_fd, TE_Action edAction) */

static void addActions(int write_to_editor_fd, TE_Action edAction)
{
  TE_ActionList actionList;

  actionList = TE_getActionActions(edAction);
  while (!TE_isActionListEmpty(actionList)) {
    TE_Menu menu = TE_getActionListHead(actionList);
    assert(TE_isValidMenu(menu));

    makeEmacsMenuItem(write_to_editor_fd, menu);

    if (TE_hasMenuShortcut(menu)) {
      makeEmacsShortcut(write_to_editor_fd, menu);
    }

    actionList = TE_getActionListTail(actionList);
  }
}

/*}}}  */
/*{{{  static void setFocus(int write_to_editor_fd, TE_Action edAction) */

static void setFocus(int write_to_editor_fd, TE_Action edAction)
{
  ATerm focusTerm = TE_getActionFocus(edAction);
  LOC_Area area = LOC_AreaFromTerm(focusTerm);
  int start = LOC_getAreaOffset(area) + 1;
  int length = LOC_getAreaLength(area);
  char buf[BUFSIZ];

  sprintf(buf, "(set-focus %d %d)", start, start+length);
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
/*{{{  static void registerTextCategories(int write_to_editor_fd, TE_Action action) */

static void registerTextCategories(int write_to_editor_fd, TE_Action action)
{
  ATermList categories = (ATermList) TE_getActionCategories(action);

  for (;!ATisEmpty(categories); categories = ATgetNext(categories)) {
    MC_Property category = MC_PropertyFromTerm(ATgetFirst(categories));
    MC_TextCategoryName name = MC_getPropertyCategory(category);
    MC_TextAttributes attributes = MC_getPropertyAttributes(category);

    if (MC_isTextCategoryNameExtern(name)) {
      char buf[BUFSIZ];
      const char* str = MC_getTextCategoryNameName(name);
      char *attribs = attributesToProperties(attributes);

      sprintf(buf, "(register-category '%s (list %s))", str, attribs);
      sendToEmacs(write_to_editor_fd, buf);
    }
  }
}

/*}}}  */
/*{{{  static void highlightSlices(int write_to_editor_fd, TE_Action action) */

static void highlightSlices(int write_to_editor_fd, TE_Action action)
{
  ATermList slices = (ATermList) TE_getActionSlices(action);

  sendToEmacs(write_to_editor_fd, "(clear-highlights)");

  for (; !ATisEmpty(slices); slices = ATgetNext(slices)) {
    LOC_Slice slice = LOC_SliceFromTerm(ATgetFirst(slices));
    const char* category = LOC_getSliceId(slice);
    LOC_AreaAreas areas = LOC_getSliceAreas(slice);

    for (; !LOC_isAreaAreasEmpty(areas); areas = LOC_getAreaAreasTail(areas)) {
      LOC_Area area = LOC_getAreaAreasHead(areas);
      int start = LOC_getAreaOffset(area) + 1;
      int length = LOC_getAreaLength(area);
      char buf[BUFSIZ];

      sprintf(buf, "(set-highlight %d %d '%s)", 
	      start, start+length, category);
      sendToEmacs(write_to_editor_fd, buf);
    }
  }
}

/*}}}  */
/*{{{  static void displayMessage(int write_to_editor_fd, TE_Action edAction) */

static void displayMessage(int write_to_editor_fd, TE_Action edAction)
{
  char buf[BUFSIZ];

  sprintf(buf,
	  "(display-message-or-buffer \"%s\")",
	  escapeQuotes(TE_getActionMessage(edAction)));

  sendToEmacs(write_to_editor_fd, buf);
}

/*}}}  */
/*{{{  static void gotoCursorAtLocation(int write_to_editor_fd, int offset) */

static void gotoCursorAtLocation(int write_to_editor_fd, int offset)
{
  char buf[BUFSIZ];

  sprintf(buf, "(goto-char %d)", offset);
  sendToEmacs(write_to_editor_fd, buf);
}

/*}}}  */
/*{{{  static void setCursorAtOffset(int write_to_editor_fd, TE_Action edAction) */

static void setCursorAtOffset(int write_to_editor_fd, TE_Action edAction)
{
  int offset = TE_getActionOffset(edAction);
  gotoCursorAtLocation(write_to_editor_fd, offset);
}

/*}}}  */
/*{{{  static void rereadContents(int write_to_editor_fd) */

static void rereadContents(int write_to_editor_fd)
{
  sendToEmacs(write_to_editor_fd, "(reread-contents)");
}

/*}}}  */
/*{{{  static void rereadContents(int write_to_editor_fd) */

static void isModified(int write_to_editor_fd)
{
  sendToEmacs(write_to_editor_fd, "(is-modified)");
}

/*}}}  */

/*{{{  static void writeContents(int write_to_editor_fd) */

static void writeContents(int write_to_editor_fd)
{
  sendToEmacs(write_to_editor_fd, "(write-contents)");
  protocolExpect(fileno(stdin), "handshake");
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
  LOC_initLocationApi();
  TE_initTextEditorApi();
  MC_initMetaConfigApi();

  for (i=1; i<argc; i++) {
    char *cur = argv[i];

    if (strcmp(cur, READ_FROM_HIVE) == 0) {
      read_from_hive_fd = atoi(argv[++i]);
    }
    else if (strcmp(cur, WRITE_TO_HIVE) == 0) {
      write_to_hive_fd = atoi(argv[++i]);
    }
    else if (strcmp(cur, FILENAME) == 0) {
      setFileName(argv[++i]);
    }
  }

  emacsEditor = initTextEditor(hiveClosed,
			       clearFocus,
			       moveToFront,
			       writeContents,
			       rereadContents,
			       displayMessage,
			       addActions,
			       setFocus,
			       registerTextCategories,
			       highlightSlices,
			       setCursorAtOffset,
			       isModified);

  hiveToEditor = TE_makePipeDefault(read_from_hive_fd, fileno(stdout));
  editorToHive = TE_makePipeDefault(fileno(stdin), write_to_hive_fd);

  return eventloop(emacsEditor, hiveToEditor, editorToHive);
}

/*}}}  */
