/* $Id$ */

/*{{{  includes */

#include <assert.h>
#include <ctype.h>
#include <errno.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/select.h>
#include <sys/stat.h>
#include <unistd.h>

#include <aterm1.h>
#include <atb-tool.h>

#include <TextEditor.h>

#include "connector.h"

/*}}}  */
/*{{{  defines */

#define MODIFIED "modified"

/*}}}  */

/*{{{  structs */

struct _TextEditor
{
  hive_closed_t hiveClosed;
  clear_focus_t clearFocus;
  move_to_front_t moveToFront;
  write_contents_t writeContents;
  reread_contents_t rereadContents;
  display_message_t displayMessage;
  set_actions_t setActions;
  set_focus_t setFocus;
  set_cursor_at_offset_t setCursorAtOffset;
};

/*}}}  */
/*{{{  variables */

static char filename[PATH_MAX + 1] = { 0 };

/*}}}  */

/*{{{  void setFileName(const char *name) */

void setFileName(const char *name)
{
  assert(name != NULL);
  assert(strlen(name) <= PATH_MAX);

  strcpy(filename, name);
}

/*}}}  */
/*{{{  const char *getFileName() */

const char *getFileName()
{
  return filename;
}

/*}}}  */

/*{{{  void protocolExpect(int fd, const char *expected) */

void protocolExpect(int fd, const char *expected)
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

/*{{{  void sendToHive(int write_to_hive_fd, TE_Event event) */

void sendToHive(int write_to_hive_fd, TE_Event event)
{
  ATBwriteTerm(write_to_hive_fd, TE_EventToTerm(event));
}

/*}}}  */

/*{{{  static void getContents(int write_to_hive_fd) */

static void getContents(int write_to_hive_fd)
{
  static char *contents = NULL;
  struct stat statrec;
  int size;

  if (stat(getFileName(), &statrec) == -1) {
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

    f = fopen(getFileName(), "rb");
    if (f == NULL) {
      ATwarning("getContents: failed to read %s\n", getFileName());
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
    ATwarning("editor: No focus text available, winging it.\n");
    contents = strdup("");
  }

  sendToHive(write_to_hive_fd, TE_makeEventContents(contents));
}

/*}}}  */
/*{{{  static void handleEditorInput(int write_to_hive_fd, const char *input) */

static void handleEditorInput(int write_to_hive_fd, const char *input)
{
  TE_Event event;

  if (isdigit((int) *input)) {
    int loc = atoi(input);
    event = TE_makeEventMouse(loc);
  }
  else if (strncmp(input, MODIFIED, strlen(MODIFIED)) == 0) {
    event = TE_makeEventModified();
  }
  else {
    event = TE_makeEventMenu(TE_MenuFromTerm(ATparse(input)));
  }

  sendToHive(write_to_hive_fd, event);
}

/*}}}  */
/*{{{  static void handleHiveInput(...) */

static void handleHiveInput(TextEditor editor,
			    int write_to_editor_fd,
			    int write_to_hive_fd,
			    TE_Action action)
{
  assert(editor != NULL);

  if (TE_isActionGetContents(action)) {
    getContents(write_to_hive_fd);
  }
  else if (TE_isActionQuit(action)) {
    editor->hiveClosed(write_to_editor_fd);
  }
  else if (TE_isActionClearFocus(action)) {
    editor->clearFocus(write_to_editor_fd);
  }
  else if (TE_isActionToFront(action)) {
    editor->moveToFront(write_to_editor_fd);
  }
  else if (TE_isActionWriteContents(action)) {
    editor->writeContents(write_to_editor_fd);
  }
  else if (TE_isActionRereadContents(action)) {
    editor->rereadContents(write_to_editor_fd);
  }
  else if (TE_isActionDisplayMessage(action)) {
    editor->displayMessage(write_to_editor_fd, action);
  }
  else if (TE_isActionSetActions(action)) {
    editor->setActions(write_to_editor_fd, action);
  }
  else if (TE_isActionSetFocus(action)) {
    editor->setFocus(write_to_editor_fd, action);
  }
  else if (TE_isActionSetCursorAtOffset(action)) {
    editor->setCursorAtOffset(write_to_editor_fd, action);
  }
}

/*}}}  */

/*{{{  TextEditor initTextEditor(...) */

TextEditor initTextEditor(hive_closed_t hiveClosed,
			  clear_focus_t clearFocus,
			  move_to_front_t moveToFront,
			  write_contents_t writeContents,
			  reread_contents_t rereadContents,
			  display_message_t displayMessage,
			  set_actions_t setActions,
			  set_focus_t setFocus,
			  set_cursor_at_offset_t setCursorAtOffset)
{
  TextEditor textEditorImpl = (TextEditor) calloc(1, sizeof(struct _TextEditor));

  assert(hiveClosed != NULL);
  textEditorImpl->hiveClosed = hiveClosed;

  assert(clearFocus != NULL);
  textEditorImpl->clearFocus = clearFocus;

  assert(moveToFront != NULL);
  textEditorImpl->moveToFront = moveToFront;

  assert(writeContents != NULL);
  textEditorImpl->writeContents = writeContents;

  assert(rereadContents != NULL);
  textEditorImpl->rereadContents = rereadContents;

  assert(displayMessage != NULL);
  textEditorImpl->displayMessage = displayMessage;

  assert(setActions != NULL);
  textEditorImpl->setActions = setActions;

  assert(setFocus != NULL);
  textEditorImpl->setFocus = setFocus;

  assert(setCursorAtOffset != NULL);
  textEditorImpl->setCursorAtOffset = setCursorAtOffset;

  return textEditorImpl;
}

/*}}}  */

/*{{{  int eventloop(TextEditor editor, TE_Pipe hiveToEditor, TE_Pipe editorToHive) */

int eventloop(TextEditor editor, TE_Pipe hiveToEditor, TE_Pipe editorToHive)
{
  fd_set set;
  int max_fd;
  int retval;
  int read_from_hive_fd = TE_getPipeRead(hiveToEditor);
  int read_from_editor_fd = TE_getPipeRead(editorToHive);
  int write_to_hive_fd = TE_getPipeWrite(editorToHive);
  int write_to_editor_fd = TE_getPipeWrite(hiveToEditor);

  while (ATtrue) {
    FD_ZERO(&set);

    FD_SET(read_from_hive_fd, &set);
    max_fd = read_from_hive_fd;

    FD_SET(read_from_editor_fd, &set);
    if (read_from_editor_fd > max_fd) {
      max_fd = read_from_editor_fd;
    }

    retval = select(max_fd+1, &set, NULL, NULL, NULL);
    if (retval == -1) {
      perror("select");
    }

    if (FD_ISSET(read_from_editor_fd, &set)) {
      char buf[BUFSIZ];
      int nr_read;
      nr_read = read(read_from_editor_fd, buf, BUFSIZ-1);
      if (nr_read <= 0) {
	close(read_from_editor_fd);
	return 0;
      }
      buf[nr_read] = '\0';
      handleEditorInput(write_to_hive_fd, buf);
    }

    if (FD_ISSET(read_from_hive_fd, &set)) {
      ATerm t;
      t = ATBreadTerm(read_from_hive_fd);
      if (t == NULL) {
	editor->hiveClosed(write_to_editor_fd);
	return 0;
      }

      handleHiveInput(editor,
		      write_to_editor_fd,
		      write_to_hive_fd,
		      TE_ActionFromTerm(t));
    }
  }
}

/*}}}  */
