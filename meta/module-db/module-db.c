/*
  $Id$
 */
/*{{{  includes */

#include <assert.h>

#include "module-db.h"
#include "module-refactorings.h"
#include "MDB.h"

/*}}}  */
/*{{{  variables */

static char myversion[] = "3.1beta";

static ATermTable modules_db;
static ATermTable import_db;
static ATermTable full_import_db;
static ATermTable trans_db;

static ATerm MDB_NONE;

static char *syntax_ext;
static char *rules_ext;
static char *term_ext;

#define TBL_EXT ".tbl"

/* adding position info can stop at the condition level */
#define DEPTH_OF_EQUATIONS   4

/*}}}  */

/*{{{  Forward declarations */

static ATbool all_rules_available(ATermList visited, ATerm module);
static ATermList add_imports(ATerm name, ATermList mods, SDF_ImportList imports);
static ATermList replace_imports(ATerm name, ATermList mods, SDF_ImportList imports);
static ATermList modules_depend_on(ATerm name, ATermList mods);
static ATbool is_valid_parse_table(ATermList visited, ATerm module, 
				   int timeOfEqsTable, int timeOfTrmTable);
static ATbool checkModuleNameWithPath(const char *moduleName, const char *path);
static ATbool checkModuleName(const char *moduleName); 
/*}}}  */

/*{{{  static void strip_syntax_ext(char *name) */

static void strip_syntax_ext(char *name)
{
  if (!strcmp(name+strlen(name)-strlen(syntax_ext),
	      syntax_ext)) {
    name[strlen(name)-strlen(syntax_ext)] = '\0';
  }
}

/*}}}  */

/*{{{  void rec_terminate(int cid, ATerm t) */

void rec_terminate(int cid, ATerm t)
{
  exit(0);
}

/*}}}  */
/*{{{  void set_file_extensions(int cid, char *syntaxExt, char *ruleExt, char *termExt) */

void set_file_extensions(int cid, char *syntaxExt, char *rulesExt, char *termExt)
{
  syntax_ext = (char *) malloc(strlen(syntaxExt) + 1);
  if (syntax_ext == NULL) {
    ATerror("set_file_extensions: out of memory.\n");
  }
  strcpy(syntax_ext, syntaxExt);
  rules_ext = (char *) malloc(strlen(rulesExt) + 1);
  if (rules_ext == NULL) {
    ATerror("set_file_extensions: out of memory.\n");
  }
  strcpy(rules_ext, rulesExt);
  term_ext = (char *) malloc(strlen(termExt) + 1);
  if (term_ext == NULL) {
    ATerror("set_file_extensions: out of memory.\n");
  }
  strcpy(term_ext, termExt);
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
/*{{{  static ATbool pathAvailable(const char *path) */

static ATbool pathAvailable(const char *path)
{
  return strcmp(path, "unavailable");
}

/*}}}  */
/*{{{  static char *makeAsfPath(const char *path) */

static char *
makeAsfPath(const char *path)
{
  static char newPath[BUFSIZ];
  int len;

  if (pathAvailable(path)) {
    len = strlen(path) - strlen(syntax_ext);
    strncpy(newPath, path, len);
    strcpy(newPath+len, rules_ext);
  }
  else {
    strcpy(newPath, path);
  }

  return newPath;
}

/*}}}  */
/*{{{  static ATermList calc_trans(SDF_ImportList todo) */

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
    SDF_Module     sdfModule;

    if (ATindexOf(result, atImport, 0) < 0) {
      MDB_Entry entry = MDB_EntryFromTerm(GetValue(modules_db, name));
      if (entry) {
        fullImports = SDF_makeImportListFromTerm(
                        GetValue(full_import_db, name));

        if (SDF_isModuleNameParameterized(moduleName)) {
          sdfTerm = MDB_getEntrySdfTree(entry);
	  sdfModule = SDF_getStartTopModule(SDF_StartFromTerm(sdfTerm));

          fullImports = renameParametersInImportList(moduleName, 
                                                     sdfModule, 
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
ATermList get_imported_modulenames(char *name)
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

ATerm get_imported_modules(int cid, char *moduleName)
{
  MDB_Entry entry = NULL;
  ATermList result = ATempty;
  ATerm modname;
  SDF_Module mod;

  modname = ATmake("<str>", moduleName);

  entry = MDB_EntryFromTerm(GetValue(modules_db, modname));
  if (!entry) {
    ATwarning("Module %s not in database!", moduleName);
  }
  else {
    mod = SDF_getStartTopModule(SDF_StartFromTerm(MDB_getEntrySdfTree(entry)));
    result = SDF_getImports(mod);
  }

  return ATmake("snd-value(imported-modules([<list>]))", result);

}

/*}}}  */ 
/*{{{  ATerm get_all_imported_modules(int cid, char *moduleName) */
 
ATerm get_all_imported_modules(int cid, char *moduleName)
{
  ATermList imports = get_imported_modulenames(moduleName);
  return ATmake("snd-value(all-modules([<list>]))", imports);
}
 
/*}}}  */
/*{{{  ATerm all_equations_available(int cid, char *moduleName) */
 
ATerm all_equations_available(int cid, char *moduleName)
{
  ATerm name = ATmake("<str>", moduleName);
  ATbool missing = all_rules_available(ATempty, name);

  if (!missing) {
    return ATmake("snd-value(equations-available)");
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
/*{{{  void create_module_db(int cid) */

void create_module_db(int cid)
{
  modules_db = CreateValueStore(100,75);
  import_db = CreateValueStore(100,75);
  full_import_db = CreateValueStore(100,75);
  trans_db = CreateValueStore(100,75);
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
}

/*}}}  */
/*{{{  static ATerm calc_import_graph(void) */

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
  SDF_Module     sdfModule;
  SDF_ImportList fullImports;

  sdfModule = SDF_getStartTopModule(SDF_StartFromTerm(sdfTree));

  if (!checkModuleNameWithPath(SDFgetModuleName(sdfModule), path)) {
    return ATmake("snd-value(name-consistency-error(<str>))", moduleName);
  }

  modName = ATmake("<str>",  SDFgetModuleName(sdfModule));
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

  return ATmake("snd-value(module(<term>,imports(need-modules([<list>]),<term>)))", 
		modName, unknowns, import_graph);
}

/*}}}  */
/*{{{  static void update_syntax_status_of_modules(ATermList mods) */
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

ATerm update_sdf2_module(int cid, char *moduleName, ATerm newSdfTree)
{
  ATerm          curSdfTree, import_graph;
  MDB_Entry      entry;
  ATermList      imports, unknowns, chg_mods;
  SDF_Module     sdfModule;
  ATerm          modName;
  SDF_ImportList fullImports;
  char *newModuleName = NULL;

  sdfModule = SDF_getStartTopModule(SDF_StartFromTerm(
	      ATremoveAllAnnotations(newSdfTree)));
						     
  newModuleName = SDFgetModuleName(sdfModule);

  if (strcmp(moduleName, newModuleName)) {
    return ATmake("snd-value(name-consistency-error(<str>))", moduleName);
  }

  modName   = ATmake("<str>", newModuleName);
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
  sprintf(fileName,"%s%s", moduleName, syntax_ext);
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
/*{{{  ATerm update_eqs_text(int cid, char *moduleName, char *eqsText) */

ATerm update_eqs_text(int cid, char *moduleName, char *eqsText)
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

  return ATmake("snd-value(eqs-text-updated(<str>))", moduleName);
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
/*{{{  ATerm get_asf_tree(int cid, char *modulename) */

ATerm get_asf_tree(int cid, char *modulename)
{
  MDB_Entry entry;
  ATerm tree;
  ATerm modname;
 
  modname = ATmake("<str>", modulename);
 
  entry = MDB_EntryFromTerm(GetValue(modules_db, modname));
  if (!entry) {
    ATwarning("Module %s not in database!!", modulename);
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

/*}}}  */
/*{{{  ATerm get_equations_for_module(int cid, ATerm atImport) */

ATerm get_equations_for_module(int cid, ATerm atImport)
{
  SDF_Import import = SDF_makeImportFromTerm(atImport);

  SDF_ModuleName moduleName = SDF_getImportModuleName(import);
  ATerm plainName = SDF_getModuleNamePlain(moduleName);

  MDB_Entry entry = MDB_EntryFromTerm(GetValue(modules_db, plainName));

  if (entry) { 
    ATerm eqsTerm = MDB_getEntryAsfTree(entry);

    if (!ATisEqual(eqsTerm, MDB_NONE)) {
      SDF_Renamings renamings;
      SDF_ImportList fullImports;

      if (SDF_isImportRenamedModule(import)) {
	fullImports = SDF_makeImportListEmpty();
        renamings = SDF_getImportRenamings(import);
      } 
      else if (SDF_isModuleNameParameterized(moduleName)) {
        ATerm sdfTerm = MDB_getEntrySdfTree(entry);
	SDF_Module module = SDF_getStartTopModule(SDF_StartFromTerm(sdfTerm));
        SDF_ModuleName formalModuleName = SDF_getModuleModuleName(module);
        fullImports = SDF_getModuleImportsList(module);

	renamings = SDF_makeRenamingsFromModuleNames(formalModuleName,
						     moduleName);
      }
      else {
	return ATmake("snd-value(plain-equations(<term>))", ATBpack(eqsTerm));
      }

      return ATmake("snd-value(renaming-equations(<term>,<term>,<term>))", 
		    SDF_makeTermFromRenamings(renamings),
		    SDF_makeTermFromImportList(fullImports),
		    ATBpack(eqsTerm));
    }
  }

  return ATmake("snd-value(no-equations)");
}

/*}}}  */
/*{{{  ATerm get_equations_for_renamed_import(int cid, ATerm atImport, ATerm atRenamings) */

ATerm get_equations_for_renamed_import(int cid, ATerm atImport, ATerm atRenamings)
{
  SDF_Import import = SDF_makeImportFromTerm(atImport);
  SDF_Renamings renamings = SDF_makeRenamingsFromTerm(atRenamings);

  if (SDF_isValidImport(import)) {
    SDF_ModuleName moduleName = SDF_getImportModuleName(import);

    ATerm plainName = SDF_getModuleNamePlain(moduleName);

    MDB_Entry entry = MDB_EntryFromTerm(GetValue(modules_db, plainName));

    if (entry) { 
      ATerm eqsTerm = MDB_getEntryAsfTree(entry);

      if (!ATisEqual(eqsTerm, MDB_NONE)) {
        SDF_Renamings newRenamings;
        SDF_ImportList fullImports;

        if (SDF_isImportRenamedModule(import)) {
          fullImports = SDF_makeImportListEmpty();
          newRenamings = SDF_getImportRenamings(import);
          newRenamings = SDF_renameRenamings(renamings, newRenamings);
        } 
        else if (SDF_isModuleNameParameterized(moduleName)) {
          ATerm sdfTerm = MDB_getEntrySdfTree(entry);
	  SDF_Module module = SDF_getStartTopModule(SDF_StartFromTerm(sdfTerm));
          SDF_ModuleName formalModuleName = SDF_getModuleModuleName(module);

          fullImports = SDF_getModuleImportsList(module);
	  newRenamings = SDF_makeRenamingsFromModuleNames(formalModuleName,
	  					       moduleName);
          newRenamings = SDF_renameRenamings(renamings, newRenamings);
        }
        else {
	  return ATmake("snd-value(no-equations))");
        }
        return ATmake("snd-value(renamed-equations(<term>,<term>,<term>))", 
		     SDF_makeTermFromRenamings(newRenamings),
		     SDF_makeTermFromImportList(fullImports),
		     ATBpack(eqsTerm));
      }
    }
  }

  return ATmake("snd-value(no-equations)");
}

/*}}}  */
/*{{{  ATerm get_sdf_tree(int cid, char *modulename) */

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
  int       strLen, lenExtension, lenType;

  if (ATmatch(moduleId, "eqs(<str>)", &moduleName)) {
    strcpy(pathExt, rules_ext);
    lenType = strlen(rules_ext);
    strcpy(pathExt+strlen(rules_ext), TBL_EXT);
  } 
  else if (ATmatch(moduleId, "trm(<str>)", &moduleName))  {
    strcpy(pathExt, term_ext);
    lenType = strlen(term_ext);
    strcpy(pathExt+strlen(term_ext), TBL_EXT);
  }
  else {
    ATwarning("Illegal moduleId: %t\n", moduleId);
    return ATmake("snd-value(no-table)");
  }
    
  modname = ATmake("<str>", moduleName);
  entry = MDB_EntryFromTerm(GetValue(modules_db, modname));
  if (entry && MDB_isValidEntry(entry)) {
    if (ATmatch(moduleId, "eqs(<str>)", &moduleName)) {
      table = MDB_getEntryAsfTable(entry);
    }
    else {
      table = MDB_getEntryTrmTable(entry);
    }
    path = MDB_getEntryPath(entry);
    if (pathAvailable(path)) {
      strLen = strlen(path);
      lenExtension = strlen(pathExt);
      newpath = malloc(strLen+lenExtension+1);
      strncpy(newpath, path, strLen-lenType);
      strcpy(newpath+strLen-lenType, pathExt);

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
/*{{{  static void mdb_invalidate_parse_tables(ATermList visited, char *modulename) */
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
 /*{{{  delete_modulename_from_modules(ATermList mods, char *oldModuleName)  */

static ATermList delete_modulename_from_modules(ATermList mods, 
						char *oldModuleName) 
{
  ATerm oldSdfTree, newSdfTree;
  MDB_Entry entry;
  SDF_Module oldSdfModule, newSdfModule;
  ATerm modName;
  ATermList unknowns, imports, changedMods = ATempty;
  SDF_ImportList fullImports;
 
  SDF_ModuleId oldName = SDFmakeModuleId(oldModuleName);

  while (!ATisEmpty(mods)) {
    modName = ATgetFirst(mods);
    entry = MDB_EntryFromTerm(GetValue(modules_db, modName));

    oldSdfTree   = MDB_getEntrySdfTree(entry);
    oldSdfModule = SDF_getStartTopModule(SDF_StartFromTerm(oldSdfTree));
    newSdfModule = delete_modulename_from_module(oldSdfModule, oldName);
    
    if (!SDF_isEqualModule(oldSdfModule, newSdfModule)) {
      changedMods = ATinsert(changedMods, modName);
    }

    newSdfTree   = SDF_StartToTerm(SDF_setStartTopModule(
		     SDF_StartFromTerm(oldSdfTree), newSdfModule));
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
/*{{{  ATerm delete_module(int cid, char *moduleName) */
/* If a module is delete a list of depending modules
 * should be calculated and returned.
 */

ATerm delete_module(int cid, char *moduleName)
{
  ATerm name = ATmake("<str>",moduleName);
  ATermList changedMods, tmp;

  changedMods = modules_depend_on(name,ATempty);
  changedMods =
    delete_modulename_from_modules(changedMods, moduleName);

  /* remove the module itself from the list of changed modules */
  for(tmp=ATempty; !ATisEmpty(changedMods); 
      changedMods = ATgetNext(changedMods)) {
    ATerm head = ATgetFirst(changedMods);
    if (!ATisEqual(name, head)) {
      tmp = ATinsert(tmp, head);
    }
  }
  changedMods = tmp;

  update_syntax_status_of_modules(changedMods); 

  RemoveKey(modules_db,name);
  RemoveKey(import_db,name);
  RemoveKey(full_import_db,name);
  reset_trans_db();

  return ATmake("snd-value(changed-modules([<list>]))", changedMods);
}

/*}}}  */
/*{{{  static ATermList rename_modulename_in_modules(ATermList mods, ... */
/* If a module is renamed a new import graph should be returned.
 */

static ATermList
rename_modulename_in_modules(ATermList mods,
                             char *oldModuleName, 
                             char *newModuleName)
{
  ATerm oldSdfTree, newSdfTree;
  MDB_Entry entry;
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
    oldSdfModule = SDF_getStartTopModule(SDF_StartFromTerm(oldSdfTree));
    newSdfModule = rename_modulename_in_module(oldSdfModule, oldName, newName);
    if (!SDF_isEqualModule(oldSdfModule, newSdfModule)) {
      changedMods = ATinsert(changedMods, modName);
    }
    newSdfTree = SDF_StartToTerm(SDF_setStartTopModule(
		  SDF_StartFromTerm(oldSdfTree), newSdfModule));
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
/*{{{  static char *changeSdfPath(char *path, char *oldModuleName, char *newModuleName) */

char *
changeSdfPath(char *path, char *oldModuleName, char *newModuleName)
{
  static char newPath[BUFSIZ];  
  int len;

  len = strlen(path) - strlen(oldModuleName) - strlen(syntax_ext);
  strncpy(newPath, path, len);
  strcpy(newPath+len, newModuleName);
  strcpy(newPath+len+strlen(newModuleName), syntax_ext);

  return newPath;
}

/*}}}  */
/*{{{  static ATbool checkModuleNameWithPath(const char *moduleName, const char *path) */

static ATbool checkModuleNameWithPath(const char *moduleName, const char *path)
{
  int i,j;
  int pathlen = strlen(path);
  int namelen = strlen(moduleName);

  /* first skip extension (may not use knowledge of which extension it is) */
  for(i=pathlen - 1; i >= 0 && path[i] != '.'; i --);

  for(j=namelen - 1, --i; i >= 0 && j >= 0; i--, j--) {
    if (moduleName[j] != path[i]) {
      return ATfalse;
    }
    if (!isalnum(moduleName[j]) 
	&& moduleName[j] != '-'
	&& moduleName[j] != '_'
	&& moduleName[j] != '/') {
      return ATfalse;
    }
  }

  return ATtrue;
}

/*}}}  */
/*{{{  static ATbool checkModuleName(const char *moduleName)   */

static ATbool checkModuleName(const char *moduleName)  
{
  int i;
  int len = strlen(moduleName);

  for (i = 0; i < len; i++) {
    if (!isalnum(moduleName[i]) 
        && moduleName[i] != '-'  
        && moduleName[i] != '_'
	&& moduleName[i] != '/') {
      return ATfalse;
    }
  }
  return ATtrue;
}

/*}}}  */
/*{{{  ATerm rename_module(int cid, char *oldModuleName, char *newModuleName) */

ATerm rename_module(int cid, char *oldModuleName, char *newModuleName, 
		    char *newPath)
{
  char path[BUFSIZ]; 
  ATerm oldSdfTree, newSdfTree, import_graph;
  ATerm oldName = ATmake("<str>", oldModuleName);
  ATerm newName;
  ATermList changedMods;
  MDB_Entry entry;
  SDF_Module oldSdfModule, newSdfModule;
  ATermList unknowns, imports;
  SDF_ImportList fullImports;

  newName = ATmake("<str>", newModuleName);

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
    oldSdfModule = SDF_getStartTopModule(SDF_StartFromTerm(oldSdfTree));
    newSdfModule = SDFsetModuleName(oldSdfModule, newModuleName);
    newSdfTree   = SDF_StartToTerm(SDF_setStartTopModule(
                     SDF_StartFromTerm(oldSdfTree), newSdfModule));

    entry = MDB_setEntrySdfTree(entry, newSdfTree);

    strcpy(path, newPath);
    strcpy(path+strlen(path), syntax_ext);

    entry   = MDB_setEntryPath(entry, path);

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
  }
  import_graph = calc_import_graph();
  return ATmake("snd-value(imports(changed-modules([<list>]),<term>))",
                changedMods, import_graph);
}

/*}}}  */
/*{{{  ATerm copy_module(int cid, char *oldModuleName, char *newModuleName) */

ATerm copy_module(int cid, char *oldModuleName, char *newModuleName,
		  char *newPath)
{
  char path[BUFSIZ]; 
  ATerm oldSdfTree, newSdfTree, import_graph;
  ATerm oldName = ATmake("<str>", oldModuleName);
  ATerm newName;
  ATermList changedMods;
  MDB_Entry entry;
  SDF_Module oldSdfModule, newSdfModule;
  ATermList unknowns, imports;
  SDF_ImportList fullImports;

  newName = ATmake("<str>", newModuleName);

  if (!checkModuleName(newModuleName)) {
    return ATmake("snd-value(illegal-module-name(<str>))", newModuleName);
  }

  changedMods = modules_depend_on(newName,ATempty);

  entry = MDB_EntryFromTerm(GetValue(modules_db, oldName));
  if (entry) {
    oldSdfTree   = MDB_getEntrySdfTree(entry);
    oldSdfModule = SDF_getStartTopModule(SDF_StartFromTerm(oldSdfTree));
    newSdfModule = SDFsetModuleName(oldSdfModule, newModuleName);
    newSdfTree   = SDF_StartToTerm(SDF_setStartTopModule(
                     SDF_StartFromTerm(oldSdfTree), newSdfModule));

    entry = MDB_setEntrySdfTree(entry, newSdfTree);

    strcpy(path, newPath);
    strcpy(path+strlen(path), syntax_ext);
    entry   = MDB_setEntryPath(entry, path);

    entry = MDB_setEntryAsfTable(entry, MDB_NONE);
    entry = MDB_setEntryTrmTable(entry, MDB_NONE);
    entry = MDB_setEntryAsfTree(entry, MDB_NONE);
    PutValue(modules_db, newName, MDB_EntryToTerm(entry));

    imports = SDF_getImports(newSdfModule);

    fullImports = SDF_getModuleImportsList(newSdfModule);
    unknowns = add_imports(newName, imports, fullImports);

    reset_trans_db();
  }

  import_graph = calc_import_graph();
  return ATmake("snd-value(imports(changed-modules([<list>]),<term>))",
                changedMods, import_graph);
}

/*}}}  */
/*{{{  ATerm add_import(int cid, char *oldModuleName, char *newModuleName, */

ATerm add_import(int cid, char *modName, char *importedModName,
		  char *ImportedPath)
{
  ATerm oldSdfTree, newSdfTree, import_graph;
  ATerm moduleName = ATmake("<str>", modName);
  ATerm importedModuleName;
  SDF_Import sdfImport;
  ATermList changedMods;
  MDB_Entry entry;
  SDF_Module oldSdfModule, newSdfModule;
  ATermList unknowns, imports;
  SDF_ImportList fullImports;

  strip_syntax_ext(importedModName);

  importedModuleName = ATmake("<str>", importedModName);
  sdfImport = SDFmakeImport(importedModName);

  if (!checkModuleName(importedModName)) {
    return ATmake("snd-value(illegal-module-name(<str>))", importedModName);
  }

  entry = MDB_EntryFromTerm(GetValue(modules_db, moduleName));
  if (entry) {
    oldSdfTree   = MDB_getEntrySdfTree(entry);

    oldSdfModule = SDF_getStartTopModule(SDF_StartFromTerm(oldSdfTree));
    newSdfModule = SDF_addModuleImport(oldSdfModule, sdfImport);

    newSdfTree   = SDF_StartToTerm(SDF_setStartTopModule(
                     SDF_StartFromTerm(oldSdfTree), newSdfModule));

    entry = MDB_setEntrySdfTree(entry, newSdfTree);
    entry = MDB_setEntryAsfTable(entry, MDB_NONE);
    entry = MDB_setEntryTrmTable(entry, MDB_NONE);
    entry = MDB_setEntryAsfTree(entry, MDB_NONE);

    PutValue(modules_db, moduleName, MDB_EntryToTerm(entry));

    imports = SDF_getImports(newSdfModule);
    fullImports = SDF_getModuleImportsList(newSdfModule);
    unknowns = replace_imports(moduleName, imports, fullImports);

    reset_trans_db();
  }

  changedMods = ATinsert(modules_depend_on(moduleName,ATempty), 
			 moduleName);

  import_graph = calc_import_graph();
  return ATmake("snd-value(imports(changed-modules([<list>]),<term>))",
                changedMods, import_graph);
}

/*}}}  */
/*{{{  ATerm add_import(int cid, char *oldModuleName, char *newModuleName, */

ATerm remove_import(int cid, char *modName, char *importedModName, char *path)
		  
{
  ATerm oldSdfTree, newSdfTree, import_graph;
  ATerm moduleName = ATmake("<str>", modName);
  ATerm importedModuleName;
  SDF_ModuleId sdfImport;
  ATermList changedMods;
  MDB_Entry entry;
  SDF_Module oldSdfModule, newSdfModule;
  ATermList unknowns, imports;
  SDF_ImportList fullImports;

  strip_syntax_ext(importedModName);

  importedModuleName = ATmake("<str>", importedModName);
  sdfImport = SDFmakeModuleId(importedModName);

  entry = MDB_EntryFromTerm(GetValue(modules_db, moduleName));
  if (entry) {
    oldSdfTree   = MDB_getEntrySdfTree(entry);
    oldSdfModule = SDF_getStartTopModule(SDF_StartFromTerm(oldSdfTree));
    newSdfModule = delete_modulename_from_module(oldSdfModule, sdfImport);
    newSdfTree   = SDF_StartToTerm(SDF_setStartTopModule(
                     SDF_StartFromTerm(oldSdfTree), newSdfModule));

    entry = MDB_setEntrySdfTree(entry, newSdfTree);
    entry = MDB_setEntryAsfTable(entry, MDB_NONE);
    entry = MDB_setEntryTrmTable(entry, MDB_NONE);
    entry = MDB_setEntryAsfTree(entry, MDB_NONE);

    PutValue(modules_db, moduleName, MDB_EntryToTerm(entry));

    imports = SDF_getImports(newSdfModule);
    fullImports = SDF_getModuleImportsList(newSdfModule);
    unknowns = replace_imports(moduleName, imports, fullImports);

    reset_trans_db();
  }

  changedMods = ATinsert(modules_depend_on(moduleName,ATempty), 
			 moduleName);

  import_graph = calc_import_graph();
  return ATmake("snd-value(imports(changed-modules([<list>]),<term>))",
                changedMods, import_graph);
}

/*}}}  */
/*{{{  static ATermList select_unknowns(ATermList mods) */

static ATermList select_unknowns(ATermList mods)
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
/*{{{  static ATermList add_imports(ATerm name, ATermList mods) */

static ATermList 
add_imports(ATerm name, ATermList mods, SDF_ImportList imports)
{
  ATermList unknowns = ATempty;

  reset_trans_db();
  if (!GetValue(import_db,name)) {
    PutValue(import_db, name, (ATerm) mods);
    PutValue(full_import_db, name, SDF_makeTermFromImportList(imports));
    unknowns = select_unknowns(mods);
  }
  return unknowns;
}

/*}}}  */
/*{{{  static ATermList replace_imports(ATerm name, ATermList mods, SDF_ImportList imports) */

static ATermList 
replace_imports(ATerm name, ATermList mods, SDF_ImportList imports)
{
  reset_trans_db();
  ATtableRemove(import_db, name);
  PutValue(import_db, name, (ATerm) mods);
  PutValue(full_import_db, name, SDF_makeTermFromImportList(imports));
  return select_unknowns(mods);
}

/*}}}  */
/*{{{  static ATbool complete_sdf2_specification(ATermList visited, ATerm module) */

static ATerm 
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
	ATerm result = NULL;
	ATermList imports = (ATermList)GetValue(import_db,module);
	
	visited = ATinsert(visited,module);
	while(!ATisEmpty(imports) && (result == NULL)) {
	  first = ATgetFirst(imports);
	  result = complete_sdf2_specification(visited,first);
	  imports = ATgetNext(imports);
	}
	return result;
      }
      else {
	return module;
      }
    } 
    else {
      return module;
    }
  }
  else {
    return NULL;
  }
}

/*}}}  */
/*{{{  static ATbool is_valid_parse_table(ATermList visited, ATerm module,...)  */

static ATbool 
is_valid_parse_table(ATermList visited, ATerm module, 
			    int timeOfEqsTable, int timeOfTrmTable)
{
  ATbool result;
  ATermList imports;
  ATerm first;
  MDB_Entry entry;
  int time;
  ATerm syntax = NULL;


  entry = MDB_EntryFromTerm(GetValue(modules_db, module));

  if (entry == NULL) {
    return ATfalse;
  }

  syntax = MDB_getEntrySdfTree(entry);
  if (ATisEqual(syntax, MDB_NONE)) {
    return ATfalse;
  }

  time = MDB_getEntrySdfTreeCreationTime(entry);

  if ((timeOfEqsTable > 0 && time > timeOfEqsTable) ||
      (timeOfTrmTable > 0 && time > timeOfTrmTable)) {
    return ATfalse;
  } else {
    result = ATtrue;
  }

  if (ATindexOf(visited, module, 0) < 0) {
    imports = (ATermList)GetValue(import_db,module);
    visited = ATinsert(visited, module);
    while(imports && !ATisEmpty(imports)) {
      first = ATgetFirst(imports);

      entry = MDB_EntryFromTerm(GetValue(modules_db, first));
      if (entry == NULL)  {
	return ATfalse;
      }

      syntax = MDB_getEntrySdfTree(entry);
      if (ATisEqual(syntax, MDB_NONE))  {
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
/*{{{  static ATbool all_rules_available(ATermList visited, ATerm module) */

static ATbool 
all_rules_available(ATermList visited, ATerm module)
{
  ATerm first;
  MDB_Entry entry;
  ATerm EqsTree;
  ATerm EqsText;
  ATbool missing;
  ATermList imports;

  if (ATindexOf(visited, module, 0) < 0) { 
    entry = MDB_EntryFromTerm(GetValue(modules_db, module));

    if (entry == NULL) {
      return ATtrue;
    }

    if (MDB_isValidEntry(entry)) {
      EqsTree = MDB_getEntryAsfTree(entry);
      EqsText = MDB_getEntryAsfText(entry);
      if (ATisEqual(EqsTree, MDB_NONE) &&
          !ATisEqual(EqsText, MDB_NONE)) {
        return ATtrue;
      }
      else {
        missing = ATfalse;
        imports = (ATermList)GetValue(import_db,module);

        if (imports == NULL) {
          return ATtrue;
        }

        visited = ATinsert(visited,module); 
    
        while (!ATisEmpty(imports) && !missing) {
          first = ATgetFirst(imports);

          missing = all_rules_available(visited,first);
          imports = ATgetNext(imports);
        }
        return missing;
      }
    }
    else {
      return ATtrue;
    }
  }
  else {
    return ATfalse;
  }
}

/*}}}  */
/*{{{  ATerm eqs_not_available_for_modules(int cid, char *moduleName) */

ATerm eqs_not_available_for_modules(int cid, char *moduleName)
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
    modules = get_imported_modulenames(moduleName);

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
/*{{{  static ATermList modules_depend_on(ATerm name, ATermList dependent) */
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
/*{{{  SDF_SDF getSyntax(ATermList modules) */

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
      SDF_Module sdfModule;
      
      sdfModule = SDF_getStartTopModule(SDF_StartFromTerm(module));

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
  ATerm result;
  ATerm missing;

  name = ATmake("<str>", moduleName);
  missing = complete_sdf2_specification(ATempty, name);
  if (missing == NULL) {
    imports = get_imported_modulenames(moduleName);
    definition = getSyntax(imports);
    result = SDF_StartToTerm(SDF_makeStartSDF(SDF_makeOptLayoutAbsent(),
			      definition,
			      SDF_makeOptLayoutAbsent(),0));
    return ATmake("snd-value(syntax(<term>))", ATBpack(result));
  }
  else {
    char msg[256];
    sprintf(msg, "Module %s has errors.", ATgetName(ATgetAFun(missing)));
    return ATmake("snd-value(sdf2-definition-error(<str>))", msg);
  }
}

/*}}}  */
/*{{{  ATerm get_module_info(int cid, char *moduleName) */

ATerm get_module_info(int cid, char *moduleName)
{
  ATerm atName;
  char *path;
  ATermList info = ATempty;
  ATerm entry = NULL;

  atName = ATmake("<str>", moduleName);
 
  entry = GetValue(modules_db, atName);
  if (entry != NULL) {
    path = MDB_getEntryPath(MDB_EntryFromTerm(entry));
    if (pathAvailable(path)) {
      info = ATinsert(info, ATmake("[path,<str>]", path));
    }
  }
  else  {
    info = ATinsert(info, ATmake("[path,\"not available\"]"));
  }

  return ATmake("snd-value(module-info(<str>,<term>))", moduleName, info);
}

/*}}}  */
/*{{{  static void usage(char *prg, ATbool is_err) */

static void 
usage(char *prg, ATbool is_err)
{
    ATwarning("usage: %s [aterm-options] [toolbus-options]\n", prg);
    ATwarning("use '%s -at-help' to get more options.\n", prg);
    ATwarning("This program can only be used as a ToolBus tool!\n");
    exit(is_err ? 1 : 0);
}

/*}}}  */
/*{{{  static void version(const char *msg) */

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
  MDB_initMDBApi();

  MDB_NONE = ATparse("unavailable");
  ATprotect(&MDB_NONE);

  ATsetChecking(ATtrue);
  cid = ATBconnect(NULL, NULL, -1, module_db_handler);

  ATBeventloop();

  return 0;
}

/*}}}  */
