/*

    Meta-Environment - An environment for language prototyping.
    Copyright (C) 2000  Stichting Mathematisch Centrum, Amsterdam, The Netherlands. 

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
/* The code for the reshuffling of the equations in a module.
 */

#include "module-db.h"

extern ATermTable new_modules_db;
extern ATermTable compile_db;
extern ATermList modules_to_process; 
extern ATbool compiling;
extern ATbool reshuffling;
extern ATerm top_module;

/* From module-db.c */
extern char *get_output_dir();

/* The function {\tt AFTgeLexFuncsSort} traverse a list
   of modules and looks for all lexical functions
   with the given sorts as result sort. */

ATerm AFTmakeId(ATerm id)
{
  char *id_str;
 
  if(ATmatch(id, "<str>", &id_str))
    return ATmakeTerm(pattern_asfix_id, id_str);
  else {
    ATerror("Illegal identifier %t\n", id);
    return NULL; /* silence the compiler */
  }
}

ATermList AFTgetLexFuncsSort(ATerm sort, ATermList mods)
{
  ATerm entry, lmod, amod, lexfunc, rsort;
  ATermList lexfuncs;
  ATermList functions = ATempty;

  while(!ATisEmpty(mods)) {
    lmod = ATgetFirst(mods);
    entry = GetValue(new_modules_db,lmod);
    amod = ATelementAt((ATermList)entry, SYN_LOC);
    lexfuncs = AFTgetLexFunctions(amod);
    lexfuncs = asfix_filter_layout(lexfuncs);
    while(!ATisEmpty(lexfuncs)) {
      lexfunc = ATgetFirst(lexfuncs);
      rsort = AFTgetProdRhs(lexfunc);
      if(ATisEqual(sort,rsort)) {
        if(!ATisEmpty(functions))
          functions = ATappend(functions,
                               ATreadFromString("w(\"\\n\")"));
        functions = ATappend(functions, lexfunc);
      }
      lexfuncs = ATgetNext(lexfuncs);
    }
    mods = ATgetNext(mods);
  }
  return functions;
}

/* The function {\tt ATgetEquationsFunc} traverse a list
   of modules and looks for all equations with the given
   context-free function as outermost function symbol in the
   left-hand side. */
ATermList AFTgetEquationsFunc(ATerm func,ATermList mods)
{
  ATerm entry, mod, amod, eq, lhs, ofs;
  ATermList eqs;
  ATermList equations = ATempty;

  while(!ATisEmpty(mods)) {
    mod = ATgetFirst(mods);
    entry = GetValue(new_modules_db,mod);
    amod = ATelementAt((ATermList)entry, EQS_TREE_LOC); 
    eqs = (ATermList)AFTgetEqs(amod);
    eqs = asfix_filter_layout(eqs);
    while(!ATisEmpty(eqs)) {
      eq = ATgetFirst(eqs);
      lhs = AFTgetEquLhs(eq);
      ofs = asfix_get_appl_prod(lhs); 
      if(ATisEqual(func,ofs)) {
        if(!ATisEmpty(equations))
          equations = ATappend(equations, ATreadFromString( "w(\"\\n\")"));
        equations = ATappend(equations, eq);
      }
      eqs = ATgetNext(eqs);
    }
    mods = ATgetNext(mods);
  };
  return equations;
}

void AFTaddSection(ATerm module, ATerm section)
{
  ATerm newmodule = GetValue(compile_db,module);
  ATermList sections = AFgetModuleSections(newmodule);
  if(!ATisEmpty(sections)) {
    sections = ATconcat(sections,
                        ATmakeList2(pattern_asfix_nlws,
                                    section));
    newmodule = AFputModuleSections(newmodule,sections);
  }
  else
    newmodule = AFputModuleSections(newmodule,ATmakeList1(section));
  PutValue(compile_db,module,newmodule);
}

ATerm unique_new_name(ATerm name);

ATerm AFTcreateNewModule(ATerm modname)
{ 
  ATerm module_name_with_id, extmodname;
  ATerm orig_mod_name_with_id;

  ATerm newmodule = AFinitModule();
  ATerm newmodname = unique_new_name(modname);
  
  module_name_with_id = AFTmakeId(newmodname);
  orig_mod_name_with_id = AFTmakeId(modname);

  extmodname = ATsetAnnotation(module_name_with_id,
                               ATparse("module-name"),orig_mod_name_with_id);
  newmodule = AFputModuleName(newmodule,extmodname);
  PutValue(compile_db,newmodname,newmodule);
  return newmodname;
}

void AFTaddEquations(ATerm module, ATermList eqs)
{
  ATerm newmodule = GetValue(compile_db,module);
  newmodule = AFputModuleEqs(newmodule,eqs);
  PutValue(compile_db,module,newmodule);
}

void AFTwriteAsfixFile(int cid,ATerm modname)
{
  char *text, *fname;
  char *path;
  int len;
  FILE *output, *input;
  ATerm oldmod, element;
  ATbool write;

  ATerm amod = GetValue(compile_db,modname);

  if(ATmatch(modname,"<str>",&text)) {
    /* Check whether the C file exists. */
    path = get_output_dir();
    len = strlen(path) + 1 + strlen(text) + strlen(".c");
    fname = malloc(len + 1);
    if(!fname)
      ATerror("Not enough memory\n");
    sprintf(fname, "%s/%s.c", path, text);
    input = fopen(fname,"r");
    if(!input) {
      write = ATtrue;
    } else {
      write = ATfalse;
/* Only close input if we actually opened it. Linux fclose crashes on
   closing NULL
*/
      fclose(input);
    }
    free(fname);

    len = strlen(path) + 1 + strlen(text) + strlen(".asfix");
    fname = malloc(len + 1);
    if(!fname)
      ATerror("Not enough memory\n");
    sprintf(fname, "%s/%s.asfix", path, text);
    /* Check whether it is necessary to generate new C code
     * because of a modified AsFix file. */
    input = fopen(fname,"r");
    if(input) {
      oldmod = ATreadFromFile(input);
      if(!write)
        write = !ATisEqual(oldmod,amod);
      fclose(input);
    }
    else
      write = ATtrue;
    if(write) {
      output = fopen(fname,"w");
      if(!output)
        ATwarning("Cannot open file %s\n",fname);
      else {
        ATfprintf(output,"%t",amod);
        ATfprintf(output, "\n");
        fclose(output);
      }
      /* write full path name instead of only module name */
      element = ATmake("snd-event(new-aux-module(<str>,<term>))", text, amod);
      if(!compiling) {
        compiling = ATtrue;
        ATBwriteTerm(cid,element);
      }
      else
        modules_to_process = ATappend(modules_to_process,element);
    }
    free(fname);
  }
  else
    ATerror("Illegal module name %t\n", modname);
}

/* This function uses the sorts to determine whether there are equations
 * for the lexical functions.
 */
void AFTreshuffleLexicalConstructorFunctions(int cid,
                                             ATerm modname, ATerm newmod,
                                             ATermList orgmods)
{
  ATerm entry, prod, amod, sort, newsection, newsubsection, newmodname;
  ATermList sorts, funcs, eqs;

  entry = GetValue(new_modules_db,modname);
  amod = ATelementAt((ATermList)entry, SYN_LOC);
  sorts = AFTgetSorts(amod); 
  sorts = asfix_filter_layout(sorts);
  while(!ATisEmpty(sorts)) {
    sort = ATgetFirst(sorts);
    funcs = AFTgetLexFuncsSort(sort,orgmods);
    if(!ATisEmpty(funcs)) {
      newsubsection = AFinitLexicalSyntaxSection();
      newsubsection = AFputSectionArgs(newsubsection,funcs);
      newsection = AFinitExportSection();
      newsection = AFputSectionArgs(newsection,
                                    ATmakeList1(newsubsection));
      prod = AFTmakeCallerProd(sort);
      eqs = AFTgetEquationsFunc(prod,orgmods);
      if(!ATisEmpty(eqs)) {
/* There are equations for the lexical constructor of sort SORT.
 * So, a new module has to be created containing these lexical functions
 * and the corresponding equations.
 */
        newmodname = AFTcreateNewModule(modname);
        AFTaddSection(newmodname,newsection);
        AFTaddEquations(newmodname,eqs);
        AFTwriteAsfixFile(cid,newmodname);
      }
      else
/* There are no equations for the lexical constructor of sort SORT.
 * So, this function is to be added to the module containing no
 * equations.
 */
        AFTaddSection(newmod,newsection);
    }
    sorts = ATgetNext(sorts);
  }
}

void gen_makefile(ATerm name);

void AFTreshuffleModules(int cid, ATermList mods)
{
  ATerm entry, mod, id_mod, newmod, newmodname, oldamod, cffunc, flatcffunc;
  ATermList cffuncs, eqs, orgmods;
  ATerm newsubsection, newsection;

  compile_db = CreateValueStore(500,75);
  orgmods = mods;
  reshuffling = ATtrue;
  while(!ATisEmpty(mods)) {
    mod = ATgetFirst(mods);
    newmod = AFTcreateNewModule(mod);
    AFTreshuffleLexicalConstructorFunctions(cid,mod,newmod,orgmods);
    entry = GetValue(new_modules_db,mod);
    oldamod = ATelementAt((ATermList)entry, SYN_LOC);
    cffuncs = AFTgetCFFunctions(oldamod);
    cffuncs = asfix_filter_layout(cffuncs);
    while(!ATisEmpty(cffuncs)) {
      cffunc = ATgetFirst(cffuncs);
      newsubsection = AFinitContextFreeSyntaxSection();
      newsubsection = AFputSectionArgs(newsubsection,
                                       ATmakeList1(cffunc));
      newsection = AFinitExportSection();
      newsection = AFputSectionArgs(newsection,
                                    ATmakeList1(newsubsection));
      id_mod = AFTmakeId(mod);
      flatcffunc = AFTflattenSdf2Prod(id_mod,cffunc);
      eqs = AFTgetEquationsFunc(flatcffunc,orgmods);
      if(!ATisEmpty(eqs)) {
        newmodname = AFTcreateNewModule(mod);
        AFTaddSection(newmodname,newsection);
        AFTaddEquations(newmodname,eqs);
        AFTwriteAsfixFile(cid,newmodname);
      } else {
        AFTaddSection(newmod,newsection);
      }
      cffuncs = ATgetNext(cffuncs);
    }
    AFTwriteAsfixFile(cid,newmod);
    while(ATBpeekOne(cid))
      ATBhandleOne(cid);
    mods = ATgetNext(mods);
  }
  reshuffling = ATfalse;
  if(!compiling && ATisEmpty(modules_to_process))
  {
    gen_makefile(top_module);
    ATfprintf(stderr,"Compilation completed\n");
    ATBwriteTerm(cid,ATmake("snd-event(done)"));
  }
} 




