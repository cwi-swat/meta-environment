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
/* The module-database is written by Mark van den Brand.

The following functions are available.
General ToolBus functions:
   void rec_terminate(ATerm t)
   void rec_ack_event(ATerm term)

Creation and clearing of the module database:
   void create_module_db()
   void clear_module_db()

Manipulation of modules in database:
   ATerm exists(char *modulename)
   ATerm delete_module(char *modulename)
   ATerm add_module(ATerm asfix)
   ATerm add_empty_module(char* modulename)
   ATerm add_sdf2_module(char* path, ATerm asfix, 
                         int timestamp, char* changed)
   void add_tree_eqs_section(char* modulename, char* path,
                             ATerm eqsTree, char *eqsText, int timestamp)
   void add_text_eqs_section(char* modulename, char* path, 
                             char *eqsText, int timestamp)
   ATerm update_sdf2_module(ATerm asfix)
   ATerm update_eqs_tree(char* modulename, ATerm eqsTree)
   ATerm eqs_available_for_modules(char *modulename)
   ATerm get_path(char *modulename, ATerm type)
   ATerm get_asfix(char *modulename, ATerm type)
   ATerm get_all_sdf2_definitions(char *modulename)
   ATerm get_all_equations(char *modulename)
   ATerm get_parse_table(char *modulename)
   ATerm add_parse_table(char *modulename, char *table, int timestamp)
   void invalidate_parse_tables(char *modulename)
   ATerm get_all_modules()
   void process_next_module()
   void reshuffle_modules_from(char *modulename)
*/

#include <stdlib.h>

#include "module-db.h"

static char myversion[] = "1.1";

ATermTable new_modules_db;
ATermTable import_db;
ATermTable trans_db;

/* Declaration for the reshuffling phase. */
ATermList modules_to_process;
ATbool compiling = ATfalse;
ATbool reshuffling = ATfalse;
ATerm top_module;
ATermTable compile_db;

static char *outputDirName = NULL;

void rec_terminate(int cid, ATerm t)
{
  exit(0);
}

void
set_output_dir(int cid, char *dirName)
{
  int len = strlen(dirName) + 1;

  outputDirName = (char *) realloc(outputDirName, len);

  if (outputDirName == NULL) {
    ATerror("module-db: unable to allocate %d bytes\n", len);
  } else {
    strcpy(outputDirName, dirName);
  }
}

/*
 * The same construct is used in compiler.c
 * This obviously needs to be moved away altogether from the module-db.
 */
char *
get_output_dir(void)
{
    if (outputDirName != NULL) {
	return outputDirName;
    } else if (getenv("COMPILER_OUTPUT") != NULL) {
	return getenv("COMPILER_OUTPUT");
    } else {
	return ".";
    }
}

ATerm exists(int cid, char *modulename)
{
  ATerm name = ATmake("<str>",modulename);
  if(GetValue(new_modules_db,name))
    return ATmake("snd-value(result(exists(<term>)))", name);
  else
    return ATmake("snd-value(result(notexists(<term>)))", name);
}

ATermList get_imported_modules(ATerm name);
ATbool complete_asf_specification(ATermList visited, ATerm module);

ATerm get_all_equations(int cid, char *moduleName)
{
  ATerm mod, entry, eqsterm, name;
  ATermList eqs, mods;
  ATermList equations = ATempty;

/* calculate the transitive closure of the imported modules. */
  
  name = ATmake("<str>",moduleName);
  if (complete_asf_specification(ATempty, name)) {
    mods = get_imported_modules(name);

    equations = ATempty;
    while(!ATisEmpty(mods)) {
      mod = ATgetFirst(mods);
      entry = GetValue(new_modules_db,mod);
      eqsterm = ATelementAt((ATermList)entry, EQS_TREE_LOC);
      eqs = AFTgetEqs(eqsterm);
      equations = ATconcat(equations, eqs); 
      mods = ATgetNext(mods);
    };

    return ATmake("snd-value(equations([<list>]))",equations);
  } else {
    return ATmake("snd-value(equations-incomplete)");
  }
}

void create_module_db(int cid)
{
  new_modules_db = CreateValueStore(100,75);
  import_db = CreateValueStore(100,75);
  trans_db = CreateValueStore(100,75);
}

void clear_module_db(int cid)
{
  new_modules_db = CreateValueStore(100,75);
  import_db = CreateValueStore(100,75);
  trans_db = CreateValueStore(100,75);
}

ATermList get_import_section(ATermList sections);
ATermList add_imports(ATerm name, ATermList mods);
char *get_module_name(ATerm module);
ATermList get_import_section_sdf2(ATerm module);

ATerm calc_import_graph(void)
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


/* Creation of a new entry in the database of a new Sdf2 definition. 
 */
ATerm add_sdf2_module(int cid, char* moduleName, char* path, ATerm sdfTree, 
                      int timestamp, char* changed)
{
  ATerm t[8];
  char *modname;
  ATerm modname_term,appl, entry, import_graph;
  ATermList imports, unknowns;
  ATerm isChanged;

  if(!strcmp(changed,"changed")) {
    isChanged = Mtrue;
  }
  else {
    isChanged = Mfalse;
  }

  if(ATmatchTerm(sdfTree,pattern_asfix_term,
                 &t[0], &t[1], &t[2], &t[3], &t[4], &t[5],
                 &appl, &t[6], &t[7])) {
    modname = get_module_name(appl);
    if(strcmp(moduleName, modname) == 0) {
      modname_term = ATmake("<str>", modname);
      entry = (ATerm)ATmakeList(LOC_CNT,
                                ATmake("<str>", path),   /* Path Sdf */
                                sdfTree,                
                                ATmakeInt(timestamp),    /* Time Sdf */
                                isChanged,               /* Sdf changed? */
                                ATparse("unavailable"),  /* Path Eqs */
                                ATparse("unavailable"),  /* Eqs Tree */
                                ATparse("unavailable"),  /* Eqs Text */
                                ATmakeInt(0),            /* Time Eqs */
                                Mtrue,                   /* Eqs changed?: true */
                                ATparse("unavailable"),  /* Path EqsParseTable */
                                ATmakeInt(0),            /* Time of EqsParseTable */
                                ATparse("unavailable"),  /* Path TrmParseTable */
                                ATmakeInt(0)             /* Time of TrmParseTable */
                               );
      PutValue(new_modules_db, modname_term, entry);
      imports = get_import_section_sdf2(sdfTree);
      unknowns = add_imports(modname_term,imports);
      import_graph = calc_import_graph();
      return ATmake("snd-value(imports(need-modules([<list>]),<term>))",
                    unknowns, import_graph);
    }
    else {
      return ATmake("snd-value(name-consistency-error(<str>))", modname);
    }
  } else {
    return ATmake("snd-value(illegal-module-error(<str>))", moduleName);
  }
}

/* This function "update..." removes the parse table and
   the asfix representation of the equations from the
   module database for all listed modules. */
void update_syntax_status_of_modules(ATermList mods)
{
  ATerm modname;
  ATermList entry;

  while (!ATisEmpty(mods)) {
    modname = ATgetFirst(mods);
    entry = (ATermList)GetValue(new_modules_db, modname);
    entry = ATreplace(entry, ATparse("unavailable"), EQS_TREE_LOC);
    entry = ATreplace(entry, Mtrue, EQS_UPDATED_LOC);
    entry = ATreplace(entry, ATparse("unavailable"), EQS_TABLE_LOC);
    entry = ATreplace(entry, ATparse("unavailable"), TRM_TABLE_LOC);
    PutValue(new_modules_db, modname, (ATerm)entry);
    mods = ATgetNext(mods);
  }
}

ATermList replace_imports(ATerm name, ATermList mods);
ATermList modules_depend_on(ATerm name, ATermList mods);

/* Update an existing Sdf2 definition in the database.
 */
ATerm update_sdf2_module(int cid, ATerm newSdfTree)
{
  ATerm t[8];
  char *moduleName;
  ATerm curSdfTree, appl, entry, import_graph;
  ATerm atModuleName;
  ATermList imports, unknowns, chg_mods;

  if(ATmatchTerm(newSdfTree,pattern_asfix_term,
                 &t[0], &t[1], &t[2], &t[3], &t[4], &t[5],
                 &appl, &t[6], &t[7])) {
    moduleName = get_module_name(appl);
    atModuleName = ATmake("<str>",  moduleName);
    entry = GetValue(new_modules_db, atModuleName);
  
    if(entry) {
      curSdfTree = ATelementAt((ATermList)entry, SYN_LOC);
      if(!ATisEqual(curSdfTree, newSdfTree)) {
        entry = (ATerm)ATreplace((ATermList)entry, newSdfTree,
                                 SYN_LOC);
        entry = (ATerm)ATreplace((ATermList)entry, Mtrue,
                                 SYN_UPDATED_LOC);
  
        entry = (ATerm)ATreplace((ATermList)entry,
                       ATparse("unavailable"), EQS_TABLE_LOC);
        entry = (ATerm)ATreplace((ATermList)entry,
                       ATparse("unavailable"), TRM_TABLE_LOC);
        PutValue(new_modules_db, atModuleName, entry);

        chg_mods = modules_depend_on(atModuleName,ATempty);
        update_syntax_status_of_modules(chg_mods); 
        imports = get_import_section_sdf2(newSdfTree);
        unknowns = replace_imports(atModuleName,imports);
        import_graph = calc_import_graph();

        return ATmake("snd-value(imports(changed-modules([<term>,<list>]),"
		      "need-modules([<list>]),<term>))",
		      atModuleName, chg_mods, unknowns, import_graph);
      } else {
        import_graph = calc_import_graph();
  
        return ATmake("snd-value(imports(changed-modules([<list>]),"
                      "need-modules([<list>]),<term>))",
                      ATempty, ATempty, import_graph);
      }
    }
    else {
      return ATmake("snd-value(name-consistency-error(<str>))", 
                    moduleName);
    }
  } else {
    ATerror("not an asfix module: %t\n", newSdfTree);
    return NULL; 
  }
}

ATerm add_empty_module(int cid, char *moduleName)
{
  ATerm atModuleName, entry, importGraph;
  ATermList discardValue;
  char  fileName[1024] = {'\0'};

  atModuleName = ATmake("<str>",  moduleName);
  sprintf(fileName,"%s%s", moduleName, ".sdf2");
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
  PutValue(new_modules_db, ATmake("<str>", moduleName), entry);

  discardValue = add_imports(atModuleName, ATempty);
  importGraph = calc_import_graph();

  return ATmake("snd-value(empty-module-added(<term>))", importGraph);
}

void add_tree_eqs_section(int cid, char *moduleName, char* path,
                          ATerm eqsTree, char *eqsText, int timestamp)
{
  ATerm entry;
  ATerm isChanged = Mfalse;
  ATerm atModuleName, atEqsText;

  atModuleName = ATmake("<str>", moduleName);
  atEqsText = ATmake("<str>", eqsText);

  eqsTree = AFaddPosInfoToModule(path, eqsTree);

  entry = GetValue(new_modules_db, atModuleName);
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
  PutValue(new_modules_db, atModuleName, entry);
}

void add_text_eqs_section(int cid, char *moduleName, char* path, 
                          char *eqsText, int timestamp)
{
  ATerm entry;
  ATerm isChanged = Mtrue;
  ATerm atModuleName;
  ATerm atEqsText;

  atModuleName = ATmake("<str>", moduleName);
  atEqsText = ATmake("<str>", eqsText);

  entry = GetValue(new_modules_db, atModuleName);

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
  PutValue(new_modules_db, atModuleName, entry);
}

void add_empty_eqs_section(int cid, char *moduleName, char* path)
{
  ATerm entry;
  ATerm isChanged = Mfalse;
  ATerm atModuleName, atEqsText;

  atModuleName = ATmake("<str>", moduleName);
  atEqsText = ATmake("\"\"");

  entry = GetValue(new_modules_db, atModuleName);
  entry = (ATerm)ATreplace((ATermList)entry,
                           ATmake("<str>", path),
                           PATH_EQS_LOC);
  entry = (ATerm)ATreplace((ATermList)entry,
                           isChanged,
                           EQS_UPDATED_LOC);
  entry = (ATerm)ATreplace((ATermList)entry, atEqsText, EQS_TEXT_LOC);
  PutValue(new_modules_db, atModuleName, entry);
}

ATerm update_eqs_tree(int cid, char *moduleName, ATerm newEqsTree)
{
  ATerm entry;
  ATerm curEqsTree;
  ATerm atModuleName, atPath;
  ATermList changedModules;
  char *path;

  atModuleName = ATmake("<str>", moduleName);

  entry = GetValue(new_modules_db, atModuleName);

  curEqsTree = ATelementAt((ATermList)entry, EQS_TREE_LOC);

  atPath = ATelementAt((ATermList)entry, PATH_EQS_LOC);
  if (ATmatch(atPath, "<str>", &path)) {
    newEqsTree = AFaddPosInfoToModule(path, newEqsTree);
  } else {
    ATwarning("No path for %s equations section\n", moduleName);
  }

  if (!ATisEqual(newEqsTree, curEqsTree)) {
    entry = (ATerm)ATreplace((ATermList)entry, newEqsTree, EQS_TREE_LOC);
    PutValue(new_modules_db, atModuleName, entry);
    changedModules = modules_depend_on(atModuleName, ATempty);
    return ATmake("snd-value(changed-modules([<term>,<list>]))",
      atModuleName, changedModules);
  } else {
    return ATmake("snd-value(changed-modules([]))");
  }
}

ATerm add_parse_table(int cid, char *module, char *table, 
                               ATerm tableType, int timestamp)
{
  ATerm entry, modname;

  modname = ATmake("<str>",module);

  entry = GetValue(new_modules_db, modname);
  if (ATisEqual(tableType, ATmake("eqs"))) {
    entry = (ATerm)ATreplace((ATermList)entry,
                             ATmake("table(<str>)", table),
                             EQS_TABLE_LOC); 
    entry = (ATerm)ATreplace((ATermList)entry,
                             (ATerm)ATmakeInt(timestamp),
                             EQS_TABLE_TIME_LOC);
  } else {
    entry = (ATerm)ATreplace((ATermList)entry,
                             ATmake("table(<str>)", table),
                             TRM_TABLE_LOC); 
    entry = (ATerm)ATreplace((ATermList)entry,
                             (ATerm)ATmakeInt(timestamp),
                             TRM_TABLE_TIME_LOC);
  }
  PutValue(new_modules_db, modname, entry);
  return ATmake("snd-value(parse-table-added)");
}

/* Get the path to module modulename. type is either eqs or sdf2,
   because eqs path can be empty, and sdf2 path cannot be empty... It
   would probably be better to add an empty eqs module to the db
   whenever a sdf2 module is entered, but that requires thought, and
   right now it's too warm for thinking :-) */

ATerm get_path(int cid, char *modulename, ATerm type)
{
  ATerm entry, place, modname;
  char *path;
  int location = 0; /* to keep compiler happy */

  if (ATmatch(type,"eqs")) {
      location = PATH_EQS_LOC;
  } else if (ATmatch(type,"sdf2")) {
      location = PATH_SYN_LOC;
  } else {
      ATerror("Unsupported database type: %t", type);
  }
  modname = ATmake("<str>",modulename);
  entry = GetValue(new_modules_db, modname);
  place = ATelementAt((ATermList)entry, location);
  if(ATmatch(place,"<str>",&path)) {
      return ATmake("snd-value(path(<str>))",path);
  } else if (location == PATH_EQS_LOC) {
      /* found an empty equation section. Return empty path */
      return ATmake("snd-value(path(<str>))","");
  } else {
      ATerror("Module not in database!!!");
      return NULL;
  }
}

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
  entry = GetValue(new_modules_db, modname);
  isChanged = ATelementAt((ATermList)entry, updated_location);
  asfix = ATelementAt((ATermList)entry, location);
  if(ATisEqual(isChanged, Mtrue)) {
    if(ATisEqual(asfix, ATparse("unavailable"))) {
	return ATmake("snd-value(unavailable)");
    } else {
      isChanged = Mfalse;
      entry = (ATerm)ATreplace((ATermList)entry,
                               isChanged,
                               updated_location);
      PutValue(new_modules_db, modname, entry);
      if (module_type == sdf2) {
	  return ATmake("snd-value(syntax(<term>))", asfix);
      } else if (module_type == eqs) {
	  return ATmake("snd-value(tree(<term>))", asfix);
      }
    }
  } else {
      /* isChanged = false */
      if (module_type == eqs) {
	  asfix = ATelementAt((ATermList)entry, location);
	  if(ATisEqual(asfix, ATparse("unavailable"))) {
	    return ATmake("snd-value(unavailable)");
	  } else {
	      return ATmake("snd-value(tree(<term>))", asfix);
	  }
      } else if (module_type == sdf2) {
	  return ATmake("snd-value(syntax-unchanged(<term>))",asfix);
      }
  }
  /* we never get here */
  ATerror("Error in get_asfix");
  return NULL;
}

ATbool is_valid_parse_table(ATermList visited, ATerm module, 
                            int timeOfEqsTable, int timeOfTrmTable);

ATerm get_parse_table(int cid, char *modulename, ATerm tableType)
{
  ATermList entry;
  ATerm     table, modname;
  char      *place;
  int tableLoc;

  if(ATisEqual(tableType, ATmake("eqs"))) {
    tableLoc = EQS_TABLE_LOC;
  } else {
    tableLoc = TRM_TABLE_LOC;
  }
  modname = ATmake("<str>", modulename);
  if((entry = (ATermList) GetValue(new_modules_db, modname))) {
    table = ATelementAt((ATermList)entry, tableLoc);
    if(ATmatch(table,"table(<str>)", &place))
      return ATmake("snd-value(table(<str>))",place);
  }
  return ATmake("snd-value(no-table)");
}

/* This function traverses the import graph and visit all nodes
 * to check whether the parse tables are still valid and 
 * invalidates the parse table and "removes" the parse
 * tree of the equations section if necessary.
 */
void mdb_invalidate_parse_tables(ATermList visited, char *modulename)
{
  int timeOfEqsTable, timeOfTrmTable;
  char *imported_modulename;
  ATermList imports;
  ATerm import,modname;
  ATermList entry;

  modname = ATmake("<str>",modulename);
  entry = (ATermList)GetValue(new_modules_db, modname);
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
        PutValue(new_modules_db, modname, (ATerm)entry);
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

void invalidate_parse_tables(int cid, char *modulename)
{
  mdb_invalidate_parse_tables(ATempty,modulename);
}

ATermList get_import_section(ATermList sections)
{
  ATerm t[2];
  ATerm section, import;
  ATermList imps;
  ATermList imports = ATempty, import_strings = ATempty;
  char *str;

/* Traverse the list of section to find the import section. */
  imps = ATempty;
  while(!ATisEmpty(sections)) {
    section = ATgetFirst(sections);
    if(ATmatchTerm(section,pattern_asfix_imports, &t[0], &t[1], &imps))
      imports = ATconcat(imports,imps);
    sections = ATgetNext(sections);
  };
  imports = asfix_filter_layout(imports);
  while(!ATisEmpty(imports)) {
      import = ATgetFirst(imports);
      if (ATmatchTerm(import,pattern_asfix_id,&str)) {
	  import_strings = ATinsert(import_strings,ATmake("<str>",str));
      }
      imports = ATgetNext(imports);
  }
  return import_strings;
}

/* If a module is delete a list of depending modules
 * should be calculated and returned.
 */
ATerm delete_module(int cid, char *moduleName)
{
  ATerm name = ATmake("<str>",moduleName);
  ATermList changedMods;

  changedMods = modules_depend_on(name,ATempty);
  update_syntax_status_of_modules(changedMods); 
  RemoveKey(new_modules_db,name);
  RemoveKey(import_db,name);
  trans_db = CreateValueStore(100,75);
  return ATmake("snd-value(changed-modules([<term>,<list>]))",
                name, changedMods);
}

ATermList select_unknowns(ATermList mods)
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

ATermList add_imports(ATerm name, ATermList mods)
{
  ATermList unknowns = ATempty;

  trans_db = CreateValueStore(100,75);
  if(!GetValue(import_db,name)) {
    PutValue(import_db, name, (ATerm) mods);
    unknowns = select_unknowns(mods);
  }
  return unknowns;
}

ATermList replace_imports(ATerm name, ATermList mods)
{
  trans_db = CreateValueStore(100,75);
  ATtableRemove(import_db, name);
  PutValue(import_db, name, (ATerm) mods);
  return select_unknowns(mods);
}

ATbool complete_sdf2_specification(ATermList visited, ATerm module)
{
  ATerm entry, asfix;

  if(ATindexOf(visited, module, 0) < 0) {
    entry = GetValue(new_modules_db, module);
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

ATbool is_valid_parse_table(ATermList visited, ATerm module, 
                            int timeOfEqsTable, int timeOfTrmTable)
{
  ATbool result;
  ATermList imports;
  ATerm first, entry;
  int time;

  entry = GetValue(new_modules_db, module);
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

			entry = (ATermList)GetValue(new_modules_db, first);
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

ATbool complete_asf_specification(ATermList visited, ATerm module)
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
      entry = GetValue(new_modules_db, first);
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

ATbool complete_asf_sdf2_specification(ATerm module)
{
  if(complete_sdf2_specification(ATempty,module))
    return complete_asf_specification(ATempty, module);
  else
    return ATfalse;
}

ATermList calc_trans(ATermList todo)
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

ATerm eqs_available_for_modules(int cid, char *moduleName)
{
  ATerm module, entry, eqsText;
  ATerm eqsTree;
  ATerm atModuleName;
  ATermList result = ATempty;
  ATermList modules;

  atModuleName = ATmake("<str>",moduleName);
  if(GetValue(new_modules_db, atModuleName)) {
    /* Get all imported modules (including the module itself) */
    modules = get_imported_modules(atModuleName);

    while (!ATisEmpty(modules)) {
      module = ATgetFirst(modules);
      entry = GetValue(new_modules_db, module);
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

ATerm get_eqs_text(int cid, char *moduleName)
{
  ATerm eqsText;
  ATerm atName, entry;

  atName = ATmake("<str>",moduleName);
  
  entry = GetValue(new_modules_db, atName);
  eqsText = ATelementAt((ATermList)entry, EQS_TEXT_LOC);
  if (!ATisEqual(eqsText, ATparse("unavailable"))) {
    return ATmake("snd-value(eqs-text(<str>,<term>))", moduleName, eqsText);
  } else {
    return ATmake("snd-value(no-eqs-text(<str>))", moduleName);
  }
}

ATerm get_all_modules(int cid)
{
  ATermList list = ATtableKeys(import_db);

  return ATmake("snd-value(all-modules([<list>]))",list);
}

/* The function "module_depend_on" determines which modules
   depend on the module "name" with respect to the import graph. */
ATermList modules_depend_on(ATerm name, ATermList dependent)
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

/* A number of function to deal with modules which are recognized
   via Sdf2. */

char *get_module_name(ATerm module)
{
  ATerm t[2], elem;
  ATermList args;
  char *text;

  if(ATmatchTerm(module,pattern_asfix_appl,
                 &t[0], &t[1], &args)) {
    elem = ATelementAt(args,2);
    if(ATmatchTerm(elem,pattern_asfix_appl,
                   &t[0], &t[1], &args)) {
      elem = ATelementAt(args,0);
      if(ATmatchTerm(elem,pattern_asfix_lex, &text, &t[0])) {
        return text;
      }
      else {
        ATerror("Not a correct Sdf2 module: %t\n", module);
        return NULL;
      }
    }
    else {
      ATerror("Not a correct Sdf2 module: %t\n", module);
      return NULL;
    }
  }
  else {
    ATerror("Not a correct Sdf2 module: %t\n", module);
    return NULL;
  }
}

ATermList filter_import_names(ATermList imps)
{
  ATerm t[2], elem, arg;
  ATermList args, imports = ATempty;
  char *text;

  while(!ATisEmpty(imps)) {
    elem = ATgetFirst(imps);
    if(ATmatchTerm(elem,pattern_asfix_appl,
                   &t[0], &t[1], &args)) {
      arg = ATelementAt(args,0);
      if(ATmatchTerm(arg,pattern_asfix_appl,
                     &t[0], &t[1], &args)) {
        elem = ATelementAt(args,0);
        if(ATmatchTerm(elem,pattern_asfix_lex,
                       &text, &t[0])) {
          imports = ATinsert(imports,ATmake("<str>",text));
        }
      }
    }
    imps = ATgetNext(imps);
  }
  return imports;
}

ATermList filter_import_list(ATermList imps)
{
  ATerm t[2], elem, arg;
  ATermList args, elems, imports = ATempty;

  while(!ATisEmpty(imps)) {
    elem = ATgetFirst(imps);
    if(ATmatchTerm(elem,pattern_asfix_appl,
                   &t[0], &t[1], &args)) {
      arg = ATelementAt(args,2);
      if(ATmatchTerm(elem,pattern_asfix_appl,
                     &t[0], &t[1], &args)) {
        elem = ATelementAt(args,2);
        if(ATmatchTerm(elem,pattern_asfix_appl,
                       &t[0], &t[1], &args)) {
          elem = ATelementAt(args,0);
          if(ATmatchTerm(elem,pattern_asfix_list,
                         &t[0], &t[1], &elems)) {
            imports = ATconcat(imports,filter_import_names(elems));
          }
        }
      }
    }
    imps = ATgetNext(imps);
  }
  return imports;
}

ATermList AFTgetImports(ATerm mod);

ATermList get_import_section_sdf2(ATerm module)
{
  return filter_import_list(AFTgetImports(module));
}

ATerm make_main_module(ATerm mainname)
{
  ATerm result = NULL,result1,result2,result3;
  char *text;

  result1 = ATmakeTerm(pattern_asfix_list,
                      ATparse("iter(sort(\"Section\"),w(\"\"),l(\"*\"))"),
                      pattern_asfix_ews,
                      ATmakeList0());
  result1 = ATmakeTerm(pattern_asfix_appl,
                      ATparse("prod(id(\"Modular-Sdf-Syntax\"),w(\"\"),[iter(sort(\"Section\"),w(\"\"),l(\"*\"))],w(\"\"),l(\"->\"),w(\"\"),sort(\"Sections\"),w(\"\"),no-attrs)"),
                      pattern_asfix_ews,
                      ATmakeList1(result1));
  if(ATmatchTerm(mainname,pattern_asfix_id,&text)) {
    result2 = ATmakeTerm(pattern_asfix_lex,
                         text,
                         ATparse("sort(\"ModuleId\")"));
    result2 = ATmakeTerm(pattern_asfix_appl,
                         ATparse("prod(id(\"Modular-Sdf-Syntax\"),w(\"\"),[sort(\"ModuleId\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ModuleName\"),w(\"\"),no-attrs)"),
                         pattern_asfix_nlws,
                         ATmakeList1(result2));
    result2 = ATmakeTerm(pattern_asfix_appl,
                         ATparse("prod(id(\"Modular-Sdf-Syntax\"),w(\"\"),[sort(\"ModuleName\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Import\"),w(\"\"),no-attrs)"),
                         pattern_asfix_ews,
                         ATmakeList1(result2));
    result2 = ATmakeTerm(pattern_asfix_list,
                         ATparse("iter(sort(\"Import\"),w(\"\"),l(\"*\"))"),
                         pattern_asfix_ews,
                         ATmakeList1(result2));
    result2 = ATmakeTerm(pattern_asfix_appl,
                         ATparse("prod(id(\"Modular-Sdf-Syntax\"),w(\"\"),[iter(sort(\"Import\"),w(\"\"),l(\"*\"))],w(\"\"),l(\"->\"),w(\"\"),sort(\"Imports\"),w(\"\"),no-attrs)"),
                         pattern_asfix_ews,
                         ATmakeList1(result2));
    result2 = ATmakeTerm(pattern_asfix_appl,
                         ATparse("prod(id(\"Modular-Sdf-Syntax\"),w(\"\"),[ql(\"imports\"),w(\"\"),sort(\"Imports\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ImpSection\"),w(\"\"),no-attrs)"),
                         pattern_asfix_ews,
                         ATmakeList3(ATparse("l(\"imports\")"),
                                     pattern_asfix_ews,
                                     result2));
    result2 = ATmakeTerm(pattern_asfix_list,
                         ATparse("iter(sort(\"ImpSection\"),w(\"\"),l(\"*\"))"),
                         pattern_asfix_ews,
                         ATmakeList1(result2));
    result3 = ATmakeTerm(pattern_asfix_lex,
                         "Main",
                         ATparse("sort(\"ModuleId\")"));
    result3 = ATmakeTerm(pattern_asfix_appl,
                         ATparse("prod(id(\"Modular-Sdf-Syntax\"),w(\"\"),[sort(\"ModuleId\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ModuleName\"),w(\"\"),no-attrs)"),
                         pattern_asfix_ews,
                         ATmakeList1(result3));
    result = ATmakeTerm(pattern_asfix_appl,
                        ATparse("prod(id(\"Modular-Sdf-Syntax\"),w(\"\"),[ql(\"module\"),w(\"\"),sort(\"ModuleName\"),w(\"\"),iter(sort(\"ImpSection\"),w(\"\"),l(\"*\")),w(\"\"),sort(\"Sections\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Module\"),w(\"\"),no-attrs)"),
                        pattern_asfix_ews,
                        ATmakeList(7,ATparse("l(\"module\")"),
                                     pattern_asfix_ws,
                                     result3,
                                     pattern_asfix_nlws,
                                     result2,
                                     pattern_asfix_nlws,
                                     result1));
  }
  return result;
}


ATerm make_name_term(ATerm name)
{
  ATerm result = NULL;
  char *text;

  if(ATmatch(name,"<str>",&text)) {
    result = ATmakeTerm(pattern_asfix_lex,
                        text,
                        ATparse("sort(\"ModuleId\")"));
    result = ATmakeTerm(pattern_asfix_appl,
                         ATparse("prod(id(\"Modular-Sdf-Syntax\"),w(\"\"),[sort(\"ModuleId\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ModuleName\"),w(\"\"),no-attrs)"),
                         pattern_asfix_nlws,
                         ATmakeList1(result));
  }
  return result;
}

ATerm get_syntax(ATerm name, ATermList modules)
{
  ATermList syntaxes = ATempty;
  ATerm t[8], nameterm, appl, elem, module, result, term, entry;


  nameterm = make_name_term(name);
  while(!ATisEmpty(modules)) {
    elem = ATgetFirst(modules); 
    entry = GetValue(new_modules_db,elem);
    module = ATelementAt((ATermList)entry, SYN_LOC);
    if(ATmatchTerm(module,pattern_asfix_term,
                   &t[0], &t[1], &t[2], &t[3], &t[4], &t[5],
                   &appl, &t[6], &t[7])) { 
      if(ATisEmpty(syntaxes))
        syntaxes = ATinsert(syntaxes,appl);
      else {
        syntaxes = ATinsert(syntaxes,pattern_asfix_ews);
        syntaxes = ATinsert(syntaxes,appl);
      }
    }
    modules = ATgetNext(modules);
  }
  result = ATmakeTerm(pattern_asfix_list,
                      ATparse("iter(sort(\"Module\"),w(\"\"),l(\"*\"))"),
                      pattern_asfix_ews,
                      syntaxes);
  result = ATmakeTerm(pattern_asfix_appl,
                      ATparse("prod(id(\"Modular-Sdf-Syntax\"),w(\"\"),[iter(sort(\"Module\"),w(\"\"),l(\"*\"))],w(\"\"),l(\"->\"),w(\"\"),sort(\"Definition\"),w(\"\"),no-attrs)"),
                      pattern_asfix_ews,
                      ATmakeList1(result));
  result = ATmakeTerm(pattern_asfix_appl,
                      ATparse("prod(id(\"Sdf2-Syntax\"),w(\"\"),[ql(\"definition\"),w(\"\"),sort(\"Definition\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"SDF\"),w(\"\"),no-attrs)"),
                      pattern_asfix_ews,
                      ATmakeList3(ATparse("l(\"definition\")"),
                                  pattern_asfix_ws,
                                  result));
  term = ATmakeTerm(pattern_asfix_term,
                    ATparse("l(\"term\")"),
                    pattern_asfix_ews,
                    ATparse("l(\"X\")"),
                    pattern_asfix_ews,
                    ATparse("id(\"X\")"),
                    pattern_asfix_ews,
                    result,
                    pattern_asfix_ews,
                    ATparse("no-abbreviations"));
  return term;
}

ATerm get_all_sdf2_definitions(int cid, char *modulename)
{
  ATerm result, name;
  ATermList imports;

  name = ATmake("<str>",modulename);
  if(complete_sdf2_specification(ATempty,name)) {
    imports = get_imported_modules(name);
    result = get_syntax(name,imports);
    return ATmake("snd-value(syntax(<term>))",result);
  }
  else {
    return ATmake("snd-value(sdf2-definition-error(\"Specification is incomplete, can not generate parse table\"))");
  }
}

ATerm unique_new_name(ATerm name)
{
  char *text, *newtext;
  ATerm newname;
  int n = 1;

  if(ATmatch(name,"<str>",&text)) {
    newtext = malloc(strlen(text)+16);
    sprintf(newtext,"AUX-%s%d",text,n);
    newname = ATmake("<str>",newtext);
    while(GetValue(compile_db,newname)) {
      n++;
      sprintf(newtext,"AUX-%s%d",text,n);
      newname = ATmake("<str>",newtext);
    }
    free(newtext);
    return newname;
  }
  else {
    ATerror("illegal name %t\n", name);
    return NULL; /* silence the compiler */
  }
}

void gen_makefile(ATerm name)
{
  char *text, *mtext;
  char *path;
  char buf[1024];
  FILE *output;
  ATerm module;
  ATermList modules = ATtableKeys(compile_db);

  if(ATmatch(name,"<str>",&text)) {
      path = get_output_dir();
    sprintf(buf, "%s/%s.module-list", path, text);
    output = fopen(buf,"w");
    if(!output)
      ATfprintf(stderr,"Cannot open file %s\n",buf);
    else {
      fprintf( output, "# Generated automatically, please do not edit.\n" );
      while (!ATisEmpty(modules)) {
        module = ATgetFirst(modules);
        if(ATmatch(module,"<str>",&mtext)) {
          ATfprintf(output,"%s.c\n", mtext);
        }
        modules = ATgetNext(modules);
      }
      fclose( output );

      sprintf(buf, "cd %s; %s/genmakefile %s", path, BINDIR, text);
      system(buf);
    }
  }
  else
    ATerror("illegal name %t\n", name);
}

void process_next_module(int cid)
{
  ATerm event;

  if(!ATisEmpty(modules_to_process)) {
    compiling = ATtrue;
    event = ATgetFirst(modules_to_process);
    modules_to_process = ATgetNext(modules_to_process);
    ATBwriteTerm(cid,event);
  }
  else {
    compiling = ATfalse;
    if(!reshuffling) {
      gen_makefile(top_module);
      ATwarning("Compilation completed\n");
      ATBwriteTerm(cid,ATmake("snd-event(done)"));
    }
  }
}

void rec_ack_event(int cid, ATerm term)
{
  char *name;
  ATerm mod;

  if(ATmatch(term,"new-aux-module(<str>,<term>)",&name,&mod)) {
    process_next_module(cid);
  }
  else if(ATmatch(term,"done")) {
    compiling = ATfalse;
  }
  else
    exit(1);
}

void AFTreshuffleModules(int cid, ATermList mods);

void reshuffle_modules_from(int cid, char *modulename)
{
  ATerm mod;
  ATermList imports;

  mod = ATmake("<str>",modulename);
  if(GetValue(new_modules_db, mod)) {
    /* We are working with the term asfix representation. */
    if(complete_asf_sdf2_specification(mod)) {
      top_module = mod;
      modules_to_process = ATempty;
      imports = get_imported_modules(mod);
      AFTreshuffleModules(cid,imports);
    }
    else {
      ATwarning("Specification is incomplete and can not be compiled!\n");
      ATBwriteTerm(cid,ATmake("snd-event(done)"));
    }
  }
  else {
    ATwarning("Module %t not in module databases!\n", mod);
    ATBwriteTerm(cid,ATmake("snd-event(done)"));
  } 
}

void usage(char *prg, ATbool is_err)
{
    ATwarning("usage: %s [aterm-options] [toolbus-options]\n", prg);
    ATwarning("use '%s -at-help' to get more options.\n", prg);
    ATwarning("This program can only be used as a ToolBus tool!\n");
    exit(is_err ? 1 : 0);
}

void version(const char *msg)
{
    ATwarning("%s v%s\n", msg, myversion);
    exit(1);
}


/* Main program */
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

  ATBinit(argc, argv,&bottomOfStack);
  AFinit(argc, argv, &bottomOfStack);


  cid = ATBconnect(NULL, NULL, -1, module_db_handler);

  ATprotect((ATerm *)&modules_to_process);

  ATBeventloop();

  return 0;
}
