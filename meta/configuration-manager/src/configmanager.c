/* $Id$ */   

/*{{{  includes */

#include "configmanager.h"
#include "MetaButtons.h"
#include <unistd.h> 
#include <assert.h>

/*}}}  */
/*{{{  defines */

#define MAX_MESSAGE_LENGTH 133

/*}}}  */
/*{{{  globals */

static char myversion[] = "3.0";     
static MB_ButtonList buttons = NULL;
static MB_ButtonList standardButtons = NULL;
static ATermList userSearchPaths = NULL;
static ATerm librarySearchPath = NULL;

/*}}}  */

/*{{{  static MB_ButtonList MB_concatButtonList(MB_ButtonList l1, MB_ButtonList l2) */

static MB_ButtonList MB_concatButtonList(MB_ButtonList l1, MB_ButtonList l2)
{
  return (MB_ButtonList) ATconcat((ATermList) l1, (ATermList) l2);
}

/*}}}  */

/*{{{  void rec_terminate(int cid, ATerm t) */

void rec_terminate(int cid, ATerm t)
{
  exit(0);
}

/*}}}  */

/*{{{  ATerm parse_config_file(int cid, const char *contents) */

ATerm parse_config_file(int cid, char *contents)
{
  int i;
  int j = 0;
  int line_number = 0;
  int len = strlen(contents);
  char pathline[len];
  ATermList paths = ATempty;

  for (i = 0; i < len; i++) {
    if (contents[i] == '\n') {
      if (j != 0 && pathline[0] != '#') {
	pathline[j] = '\0';
	while (j > 0 && isspace((int)pathline[j-1])) {
	  pathline[--j] = '\0';
	}
	line_number++;
	j = 0;
	paths = ATinsert(paths, ATmake("<str>", pathline));
      } 
      else {
	j = 0;
      }
    }
    else {
      pathline[j++] =  contents[i];
    }
  }
  if (j != 0 && pathline[0] != '#') {
    pathline[j] = '\0';
    while (j > 0 && isspace((int)pathline[j-1])) {
      pathline[--j] = '\0';
    }
    line_number++;
    j = 0;
    paths = ATinsert(paths, ATmake("<str>", pathline));
  }

  return ATmake("snd-value(directories(<term>))", paths);
}

/*}}}  */
/*{{{  void register_user_directories(int cid, ATerm paths) */

void register_user_directories(int cid, ATerm paths)
{
  userSearchPaths = (ATermList) paths;
}

/*}}}  */
/*{{{  void register_library(int cid, char *path) */

void register_library(int cid, char *path)
{
  librarySearchPath = ATmake("<str>", path);
}

/*}}}  */
/*{{{  ATerm process_button_file(int cid, char *filename, ATerm contents) */

ATerm process_button_file(int cid, char *filename, char *contents)
{
  ATerm atButtons = ATreadFromString(contents);
  buttons = MB_makeButtonListEmpty();

  if (MB_isValidButtons(MB_ButtonsFromTerm(atButtons))) {
    buttons = MB_getButtonsList(MB_ButtonsFromTerm(atButtons));
  }
  
  return ATmake("snd-value(buttons-processed)");
}

/*}}}  */

/*{{{  static MB_ButtonList getButtonList() */

static MB_ButtonList getButtonList()
{
  return MB_concatButtonList(buttons, standardButtons);
}

/*}}}  */
/*{{{  static ATbool moduleNameMatches(const char *suspect, const char *peer) */

static ATbool moduleNameMatches(const char *suspect, const char *peer)
{
  return !strcmp(suspect, peer) || !strcmp(suspect, "*");
}

/*}}}  */
/*{{{  static ATbool typeMatches(MB_ButtonType suspect, MB_ButtonType peer) */

static ATbool typeMatches(MB_ButtonType suspect, MB_ButtonType peer)
{
  return MB_isEqualButtonType(suspect, peer)
    || MB_isButtonTypeWildcard(suspect);
}

/*}}}  */

/*{{{  static ATermList getButtonArgs(MB_Button button, MB_ButtonType requestedType) */

static ATermList getButtonArgs(MB_Button button, MB_ButtonType requestedType)
{
  ATermList events = ATempty;
  MB_ButtonDescriptionList descriptions;

  descriptions = MB_getButtonDescriptions(button);
  assert(MB_isValidButtonDescriptionList(descriptions));

  while (!MB_isButtonDescriptionListEmpty(descriptions)) {
    MB_ButtonDescription desc = MB_getButtonDescriptionListHead(descriptions);
    MB_ButtonType type = MB_getButtonDescriptionType(desc);

    assert(MB_isValidButtonType(type));

    if (typeMatches(type, requestedType)) {
      MB_ButtonArgs args = MB_getButtonDescriptionArgs(desc);
      if (!MB_isValidButtonArgs(args)) {
	ATerror("configmanager.c:getButtonArgs: illegal args: %t\n", args);
      }
      events = ATinsert(events, MB_ButtonArgsToTerm(args));
    }

    descriptions = MB_getButtonDescriptionListTail(descriptions);
  }

  return events;
}

/*}}}  */
/*{{{  static ATbool buttonContainsDescription(MB_Button button, MB_ButtonDescription desc) */

static ATbool buttonContainsDescription(MB_Button button,
					MB_ButtonType type,
					MB_ButtonArgs args)
{
  MB_ButtonDescriptionList descriptions;

  descriptions = MB_getButtonDescriptions(button);
  assert(MB_isValidButtonDescriptionList(descriptions));

  while (!MB_isButtonDescriptionListEmpty(descriptions)) {
    MB_ButtonDescription cur = MB_getButtonDescriptionListHead(descriptions);
    MB_ButtonType curType = MB_getButtonDescriptionType(cur);
    MB_ButtonArgs curArgs = MB_getButtonDescriptionArgs(cur);

    assert(MB_isValidButtonType(curType));

    if (typeMatches(curType, type) && MB_isEqualButtonArgs(curArgs, args)) {
      return ATtrue;
    }

    descriptions = MB_getButtonDescriptionListTail(descriptions);
  }

  return ATfalse;
}

/*}}}  */

/*{{{  ATerm get_button_names(int cid, char *modulename, ATerm requestedType) */

ATerm get_button_names(int cid, char *modulename, ATerm requestedType)
{
  MB_ButtonList buttonList = getButtonList();
  ATermList events = ATempty;

  while (!ATisEmpty(buttonList)) {
    MB_Button button = MB_getButtonListHead(buttonList);
    char *buttonModule = MB_getButtonModule(button);

    if (moduleNameMatches(buttonModule, modulename)) {
      MB_ButtonType requestedButtonType = MB_ButtonTypeFromTerm(requestedType);
      events = ATconcat(events, getButtonArgs(button, requestedButtonType));
    }
    buttonList = MB_getButtonListTail(buttonList);
  }

  return ATmake("snd-value(button-names(<term>))", events);
}

/*}}}  */
/*{{{  ATerm get_button_actions(int cid, char *modulename, ATerm requestedType, ATerm requestedArgs) */

ATerm get_button_actions(int cid, char *modulename, ATerm type, ATerm args)
{
  MB_ButtonList buttonList = getButtonList();
  ATerm actions = NULL;

  while (!ATisEmpty(buttonList)) {
    MB_Button button = MB_getButtonListHead(buttonList);
    char *buttonModule = MB_getButtonModule(button);

    if (moduleNameMatches(buttonModule, modulename)) {
      MB_ButtonType curType = MB_ButtonTypeFromTerm(type);
      MB_ButtonArgs curArgs = MB_ButtonArgsFromTerm(args);
      if (buttonContainsDescription(button, curType, curArgs)) {
	actions = MB_getButtonActions(button);
	break;
      }
    }
    buttonList = MB_getButtonListTail(buttonList);
  }

  if (actions == NULL) {
    char message[MAX_MESSAGE_LENGTH] = "undefined button: ";
    strncat(message, ATwriteToString(args), 
	    MAX_MESSAGE_LENGTH - strlen(message));

    actions = ATmake("[message(<str>)]", message); /* XXX */
  }

  return ATmake("snd-value(button-actions(<term>))", actions);
}

/*}}}  */
/*{{{  ATerm get_search_paths(int cid) */

ATerm get_search_paths(int cid)
{
  ATermList searchPaths = ATappend(userSearchPaths, librarySearchPath);

  return ATmake("snd-value(search-paths(<term>))", searchPaths);
}

/*}}}  */
/*{{{  void usage(char *prg, ATbool is_err) */

void usage(char *prg, ATbool is_err)
{
  ATwarning("usage: %s [aterm-options] [toolbus-options]\n", prg);
  ATwarning("use '%s -at-help' to get more options.\n", prg);
  ATwarning("This program can only be used as a ToolBus tool!\n");
  exit(is_err ? 1 : 0);
}

/*}}}  */
/*{{{  void version(const char *msg) */

void version(const char *msg)
{
  ATwarning("%s v%s\n", msg, myversion);
  exit(1);
}    

/*}}}  */

/*{{{  int main(int argc, char *argv[]) */

int main(int argc, char *argv[])
{
  int i, cid;
  ATerm bottomOfStack;
  ATerm standard = NULL;

  for (i=1; i<argc; i++) {
    if (strcmp(argv[i], "-h") == 0) {
      usage(argv[0], ATfalse);
    } else if (strcmp(argv[i], "-V") == 0) {
      version(argv[0]);
    }
  }

  ATBinit(argc, argv,&bottomOfStack);
  MB_initMetaButtonsApi();

  ATprotect((ATerm*) &buttons);
  ATprotect((ATerm*) &standardButtons);
  ATprotect((ATerm*) &userSearchPaths);
  ATprotect(&librarySearchPath);

  buttons = MB_makeButtonListEmpty();
  standard = ATreadFromNamedFile(STANDARD_BUTTONS);

  if (standard != NULL) {
    if (MB_isValidButtons(MB_ButtonsFromTerm(standard))) {
      standardButtons = MB_getButtonsList(MB_ButtonsFromTerm(standard));
    }
  }
  else {
    ATwarning("Could not read: " STANDARD_BUTTONS "\n");
  }

  cid = ATBconnect(NULL, NULL, -1, configmanager_handler);

  ATBeventloop();

  return 0;
}         

/*}}}  */
