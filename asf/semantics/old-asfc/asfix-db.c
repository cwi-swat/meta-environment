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

Creation and clearing of the module database:
   void create_module_db()

Manipulation of modules in database:
   ATerm add_module(ATerm asfix)
   void reshuffle_modules_from(char *modulename)
*/

#include <stdlib.h>

#include "asfix-db.h"

ATermTable modules_db;
ATermTable import_db;
ATermTable trans_db;

/* Declaration for the reshuffling phase. */
ATermList modules_to_process;
ATbool compiling = ATfalse;
ATbool reshuffling = ATfalse;
ATerm top_module;
ATermTable compile_db;

extern char *get_output_dir();  

ATermList get_imported_modules(ATerm name);

void create_module_db()
{
  modules_db = CreateValueStore(100,75);
  import_db = CreateValueStore(100,75);
  trans_db = CreateValueStore(100,75);
}

ATermList get_import_section(ATermList sections);
ATermList add_imports(ATerm name, ATermList mods);

ATermList add_module(ATerm asfix)
{
  ATerm t[8];
  ATerm modname, modname_term;
  ATermList sections, imports, unknowns;
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
      return unknowns;
    }
    else {
      ATwarning("not an identifier: %t\n", modname);
      return ATempty;
    }
  } else {
    ATwarning("not an asfix module: %t\n", asfix);
    return ATempty;
  }
}

/* Creation of a new entry in the database of a new Sdf2 definition. 
 */

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

      sprintf(buf, "cd %s; %s/genmakefile.sh %s", path, BINDIR, text);
      system(buf);
    }
  }
  else
    ATerror("illegal name %t\n", name);
}

void AFreshuffleModules(ATermList mods);

void reshuffle_modules_from(char *moduleName)
{
  ATerm atModuleName;
  ATermList imports;

  atModuleName = ATmake("<str>",moduleName);
  if(GetValue(modules_db, atModuleName)) {
    /* We are working with the module asfix representation. */
    if(complete_specification(ATempty,atModuleName)) {
      top_module = atModuleName;
      modules_to_process = ATempty;
      imports = get_imported_modules(atModuleName);
      AFreshuffleModules(imports);
    }
    else {
      ATwarning("Specification is incomplete and can not be compiled!\n");
    } 
  }
  else {
    ATwarning("Module %t not in module databases!\n", atModuleName);
  } 
}
