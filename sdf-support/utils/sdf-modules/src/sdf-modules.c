/* $Id$ */

#include <stdlib.h>
#include <aterm2.h>
#include <atb-tool.h>
#include <ctype.h>
#include <assert.h>

#include <SDFME-utils.h>
#include "sdf-modules.tif.h"

#define SEP '/'

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

/*{{{  static ATermList importsToModuleList(SDF_ImportList imports) */

static ATermList importsToModuleList(SDF_ImportList imports)
{
  ATermList modules = ATempty;

  while (!SDF_isImportListEmpty(imports)) {
    SDF_Import import = SDF_getImportListHead(imports);
    SDF_ModuleId id = SDF_getModuleNameModuleId(
			SDF_getImportModuleName(import));
    ATerm name = ATmake("<str>", SDF_getCHARLISTString(
                                   SDF_getModuleIdChars(id)));

    if (ATindexOf(modules, name, 0) < 0) {
      modules = ATinsert(modules, name);
    }

    if (SDF_hasImportListTail(imports)) {
      imports = SDF_getImportListTail(imports);
    }
    else {
      break;
    }
  }

  return modules;
}

/*}}}  */

/*{{{  ATerm get_all_needed_module_names(int cid, ATerm atModules, char* name)  */

ATerm get_all_needed_module_names(int cid, ATerm atModules, char* name) 
{
  ATermList list = (ATermList) atModules;
  SDF_ModuleId id = SDF_makeModuleIdWord(SDF_makeCHARLISTString(name));
  SDF_ImportList imports;
 
  imports = SDF_getTransitiveImports(list, id);

  return ATmake("snd-value(all-needed-module-names(<term>))", 
		importsToModuleList(imports));
}

/*}}}  */
/*{{{  ATerm get_all_needed_modules(int cid, ATerm atModules, char* name)  */

ATerm get_all_needed_modules(int cid, ATerm atModules, char* name) 
{
  SDF_ModuleId id = SDF_makeModuleIdWord(SDF_makeCHARLISTString(name));
  ATermList result = SDF_getTransitiveImportedModules((ATermList) atModules, 
						      id);
 

  return ATmake("snd-value(all-needed-modules(<term>))", result);
}

/*}}}  */
/*{{{  ATerm get_all_needed_imports(int cid, ATerm atModules, char* name)  */

ATerm get_all_needed_imports(int cid, ATerm atModules, char* name) 
{
  ATermList list = (ATermList) atModules;
  SDF_ModuleId id = SDF_makeModuleIdWord(SDF_makeCHARLISTString(name));
  SDF_ImportList imports;
 
  imports = SDF_getTransitiveImports(list, id);

  return ATmake("snd-value(all-needed-imports(<term>))", imports);
}

/*}}}  */
/*{{{  ATerm get_imported_module_names(int cid, ATerm atModule) */

ATerm get_imported_module_names(int cid, ATerm atModule)
{
  SDF_Start start = SDF_StartFromTerm(atModule);
  SDF_Module module = SDF_getStartTopModule(start);
  ATermList imports = SDF_getImports(module);
 
  return ATmake("snd-value(imported-module-names(<term>))", imports);
}

/*}}}  */

/*{{{  ATerm get_all_depending_modules(int cid, ATerm atModules, char* name) */

ATerm get_all_depending_module_names(int cid, ATerm atModules, char* name)
{
  ATermList list = (ATermList) atModules;
  SDF_ModuleId id = SDF_makeModuleIdWord(SDF_makeCHARLISTString(name));

  return ATmake("snd-value(all-depending-module-names(<term>))",
		(ATerm) SDF_getDependingModuleIds(list, id));
}

/*}}}  */

/*{{{  ATerm get_import_renamings(int cid, ATerm atImport) */

ATerm get_import_renamings(int cid, ATerm atImport)
{
  SDF_Import import = SDF_ImportFromTerm(atImport);
  SDF_Renamings renamings = SDF_makeRenamingsRenamings(SDF_makeLayoutSpace(),
			       SDF_makeRenamingListEmpty(),
			       SDF_makeLayoutSpace());

  if (SDF_hasImportRenamings(import)) {
    renamings = SDF_getImportRenamings(import);
  }
    

  return ATmake("snd-value(renamings(<term>))", renamings);
}

/*}}}  */
/*{{{  ATerm get_module_id(int cid, ATerm atModule) */

ATerm get_module_id(int cid, ATerm atModule)
{
  SDF_Start start = SDF_StartFromTerm(atModule);
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
  
  for(p = strlen(path) - 1; p >= 0 && path[p] == SEP; p--);
  path[p+1] = '\0';
  
  for(i = strlen(id) - 1; i >= 0 && id[i] != SEP; i--);

  /* if i < 0, then the module name is not compound */
  if (i >= 0) {
    assert(id[i] == SEP);
    id[i] = '\0';
    i--;

    /* Eat up as much overlap as possible */
    for(; p >= 0 && i >= 0; p--, i--) {
      ATwarning("%d == %d ??\n", path[p], id[i]);
      if (path[p] != id[i]) {
	break;
      }
      else {
	path[p] = '\0';
      }
    }
  }

  /* remove trailing directory separators */
  for(p = strlen(path) - 1; p >= 0 && path[p] == SEP; p--);
  path[p+1] = '\0';

  return ATmake("snd-value(module-path(<str>))", path);
}

/*}}}  */

/*{{{  ATerm make_sdf_definition(int cid, ATerm atModules) */

ATerm make_sdf_definition(int cid, ATerm atModules, char *name)
{
  SDF_ModuleId id = SDF_makeModuleIdWord(SDF_makeCHARLISTString(name));
  ATermList list = 
    SDF_getTransitiveImportedModules((ATermList) atModules, id);
  SDF_ModuleList modules = SDF_makeModuleListEmpty();
  SDF_OptLayout space = SDF_makeLayoutSpace();
  SDF_SDF sdf;
  SDF_Start start;

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

  return ATmake("snd-value(sdf-definition(<term>))", start); 
}

/*}}}  */
/*{{{  ATerm get_import_graph(int cid, ATerm atModules) */

ATerm get_import_graph(int cid, ATerm atModules)
{
  ATermList list = (ATermList) atModules;
  ATermList nodes = ATempty;
  ATermList edges = ATempty;

  for (; !ATisEmpty(list); list = ATgetNext(list)) {
    SDF_Start start = SDF_StartFromTerm(ATgetFirst(list));
    SDF_Module module = SDF_getStartTopModule(start);
    SDF_ModuleId id = SDF_getModuleNameModuleId(
			SDF_getModuleModuleName(module));
    ATerm name = ATmake("<str>", 
                        SDF_getCHARLISTString(SDF_getModuleIdChars(id)));
    ATermList imports = SDF_getImports(module);

    for(; !ATisEmpty(imports); imports = ATgetNext(imports)) {
      ATerm import = ATgetFirst(imports);
      ATerm pair = ATmake("[<term>,<term>]", name, import);

      if (ATindexOf(edges, pair, 0) < 0) {
        edges = ATinsert(edges, pair);
      }
    }

    nodes = ATinsert(nodes, name);
  }

  return ATmake("snd-value(import-graph(<term>,<term>))", nodes, edges);
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
