/*{{{  includes */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <pwd.h>
#include <assert.h>

#include <aterm2.h>
#include <atb-tool.h>

#include <connector.h>
#include <TextEditor.h>
#include <Location.h>
#include <MetaConfig.h>

#include "protocol.h"

/*}}}  */
/*{{{  defines */

#define ANONYMOUS "anonymous"

#define READ_FROM_HIVE "--read_from_hive_fd"
#define WRITE_TO_HIVE "--write_to_hive_fd"
#define FILENAME "--filename"

#define PIPE_READ 0
#define PIPE_WRITE 1

#define ESCAPE_CHAR '\\'
#define SPACE_CHAR ' '
#define QUOTE_CHAR '"'
#define EOS '\0'

#define RGB "#%02x%02x%02x"

/*}}}  */
/*{{{  variables */

static char *path_lib = LIBDIR "/lib_gvim.so";
static char *path_vim = DATADIR "/meta.vim";

static char *id = NULL;
static int read_from_editor_fd = -1;

/*}}}  */

/*{{{  static char *escape(const char *input, char toBeEscaped) */

static char *escape(const char *input, char toBeEscaped)
{
  static char *buf = NULL;
  const char *p;
  char *s;
  int len;

  len = strlen(input);
  buf = realloc(buf, len*2 + 1);

  p = input;
  s = buf;
  while (p && *p) {
    if (*p == toBeEscaped || *p == ESCAPE_CHAR) {
      *s++ = ESCAPE_CHAR;
    }
    *s++ = *p++;
  }
  *s++ = EOS;

  return buf;
}

/*}}}  */
/*{{{  static char *attributesToProperties(MC_TextAttributes attributes) */

static char *attributesToProperties(MC_TextAttributes attributes)
{
  static char buffer[BUFSIZ];
  buffer[0] = '\0';

  while (!MC_isTextAttributesEmpty(attributes)) {
    MC_TextAttribute attr = MC_getTextAttributesHead(attributes);
    int len = strlen(buffer);
    char *end = buffer + len;
    int spaceLeft = BUFSIZ - len - 1;

    if (MC_isTextAttributeForegroundColor(attr)) {
      MC_Color color = MC_getTextAttributeColor(attr);
      assert(MC_isColorRgb(color));
      snprintf(end, spaceLeft, " guifg=" RGB,
	      MC_getColorRed(color),
	      MC_getColorGreen(color),
	      MC_getColorBlue(color));
    }
    else if (MC_isTextAttributeBackgroundColor(attr)) {
      MC_Color color = MC_getTextAttributeColor(attr);
      assert(MC_isColorRgb(color));
      snprintf(end, spaceLeft," guibg=" RGB,
	      MC_getColorRed(color),
	      MC_getColorGreen(color),
	      MC_getColorBlue(color));
    }
    else if (MC_isTextAttributeStyle(attr)) {
      MC_TextStyle style = MC_getTextAttributeStyle(attr);

      if (MC_isTextStyleBold(style)) {
	snprintf(end, spaceLeft, " gui=bold");
      }
      else if (MC_isTextStyleItalics(style)) {
	snprintf(end, spaceLeft, " gui=italic");
      }
      else if (MC_isTextStyleUnderlined(style)) {
	snprintf(end, spaceLeft, " gui=underline");
      }
    }
    else if (MC_isTextAttributeSize(attr)) {
      /* VIM does not support different font sizes in a single buffer */
    }

    attributes = MC_getTextAttributesTail(attributes);
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
  buf[len] = EOS;

  return buf;
}

/*}}}  */

/*{{{  static void sendToVimVerbatim(const char *cmd) */

static void sendToVimVerbatim(const char *cmd)
{
  char buf[BUFSIZ];
  sprintf(buf, "gvim --servername %s --remote-send \"%s\"", id, cmd);
  system(buf);
}

/*}}}  */
/*{{{  static void sendToVim(const char *cmd) */

static void sendToVim(const char *cmd)
{
  char buf[BUFSIZ];
  sprintf(buf, "%s<Cr>", escape(cmd, QUOTE_CHAR));
  sendToVimVerbatim(buf);
}

/*}}}  */

/*{{{  static void makeVimMenuItem(TE_Menu menu) */

static void makeVimMenuItem(TE_Menu menu)
{
  TE_Items items;
  const char *item;
  char buf[BUFSIZ];
  char escapedBuf[BUFSIZ];

  items = TE_getMenuItems(menu);

  strcpy(buf, ":call AddMenu(tb_pipe, \"");

  item = TE_getItemsHead(items);
  items = TE_getItemsTail(items);
  strcpy(escapedBuf, escape(item, SPACE_CHAR));
  strcat(buf, escape(escapedBuf, SPACE_CHAR));

  strcat(buf, "\", \"");

  item = TE_getItemsHead(items);
  items = TE_getItemsTail(items);
  strcpy(escapedBuf, escape(item, SPACE_CHAR));
  strcat(buf, escape(escapedBuf, SPACE_CHAR));

  strcat(buf, "\", \"");

  strcpy(escapedBuf, escape(menuToString(menu), QUOTE_CHAR));
  strcat(buf, escape(escapedBuf, QUOTE_CHAR));

  strcat(buf, "\")");

  sendToVim(buf);
  protocolExpect(read_from_editor_fd, HANDSHAKE);
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
/*{{{  static void addActions(int write_to_editor_fd, TE_Action edAction) */

static void addActions(int write_to_editor_fd, TE_Action edAction)
{
  TE_ActionList actionList;

  actionList = TE_getActionActions(edAction);
  while (!TE_isActionListEmpty(actionList)) {
    TE_Menu menu = TE_getActionListHead(actionList);
    assert(TE_isValidMenu(menu));
    makeVimMenuItem(menu);
    actionList = TE_getActionListTail(actionList);
  }
  sendToVimVerbatim("");
}

/*}}}  */
/*{{{  static void writeContents(int write_to_editor_fd) */

static void writeContents(int write_to_editor_fd)
{
  sendToVim(":call WriteContents()");
  protocolExpect(read_from_editor_fd, HANDSHAKE);
}

/*}}}  */
/*{{{  static void rereadContents(int write_to_editor_fd) */

static void rereadContents(int write_to_editor_fd)
{
  sendToVim(":call RereadContents()");
  protocolExpect(read_from_editor_fd, HANDSHAKE);
}

/*}}}  */
/*{{{  static void clearFocus(int write_to_editor_fd) */

static void clearFocus(int write_to_editor_fd)
{
  sendToVim(":silent! syn clear Focus");
  sendToVim(":echo \"Focus symbol: <none>\"");
}

/*}}}  */
/*{{{  static void registerTextCategories(int write_to_editor_fd, TE_Action action) */

static void registerTextCategories(int write_to_editor_fd, TE_Action action)
{
  ATermList categories = (ATermList) TE_getActionCategories(action);

  while (!ATisEmpty(categories)) {
    MC_Property category = MC_PropertyFromTerm(ATgetFirst(categories));
    MC_TextCategoryName name = MC_getPropertyCategory(category);
    MC_TextAttributes attributes = MC_getPropertyAttributes(category);
    char buf[BUFSIZ];
    
    if (!MC_isTextAttributesEmpty(attributes)) {
      const char *properties = attributesToProperties(attributes);
      if (MC_isTextCategoryNameExtern(name)) {
	const char *str = MC_getTextCategoryNameName(name);
	sprintf(buf, ":highlight %s %s", str, properties);
      }
      else if (MC_isTextCategoryNameFocus(name)) {
	sprintf(buf, ":highlight Focus %s", properties);
      }
      else if (MC_isTextCategoryNameSelection(name)) {
	sprintf(buf, ":highlight Visual %s", properties);
      }
      else if (MC_isTextCategoryNameNormal(name)) {
	sprintf(buf, ":highlight Normal %s", properties);
      }

      sendToVim(buf);
    }

    categories = ATgetNext(categories);
  }
}

/*}}}  */
/*{{{  static void highlightSlices(int write_to_editor_fd, TE_Action action) */

static void highlightSlices(int write_to_editor_fd, TE_Action action)
{
  char filename[] = "/tmp/syntax-vim-XXXXXX";
  char source[BUFSIZ];
  int fd;
  FILE *f;
  ATermList slices = (ATermList) TE_getActionSlices(action);

  fd = mkstemp(filename);
  if (fd < 0) {
    perror("mkstemp");
    exit(errno);
  }

  f = fdopen(fd, "w");
  if (f == NULL) {
    perror("fdopen");
    exit(errno);
  }

  /* Reset syntax rules */
  fprintf(f, ":syntax off\n");
  fprintf(f, ":syntax on\n");

  while (!ATisEmpty(slices)) {
    LOC_Slice slice = LOC_SliceFromTerm(ATgetFirst(slices));
    const char* category = LOC_getSliceId(slice);
    LOC_AreaAreas areas = LOC_getSliceAreas(slice);

    while (!LOC_isAreaAreasEmpty(areas)) {
      LOC_Area area = LOC_getAreaAreasHead(areas);
      areas = LOC_getAreaAreasTail(areas);

      fprintf(f,
	      ":syn region %s "
	      "start=\"\\%%%dl\\%%%dv\" "
	      "end=\"\\%%%dl\\%%%dc\"\n",
	      category,
	      LOC_getAreaBeginLine(area),
	      LOC_getAreaBeginColumn(area) + 1,
	      LOC_getAreaEndLine(area),
	      LOC_getAreaEndColumn(area) + 1
	     );
    }

    slices = ATgetNext(slices);
  }

  fprintf(f, "\"The next line will delete this file upon sourcing\n");
  fprintf(f, ":silent !rm %s\n",filename);
  fclose(f);

  sprintf(source, ":source %s", filename);
  sendToVim(source);
}

/*}}}  */
/*{{{  static void setFocus(int write_to_editor_fd, TE_Action edAction) */

static void setFocus(int write_to_editor_fd, TE_Action edAction)
{
  ATerm focusTerm = TE_getActionFocus(edAction);
  LOC_Area area = LOC_AreaFromTerm(focusTerm);
  int start = LOC_getAreaOffset(area);
  int length = LOC_getAreaLength(area);
  char buf[BUFSIZ];

  sendToVim(":silent! syn clear Focus");
  sprintf(buf, ":call SetFocus(%d, %d)", start, length);
  sendToVim(buf);
}

/*}}}  */
/*{{{  static void displayMessage(int write_to_editor_fd, TE_Action edAction) */

static void displayMessage(int write_to_editor_fd, TE_Action edAction)
{
  char *escaped;
  char buf[BUFSIZ];

  sprintf(buf, TE_getActionMessage(edAction));

  escaped = escape(buf, ESCAPE_CHAR);
  escaped = escape(buf, QUOTE_CHAR);
  sprintf(buf, ":echo \"%s\"", escaped);

  sendToVim(buf);
}

/*}}}  */
/*{{{  static void gotoCursorAtOffset(int write_to_editor_fd, int offset) */

static void gotoCursorAtOffset(int write_to_editor_fd, int offset)
{
  char cmd[BUFSIZ];
  sprintf(cmd, ":goto %d", offset);
  sendToVim(cmd);
}

/*}}}  */
/*{{{  static void setCursorAtOffset(int write_to_editor_fd, TE_Action edAction) */

static void setCursorAtOffset(int write_to_editor_fd, TE_Action edAction)
{
  int offset = TE_getActionOffset(edAction);
  gotoCursorAtOffset(write_to_editor_fd, offset);
}

/*}}}  */
/*{{{  static void isModified(int write_to_editor_fd) */

static void isModified(int write_to_editor_fd)
{
  sendToVim(":call IsModified()");
  protocolExpect(read_from_editor_fd, HANDSHAKE);
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

  gvimEditor = initTextEditor(hiveClosed,
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

    protocolExpect(read_from_editor_fd, CONNECTED);

    sprintf(buf, ":source %s", path_vim);
    sendToVim(buf);
    protocolExpect(read_from_editor_fd, HANDSHAKE);

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

    execlp("gvim", "gvim", "--servername", id, "-c", buf, getFileName(), NULL);

    /* only get here in case of error */
    perror("execlp-vim");
    return -1;
  }
}

/*}}}  */
