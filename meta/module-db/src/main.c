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
                     ATerm sdfTree, int timestamp)
{
  ATerm atModuleName, importGraph;
  ATermList unknowns;

  SDF_Module sdfModule = SDF_getStartTopModule(
                           SDF_StartFromTerm(sdfTree));

  if (!SO_checkModuleNameWithPath(SDFgetModuleName(sdfModule), 
                                  path)) {
    return ATmake("snd-value(name-consistency-error(<str>))", 
                  moduleName);
  }
  
  atModuleName = makeString(SDFgetModuleName(sdfModule)); 

  sdfTree = PT_makeTermFromParseTree(
              PT_addParseTreePosInfo(
                path,
                PT_makeParseTreeFromTerm(sdfTree)));
  
  MS_putModuleName(atModuleName);

  MS_putSdfTree(atModuleName, sdfTree);
  MS_putSdfText(atModuleName, "", path, timestamp);

  unknowns = MDB_unavailableImportedModules(atModuleName);

  importGraph = MDB_retrieveImportGraph();

  return ATmake("snd-value(module(<term>,imports(need-modules([<list>]),<term>)))",
                atModuleName, unknowns, importGraph);;
}

ATerm update_sdf2_module(int cid, char *moduleName, ATerm newSdfTree)
{
  ATwarning("Not implemented at line %d\n", __LINE__);
  return NULL;
}

ATerm get_sdf_tree(int cid, char *moduleName)
{
  ATerm atModuleName = makeString(moduleName);
  if (MS_existsModule(atModuleName)) {
    ATerm tree = MS_getSdfTree(atModuleName);
    return ATmake("snd-value(asfix(syntax(<term>)))", ATBpack(tree)); 
  }
  else {
    ATwarning("Module %t not in database!", moduleName);
    return ATmake("snd-value(asfix(unavailable))");
  }
}

void invalidate_sdf(int cid, char *moduleName)
{
  ATwarning("Not implemented at line %d\n", __LINE__);
}

ATerm add_empty_module(int cid, char *moduleName)
{
  ATwarning("Not implemented at line %d\n", __LINE__);
  return NULL;
}

ATerm all_equations_available(int cid, char *moduleName)
{
  ATwarning("Not implemented at line %d\n", __LINE__);
  return NULL;
}

void add_tree_eqs_section(int cid, char *moduleName, char* path,
                          ATerm eqsTree, char *eqsText, int timestamp)
{
  ATwarning("Not implemented at line %d\n", __LINE__);
  
}

void add_text_eqs_section(int cid, char *moduleName, char* path, 
                          char *eqsText, int timestamp)
{
  MS_putAsfText(makeString(moduleName), eqsText, path, timestamp);
}

ATerm update_eqs_text(int cid, char *moduleName, char *eqsText)
{
  ATwarning("Not implemented at line %d\n", __LINE__);
  return NULL;
}


void add_empty_eqs_section(int cid, char *moduleName, char* path)
{
  ATwarning("Not implemented at line %d\n", __LINE__);
}

ATerm update_eqs_tree(int cid, char *moduleName, ATerm newEqsTree)
{
  ATwarning("Not implemented at line %d\n", __LINE__);
  return NULL;
}


ATerm get_asf_tree(int cid, char *modulename)
{
  ATwarning("Not implemented at line %d\n", __LINE__);
  return NULL;
}

ATerm get_equations_for_module(int cid, ATerm atImport)
{
  ATwarning("Not implemented at line %d\n", __LINE__);
  return NULL;
}

ATerm get_equations_for_renamed_import(int cid, ATerm atImport, ATerm atRenamings)
{
  ATwarning("Not implemented at line %d\n", __LINE__);
  return NULL;
}

ATerm eqs_not_available_for_modules(int cid, char *moduleName)
{
  ATwarning("Not implemented at line %d\n", __LINE__);
  return NULL;
}

ATerm get_eqs_text(int cid, char *moduleName)
{
  ATwarning("Not implemented at line %d\n", __LINE__);
  return NULL;
}


ATerm get_parse_table(int cid, ATerm moduleId)
{
  char *moduleName;
  ATerm table, contents, result, atModuleName;
  char pathExt[9];
  int lenType;   


  if (ATmatch(moduleId, "eqs(<str>)", &moduleName)) {
    strcpy(pathExt, ES_getExtension("equations"));
    lenType = strlen(ES_getExtension("equations"));
    strcpy(pathExt+lenType, ES_getExtension("table"));
  }
  else if (ATmatch(moduleId, "trm(<str>)", &moduleName))  {
    strcpy(pathExt, ES_getExtension("term"));
    lenType = strlen(ES_getExtension("term"));
    strcpy(pathExt+lenType, ES_getExtension("table"));
  }
  else {
    ATwarning("Illegal moduleId: %t\n", moduleId);
    return ATmake("snd-value(no-table)");
  }

  atModuleName = makeString(moduleName);

  if (ATmatch(moduleId, "eqs(<str>)", &moduleName)) {
    table = MS_getAsfParseTable(atModuleName);
  }
  else {
    table = MS_getTermParseTable(atModuleName);
  }
  if (table) {
    ATermAppl dummy = (ATermAppl)ATBpack(ATmake("dummy"));
    char *path = MS_getSdfTextPath(atModuleName);
    int strLen = strlen(path);
    int lenExtension = strlen(pathExt);

    char *newPath = malloc(strLen+lenExtension+1);
    strncpy(newPath, path, strLen-lenType);
    strcpy(newPath+strLen-lenType, pathExt);

    contents = (ATerm)ATgetArgument((ATermAppl)table, 0);
    contents = (ATerm)ATmakeAppl1(ATgetAFun(dummy), contents);
    result = ATmake("snd-value(table(<term>,<str>))", 
                    contents, newPath);
    free(newPath);
    return result;
  }

  return ATmake("snd-value(no-table)");
}

ATerm add_parse_table(int cid, ATerm moduleId, ATerm table, int timestamp)
{
  char* moduleName;

  if (ATmatch(moduleId, "eqs(<str>)", &moduleName)) {
    MS_putAsfParseTable(makeString(moduleName), table, timestamp);
    return ATmake("snd-value(parse-table-added)");
  }
  else if (ATmatch(moduleId, "trm(<str>)", &moduleName))  {
    MS_putTermParseTable(makeString(moduleName), table, timestamp);
    return ATmake("snd-value(parse-table-added)");
  }
  else {
    ATerror("Illegal moduleId: %t\n", moduleId);
    return ATmake("snd-value(no-parse-table-added)");
  }
}

ATerm get_path(int cid, char *moduleName, ATerm type)
{
  char *path;
  ATerm atModuleName = makeString(moduleName);

  if (MS_existsModule(atModuleName)) {
    if (ATmatch(type, "eqs")) {
      path = MS_getAsfTextPath(atModuleName);
    }
    else {
      path = MS_getSdfTextPath(atModuleName);
    }
    return ATmake("snd-value(path(<str>))", path);
  }
  else {
    ATwarning("Module %t not in database!\n", atModuleName);
    return ATmake("snd-value(no-path)");
  }
}

void invalidate_parse_tables(int cid, char *modulename)
{
  ATwarning("Not implemented at line %d\n", __LINE__);
}

ATerm close_module(int cid, char *moduleName)
{
  ATwarning("Not implemented at line %d\n", __LINE__);
  return NULL;
}

ATerm delete_module(int cid, char *moduleName)
{
  ATwarning("Not implemented at line %d\n", __LINE__);
  return NULL;
}

ATerm rename_module(int cid, char *oldModuleName, char *newModuleName, 
		    char *newPath)
{
  ATwarning("Not implemented at line %d\n", __LINE__);
  return NULL;
}

ATerm copy_module(int cid, char *oldModuleName, char *newModuleName,
		  char *newPath)
{
  ATwarning("Not implemented at line %d\n", __LINE__);
  return NULL;
}

ATerm add_import(int cid, char *modName, char *importedModName, char *ImportedPath)
{
  ATwarning("Not implemented at line %d\n", __LINE__);
  return NULL;
}

ATerm remove_import(int cid, char *modName, char *importedModName, char *path)
{
  ATwarning("Not implemented at line %d\n", __LINE__);
  return NULL;
}

ATerm get_all_modules(int cid)
{
  ATwarning("Not implemented at line %d\n", __LINE__);
  return NULL;
}

ATerm get_all_depending_modules(int cid, char *moduleName)
{
  ATwarning("Not implemented at line %d\n", __LINE__);
  return NULL;
}

ATerm get_all_sdf2_definitions(int cid, char *moduleName)
{
  ATwarning("Not implemented at line %d\n", __LINE__);
  return NULL;
}

ATerm get_module_info(int cid, char *moduleName)
{
  ATerm atModuleName = makeString(moduleName);
  ATerm pathInfo;
  ATermList info = ATempty;

  if (MS_existsModule(atModuleName)) {
    char *path = MS_getSdfTextPath(atModuleName);
  
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
