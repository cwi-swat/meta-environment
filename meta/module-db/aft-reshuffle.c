/*

    Meta-Environment - An environment for language prototyping.
    Copyright (C) 2001  Stichting Mathematisch Centrum, Amsterdam, 
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

    $Id$
*/
/* The code for the reshuffling of the equations in a module.
 */

#include "module-db.h"

extern ATermTable modules_db;

static ATermList compiled_modules;
static ATermList modules_to_process; 
static ATbool compiling  = ATfalse;
static ATbool reshuffling  = ATfalse;
static ATerm top_module;
static char *outputDirName = NULL; 

/*{{{  set_output_dir(int cid, char *dirName) */

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

/*}}}  */
/*{{{  get_output_dir(void) */

/*
 * The same construct is used in compiler.c
 * This obviously needs to be moved away altogether from the module-db.
 */

static char *
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

/*}}}  */

/* The function {\tt AFTgeLexFuncsSort} traverse a list
   of modules and looks for all lexical functions
   with the given sorts as result sort. */

static ATerm AFTmakeId(ATerm id)
{
  char *id_str;
 
  if(ATmatch(id, "<str>", &id_str))
    return ATmakeTerm(pattern_asfix_id, id_str);
  else {
    ATerror("Illegal identifier %t\n", id);
    return NULL; /* silence the compiler */
  }
}

static ATermList AFTgetLexFuncsSort(ATerm sort, ATermList mods)
{
  ATerm entry, lmod, amod, lexfunc, rsort;
  ATermList lexfuncs;
  ATermList functions = ATempty;

  while(!ATisEmpty(mods)) {
    lmod = ATgetFirst(mods);
    entry = GetValue(modules_db,lmod);
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
static ATermList AFTgetEquationsFunc(ATerm func,ATermList mods)
{
  ATerm entry, mod, amod, eq, lhs, ofs;
  ATermList eqs;
  ATermList equations = ATempty;

  while(!ATisEmpty(mods)) {
    mod = ATgetFirst(mods);
    entry = GetValue(modules_db,mod);
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

static ATerm unique_new_name(ATerm name)
{
  char *text, *newtext;
  ATerm newname;
  int n = 1;

  if(ATmatch(name,"<str>",&text)) {
    newtext = malloc(strlen(text)+16);
    sprintf(newtext,"AUX-%s%d",text,n);
    newname = ATmake("<str>",newtext);
    while (ATindexOf(compiled_modules, newname, 0) >= 0) {
      n++;
      sprintf(newtext,"AUX-%s%d",text,n);
      newname = ATmake("<str>",newtext);
    }
    free(newtext);
    compiled_modules = ATinsert(compiled_modules, newname);
    return newname;
  }
  else {
    ATerror("illegal name %t\n", name);
    return NULL; /* silence the compiler */
  }
}

static ATerm createNewModuleName(ATerm modname)
{ 
  return unique_new_name(modname);
}

static ATerm extendModuleName(ATerm modname, ATerm newModuleName)
{ 
  ATerm module_name_with_id = AFTmakeId(newModuleName);
  ATerm orig_mod_name_with_id = AFTmakeId(modname);

  return ATsetAnnotation(module_name_with_id,
                               ATparse("module-name"),orig_mod_name_with_id);
}

static void AFTwriteAsfixFile(int cid, ATerm modName, ATermList auxModule)
{
  char *text, *fname;
  char *path;
  int len;
  FILE *output, *input;
  ATerm oldmod, element;
  ATbool write;

  if (ATmatch(modName,"<str>", &text)) {
    /* Check whether the C file exists. */
    path = get_output_dir();
    len = strlen(path) + 1 + strlen(text) + strlen(".c");
    fname = malloc(len + 1);
    if (!fname) {
      ATerror("Not enough memory\n");
    }
    sprintf(fname, "%s/%s.c", path, text);
    input = fopen(fname,"r");
    if(!input) {
      write = ATtrue;
    } 
    else {
      write = ATfalse;
/* Only close input if we actually opened it. Linux fclose crashes on
   closing NULL
*/
      fclose(input);
    }
    free(fname);

    len = strlen(path) + 1 + strlen(text) + strlen(".asfix");
    fname = malloc(len + 1);
    if (!fname) {
      ATerror("Not enough memory\n");
    }
    sprintf(fname, "%s/%s.asfix", path, text);
    /* Check whether it is necessary to generate new C code
     * because of a modified AsFix file. */
    input = fopen(fname,"r");
    if(input) {
      oldmod = ATreadFromFile(input);
      if(!write) {
        write = !ATisEqual(oldmod,auxModule);
      }
      fclose(input);
    }
    else {
      write = ATtrue;
    }
    if(write) {
      output = fopen(fname,"w");
      if(!output)
        ATwarning("Cannot open file %s\n", fname);
      else {
        ATfprintf(output,"%t", auxModule);
        ATfprintf(output, "\n");
        fclose(output);
      }
      /* write full path name instead of only module name */
      element = ATmake("snd-event(new-aux-module(<str>,<term>))", 
                       text, auxModule);
      if (!compiling) {
        compiling = ATtrue;
        ATBwriteTerm(cid, element);
      }
      else {
        modules_to_process = ATappend(modules_to_process,element);
      }
    }
    free(fname);
  }
  else {
    ATerror("Illegal module name %t\n", modName);
  }
}

/* This function uses the sorts to determine whether there are equations
 * for the lexical functions.
 */
static ATermList 
AFTreshuffleLexicalConstructorFunctions(int cid,
                                        ATerm modname,
                                        ATermList orgmods)
{
  ATerm entry, prod, amod, sort, newmodname, extmodname;
  ATermList sorts, funcs, eqs, newAuxModule, newLexFuncs = ATempty;

  entry = GetValue(modules_db, modname);
  amod = ATelementAt((ATermList)entry, SYN_LOC);
  sorts = AFTgetSorts(amod); 
  sorts = asfix_filter_layout(sorts);
  while (!ATisEmpty(sorts)) {
    sort = ATgetFirst(sorts);
    funcs = AFTgetLexFuncsSort(sort,orgmods);
    if (!ATisEmpty(funcs)) {
      prod = AFTmakeCallerProd(sort);
      eqs = AFTgetEquationsFunc(prod,orgmods);
      if(!ATisEmpty(eqs)) {
/* There are equations for the lexical constructor of sort SORT.
 * So, a new module has to be created containing these lexical functions
 * and the corresponding equations.
 */
        newmodname = createNewModuleName(modname);
        extmodname = extendModuleName(modname, newmodname);
        newAuxModule = ATmakeList4(extmodname, 
                                   (ATerm)funcs, 
                                   (ATerm)ATempty,
                                   (ATerm)eqs);
        AFTwriteAsfixFile(cid, newmodname, newAuxModule);
      }
      else {
/* There are no equations for the lexical constructor of sort SORT.
 * So, this function is to be added to the module containing no
 * equations.
 */
        if (!ATisEmpty(newLexFuncs)) {
          newLexFuncs = ATconcat(newLexFuncs,
                                 ATinsert(funcs, pattern_asfix_nlws));
        }
        else {
          newLexFuncs = funcs;
        }
      }
    }
    sorts = ATgetNext(sorts);
  }
  return newLexFuncs;
}

/*{{{  static void gen_makefile(ATerm name) */

static void gen_makefile(ATerm name)
{
  char *text, *mtext;
  char *path;
  char buf[1024];
  FILE *output;
  ATerm module;
  ATermList modules = compiled_modules;  

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
    }
  }
  else {
    ATerror("illegal name %t\n", name);
  }
}

/*}}}  */          

void AFTreshuffleModules(int cid, ATermList mods)
{
  ATerm entry, mod, id_mod, newmod, extmod, newmodname, extmodname, oldamod, 
        cffunc, flatcffunc;
  ATermList cffuncs, eqs, orgmods, newAuxModule;
  ATermList lexFuncs, newCfFuncs = ATempty;

  ATprotect((ATerm *)&compiled_modules); 
  compiled_modules = ATempty;
  ATprotect((ATerm *)&modules_to_process); 

  orgmods = mods;
  reshuffling = ATtrue;
  while(!ATisEmpty(mods)) {
    mod = ATgetFirst(mods);
    newmod = createNewModuleName(mod);
    extmod = extendModuleName(mod, newmod);
    newCfFuncs = ATempty;
    lexFuncs = AFTreshuffleLexicalConstructorFunctions(cid, mod, orgmods);
    entry = GetValue(modules_db,mod);
    oldamod = ATelementAt((ATermList)entry, SYN_LOC);
    cffuncs = AFTgetCFFunctions(oldamod);
    cffuncs = asfix_filter_layout(cffuncs);
    while (!ATisEmpty(cffuncs)) {
      cffunc = ATgetFirst(cffuncs);
      id_mod = AFTmakeId(mod);
      flatcffunc = AFTflattenSdf2Prod(id_mod,cffunc);
      eqs = AFTgetEquationsFunc(flatcffunc,orgmods);
      if (!ATisEmpty(eqs)) {
        newmodname = createNewModuleName(mod);
        extmodname = extendModuleName(mod, newmodname);
        newAuxModule = ATmakeList4(extmodname, 
                                   (ATerm)ATempty, 
                                   (ATerm)ATmakeList1(cffunc),
                                   (ATerm)eqs);
        AFTwriteAsfixFile(cid, newmodname, newAuxModule);
      }
      else {
        if (!ATisEmpty(newCfFuncs)) {
          newCfFuncs = ATconcat(newCfFuncs,
                                ATmakeList2(pattern_asfix_nlws, cffunc));
        }
        else {
          newCfFuncs = ATmakeList1(cffunc);
        }
      }
      cffuncs = ATgetNext(cffuncs);
    }
    newAuxModule = ATmakeList4(extmod, 
                               (ATerm)lexFuncs, 
                               (ATerm)newCfFuncs,
                               (ATerm)ATempty);
    AFTwriteAsfixFile(cid, newmod, newAuxModule);
    while(ATBpeekOne(cid)) {
      ATBhandleOne(cid);
    }
    mods = ATgetNext(mods);
  }
  reshuffling = ATfalse;
  if(!compiling && ATisEmpty(modules_to_process))
  {
    gen_makefile(top_module);
    /*ATfprintf(stderr,"Compilation completed\n");*/
    ATBwriteTerm(cid,ATmake("snd-event(done)"));
  }
} 

/*{{{  void process_next_module(int cid) */

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
      ATBwriteTerm(cid,ATmake("snd-event(done)"));
    }
  }
}

/*}}}  */ 
/*{{{  void rec_ack_event(int cid, ATerm term) */

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

/*}}}  */ 
/*{{{  void reshuffle_modules_from(int cid, char *modulename) */

void reshuffle_modules_from(int cid, char *modulename)
{
  ATerm mod;
  ATermList imports;

  mod = ATmake("<str>",modulename);
  if(GetValue(modules_db, mod)) {
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

/*}}}  */   
