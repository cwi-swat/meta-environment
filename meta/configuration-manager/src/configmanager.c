/* $Id$ */   

/*{{{  includes */

#include "configuration-manager.tif.h"
#include <ctype.h>
#include "MetaConfig.h"
#include <unistd.h> 
#include <assert.h>

/*}}}  */
/*{{{  defines */

#define MAX_MESSAGE_LENGTH 133

/*}}}  */
/*{{{  globals */

static char myversion[] = "4.0";     
static MC_Properties properties = NULL;
static MC_Properties standardProperties = NULL;
static ATermList userSearchPaths = NULL;
static ATerm librarySearchPath = NULL;

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
/*{{{  void set_actions(int cid, char *contents) */

void set_actions(int cid, char *contents)
{
  ATerm atButtons = ATreadFromString(contents);
  properties = MC_makePropertiesEmpty();

  if (MC_isValidConfiguration(MC_ConfigurationFromTerm(atButtons))) {
    properties = MC_getConfigurationList(MC_ConfigurationFromTerm(atButtons));
  }
}

/*}}}  */
/*{{{  void remove_actions(int cid) */

void remove_actions(int cid)
{
  properties = MC_makePropertiesEmpty();
}

/*}}}  */
/*{{{  void add_predefined_actions(int cid, char *contents) */

void add_predefined_actions(int cid, char *contents)
{
  ATerm actions = ATreadFromString(contents);

  if (MC_isValidConfiguration(MC_ConfigurationFromTerm(actions))) {
    MC_Properties newActions = MC_getConfigurationList(MC_ConfigurationFromTerm(actions));
    standardProperties = MC_concatProperties(newActions, standardProperties);
  }
}

/*}}}  */

/*{{{  static MC_Properties getProperties() */

static MC_Properties getProperties()
{
  return MC_concatProperties(standardProperties, properties);
}

/*}}}  */
/*{{{  static ATbool moduleNameMatches(const char *suspect, const char *peer) */

static ATbool moduleNameMatches(const char *suspect, const char *peer)
{
  return !strcmp(suspect, peer) || !strcmp(suspect, "*");
}

/*}}}  */
/*{{{  static ATbool typeMatches(MC_ButtonType suspect, MC_ButtonType peer) */

static ATbool typeMatches(MC_ButtonType suspect, MC_ButtonType peer)
{
  return MC_isEqualButtonType(suspect, peer)
    || MC_isButtonTypeWildcard(suspect);
}

/*}}}  */

/*{{{  static ATermList getButtonArgs(MC_Property button, MC_ButtonType requestedType) */

static ATermList getButtonArgs(MC_Property button, MC_ButtonType requestedType)
{
  ATermList events = ATempty;
  MC_ButtonDescriptionList descriptions;

  descriptions = MC_getPropertyDescriptions(button);
  assert(MC_isValidButtonDescriptionList(descriptions));

  while (!MC_isButtonDescriptionListEmpty(descriptions)) {
    MC_ButtonDescription desc = MC_getButtonDescriptionListHead(descriptions);
    MC_ButtonType type = MC_getButtonDescriptionType(desc);

    assert(MC_isValidButtonType(type));

    if (typeMatches(type, requestedType)) {
      MC_ButtonArgs args = MC_getButtonDescriptionArgs(desc);
      if (!MC_isValidButtonArgs(args)) {
	ATerror("configmanager.c:getButtonArgs: illegal args: %t\n", args);
      }
      events = ATinsert(events, MC_ButtonArgsToTerm(args));
    }

    descriptions = MC_getButtonDescriptionListTail(descriptions);
  }

  return events;
}

/*}}}  */
/*{{{  static ATbool buttonContainsDescription(MC_Property button, MC_ButtonDescription desc) */

static ATbool buttonContainsDescription(MC_Property button,
					MC_ButtonType type,
					MC_ButtonArgs args)
{
  MC_ButtonDescriptionList descriptions;

  descriptions = MC_getPropertyDescriptions(button);
  assert(MC_isValidButtonDescriptionList(descriptions));

  while (!MC_isButtonDescriptionListEmpty(descriptions)) {
    MC_ButtonDescription cur = MC_getButtonDescriptionListHead(descriptions);
    MC_ButtonType curType = MC_getButtonDescriptionType(cur);
    MC_ButtonArgs curArgs = MC_getButtonDescriptionArgs(cur);

    assert(MC_isValidButtonType(curType));

    if (typeMatches(curType, type) && MC_isEqualButtonArgs(curArgs, args)) {
      return ATtrue;
    }

    descriptions = MC_getButtonDescriptionListTail(descriptions);
  }

  return ATfalse;
}

/*}}}  */

/*{{{  ATerm get_button_names(int cid, char *modulename, ATerm requestedType) */

ATerm get_button_names(int cid, char *modulename, ATerm requestedType)
{
  MC_Properties buttonList = getProperties();
  ATermList events = ATempty;

  while (!ATisEmpty(buttonList)) {
    MC_Property button = MC_getPropertiesHead(buttonList);

    if (MC_isPropertyButton(button)) {
      char *buttonModule = MC_getPropertyModule(button);

      if (moduleNameMatches(buttonModule, modulename)) {
	MC_ButtonType requestedButtonType = MC_ButtonTypeFromTerm(requestedType);
	events = ATconcat(events, getButtonArgs(button, requestedButtonType));
      }
    }
    buttonList = MC_getPropertiesTail(buttonList);
  }

  return ATmake("snd-value(button-names(<term>))", events);
}

/*}}}  */
/*{{{  ATerm get_button_actions(int cid, char *modulename, ATerm requestedType, ATerm requestedArgs) */

ATerm get_button_actions(int cid, char *modulename, ATerm type, ATerm args)
{
  MC_Properties buttonList = getProperties();
  ATerm actions = NULL;

  while (!ATisEmpty(buttonList)) {
    MC_Property button = MC_getPropertiesHead(buttonList);

    if (MC_isPropertyButton(button)) {
      char *buttonModule = MC_getPropertyModule(button);

      if (moduleNameMatches(buttonModule, modulename)) {
	MC_ButtonType curType = MC_ButtonTypeFromTerm(type);
	MC_ButtonArgs curArgs = MC_ButtonArgsFromTerm(args);
	if (buttonContainsDescription(button, curType, curArgs)) {
	  actions = MC_getPropertyActions(button);
	  break;
	}
      }
    }
    buttonList = MC_getPropertiesTail(buttonList);
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
/*{{{  ATerm get_extensions(int cid) */

ATerm get_extensions(int cid)
{
  MC_Properties properties = getProperties();
  ATermList extensions = ATempty;

  while (!MC_isPropertiesEmpty(properties)) {
    MC_Property property = MC_getPropertiesHead(properties);

    if (MC_isPropertyExtension(property)) {
      char *language = MC_getPropertyLanguage(property);
      char *extension = MC_getPropertyExtension(property);
      ATerm lang = (ATerm) ATmakeAppl(ATmakeAFun(language, 0, ATtrue));
      ATerm ext = (ATerm) ATmakeAppl(ATmakeAFun(extension, 0, ATtrue));
      extensions = ATinsert(extensions, (ATerm) ATmakeList2(lang, ext));
    }
    properties = MC_getPropertiesTail(properties);
  }

  return ATmake("snd-value(extensions(<term>))", extensions);
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
  MC_initMetaConfigApi();

  ATprotect((ATerm*) &properties);
  ATprotect((ATerm*) &standardProperties);
  ATprotect((ATerm*) &userSearchPaths);
  ATprotect(&librarySearchPath);

  properties = MC_makePropertiesEmpty();
  standard = ATreadFromNamedFile(STANDARD_META_BUTTONS);

  if (standard != NULL) {
    if (MC_isValidConfiguration(MC_ConfigurationFromTerm(standard))) {
      standardProperties = MC_getConfigurationList(MC_ConfigurationFromTerm(standard));
    }
  }
  else {
    ATwarning("Could not read: " STANDARD_META_BUTTONS "\n");
  }

  cid = ATBconnect(NULL, NULL, -1, configuration_manager_handler);

  ATBeventloop();

  return 0;
}         

/*}}}  */
