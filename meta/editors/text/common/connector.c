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
#define CONTENTS_WRITTEN "contents-written"

/*}}}  */

/*{{{  structs */

struct _TextEditor
{
  handle_editor_input_t handleEditorInput;

  hive_closed_t hiveClosed;
  clear_focus_t clearFocus;
  move_to_front_t moveToFront;
  write_contents_t writeContents;
  reread_contents_t rereadContents;
  display_message_t displayMessage;
  add_actions_t addActions;
  set_focus_t setFocus;
  set_cursor_at_offset_t setCursorAtOffset;
  is_modified_t isModified;
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
/*{{{  void setEditorInputHandler(TextEditor editor, handle_editor_input_t handler) */

void setEditorInputHandler(TextEditor editor, handle_editor_input_t handler)
{
  assert(editor != NULL);
  assert(handler != NULL);

  editor->handleEditorInput = handler;
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

/*{{{  static int defaultHandleEditorInput(TE_Pipe hiveToEditor, TE_Pipe editorToHive) */

static int defaultHandleEditorInput(TE_Pipe hiveToEditor, TE_Pipe editorToHive)
{
  TE_Event event;
  char buf[BUFSIZ];
  int nr_read;
  int read_from_editor_fd;
  int write_to_hive_fd;

  read_from_editor_fd = TE_getPipeRead(editorToHive);
  write_to_hive_fd = TE_getPipeWrite(editorToHive);

  nr_read = read(read_from_editor_fd, buf, BUFSIZ-1);
  if (nr_read <= 0) {
    close(read_from_editor_fd);
    return -1;
  }
  buf[nr_read] = '\0';

  if (isdigit((int) *buf)) {
    int loc = atoi(buf);
    event = TE_makeEventMouse(loc);
  }
  else if (strncmp(buf, MODIFIED, strlen(MODIFIED)) == 0) {
    const char *p = buf + strlen(MODIFIED);
    if (*p == '#') {
      event = TE_makeEventIsModified(atoi(p+1));
    }
    else {
      event = TE_makeEventModified();
    }
  }
  else if (strncmp(buf, CONTENTS_WRITTEN, strlen(CONTENTS_WRITTEN)) == 0) {
    event = TE_makeEventContentsWritten();
  }
  else {
    event = TE_makeEventMenu(TE_MenuFromTerm(ATparse(buf)));
  }

  sendToHive(write_to_hive_fd, event);
  return 0;
}

/*}}}  */
/*{{{  static void handleHiveInput(...) */

static void handleHiveInput(TextEditor editor,
			    int write_to_editor_fd,
			    int write_to_hive_fd,
			    TE_Action action)
{
  assert(editor != NULL);

  if (TE_isActionQuit(action)) {
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
  else if (TE_isActionAddActions(action)) {
    editor->addActions(write_to_editor_fd, action);
  }
  else if (TE_isActionSetFocus(action)) {
    editor->setFocus(write_to_editor_fd, action);
  }
  else if (TE_isActionSetCursorAtOffset(action)) {
    editor->setCursorAtOffset(write_to_editor_fd, action);
  }
  else if (TE_isActionIsModified(action)) {
    editor->isModified(write_to_editor_fd);
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
			  add_actions_t addActions,
			  set_focus_t setFocus,
			  set_cursor_at_offset_t setCursorAtOffset,
			  is_modified_t isModified)
{
  TextEditor textEditorImpl = (TextEditor) calloc(1, sizeof(struct _TextEditor));

  textEditorImpl->handleEditorInput = defaultHandleEditorInput;

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

  assert(addActions != NULL);
  textEditorImpl->addActions = addActions;

  assert(setFocus != NULL);
  textEditorImpl->setFocus = setFocus;

  assert(setCursorAtOffset != NULL);
  textEditorImpl->setCursorAtOffset = setCursorAtOffset;

  assert(isModified != NULL);
  textEditorImpl->isModified = isModified;

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
      int retval;
      retval = editor->handleEditorInput(hiveToEditor, editorToHive);
      if (retval == -1) {
	return 0;
      }
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
