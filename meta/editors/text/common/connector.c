/* $Id$ */

/*{{{  includes */

#include <assert.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/select.h>
#include <unistd.h>

#include <aterm1.h>
#include <atb-tool.h>

#include <TextEditor.h>

#include "connector.h"

/*}}}  */

/*{{{  structs */

struct _TextEditor
{
  hive_closed_t hiveClosed;
  clear_focus_t clearFocus;
  move_to_front_t moveToFront;
  reread_contents_t rereadContents;
  display_message_t displayMessage;
  set_cursor_at_location_t setCursorAtLocation;
  set_cursor_at_focus_t setCursorAtFocus;
  set_actions_t setActions;
  set_focus_t setFocus;
  get_contents getContents;
};

/*}}}  */

/*{{{  void sendToHive(int write_to_hive_fd, TE_Event event) */

void sendToHive(int write_to_hive_fd, TE_Event event)
{
  ATBwriteTerm(write_to_hive_fd, TE_EventToTerm(event));
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
  else if (strcmp(input, "modified") == 0) {
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

  if (TE_isActionClearFocus(action)) {
    editor->clearFocus(write_to_editor_fd);
  }
  else if (TE_isActionToFront(action)) {
    editor->moveToFront(write_to_editor_fd);
  }
  else if (TE_isActionRereadContents(action)) {
    editor->rereadContents(write_to_editor_fd);
  }
  else if (TE_isActionDisplayMessage(action)) {
    editor->displayMessage(write_to_editor_fd, action);
  }
  else if (TE_isActionSetCursorAtLocation(action)) {
    editor->setCursorAtLocation(write_to_editor_fd, action);
  }
  else if (TE_isActionSetCursorAtFocus(action)) {
    editor->setCursorAtFocus(write_to_editor_fd, action);
  }
  else if (TE_isActionSetActions(action)) {
    editor->setActions(write_to_editor_fd, action);
  }
  else if (TE_isActionSetFocus(action)) {
    editor->setFocus(write_to_editor_fd, action);
  }
  else if (TE_isActionGetContents(action)) {
    editor->getContents(write_to_hive_fd, action);
  }
}

/*}}}  */

/*{{{  TextEditor initTextEditor(...) */

TextEditor initTextEditor(hive_closed_t hiveClosed,
			  clear_focus_t clearFocus,
			  move_to_front_t moveToFront,
			  reread_contents_t rereadContents,
			  display_message_t displayMessage,
			  set_cursor_at_location_t setCursorAtLocation,
			  set_cursor_at_focus_t setCursorAtFocus,
			  set_actions_t setActions,
			  set_focus_t setFocus,
			  get_contents getContents)
{
  TextEditor textEditorImpl = (TextEditor) calloc(1, sizeof(struct _TextEditor));

  assert(hiveClosed != NULL);
  assert(clearFocus != NULL);
  assert(moveToFront != NULL);
  assert(rereadContents != NULL);
  assert(displayMessage != NULL);
  assert(setCursorAtLocation != NULL);
  assert(setCursorAtFocus != NULL);
  assert(setActions != NULL);
  assert(setFocus != NULL);
  assert(getContents != NULL);

  textEditorImpl->hiveClosed = hiveClosed;
  textEditorImpl->clearFocus = clearFocus;
  textEditorImpl->moveToFront = moveToFront;
  textEditorImpl->rereadContents = rereadContents;
  textEditorImpl->displayMessage = displayMessage;
  textEditorImpl->setCursorAtLocation = setCursorAtLocation;
  textEditorImpl->setCursorAtFocus = setCursorAtFocus;
  textEditorImpl->setActions = setActions;
  textEditorImpl->setFocus = setFocus;
  textEditorImpl->getContents = getContents;

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
