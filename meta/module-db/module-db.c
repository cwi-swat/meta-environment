/*
  $Id$
 */
/*{{{  includes */

#include <assert.h>

#include "module-db.h"
#include "renaming-symbols.h"
#include "renaming-imports.h"
#include "MDB.h"

/*}}}  */
/*{{{  variables */

static char myversion[] = "3.0";

static ATermTable modules_db;
static ATermTable import_db;
static ATermTable full_import_db;
static ATermTable trans_db;
static ATermTable eqs_db;

static ATerm MDB_NONE;

/* adding position info can stop at the condition level */
#define DEPTH_OF_EQUATIONS   4

/*}}}  */

/*{{{  Forward declarations */

static ATbool complete_asf_specification(ATermList visited, ATerm module);
static ATermList add_imports(ATerm name, ATermList mods, SDF_ImportList imports);
static ATermList replace_imports(ATerm name, ATermList mods, SDF_ImportList imports);
static ATermList modules_depend_on(ATerm name, ATermList mods);
static ATbool is_valid_parse_table(ATermList visited, ATerm module, 
				   int timeOfEqsTable, int timeOfTrmTable);
/*}}}  */

/*{{{  void rec_terminate(int cid, ATerm t) */

void rec_terminate(int cid, ATerm t)
{
  exit(0);
}

/*}}}  */
/*{{{  ATerm exists(int cid, char *modulename) */

ATerm exists(int cid, char *modulename)
{
  ATerm name = ATmake("<str>",modulename);
  MDB_Entry entry = MDB_EntryFromTerm(GetValue(modules_db, name));
  if (entry) {
    return ATmake("snd-value(result(exists(<term>)))", name);
  }
  else {
    return ATmake("snd-value(result(notexists(<term>)))", name);
  }
}

/*}}}  */
/*{{{  XXX calculateImportList(SDF_ModuleName moduleName) */

static ATbool pathAvailable(const char *path)
{
  return strcmp(path, "unavailable");
}

static char *
makeAsfPath(const char *path)
{
  static char newPath[BUFSIZ];
  int len;

  if (pathAvailable(path)) {
    len = strlen(path) - strlen(".sdf");
    strncpy(newPath, path, len);
    strcpy(newPath+len, ".asf");
  }
  else {
    strcpy(newPath, path);
  }

  return newPath;
}

/*}}}  */
/*{{{  SDF_ImportList calculateImportList(SDF_ModuleName moduleName) */

static
SDF_ImportList calculateImportList(SDF_ModuleName moduleName)
{
  ATerm plainName = SDF_getModuleNamePlain(moduleName);
  MDB_Entry entry = MDB_EntryFromTerm(GetValue(modules_db, plainName));
  SDF_ImportList fullImports = SDF_makeImportListFromTerm(
                                 GetValue(full_import_db, plainName));

  if (SDF_isModuleNameParameterized(moduleName)) {
    ATerm sdfTerm = MDB_getEntrySdfTree(entry);
    PT_Tree sdfTree = PT_getParseTreeTree(PT_makeParseTreeFromTerm(sdfTerm));

    fullImports = renameParametersInImportList(moduleName, 
                                               sdfTree, fullImports);
  }
  return fullImports;
}

/*}}}  */
/*{{{  ASF_CondEquationList getEquations(SDF_Import import) */

static
ASF_CondEquationList getEquations(SDF_Import import)
{
  ATerm plainName, eqsTerm, sdfTerm;
  MDB_Entry entry;
  ASF_CondEquationList asfEqsList;
  ASF_CondEquationList newAsfEqsList = ASF_makeCondEquationListEmpty();
  PT_Tree eqsTree, sdfTree;
  ASF_Equations asfEqs;
  SDF_ModuleName moduleName;
  SDF_ImportList fullImports;
  ATerm eqs;
  ATerm atImport = SDF_makeTermFromImport(import);

  moduleName = SDF_getImportModuleName(import);
  plainName = SDF_getModuleNamePlain(moduleName);

  eqs = GetValue(eqs_db, atImport);
  if (!eqs) {
    entry = MDB_EntryFromTerm(GetValue(modules_db, plainName));
    fullImports = calculateImportList(moduleName);
    eqsTerm = MDB_getEntryAsfTree(entry);

    if (!ATisEqual(eqsTerm, MDB_NONE)) {
      eqsTree = PT_getParseTreeTree(PT_makeParseTreeFromTerm(eqsTerm));
      asfEqs = ASF_makeEquationsFromTerm(PT_makeTermFromTree(eqsTree));
      if (ASF_isEquationsPresent(asfEqs)) {
        asfEqsList = ASF_getEquationsList(asfEqs);
        newAsfEqsList = ASF_unionCondEquationList(newAsfEqsList, asfEqsList);
      }
    }
    
/* To ensure termination when recursing */
    PutValue(eqs_db, atImport, 
             ASF_makeTermFromCondEquationList(
               ASF_makeCondEquationListEmpty())); 

    while (SDF_hasImportListHead(fullImports)) {
      SDF_Import localImport = SDF_getImportListHead(fullImports);

      newAsfEqsList = ASF_unionCondEquationList(
                        newAsfEqsList,
                        getEquations(localImport));

      if (SDF_hasImportListTail(fullImports)) {
        fullImports = SDF_getImportListTail(fullImports);
      }
      else {
        break;
      }
    }

    if (SDF_isImportRenamedModule(import)) {
      SDF_Renamings renamings = SDF_getImportRenamings(import);

      newAsfEqsList = renameSymbolsInEquations(newAsfEqsList, renamings);
    }

    if (SDF_isModuleNameParameterized(moduleName)) {
      SDF_Symbols actualParams = SDF_getModuleNameParams(moduleName);

      sdfTerm = MDB_getEntrySdfTree(entry);
      sdfTree = PT_getParseTreeTree(PT_makeParseTreeFromTerm(sdfTerm));

      newAsfEqsList = renameParametersInEquations(sdfTree, 
                                                  newAsfEqsList, 
                                                  actualParams);

    }
    eqs = ASF_makeTermFromCondEquationList(newAsfEqsList);

    PutValue(eqs_db, atImport, eqs);

    return newAsfEqsList;
  }
  else {
    return ASF_makeCondEquationListFromTerm(eqs);
  }
}

/*}}}  */
/*{{{  ATermList calc_trans(ATermList todo) */

static ATermList calc_trans(SDF_ImportList todo)
{
  SDF_ImportList fullImports;
  ATermList result = ATempty;

  while (SDF_hasImportListHead(todo)) {
    SDF_Import     import     = SDF_getImportListHead(todo);
    ATerm          atImport   = SDF_makeTermFromImport(import);
    SDF_ModuleName moduleName = SDF_getImportModuleName(import);
    ATerm          name       = SDF_getModuleNamePlain(moduleName);
    ATerm          sdfTerm;
    PT_Tree        sdfTree;

    if (ATindexOf(result, atImport, 0) < 0) {
      MDB_Entry entry = MDB_EntryFromTerm(GetValue(modules_db, name));
      if (entry) {
        fullImports = SDF_makeImportListFromTerm(
                        GetValue(full_import_db, name));

        if (SDF_isModuleNameParameterized(moduleName)) {
          sdfTerm = MDB_getEntrySdfTree(entry);
          sdfTree = PT_getParseTreeTree(PT_makeParseTreeFromTerm(sdfTerm));

          fullImports = renameParametersInImportList(moduleName, 
                                                     sdfTree, 
                                                     fullImports);
        }
        result = ATappend(result, atImport);
        todo = SDF_concatImportList(todo, fullImports);
      }
    };
    if (SDF_hasImportListTail(todo)) {
      todo = SDF_getImportListTail(todo);
    }
    else {
      break;
    }
  }
  return result;
}

/*}}}  */
/*{{{  static ATermList get_imported_modules(ATerm name) */

static
ATermList get_imported_modules(char *name)
{
  ATermList result;
  ATerm atName, value;

  atName = ATmake("<str>", name);
  value = GetValue(trans_db, atName);
  if (!value) {
    result = calc_trans(SDF_makeImportListSingle(SDFmakeImport(name)));
    result = ATsort(result, ATcompare);
    PutValue(trans_db, atName, (ATerm)result);
  }
  else {
    result = (ATermList)value;
  }

  return result;
}

/*}}}  */
/*{{{  ATerm get_all_equations(int cid, char *moduleName) */

ATerm get_all_equations(int cid, char *moduleName)
{
  ATerm name;
  ATerm result;

/* calculate the transitive closure of the imported modules. */
  
  name = ATmake("<str>", moduleName);

  if (complete_asf_specification(ATempty, name)) {
    result = ASF_makeTermFromCondEquationList(
               getEquations(SDFmakeImport(moduleName)));
    return ATmake("snd-value(equations(<term>))", ATBpack(result));
  }
  else {
    return ATmake("snd-value(equations-incomplete)");
  }
}

/*}}}  */
/*{{{  static void reset_trans_db(void) */

static void reset_trans_db(void)
{
  if (trans_db != NULL) {
    ATtableDestroy(trans_db);
    trans_db = CreateValueStore(100,75);
  }
}

/*}}}  */
/*{{{  static void reset_eqs_db(void) */

static void reset_eqs_db(void)
{
  if (eqs_db != NULL) {
    ATtableDestroy(eqs_db);
    eqs_db = CreateValueStore(100,75);
  }
}

/*}}}  */
/*{{{  void create_module_db(int cid) */

void create_module_db(int cid)
{
  modules_db = CreateValueStore(100,75);
  import_db = CreateValueStore(100,75);
  full_import_db = CreateValueStore(100,75);
  trans_db = CreateValueStore(100,75);
  eqs_db = CreateValueStore(100,75);
}

/*}}}  */

/*{{{  void clear_module_db(int cid) */

void clear_module_db(int cid)
{
  if (modules_db != NULL) {
    ATtableDestroy(modules_db);
    modules_db = CreateValueStore(100,75);
  }

  if (import_db != NULL) {
    ATtableDestroy(import_db);
    ATtableDestroy(full_import_db);
    import_db = CreateValueStore(100,75);
    full_import_db = CreateValueStore(100,75);
  }

  reset_trans_db();
  reset_eqs_db();
}

/*}}}  */
/*{{{  ATerm calc_import_graph(void) */

static ATerm 
calc_import_graph(void)
{
  ATerm module1, module2, pair;
  ATermList result = ATempty;
  ATermList allmodules = ATtableKeys(import_db), importedmodules = ATempty;
  ATermList actualmodules = allmodules;

  while (!ATisEmpty(allmodules)) {
    module1 = ATgetFirst(allmodules);
    importedmodules = (ATermList) GetValue(import_db,module1);
    while (!ATisEmpty(importedmodules)) {
      module2 = ATgetFirst(importedmodules);
      pair = ATmake("[<term>,<term>]", module1, module2);
      if(ATindexOf(result, pair, 0) < 0) {
        result = ATappend(result, pair);
      }
      importedmodules = ATgetNext(importedmodules);
    }
    allmodules = ATgetNext(allmodules);
  }
  return ATmake("import-graph([<list>],[<list>])", actualmodules, result);
}

/*}}}  */
/*{{{  ATerm add_sdf_module(int cid, char *moduleName, char *path, ATerm sdfTree,  */
/* Creation of a new entry in the database of a new Sdf2 definition. 
 */

ATerm add_sdf_module(int cid, char *moduleName, char *path, ATerm sdfTree, 
		      int timestamp)
{
  ATerm          modName;
  MDB_Entry      entry; 
  ATerm          import_graph;
  ATermList      imports, unknowns;
  PT_Tree        tree;
  PT_ParseTree   parseTree;
  SDF_Module     sdfModule;
  SDF_ImportList fullImports;

  parseTree = PT_makeParseTreeFromTerm(sdfTree);

  if (!PT_isValidParseTree(parseTree)) {
    return ATmake("snd-value(illegal-module-error(<str>))", moduleName);
  }

  tree      = PT_getParseTreeTree(parseTree);
  sdfModule = SDF_makeModuleFromTerm(PT_makeTermFromTree(tree));

  /* Sanity check: modulename inside module must equal name passed as str */
  if (strcmp(moduleName, SDFgetModuleName(sdfModule)) != 0) {
    return ATmake("snd-value(name-consistency-error(<str>))", moduleName);
  }

  modName = ATmake("<str>", moduleName);
  entry = MDB_makeEntryDefault(path,
                               sdfTree,
                               timestamp,
                               MDB_NONE,
                               MDB_NONE,
                               0,
                               MDB_NONE,
                               0,
                               MDB_NONE,
                               0);

  PutValue(modules_db, modName, MDB_EntryToTerm(entry));
  imports = SDF_getImports(sdfModule);
  fullImports = SDF_getModuleImportsList(sdfModule);
  unknowns = add_imports(modName, imports, fullImports);
  import_graph = calc_import_graph();

  return ATmake("snd-value(imports(need-modules([<list>]),<term>))",
		unknowns, import_graph);
}

/*}}}  */
/*{{{  void update_syntax_status_of_modules(ATermList mods) */
/* This function "update..." removes the parse table and
   the asfix representation of the equations from the
   module database for all listed modules. */

static void 
update_syntax_status_of_modules(ATermList mods)
{
  ATerm modname;
  MDB_Entry entry;

  while (!ATisEmpty(mods)) {
    modname = ATgetFirst(mods);
    entry = MDB_EntryFromTerm(GetValue(modules_db, modname));
    entry = MDB_setEntryAsfTree(entry, MDB_NONE);
    entry = MDB_setEntryAsfTable(entry, MDB_NONE);
    entry = MDB_setEntryTrmTable(entry, MDB_NONE);
    PutValue(modules_db, modname, MDB_EntryToTerm(entry));
    mods = ATgetNext(mods);
  }
}

/*}}}  */
/*{{{  ATerm update_sdf2_module(int cid, ATerm newSdfTree) */
/* Update an existing Sdf2 definition in the database.
 */

ATerm update_sdf2_module(int cid, ATerm newSdfTree)
{
  ATerm          curSdfTree, import_graph;
  MDB_Entry      entry;
  ATermList      imports, unknowns, chg_mods;
  PT_ParseTree   parseTree;
  PT_Tree        tree;
  SDF_Module     sdfModule;
  ATerm          modName;
  SDF_ImportList fullImports;

  newSdfTree = ATremoveAllAnnotations(newSdfTree);
  parseTree = PT_makeParseTreeFromTerm(newSdfTree);
  if (!PT_isValidParseTree(parseTree)) {
    ATerror("not an asfix module: %t\n", newSdfTree);
    return NULL;
  }

  tree      = PT_getParseTreeTree(parseTree);
  sdfModule = SDF_makeModuleFromTerm(PT_makeTermFromTree(tree));
  modName   = ATmake("<str>", SDFgetModuleName(sdfModule));
  entry     = MDB_EntryFromTerm(GetValue(modules_db, modName));

  if (MDB_isValidEntry(entry)) {
    curSdfTree = MDB_getEntrySdfTree(entry);
    if (!ATisEqual(curSdfTree, newSdfTree)) {
      entry = MDB_setEntrySdfTree(entry, newSdfTree);

      entry = MDB_setEntryAsfTree(entry, MDB_NONE);
      entry = MDB_setEntryAsfTable(entry, MDB_NONE);
      entry = MDB_setEntryTrmTable(entry, MDB_NONE);
      PutValue(modules_db, modName, MDB_EntryToTerm(entry));

      chg_mods = modules_depend_on(modName, ATempty);
      update_syntax_status_of_modules(chg_mods); 
      imports = SDF_getImports(sdfModule);
      fullImports = SDF_getModuleImportsList(sdfModule);

      unknowns = replace_imports(modName, imports, fullImports);
      import_graph = calc_import_graph();

      return ATmake("snd-value(imports(changed-modules([<term>,<list>]),"
		    "need-modules([<list>]),<term>))",
		    modName, chg_mods, unknowns, import_graph);
    } else {
      import_graph = calc_import_graph();

      return ATmake("snd-value(imports(changed-modules([<list>]),"
		    "need-modules([<list>]),<term>))",
		    ATempty, ATempty, import_graph);
    }
  }
  else {
    return ATmake("snd-value(name-consistency-error(<str>))", modName);
  }
}

/*}}}  */
/*{{{  ATerm add_empty_module(int cid, char *moduleName) */

ATerm add_empty_module(int cid, char *moduleName)
{
  ATerm atModuleName, importGraph;
  MDB_Entry entry;
  ATermList discardValue;
  char  fileName[1024] = {'\0'};

  atModuleName = ATmake("<str>",  moduleName);
  sprintf(fileName,"%s%s", moduleName, ".sdf");
  entry = MDB_makeEntryDefault(fileName,
                               MDB_NONE,
                               0,
                               MDB_NONE,
                               MDB_NONE,
                               0,
                               MDB_NONE,
                               0,
                               MDB_NONE,
                               0);
  PutValue(modules_db, ATmake("<str>", moduleName), MDB_EntryToTerm(entry));

  discardValue = add_imports(atModuleName, ATempty, SDF_makeImportListEmpty());
  importGraph = calc_import_graph();

  return ATmake("snd-value(empty-module-added(<term>))", importGraph);
}

/*}}}  */
/*{{{  void add_tree_eqs_section(int cid, char *moduleName, char* path, */

void add_tree_eqs_section(int cid, char *moduleName, char* path,
                          ATerm eqsTree, char *eqsText, int timestamp)
{
  MDB_Entry entry;
  ATerm atModuleName, atEqsText;

  atModuleName = ATmake("<str>", moduleName);
  atEqsText = ATmake("<str>", eqsText);

  eqsTree = PT_makeTermFromParseTree(
              PT_addParseTreePosInfoToDepth(
                path, 
                PT_makeParseTreeFromTerm(eqsTree),
                DEPTH_OF_EQUATIONS));

  entry = MDB_EntryFromTerm(GetValue(modules_db, atModuleName));
  entry = MDB_setEntryAsfTree(entry, eqsTree);
  entry = MDB_setEntryAsfText(entry, atEqsText);
  entry = MDB_setEntryAsfTreeCreationTime(entry, timestamp);
  PutValue(modules_db, atModuleName, MDB_EntryToTerm(entry));
}

/*}}}  */
/*{{{  void add_text_eqs_section(int cid, char *moduleName, char* path,  */

void add_text_eqs_section(int cid, char *moduleName, char* path, 
                          char *eqsText, int timestamp)
{
  MDB_Entry entry;
  ATerm atModuleName;
  ATerm atEqsText;

  atModuleName = ATmake("<str>", moduleName);
  atEqsText = ATmake("<str>", eqsText);

  entry = MDB_EntryFromTerm(GetValue(modules_db, atModuleName));
  entry = MDB_setEntryAsfText(entry, atEqsText);
  entry = MDB_setEntryAsfTree(entry, MDB_NONE);
  entry = MDB_setEntryAsfTreeCreationTime(entry, timestamp);
  PutValue(modules_db, atModuleName, MDB_EntryToTerm(entry));
}

/*}}}  */

/*{{{  void update_eqs_text(int cid, char *moduleName, char *eqsText) */

void update_eqs_text(int cid, char *moduleName, char *eqsText)
{
  MDB_Entry entry;
  ATerm atModuleName;
  ATerm atEqsText;

  atModuleName = ATmake("<str>", moduleName);
  atEqsText = ATmake("<str>", eqsText);

  entry = MDB_EntryFromTerm(GetValue(modules_db, atModuleName));
  entry = MDB_setEntryAsfText(entry, atEqsText);
  entry = MDB_setEntryAsfTree(entry, MDB_NONE); 
  PutValue(modules_db, atModuleName, MDB_EntryToTerm(entry));

  reset_eqs_db();
}

/*}}}  */

/*{{{  void invalidate_sdf(int cid, char *moduleName) */

void invalidate_sdf(int cid, char *moduleName)
{
  MDB_Entry entry;
  ATerm atModuleName;

  atModuleName = ATmake("<str>", moduleName);

  entry = MDB_EntryFromTerm(GetValue(modules_db, atModuleName));

  entry = MDB_setEntrySdfTree(entry, MDB_NONE);

  PutValue(modules_db, atModuleName, MDB_EntryToTerm(entry));
}

/*}}}  */

/*{{{  void add_empty_eqs_section(int cid, char *moduleName, char* path) */

void add_empty_eqs_section(int cid, char *moduleName, char* path)
{
  MDB_Entry entry;
  ATerm atModuleName, atEqsText;

  atModuleName = ATmake("<str>", moduleName);
  atEqsText = ATmake("\"\"");

  entry = MDB_EntryFromTerm(GetValue(modules_db, atModuleName));
  entry = MDB_setEntryAsfText(entry, atEqsText);
  entry = MDB_setEntryAsfTree(entry, MDB_NONE);
  PutValue(modules_db, atModuleName, MDB_EntryToTerm(entry));
}

/*}}}  */

/*{{{  ATerm update_eqs_tree(int cid, char *moduleName, ATerm newEqsTree) */

ATerm update_eqs_tree(int cid, char *moduleName, ATerm newEqsTree)
{
  MDB_Entry entry;
  ATerm curEqsTree;
  ATerm atModuleName;
  ATermList changedModules;
  char *sdfPath, *asfPath;

  atModuleName = ATmake("<str>", moduleName);

  entry = MDB_EntryFromTerm(GetValue(modules_db, atModuleName));

  curEqsTree = MDB_getEntryAsfTree(entry);

  sdfPath = MDB_getEntryPath(entry);
  if (pathAvailable(sdfPath)) {
    asfPath = makeAsfPath(sdfPath);
    newEqsTree = PT_makeTermFromParseTree(
                   PT_addParseTreePosInfoToDepth(
                     asfPath, 
                     PT_makeParseTreeFromTerm(newEqsTree),
                     DEPTH_OF_EQUATIONS));
  }
  else {
    ATwarning("No path for %s equations section\n", moduleName);
  }

  if (!ATisEqual(newEqsTree, curEqsTree)) {
    entry = MDB_setEntryAsfTree(entry, newEqsTree);
    PutValue(modules_db, atModuleName, MDB_EntryToTerm(entry));
    changedModules = modules_depend_on(atModuleName, ATempty);
    reset_eqs_db();
    return ATmake("snd-value(changed-modules([<term>,<list>]))",
      atModuleName, changedModules);
  }
  else {
    return ATmake("snd-value(changed-modules([]))");
  }
}

/*}}}  */
/*{{{  ATerm add_parse_table(int cid, ATerm moduleId, ATerm table, int timestamp) */

ATerm add_parse_table(int cid, ATerm moduleId, ATerm table, int timestamp)
{
  MDB_Entry entry;
  ATerm modname;
  char *moduleName;

  if (ATmatch(moduleId, "eqs(<str>)", &moduleName)) {
    modname = ATmake("<str>", moduleName);
    entry = MDB_EntryFromTerm(GetValue(modules_db, modname));
    entry = MDB_setEntryAsfTable(entry, table);
    entry = MDB_setEntryAsfTableCreationTime(entry, timestamp);
    PutValue(modules_db, modname, MDB_EntryToTerm(entry));
    return ATmake("snd-value(parse-table-added)");
  } 
  else if (ATmatch(moduleId, "trm(<str>)", &moduleName))  {
    modname = ATmake("<str>", moduleName);
    entry = MDB_EntryFromTerm(GetValue(modules_db, modname));
    entry = MDB_setEntryTrmTable(entry, table);
    entry = MDB_setEntryTrmTableCreationTime(entry, timestamp);
    PutValue(modules_db, modname, MDB_EntryToTerm(entry));
    return ATmake("snd-value(parse-table-added)");
  }
  else {
    ATerror("Illegal moduleId: %t\n", moduleId);
    return ATmake("snd-value(no-parse-table-added)");
  }
}

/*}}}  */
/*{{{  ATerm get_path(int cid, char *modulename, ATerm type) */

ATerm get_path(int cid, char *modulename, ATerm type)
{
  MDB_Entry entry;
  ATerm modname;
  char *path;

  if (!ATmatch(type, "eqs") && !ATmatch(type, "sdf2")) {  
    ATerror("Unsupported database type: %t", type);
    return NULL;
  }

  modname = ATmake("<str>", modulename);
  entry = MDB_EntryFromTerm(GetValue(modules_db, modname));
  if (!entry) {
    ATerror("Module %s not in database!", modulename);
    return NULL;
  }

  if (ATmatch(type, "eqs")) {
    path = makeAsfPath(MDB_getEntryPath(entry));
  }
  else {
    path = MDB_getEntryPath(entry);
  }
  if (pathAvailable(path)) {
    return ATmake("snd-value(path(<str>))", path);
  }
  else {
    /* found an empty equation section. Return empty path */
    return ATmake("snd-value(path(<str>))", "");
  }
  /* we never get here */
  ATerror("Error in get_path");
  return NULL;
}

/*}}}  */
/*{{{  ATerm get_asfix(int cid, char *modulename, ATerm type) */

ATerm get_asf_tree(int cid, char *modulename)
{
  MDB_Entry entry;
  ATerm tree;
  ATerm modname;
 
  modname = ATmake("<str>", modulename);
 
  entry = MDB_EntryFromTerm(GetValue(modules_db, modname));
  if (!entry) {
    ATwarning("Module %s not in database!", modulename);
    return ATmake("snd-value(asfix(unavailable))");
  }
 
  tree = MDB_getEntryAsfTree(entry);
 
  if (ATisEqual(tree, MDB_NONE)) {
    return ATmake("snd-value(asfix(unavailable))");
  }
  else {
    return ATmake("snd-value(asfix(tree(<term>)))", ATBpack(tree));
  }
}

ATerm get_sdf_tree(int cid, char *modulename)
{
  MDB_Entry entry;
  ATerm tree;
  ATerm modname;

  modname = ATmake("<str>", modulename);

  entry = MDB_EntryFromTerm(GetValue(modules_db, modname));
  if (!entry) {
    ATwarning("Module %s not in database!", modulename);
    return ATmake("snd-value(asfix(unavailable))");
  }

  tree = MDB_getEntrySdfTree(entry);

  if (ATisEqual(tree, MDB_NONE)) {
    return ATmake("snd-value(asfix(unavailable))");
  }
  else {
    return ATmake("snd-value(asfix(syntax(<term>)))", ATBpack(tree));
  }
}

/*}}}  */
/*{{{  ATerm get_parse_table(int cid, ATerm moduleId) */

ATerm get_parse_table(int cid, ATerm moduleId)
{
  MDB_Entry entry;
  ATerm     table, modname;
  ATerm     contents, result;
  char      *moduleName;
  char      *path, pathExt[9], *newpath;
  int       strLen;

  if (ATmatch(moduleId, "eqs(<str>)", &moduleName)) {
    strcpy(pathExt, ".asf.tbl");
  } 
  else if (ATmatch(moduleId, "trm(<str>)", &moduleName))  {
    strcpy(pathExt, ".trm.tbl");
  }
  else {
    ATwarning("Illegal moduleId: %t\n", moduleId);
    return ATmake("snd-value(no-table)");
  }
    
  modname = ATmake("<str>", moduleName);
  entry = MDB_EntryFromTerm(GetValue(modules_db, modname));
  if (MDB_isValidEntry(entry)) {
    if (ATmatch(moduleId, "eqs(<str>)", &moduleName)) {
      table = MDB_getEntryAsfTable(entry);
    }
    else {
      table = MDB_getEntryTrmTable(entry);
    }
    path = MDB_getEntryPath(entry);
    if (pathAvailable(path)) {
      strLen = strlen(path);
      newpath = malloc(strLen+5);
      strncpy(newpath, path, strLen-4);
      strcpy(newpath+strLen-4, pathExt);
      if (!ATisEqual(table, MDB_NONE)) {
        ATermAppl dummy = (ATermAppl)ATBpack(ATmake("dummy"));
        contents = (ATerm)ATgetArgument((ATermAppl)table, 0);
        contents = (ATerm)ATmakeAppl1(ATgetAFun(dummy), contents);
        result = ATmake("snd-value(table(<term>,<str>))", contents, newpath);
        free(newpath);
        return result;
      }
      free(newpath);
    }
  }
  return ATmake("snd-value(no-table)");
}

/*}}}  */
/*{{{  void mdb_invalidate_parse_tables(ATermList visited, char *modulename) */
/* This function traverses the import graph and visit all nodes
 * to check whether the parse tables are still valid and 
 * invalidates the parse table and "removes" the parse
 * tree of the equations section if necessary.
 */

static void 
mdb_invalidate_parse_tables(ATermList visited, char *modulename)
{
  int timeOfEqsTable, timeOfTrmTable;
  char *imported_modulename;
  ATermList imports;
  ATerm import,modname;
  MDB_Entry entry;

  modname = ATmake("<str>",modulename);
  entry = MDB_EntryFromTerm(GetValue(modules_db, modname));
  if(entry) {
    timeOfEqsTable = MDB_getEntryAsfTableCreationTime(entry);
    timeOfTrmTable = MDB_getEntryTrmTableCreationTime(entry);

    if(ATindexOf(visited, modname, 0) < 0) {
      if(!is_valid_parse_table(ATempty, modname, 
                               timeOfEqsTable, timeOfTrmTable)) {
        entry = MDB_setEntryAsfTable(entry, MDB_NONE);
        entry = MDB_setEntryTrmTable(entry, MDB_NONE);
        entry = MDB_setEntryAsfTree(entry, MDB_NONE);
        PutValue(modules_db, modname, MDB_EntryToTerm(entry));
      }
      visited = ATinsert(visited, modname);
      imports = (ATermList)GetValue(import_db, modname);
      while (imports && !ATisEmpty(imports)) {
        import = ATgetFirst(imports);
	imported_modulename = ATgetName(ATgetAFun(import));
        mdb_invalidate_parse_tables(visited, imported_modulename);
        imports = ATgetNext(imports);
      }
    }
  }
}

/*}}}  */
/*{{{  void invalidate_parse_tables(int cid, char *modulename) */

void invalidate_parse_tables(int cid, char *modulename)
{
  mdb_invalidate_parse_tables(ATempty,modulename);
}

/*}}}  */
/*{{{  ATerm delete_module(int cid, char *moduleName) */
/* If a module is delete a list of depending modules
 * should be calculated and returned.
 */

ATerm delete_module(int cid, char *moduleName)
{
  ATerm name = ATmake("<str>",moduleName);
  ATermList changedMods;

  changedMods = modules_depend_on(name,ATempty);
  update_syntax_status_of_modules(changedMods); 
  RemoveKey(modules_db,name);
  RemoveKey(import_db,name);
  RemoveKey(full_import_db,name);
  reset_trans_db();
  reset_eqs_db();
  return ATmake("snd-value(changed-modules([<term>,<list>]))",
                name, changedMods);
}

/*}}}  */
/*{{{  ATerm rename_module(int cid, char *oldModuleName, char *newModuleName) */
/* If a module is renamed a new import graph should be returned.
 */

static ATermList
rename_modulename_in_modules(ATermList mods,
                             char *oldModuleName, 
                             char *newModuleName)
{
  ATerm oldSdfTree, newSdfTree;
  MDB_Entry entry;
  PT_ParseTree oldParseTree, newParseTree;
  PT_Tree oldTree, newTree;
  SDF_Module oldSdfModule, newSdfModule;
  ATerm modName;
  ATermList unknowns, imports, changedMods = ATempty;
  SDF_ImportList fullImports;
 
  SDF_ModuleId oldName = SDFmakeModuleId(oldModuleName);
  SDF_ModuleId newName = SDFmakeModuleId(newModuleName);

  while (!ATisEmpty(mods)) {
    modName = ATgetFirst(mods);
    entry = MDB_EntryFromTerm(GetValue(modules_db, modName));

    oldSdfTree   = MDB_getEntrySdfTree(entry);
    oldParseTree = PT_makeParseTreeFromTerm(oldSdfTree);
    oldTree      = PT_getParseTreeTree(oldParseTree);
    oldSdfModule = SDF_makeModuleFromTerm(PT_makeTermFromTree(oldTree));
    newSdfModule = rename_modulename_in_module(oldSdfModule, oldName, newName);
    if (!SDF_isEqualModule(oldSdfModule, newSdfModule)) {
      changedMods = ATinsert(changedMods, modName);
    }
    newTree      = PT_makeTreeFromTerm(SDF_makeTermFromModule(newSdfModule));
    newParseTree = PT_setParseTreeTree(oldParseTree, newTree);
    newSdfTree   = PT_makeTermFromParseTree(newParseTree);
    entry = MDB_setEntrySdfTree(entry, newSdfTree);

    PutValue(modules_db, modName, MDB_EntryToTerm(entry));

    imports = SDF_getImports(newSdfModule);
    fullImports = SDF_getModuleImportsList(newSdfModule);
    unknowns = replace_imports(modName, imports, fullImports);

    mods = ATgetNext(mods);
  }
  return changedMods;
}

/*}}}  */

static char *
changeSdfPath(char *path, char *oldModuleName, char *newModuleName)
{
  static char newPath[BUFSIZ];  
  int len;

  len = strlen(path) - strlen(oldModuleName) - strlen(".sdf");
  strncpy(newPath, path, len);
  strcpy(newPath+len, newModuleName);
  strcpy(newPath+len+strlen(newModuleName), ".sdf");

  return newPath;
}

static ATbool checkModuleName(const char *moduleName)  
{
  int i;
  int len = strlen(moduleName);

  for (i = 0; i < len; i++) {
    if (!isalnum(moduleName[i]) 
        && moduleName[i] != '-'  
        && moduleName[i] != '_') {
      return ATfalse;
    }
  }
  return ATtrue;
}

ATerm rename_module(int cid, char *oldModuleName, char *newModuleName)
{
  char *path; 
  char *newPath;
  ATerm oldSdfTree, newSdfTree, import_graph;
  ATerm oldName = ATmake("<str>", oldModuleName);
  ATerm newName = ATmake("<str>", newModuleName);
  ATermList changedMods;
  MDB_Entry entry;
  PT_ParseTree oldParseTree, newParseTree;
  PT_Tree oldTree, newTree;
  SDF_Module oldSdfModule, newSdfModule;
  ATermList unknowns, imports;
  SDF_ImportList fullImports;

  if (!checkModuleName(newModuleName)) {
    return ATmake("snd-value(illegal-module-name(<str>))", newModuleName);
  }

  changedMods = modules_depend_on(oldName, ATempty);
  update_syntax_status_of_modules(changedMods); 
  changedMods =
    rename_modulename_in_modules(changedMods, oldModuleName, newModuleName);

  entry = MDB_EntryFromTerm(GetValue(modules_db, oldName));
  if (entry) {
    oldSdfTree   = MDB_getEntrySdfTree(entry);
    oldParseTree = PT_makeParseTreeFromTerm(oldSdfTree);
    oldTree      = PT_getParseTreeTree(oldParseTree);
    oldSdfModule = SDF_makeModuleFromTerm(PT_makeTermFromTree(oldTree));
    newSdfModule = SDFsetModuleName(oldSdfModule, newModuleName);
    newTree      = PT_makeTreeFromTerm(SDF_makeTermFromModule(newSdfModule));
    newParseTree = PT_setParseTreeTree(oldParseTree, newTree);
    newSdfTree   = PT_makeTermFromParseTree(newParseTree);

    entry = MDB_setEntrySdfTree(entry, newSdfTree);

    path    = MDB_getEntryPath(entry); 
    newPath = changeSdfPath(path, oldModuleName, newModuleName);
    entry   = MDB_setEntryPath(entry, newPath);

    entry = MDB_setEntryAsfTable(entry, MDB_NONE);
    entry = MDB_setEntryTrmTable(entry, MDB_NONE);
    entry = MDB_setEntryAsfTree(entry, MDB_NONE);
    PutValue(modules_db, newName, MDB_EntryToTerm(entry));

    RemoveKey(modules_db, oldName);
    RemoveKey(import_db, oldName);

    imports = SDF_getImports(newSdfModule);
    fullImports = SDF_getModuleImportsList(newSdfModule);
    unknowns = add_imports(newName, imports, fullImports);

    reset_trans_db();
    reset_eqs_db();
  }
  import_graph = calc_import_graph();
  return ATmake("snd-value(imports(changed-modules([<list>]),<term>))",
                changedMods, import_graph);
}

/*}}}  */
/*{{{  ATermList select_unknowns(ATermList mods) */

static ATermList 
select_unknowns(ATermList mods)
{
  ATermList result = ATempty;

  while(!ATisEmpty(mods)) {
    ATerm mod = ATgetFirst(mods);
    
    if (!GetValue(import_db,mod)) {
      if (ATindexOf(result, mod, 0) < 0) {
        result = ATappend(result,mod);
      }
    }
    mods = ATgetNext(mods);
  }
  return result;
}

/*}}}  */
/*{{{  ATermList add_imports(ATerm name, ATermList mods) */

static ATermList 
add_imports(ATerm name, ATermList mods, SDF_ImportList imports)
{
  ATermList unknowns = ATempty;

  reset_trans_db();
  reset_eqs_db();
  if (!GetValue(import_db,name)) {
    PutValue(import_db, name, (ATerm) mods);
    PutValue(full_import_db, name, SDF_makeTermFromImportList(imports));
    unknowns = select_unknowns(mods);
  }
  return unknowns;
}

/*}}}  */
/*{{{  ATermList replace_imports(ATerm name, ATermList mods) */

static ATermList 
replace_imports(ATerm name, ATermList mods, SDF_ImportList imports)
{
  reset_trans_db();
  reset_eqs_db();
  ATtableRemove(import_db, name);
  PutValue(import_db, name, (ATerm) mods);
  PutValue(full_import_db, name, SDF_makeTermFromImportList(imports));
  return select_unknowns(mods);
}

/*}}}  */
/*{{{  ATbool complete_sdf2_specification(ATermList visited, ATerm module) */

static ATbool 
complete_sdf2_specification(ATermList visited, ATerm module)
{
  MDB_Entry entry;
  ATerm asfix;

  if(ATindexOf(visited, module, 0) < 0) {
    entry = MDB_EntryFromTerm(GetValue(modules_db, module));
    if(entry) {
      asfix = MDB_getEntrySdfTree(entry);
      if(!ATisEqual(asfix, MDB_NONE)) {
	ATerm first;
	ATbool result = ATtrue;
	ATermList imports = (ATermList)GetValue(import_db,module);
	
	visited = ATinsert(visited,module);
	while(!ATisEmpty(imports) && result) {
	  first = ATgetFirst(imports);
	  result = complete_sdf2_specification(visited,first);
	  imports = ATgetNext(imports);
	}
	return result;
      }
      else {
	ATwarning("Sdf2: %t is missing\n", module);
	return ATfalse;
      }
    } 
    else {
      ATwarning("Sdf2: %t is missing\n", module);
      return ATfalse;
    }
  }
  else
    return ATtrue;
}

/*}}}  */
/*{{{  ATbool is_valid_parse_table(ATermList visited, ATerm module,...)  */

static ATbool 
is_valid_parse_table(ATermList visited, ATerm module, 
			    int timeOfEqsTable, int timeOfTrmTable)
{
  ATbool result;
  ATermList imports;
  ATerm first;
  MDB_Entry entry;
  int time;

  entry = MDB_EntryFromTerm(GetValue(modules_db, module));

  if (entry == NULL) {
    return ATfalse;
  }

  time = MDB_getEntrySdfTreeCreationTime(entry);

  if((timeOfEqsTable > 0 && time > timeOfEqsTable) ||
     (timeOfTrmTable > 0 && time > timeOfTrmTable)) {
    result = ATfalse;
  } else {
    result = ATtrue;
  }

  if (ATindexOf(visited, module, 0) < 0) {
    imports = (ATermList)GetValue(import_db,module);
    visited = ATinsert(visited, module);
    while(imports && !ATisEmpty(imports)) {
      first = ATgetFirst(imports);

      entry = MDB_EntryFromTerm(GetValue(modules_db, first));

      if (entry == NULL) {
	return ATfalse;
      }

      if (MDB_isValidEntry(entry)) {
	timeOfEqsTable = MDB_getEntryAsfTableCreationTime(entry);
	timeOfTrmTable = MDB_getEntryTrmTableCreationTime(entry);

	result = result && is_valid_parse_table(visited, first, 
						timeOfEqsTable, timeOfTrmTable);
	imports = ATgetNext(imports);
      } else {
	return ATfalse;
      }
    }
  }

  return result;
} 

/*}}}  */
/*{{{  ATbool complete_asf_specification(ATermList visited, ATerm module) */

static ATbool 
complete_asf_specification(ATermList visited, ATerm module)
{
  ATerm first;
  MDB_Entry entry;
  ATerm EqsTree;
  ATerm EqsText;
  ATbool result;
  ATermList imports;

  if(ATindexOf(visited, module, 0) < 0) { 
    result = ATtrue;
    imports = (ATermList)GetValue(import_db,module);

    if (imports == NULL) {
      return ATfalse;
    }

    visited = ATinsert(visited,module); 
    
    while (!ATisEmpty(imports) && result) {
      first = ATgetFirst(imports);

      entry = MDB_EntryFromTerm(GetValue(modules_db, first));

      if (entry == NULL) {
	 return ATfalse;
      }

      if (MDB_isValidEntry(entry)) {
        EqsTree = MDB_getEntryAsfTree(entry);
        EqsText = MDB_getEntryAsfText(entry);
        if (ATisEqual(EqsTree, MDB_NONE) &&
            !ATisEqual(EqsText, MDB_NONE)) {
          result = ATfalse;
        }
        else {
          result = complete_asf_specification(visited,first);
          imports = ATgetNext(imports);
        }
      }
      else {
        result = ATfalse;
      }
    }
    return result;
  }
  else
    return ATtrue;
}

/*}}}  */
/*{{{  ATbool complete_asf_sdf2_specification(ATerm module) */

ATbool complete_asf_sdf2_specification(ATerm module)
{
  if(complete_sdf2_specification(ATempty,module))
    return complete_asf_specification(ATempty, module);
  else
    return ATfalse;
}

/*}}}  */
/*{{{  ATerm eqs_available_for_modules(int cid, char *moduleName) */

ATerm eqs_available_for_modules(int cid, char *moduleName)
{
  ATerm module;
  MDB_Entry entry;
  ATerm eqsText;
  ATerm eqsTree;
  ATerm atModuleName;
  ATermList result = ATempty;
  ATermList modules;

  atModuleName = ATmake("<str>",moduleName);
  entry = MDB_EntryFromTerm(GetValue(modules_db, atModuleName));

  if (entry != NULL && MDB_isValidEntry(entry)) {
    /* Get all imported modules (including the module itself) */
    modules = get_imported_modules(moduleName);

    modules = ATreverse(modules);
    while (!ATisEmpty(modules)) {
      module = SDF_getModuleNamePlain(
                 SDF_getImportModuleName(
                   SDF_makeImportFromTerm(ATgetFirst(modules)))); 
      entry = MDB_EntryFromTerm(GetValue(modules_db, module));
      eqsText = MDB_getEntryAsfText(entry);
      eqsTree = MDB_getEntryAsfTree(entry);
      if (ATisEqual(eqsTree, MDB_NONE) &&
	  !ATisEqual(eqsText, MDB_NONE)) {
        result = ATinsert(result, module);
      }
      modules = ATgetNext(modules);
    }
  }
  return ATmake("snd-value(modules([<list>]))",result);
}

/*}}}  */
/*{{{  ATerm get_eqs_text(int cid, char *moduleName) */

ATerm get_eqs_text(int cid, char *moduleName)
{
  ATerm eqsText;
  ATerm atName;
  MDB_Entry entry;

  atName = ATmake("<str>",moduleName);
  
  entry = MDB_EntryFromTerm(GetValue(modules_db, atName));

  if (entry != NULL) {
    eqsText = MDB_getEntryAsfText(entry);

    if (!ATisEqual(eqsText, MDB_NONE)) {
      return ATmake("snd-value(eqs-text(<str>,<term>))", moduleName, eqsText);
    } 
  }

  return ATmake("snd-value(no-eqs-text(<str>))", moduleName);
}

/*}}}  */
/*{{{  ATerm get_all_modules(int cid) */

ATerm get_all_modules(int cid)
{
  ATermList list = ATtableKeys(import_db);

  return ATmake("snd-value(all-modules([<list>]))",list);
}

/*}}}  */
/*{{{  ATerm get_all_depending_modules(int cid, char *moduleName) */

ATerm get_all_depending_modules(int cid, char *moduleName)
{
  ATerm atModuleName = ATmake("<str>", moduleName);
  ATermList modules = modules_depend_on(atModuleName, ATempty);

  return ATmake("snd-value(all-depending-modules([<list>]))", modules);
}

/*}}}  */
/*{{{  ATermList modules_depend_on(ATerm name, ATermList dependent) */
/* The function "module_depend_on" determines which modules
   depend on the module "name" with respect to the import graph. */

static ATermList 
modules_depend_on(ATerm name, ATermList dependent)
{  
  ATerm module;
  ATermList result = ATempty;
  ATermList modules = ATtableKeys(import_db);

  while (!ATisEmpty(modules)) {
    module = ATgetFirst(modules);
    if (ATindexOf((ATermList)GetValue(import_db,module), name, 0) >= 0) {
      if(ATindexOf(result, module, 0) < 0)
        result = ATinsert(result, module);
    };
    modules = ATgetNext(modules);
  }

  while(!ATisEmpty(result)) {
    module = ATgetFirst(result);
    if(ATindexOf(dependent, module, 0) < 0) { 
      dependent = ATinsert(dependent, module);
      dependent = modules_depend_on(module,dependent);
    }
    result = ATgetNext(result);
  }
  return dependent;
}

/*}}}  */
/*{{{  ATerm get_syntax(ATerm name, ATermList modules) */

SDF_SDF 
getSyntax(ATermList modules)
{
  SDF_ModuleList  sdfModules = NULL;
  SDF_Definition  sdfDefinition;

  if (ATisEmpty(modules)) {
    sdfModules = SDF_makeModuleListEmpty();
  } 
  else {
    while (!ATisEmpty(modules)) {
      ATerm head = SDF_getModuleNamePlain(
                     SDF_getImportModuleName(
                       SDF_makeImportFromTerm(ATgetFirst(modules)))); 
      MDB_Entry entry = MDB_EntryFromTerm(GetValue(modules_db, head));
      ATerm module = MDB_getEntrySdfTree(entry);
      PT_ParseTree parseTree = PT_makeParseTreeFromTerm(module);
      PT_Tree tree = PT_getParseTreeTree(parseTree);
      SDF_Module sdfModule = SDF_makeModuleFromTerm(PT_makeTermFromTree(tree));

      if (sdfModules == NULL) {
	sdfModules = SDF_makeModuleListSingle(sdfModule);
      } else {
	sdfModules = SDF_makeModuleListMany(sdfModule,
                                            SDF_makeLayoutEmpty(),
                                            sdfModules);
      }

      modules = ATgetNext(modules);
    }
  }
  sdfDefinition = SDF_makeDefinitionDefault(sdfModules);

  return SDF_makeSDFDefinition(SDF_makeLayoutEmpty(), sdfDefinition);
}

/*}}}  */
/*{{{  ATerm get_all_sdf2_definitions(int cid, char *modulename) */

ATerm get_all_sdf2_definitions(int cid, char *moduleName)
{
  SDF_SDF definition;
  ATerm name;
  ATermList imports;
  PT_ParseTree parseTree;
  PT_Tree sdfTree;
  ATerm result;
  PT_Symbol sort;
  PT_Symbols symbols;

  name = ATmake("<str>", moduleName);
  if (complete_sdf2_specification(ATempty, name)) {
    imports = get_imported_modules(moduleName);
    definition = getSyntax(imports);
    sdfTree = PT_makeTreeFromTerm(SDF_makeTermFromSDF(definition));
    sort = PT_makeSymbolCf(PT_makeSymbolSort("SDF"));
    symbols = PT_makeSymbolsList(sort, PT_makeSymbolsEmpty());
    parseTree = PT_makeParseTreeTree(symbols, 
                                     PT_makeTreeLayoutEmpty(),
                                     sdfTree,
                                     PT_makeTreeLayoutEmpty(), 0);
    result = PT_makeTermFromParseTree(parseTree);
    return ATmake("snd-value(syntax(<term>))", ATBpack(result));
  }
  else {
    return ATmake("snd-value(sdf2-definition-error(\"Specification is incomplete, can not generate parse table\"))");
  }
}

/*}}}  */
/*{{{  ATerm get_module_info(int cid, char *moduleName) */

ATerm get_module_info(int cid, char *moduleName)
{
  ATerm atName;
  char *path;

  atName = ATmake("<str>", moduleName);
  
  path = MDB_getEntryPath(MDB_EntryFromTerm(GetValue(modules_db, atName)));
  if (pathAvailable(path)) {
    return ATmake("snd-value(module-info(<str>, path(<str>)))", 
                  moduleName,path);
  }
  else {
    return ATmake("snd-value(no-module-info(<str>))", moduleName);
  }
}

/*}}}  */
/*{{{  void usage(char *prg, ATbool is_err) */

static void 
usage(char *prg, ATbool is_err)
{
    ATwarning("usage: %s [aterm-options] [toolbus-options]\n", prg);
    ATwarning("use '%s -at-help' to get more options.\n", prg);
    ATwarning("This program can only be used as a ToolBus tool!\n");
    exit(is_err ? 1 : 0);
}

/*}}}  */
/*{{{  void version(const char *msg) */

static void 
version(const char *msg)
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
  ASF_initASFMEApi();
  MDB_initMDBApi();

  MDB_NONE = ATparse("unavailable");
  ATprotect(&MDB_NONE);

  cid = ATBconnect(NULL, NULL, -1, module_db_handler);

  ATBeventloop();

  return 0;
}

/*}}}  */
