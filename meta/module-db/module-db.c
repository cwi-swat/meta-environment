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
ATermTable import_db;
ATermTable trans_db;
extern ATermTable compile_db;
extern ATerm modules_to_process;

void rec_terminate(int cid, ATerm t) 
{
  exit(0);
}

ATerm exists(int cid,ATerm name)
{ 
  if(GetValue(modules_db,name))
    return ATmake("snd-value(result(exists(<term>)))", name);
  else
    return ATmake("snd-value(result(notexists(<term>)))", name);
}

/*
ATerm get_section(int cid,ATerm name,ATerm module)
{
  return (ATerm) ATempty;
}
*/

ATerm get_module(int cid, ATerm name)
{
  ATerm asfix;
ATfprintf(stderr,"Get module entered with %t\n",name);
  asfix = GetValue(modules_db,name);
  return ATmake("snd-value(getmod(<term>))",asfix);
}

ATerm get_equations(int cid,ATerm mods)
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

void create_module_db(int cid)
{
  modules_db = CreateValueStore(100,75);
  import_db = CreateValueStore(100,75);
  trans_db = CreateValueStore(100,75);
}

void clear_module_db(int cid)
{
  modules_db = CreateValueStore(100,75);
  import_db = CreateValueStore(100,75);
  trans_db = CreateValueStore(100,75);
}

ATermList get_import_section(ATermList sections);
ATermList add_imports(ATerm name, ATermList mods);

ATerm add_module(int cid, ATerm asfix)
{
  ATerm t[7]; 
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
  }
  else {
    ATerror("not an asfix module: %t\n", asfix);
    return NULL;
  }
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
ATfprintf(stderr, "gives: %t\n", imports);
  return imports;
}

ATerm delete_module(int cid, ATerm name)
{
ATfprintf(stderr, "Deleting: %t\n", name);
  RemoveKey(modules_db,name);
  RemoveKey(import_db,name);
  trans_db = CreateValueStore(100,75);
  return ATmake("snd-value(deleted(<term>))",name);
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

int main(int argc, char **argv)
{
  int cid;
  ATerm bottomOfStack;

  ATBinit(argc, argv,&bottomOfStack);
  AFinit(argc, argv, &bottomOfStack);
  cid = ATBconnect(NULL, NULL, -1, module_db_handler); 

  AFinitAsFixPatterns();

  ATprotect(&modules_to_process);

  ATBeventloop();

  return 0;
}
