/* $Id$ */   

/*{{{  includes */

#include "configuration-manager.tif.h"
#include <ctype.h>
#include "Config.h"
#include <unistd.h> 
#include <assert.h>

/*}}}  */
/*{{{  defines */

#define MAX_MESSAGE_LENGTH 133
#define INITIAL_TABLE_SIZE 100
#define TABLE_RESIZE_PERCENTAGE 75
#define MAX_PATH_LENGTH 1024

/*}}}  */
/*{{{  variables */

static char myversion[] = "5.0";     

static ATermTable userDescriptionsByType = NULL;
static ATermTable systemDescriptionsByType = NULL;

static ATermTable userActionsByDescription = NULL;
static ATermTable systemActionsByDescription = NULL;

static ATermList userExtensions = NULL;
static ATermList systemExtensions = NULL;

static ATermList userTextCategories = NULL;
static ATermList systemTextCategories = NULL;

static CFG_Properties modulePaths = NULL;
static CFG_Properties libraryPaths = NULL;

/*}}}  */

/*{{{  static void addDescription(ATermTable table, CFG_ActionDescription desc) */

static void addDescription(ATermTable table, CFG_ActionDescription desc)
{
  ATerm type;
  ATermList list;

  type = CFG_ActionTypeToTerm(CFG_getActionDescriptionActionType(desc));

  list = (ATermList) ATtableGet(table, type);
  if (list == NULL) {
    list = ATempty;
  }
  list = ATinsert(list, CFG_ActionDescriptionToTerm(desc));

  ATtablePut(table, type, (ATerm) list);
}

/*}}}  */
/*{{{  static CFG_ActionDescriptionList getDescriptions(CFG_ActionType type) */

static CFG_ActionDescriptionList getDescriptions(CFG_ActionType type)
{
  CFG_ActionDescriptionList result;
  CFG_ActionDescriptionList list;
  ATerm key;
  ATerm value;

  key = CFG_ActionTypeToTerm(type);
  result = CFG_makeActionDescriptionListEmpty();

  value = ATtableGet(userDescriptionsByType, key);
  if (value != NULL) {
    list = CFG_ActionDescriptionListFromTerm(value);
    result = CFG_concatActionDescriptionList(result, list);
  }

  value = ATtableGet(systemDescriptionsByType, key);
  if (value != NULL) {
    list = CFG_ActionDescriptionListFromTerm(value);
    result = CFG_concatActionDescriptionList(result, list);
  }

  return result;
}

/*}}}  */

/*{{{  static void setAction(ATermTable table, CFG_ActionDescription desc, const char *action) */

static void setAction(ATermTable table, CFG_ActionDescription desc, const char *action)
{
  ATerm key = CFG_ActionDescriptionToTerm(desc);
  ATtablePut(table, key, (ATerm) ATmakeAppl0(ATmakeAFun(action, 0, ATtrue)));
}

/*}}}  */
/*{{{  static ATermList getActions(CFG_ActionDescription desc) */

static ATermList getActions(CFG_ActionDescription desc)
{
  ATerm key;
  ATermList value;

  key = CFG_ActionDescriptionToTerm(desc);
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
  modulePaths = CFG_makePropertiesEmpty();
}

/*}}}  */

/*{{{  static void addExtension(ATermList extensions, CFG_Property property) */

static ATermList addExtension(ATermList extensions, CFG_Property property)
{
  return ATinsert(extensions, CFG_PropertyToTerm(property));
}

/*}}}  */
/*{{{  static void addTextCategory(ATermList categories, CFG_Property property) */

static ATermList addTextCategory(ATermList categories, CFG_Property property)
{
  return ATinsert(categories, CFG_PropertyToTerm(property));
}

/*}}}  */

/*{{{  static void addSystemProperty(CFG_Property property) */

static void addSystemProperty(CFG_Property property)
{
  if (CFG_isPropertyExtension(property)) {
    systemExtensions = addExtension(systemExtensions, property);
  }
  else if (CFG_isPropertyModulePath(property)) {
    modulePaths = CFG_makePropertiesMany(property, modulePaths);
  }
  else if (CFG_isPropertyLibraryPath(property)) {
    libraryPaths = CFG_makePropertiesMany(property, libraryPaths);
  }
  else if (CFG_isPropertyAction(property)) {
    const char *action = CFG_getPropertyAction(property);
    CFG_ActionDescriptionList list = CFG_getPropertyDescriptions(property);
    while (!CFG_isActionDescriptionListEmpty(list)) {
      CFG_ActionDescription cur = CFG_getActionDescriptionListHead(list);
      addDescription(systemDescriptionsByType, cur);
      setAction(systemActionsByDescription, cur, action);
      list = CFG_getActionDescriptionListTail(list);
    }
  }
  else if (CFG_isPropertyTextCategory(property)) {
    systemTextCategories = addTextCategory(systemTextCategories, property);
  }
  else {
    ATwarning(__FILE__ ":addSystemProperty: unhandled property: %t\n", property);
  }
}

/*}}}  */

static void add_configuration_properties(ATerm actions) {
  CFG_Configuration configuration = CFG_ConfigurationFromTerm(actions);
  if (CFG_isConfigurationList(configuration)) {
    CFG_Properties properties = CFG_getConfigurationList(configuration);
    while (!CFG_isPropertiesEmpty(properties)) {
      CFG_Property property = CFG_getPropertiesHead(properties);
      addSystemProperty(property);
      properties = CFG_getPropertiesTail(properties);
    }
    modulePaths = CFG_reverseProperties(modulePaths);
    libraryPaths = CFG_reverseProperties(libraryPaths);
  }
  else if (CFG_isConfigurationImport(configuration)) {
    char *path = CFG_getConfigurationPath(configuration);
    ATerm import_contents = ATreadFromNamedFile(path);
    add_configuration_properties(import_contents);
  }
}

/*{{{  void add_system_properties(int cid, const char *contents) */

void add_system_properties(int cid, const char *contents)
{
  ATerm actions = ATreadFromString(contents);

  if (actions != NULL) {
    add_configuration_properties(actions);
  }
  else {
    ATwarning("%s:add_system_properties: parse error in input.\n", __FILE__);
  }
}

/*}}}  */

/*{{{  static void addUserProperty(CFG_Property property) */

static void addUserProperty(CFG_Property property)
{
  if (CFG_isPropertyExtension(property)) {
    userExtensions = addExtension(userExtensions, property);
  }
  else if (CFG_isPropertyAction(property)) {
    const char *action = CFG_getPropertyAction(property);
    CFG_ActionDescriptionList list = CFG_getPropertyDescriptions(property);
    while (!CFG_isActionDescriptionListEmpty(list)) {
      CFG_ActionDescription cur = CFG_getActionDescriptionListHead(list);
      addDescription(userDescriptionsByType, cur);
      setAction(userActionsByDescription, cur, action);
      list = CFG_getActionDescriptionListTail(list);
    }
  }
  else if (CFG_isPropertyTextCategory(property)) {
    userTextCategories = addTextCategory(userTextCategories, property);
  }
  else {
    ATwarning(__FILE__ ":addUserProperty: unhandled property: %t\n", property);
  }
}

/*}}}  */
/*{{{  void add_user_properties(int cid, const char *contents) */

void add_user_properties(int cid, const char *contents)
{
  ATerm actions = ATreadFromString(contents);

  if (actions != NULL) {
    CFG_Configuration configuration = CFG_ConfigurationFromTerm(actions);
    if (CFG_isValidConfiguration(configuration)) {
      CFG_Properties properties = CFG_getConfigurationList(configuration);
      while (!CFG_isPropertiesEmpty(properties)) {
	CFG_Property property = CFG_getPropertiesHead(properties);
	addUserProperty(property);
	properties = CFG_getPropertiesTail(properties);
      }
    }
  }
  else {
    ATwarning("%s:set_user_properties: parse error in input.\n", __FILE__);
  }
}

/*}}}  */

static CFG_Property getWorkspace() {
  char curdir[MAX_PATH_LENGTH];

  if (getcwd(curdir, MAX_PATH_LENGTH) == NULL) {
    ATerror("__FILE__: could not get current working directory");
  }
  else {
    return CFG_makePropertyModulePath("Workspace",curdir);
  }

  return NULL;
}

/*{{{  void remove_user_properties(int cid) */

void remove_user_properties(int cid)
{
  ATtableReset(userDescriptionsByType);
  ATtableReset(userActionsByDescription);
  userTextCategories = ATempty;

  modulePaths = CFG_makePropertiesSingle(getWorkspace());
}

/*}}}  */

/*{{{  static ATermList getEvents(ATerm type) */

static ATermList getEvents(ATerm actionType)
{
  ATermList result = ATempty;
  CFG_ActionType type = CFG_ActionTypeFromTerm(actionType);
  CFG_ActionDescriptionList list = getDescriptions(type);

  if (list != NULL) {
    while (!CFG_isActionDescriptionListEmpty(list)) {
      CFG_ActionDescription cur = CFG_getActionDescriptionListHead(list);
      CFG_Event event = CFG_getActionDescriptionEvent(cur);
      result = ATinsert(result, CFG_EventToTerm(event));
      list = CFG_getActionDescriptionListTail(list);
    }
  }

  return result;
}

/*}}}  */
/*{{{  ATerm get_events(int cid, ATerm type) */

ATerm get_events(int cid, ATerm actionType)
{
  ATermList result = getEvents(actionType);
  return ATmake("snd-value(events(<term>))", result);
}

/*}}}  */
/*{{{  ATerm get_module_events(int cid, ATerm type, ATerm moduleId) */

ATerm get_module_events(int cid, ATerm type, ATerm moduleId)
{
  ATerm boundType;
  ATermList result1, result2;

  char *fun = ATgetName(ATgetAFun((ATermAppl)type));
  boundType = (ATerm)ATmakeAppl1(ATmakeAFun(fun, 1, ATfalse),
                                           ATmake("<str>", 
						  ATwriteToString(moduleId)));

  result1 = getEvents(type);
  result2 = getEvents(boundType);

  return ATmake("snd-value(events(<term>))", ATconcat(result1, result2));
}

/*}}}  */

/*{{{  static ATermList getActions(ATerm type, ATerm event) */

static ATermList getEventActions(ATerm type, ATerm event)
{
  CFG_ActionDescription desc;
  ATermList actions;

  desc = CFG_makeActionDescriptionDefault(CFG_ActionTypeFromTerm(type),
					 CFG_EventFromTerm(event));
  actions = getActions(desc);

  return actions;
}

/*}}}  */
/*{{{  ATerm get_action(int cid, ATerm type, ATerm event) */

ATerm get_action(int cid, ATerm type, ATerm event)
{
  ATermList actions = getEventActions(type, event);

  if (actions == NULL) {
    ATabort("%s:get_actions: no actions for: %t, %t\n", __FILE__, type, event);
  }

  return ATmake("snd-value(action(<term>))", actions);
}

/*}}}  */
/*{{{  ATerm get_module_action(int cid, ATerm type, ATerm event, ATerm moduleId) */

ATerm get_module_action(int cid, ATerm type, ATerm event, ATerm moduleId)
{
  ATerm boundType;
  ATermList actions;

  char *fun = ATgetName(ATgetAFun((ATermAppl)type));
  boundType = (ATerm)ATmakeAppl1(ATmakeAFun(fun, 1, ATfalse),
                                           ATmake("<str>", ATwriteToString(moduleId)));

  actions = getEventActions(boundType, event);
  if (actions == NULL) {
    actions = getEventActions(type, event);
    
    if (actions == NULL) {
      ATabort("%s:get_actions: no actions for: %t, %t\n", __FILE__, type, event);
    }
  }
  return ATmake("snd-value(action(<term>))", actions);
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
    CFG_Property property = CFG_PropertyFromTerm((ATgetFirst(extensions)));

    if (CFG_isPropertyExtension(property)) {
      const char *language = CFG_getPropertyLanguage(property);
      const char *stored = CFG_getPropertyExtension(property);

      if (strcmp(extension, stored) == 0) {
	return ATmake("snd-value(extension-modulename(<str>))", language);
      }
    }

    extensions = ATgetNext(extensions);
  }

  return ATmake("snd-value(no-modulename)");
}

/*}}}  */
/*{{{  ATerm get_modulename_extension(int cid, ATerm moduleId) */

ATerm get_modulename_extension(int cid, ATerm moduleId)
{
  ATermList extensions = getExtensions();

  while (!ATisEmpty(extensions)) {
    CFG_Property property = CFG_PropertyFromTerm((ATgetFirst(extensions)));

    if (CFG_isPropertyExtension(property)) {
      char *language = CFG_getPropertyLanguage(property);
      char *extension = CFG_getPropertyExtension(property);

      if (strcmp(language, ATwriteToString(moduleId)) == 0) {
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
  CFG_Properties paths = CFG_concatProperties(modulePaths, libraryPaths);
  return ATmake("snd-value(module-paths(<term>))", paths);
}

/*}}}  */
/*{{{  ATerm get_library_paths(int cid) */

ATerm get_library_paths(int cid)
{
  return ATmake("snd-value(library-paths(<term>))", libraryPaths);
}

/*}}}  */
/*{{{  ATerm get_text_properties(int cid) */

ATerm get_text_categories(int cid)
{
  ATermList all = ATconcat(userTextCategories, systemTextCategories);
  return ATmake("snd-value(text-categories(<term>))", all);
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
  modulePaths = CFG_makePropertiesSingle(getWorkspace());

  ATprotectList(&libraryPaths);
  libraryPaths = CFG_makePropertiesEmpty();

  ATprotectList(&userExtensions);
  userExtensions = ATempty;

  ATprotectList(&systemExtensions);
  systemExtensions = ATempty;

  ATprotectList(&userTextCategories);
  userTextCategories = ATempty;

  ATprotectList(&systemTextCategories);
  systemTextCategories = ATempty;

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
  CFG_initConfigApi();
  initConfigurationManager();
  /*ATsetChecking(ATtrue);*/

  cid = ATBconnect(NULL, NULL, -1, configuration_manager_handler);

  ATBeventloop();

  return 0;
}         

/*}}}  */
