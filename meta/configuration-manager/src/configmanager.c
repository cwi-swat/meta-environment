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
#define INITIAL_TABLE_SIZE 100
#define TABLE_RESIZE_PERCENTAGE 75

/*}}}  */
/*{{{  variables */

static char myversion[] = "5.0";     

static ATermTable userDescriptionsByType = NULL;
static ATermTable systemDescriptionsByType = NULL;

static ATermTable userActionsByDescription = NULL;
static ATermTable systemActionsByDescription = NULL;

static ATermList userExtensions = NULL;
static ATermList systemExtensions = NULL;

static ATermList modulePaths = NULL;

/*}}}  */

/*{{{  static void addDescription(ATermTable table, MC_ActionDescription desc) */

static void addDescription(ATermTable table, MC_ActionDescription desc)
{
  ATerm type;
  ATermList list;

  type = MC_ActionTypeToTerm(MC_getActionDescriptionType(desc));

  list = (ATermList) ATtableGet(table, type);
  if (list == NULL) {
    list = ATempty;
  }
  list = ATinsert(list, MC_ActionDescriptionToTerm(desc));

  ATtablePut(table, type, (ATerm) list);
}

/*}}}  */
/*{{{  static MC_ActionDescriptionList getDescriptions(MC_ActionType type) */

static MC_ActionDescriptionList getDescriptions(MC_ActionType type)
{
  MC_ActionDescriptionList result;
  MC_ActionDescriptionList list;
  ATerm key;
  ATerm value;

  key = MC_ActionTypeToTerm(type);
  result = MC_makeActionDescriptionListEmpty();

  value = ATtableGet(userDescriptionsByType, key);
  if (value != NULL) {
    list = MC_ActionDescriptionListFromTerm(value);
    result = MC_concatActionDescriptionList(result, list);
  }

  value = ATtableGet(systemDescriptionsByType, key);
  if (value != NULL) {
    list = MC_ActionDescriptionListFromTerm(value);
    result = MC_concatActionDescriptionList(result, list);
  }

  return result;
}

/*}}}  */

/*{{{  static void setActions(ATermTable table, MC_ActionDescription desc, ATermList actions) */

static void setActions(ATermTable table, MC_ActionDescription desc, ATermList actions)
{
  ATerm key = MC_ActionDescriptionToTerm(desc);
  ATtablePut(table, key, (ATerm) actions);
}

/*}}}  */
/*{{{  static ATermList getActions(MC_ActionDescription desc) */

static ATermList getActions(MC_ActionDescription desc)
{
  ATerm key;
  ATermList value;

  key = MC_ActionDescriptionToTerm(desc);
  value = (ATermList) ATtableGet(userActionsByDescription, key);
  if (value == NULL) {
    value = (ATermList) ATtableGet(systemActionsByDescription, key);
  }

  return value;
}

/*}}}  */

/*{{{  void rec_terminate(int cid, ATerm t) */

void rec_terminate(int cid, ATerm t)
{
  exit(0);
}

/*}}}  */

/*{{{  ATerm parse_config_file(int cid, const char *contents) */

ATerm parse_config_file(int cid, const char *contents)
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
  modulePaths = (ATermList) paths;
}

/*}}}  */

/*{{{  static void addExtension(ATermList extensions, MC_Property property) */

static void addExtension(ATermList extensions, MC_Property property)
{
  extensions = ATinsert(extensions, MC_PropertyToTerm(property));
}

/*}}}  */

/*{{{  static void addSystemProperty(MC_Property property) */

static void addSystemProperty(MC_Property property)
{
  if (MC_isPropertyExtension(property)) {
    addExtension(systemExtensions, property);
  }
  else if (MC_isPropertyModulePath(property)) {
    const char *path = MC_getPropertyName(property);
    modulePaths = ATinsert(modulePaths, ATmake("<str>", path));
  }
  else if (MC_isPropertyAction(property)) {
    ATermList actions = (ATermList) MC_getPropertyActions(property);
    MC_ActionDescriptionList list = MC_getPropertyDescriptions(property);
    while (!MC_isActionDescriptionListEmpty(list)) {
      MC_ActionDescription cur = MC_getActionDescriptionListHead(list);
      addDescription(systemDescriptionsByType, cur);
      setActions(systemActionsByDescription, cur, actions);
      list = MC_getActionDescriptionListTail(list);
    }
  }
  else {
    ATabort(__FILE__ ":addSystemProperty: unhandled property: %t\n", property);
  }
}

/*}}}  */
/*{{{  void add_system_properties(int cid, const char *contents) */

void add_system_properties(int cid, const char *contents)
{
  ATerm actions = ATreadFromString(contents);

  if (actions != NULL) {
    MC_Configuration configuration = MC_ConfigurationFromTerm(actions);
    if (MC_isValidConfiguration(configuration)) {
      MC_Properties properties = MC_getConfigurationList(configuration);
      while (!MC_isPropertiesEmpty(properties)) {
	MC_Property property = MC_getPropertiesHead(properties);
	addSystemProperty(property);
	properties = MC_getPropertiesTail(properties);
      }
    }
  }
  else {
    ATwarning("%s:add_system_properties: parse error in input.\n", __FILE__);
  }
}

/*}}}  */

/*{{{  static void addUserProperty(MC_Property property) */

static void addUserProperty(MC_Property property)
{
  if (MC_isPropertyExtension(property)) {
    addExtension(userExtensions, property);
  }
  else if (MC_isPropertyAction(property)) {
    ATermList actions = (ATermList) MC_getPropertyActions(property);
    MC_ActionDescriptionList list = MC_getPropertyDescriptions(property);
    while (!MC_isActionDescriptionListEmpty(list)) {
      MC_ActionDescription cur = MC_getActionDescriptionListHead(list);
      addDescription(userDescriptionsByType, cur);
      setActions(userActionsByDescription, cur, actions);
      list = MC_getActionDescriptionListTail(list);
    }
  }
  else {
    ATabort(__FILE__ ":addUserProperty: unhandled property: %t\n", property);
  }
}

/*}}}  */
/*{{{  void add_user_properties(int cid, const char *contents) */

void add_user_properties(int cid, const char *contents)
{
  ATerm actions = ATreadFromString(contents);

  if (actions != NULL) {
    MC_Configuration configuration = MC_ConfigurationFromTerm(actions);
    if (MC_isValidConfiguration(configuration)) {
      MC_Properties properties = MC_getConfigurationList(configuration);
      while (!MC_isPropertiesEmpty(properties)) {
	MC_Property property = MC_getPropertiesHead(properties);
	addUserProperty(property);
	properties = MC_getPropertiesTail(properties);
      }
    }
  }
  else {
    ATwarning("%s:set_user_properties: parse error in input.\n", __FILE__);
  }
}

/*}}}  */
/*{{{  void remove_user_properties(int cid) */

void remove_user_properties(int cid)
{
  ATtableReset(userDescriptionsByType);
  ATtableReset(userActionsByDescription);
  modulePaths = (ATermList) ATparse("[\".\"]");
}

/*}}}  */

/*{{{  ATerm get_events(int cid, ATerm type) */

ATerm get_events(int cid, ATerm actionType)
{
  ATermList result = ATempty;
  MC_ActionType type = MC_ActionTypeFromTerm(actionType);
  MC_ActionDescriptionList list = getDescriptions(type);

  if (list != NULL) {
    while (!MC_isActionDescriptionListEmpty(list)) {
      MC_ActionDescription cur = MC_getActionDescriptionListHead(list);
      MC_Event event = MC_getActionDescriptionEvent(cur);
      result = ATinsert(result, MC_EventToTerm(event));
      list = MC_getActionDescriptionListTail(list);
    }
  }

  return ATmake("snd-value(events(<term>))", result);
}

/*}}}  */
/*{{{  ATerm get_module_events(int cid, ATerm type, const char *moduleId) */

ATerm get_module_events(int cid, ATerm type, const char *moduleId)
{
  ATerm boundType;

  boundType = ATmake("<term>(<str>)", type, moduleId);

  return get_events(cid, boundType);
}

/*}}}  */

/*{{{  ATerm get_actions(int cid, ATerm type, ATerm event) */

ATerm get_actions(int cid, ATerm type, ATerm event)
{
  MC_ActionDescription desc;
  ATermList actions;

  desc = MC_makeActionDescriptionDefault(MC_ActionTypeFromTerm(type),
					 MC_EventFromTerm(event));
  actions = getActions(desc);

  if (actions == NULL) {
    ATabort("%s:get_actions: no actions for: %t, %t\n", __FILE__, type, event);
  }

  return ATmake("snd-value(actions(<term>))", actions);
}

/*}}}  */
/*{{{  ATerm get_module_actions(int cid, ATerm type, ATerm event, const char *moduleId) */

ATerm get_module_actions(int cid, ATerm type, ATerm event, const char *moduleId)
{
  ATerm boundType;

  boundType = ATmake("<term>(<str>)", type, moduleId);

  return get_actions(cid, boundType, event);
}

/*}}}  */

/*{{{  static ATermList getExtensions() */

static ATermList getExtensions()
{
  return ATconcat(userExtensions, systemExtensions);
}

/*}}}  */
/*{{{  ATerm get_extension_modulename(int cid, const char *extension) */

ATerm get_extension_modulename(int cid, const char *extension)
{
  ATermList extensions = getExtensions();
  
  while (!ATisEmpty(extensions)) {
    MC_Property property = MC_PropertyFromTerm((ATgetFirst(extensions)));

    if (MC_isPropertyExtension(property)) {
      const char *language = MC_getPropertyLanguage(property);
      const char *stored = MC_getPropertyExtension(property);

      if (strcmp(extension, stored) == 0) {
	return ATmake("snd-value(extension-modulename(<str>))", language);
      }
    }

    extensions = ATgetNext(extensions);
  }

  return ATmake("snd-value(no-modulename)");
}

/*}}}  */
/*{{{  ATerm get_modulename_extension(int cid, const char *modulename) */

ATerm get_modulename_extension(int cid, const char *modulename)
{
  ATermList extensions = getExtensions();

  while (!ATisEmpty(extensions)) {
    MC_Property property = MC_PropertyFromTerm((ATgetFirst(extensions)));

    if (MC_isPropertyExtension(property)) {
      char *language = MC_getPropertyLanguage(property);
      char *extension = MC_getPropertyExtension(property);

      if (strcmp(language, modulename) == 0) {
	return ATmake("snd-value(modulename-extension(<str>))", extension);
      }
    }

    extensions = ATgetNext(extensions);
  }

  return ATmake("snd-value(no-extension)");
}

/*}}}  */

/*{{{  ATerm get_module_paths(int cid) */

ATerm get_module_paths(int cid)
{
  return ATmake("snd-value(module-paths(<term>))", modulePaths);
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

/*{{{  static void initConfigurationManager(void) */

static void initConfigurationManager(void)
{
  ATprotectList(&modulePaths);
  modulePaths = (ATermList) ATparse("[\".\"]");

  ATprotectList(&userExtensions);
  userExtensions = ATempty;

  ATprotectList(&systemExtensions);
  systemExtensions = ATempty;

  userDescriptionsByType = ATtableCreate(INITIAL_TABLE_SIZE,
					 TABLE_RESIZE_PERCENTAGE);
  systemDescriptionsByType = ATtableCreate(INITIAL_TABLE_SIZE,
					   TABLE_RESIZE_PERCENTAGE);

  userActionsByDescription = ATtableCreate(INITIAL_TABLE_SIZE,
					   TABLE_RESIZE_PERCENTAGE);
  systemActionsByDescription = ATtableCreate(INITIAL_TABLE_SIZE,
					     TABLE_RESIZE_PERCENTAGE);
}

/*}}}  */
/*{{{  int main(int argc, char *argv[]) */

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

  ATBinit(argc, argv, &bottomOfStack);
  MC_initMetaConfigApi();
  initConfigurationManager();
  /*ATsetChecking(ATtrue);*/

  cid = ATBconnect(NULL, NULL, -1, configuration_manager_handler);

  ATBeventloop();

  return 0;
}         

/*}}}  */
