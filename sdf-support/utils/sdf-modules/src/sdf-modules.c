/*
  $Id$
 */

#include <stdlib.h>
#include <aterm2.h>
#include <atb-tool.h>
#include <ctype.h>

#include <SDFME-utils.h>
#include "sdf-modules.tif.h"

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

/*{{{  ATerm get_all_imports(int cid, ATerm atModules, char* name)  */

ATerm get_all_imports(int cid, ATerm atModules, char* name) 
{
  ATermList list = (ATermList) atModules;
  SDF_ModuleId id = SDF_makeModuleIdWord(SDF_makeCHARLISTString(name));
  ATermList imports;
 
  imports = SDF_getTransitiveImports(list, id);

  return ATmake("snd-result(all-imports(<term>))", imports);
}

/*}}}  */

/*{{{  ATerm get_all_depending_modules(int cid, ATerm atModules, char* name) */

ATerm get_all_depending_modules(int cid, ATerm atModules, char* name)
{
  ATermList list = (ATermList) atModules;
  SDF_ModuleId id = SDF_makeModuleIdWord(SDF_makeCHARLISTString(name));

  return ATmake("snd-result(all-depending-modules(<term>))",
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
    

  return ATmake("snd-result(renamings(<term>))", renamings);
}

/*}}}  */
/*{{{  ATerm get_module_id(int cid, ATerm atModule) */

ATerm get_module_id(int cid, ATerm atModule)
{
  SDF_Module module = SDF_ModuleFromTerm(atModule);

  return ATmake("snd-result(module-id(<str>))", SDF_getModuleName(module));
}

/*}}}  */

/*{{{  ATerm make_sdf_definition(int cid, ATerm atModules) */

ATerm make_sdf_definition(int cid, ATerm atModules)
{
  ATermList list = (ATermList) atModules;
  SDF_ModuleList modules = SDF_makeModuleListEmpty();
  SDF_OptLayout space = SDF_makeLayoutSpace();
  SDF_SDF sdf;
  SDF_Start start;

  for( ;!ATisEmpty(list); list = ATgetNext(list)) {
    SDF_Module module = SDF_ModuleFromTerm(ATgetFirst(list));

    if (SDF_isModuleListEmpty(modules)) {
      modules = SDF_makeModuleListSingle(module);
    }
    else {
      modules = SDF_makeModuleListMany(module, space, modules);
    }
  }

  sdf = SDF_makeSDFDefinition(space, SDF_makeDefinitionDefault(modules));
  start = SDF_makeStartSDF(space, sdf, space, 0);

  return ATmake("snd-result(sdf-definition(<term>))", start); 
}

/*}}}  */
/*{{{  ATerm get_import_graph(int cid, ATerm atModules) */

ATerm get_import_graph(int cid, ATerm atModules)
{
  ATermList list = (ATermList) atModules;
  ATermList nodes = ATempty;
  ATermList edges = ATempty;

  for (; !ATisEmpty(list); list = ATgetNext(list)) {
    SDF_Module module = SDF_ModuleFromTerm(ATgetFirst(list));
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

      imports = ATgetNext(imports);
    }

    nodes = ATinsert(nodes, name);
  }

  return ATmake("snd-result(import-graph(<term>,<term>))", nodes, edges);
}

/*}}}  */

/*{{{  ATerm is_valid_modulename_in_path(int cid, char* path, char *moduleName) */

ATerm is_valid_modulename_in_path(int cid, char* path, char *moduleName)
{
  int i,j;
  int pathlen = strlen(path);
  int namelen = strlen(moduleName);
  ATerm no = ATmake("snd-result(no)");
  ATerm yes = ATmake("snd-result(yes)");
 
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
