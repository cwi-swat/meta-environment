/*{{{  includes */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <dlfcn.h>
#include <errno.h>
#include <assert.h>

#include <aterm2.h>

#include <TextEditor.h>

#include "editor-hive.tif.h"
#include "editor-hive.h"
#include "external-startup.h"

/*}}}  */
/*{{{  defines */

#define PIPE_READ 0
#define PIPE_WRITE 1

#define DYNAMIC_LIBRARY_NAME "lib_%s.so"
#define STARTUP "startup"

#define INITIAL_SIZE 128
#define LOAD_PERCENTAGE 75

#define EVENT_EDITOR_DISCONNECTED "editor-disconnected(<term>)"
#define EVENT_MENU "menu-event(<term>,<term>)"
#define EVENT_MOUSE "mouse-event(<term>,<int>)"
#define EVENT_CONTENTS "contents(<term>,<str>)"
#define EVENT_CONTENTS_CHANGED "contents-changed(<term>)"

/*}}}  */
/*{{{  variables */

static ATermTable editorsById = NULL;

/*}}}  */

/*{{{  static void executeEditor(library, filename, process) */

static void executeEditor(const char *library,
			  const char *filename,
			  TE_Process process)
{
  int read_from_hive_fd;
  int write_to_hive_fd;
  void *handler;
  external_startup startup;

  read_from_hive_fd = TE_getPipeRead(TE_getProcessToChild(process));
  write_to_hive_fd = TE_getPipeWrite(TE_getProcessFromChild(process));

  handler = dlopen(library, RTLD_NOW);
  if (handler == NULL) {
    fprintf(stderr, "dlopen failed: %s\n", dlerror());
    exit(errno);
  }

  startup = (external_startup) dlsym(handler, STARTUP);

  if (startup != NULL) {
    startup(filename, read_from_hive_fd, write_to_hive_fd);
  }
  else {
    char *error = dlerror();
    if (error != NULL) {
      fprintf(stderr, "%s in %s\n", error, library);
    }
    exit(1);
  }
}

/*}}}  */

/*{{{  static TE_Process createProcess() */

static TE_Process createProcess()
{
  int fds[2];
  TE_Pipe hiveToEditor;
  TE_Pipe editorToHive;

  if (pipe(fds) == -1) {
    perror("pipe:hiveToEditor");
    exit(errno);
  }
  hiveToEditor = TE_makePipeDefault(fds[PIPE_READ], fds[PIPE_WRITE]);

  if (pipe(fds) == -1) {
    perror("pipe:editorToHive");
    exit(errno);
  }
  editorToHive = TE_makePipeDefault(fds[PIPE_READ], fds[PIPE_WRITE]);

  return TE_makeProcessDefault(hiveToEditor, editorToHive);
}

/*}}}  */
/*{{{  static TE_Process startEditor(char *filename) */

static TE_Process startEditor(const char *library, const char *filename)
{
  TE_Process process;
  int pid;

  process = createProcess();

  pid = fork();

  if (pid < 0) {
    perror("fork");
    exit(errno);
  }
  else {
    if (pid == 0) {
      /* child */
      close(TE_getPipeRead(TE_getProcessFromChild(process)));
      close(TE_getPipeWrite(TE_getProcessToChild(process)));

      executeEditor(library, filename, process);
    }
    else {
      /* parent */
      close(TE_getPipeWrite(TE_getProcessFromChild(process)));
      close(TE_getPipeRead(TE_getProcessToChild(process)));
    }
  }

  return process;
}

/*}}}  */
/*{{{  static TE_Process getEditorProcess(ATerm id) */

static TE_Process getEditorProcess(ATerm id)
{
  return TE_ProcessFromTerm(ATtableGet(editorsById, id));
}

/*}}}  */
/*{{{  static void setEditorProcess(ATerm id, TE_Process process) */

static void setEditorProcess(ATerm id, TE_Process process)
{
  assert(ATtableGet(editorsById, id) == NULL);

  ATtablePut(editorsById, id, TE_ProcessToTerm(process));
}

/*}}}  */
/*{{{  static void removeEditorProcess(ATerm id) */

static void removeEditorProcess(ATerm id)
{
  TE_Process process = getEditorProcess(id);

  if (process != NULL) {
    close(TE_getPipeWrite(TE_getProcessToChild(process)));
    close(TE_getPipeRead(TE_getProcessFromChild(process)));
    ATtableRemove(editorsById, id);
  }
}

/*}}}  */
/*{{{  static void sendToEditor(TE_Process process, TE_Action action) */

static void sendToEditor(TE_Process process, TE_Action action)
{
  int fd = TE_getPipeWrite(TE_getProcessToChild(process));
  ATerm term = TE_ActionToTerm(action);

  if (ATBwriteTerm(fd, term)) {
    perror("ATBwriteTerm");
  }
}

/*}}}  */
/*{{{  static void sendToToolBus(int tb_fd, ATerm event) */

static void sendToToolBus(int tb_fd, ATerm event)
{
  ATBpostEvent(tb_fd, event);
}

/*}}}  */

/*{{{  void get_contents(int c, ATerm editorId, ATerm focus) */

void get_contents(int c, ATerm editorId, ATerm focus)
{
  TE_Process process = getEditorProcess(editorId);

  if (process != NULL) {
    sendToEditor(process, TE_makeActionGetContents(focus));
  }
}

/*}}}  */
/*{{{  void clear_focus(int c, ATerm editorId) */

void clear_focus(int c, ATerm editorId)
{
  TE_Process process = getEditorProcess(editorId);

  if (process != NULL) {
    sendToEditor(process, TE_makeActionClearFocus());
  }
}

/*}}}  */
/*{{{  void set_focus(int c, ATerm editorId, ATerm focus) */

void set_focus(int c, ATerm editorId, ATerm focus)
{
  TE_Process process = getEditorProcess(editorId);

  if (process != NULL) {
    sendToEditor(process, TE_makeActionSetFocus(focus));
  }
}

/*}}}  */
/*{{{  void display_message(int c, ATerm editorId, char *message) */

void display_message(int c, ATerm editorId, char *message)
{
  TE_Process process = getEditorProcess(editorId);

  if (process != NULL) {
    sendToEditor(process, TE_makeActionDisplayMessage(message));
  }
}

/*}}}  */
/*{{{  void set_cursor_at_location(int c, ATerm editorId, int location) */

void set_cursor_at_location(int c, ATerm editorId, int location)
{
  TE_Process process = getEditorProcess(editorId);

  if (process != NULL) {
    sendToEditor(process, TE_makeActionSetCursorAtLocation(location));
  }
}

/*}}}  */
/*{{{  void set_cursor_at_focus(int c, ATerm editorId, ATerm focus) */

void set_cursor_at_focus(int c, ATerm editorId, ATerm focus)
{
  TE_Process process = getEditorProcess(editorId);

  if (process != NULL) {
    sendToEditor(process, TE_makeActionSetCursorAtFocus(focus));
  }
}

/*}}}  */
/*{{{  void reread_contents(int c, ATerm editorId) */

void reread_contents(int c, ATerm editorId)
{
  TE_Process process = getEditorProcess(editorId);

  if (process != NULL) {
    sendToEditor(process, TE_makeActionRereadContents());
  }
}

/*}}}  */
/*{{{  void editor_to_front(int c, ATerm editorId) */

void editor_to_front(int c, ATerm editorId)
{
  TE_Process process = getEditorProcess(editorId);

  if (process != NULL) {
    sendToEditor(process, TE_makeActionToFront());
  }
}

/*}}}  */
/*{{{  void set_actions(int c, ATerm editorId, ATerm actions) */

void set_actions(int c, ATerm editorId, ATerm actions)
{
  TE_Process process = getEditorProcess(editorId);

  if (process != NULL) {
    TE_ActionList editActions;
    editActions = TE_ActionListFromTerm(actions);
    sendToEditor(process, TE_makeActionSetActions(editActions));
  }
}

/*}}}  */
/*{{{  void edit_file(int c, ATerm editorId, char *editor, char *filename) */

void edit_file(int c, ATerm editorId, char *editor, char *filename)
{
  char library[BUFSIZ];
  TE_Process process;
  
  sprintf(library, DYNAMIC_LIBRARY_NAME, editor);
  process = getEditorProcess(editorId);

  if (process == NULL) {
    process = startEditor(library, filename);
    setEditorProcess(editorId, process);
  }
  else {
    ATwarning("editor-hive: ignoring illegal attempt to edit_file for %t\n",
	      editorId);
  }
}

/*}}}  */
/*{{{  void kill_editor(int c, ATerm editorId) */

void kill_editor(int c, ATerm editorId)
{
  removeEditorProcess(editorId);
}

/*}}}  */
/*{{{  void rec_ack_event(int c, ATerm event) */

void rec_ack_event(int c, ATerm event)
{
  /*ATwarning("editor-hive: ack-event [%t]\n", event);*/
}

/*}}}  */
/*{{{  void rec_terminate(int c, ATerm message) */

void rec_terminate(int c, ATerm message)
{
  exit(0);
}

/*}}}  */

/*{{{  static void addEditorDescriptors(fd_set *set, int *max_fd) */

static void addEditorDescriptors(fd_set *set, int *max_fd)
{
  ATermList editorIds = ATtableKeys(editorsById);

  while (!ATisEmpty(editorIds)) {
    ATerm id = ATgetFirst(editorIds);
    TE_Process process = getEditorProcess(id);
    int fd = TE_getPipeRead(TE_getProcessFromChild(process));
    FD_SET(fd, set);
    if (fd > *max_fd) {
      *max_fd = fd;
    }
    editorIds = ATgetNext(editorIds);
  }
}

/*}}}  */
/*{{{  static void handleEditorInput(int tb_fd, ATerm editorId, const char *input) */

static void handleEditorInput(int tb_fd, ATerm editorId, TE_Event event)
{
  if (TE_isEventMenu(event)) {
    TE_Menu menu = TE_getEventMenu(event);
    sendToToolBus(tb_fd, ATmake(EVENT_MENU, editorId, menu));
  }
  else if (TE_isEventMouse(event)) {
    int location = TE_getEventLocation(event);
    sendToToolBus(tb_fd, ATmake(EVENT_MOUSE, editorId, location));
  }
  else if (TE_isEventContents(event)) {
    char *contents = TE_getEventText(event);
    sendToToolBus(tb_fd, ATmake(EVENT_CONTENTS, editorId, contents));
  }
  else if (TE_isEventModified(event)) {
    sendToToolBus(tb_fd, ATmake(EVENT_CONTENTS_CHANGED, editorId));
  }
  else {
    ATwarning("editor-hive: ignoring editor input: %t\n", event);
  }
}

/*}}}  */
/*{{{  static void handleEditor(ATerm editorId) */

static void handleEditor(int tb_fd, ATerm editorId)
{
  TE_Process process = getEditorProcess(editorId);
  int fd = TE_getPipeRead(TE_getProcessFromChild(process));
  ATerm t;

  t = ATBreadTerm(fd);
  if (t == NULL) {
    removeEditorProcess(editorId);
    sendToToolBus(tb_fd, ATmake(EVENT_EDITOR_DISCONNECTED, editorId));
  }
  else {
    handleEditorInput(tb_fd, editorId, TE_EventFromTerm(t));
  }
  
}

/*}}}  */
/*{{{  static void inspectEditors(int tb_fd, fd_set *set) */

static void inspectEditors(int tb_fd, fd_set *set)
{
  ATermList editorIds = ATtableKeys(editorsById);

  while (!ATisEmpty(editorIds)) {
    ATerm id = ATgetFirst(editorIds);
    TE_Process process = getEditorProcess(id);
    int fd = TE_getPipeRead(TE_getProcessFromChild(process));
    if (FD_ISSET(fd, set)) {
      handleEditor(tb_fd, id);
    }
    editorIds = ATgetNext(editorIds);
  }
}

/*}}}  */

/*{{{  static int eventloop(int tb_fd) */

static int eventloop(int tb_fd)
{
  fd_set set;
  int max_fd;
  int retval;

  while (ATtrue) {
    FD_ZERO(&set);
    max_fd = 0;

    FD_SET(tb_fd, &set);
    if (tb_fd > max_fd) {
      max_fd = tb_fd;
    }

    addEditorDescriptors(&set, &max_fd);

    retval = select(max_fd+1, &set, NULL, NULL, NULL);
    if (retval == -1) {
      perror("editor-hive:select");
    }

    if (FD_ISSET(tb_fd, &set)) {
      int result = ATBhandleOne(tb_fd);
      if (result == -1) {
	return -1;
      }
    }

    inspectEditors(tb_fd, &set);
  }
}

/*}}}  */

/*{{{  int main(int argc, char *argv[]) */

int main(int argc, char *argv[])
{
  ATerm bottomOfStack;
  int fd;

  ATBinit(argc, argv, &bottomOfStack);
  TE_initTextEditorApi();

  editorsById = ATtableCreate(INITIAL_SIZE, LOAD_PERCENTAGE);

  fd = ATBconnect(NULL, NULL, -1, editor_hive_handler);

  return eventloop(fd);
}

/*}}}  */
