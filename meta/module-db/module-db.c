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
   void delete_module(char *modulename)
   ATerm add_module(ATerm asfix)
   ATerm add_empty_module(char* modulename)
   ATerm add_sdf2_module(char* path, ATerm asfix, 
                         int timestamp, char* changed)
   ATerm update_sdf2_module(ATerm asfix)
   ATerm add_eqs_module(char* odulename, char* path, ATerm eqs,
                        int timestamp, char* changed)
   ATerm update_eqs_for_modules(char *modulename)
   ATerm get_path(char *modulename, ATerm type)
   ATerm get_asfix(char *modulename, ATerm type)
   ATerm get_all_sdf2_definitions(char *modulename)
   ATerm get_all_equations(char *modulename)
   ATerm get_parse_table(char *modulename)
   ATerm add_parse_table(char *modulename, char *table, int timestamp)
   ATerm validate_parse_tables(char *modulename)
   ATerm get_all_modules()
   void process_next_module()
   void reshuffle_modules_from(char *modulename)
*/

#include "module-db.h"

ATermTable modules_db;
ATermTable new_modules_db;
ATermTable import_db;
ATermTable trans_db;

/* Declaration for the reshuffling phase. */
ATermList modules_to_process;
ATbool compiling = ATfalse;
ATbool reshuffling = ATfalse;
ATerm top_module;
ATermTable compile_db;

void rec_terminate(int cid, ATerm t)
{
  exit(0);
}

ATerm exists(int cid, char *modulename)
{
  ATerm name = ATmake("<str>",modulename);
  if(GetValue(modules_db,name) || GetValue(new_modules_db,name))
    return ATmake("snd-value(result(exists(<term>)))", name);
  else
    return ATmake("snd-value(result(notexists(<term>)))", name);
}

ATermList get_imported_modules(ATerm name);

ATerm get_all_equations(int cid, char *modulename)
{
  ATerm mod, entry, eqsterm, name;
  ATermList eqs, mods;
  ATermList equations = ATempty;

/* calculate the transitive closure of the imported modules. */
  name = ATmake("<str>",modulename);
  mods = get_imported_modules(name);

  equations = ATempty;
  while(!ATisEmpty(mods)) {
    mod = ATgetFirst(mods);
    entry = GetValue(new_modules_db,mod);
    eqsterm = ATelementAt((ATermList)entry, EQS_LOC);
    eqs = AFTgetEqs(eqsterm);
    equations = ATconcat(equations, eqs); 
    mods = ATgetNext(mods);
  };

  return ATmake("snd-value(equations([<list>]))",equations);
}

void create_module_db(int cid)
{
  new_modules_db = CreateValueStore(100,75);
  modules_db = CreateValueStore(100,75);
  import_db = CreateValueStore(100,75);
  trans_db = CreateValueStore(100,75);
}

void clear_module_db(int cid)
{
  new_modules_db = CreateValueStore(100,75);
  modules_db = CreateValueStore(100,75);
  import_db = CreateValueStore(100,75);
  trans_db = CreateValueStore(100,75);
}

ATermList get_import_section(ATermList sections);
ATermList add_imports(ATerm name, ATermList mods);
char *get_module_name(ATerm module);
ATermList get_import_section_sdf2(ATerm module);

ATermList calc_import_relations(ATerm name)
{
  ATerm module, pair;
  ATermList result = ATempty;
  ATermList modules = ATtableKeys(import_db);

  while (!ATisEmpty(modules)) {
    module = ATgetFirst(modules);
    if(ATindexOf((ATermList) GetValue(import_db,module), name, 0) >= 0) {
      pair = ATmake("[<term>,<term>]", module, name);
      if(ATindexOf(result, pair, 0) < 0)
        result = ATappend(result, pair);
    };
    modules = ATgetNext(modules);
  }
  modules = (ATermList) GetValue(import_db,name);
  while (!ATisEmpty(modules)) {
    module = ATgetFirst(modules);
    pair = ATmake("[<term>,<term>]", name, module);
    if(ATindexOf(result, pair, 0) < 0)
      result = ATappend(result, pair);
    modules = ATgetNext(modules);
  }
  return result;
}

/*The Asf+Sdf variant */
ATerm add_module(int cid, ATerm asfix)
{
  ATerm t[8];
  ATerm modname, modname_term;
  ATermList sections, imports, unknowns, irels;
  ATerm newasfix;
  char *modname_str;

  if(ATmatchTerm(asfix,pattern_asfix_module,
                 &t[0], &t[1], &modname, &t[2],
                 &sections, &t[3], &t[4], &t[5], &t[6])) {
    if(ATmatchTerm(modname,pattern_asfix_id,&modname_str)) {
      modname_term = ATmake("<str>", modname_str);
      if(GetValue(modules_db,modname_term) == ATfalse) {
        newasfix = AFexpandModule(asfix);
        PutValue(modules_db,modname_term,newasfix);
      };
      imports = get_import_section(sections);
      unknowns = add_imports(modname_term,imports);
      irels = calc_import_relations(modname_term);
      return ATmake("snd-value(imports(<str>,need-modules([<list>]),irels([<list>])))",
                    modname_str,unknowns,irels);
    }
    else {
      ATerror("not an identifier: %t\n", modname);
      return NULL;
    }
  } else {
    ATerror("not an asfix module: %t\n", asfix);
    return NULL;
  }
}

/* The Sdf2 variant */
ATerm add_sdf2_module(int cid, char* path, ATerm asfix, 
                      int timestamp, char* changed)
{
  ATerm t[8];
  char *modname;
  ATerm modname_term,appl, entry;
  ATermList imports, unknowns, irels;
  ATerm status;
  char  newpath[1024] = {'\0'};

  if(!strcmp(changed,"changed")) {
    sprintf(newpath,"%s", path);
    status = Mtrue;
  }
  else {
    sprintf(newpath,"%s", path);
    status = Mfalse;
  }

  if(ATmatchTerm(asfix,pattern_asfix_term,
                 &t[0], &t[1], &t[2], &t[3], &t[4], &t[5],
                 &appl, &t[6], &t[7])) {
    modname = get_module_name(appl);
    modname_term = ATmake("<str>",modname);
    entry = (ATerm)ATmakeList(10,
                              ATmake("<str>",newpath), /* Path Sdf */
                              asfix,                   /* AsFix Sdf */
                              ATmakeInt(timestamp),    /* Time Sdf */
                              status,                  /* Status Sdf */
                              ATparse("unavailable"),  /* Path Eqs */
                              ATparse("unavailable"),  /* AsFix Eqs */
                              ATmakeInt(0),            /* Time Eqs */
                              Mtrue,                   /* Status Eqs: true */
                              ATparse("unavailable"),  /* Path PT */
                              ATmakeInt(0)
                             );
    PutValue(new_modules_db, modname_term, entry);
    imports = get_import_section_sdf2(asfix);
    unknowns = add_imports(modname_term,imports);
    irels = calc_import_relations(modname_term);
    return ATmake("snd-value(imports(<str>,need-modules([<list>]),irels([<list>])))",
                  modname,unknowns,irels);
  } else {
    ATerror("not an asfix module: %t\n", asfix);
    return NULL;
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
    entry = ATreplace(entry,ATparse("unavailable"),PATH_EQS_LOC);
    entry = ATreplace(entry,ATparse("unavailable"),EQS_LOC);
    entry = ATreplace(entry,Mtrue,EQS_UPDATED_LOC);
    entry = ATreplace(entry,ATparse("unavailable"),TABLE_LOC);
    PutValue(new_modules_db, modname, (ATerm)entry);
    mods = ATgetNext(mods);
  }
}

ATermList replace_imports(ATerm name, ATermList mods);
ATermList modules_depend_on(ATerm name, ATermList mods);

ATerm update_sdf2_module(int cid, ATerm asfix)
{
  ATerm t[8];
  char *module_string;
  ATerm oldasfix, modname, appl, entry;
  ATermList imports, unknowns, chg_mods, irels;
  ATerm place;
  char  *path;

  if(ATmatchTerm(asfix,pattern_asfix_term,
                 &t[0], &t[1], &t[2], &t[3], &t[4], &t[5],
                 &appl, &t[6], &t[7])) {
    module_string = get_module_name(appl);
    modname = ATmake("<str>", module_string);
    entry = GetValue(new_modules_db, modname);
    place = ATelementAt((ATermList)entry, PATH_SYN_LOC);

    oldasfix = ATelementAt((ATermList)entry, SYN_LOC);
    if(!ATisEqual(asfix,oldasfix)) {
      if(ATmatch(place,"<str>",&path)) {
        entry = (ATerm)ATmakeList(10,
                                  ATmake("<str>",path),
                                  asfix,
                                  ATmakeInt((int)time(NULL)),
                                  Mtrue,
                                  ATparse("unavailable"),
                                  ATparse("unavailable"),
                                  ATmakeInt(0),
                                  Mtrue,
                                  ATparse("unavailable"),
                                  ATmakeInt(0)
                                 );
        PutValue(new_modules_db, modname, entry);
        chg_mods = modules_depend_on(modname,ATempty);
        update_syntax_status_of_modules(chg_mods); 
        imports = get_import_section_sdf2(asfix);
        unknowns = replace_imports(modname,imports);
        irels = calc_import_relations(modname);
        return ATmake("snd-value(imports(<str>,need-modules([<list>]),irels([<list>])))",
                      module_string,unknowns,irels);
      } else {
         ATerror("no path available for %t\n", asfix);
         return NULL; /* Silence the compiler */
      }
    } 
    else {
      irels = calc_import_relations(modname);
      return ATmake("snd-value(imports(<str>,need-modules([<list>]),irels([<list>])))",
                    module_string,ATempty,irels);
      }
  }
  else {
    ATerror("not an asfix module: %t\n", asfix);
    return NULL; 
  }
}

ATerm add_empty_module(int cid, char *moduleName)
{
  ATerm entry;
  char  fileName[1024] = {'\0'};

  sprintf(fileName,"%s%s", moduleName, ".sdf2");
  entry = (ATerm)ATmakeList(10,
                            ATmake("<str>",fileName),
                            ATparse("unavailable"),
                            ATmakeInt(0),
                            Mtrue,
                            ATparse("unavailable"),
                            ATparse("unavailable"),
                            ATmakeInt(0),
                            Mtrue,
                            ATparse("unavailable"),
                            ATmakeInt(0)
                           );
  PutValue(new_modules_db, ATmake("<str>",moduleName), entry);
  return ATmake("snd-value(done)");
}

ATerm add_eqs_module(int cid, char *modulename, char* path, ATerm eqs, 
                              int timestamp, char* changed)
{
  ATerm entry;
  ATerm status;
  char   newpath[1024] = {'\0'};
  ATerm modname;

  modname = ATmake("<str>",modulename);
  if(!strcmp(changed,"changed")) {
    /*sprintf(newpath,"%s%s", path, ".baf");*/
    sprintf(newpath,"%s", path);
    status = Mtrue;
  }
  else {
    sprintf(newpath,"%s", path);
    status = Mfalse;
  }

  entry = GetValue(new_modules_db, modname);
  if(!ATisEqual(eqs,ATparse("error")) &&
     !ATisEqual(eqs,ATparse("no-equations"))) {

    eqs = AFaddPosInfoToModule(path, modulename, eqs);

  }
  entry = (ATerm)ATreplace((ATermList)entry,
                           ATmake("<str>",newpath),
                           PATH_EQS_LOC);
  entry = (ATerm)ATreplace((ATermList)entry,
                           status,
                           EQS_UPDATED_LOC);
  entry = (ATerm)ATreplace((ATermList)entry, eqs, EQS_LOC);
  entry = (ATerm)ATreplace((ATermList)entry, 
                           (ATerm)ATmakeInt(timestamp),
                           EQS_TIME_LOC);
  PutValue(new_modules_db, modname, entry);
  return ATmake("snd-value(done)");
}

ATerm add_parse_table(int cid, char *module, char *table, int timestamp)
{
  ATerm entry, modname;

  modname = ATmake("<str>",module);
/*ATwarning("Creation time %t.tbl is %d\n", modname, timestamp);*/
  entry = GetValue(new_modules_db, modname);
  entry = (ATerm)ATreplace((ATermList)entry,
                           ATmake("table(<str>)",table),
                           TABLE_LOC); 
  entry = (ATerm)ATreplace((ATermList)entry,
                           (ATerm)ATmakeInt(timestamp),
                           TABLE_TIME_LOC);
  PutValue(new_modules_db, modname, entry);
  return ATmake("snd-value(done)");
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
  ATerm status, modname;
  enum { sdf2, eqs } module_type = sdf2; /* to keep compiler happy */
  int location = 0, updated_location = 0; /* To keep compiler happy*/

  if (ATmatch(type,"sdf2")) {
      updated_location = SYN_UPDATED_LOC;
      location = SYN_LOC;
      module_type = sdf2;
  } else if (ATmatch(type, "eqs")) {
      updated_location = EQS_UPDATED_LOC;
      location = EQS_LOC;
      module_type = eqs;
  } else {
      ATerror("Type not supported by database: %t", type);
  }
  modname = ATmake("<str>",modulename);
  entry = GetValue(new_modules_db, modname);
  status = ATelementAt((ATermList)entry, updated_location);
  asfix = ATelementAt((ATermList)entry, location);
  if(ATisEqual(status,Mtrue)) {
    if(ATisEqual(asfix,ATparse("unavailable")) ||
       ATisEqual(asfix,ATparse("error"))) {
	return ATmake("snd-value(unavailable)");
    } else {
      status = Mfalse;
      entry = (ATerm)ATreplace((ATermList)entry,
                               status,
                               updated_location);
      PutValue(new_modules_db, modname, entry);
      if (module_type == sdf2) {
	  return ATmake("snd-value(syntax(<term>))", asfix);
      } else if (module_type == eqs) {
	  return ATmake("snd-value(eqs(<term>))", asfix);
      }
    }
  } else {
      /* status is false */
      if (module_type == eqs) {
	  asfix = ATelementAt((ATermList)entry, location);
	  if(ATisEqual(asfix,ATparse("unavailable")) ||
	     ATisEqual(asfix,ATparse("error"))) {
	      return ATmake("snd-value(unavailable)");
	  } else if(ATisEqual(asfix,ATparse("no-equations"))) {
	      return ATmake("snd-value(no-eqs)");
	  } else {
	      return ATmake("snd-value(eqs-unchanged(<term>))", asfix);
	  }
      } else if (module_type == sdf2) {
	  return ATmake("snd-value(syntax-unchanged(<term>))",asfix);
      }
  }
  /* we never get here */
  ATerror("Error in get_asfix");
  return NULL;
}

ATbool valid_parse_tables(ATermList visited, ATerm module, int time);

ATerm get_parse_table(int cid, char *modulename)
{
  ATermList entry;
  ATerm     table, modname;
  char      *place;

  modname = ATmake("<str>",modulename);
  if((entry = (ATermList) GetValue(new_modules_db, modname))) {
    table = ATelementAt((ATermList)entry, TABLE_LOC);
    if(ATmatch(table,"table(<str>)",&place))
      return ATmake("snd-value(table(<str>))",place);
  }

  return ATmake("snd-value(no-table)");
}

/* This function traverses the import graph and visit all nodes
   to check whether the parse tables are still valid.*/
void mdb_validate_parse_tables(ATermList visited, char *modulename)
{
  int time;
  char *imported_modulename;
  ATermList imports;
  ATerm import,modname;
  ATermList entry;

  modname = ATmake("<str>",modulename);
  entry = (ATermList)GetValue(new_modules_db, modname);
  if(entry) {
    time = ATgetInt((ATermInt)ATelementAt((ATermList)entry, TABLE_TIME_LOC));
/*ATwarning("Creation time of parse table %t is %d\n", modname, time);*/
    if(ATindexOf(visited, modname, 0) < 0) {
      if(!valid_parse_tables(ATempty, modname, time)) {
        entry = ATreplace(entry,ATparse("unavailable"),TABLE_LOC);
        PutValue(new_modules_db, modname, (ATerm)entry);
/*ATfprintf(stderr,"Parse table of %t invalidated\n", modname);*/
      }
      visited = ATinsert(visited, modname);
      imports = (ATermList)GetValue(import_db, modname);
      while(imports && !ATisEmpty(imports)) {
        import = ATgetFirst(imports);
	imported_modulename = ATgetName(ATgetAFun(import));
        mdb_validate_parse_tables(visited, imported_modulename);
        imports = ATgetNext(imports);
      }
    }
  }
}

ATerm validate_parse_tables(int cid, char *modulename)
{
    /* ATfprintf(stderr, "validation entered\n");*/
  mdb_validate_parse_tables(ATempty,modulename);
  return ATmake("snd-value(validation-done)");
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

ATerm delete_module(int cid, char *modulename)
{
  ATerm name = ATmake("<str>",modulename);
  RemoveKey(modules_db,name);
  RemoveKey(new_modules_db,name);
  RemoveKey(import_db,name);
  trans_db = CreateValueStore(100,75);
  return ATmake("snd-value(done)");
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

ATbool complete_specification(ATermList visited, ATerm module)
{
  if(ATindexOf(visited, module, 0) < 0) {
    if(GetValue(modules_db, module)) {
      ATerm first;
      ATbool result = ATtrue;
      ATermList imports = (ATermList) GetValue(import_db,module);

      visited = ATinsert(visited,module);
      while(!ATisEmpty(imports) && result) {
        first = ATgetFirst(imports);
        result = complete_specification(visited,first);
        imports = ATgetNext(imports);
      }
      return result;
    }
    else {
      ATfprintf(stderr,"%t is missing\n",module);
      return ATfalse;
    }
  }
  else
    return ATtrue;
}

ATbool complete_sdf2_specification(ATermList visited, ATerm module)
{
  ATerm entry, asfix;

  if(ATindexOf(visited, module, 0) < 0) {
    entry = GetValue(new_modules_db, module);
    asfix = ATelementAt((ATermList)entry, SYN_LOC);
    if(!ATisEqual(asfix,ATparse("unavailable"))) {
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
      ATfprintf(stderr,"Sdf2: %t is missing\n",module);
      return ATfalse;
    }
  }
  else
    return ATtrue;
}

ATbool valid_parse_tables(ATermList visited, ATerm module, int timetable)
{
  ATbool result;
  ATermList imports;
  ATerm first, entry;
  int time;

  entry = GetValue(new_modules_db, module);
  time = (int)ATelementAt((ATermList)entry, SYN_TIME_LOC);
  time = ATgetInt((ATermInt)ATelementAt((ATermList)entry, SYN_TIME_LOC));
/*ATfprintf(stderr,"Creation time of %t.sdf2 is %d\n", module, time);*/
  if(time > timetable) 
    result = ATfalse;
  else
    result = ATtrue;
  if(ATindexOf(visited, module, 0) < 0) {
    imports = (ATermList)GetValue(import_db,module);
    visited = ATinsert(visited, module);
    while(imports && !ATisEmpty(imports)) {
      first = ATgetFirst(imports);
      result = result && valid_parse_tables(visited, first, timetable);
      imports = ATgetNext(imports);
    };
    return result;
  }
  else
    return result;
}

ATbool complete_asf_specification(ATermList visited, ATerm module)
{
  ATerm first, entry, asfix;
  ATbool result;
  ATermList imports;

  if(ATindexOf(visited, module, 0) < 0) { 
    result = ATtrue;
    imports = (ATermList) GetValue(import_db,module);

    visited = ATinsert(visited,module); 
    
    while(!ATisEmpty(imports) && result) {
      first = ATgetFirst(imports);
      entry = GetValue(new_modules_db, first);
      asfix = ATelementAt((ATermList)entry, EQS_LOC);
      if(ATisEqual(asfix,ATparse("unavailable")) ||
         ATisEqual(asfix,ATparse("error")))
        result = ATfalse;
      else {
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

ATerm update_eqs_for_modules(int cid, char *modulename)
{
  ATerm module, entry, eqs, name;
  ATermList result = ATempty;
  ATermList modules;

  name = ATmake("<str>",modulename);
  if(GetValue(new_modules_db, name)) {
    modules = get_imported_modules(name);

    while (!ATisEmpty(modules)) {
      module = ATgetFirst(modules);
      entry = GetValue(new_modules_db, module);
      eqs = ATelementAt((ATermList)entry, EQS_LOC);
      if(ATisEqual(eqs,ATparse("unavailable")))
        result = ATinsert(result,module);
      modules = ATgetNext(modules);
    }
  }
  return ATmake("snd-value(modules([<list>]))",result);
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
    ATfprintf(stderr,
              "Specification is incomplete, can not generate parse table\n");
    return ATmake("snd-value(syntax(done)))");
  }
}

/* Basic reshuffling functionality */
char *output_path = ".";

void initialize_output_path(ATerm name)
{
  top_module = name;
  if( getenv( "COMPILER_OUTPUT" ) != NULL )
     output_path = getenv( "COMPILER_OUTPUT" );
  else {
    if( getenv( "TMPDIR" ) != NULL )
       output_path = getenv( "TMPDIR" );
    ATfprintf(stderr,"COMPILER_OUTPUT not set, using %s\n", output_path);
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
  char buf[1024];
  FILE *output;
  ATerm module;
  ATermList modules = ATtableKeys(compile_db);

  if(ATmatch(name,"<str>",&text)) {

    sprintf(buf, "%s/%s.module-list", output_path, text);
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

      sprintf(buf, "cd %s; %s/genmakefile.sh %s", output_path, BINDIR, text );
      ATfprintf(stderr,"Executing: %s\n", buf );
      system(buf );
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
      ATfprintf(stderr,"Compilation completed\n");
      ATBwriteTerm(cid,ATmake("snd-event(done)"));
    }
  }
}

void rec_ack_event(int cid, ATerm term)
{
  char *name;
  ATerm mod;

  if(ATmatch(term,"generate-code(<str>,<term>)",&name,&mod)) {
    process_next_module(cid);
  }
  else if(ATmatch(term,"done")) {
    compiling = ATfalse;
  }
  else
    exit(1);
}

void AFTreshuffleModules(int cid, ATermList mods);
void AFreshuffleModules(int cid, ATermList mods);

void reshuffle_modules_from(int cid, char *modulename)
{
  ATerm mod;
  ATermList imports;

  mod = ATmake("<str>",modulename);
  if(GetValue(new_modules_db, mod)) {
    /* We are working with the term asfix representation. */
    if(complete_asf_sdf2_specification(mod)) {
	/*      ATfprintf(stderr,"Reshuffling ... \n");*/
      initialize_output_path(mod);
      modules_to_process = ATempty;
      imports = get_imported_modules(mod);
      AFTreshuffleModules(cid,imports);
      /*      ATfprintf(stderr,"Finished reshuffling\n");*/
    }
    else {
      ATfprintf(stderr,
                "Specification is incomplete and can not be compiled!\n");
      ATBwriteTerm(cid,ATmake("snd-event(done)"));
    }
  }
  else if(GetValue(modules_db, mod)) {
    /* We are working with the module asfix representation. */
    if(complete_specification(ATempty,mod)) {
	/*      ATfprintf(stderr,"Reshuffling ... \n");*/
      initialize_output_path(mod);
      modules_to_process = ATempty;
      imports = get_imported_modules(mod);
      AFreshuffleModules(cid,imports);
      /*      ATfprintf(stderr,"Finished reshuffling\n");*/
    }
    else {
      ATfprintf(stderr,
                "Specification is incomplete and can not be compiled!\n");
      ATBwriteTerm(cid,ATmake("snd-event(done)"));
    } 
  }
  else {
    ATfprintf(stderr,
              "Module %t not in module databases!\n", mod);
    ATBwriteTerm(cid,ATmake("snd-event(done)"));
  } 
}

void usage(char *prg)
{
  fprintf(stderr, "usage: %s [aterm-options] [toolbus-options]\n", prg);
  fprintf(stderr, "use '%s -at-help' to get more options.\n", prg);
  fprintf(stderr, "This program can only be used as a ToolBus tool!\n");
  exit(1);
}


/* Main program */
int main(int argc, char **argv)
{
  int cid;
  ATerm bottomOfStack;

  if(strcmp(argv[1], "-h") == 0) {
    usage(argv[0]);
  }

  ATBinit(argc, argv,&bottomOfStack);
  AFinit(argc, argv, &bottomOfStack);
  cid = ATBconnect(NULL, NULL, -1, module_db_handler);

  ATprotect((ATerm *)&modules_to_process);

  ATBeventloop();

  return 0;
}
