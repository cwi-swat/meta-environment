/* $Id$ */

#include <stdlib.h>
#include <aterm2.h>
#include <atb-tool.h>
#include <ctype.h>
#include <assert.h>
#include <limits.h>

#include <SDFME-utils.h>
#include "sdf-modules.tif.h"
#include "sdf-imports.h"
#include "plain-imports.h"

#define SEP '/'
#define PATH_LEN (_POSIX_PATH_MAX)

static char myversion[] = "1.0";

/*{{{  void rec_terminate(int cid, ATerm t) */

void rec_terminate(int cid, ATerm t)
{
  exit(0);
}

/*}}}  */
/*{{{  static void usage(char *prg, ATbool is_err) */

static void usage(char *prg, ATbool is_err)
{
    ATwarning("sdf-modules: an interface to the sdf-support library.\n"
	      "This tool can only be executed on the ToolBus platform.\n");
    exit(is_err ? 1 : 0);
}

/*}}}  */
/*{{{  static void version(const char *msg) */

static void version(const char *msg)
{
    ATwarning("%s v%s\n", msg, myversion);
    exit(1);
}

/*}}}  */

/*{{{  ATerm get_all_needed_module_names(int cid, ATerm atModules, char* name)  */

ATerm get_all_needed_module_names(int cid, ATerm pairs, char* name) 
{
  ATerm id = ATmake("<str>", name);
  ATermList imports = PI_getTransitiveImports((ATermList) ATBunpack(pairs), id);
  return ATmake("snd-value(all-needed-module-names(<term>))", imports);
}

/*}}}  */
/*{{{  ATerm get_all_needed_imports(int cid, ATerm atModules, char* name)  */

ATerm get_all_needed_imports(int cid, ATerm atModules, char* name) 
{
  ATermList list = (ATermList) ATBunpack(atModules);
  SDF_ModuleId id = SDF_makeModuleIdWord(SDF_makeCHARLISTString(name));
  SDF_ImportList imports;
 
  imports = SI_getTransitiveImports(list, id);

  return ATmake("snd-value(all-needed-imports(<term>))", imports);
}

/*}}}  */
/*{{{  ATerm get_imported_module_names(int cid, ATerm atModule) */

ATerm get_imported_module_names(int cid, ATerm atModule)
{
  SDF_Start start = SDF_StartFromTerm(ATBunpack(atModule));
  SDF_Module module = SDF_getStartTopModule(start);
  ATermList imports = SI_getImports(module);
 
  return ATmake("snd-value(imported-module-names(<term>))", imports);
}

/*}}}  */

/*{{{  ATerm get_all_depending_modules(int cid, ATerm atModules, char* name) */

ATerm get_all_depending_module_names(int cid, ATerm pairs, char* name)
{
  ATerm id = ATmake("<str>", name);
  ATermList depending = PI_getDependingModules((ATermList) pairs, id);

  return ATmake("snd-value(all-depending-module-names(<term>))",
		depending);
}

/*}}}  */

/*{{{  ATerm get_module_id(int cid, ATerm atModule) */

ATerm get_module_id(int cid, ATerm atModule)
{
  SDF_Start start = SDF_StartFromTerm(ATBunpack(atModule));
  SDF_Module module = SDF_getStartTopModule(start);

  return ATmake("snd-value(module-id(<str>))", SDF_getModuleName(module));
}

/*}}}  */
/*{{{  ATerm get_module_path(int cid, char *path, char *id) */

ATerm get_module_path(int cid, char *path, char *id)
{
  int p;
  int i;

  /* If path equals "/bla/basic/" and id equals "basic/Booleans"
   * then we should return "/bla".
   *
   * If path equals "/bla/basic" and id equals "Booleans"
   * then we should return "/bla/basic"
   */
  
  for(p = strlen(path) - 1; p >= 0 && path[p] == SEP; p--) {
    path[p] = '\0';
  }
  
  for(i = strlen(id) - 1; i >= 0 && id[i] != SEP; i--);

  /* if i < 0, then the module name is not compound */
  if (i >= 0) {
    assert(id[i] == SEP);
    id[i] = '\0';
    i--;

    /* Eat up as much overlap as possible */
    for(; p >= 0 && i >= 0; p--, i--) {
      if (path[p] != id[i]) {
	break;
      }
      else {
	path[p] = '\0';
      }
    }
  }

  /* remove trailing directory separators */
  for(; p >= 0 && path[p] == SEP; p--) {
    path[p] = '\0';
  }

  return ATmake("snd-value(module-path(<str>))", path);
}

/*}}}  */
/*{{{  ATerm get_new_module_name(int cid, ATerm searchPaths, char *path, char* id) */

ATerm get_new_module_name(int cid, ATerm searchPaths, char *path, char* id)
{
  ATermList search = (ATermList) searchPaths;
  char chosenPath[PATH_LEN];
  char chosenId[PATH_LEN];
  int i;
 
  ATwarning("computing: %t, %s %s\n", searchPaths, path, id);

  /* We will choose the first longest search path that matches the path of
   * the chosen module, then construct a compound module id to complete
   * the filename.
   */

  chosenPath[0] = '\0';

  for (; !ATisEmpty(search); search = ATgetNext(search)) {
    char *firstPath = ATgetName(ATgetAFun((ATermAppl) ATgetFirst(search)));
    int len = strlen(firstPath);
    char end = path[len];

    path[len] = '\0';

    if (end == SEP) { 
      if (!strcmp(path, firstPath)) {
	if (strlen(chosenPath) < strlen(firstPath)) {
	  strcpy(chosenPath,firstPath);
	}
      }
    }

    path[len] = end;
  }

  if (strcmp(chosenPath,"")) {
    /* skip trailing slashes */
    for (i = strlen(chosenPath); i < strlen(path), path[i] == '/'; i++);

    /* The modulename is what's left of the path concatenated before
     * the module id
     */
    strcpy(chosenId,path+i);
    strcat(chosenId,id);

    ATwarning("new: %s, %s\n", chosenPath, chosenId);
    return ATmake("snd-value(new-module-name(<str>,<str>))", chosenPath, 
		  chosenId);
  }
  else {
    return ATmake("snd-value(module-name-inconsistent)");
  }
}

/*}}}  */

/*{{{  ATerm make_sdf_definition(int cid, ATerm atModules) */

ATerm make_sdf_definition(int cid, ATerm atModules)
{
  ATermList list;
  SDF_ModuleList modules;
  SDF_OptLayout space;
  SDF_SDF sdf;
  SDF_Start start;
  ATerm result;

  list = (ATermList) ATBunpack(atModules);

  modules = SDF_makeModuleListEmpty();
  space = SDF_makeLayoutSpace();

  for( ;!ATisEmpty(list); list = ATgetNext(list)) {
    SDF_Start start = SDF_StartFromTerm(ATgetFirst(list));
    SDF_Module module = SDF_getStartTopModule(start);

    if (SDF_isModuleListEmpty(modules)) {
      modules = SDF_makeModuleListSingle(module);
    }
    else {
      modules = SDF_makeModuleListMany(module, space, modules);
    }
  }

  sdf = SDF_makeSDFDefinition(space, SDF_makeDefinitionDefault(modules));
  start = SDF_makeStartSDF(space, sdf, space, 0);
  result = ATBpack(SDF_StartToTerm(start));

  return ATmake("snd-value(sdf-definition(<term>))", result);
}

/*}}}  */

/*{{{  ATerm is_valid_modulename_in_path(int cid, char* path, char *moduleName) */

ATerm is_valid_modulename_in_path(int cid, char* path, char *moduleName)
{
  int i,j;
  int pathlen = strlen(path);
  int namelen = strlen(moduleName);
  ATerm no = ATmake("snd-value(result(no))");
  ATerm yes = ATmake("snd-value(result(yes))");
 
  for(i=pathlen - 1, j=namelen - 1; i >= 0 && j >= 0; i--, j--) {
    if (moduleName[j] != path[i]) {
      return no;
    }
    if (!isalnum((int)moduleName[j])
        && moduleName[j] != '-'
        && moduleName[j] != '_'
        && moduleName[j] != '/') {
      return no;
    }
  }
 
  return yes;
}

/*}}}  */

/*{{{  ATerm add_import_to_module(int cid, ATerm atModule, char* name) */

ATerm add_import_to_module(int cid, ATerm atModule, char* name)
{
  SDF_Import sdfImport = SDF_makeImport(name);
  SDF_Start start = SDF_StartFromTerm(ATBunpack(atModule));
  SDF_Module oldModule = SDF_getStartTopModule(start);
  SDF_Module newModule = SDF_addModuleImport(oldModule, sdfImport);

  start = SDF_setStartTopModule(start, newModule);
  atModule = SDF_StartToTerm(start);

  return ATmake("snd-value(module(<term>))", ATBpack(atModule));
}

/*}}}  */
/*{{{  ATerm remove_import_from_module(int cid, ATerm atModule, char* name) */

ATerm remove_import_from_module(int cid, ATerm atModule, char* name)
{
  SDF_Import sdfImport = SDF_makeImport(name);
  SDF_Start start = SDF_StartFromTerm(ATBunpack(atModule));
  SDF_Module oldModule = SDF_getStartTopModule(start);
  SDF_Module newModule = SDF_removeModuleImport(oldModule, sdfImport);

  start = SDF_setStartTopModule(start, newModule);
  atModule = SDF_StartToTerm(start);

  return ATmake("snd-value(module(<term>))", ATBpack(atModule));
}

/*}}}  */
/*{{{  ATerm rename_modulename_in_module(int cid, ATerm atModule, char* from, ) */

ATerm rename_modulename_in_module(int cid, ATerm atModule, char* name)
{
  SDF_Start start = SDF_StartFromTerm(ATBunpack(atModule));
  SDF_Module oldModule = SDF_getStartTopModule(start);
  SDF_Module newModule = SDF_setModuleName(oldModule, name);

  start = SDF_setStartTopModule(start, newModule);
  atModule = SDF_StartToTerm(start);

  return ATmake("snd-value(module(<term>))", ATBpack(atModule));
}

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
  SDF_initSDFMEApi();

  cid = ATBconnect(NULL, NULL, -1, sdf_modules_handler);

  ATBeventloop();

  return 0;
}

/*}}}  */
