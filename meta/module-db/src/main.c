/*
  $Id$
 */

#include <stdlib.h>
#include <aterm2.h>
#include <atb-tool.h>

#include <SDFME-utils.h>
#include <MEPT-utils.h>

#include "module-db.h"
#include "module-store.h"
#include "extension-store.h"
#include "table-store.h"
#include "term-conversion.h"
#include "module-operations.h"
#include "module-db.tif.h"

static char myversion[] = "4.0";

void rec_terminate(int cid, ATerm t)
{
  exit(0);
}

void init_module_db(int cid)
{
  ES_initExtensionStore();
  MS_initModuleStore();
}

ATerm retrieve_import_graph(int cid)
{
  return ATmake("snd-value(<term>)", MDB_retrieveImportGraph());
}

void set_file_extensions(int cid, char *syntaxExt, char *eqsExt, char *termExt)
{
  ES_addExtension("syntax", syntaxExt);
  ES_addExtension("equations", eqsExt);
  ES_addExtension("term", termExt);
  ES_addExtension("table", ".tbl");
}

ATerm exists(int cid, char *moduleName)
{
  if (MS_existsModule(makeString(moduleName))) {
    return ATmake("snd-value(exists)");
  }
  else {
    return ATmake("snd-value(notexists)");
  }
}

ATerm get_imported_modules(int cid, char *moduleName)
{
  ATermList result = MDB_getImportIds(makeString(moduleName));

  return ATmake("snd-value(imported-modules([<list>]))", result);
}

ATerm get_all_imported_modules(int cid, char *moduleName)
{
  ATermList imports = SO_getTransitiveImports(
                        SDF_makeImportListSingle(
                         SDFmakeImport(moduleName)));

  return ATmake("snd-value(all-modules([<list>]))", imports);
}
 

void clear_module_db(int cid)
{
}

ATerm add_sdf_module(int cid, char *moduleName, char *path, 
                     char *sdfText, ATerm sdfTree)
{
  ATerm atModuleName;
  ATermList unknowns;
  
  SDF_Module sdfModule = SDF_getStartTopModule(
                           SDF_StartFromTerm(sdfTree));

  if (!SO_checkModuleNameWithPath(SDFgetModuleName(sdfModule), 
                                  path)) {
    return ATmake("snd-value(name-consistency-error(<str>))", moduleName);
  }
  
  atModuleName = makeString(SDFgetModuleName(sdfModule)); 

  sdfTree = PT_makeTermFromParseTree(
              PT_addParseTreePosInfo(
                path,
                PT_makeParseTreeFromTerm(sdfTree)));
  
  MS_putModuleName(atModuleName);
  MS_putSdfTree(atModuleName, sdfTree);
  MS_putSdfText(atModuleName, sdfText);
  MS_putModulePath(atModuleName, path);

  unknowns = MDB_unavailableImportedModules(atModuleName);

  return ATmake("snd-value(module(<term>,need-modules([<list>])))",
                atModuleName, unknowns);
}

ATerm update_sdf2_module(int cid, char *moduleName, ATerm sdfTree)
{
  ATerm atModuleName;
  ATermList dependingModules;
  ATerm oldSdfTree;
  ATermList unknowns;

  SDF_Module sdfModule = SDF_getStartTopModule(
                           SDF_StartFromTerm(sdfTree));
  char *newModuleName = SDFgetModuleName(sdfModule);

  if (strcmp(moduleName, newModuleName)) {
    return ATmake("snd-value(name-consistency-error(<str>))", moduleName);
  }
  
  atModuleName = makeString(newModuleName);
  
  if (!MS_existsModule(atModuleName)) {
    return ATmake("snd-value(name-consistency-error(<str>))", moduleName);
  }

  oldSdfTree = MS_getSdfTree(atModuleName);

  if (oldSdfTree) {
    if (!ATisEqual(oldSdfTree, sdfTree)) {
      MS_putSdfTree(atModuleName, sdfTree);
      MS_removeAsfTree(atModuleName);
      MS_removeAsfParseTable(atModuleName);
      MS_removeTermParseTable(atModuleName);

      dependingModules = MDB_getDependingModules(atModuleName);
      MDB_invalidateModules(dependingModules);
     
      unknowns = MDB_unavailableImportedModules(atModuleName);

      return ATmake("snd-value(imports(changed-modules([<term>,<list>]),"
		    "need-modules([<list>]),<term>))",
		    atModuleName, dependingModules, unknowns, 
                    MDB_retrieveImportGraph());
    }
    else {
      return ATmake("snd-value(imports(changed-modules([<term>,<list>]),"
		    "need-modules([<list>]),<term>))",
		    ATempty, ATempty, MDB_retrieveImportGraph());
    }
  }
  return ATmake("snd-value(name-consistency-error(<str>))", moduleName);
}

ATerm get_sdf_tree(int cid, char *moduleName)
{
  ATerm atModuleName = makeString(moduleName);
  if (MS_existsModule(atModuleName)) {
    ATerm tree = MS_getSdfTree(atModuleName);
    return ATmake("snd-value(asfix(syntax(<term>)))", tree); 
  }
  else {
    ATwarning("get_sdf_tree: Module %t not in database!\n", 
              moduleName);
    return ATmake("snd-value(asfix(unavailable))");
  }
}

void invalidate_sdf(int cid, char *moduleName)
{
  MS_removeSdfTree(makeString(moduleName));
}

ATerm add_empty_module(int cid, char *moduleName)
{
  MS_putModuleName(makeString(moduleName));
  return ATmake("snd-value(empty-module-added(<term>))", 
		MDB_retrieveImportGraph());
}

ATerm all_equations_available(int cid, char *moduleName)
{
  ATermList missing = MDB_getModulesWithoutEqs(makeString(moduleName));

  if (ATisEmpty(missing)) {
    return ATmake("snd-value(equations-available)");
  }
  else {
    return ATmake("snd-value(equations-incomplete)");
  }
}

void add_tree_eqs_section(int cid, char *moduleName,
                          ATerm tree, char *eqsText)
{
  MS_putAsfText(makeString(moduleName), eqsText);
  MDB_updateEqsTree(makeString(moduleName), tree);
}

void add_text_eqs_section(int cid, char *moduleName,
                          char *eqsText)
{
  MS_putAsfText(makeString(moduleName), eqsText);
}

void update_eqs_text(int cid, char *moduleName, char *eqsText)
{
  ATerm atModuleName = makeString(moduleName);

  MS_putAsfText(atModuleName, eqsText);
  MS_removeAsfTree(atModuleName);
}


void add_empty_eqs_section(int cid, char *moduleName)
{
  MS_putAsfText(makeString(moduleName), "");
}

void update_eqs_tree(int cid, char *moduleName, ATerm tree)
{
  MDB_updateEqsTree(makeString(moduleName), tree);
}


ATerm get_asf_tree(int cid, char *moduleName)
{
  ATerm asfTree = MDB_getEqsTree(makeString(moduleName));

  if (asfTree) {
    return ATmake("snd-value(asfix(tree(<term>)))", asfTree);
  }
  else {
    return ATmake("snd-value(asfix(unavailable))");
  }
}

ATerm get_equations_for_module(int cid, ATerm atImport)
{
  SDF_Import import = SDF_makeImportFromTerm(atImport);
  SDF_ModuleName moduleName = SDF_getImportModuleName(import);
  ATerm plainName = SDF_getModuleNamePlain(moduleName);

  ATerm eqsTree = MDB_getEqsTree(plainName);

  if (eqsTree) {
    ATerm sdfTree = MS_getSdfTree(plainName);

    if (sdfTree) {
      SDF_Module module = SDF_getStartTopModule(SDF_StartFromTerm(sdfTree));
      SDF_Renamings renamings = SO_getModuleRenamings(import, module);
      SDF_ImportList fullImports;

      /* In case of parameters we need the imports in order
       * to rename the parameters in the imports correctly.
       * This is not needed in case of plain renamings.
       */
      if (renamings) {
        if (SDF_isImportRenamedModule(import)) {
	  fullImports = SDF_makeImportListEmpty();
        }
	else {
	  fullImports = SDF_getModuleImportsList(module);
	}
	return ATmake("snd-value(renaming-equations(<term>,<term>,<term>))",
		      SDF_makeTermFromRenamings(renamings),
		      SDF_makeTermFromImportList(fullImports),
		      ATBpack(eqsTree));
      }
      else {
        return ATmake("snd-value(plain-equations(<term>))", 
		      ATBpack(eqsTree));
      }
    }
  }
  
  return ATmake("snd-value(no-equations)");
}

ATerm get_equations_for_renamed_import(int cid, ATerm atImport, ATerm atRenamings)
{
  SDF_Import import;
  SDF_ModuleName moduleName;
  ATerm plainName;
  SDF_Renamings renamings;
  ATerm eqsTree;

  import = SDF_makeImportFromTerm(atImport);

  if (SDF_isValidImport(import)) {
    moduleName = SDF_getImportModuleName(import);
    plainName = SDF_getModuleNamePlain(moduleName);
    renamings = SDF_makeRenamingsFromTerm(atRenamings);

    eqsTree = MDB_getEqsTree(plainName);

    if (eqsTree) {
      ATerm sdfTree = MS_getSdfTree(plainName);

      if (sdfTree) {
        SDF_ImportList fullImports;
        SDF_Module module = SDF_getStartTopModule(SDF_StartFromTerm(sdfTree));
        SDF_Renamings newRenamings = SO_getModuleRenamings(import, module);

        /* In case of parameters we need the imports in order
         * to rename the parameters in the imports correctly.
         * This is not needed in case of plain renamings.
         */
        if (newRenamings) {
          newRenamings = SDF_renameRenamings(renamings, newRenamings);

          if (SDF_isImportRenamedModule(import)) {
	    fullImports = SDF_makeImportListEmpty();
          }
	  else {
	    fullImports = SDF_getModuleImportsList(module);
	  }
	  return ATmake("snd-value(renamed-equations(<term>,<term>,<term>))",
		        SDF_makeTermFromRenamings(newRenamings),
		        SDF_makeTermFromImportList(fullImports),
		        ATBpack(eqsTree));
        }
      }
    }
  }

  return ATmake("snd-value(no-equations)");
}

ATerm eqs_not_available_for_modules(int cid, char *moduleName)
{
  ATermList missingEqs = MDB_getModulesWithoutEqs(makeString(moduleName));

  return ATmake("snd-value(modules([<list>]))", missingEqs);
}

ATerm get_eqs_text(int cid, char *moduleName)
{
  char *eqsText = MS_getAsfTextText(makeString(moduleName));

  if (eqsText) {
    return ATmake("snd-value(eqs-text(<str>,<str>))", moduleName, eqsText);
  }
  else {
    return ATmake("snd-value(no-eqs-text(<str>))", moduleName);
  }
}

ATerm get_parse_table(int cid, ATerm moduleId)
{
  char *moduleName;
  ATerm table = NULL;
  ATerm atModuleName = NULL;

  if (ATmatch(moduleId, "eqs(<str>)", &moduleName)) {
    atModuleName = makeString(moduleName);
    table = MS_getAsfParseTable(atModuleName);
  }
  else if (ATmatch(moduleId, "trm(<str>)", &moduleName))  {
    atModuleName = makeString(moduleName);
    table = MS_getTermParseTable(atModuleName);
  }
  else {
    ATerror("Illegal moduleId: %t\n", moduleId);
  }

  if (table) {
    return ATmake("snd-value(table(<term>))", table);
  }
  return ATmake("snd-value(no-table)");
}

ATerm add_parse_table(int cid, ATerm moduleId, ATerm table)
{
  char* moduleName;

  if (ATmatch(moduleId, "eqs(<str>)", &moduleName)) {
    MS_putAsfParseTable(makeString(moduleName), table);
    return ATmake("snd-value(parse-table-added)");
  }
  else if (ATmatch(moduleId, "trm(<str>)", &moduleName))  {
    MS_putTermParseTable(makeString(moduleName), table);
    return ATmake("snd-value(parse-table-added)");
  }
  else {
    ATerror("Illegal moduleId: %t\n", moduleId);
    return ATmake("snd-value(no-parse-table-added)");
  }
}

ATerm get_path(int cid, char *moduleName)
{
  char *path;
  ATerm atModuleName = makeString(moduleName);

  if (MS_existsModule(atModuleName)) {
    path = MS_getModulePath(atModuleName);
    
    if (path) {
      return ATmake("snd-value(path(<str>))", path);
    }
    else {
      return ATmake("snd-value(no-path)");
    }
  }
  else {
    ATwarning("get_path: Module %t not in database!\n", atModuleName);
    return ATmake("snd-value(no-path)");
  }
}

void invalidate_parse_tables(int cid, char *moduleName)
{
  MDB_invalidateModules(MDB_getDependingModules(
                          makeString(moduleName)));
}

ATerm close_module(int cid, char *moduleName)
{
  ATerm atModuleName = makeString(moduleName);
  ATermList dependingModules = MDB_getDependingModules(atModuleName);

  dependingModules = ATremoveAll(dependingModules, atModuleName);

  MDB_invalidateModules(dependingModules);
  TS_removeValueFromAllTables(atModuleName);

  return ATmake("snd-value(changed-modules([<list>]))", dependingModules);
}

ATerm delete_module(int cid, char *moduleName)
{
  ATerm atModuleName = makeString(moduleName);
  ATermList dependingModules = MDB_getDependingModules(atModuleName);

  MDB_deleteModuleFromImportsInModules(dependingModules, atModuleName);

  dependingModules = ATremoveAll(dependingModules, atModuleName);

  MDB_invalidateModules(dependingModules);
  TS_removeValueFromAllTables(atModuleName);

  /* JV: Why is there no import graph calculated here? */

  return ATmake("snd-value(changed-modules([<list>]))", dependingModules);
}

ATerm rename_module(int cid, char *oldModuleName, 
                    char *newModuleName, 
		    char *newPath)
{
  ATwarning("Not implemented at line %d\n", __LINE__);
  return ATmake("snd-value(imports(changed-modules([]),<term>))",
                MDB_retrieveImportGraph());
}

ATerm copy_module(int cid, char *oldModuleName, char *newModuleName,
		  char *newPath)
{
  ATwarning("Not implemented at line %d\n", __LINE__);
  return ATmake("snd-value(imports(changed-modules([]),<term>))",
                MDB_retrieveImportGraph());
}

ATerm add_import(int cid, char *modName, char *importedModName, char *ImportedPath)
{
  ATwarning("Not implemented at line %d\n", __LINE__);
  return ATmake("snd-value(imports(changed-modules([]),<term>))",
                MDB_retrieveImportGraph());
}

ATerm remove_import(int cid, char *modName, char *importedModName, char *path)
{
  ATwarning("Not implemented at line %d\n", __LINE__);
  return ATmake("snd-value(imports(changed-modules([]),<term>))",
                MDB_retrieveImportGraph());
}

ATerm get_all_modules(int cid)
{
  return ATmake("snd-value(all-modules([<list>]))", MS_getActiveModules());
}

ATerm get_all_depending_modules(int cid, char *moduleName)
{
  return ATmake("snd-value(all-depending-modules([<list>]))", 
		MDB_getDependingModules(makeString(moduleName)));
}

ATerm get_all_sdf2_definitions(int cid, char *moduleName)
{
  ATerm definition = MDB_getSdfDefinition(makeString(moduleName));

  if (definition) {
    return ATmake("snd-value(syntax(<term>))", ATBpack(definition));
  }
  else {
    return ATmake("snd-value(sdf2-definition-error(\"Incomplete specification\")
    )");
  }
}

ATerm get_module_info(int cid, char *moduleName)
{
  ATerm atModuleName = makeString(moduleName);
  ATerm pathInfo;
  ATermList info = ATempty;

  if (MS_existsModule(atModuleName)) {
    char *path = MS_getModulePath(atModuleName);
  
    pathInfo = ATmake("[path,<str>]", path);
  }
  else {
    pathInfo = ATparse("[path,\"not available\"]");
  }

  info = ATmakeList1(pathInfo);

  return ATmake("snd-value(module-info(<str>,<term>))", moduleName, info);
}

static void 
usage(char *prg, ATbool is_err)
{
    ATwarning("usage: %s [aterm-options] [toolbus-options]\n", prg);
    ATwarning("use '%s -at-help' to get more options.\n", prg);
    ATwarning("This program can only be used as a ToolBus tool!\n");
    exit(is_err ? 1 : 0);
}

static void 
version(const char *msg)
{
    ATwarning("%s v%s\n", msg, myversion);
    exit(1);
}

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
  PT_initMEPTApi();
  SDF_initSDFMEApi();

  cid = ATBconnect(NULL, NULL, -1, module_db_handler);

  ATBeventloop();

  return 0;
}
