/* $Id$ */

/*{{{  includes */

#include <stdlib.h>
#include <aterm2.h>
#include <atb-tool.h>
#include <ctype.h>
#include <assert.h>
#include <limits.h>

#include <SDFME-utils.h>
#include <MEPT-utils.h>
#include "sdf-modules.h"
#include "sdf-imports.h"

/*}}}  */

/*{{{  defines */

#define SEP '/'
#define PATH_LEN (_POSIX_PATH_MAX)

/*}}}  */
/*{{{  variables */

static char myversion[] = "1.0";

/*}}}  */

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

/*{{{  ATerm get_all_needed_imports(int cid, ATerm atModules, const char* name)  */

ATerm get_all_needed_imports(int cid, ATerm atModules, const char* name) 
{
  ATermList list = (ATermList) ATBunpack(atModules);
  SDF_ModuleId id = SDF_makeModuleId(name);
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

/*{{{  ATerm get_module_id(int cid, ATerm atModule) */

ATerm get_module_id(int cid, ATerm atModule)
{
  SDF_Start start = SDF_StartFromTerm(ATBunpack(atModule));
  SDF_Module module = SDF_getStartTopModule(start);
  SDF_ModuleId id = SDF_getModuleName(module);

  return ATmake("snd-value(module-id(<str>))", PT_yieldTree((PT_Tree) id));
}

/*}}}  */
/*{{{  ATerm get_module_path(int cid, const char *path, const char *id) */

ATerm get_module_path(int cid, const char *path, const char *id)
{
  char *pathBuf;
  char *idBuf;
  int p;
  int i;
  ATerm result;

  pathBuf = strdup(path);
  assert(pathBuf != NULL);

  idBuf = strdup(id);
  assert(idBuf != NULL);

  /* If path equals "/bla/basic/" and id equals "basic/Booleans"
   * then we should return "/bla".
   *
   * If path equals "/bla/basic" and id equals "Booleans"
   * then we should return "/bla/basic"
   */
  
  for (p = strlen(pathBuf) - 1; p >= 0 && pathBuf[p] == SEP; p--) {
    pathBuf[p] = '\0';
  }
  
  for (i = strlen(idBuf) - 1; i >= 0 && idBuf[i] != SEP; i--) {
    /* skip */
  }

  /* if i < 0, then the module name is not compound */
  if (i >= 0) {
    int lp = p;
    assert(idBuf[i] == SEP);
    idBuf[i] = '\0';
    i--;

    /* Eat up as much overlap as possible */
    for(; p >= 0 && i >= 0; p--, i--) {
      if (pathBuf[p] != idBuf[i]) {
	break;
      }
    }
    /* if the original prefix of the module names has not 
     * entirely disappeared we had a mismatch! */
    if (i > 0) {
      p = lp;
    }
  }

  /* remove trailing directory separators */
  for(; p >= 0 && pathBuf[p] == SEP; p--) {
    pathBuf[p] = '\0';
  }

  result = ATmake("snd-value(module-path(<str>))", pathBuf);

  free(pathBuf);
  free(idBuf);


  return result;
}

/*}}}  */
/*{{{  ATerm get_new_module_name(int cid, ATerm searchPaths, const char *path, const char* id) */

ATerm get_new_module_name(int cid, ATerm searchPaths, const char *path, const char* id)
{
  ATermList search = (ATermList) searchPaths;
  char chosenPath[PATH_LEN] = "";
  int chosenPathLen = 0;
  char chosenId[PATH_LEN];
 
  /* We will choose the longest search path that matches the path of
   * the chosen module.
   */

  for (; !ATisEmpty(search); search = ATgetNext(search)) {
    char *current = ATgetName(ATgetAFun((ATermAppl) ATgetArgument(ATgetFirst(search), 1)));
    int currentLen = strlen(current);

    if (strncmp(current, path, currentLen) == 0) {
      if (currentLen > chosenPathLen) {
	strcpy(chosenPath, current);
	chosenPathLen = currentLen;
      }
    }
  }

  /* Now construct a compound module id to complete
   * the filename.
   */

  if (chosenPathLen > 0) {
    int i = chosenPathLen;
    
    while (path[i] == SEP) {
      i++;
    } 

    if (strcmp(chosenPath, path) == 0) {
      strcpy(chosenId, id);
    }
    else {
      sprintf(chosenId, "%s%c%s", path+i, SEP, id);
    }

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
  SDF_OptLayout newline;
  SDF_SDF sdf;
  SDF_Start start;
  ATerm result;

  list = (ATermList) ATBunpack(atModules);

  modules = SDF_makeModuleListEmpty();
  newline = SDF_makeLayoutNewline();

  for( ;!ATisEmpty(list); list = ATgetNext(list)) {
    SDF_Start start = SDF_StartFromTerm(ATgetFirst(list));
    SDF_Module module = SDF_getStartTopModule(start);

    if (SDF_isModuleListEmpty(modules)) {
      modules = SDF_makeModuleListSingle(module);
    }
    else {
      modules = SDF_makeModuleListMany(module, newline, modules);
    }
  }

  if (!SDF_isModuleListEmpty(modules)) {
    sdf = SDF_makeSDFDefinition(newline, SDF_makeDefinitionDefault(modules));
    start = SDF_makeStartSDF(newline, sdf, newline, 0);
    result = ATBpack(SDF_StartToTerm(start));

    return ATmake("snd-value(sdf-definition(<term>))", result);
  }
  else {
    return ATmake("snd-value(no-sdf-definition)");
  }
}

/*}}}  */

/*{{{  ATerm is_valid_modulename(int cid, const char* path, const char *moduleName) */

ATerm is_valid_modulename(int cid, const char *moduleName)
{
  int j;
  int namelen = strlen(moduleName);
  ATerm no = ATmake("snd-value(result(no))");
  ATerm yes = ATmake("snd-value(result(yes))");
  
  for(j=namelen - 1; j >= 0; j--) {
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

/*{{{  ATerm add_import_to_module(int cid, ATerm atModule, const char* name) */

ATerm add_import_to_module(int cid, ATerm atModule, const char* name)
{
  SDF_Import sdfImport = SDF_makeImport((char*) name);
  SDF_Start start = SDF_StartFromTerm(ATBunpack(atModule));
  SDF_Module oldModule = SDF_getStartTopModule(start);
  SDF_Module newModule = SDF_addModuleImport(oldModule, sdfImport);

  start = SDF_setStartTopModule(start, newModule);
  atModule = SDF_StartToTerm(start);

  return ATmake("snd-value(module(<term>))", ATBpack(atModule));
}

/*}}}  */
/*{{{  ATerm remove_import_from_module(int cid, ATerm atModule, const char* name) */

ATerm remove_import_from_module(int cid, ATerm atModule, const char* name)
{
  SDF_Import sdfImport = SDF_makeImport((char*) name);
  SDF_Start start = SDF_StartFromTerm(ATBunpack(atModule));
  SDF_Module oldModule = SDF_getStartTopModule(start);
  SDF_Module newModule = SDF_removeModuleImport(oldModule, sdfImport);

  start = SDF_setStartTopModule(start, newModule);
  atModule = SDF_StartToTerm(start);

  return ATmake("snd-value(module(<term>))", ATBpack(atModule));
}

/*}}}  */

/*{{{  ATerm rename_modulename_in_module(int cid, ATerm atModule, const char* name) */

ATerm rename_modulename_in_module(int cid, ATerm atModule, const char* name)
{
  SDF_Start start = SDF_StartFromTerm(ATBunpack(atModule));
  SDF_Module oldModule = SDF_getStartTopModule(start);
  SDF_Module newModule = SDF_setModuleName(oldModule, (char*) name);

  start = SDF_setStartTopModule(start, newModule);
  atModule = SDF_StartToTerm(start);

  return ATmake("snd-value(module(<term>))", ATBpack(atModule));
}

/*}}}  */

/*{{{  int main(int argc, char *argv[]) */

int main(int argc, char *argv[])
{
  ATerm bottomOfStack;
  int i, cid;

  for (i=1; i<argc; i++) {
      if (strcmp(argv[i], "-h") == 0) {
	  usage(argv[0], ATfalse);
      } else if (strcmp(argv[i], "-V") == 0) {
	  version(argv[0]);
      }
  }

  ATBinit(argc, argv, &bottomOfStack);
  SDF_initSDFMEApi();
  PT_initMEPTApi();

  cid = ATBconnect(NULL, NULL, -1, sdf_modules_handler);

  ATBeventloop();

  return 0;
}

/*}}}  */
