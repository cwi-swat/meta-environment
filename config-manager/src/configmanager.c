/* $Id$ */   

#include "configuration-manager.tif.h"
#include <ctype.h>
#include "Config.h"
#include <unistd.h> 
#include <assert.h>

#define MAX_MESSAGE_LENGTH 133
#define INITIAL_TABLE_SIZE 100
#define TABLE_RESIZE_PERCENTAGE 75
#define MAX_PATH_LENGTH 1024

static char myversion[] = "5.0";     
static char myargs[] = "Isi:";

static ATermTable userDescriptionsByType = NULL;
static ATermTable systemDescriptionsByType = NULL;

static ATermTable userActionsByDescription = NULL;
static ATermTable systemActionsByDescription = NULL;

static ATermList userExtensions = NULL;
static ATermList systemExtensions = NULL;

static ATermList userTextCategories = NULL;
static ATermList systemTextCategories = NULL;

static CFG_PropertyList modulePaths = NULL;
static CFG_PropertyList libraryPaths = NULL;

static CFG_PropertyList scripts = NULL;
static CFG_PropertyList scriptPaths = NULL;

static void add_configuration_properties(ATerm actions);

static void addDescription(ATermTable table, CFG_ActionDescription desc) {
  ATerm type;
  ATermList list;

  type = CFG_getActionDescriptionContext(desc);

  list = (ATermList) ATtableGet(table, type);
  if (list == NULL) {
    list = ATempty;
  }
  list = ATinsert(list, CFG_ActionDescriptionToTerm(desc));

  ATtablePut(table, type, (ATerm) list);
}

static CFG_ActionDescriptionList getDescriptions(ATerm key) {
  CFG_ActionDescriptionList result;
  CFG_ActionDescriptionList list;
  ATerm value;

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

static void setAction(ATermTable table, CFG_ActionDescription desc, const char *action) {
  ATerm key = CFG_ActionDescriptionToTerm(desc);
  ATtablePut(table, key, (ATerm) ATmakeAppl0(ATmakeAFun(action, 0, ATtrue)));
}

static ATermList getActions(CFG_ActionDescription desc) {
  ATerm key;
  ATermList value;

  key = CFG_ActionDescriptionToTerm(desc);
  value = (ATermList) ATtableGet(userActionsByDescription, key);
  if (value == NULL) {
    value = (ATermList) ATtableGet(systemActionsByDescription, key);
  }

  return value;
}

void rec_terminate(int cid, ATerm t) {
  exit(0);
}

ATerm parse_config_file(int cid, const char *contents) {
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

void register_user_directories(int cid, ATerm paths) {
  modulePaths = CFG_makePropertyListEmpty();
}

static ATermList addExtension(ATermList extensions, CFG_Property property) {
  return ATinsert(extensions, CFG_PropertyToTerm(property));
}

static ATermList addTextCategory(ATermList categories, CFG_Property property) {
  return ATinsert(categories, CFG_PropertyToTerm(property));
}

static void addSystemProperty(CFG_Property property) {
  if (CFG_isPropertyImport(property)) {
    char *path = CFG_getPropertyPath(property);
    ATerm import_contents = ATreadFromNamedFile(path);

    if (import_contents != NULL) {
      add_configuration_properties(import_contents);
    }
    else {
      ATwarning("Configuration file %s not used.\n", path);
    }
  }
  else if (CFG_isPropertyExtension(property)) {
    systemExtensions = addExtension(systemExtensions, property);
  }
  else if (CFG_isPropertyScript(property)) {
    scripts = CFG_makePropertyListMany(property, scripts);
  }
  else if (CFG_isPropertyScriptPath(property)) {
    scriptPaths = CFG_makePropertyListMany(property, scriptPaths);
  }
  else if (CFG_isPropertyModulePath(property)) {
    modulePaths = CFG_makePropertyListMany(property, modulePaths);
  }
  else if (CFG_isPropertyLibraryPath(property)) {
    libraryPaths = CFG_makePropertyListMany(property, libraryPaths);
  }
  else if (CFG_isPropertyAction(property)) {
    const char *action = CFG_getPropertyAction(property);
    CFG_ActionDescriptionList list = CFG_getPropertyList(property);
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

static void add_configuration_properties(ATerm actions) {
  CFG_Configuration configuration = CFG_ConfigurationFromTerm(actions);
  if (CFG_isValidConfiguration(configuration)) {
    CFG_PropertyList properties = CFG_getConfigurationList(configuration);
    while (!CFG_isPropertyListEmpty(properties)) {
      CFG_Property property = CFG_getPropertyListHead(properties);
      addSystemProperty(property);
      properties = CFG_getPropertyListTail(properties);
    }
    modulePaths = CFG_reversePropertyList(modulePaths);
    libraryPaths = CFG_reversePropertyList(libraryPaths);
  }
}

void add_system_properties(int cid, const char *contents) {
  ATerm actions = ATreadFromString(contents);

  if (actions != NULL) {
    add_configuration_properties(actions);
  }
  else {
    ATwarning("%s:add_system_properties: parse error in input.\n", __FILE__);
  }
}

static void addUserProperty(CFG_Property property) {
  if (CFG_isPropertyExtension(property)) {
    userExtensions = addExtension(userExtensions, property);
  }
  else if (CFG_isPropertyImport(property)) {
    char *path = CFG_getPropertyPath(property);
    ATerm import_contents = ATreadFromNamedFile(path);

    if (import_contents != NULL) {
      add_configuration_properties(import_contents);
    }
    else {
      ATwarning("Could not import properties from: %s\n", path);
    }
  }
  else if (CFG_isPropertyAction(property)) {
    const char *action = CFG_getPropertyAction(property);
    CFG_ActionDescriptionList list = CFG_getPropertyList(property);
    while (!CFG_isActionDescriptionListEmpty(list)) {
      CFG_ActionDescription cur = CFG_getActionDescriptionListHead(list);
      addDescription(userDescriptionsByType, cur);
      setAction(userActionsByDescription, cur, action);
      list = CFG_getActionDescriptionListTail(list);
    }
  }
  else if (CFG_isPropertyScript(property)) {
    scripts = CFG_makePropertyListMany(property, scripts);
  }
  else if (CFG_isPropertyScriptPath(property)) {
    scriptPaths = CFG_makePropertyListMany(property, scriptPaths);
  }
  else if (CFG_isPropertyTextCategory(property)) {
    userTextCategories = addTextCategory(userTextCategories, property);
  }
  else {
    ATwarning(__FILE__ ":addUserProperty: unhandled property: %t\n", property);
  }
}

void add_user_properties(int cid, const char *contents) {
  ATerm actions = ATreadFromString(contents);

  if (actions != NULL) {
    CFG_Configuration configuration = CFG_ConfigurationFromTerm(actions);
    if (CFG_isValidConfiguration(configuration)) {
      CFG_PropertyList properties = CFG_getConfigurationList(configuration);
      while (!CFG_isPropertyListEmpty(properties)) {
	CFG_Property property = CFG_getPropertyListHead(properties);
	addUserProperty(property);
	properties = CFG_getPropertyListTail(properties);
      }
    }
  }
  else {
    ATwarning("%s:set_user_properties: parse error in input.\n", __FILE__);
  }
}

static CFG_Property getWorkspace() {
  char curdir[MAX_PATH_LENGTH];

  if (getcwd(curdir, MAX_PATH_LENGTH) == NULL) {
    ATerror("__FILE__: could not get current working directory");
  }
  else {
    return CFG_makePropertyModulePath("Workspace", curdir);
  }

  return NULL;
}

void remove_user_properties(int cid) {
  ATtableReset(userDescriptionsByType);
  ATtableReset(userActionsByDescription);
  userTextCategories = ATempty;

  modulePaths = CFG_makePropertyListSingle(getWorkspace());
}

static ATermList getEvents(ATerm actionType) {
  ATermList result = ATempty;
  CFG_ActionDescriptionList list = getDescriptions(actionType);

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

ATerm get_events(int cid, ATerm actionType) {
  ATermList result = getEvents(actionType);
  return ATmake("snd-value(events(<term>))", result);
}

ATerm get_module_events(int cid, ATerm type, ATerm moduleId) {
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

static ATermList getEventActions(ATerm type, ATerm event) {
  CFG_ActionDescription desc;
  ATermList actions;

  desc = CFG_makeActionDescriptionDescription(type,
					      CFG_EventFromTerm(event));
  actions = getActions(desc);

  return actions;
}

ATerm get_action(int cid, ATerm type, ATerm event) {
  ATermList actions = getEventActions(type, event);

  if (actions == NULL) {
    ATabort("%s:get_actions: no actions for: %t, %t\n", __FILE__, type, event);
  }

  return ATmake("snd-value(action(<term>))", actions);
}

ATerm get_module_action(int cid, ATerm type, ATerm event, ATerm moduleId) {
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

static ATermList getExtensions() {
  return ATconcat(userExtensions, systemExtensions);
}

ATerm get_extension_modulename(int cid, const char *extension) {
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

ATerm get_modulename_extension(int cid, ATerm moduleId) {
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

void change_workspace(int cid, const char *path) {
  CFG_Property current = getWorkspace();
  CFG_PropertyList updated = CFG_makePropertyListEmpty();

  if (chdir(path) != 0) {
    return;
  }
  
  while (!CFG_isPropertyListEmpty(modulePaths)) {
    CFG_Property property = CFG_getPropertyListHead(modulePaths);
    modulePaths = CFG_getPropertyListTail(modulePaths);

    if (CFG_isEqualProperty(current, property)) {
      property = getWorkspace();
    }

    updated = CFG_makePropertyListMany(property, updated);
  }

  modulePaths = updated;
}

ATerm get_module_paths(int cid) {
  CFG_PropertyList paths = CFG_concatPropertyList(modulePaths, libraryPaths);
  return ATmake("snd-value(module-paths(<term>))", paths);
}

ATerm get_library_paths(int cid) {
  return ATmake("snd-value(library-paths(<term>))", libraryPaths);
}

ATerm get_text_categories(int cid) {
  ATermList all = ATconcat(userTextCategories, systemTextCategories);
  return ATmake("snd-value(text-categories(<term>))", all);
}

void usage(char *prg, ATbool is_err) {
  ATwarning("usage: %s -[Is] -i <config-file>\n"
	    "\t-I print ToolBus include path\n"
	    "\t-s print ToolBus main scripts\n"
	    "\t-i input configuration file [multiple]\n", prg);
  exit(is_err ? 1 : 0);
}

void version(const char *msg) {
  ATwarning("%s v%s\n", msg, myversion);
  exit(1);
}    

static void initConfigurationManager(void) {
  ATprotectList(&modulePaths);
  modulePaths = CFG_makePropertyListSingle(getWorkspace());

  ATprotectList(&libraryPaths);
  libraryPaths = CFG_makePropertyListEmpty();

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

  scripts = CFG_makePropertyListEmpty();
  CFG_protectPropertyList(&scripts);

  scriptPaths = CFG_makePropertyListEmpty();
  CFG_protectPropertyList(&scriptPaths);
}

void printScriptPath() 
{
  CFG_PropertyList runner = scriptPaths;

  for ( ; !CFG_isPropertyListEmpty(runner); runner = CFG_getPropertyListTail(runner)) {
    printf("%s ", CFG_getPropertyPath(CFG_getPropertyListHead(runner)));
  }
}

void printScripts() 
{
  CFG_PropertyList runner = scripts;

  for ( ; !CFG_isPropertyListEmpty(runner); runner = CFG_getPropertyListTail(runner)) {
    printf("%s ", CFG_getPropertyPath(CFG_getPropertyListHead(runner)));
  }
}


int main(int argc, char *argv[]) {
  int i, cid;
  ATerm bottomOfStack;
  ATbool toolbus_tool = ATfalse;


  for (i=1; !toolbus_tool && i<argc; i++) {
    toolbus_tool = !strcmp(argv[i], "-TB_TOOL_NAME");
  }

  ATinit(argc, argv, &bottomOfStack);
  CFG_initConfigApi();
  initConfigurationManager();

  if (toolbus_tool) {
    ATBinit(argc, argv, &bottomOfStack);
    cid = ATBconnect(NULL, NULL, -1, configuration_manager_handler);
    ATBeventloop();
  }
  else {
    ATerm input = NULL;
    ATbool print_script_path = ATfalse;
    ATbool print_scripts = ATfalse;
    int c;

    while ((c = getopt(argc, argv, myargs)) != -1) {
      switch (c) {
	case 'i':
	  input = ATreadFromNamedFile(optarg);
	  if (input != NULL) {
	    add_configuration_properties(input);
	  }
	  else {
	    ATerror("%s: error parsing %s\n", argv[0], optarg);
	    return 1;
	  }
	  break;
	case 'I':
	  print_script_path = ATtrue;
	  break;
	case 's':
	  print_scripts = ATtrue;
	  break;
	default:
	  usage(argv[0], ATtrue);
      }
    }

    if (print_scripts && print_script_path) {
      ATerror("%s: can not have both -s and -I options\n", argv[0]);
      return 1;
    }

    if (print_script_path) {
      printScriptPath();
    }
    else if (print_scripts) {
      printScripts();
    }
  }

  return 0;
}         
