/*
   $Id$
   */   

#include "configmanager.h"
#include <unistd.h> 

static char myversion[] = "1.0";     
static ATermList buttons;

void rec_terminate(int cid, ATerm t)
{
  exit(0);
}

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

ATerm process_button_file(int cid, char *filename, ATerm contents)
{
  ATermList buttonList = ATgetArguments((ATermAppl)contents);

  if (!ATisEmpty(buttonList)) {
    buttons = (ATermList)ATgetFirst(buttonList);
  }
  else {
    buttons = buttonList;
  }
  return ATmake("snd-value(buttons-processed)");
}

ATerm get_button_names(int cid, char *editortype, char *modulename)
{
  ATermList localButtons = buttons;
  ATermList buttonNames = ATempty;

  buttonNames = ATinsert(buttonNames, ATparse("[\"Move\",\"Down\"]"));
  buttonNames = ATinsert(buttonNames, ATparse("[\"Move\",\"Up\"]"));
  buttonNames = ATinsert(buttonNames, ATparse("[\"Move\",\"Right\"]"));
  buttonNames = ATinsert(buttonNames, ATparse("[\"Move\",\"Left\"]"));

  while (!ATisEmpty(localButtons)) {
    ATerm buttonDesc = ATgetFirst(localButtons);
    ATermList buttonArgs = ATgetArguments((ATermAppl)buttonDesc);
    if (ATisEqual(ATgetFirst(buttonArgs), ATmake("<str>",modulename))) {
      buttonArgs = ATgetNext(buttonArgs);
      if (ATisEqual(ATgetFirst(buttonArgs), ATmake("<str>",editortype))) {
	buttonArgs = ATgetNext(buttonArgs);
	buttonNames = ATinsert(buttonNames,ATgetFirst(buttonArgs));
      }
    }
    localButtons = ATgetNext(localButtons);
  }

  if (strcmp(editortype, "term") == 0) {
    buttonNames = ATinsert(buttonNames, ATparse("[\"Actions\",\"ViewTree\"]"));
    buttonNames = ATinsert(buttonNames, ATparse("[\"Actions\",\"Reduce\"]"));
    buttonNames = ATinsert(buttonNames, ATparse("[\"Actions\",\"Parse\"]"));
  }
  if (strcmp(editortype, "equations") == 0 ||
      strcmp(editortype, "syntax") == 0) {
    buttonNames = ATinsert(buttonNames, ATparse("[\"Actions\",\"ViewTree\"]"));
    buttonNames = ATinsert(buttonNames, ATparse("[\"Actions\",\"Parse\"]"));
  }


  return ATmake("snd-value(button-names(<term>))", buttonNames);
}

ATerm get_button_actions(int cid, ATerm buttonName, char *type, char *moduleName)
{
  ATermList localButtons = buttons;
  ATermList buttonActions = ATempty;

  while (!ATisEmpty(localButtons)) {
    ATerm buttonDesc = ATgetFirst(localButtons);
    ATermList buttonArgs = ATgetArguments((ATermAppl)buttonDesc);
    if (ATisEqual(ATgetFirst(buttonArgs), ATmake("<str>", moduleName))) {
      buttonArgs = ATgetNext(buttonArgs);
      buttonArgs = ATgetNext(buttonArgs);
      if (ATisEqual(ATgetFirst(buttonArgs), buttonName)) {
	buttonArgs = ATgetNext(buttonArgs);
	buttonActions = (ATermList)ATgetFirst(buttonArgs);
      }
    }
    localButtons = ATgetNext(localButtons);
  }

  if (ATisEmpty(buttonActions)) {
    if (ATisEqual(buttonName, ATparse("[\"Actions\",\"Parse\"]"))) {
      ATerm action = NULL;

      if (strcmp(type,"equations") == 0) {
	action = ATmake("parse-equations-action(<str>)", moduleName);
      }
      else if (strcmp(type,"syntax") == 0) {
	action = ATmake("parse-syntax-action(<str>)", moduleName);
      }
      else {
	action = ATmake("parse-action(<str>)", moduleName);
      }
      buttonActions = ATinsert(buttonActions,  action);
    }
    else if (ATisEqual(buttonName, ATparse("[\"Actions\",\"Reduce\"]"))) {
      buttonActions = ATinsert(buttonActions, 
			       ATmake("edit-given-filename(<str>)",
				      moduleName));
      buttonActions = ATinsert(buttonActions, 
			       ATmake("push-filename(\"reduct.out\")"));
      buttonActions = ATinsert(buttonActions, 
			       ATmake("reduce(<str>)", moduleName));
      buttonActions = ATinsert(buttonActions, 
			       ATmake("get-root"));
    }
    else if (ATisEqual(buttonName, ATparse("[\"Actions\",\"ViewTree\"]"))) {
      buttonActions = ATinsert(buttonActions,
			       ATmake("show-tree"));
      buttonActions = ATinsert(buttonActions, 
			       ATmake("get-focus"));
    }
    else if (ATisEqual(buttonName, ATparse("[\"Move\",\"Left\"]"))) {
      buttonActions = ATinsert(buttonActions,ATparse("move-left"));
    }
    else if (ATisEqual(buttonName, ATparse("[\"Move\",\"Right\"]"))) {
      buttonActions = ATinsert(buttonActions,ATparse("move-right"));
    }
    else if (ATisEqual(buttonName, ATparse("[\"Move\",\"Up\"]"))) {
      buttonActions = ATinsert(buttonActions,ATparse("move-up"));
    }
    else if (ATisEqual(buttonName, ATparse("[\"Move\",\"Down\"]"))) {
      buttonActions = ATinsert(buttonActions,ATparse("move-down"));
    }
  }
  return ATmake("snd-value(button-actions(<term>))", buttonActions);
}

void usage(char *prg, ATbool is_err)
{
  ATwarning("usage: %s [aterm-options] [toolbus-options]\n", prg);
  ATwarning("use '%s -at-help' to get more options.\n", prg);
  ATwarning("This program can only be used as a ToolBus tool!\n");
  exit(is_err ? 1 : 0);
}

void version(const char *msg)
{
  ATwarning("%s v%s\n", msg, myversion);
  exit(1);
}    

/* Main program */
int main(int argc, char *argv[])
{
  int i, cid;
  ATerm bottomOfStack;

  for (i=1; i<argc; i++) {
    if (strcmp(argv[i], "-h") == 0) {
      usage(argv[0], ATfalse);
    } else if (strcmp(argv[i], "-V") == 0) {
      version(argv[0]);
    }
  }

  ATBinit(argc, argv,&bottomOfStack);

  cid = ATBconnect(NULL, NULL, -1, configmanager_handler);

  ATBeventloop();

  return 0;
}         
