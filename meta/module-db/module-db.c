/*
  $Id$
 */
/* The module-database is written by Mark van den Brand.

   The following functions are available:
   void rec_terminate(ATerm t)
   ATerm exists(ATerm name)
   ATerm get_section(ATerm name,ATerm module)
   void create_module_db()
   ATermList clear_module_db(ATermList db)
   ATerm get_import_section(ATermList sections)
   ATermList add_module(ATerm asfix)
   void delete_module(ATerm name)
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

static ATerm Mtrue;
static ATerm Mfalse;

void rec_terminate(int cid, ATerm t)
{
  exit(0);
}

ATerm exists(int cid,ATerm name)
{
  if(GetValue(modules_db,name) || GetValue(new_modules_db,name))
    return ATmake("snd-value(result(exists(<term>)))", name);
  else
    return ATmake("snd-value(result(notexists(<term>)))", name);
}

ATerm get_module(int cid, ATerm name)
{
  ATerm asfix;

  asfix = GetValue(modules_db,name);
  return ATmake("snd-value(getmod(<term>))",asfix);
}

ATerm get_equations(int cid, ATerm mods)
{
  ATerm mod, amod;
  ATermList eqs;
  ATermList equations = ATempty;

  equations = ATempty;
  while(!ATisEmpty((ATermList) mods)) {
    mod = ATgetFirst((ATermList) mods);
    amod = GetValue(modules_db,mod);
    eqs = (ATermList)AFgetModuleEqs(amod);
    equations = ATconcat(equations, eqs);
    mods = (ATerm) ATgetNext((ATermList) mods);
  };
  return ATmake("snd-value(equations([<list>]))",equations);
}

ATerm get_new_equations(int cid, ATerm mods)
{
  ATerm mod, entry, eqsterm;
  ATermList eqs;
  ATermList equations = ATempty;

  equations = ATempty;
  while(!ATisEmpty((ATermList) mods)) {
    mod = ATgetFirst((ATermList) mods);
    entry = GetValue(new_modules_db,mod);
    eqsterm = ATelementAt((ATermList)entry, eqs_loc);
    eqs = AFTgetEqs(eqsterm);
    equations = ATconcat(equations, eqs); 
    mods = (ATerm) ATgetNext((ATermList) mods);
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
ATerm get_module_name(ATerm module);
ATermList get_import_section_sdf2(ATerm module);

/*The Asf+Sdf variant */
ATerm add_module(int cid, ATerm asfix)
{
  ATerm t[8];
  ATerm modname;
  ATermList sections, imports, unknowns;
  ATerm newasfix;

  if(ATmatchTerm(asfix,pattern_asfix_module,
                 &t[0], &t[1], &modname, &t[2],
                 &sections, &t[3], &t[4], &t[5], &t[6])) {
    if(GetValue(modules_db,modname) == ATfalse) {
      newasfix = AFexpandModule(asfix);
      PutValue(modules_db,modname,newasfix);
    };
    imports = get_import_section(sections);
    unknowns = add_imports(modname,imports);
    return ATmake("snd-value(imports(<term>,need-modules([<list>])))",
                  modname,unknowns);
  } else {
    ATerror("not an asfix module: %t\n", asfix);
    return NULL;
  }
}

/* The Sdf2 variant */
ATerm add_sdf2_module(int cid, char* path, ATerm asfix, char* changed)
{
  ATerm t[8];
  ATerm modname, appl, entry;
  ATermList imports, unknowns;
  ATerm status;
  char  newpath[1024] = {'\0'};

  if(!strcmp(changed,"changed")) {
    /*sprintf(newpath,"%s%s", path, ".baf");*/
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
    entry = (ATerm) ATmakeList(7,ATmake("<str>",newpath),
                                 asfix,
                                 status,
                                 ATparse("unavailable"),
                                 ATparse("unavailable"),
                                 Mtrue,
                                 ATparse("unavailable"));
    PutValue(new_modules_db, modname, entry);
    imports = get_import_section_sdf2(appl);
    unknowns = add_imports(modname,imports);
    return ATmake("snd-value(imports(<term>,need-modules([<list>])))",
                  modname,unknowns);
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
    entry = ATreplace(entry,ATparse("unavailable"),path_eqs_loc);
    entry = ATreplace(entry,ATparse("unavailable"),eqs_loc);
    entry = ATreplace(entry,Mtrue,eqs_updated_loc);
    entry = ATreplace(entry,ATparse("unavailable"),table_loc);
    PutValue(new_modules_db, modname, (ATerm)entry);
    mods = ATgetNext(mods);
  }
}

ATermList replace_imports(ATerm name, ATermList mods);
ATermList modules_depend_on(ATerm name, ATermList mods);

ATerm update_sdf2_module(int cid, ATerm asfix)
{
  ATerm t[8];
  ATerm oldasfix, modname, appl, entry;
  ATermList imports, unknowns, chg_mods;
  ATerm place;
  char  *path;

  if(ATmatchTerm(asfix,pattern_asfix_term,
                 &t[0], &t[1], &t[2], &t[3], &t[4], &t[5],
                 &appl, &t[6], &t[7])) {
    modname = get_module_name(appl);
    entry = GetValue(new_modules_db, modname);
    place = ATelementAt((ATermList)entry, path_syn_loc);

    oldasfix = ATelementAt((ATermList)entry, syn_loc);
    if(!ATisEqual(asfix,oldasfix)) {
      if(ATmatch(place,"<str>",&path)) {
        entry = (ATerm) ATmakeList(7,ATmake("<str>",path),
                                     asfix,
                                     Mtrue,
                                     ATparse("unavailable"),
                                     ATparse("unavailable"),
                                     Mtrue,
                                     ATparse("unavailable"));
        PutValue(new_modules_db, modname, entry);
        chg_mods = modules_depend_on(modname,ATempty);
ATfprintf(stderr,"Changed modules are %t\n", chg_mods);
        update_syntax_status_of_modules(chg_mods); 
        imports = get_import_section_sdf2(appl);
ATfprintf(stderr,"Imported modules %t\n", imports);
        unknowns = replace_imports(modname,imports);
ATfprintf(stderr,"New modules %t\n", unknowns);
        return ATmake("snd-value(imports(<term>,need-modules([<list>])))",
                      modname,unknowns);
      } else {
         ATerror("no path available for %t\n", asfix);
         return NULL;
      }
    } else {
       return ATmake("snd-value(imports(<term>,need-modules([<list>])))",
                     modname,ATempty);
    }
  }
  else {
    ATerror("not an asfix module: %t\n", asfix);
    return NULL; 
  }
}

ATerm add_empty_module(int cid, ATerm modname)
{
  ATerm entry;
  char  *text;
  char  newpath[1024] = {'\0'};

  if(ATmatchTerm(modname,pattern_asfix_id,&text)) {
    sprintf(newpath,"%s%s", text, ".sdf2");
  }
  entry = (ATerm) ATmakeList(7,ATmake("<str>",newpath),
                               ATparse("unavailable"),
                               Mtrue,
                               ATparse("unavailable"),
                               ATparse("unavailable"),
                               Mtrue,
                               ATparse("unavailable"));
  PutValue(new_modules_db, modname, entry);
  return ATmake("snd-value(done)");
}

ATerm add_eqs_module(int cid, ATerm modname, char* path,
                              ATerm eqs, char* changed)
{
  ATerm entry;
  ATerm status;
  char   newpath[1024] = {'\0'};

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
  if(!ATisEqual(eqs,ATparse("error")) &
     !ATisEqual(eqs,ATparse("no-equations"))) {
    char *basename;
    if(!ATmatch(modname, "id(<str>)", &basename))
      ATerror("not an id(<str>): %t\n", modname);

    eqs = AFaddPosInfoToModule(path, basename, eqs);

  }
  entry = (ATerm)ATreplace((ATermList)entry,
                           ATmake("<str>",newpath),
                           path_eqs_loc);
  entry = (ATerm)ATreplace((ATermList)entry,
                           status,
                           eqs_updated_loc);
  entry = (ATerm)ATreplace((ATermList)entry, eqs, eqs_loc);
  PutValue(new_modules_db, modname, entry);
  return ATmake("snd-value(done)");
}

ATerm add_parse_table(int cid, ATerm modname, char *table)
{
  ATerm entry;

  entry = GetValue(new_modules_db, modname);
  entry = (ATerm)ATreplace((ATermList)entry,
                           ATmake("table(<str>)",table),
                           table_loc);
  PutValue(new_modules_db, modname, entry);
  return ATmake("snd-value(done)");
}

ATerm get_sdf2_path(int cid, ATerm modname)
{
  ATerm entry, place;
  char *path, *mod;

  if(ATmatch(modname,"id(<str>)",&mod)) {
    entry = GetValue(new_modules_db, modname);
    place = ATelementAt((ATermList)entry, path_syn_loc);
    if(ATmatch(place,"<str>",&path)) {
      return ATmake("snd-value(path(<str>))",path);
    }
    else {
      ATerror("Module not in database!!!");
      return NULL;
    }
  }
  else {
    ATerror("Illegal module name: %t", modname);
    return NULL;
  }
}

ATerm get_eqs_path(int cid, ATerm modname)
{
  ATerm entry, place;
  char *path, *mod;

  if(ATmatch(modname,"id(<str>)",&mod)) {
    entry = GetValue(new_modules_db, modname);
    place = ATelementAt((ATermList)entry, path_eqs_loc);
    if(ATmatch(place,"<str>",&path)) {
      return ATmake("snd-value(path(<str>))",path);
    }
    else {
      return ATmake("snd-value(path(<str>))","");
    }
  }
  else {
    ATerror("Illegal module name: %t", modname);
    return NULL;
  }
}

ATerm get_sdf2_asfix(int cid, ATerm modname)
{
  ATerm entry, asfix;
  ATerm status;

  entry = GetValue(new_modules_db, modname);
  status = ATelementAt((ATermList)entry, syn_updated_loc);
  asfix = ATelementAt((ATermList)entry, syn_loc);
  if(ATisEqual(status,Mtrue)) {
    if(ATisEqual(asfix,ATparse("unavailable"))) {
      return ATmake("snd-value(unavailable)");
    }
    else {
      status = Mfalse;
      entry = (ATerm)ATreplace((ATermList)entry,
                               status,
                               syn_updated_loc);
      PutValue(new_modules_db, modname, entry);
      return ATmake("snd-value(syntax(<term>))", asfix);
    }
  }
  else
    return ATmake("snd-value(syntax-unchanged(<term>))",asfix);
}

ATerm get_eqs_asfix(int cid, ATerm modname)
{
  ATerm entry, asfix;
  ATerm status;

  entry = GetValue(new_modules_db, modname);
  status = ATelementAt((ATermList)entry, eqs_updated_loc);
  if(ATisEqual(status,Mtrue)) {
    asfix = ATelementAt((ATermList)entry, eqs_loc);
    if(ATisEqual(asfix,ATparse("unavailable")) ||
       ATisEqual(asfix,ATparse("error"))) {
      return ATmake("snd-value(unavailable)");
    }
    else if(ATisEqual(asfix,ATparse("no-equations"))) {
      return ATmake("snd-value(no-eqs)");
    }
    else {
      status = Mfalse;
      entry = (ATerm)ATreplace((ATermList)entry,
                               status,
                               eqs_updated_loc);
      PutValue(new_modules_db, modname, entry);
      return ATmake("snd-value(eqs(<term>))", asfix);
    }
  }
  else {
    asfix = ATelementAt((ATermList)entry, eqs_loc);
    if(ATisEqual(asfix,ATparse("unavailable")) ||
       ATisEqual(asfix,ATparse("error"))) {
      return ATmake("snd-value(unavailable)");
    }
    else if(ATisEqual(asfix,ATparse("no-equations"))) {
      return ATmake("snd-value(no-eqs)");
    }
    else {
      return ATmake("snd-value(eqs-unchanged(<term>))", asfix);
    }
  }
}

ATbool valid_parse_tables(ATermList visited, ATerm module);

ATerm get_parse_table(int cid, ATerm modname)
{
  ATermList entry;
  ATerm     table;
  char      *place;

  if((entry = (ATermList) GetValue(new_modules_db, modname))) {
    table = ATelementAt((ATermList)entry, table_loc);
    if(ATmatch(table,"table(<str>)",&place))
      return ATmake("snd-value(table(<str>))",place);
  }

  return ATmake("snd-value(no-table)");
}

/* This function traverses the import graph and visit all nodes
   to check whether the parse tables are still valid.*/
void mdb_validate_parse_tables(ATermList visited, ATerm modname)
{
  ATermList entry, imports;
  ATerm import;

  if(ATindexOf(visited, modname, 0) < 0) {
    if(!valid_parse_tables(ATempty,modname))
      if((entry = (ATermList)GetValue(new_modules_db, modname)))
        entry = ATreplace(entry,ATparse("unavailable"),table_loc);
    visited = ATinsert(visited, modname);
    imports = (ATermList)GetValue(import_db, modname);
    while(!ATisEmpty(imports)) {
      import = ATgetFirst(imports);
      mdb_validate_parse_tables(visited, import);
      imports = ATgetNext(imports);
    }
  }
}

ATerm validate_parse_tables(int cid, ATerm modname)
{
  mdb_validate_parse_tables(ATempty,modname);

  return ATmake("snd-value(validation-done)");
}

ATermList get_import_section(ATermList sections)
{
  ATerm t[2];
  ATerm section;
  ATermList imps;
  ATermList imports = ATempty;

/* Traverse the list of section to find the import section. */
  imps = ATempty;
  while(!ATisEmpty(sections)) {
    section = ATgetFirst(sections);
    if(ATmatchTerm(section,pattern_asfix_imports, &t[0], &t[1], &imps))
      imports = ATconcat(imports,imps);
    sections = ATgetNext(sections);
  };
  imports = asfix_filter_layout(imports);
  return imports;
}

ATerm delete_module(int cid, ATerm name)
{
  RemoveKey(modules_db,name);
  RemoveKey(new_modules_db,name);
  RemoveKey(import_db,name);
  trans_db = CreateValueStore(100,75);
  return ATmake("snd-value(done)");
}

void save_module(int cid, ATerm name)
{
  ATerm entry;

ATfprintf(stderr, "Saving: %t\n", name);

  entry = GetValue(new_modules_db, name);
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
    asfix = ATelementAt((ATermList)entry, syn_loc);
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

ATbool valid_parse_tables(ATermList visited, ATerm module)
{
  ATbool result;
  ATermList imports;
  ATerm first, entry, status;

  if(ATindexOf(visited, module, 0) < 0) {
    result = ATtrue;
    imports = (ATermList) GetValue(import_db,module);

    visited = ATinsert(visited, module);
    while(!ATisEmpty(imports)) {
      first = ATgetFirst(imports);
      entry = GetValue(new_modules_db, first);
      status = ATelementAt((ATermList)entry, syn_updated_loc);
      if(ATisEqual(status, Mtrue)) {
        entry = (ATerm)ATreplace((ATermList)entry,
                                 ATparse("unavailable"),
                                 table_loc);
        PutValue(new_modules_db, module, entry);
        result = ATfalse;
      }
      else {
        result = result && valid_parse_tables(visited, first);
      };
      imports = ATgetNext(imports);
    };
    return result;
  }
  else
    return ATfalse;
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
      asfix = ATelementAt((ATermList)entry, eqs_loc);
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

ATerm update_eqs_for_modules(int cid, ATerm name)
{
  ATerm module, entry, eqs;
  ATermList result = ATempty;
  ATermList modules;
  if(GetValue(new_modules_db, name)) {
ATfprintf(stderr,"update_eqs_for_modules entered with %t\n",name);
    modules = get_imported_modules(name);

    while (!ATisEmpty(modules)) {
      module = ATgetFirst(modules);
      entry = GetValue(new_modules_db, module);
      eqs = ATelementAt((ATermList)entry, eqs_loc);
      if(ATisEqual(eqs,ATparse("unavailable")))
        result = ATinsert(result,module);
      modules = ATgetNext(modules);
    }
ATfprintf(stderr,"update_eqs_for_modules left with %t\n",result);
  }
  return ATmake("snd-value(modules([<list>]))",result);
}

ATerm get_all_imported_modules(int cid, ATerm name)
{
  ATermList result = get_imported_modules(name);

  return ATmake("snd-value(all-imports([<list>]))",result);
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

ATermList imported_by(ATerm name)
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

ATerm calc_import_rels(int cid, ATerm name)
{
  ATermList imports = imported_by(name);
  return ATmake("snd-value(irels([<list>]))", imports);
}

/* A number of function to deal with modules which are recognized
   via Sdf2. */

ATerm get_module_name(ATerm module)
{
  ATerm t[2], elem;
  ATermList args;
  char *text;

  if(ATmatchTerm(module,pattern_asfix_appl,
                 & t[0], &t[1], &args)) {
    elem = ATelementAt(args,2);
    if(ATmatchTerm(elem,pattern_asfix_appl,
                   &t[0], &t[1], &args)) {
      elem = ATelementAt(args,0);
      if(ATmatchTerm(elem,pattern_asfix_lex, &text, &t[0])) {
        return ATmakeTerm(pattern_asfix_id,text);
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
          imports = ATinsert(imports,ATmakeTerm(pattern_asfix_id,text));
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

ATermList get_import_section_sdf2(ATerm module)
{
  ATerm t[2], elem;
  ATermList args, elems;

  if(ATmatchTerm(module,pattern_asfix_appl,
                 &t[0], &t[1], &args)) {
    elem = ATelementAt(args,4);
    if(ATmatchTerm(elem,pattern_asfix_list,
                   &t[0], &t[1], &elems))
      return filter_import_list(elems);
    else {
      ATerror("Not a correct Sdf2 module: %t\n", module);
      return ATempty;
    }
  }
  else {
    ATerror("Not a correct Sdf2 module: %t\n", module);
    return ATempty;
  }
  return ATempty;
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

  if(ATmatchTerm(name,pattern_asfix_id,&text)) {
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
    module = ATelementAt((ATermList)entry, syn_loc);
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
                      ATparse("prod(id(\"Add-Eqs-Syntax\"),w(\"\"),[l(\"add-equation-module\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"ModuleName\"),w(\"\"),l(\",\"),w(\"\"),sort(\"Definition\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"SDF\"),w(\"\"),no-attrs)"),
                      pattern_asfix_ews,
                      ATmakeList(11,ATparse("l(\"add-equation-module\")"),
                                    pattern_asfix_ews,
                                    ATparse("l(\"(\")"),
                                    pattern_asfix_ews,
                                    nameterm,
                                    pattern_asfix_ews,
                                    ATparse("l(\",\")"),
                                    pattern_asfix_ews,
                                    result,
                                    pattern_asfix_ews,
                                    ATparse("l(\")\")")));
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

ATerm retrieve_syntax(int cid, ATerm name)
{
  ATerm result;
  ATermList imports;

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

ATerm add_pgen_func(int cid, ATerm name, ATerm syntax)
{
  ATerm t[8], result, term, appl, nameterm;

  if(ATmatchTerm(syntax,pattern_asfix_term,
                 &t[0], &t[1], &t[2], &t[3], &t[4], &t[5],
                 &appl, &t[6], &t[7])) {
    nameterm = make_name_term(name);
    result = ATmakeTerm(pattern_asfix_appl,
                        ATparse("prod(id(\"Sdf2-Parse-Table\"),w(\"\"),[l(\"parse-table\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"ModuleName\"),w(\"\"),l(\",\"),w(\"\"),sort(\"SDF\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerm\"),w(\"\"),no-attrs)"),
                        pattern_asfix_ews,
                        ATmakeList(11,ATparse("l(\"parse-table\")"),
                                      pattern_asfix_ews,
                                      ATparse("l(\"(\")"),
                                      pattern_asfix_ews,
                                      nameterm,
                                      pattern_asfix_ews,
                                      ATparse("l(\",\")"),
                                      pattern_asfix_ews,
                                      appl,
                                      pattern_asfix_ews,
                                      ATparse("l(\")\")")));
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
    return ATmake("snd-value(decorated-syntax(<term>)))",term);
  }
  else {
    ATerror("not a legal term: %t\n", syntax);
    return NULL;
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

  if(ATmatchTerm(name,pattern_asfix_id,&text)) {
    newtext = malloc(strlen(text)+16);
    sprintf(newtext,"AUX-%s%d",text,n);
    newname = ATmakeTerm(pattern_asfix_id,newtext);
    while(GetValue(compile_db,newname)) {
      n++;
      sprintf(newtext,"AUX-%s%d",text,n);
      newname = ATmakeTerm(pattern_asfix_id,newtext);
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

  if(ATmatchTerm(name,pattern_asfix_id,&text)) {

    sprintf(buf, "%s/%s.module-list", output_path, text);
    output = fopen(buf,"w");
    if(!output)
      ATfprintf(stderr,"Cannot open file %s\n",buf);
    else {
      fprintf( output, "# Generated automatically, please do not edit.\n" );
      while (!ATisEmpty(modules)) {
        module = ATgetFirst(modules);
        if(ATmatchTerm(module,pattern_asfix_id,&mtext)) {
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
  ATerm name, mod;

  if(ATmatch(term,"generate-code(<term>,<term>)",&name,&mod)) {
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

void compile_module(int cid, ATerm mod)
{
  ATermList imports;

  if(GetValue(new_modules_db, mod)) {
    /* We are working with the term asfix representation. */
    if(complete_asf_sdf2_specification(mod)) {
      ATfprintf(stderr,"Reshuffling ... \n");
      initialize_output_path(mod);
      modules_to_process = ATempty;
      imports = get_imported_modules(mod);
      AFTreshuffleModules(cid,imports);
      ATfprintf(stderr,"Finished reshuffling\n");
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
      ATfprintf(stderr,"Reshuffling ... \n");
      initialize_output_path(mod);
      modules_to_process = ATempty;
      imports = get_imported_modules(mod);
      AFreshuffleModules(cid,imports);
      ATfprintf(stderr,"Finished reshuffling\n");
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

/* Main program */
int main(int argc, char **argv)
{
  int cid;
  ATerm bottomOfStack;

  ATBinit(argc, argv,&bottomOfStack);
  AFinit(argc, argv, &bottomOfStack);
  cid = ATBconnect(NULL, NULL, -1, module_db_handler);

  Mtrue = ATparse("true");
  ATprotect(&Mtrue);
  Mfalse = ATparse("false");
  ATprotect(&Mfalse);

  ATprotect((ATerm *)&modules_to_process);

  ATBeventloop();

  return 0;
}
