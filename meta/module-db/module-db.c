/*{{{  Copyright notice */

/*

    Meta-Environment - An environment for language prototyping.
    Copyright (C) 2000  Stichting Mathematisch Centrum, Amsterdam, 
                        The Netherlands. 

    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program; if not, write to the Free Software
    Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307 USA

*/
/*
  $Id$
 */

/*}}}  */
/*{{{  includes */

#include <assert.h>

#include <conversion.h>

#include "module-db.h"

/*}}}  */
/*{{{  variables */

static char myversion[] = "2.0";

ATermTable modules_db;
ATermTable import_db;
ATermTable trans_db;

/*}}}  */

/*{{{  Forward declarations */

static ATbool complete_asf_specification(ATermList visited, ATerm module);
static ATermList add_imports(ATerm name, ATermList mods);
static ATermList replace_imports(ATerm name, ATermList mods);
static ATermList modules_depend_on(ATerm name, ATermList mods);
static ATbool is_valid_parse_table(ATermList visited, ATerm module, 
				   int timeOfEqsTable, int timeOfTrmTable);
ATermList AFTgetImports(ATerm mod);

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
  if(GetValue(modules_db,name))
    return ATmake("snd-value(result(exists(<term>)))", name);
  else
    return ATmake("snd-value(result(notexists(<term>)))", name);
}

/*}}}  */
/*{{{  ATerm get_all_equations(int cid, char *moduleName) */

ASF_CondEquationList getEquations(ATermList mods)
{
  ATerm mod, entry, eqsTerm;
  ASF_CondEquationList asfEqsList;
  ASF_CondEquationList newAsfEqsList = ASF_makeCondEquationListEmpty();
  PT_ParseTree eqsParseTree;
  PT_Tree eqsTree;
  ASF_Equations asfEqs;

  while(!ATisEmpty(mods)) {
    mod = ATgetFirst(mods);
    entry = GetValue(modules_db, mod);
    eqsTerm = ATelementAt((ATermList)entry, EQS_TREE_LOC);

    if (!ATisEqual(eqsTerm, ATparse("unavailable"))) {
      eqsParseTree = PT_makeParseTreeFromTerm(eqsTerm);
      eqsTree = PT_getParseTreeTree(eqsParseTree);
      asfEqs = ASF_makeEquationsFromTerm(PT_makeTermFromTree(eqsTree));

      if (ASF_isEquationsPresent(asfEqs)) {
	asfEqsList = ASF_getEquationsList(asfEqs);
	newAsfEqsList = ASF_concatCondEquationList(newAsfEqsList, asfEqsList);
      }
    }
    mods = ATgetNext(mods);
  }
  return newAsfEqsList;
}

ATerm get_all_equations(int cid, char *moduleName)
{
  ATerm name;
  ATermList mods;
  ATerm result;

/* calculate the transitive closure of the imported modules. */
  
  name = ATmake("<str>",moduleName);
  if (complete_asf_specification(ATempty, name)) {
    mods = get_imported_modules(name);
    result = ASF_makeTermFromCondEquationList(getEquations(mods)); 
    return ATmake("snd-value(equations(<term>))", ATBpack(result));
  }
  else {
    return ATmake("snd-value(equations-incomplete)");
  }
}

static ATerm transformEquations(ATermList equations)
{
  ATermList newEquations = ATempty;

  while (!ATisEmpty(equations)) {
    PT_Tree equation = PT_makeTreeFromTerm(ATgetFirst(equations));
    ATerm newEquation = tree2a1(equation);
    newEquations = ATappend(newEquations, newEquation);
    equations = ATgetNext(equations);
  }
  return (ATerm)newEquations;
}  

ATerm get_all_equations_for_compiler(int cid, char *moduleName)
{
  ATerm name;
  ATermList mods;
  ATerm result;

/* calculate the transitive closure of the imported modules. */
  
  name = ATmake("<str>",moduleName);
  if (complete_asf_specification(ATempty, name)) {
    mods = get_imported_modules(name);
    result = transformEquations(
               (ATermList)ASF_makeTermFromCondEquationList(
                            getEquations(mods))); 
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
/*{{{  void create_module_db(int cid) */

void create_module_db(int cid)
{
  modules_db = CreateValueStore(100,75);
  import_db = CreateValueStore(100,75);
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
    import_db = CreateValueStore(100,75);
  }

  reset_trans_db();
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
      if(ATindexOf(result, pair, 0) < 0)
        result = ATappend(result, pair);
      importedmodules = ATgetNext(importedmodules);
    }
    allmodules = ATgetNext(allmodules);
  }
  return ATmake("import-graph([<list>],[<list>])", actualmodules, result);
}

/*}}}  */
/*{{{  ATerm add_sdf2_module(int cid, char *moduleName, char *path, ATerm sdfTree,  */
/* Creation of a new entry in the database of a new Sdf2 definition. 
 */

ATerm add_sdf2_module(int cid, char *moduleName, char *path, ATerm sdfTree, 
		      int timestamp, char *changed)
{
  char          eqsPath[BUFSIZ];
  ATerm         modName;
  int           len;
  ATerm         entry, import_graph;
  ATermList     imports, unknowns;
  ATerm         isChanged;
  PT_Tree       tree;
  PT_ParseTree  parseTree;
  SDF_Module    sdfModule;

  if (!strcmp(changed, "changed")) {
    isChanged = Mtrue;
  }
  else {
    isChanged = Mfalse;
  }

  len = strlen(path) - strlen("sdf");
  strncpy(eqsPath, path, len);
  strcpy(eqsPath+len, "asf");

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
  entry = (ATerm)ATmakeList(LOC_CNT,
			    ATmake("<str>", path),   /* Path Sdf */
			    sdfTree,                
			    ATmakeInt(timestamp),    /* Time Sdf */
			    isChanged,               /* Sdf changed? */
			    ATmake("<str>", eqsPath),/* Path Eqs */
			    ATparse("unavailable"),  /* Eqs Tree */
			    ATparse("unavailable"),  /* Eqs Text */
			    ATmakeInt(0),            /* Time Eqs */
			    Mtrue,                   /* Eqs changed?: true */
			    ATparse("unavailable"),  /* Path EqsParseTable */
			    ATmakeInt(0),            /* Time of EqsParseTable */
			    ATparse("unavailable"),  /* Path TrmParseTable */
			    ATmakeInt(0)             /* Time of TrmParseTable */
			   );

  PutValue(modules_db, modName, entry);
  imports = SDF_getImports(sdfModule);
  unknowns = add_imports(modName, imports);
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
  ATermList entry;

  while (!ATisEmpty(mods)) {
    modname = ATgetFirst(mods);
    entry = (ATermList)GetValue(modules_db, modname);
    entry = ATreplace(entry, ATparse("unavailable"), EQS_TREE_LOC);
    entry = ATreplace(entry, Mtrue, EQS_UPDATED_LOC);
    entry = ATreplace(entry, ATparse("unavailable"), EQS_TABLE_LOC);
    entry = ATreplace(entry, ATparse("unavailable"), TRM_TABLE_LOC);
    PutValue(modules_db, modname, (ATerm)entry);
    mods = ATgetNext(mods);
  }
}

/*}}}  */
/*{{{  ATerm update_sdf2_module(int cid, ATerm newSdfTree) */
/* Update an existing Sdf2 definition in the database.
 */

ATerm update_sdf2_module(int cid, ATerm newSdfTree)
{
  ATerm        curSdfTree, entry, import_graph;
  ATermList    imports, unknowns, chg_mods;
  PT_ParseTree parseTree;
  PT_Tree      tree;
  SDF_Module   sdfModule;
  ATerm        modName;

  parseTree = PT_makeParseTreeFromTerm(newSdfTree);
  if (!PT_isValidParseTree(parseTree)) {
    ATerror("not an asfix module: %t\n", newSdfTree);
    return NULL;
  }

  tree      = PT_getParseTreeTree(parseTree);
  sdfModule = SDF_makeModuleFromTerm(PT_makeTermFromTree(tree));
  modName   = ATmake("<str>", SDFgetModuleName(sdfModule));
  entry     = GetValue(modules_db, modName);

  if (entry) {
    curSdfTree = ATelementAt((ATermList)entry, SYN_LOC);
    if (!ATisEqual(curSdfTree, newSdfTree)) {
      entry = (ATerm)ATreplace((ATermList)entry, newSdfTree,
			       SYN_LOC);
      entry = (ATerm)ATreplace((ATermList)entry, Mtrue,
			       SYN_UPDATED_LOC);

      entry = (ATerm)ATreplace((ATermList)entry,
			       ATparse("unavailable"), EQS_TABLE_LOC);
      entry = (ATerm)ATreplace((ATermList)entry,
			       ATparse("unavailable"), TRM_TABLE_LOC);
      PutValue(modules_db, modName, entry);

      chg_mods = modules_depend_on(modName, ATempty);
      update_syntax_status_of_modules(chg_mods); 
      imports = SDF_getImports(sdfModule);
      unknowns = replace_imports(modName, imports);
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
  ATerm atModuleName, entry, importGraph;
  ATermList discardValue;
  char  fileName[1024] = {'\0'};

  atModuleName = ATmake("<str>",  moduleName);
  sprintf(fileName,"%s%s", moduleName, ".sdf");
  entry = (ATerm)ATmakeList(LOC_CNT,
                            ATmake("<str>", fileName),   /* Path Sdf */
                            ATparse("unavailable"),      /* Sdf Tree */
                            ATmakeInt(0),                /* Time Sdf */
                            Mtrue,                       /* Sdf changed? */
                            ATparse("unavailable"),      /* Path Eqs */
                            ATparse("unavailable"),      /* Eqs Tree */
                            ATparse("unavailable"),      /* Eqs Text */
                            ATmakeInt(0),                /* Time Eqs */
                            Mtrue,                       /* Eqs changed?: true */
                            ATparse("unavailable"),      /* Path EqsParseTable */ 
                            ATmakeInt(0),                /* Time of EqsParseTable */
                            ATparse("unavailable"),      /* Path TrmParseTable */ 
                            ATmakeInt(0)                 /* Time of TrmParseTable */
                           );
  PutValue(modules_db, ATmake("<str>", moduleName), entry);

  discardValue = add_imports(atModuleName, ATempty);
  importGraph = calc_import_graph();

  return ATmake("snd-value(empty-module-added(<term>))", importGraph);
}

/*}}}  */
/*{{{  void add_tree_eqs_section(int cid, char *moduleName, char* path, */

void add_tree_eqs_section(int cid, char *moduleName, char* path,
                          ATerm eqsTree, char *eqsText, int timestamp)
{
  ATerm entry;
  ATerm isChanged = Mfalse;
  ATerm atModuleName, atEqsText;

  atModuleName = ATmake("<str>", moduleName);
  atEqsText = ATmake("<str>", eqsText);

  eqsTree = PT_makeTermFromParseTree(
              PT_addParseTreePosInfo(path, PT_makeParseTreeFromTerm(eqsTree)));

  entry = GetValue(modules_db, atModuleName);
  entry = (ATerm)ATreplace((ATermList)entry,
                           ATmake("<str>", path),
                           PATH_EQS_LOC);
  entry = (ATerm)ATreplace((ATermList)entry,
                           isChanged,
                           EQS_UPDATED_LOC);
  entry = (ATerm)ATreplace((ATermList)entry, eqsTree, EQS_TREE_LOC);
  entry = (ATerm)ATreplace((ATermList)entry, atEqsText, EQS_TEXT_LOC);
  entry = (ATerm)ATreplace((ATermList)entry, 
                           (ATerm)ATmakeInt(timestamp),
                           EQS_TIME_LOC);
  PutValue(modules_db, atModuleName, entry);
}

/*}}}  */
/*{{{  void add_text_eqs_section(int cid, char *moduleName, char* path,  */

void add_text_eqs_section(int cid, char *moduleName, char* path, 
                          char *eqsText, int timestamp)
{
  ATerm entry;
  ATerm isChanged = Mtrue;
  ATerm atModuleName;
  ATerm atEqsText;

  atModuleName = ATmake("<str>", moduleName);
  atEqsText = ATmake("<str>", eqsText);

  entry = GetValue(modules_db, atModuleName);

  entry = (ATerm)ATreplace((ATermList)entry,
                           ATmake("<str>", path),
                           PATH_EQS_LOC);
  entry = (ATerm)ATreplace((ATermList)entry,
                           isChanged,
                           EQS_UPDATED_LOC);
  entry = (ATerm)ATreplace((ATermList)entry,  atEqsText, EQS_TEXT_LOC);
  entry = (ATerm)ATreplace((ATermList)entry, 
                           (ATerm)ATmakeInt(timestamp),
                           EQS_TIME_LOC);
  PutValue(modules_db, atModuleName, entry);
}

/*}}}  */

void update_eqs_text(int cid, char *moduleName, char *eqsText)
{
  ATerm entry;
  ATerm isChanged = Mtrue;
  ATerm atModuleName;
  ATerm atEqsText;

  atModuleName = ATmake("<str>", moduleName);
  atEqsText = ATmake("<str>", eqsText);

  entry = GetValue(modules_db, atModuleName);

  entry = (ATerm)ATreplace((ATermList)entry, isChanged, EQS_UPDATED_LOC);
  entry = (ATerm)ATreplace((ATermList)entry, atEqsText, EQS_TEXT_LOC);
  entry = (ATerm)ATreplace((ATermList)entry, 
                           ATparse("unavailable"), EQS_TREE_LOC); 

  PutValue(modules_db, atModuleName, entry);
}

/*{{{  void add_empty_eqs_section(int cid, char *moduleName, char* path) */

void add_empty_eqs_section(int cid, char *moduleName, char* path)
{
  ATerm entry;
  ATerm isChanged = Mfalse;
  ATerm atModuleName, atEqsText;

  atModuleName = ATmake("<str>", moduleName);
  atEqsText = ATmake("\"\"");

  entry = GetValue(modules_db, atModuleName);
  entry = (ATerm)ATreplace((ATermList)entry,
                           ATmake("<str>", path),
                           PATH_EQS_LOC);
  entry = (ATerm)ATreplace((ATermList)entry,
                           isChanged,
                           EQS_UPDATED_LOC);
  entry = (ATerm)ATreplace((ATermList)entry, atEqsText, EQS_TEXT_LOC);
  PutValue(modules_db, atModuleName, entry);
}

/*}}}  */

/*{{{  ATerm update_eqs_tree(int cid, char *moduleName, ATerm newEqsTree) */

ATerm update_eqs_tree(int cid, char *moduleName, ATerm newEqsTree)
{
  ATerm entry;
  ATerm curEqsTree;
  ATerm atModuleName, atPath;
  ATermList changedModules;
  char *path;

  atModuleName = ATmake("<str>", moduleName);

  entry = GetValue(modules_db, atModuleName);

  curEqsTree = ATelementAt((ATermList)entry, EQS_TREE_LOC);

  atPath = ATelementAt((ATermList)entry, PATH_EQS_LOC);
  if (ATmatch(atPath, "<str>", &path)) {
    newEqsTree = PT_makeTermFromParseTree(
                   PT_addParseTreePosInfo(
                     path, 
                     PT_makeParseTreeFromTerm(newEqsTree)));
  }
  else {
    ATwarning("No path for %s equations section\n", moduleName);
  }

  if (!ATisEqual(newEqsTree, curEqsTree)) {
    entry = (ATerm)ATreplace((ATermList)entry, newEqsTree, EQS_TREE_LOC);
    PutValue(modules_db, atModuleName, entry);
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
  ATerm entry, modname;
  char *moduleName;
  int tableLoc, tableTimeLoc;

  if (ATmatch(moduleId, "eqs(<str>)", &moduleName)) {
    tableLoc = EQS_TABLE_LOC;
    tableTimeLoc = EQS_TABLE_TIME_LOC;
  } 
  else if (ATmatch(moduleId, "trm(<str>)", &moduleName))  {
    tableLoc = TRM_TABLE_LOC;
    tableTimeLoc = TRM_TABLE_TIME_LOC;
  }
  else {
    ATerror("Illegal moduleId: %t\n", moduleId);
    return NULL;
  }

  modname = ATmake("<str>",moduleName);

  entry = GetValue(modules_db, modname);

  entry = (ATerm)ATreplace((ATermList)entry,
                           /*ATmake("table(<str>)", table),*/
                           ATmake("table(<term>)", table),
                           tableLoc); 
  entry = (ATerm)ATreplace((ATermList)entry,
                           (ATerm)ATmakeInt(timestamp),
                           tableTimeLoc);

  PutValue(modules_db, modname, entry);
  return ATmake("snd-value(parse-table-added)");
}

/*}}}  */
/*{{{  ATerm get_path(int cid, char *modulename, ATerm type) */

ATerm get_path(int cid, char *modulename, ATerm type)
{
  ATerm entry, place, modname;
  char *path;
  int location = 0;

  if (ATmatch(type, "eqs")) {
      location = PATH_EQS_LOC;
  } else if (ATmatch(type, "sdf2")) {
      location = PATH_SYN_LOC;
  } else {
      ATerror("Unsupported database type: %t", type);
      return NULL;
  }

  modname = ATmake("<str>", modulename);
  entry = GetValue(modules_db, modname);
  if (!entry) {
    ATerror("Module %s not in database!", modulename);
    return NULL;
  }

  place = ATelementAt((ATermList)entry, location);
  if(ATmatch(place, "<str>", &path)) {
    return ATmake("snd-value(path(<str>))", path);
  } else if (location == PATH_EQS_LOC) {
    /* found an empty equation section. Return empty path */
    return ATmake("snd-value(path(<str>))", "");
  }
  /* we never get here */
  ATerror("Error in get_path");
  return NULL;
}

/*}}}  */
/*{{{  ATerm get_asfix(int cid, char *modulename, ATerm type) */
/* As above, type is either sdf2 or eqs, because slightly different
   actions need to be taken when the module does not exist. */


ATerm get_asfix(int cid, char *modulename, ATerm type)
{
  ATerm entry, asfix;
  ATerm isChanged, modname;
  enum { sdf2, eqs } module_type = sdf2; /* to keep compiler happy */
  int location = 0, updated_location = 0; /* To keep compiler happy*/

  if (ATmatch(type,"sdf2")) {
      updated_location = SYN_UPDATED_LOC;
      location = SYN_LOC;
      module_type = sdf2;
  } else if (ATmatch(type, "eqs")) {
      updated_location = EQS_UPDATED_LOC;
      location = EQS_TREE_LOC;
      module_type = eqs;
  } else {
      ATerror("Type not supported by database: %t", type);
  }
  modname = ATmake("<str>",modulename);
  entry = GetValue(modules_db, modname);
  if (!entry) {
    ATerror("Module %s not in database!", modulename);
    return NULL;
  }

  isChanged = ATelementAt((ATermList)entry, updated_location);
  asfix = ATelementAt((ATermList)entry, location);
  if(ATisEqual(isChanged, Mtrue)) {
    if(ATisEqual(asfix, ATparse("unavailable"))) {
	return ATmake("snd-value(asfix(unavailable))");
    } else {
      isChanged = Mfalse;
      entry = (ATerm)ATreplace((ATermList)entry,
                               isChanged,
                               updated_location);
      PutValue(modules_db, modname, entry);
      if (module_type == sdf2) {
	return ATmake("snd-value(asfix(syntax(<term>)))", ATBpack(asfix));
      }
      else if (module_type == eqs) {
	return ATmake("snd-value(asfix(tree(<term>)))", ATBpack(asfix));
      }
    }
  } else {
      /* isChanged = false */
      if (module_type == eqs) {
	asfix = ATelementAt((ATermList)entry, location);
	if(ATisEqual(asfix, ATparse("unavailable"))) {
	  return ATmake("snd-value(asfix(unavailable))");
	} else {
	    return ATmake("snd-value(asfix(tree(<term>)))", ATBpack(asfix));
	}
      } 
      else if (module_type == sdf2) {
	return ATmake("snd-value(asfix(syntax-unchanged(<term>)))", ATBpack(asfix));
      }
  }
  /* we never get here */
  ATerror("Error in get_asfix");
  return NULL;
}

/*}}}  */
/*{{{  ATerm get_parse_table(int cid, ATerm moduleId) */

ATerm get_parse_table(int cid, ATerm moduleId)
{
  ATermList entry;
  ATerm     place, table, modname;
  ATerm     contents, result;
  char      *moduleName;
  char      *path, pathExt[9], *newpath;
  int tableLoc, sdfLoc, strLen;

  if (ATmatch(moduleId, "eqs(<str>)", &moduleName)) {
    tableLoc = EQS_TABLE_LOC;
    strcpy(pathExt, ".asf.tbl");
  } 
  else if (ATmatch(moduleId, "trm(<str>)", &moduleName))  {
    tableLoc = TRM_TABLE_LOC;
    strcpy(pathExt, ".trm.tbl");
  }
  else {
    ATwarning("Illegal moduleId: %t\n", moduleId);
    return ATmake("snd-value(no-table)");
  }
    
  sdfLoc = PATH_SYN_LOC;
  modname = ATmake("<str>", moduleName);
  if ((entry = (ATermList) GetValue(modules_db, modname))) {
    table = ATelementAt((ATermList)entry, tableLoc);
    place = ATelementAt((ATermList)entry, sdfLoc);
    if (ATmatch(place, "<str>", &path)) {
      strLen = strlen(path);
      newpath = malloc(strLen+5);
      strncpy(newpath, path, strLen-4);
      strcpy(newpath+strLen-4, pathExt);
      if (ATmatch(table,"table(<term>)", &contents)) {
        ATermAppl dummy = (ATermAppl)ATBpack(ATmake("dummy"));
        contents = (ATerm)ATgetArgument((ATermAppl)contents, 0);
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
  ATermList entry;

  modname = ATmake("<str>",modulename);
  entry = (ATermList)GetValue(modules_db, modname);
  if(entry) {
    timeOfEqsTable = ATgetInt((ATermInt)ATelementAt((ATermList)entry, 
                                                    EQS_TABLE_TIME_LOC));
    timeOfTrmTable = ATgetInt((ATermInt)ATelementAt((ATermList)entry, 
                                                    TRM_TABLE_TIME_LOC));

    if(ATindexOf(visited, modname, 0) < 0) {
      if(!is_valid_parse_table(ATempty, modname, 
                               timeOfEqsTable, timeOfTrmTable)) {
        entry = ATreplace(entry,ATparse("unavailable"), EQS_TABLE_LOC);
        entry = ATreplace(entry,ATparse("unavailable"), TRM_TABLE_LOC);
        entry = ATreplace(entry,ATparse("unavailable"), EQS_TREE_LOC);
        PutValue(modules_db, modname, (ATerm)entry);
      }
      visited = ATinsert(visited, modname);
      imports = (ATermList)GetValue(import_db, modname);
      while(imports && !ATisEmpty(imports)) {
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
  reset_trans_db();
  return ATmake("snd-value(changed-modules([<term>,<list>]))",
                name, changedMods);
}

/*}}}  */
/*{{{  ATermList select_unknowns(ATermList mods) */

static ATermList 
select_unknowns(ATermList mods)
{
  ATermList result = ATempty;

  while(!ATisEmpty(mods)) {
    ATerm mod = ATgetFirst(mods);
    if(!GetValue(import_db,mod)) {
      if (ATindexOf(result, mod, 0) < 0)
        result = ATappend(result,mod);
    }
    mods = ATgetNext(mods);
  }
  return result;
}

/*}}}  */
/*{{{  ATermList add_imports(ATerm name, ATermList mods) */

static ATermList 
add_imports(ATerm name, ATermList mods)
{
  ATermList unknowns = ATempty;

  reset_trans_db();
  if(!GetValue(import_db,name)) {
    PutValue(import_db, name, (ATerm) mods);
    unknowns = select_unknowns(mods);
  }
  return unknowns;
}

/*}}}  */
/*{{{  ATermList replace_imports(ATerm name, ATermList mods) */

static ATermList 
replace_imports(ATerm name, ATermList mods)
{
  reset_trans_db();
  ATtableRemove(import_db, name);
  PutValue(import_db, name, (ATerm) mods);
  return select_unknowns(mods);
}

/*}}}  */
/*{{{  ATbool complete_sdf2_specification(ATermList visited, ATerm module) */

static ATbool 
complete_sdf2_specification(ATermList visited, ATerm module)
{
  ATerm entry, asfix;

  if(ATindexOf(visited, module, 0) < 0) {
    entry = GetValue(modules_db, module);
    if(entry) {
      asfix = ATelementAt((ATermList)entry, SYN_LOC);
      if(!ATisEqual(asfix, ATparse("unavailable"))) {
	ATerm first;
	ATbool result = ATtrue;
	ATermList imports = (ATermList) GetValue(import_db,module);
	
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
  ATerm first, entry;
  int time;

  entry = GetValue(modules_db, module);
  time = (int)ATelementAt((ATermList)entry, SYN_TIME_LOC);
  time = ATgetInt((ATermInt)ATelementAt((ATermList)entry, SYN_TIME_LOC));

  if((timeOfEqsTable > 0 && time > timeOfEqsTable) ||
     (timeOfTrmTable > 0 && time > timeOfTrmTable)) {
    result = ATfalse;
  } else {
    result = ATtrue;
  }

  if(ATindexOf(visited, module, 0) < 0) {
    imports = (ATermList)GetValue(import_db,module);
    visited = ATinsert(visited, module);
    while(imports && !ATisEmpty(imports)) {
      ATermList
	entry;
      first = ATgetFirst(imports);

      entry = (ATermList)GetValue(modules_db, first);
      if(entry) {
	timeOfEqsTable = ATgetInt((ATermInt)ATelementAt((ATermList)entry, 
							EQS_TABLE_TIME_LOC));
	timeOfTrmTable = ATgetInt((ATermInt)ATelementAt((ATermList)entry, 
							TRM_TABLE_TIME_LOC));

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
  ATerm first, entry;
  ATerm EqsTree;
  ATerm EqsText;
  ATbool result;
  ATermList imports;

  if(ATindexOf(visited, module, 0) < 0) { 
    result = ATtrue;
    imports = (ATermList) GetValue(import_db,module);

    visited = ATinsert(visited,module); 
    
    while(!ATisEmpty(imports) && result) {
      first = ATgetFirst(imports);
      entry = GetValue(modules_db, first);
      EqsTree = ATelementAt((ATermList)entry, EQS_TREE_LOC);
      EqsText = ATelementAt((ATermList)entry, EQS_TEXT_LOC);
      if (ATisEqual(EqsTree, ATparse("unavailable")) &&
          !ATisEqual(EqsText, ATparse("unavailable"))) {
        result = ATfalse;
      } else {
        result = complete_asf_specification(visited,first);
        imports = ATgetNext(imports);
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
/*{{{  ATermList calc_trans(ATermList todo) */

static ATermList 
calc_trans(ATermList todo)
{
  ATerm name;
  ATermList imports, result = ATempty;

  while(!ATisEmpty(todo)) {
    name = ATgetFirst(todo);
    if(ATindexOf(result, name, 0) < 0) {
      imports = (ATermList) GetValue(import_db,name);
      result = ATappend(result, name);
      todo = ATconcat(todo, imports);
    };
    todo = ATgetNext(todo);
  }
  return result;
}

/*}}}  */
/*{{{  ATermList get_imported_modules(ATerm name) */

ATermList get_imported_modules(ATerm name)
{
  ATermList result;
  ATerm value;

  value = GetValue(trans_db,name);
  if (!value) {
    result = calc_trans(ATmakeList1(name));
    PutValue(trans_db, name, (ATerm) result);
    return result;
  }
  else
    return (ATermList) value;
}

/*}}}  */
/*{{{  ATerm eqs_available_for_modules(int cid, char *moduleName) */

ATerm eqs_available_for_modules(int cid, char *moduleName)
{
  ATerm module, entry, eqsText;
  ATerm eqsTree;
  ATerm atModuleName;
  ATermList result = ATempty;
  ATermList modules;

  atModuleName = ATmake("<str>",moduleName);
  if(GetValue(modules_db, atModuleName)) {
    /* Get all imported modules (including the module itself) */
    modules = get_imported_modules(atModuleName);

    while (!ATisEmpty(modules)) {
      module = ATgetFirst(modules);
      entry = GetValue(modules_db, module);
      eqsText = ATelementAt((ATermList)entry, EQS_TEXT_LOC);
      eqsTree = ATelementAt((ATermList)entry, EQS_TREE_LOC);
      if(ATisEqual(eqsTree, ATparse("unavailable")) &&
	 !ATisEqual(eqsText, ATparse("unavailable"))) {
        result = ATinsert(result,module);
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
  ATerm atName, entry;

  atName = ATmake("<str>",moduleName);
  
  entry = GetValue(modules_db, atName);
  eqsText = ATelementAt((ATermList)entry, EQS_TEXT_LOC);
  if (!ATisEqual(eqsText, ATparse("unavailable"))) {
    return ATmake("snd-value(eqs-text(<str>,<term>))", moduleName, eqsText);
  } else {
    return ATmake("snd-value(no-eqs-text(<str>))", moduleName);
  }
}

/*}}}  */
/*{{{  ATerm get_all_modules(int cid) */

ATerm get_all_modules(int cid)
{
  ATermList list = ATtableKeys(import_db);

  return ATmake("snd-value(all-modules([<list>]))",list);
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
    if(ATindexOf((ATermList) GetValue(import_db,module), name, 0) >= 0) {
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
      ATerm head = ATgetFirst(modules); 
      ATerm entry = GetValue(modules_db, head);
      ATerm module = ATelementAt((ATermList)entry, SYN_LOC);
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
/*
  char *emptyString = "\"\"";
*/
  ATerm name;
  ATermList imports;
  PT_ParseTree parseTree;
  PT_Tree sdfTree;
  ATerm result;
  PT_Symbol sort;
  PT_Symbols symbols;

  name = ATmake("<str>", moduleName);
  if (complete_sdf2_specification(ATempty, name)) {
    imports = get_imported_modules(name);
    definition = getSyntax(imports);
    sdfTree = PT_makeTreeFromTerm(SDF_makeTermFromSDF(definition));
    /*
    parseTree = PT_makeParseTreeTree(emptyString, sdfTree, emptyString);
    */
    sort = PT_makeSymbolCf(PT_makeSymbolSort("SDF"));
    symbols = PT_makeSymbolsList(sort, PT_makeSymbolsEmpty());
    parseTree = PT_makeParseTreeTree(symbols, 
                                     PT_makeTreeLayoutEmpty(),
                                     sdfTree,
                                     PT_makeTreeLayoutEmpty(), 0);
/*
    result = PT_makeTermFromParseTree(parseTree);
ATwarning("syntax = %t\n", result);
*/
    result = a2metoa1(parseTree);
    return ATmake("snd-value(syntax(<term>))", ATBpack(result));
  }
  else {
    return ATmake("snd-value(sdf2-definition-error(\"Specification is incomplete, can not generate parse table\"))");
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
  ATinit(argc, argv, &bottomOfStack);

  ATsetChecking(ATtrue);

  PT_initMEPTApi();
  SDF_initSDFMEApi();
  ASF_initASFMEApi();

  cid = ATBconnect(NULL, NULL, -1, module_db_handler);

  ATBeventloop();

  return 0;
}

/*}}}  */
