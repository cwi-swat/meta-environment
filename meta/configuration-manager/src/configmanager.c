/*
   $Id$
   */   

#include "configmanager.h"
#include "MetaButtons.h"
#include <unistd.h> 
#include <assert.h>

static char myversion[] = "1.0";     
static MB_ButtonList buttons = NULL;
static MB_ButtonList standard_buttons = NULL;

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

/*{{{  ATerm process_config_file(int cid, char *filename, char *contents) */

ATerm process_config_file(int cid, char *filename, char *contents)
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

  return ATmake("snd-value(search-paths(<term>))", ATreverse(paths));
}

/*}}}  */
/*{{{  ATerm process_button_file(int cid, char *filename, ATerm contents) */

ATerm process_button_file(int cid, char *filename, ATerm contents)
{
  buttons = MB_makeButtonListEmpty();

  if (MB_isValidButtons(MB_ButtonsFromTerm(contents))) {
    buttons = MB_getButtonsList(MB_ButtonsFromTerm(contents));
  }
  
  return ATmake("snd-value(buttons-processed)");
}

/*}}}  */
/*{{{  ATerm get_button_names(int cid, char *editortype, char *modulename) */

ATerm get_button_names(int cid, char *editortype, char *modulename)
{
  MB_ButtonList localButtons = MB_concatButtonList(buttons,standard_buttons);
  ATermList buttonNames = ATempty;
  MB_EditorType editorType = MB_EditorTypeFromTerm(ATmake("<str>",editortype));

  while (!ATisEmpty(localButtons)) {
    MB_Button buttonDesc = MB_getButtonListHead(localButtons);
    char* buttonDescModule = MB_getButtonModule(buttonDesc);
    MB_EditorType buttonDescType = MB_getButtonType(buttonDesc);
    ATerm buttonDescName = MB_getButtonName(buttonDesc);

    if (!strcmp(buttonDescModule, modulename) ||
	!strcmp(buttonDescModule, "*")) {
      if (ATisEqual(buttonDescType, editorType) ||
	  MB_isEditorTypeAll(buttonDescType)) {
	buttonNames = ATinsert(buttonNames,buttonDescName);
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
  MB_ButtonList localButtons = MB_concatButtonList(buttons,standard_buttons);
  MB_EditorType editorType = MB_EditorTypeFromTerm(ATmake("<str>",editortype));
  ATermList buttonActions = (ATermList) ATparse("[message(\"undefined button\")]");

  while (!ATisEmpty(localButtons)) {
    MB_Button buttonDesc = MB_getButtonListHead(localButtons);
    char* buttonDescModule = MB_getButtonModule(buttonDesc);
    ATerm buttonDescName = MB_getButtonName(buttonDesc);
    MB_EditorType buttonDescType = MB_getButtonType(buttonDesc);
    ATerm buttonDescActions = MB_getButtonActions(buttonDesc);

    if (!strcmp(buttonDescModule, modulename) ||
	!strcmp(buttonDescModule, "*")) {
      if (MB_isEqualEditorType(buttonDescType, editorType) ||
	  MB_isEditorTypeAll(buttonDescType)) {
	if (ATisEqual(buttonDescName, buttonName)) {
	  buttonActions = (ATermList) buttonDescActions;
	}
      }
    }
    localButtons = MB_getButtonListTail(localButtons);
  }

  return ATmake("snd-value(button-actions(<term>))", buttonActions);
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
  ATprotect((ATerm*) &standard_buttons);

  buttons = MB_makeButtonListEmpty();
  standard = ATreadFromNamedFile(STANDARD_BUTTONS);

  if (standard != NULL) {
    if (MB_isValidButtons(MB_ButtonsFromTerm(standard))) {
      standard_buttons = MB_getButtonsList(MB_ButtonsFromTerm(standard));
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
