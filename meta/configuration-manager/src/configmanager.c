/*
   $Id$
   */   

#include "configmanager.h"
#include "MetaButtons.h"
#include <unistd.h> 
#include <assert.h>

#define MAX_MESSAGE_LENGTH 133

static char myversion[] = "3.0";     
static MB_ButtonList buttons = NULL;
static MB_ButtonList standardButtons = NULL;
static ATermList userSearchPaths = NULL;
static ATerm librarySearchPath = NULL;

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
/*{{{  ATerm get_button_names(int cid, char *editortype, char *modulename) */

ATerm get_button_names(int cid, char *editortype, char *modulename)
{
  MB_ButtonList localButtons = MB_concatButtonList(buttons,standardButtons);
  ATermList buttonNames = ATempty;
  MB_EditorType editorType = 
    MB_EditorTypeFromTerm(ATmake("<str>",editortype));

  while (!ATisEmpty(localButtons)) {
    MB_Button buttonDesc = MB_getButtonListHead(localButtons);
    char* buttonDescModule = MB_getButtonModule(buttonDesc);
    MB_EditorTypes buttonDescTypes = 
      MB_getButtonList(buttonDesc);
    ATerm buttonDescName = MB_getButtonName(buttonDesc);

    assert(MB_isValidEditorTypes(buttonDescTypes));

    if (!strcmp(buttonDescModule, modulename) 
	|| !strcmp(buttonDescModule, "*")) {
      while (!ATisEmpty(buttonDescTypes)) {
        MB_EditorType buttonDescType = 
	  MB_getEditorTypesHead(buttonDescTypes);

        if (ATisEqual(buttonDescType, editorType) 
	    || MB_isEditorTypeAll(buttonDescType)) {
	  buttonNames = ATinsert(buttonNames,buttonDescName);
        }
	buttonDescTypes = 
	  MB_getEditorTypesTail(buttonDescTypes);
      }
    }
    localButtons = MB_getButtonListTail(localButtons);
  }

  return ATmake("snd-value(button-names(<term>))", buttonNames);
}

/*}}}  */
/*{{{  ATerm get_button_actions(int cid, ATerm buttonName, char *editortype,  */

ATerm get_button_actions(int cid, ATerm buttonName, char *editortype, 
			 char *modulename)
{
  char message[MAX_MESSAGE_LENGTH] = "undefined button: ";
  MB_ButtonList localButtons = MB_concatButtonList(buttons,standardButtons);
  MB_EditorType editorType = 
    MB_EditorTypeFromTerm(ATmake("<str>",editortype));
  ATermList buttonActions;
  
  strncat(message, ATwriteToString(buttonName), 
          MAX_MESSAGE_LENGTH - strlen(message));

  buttonActions = (ATermList) ATmake("[message(<str>)]", message);

  while (!ATisEmpty(localButtons)) {
    MB_Button buttonDesc = MB_getButtonListHead(localButtons);
    char* buttonDescModule = MB_getButtonModule(buttonDesc);
    ATerm buttonDescName = MB_getButtonName(buttonDesc);
    MB_EditorTypes buttonDescTypes = MB_getButtonList(buttonDesc);
    ATerm buttonDescActions = MB_getButtonActions(buttonDesc);

    assert(MB_isValidEditorTypes(buttonDescTypes));

    if (!strcmp(buttonDescModule, modulename) 
	|| !strcmp(buttonDescModule, "*")) {
      while (!ATisEmpty(buttonDescTypes)) {
        MB_EditorType buttonDescType = 
	  MB_getEditorTypesHead(buttonDescTypes);

        if (MB_isEqualEditorType(buttonDescType, editorType) 
	    || MB_isEditorTypeAll(buttonDescType)) {
	  if (ATisEqual(buttonDescName, buttonName)) {
	    buttonActions = (ATermList) buttonDescActions;
	  }
        }
	buttonDescTypes = 
	  MB_getEditorTypesTail(buttonDescTypes);
      }
    }
    localButtons = MB_getButtonListTail(localButtons);
  }

  return ATmake("snd-value(button-actions(<term>))", buttonActions);
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
    ATwarning("Could not read in: " STANDARD_BUTTONS "\n");
  }

  cid = ATBconnect(NULL, NULL, -1, configmanager_handler);

  ATBeventloop();

  return 0;
}         

/*}}}  */
