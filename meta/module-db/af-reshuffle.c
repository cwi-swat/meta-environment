/* The code for the reshuffling of the equations in a module.
 */

#include "module-db.h"


extern ATermTable modules_db;
extern ATermTable compile_db;
extern ATermList modules_to_process;
extern ATbool compiling;
extern ATbool reshuffling;
extern ATerm top_module;
extern char *output_path;

int equal_term(ATerm term1,ATerm term2)
{
  char *text1, *text2;
  ATerm t1[9], t2[9];

  if(ATmatchTerm(term1,pattern_asfix_sort,&text1) &&
     ATmatchTerm(term2,pattern_asfix_sort,&text2))
    return ATisEqual(term1,term2);
  else if(ATmatchTerm(term1,pattern_asfix_l,&text1) &&
          ATmatchTerm(term2,pattern_asfix_l,&text2))
    return ATisEqual(term1,term2);
  else if(ATmatchTerm(term1,pattern_asfix_ql,&text1) &&
          ATmatchTerm(term2,pattern_asfix_ql,&text2))
    return ATisEqual(term1,term2);
  else if(ATmatchTerm(term1,pattern_asfix_sep,&text1) &&
          ATmatchTerm(term2,pattern_asfix_sep,&text2))
    return ATisEqual(term1,term2);
  else if(ATmatchTerm(term1,pattern_asfix_iter,
                     &t1[0],&t1[1],&t1[2]) &&
          ATmatchTerm(term2,pattern_asfix_iter,
                     &t2[0],&t2[1],&t2[2]))
    return equal_term(t1[0],t2[0]) &&
           equal_term(t1[2],t2[2]);
  else if(ATmatchTerm(term1,pattern_asfix_itersep,
                     &t1[0],&t1[1],&t1[2],&t1[3],&t1[4],
                     &t1[5],&t1[6],&t1[7],&t1[8]) &&
          ATmatchTerm(term2,pattern_asfix_itersep,
                     &t2[0],&t2[1],&t2[2],&t2[3],&t2[4],
                     &t2[5],&t2[6],&t2[7],&t2[8]))
    return equal_term(t1[2],t2[2]) &&
           equal_term(t1[4],t2[4]) &&
           equal_term(t1[8],t2[8]);
  else return ATfalse;
}

int equal_args(ATermList args1,ATermList args2)
{
  ATerm arg1,arg2;
  ATbool equal;

  equal = ATtrue;
  while(equal && !ATisEmpty(args1) && !ATisEmpty(args2)) {
    arg1 = ATgetFirst(args1);
    arg2 = ATgetFirst(args2);
    if(!asfix_is_whitespace(arg1) && !asfix_is_whitespace(arg2)) {
      equal = equal_term(arg1,arg2);
    }
    args1 = ATgetNext(args1);
    args2 = ATgetNext(args2);
  }
  return equal && ATisEmpty(args1) && ATisEmpty(args2);
}

int equal_attrs(ATerm attrs1,ATerm attrs2)
{
  ATerm w1[2], w2[2], l1[2], l2[2];
  ATermList args1, args2;

  if(ATmatchTerm(attrs1,pattern_asfix_noattrs) &&
     ATmatchTerm(attrs2,pattern_asfix_noattrs))
    return ATtrue;
  else if(!ATmatchTerm(attrs1,pattern_asfix_noattrs) &&
          !ATmatchTerm(attrs2,pattern_asfix_noattrs)) {
    if(ATmatchTerm(attrs1, pattern_asfix_attrs,
                  &l1[0],&w1[0],&args1,&w1[1],&l1[1])) {
      if(ATmatchTerm(attrs2, pattern_asfix_attrs,
                    &l2[0],&w2[0],&args2,&w2[1],&l2[1]))
        return equal_args(args1,args2);
      else
        return ATfalse;
    }
    else
      return ATfalse;
  }
  else
    return ATfalse;
}

int equal_prod(ATerm prod1, ATerm prod2)
{
  ATerm mname1, lit1, sort1, w1[4], attrs1;
  ATerm mname2, lit2, sort2, w2[4], attrs2;
  ATermList args1, args2;

  if(ATmatchTerm(prod1, pattern_asfix_prod,
                &mname1,&w1[0],&args1,&w1[1],&lit1,&w1[2],
                &sort1,&w1[3],&attrs1)) {
    if(ATmatchTerm(prod2, pattern_asfix_prod,
                  &mname2,&w2[0],&args2,&w2[1],&lit2,&w2[2],
                  &sort2,&w2[3],&attrs2)) {
      if(ATisEqual(mname1,mname2) && equal_args(args1,args2) &&
         ATisEqual(sort1,sort2) && equal_attrs(attrs1,attrs2))
        return ATtrue;
    }
  }
  return ATfalse;
}

/* The function {\tt AFgetLexFuncsSort} traverse a list
   of modules and looks for all lexical functions
   with the given sorts as result sort. */
ATermList AFgetLexFuncsSort(ATerm sort, ATermList mods)
{
  ATerm lmod, amod, lexfunc, rsort;
  ATermList lexfuncs;
  ATermList functions = ATempty;

  while(!ATisEmpty(mods)) {
    lmod = ATgetFirst(mods);
    amod = GetValue(modules_db,lmod);
    lexfuncs = AFgetModuleLexfuncs(amod);
    lexfuncs = asfix_filter_layout(lexfuncs);
    while(!ATisEmpty(lexfuncs)) {
      lexfunc = ATgetFirst(lexfuncs);
      rsort = AFgetProdSort(lexfunc);
      if(equal_term(sort,rsort)) {
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

/* The function {\tt AFgetEquationsFunc} traverse a list
   of modules and looks for all equations with the given
   context-free function as outermost function symbol in the
   left-hand side. */
ATermList AFgetEquationsFunc(ATerm func,ATermList mods)
{
  ATerm mod, amod, eq, lhs, ofs;
  ATermList eqs;
  ATermList equations = ATempty;

  while(!ATisEmpty(mods)) {
    mod = ATgetFirst(mods);
    amod = GetValue(modules_db,mod);
    eqs = (ATermList)asfix_get_module_eqs(amod);
    eqs = asfix_filter_layout(eqs);
    while(!ATisEmpty(eqs)) {
      eq = ATgetFirst(eqs);
      lhs = asfix_get_equ_lhs(eq);
      ofs = asfix_get_appl_prod(lhs);
      if(equal_prod(func,ofs)) {
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

void AFaddSection(ATerm module, ATerm section)
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

ATerm ATcreateNewModule(ATerm modname)
{
  ATerm newmodule = AFinitModule();
  ATerm newmodname = unique_new_name(modname);
  newmodule = AFputModuleName(newmodule,newmodname);
  PutValue(compile_db,newmodname,newmodule);
  return newmodname;
}

void AFaddEquations(ATerm module, ATermList eqs)
{
  ATerm newmodule = GetValue(compile_db,module);
  newmodule = AFputModuleEqs(newmodule,eqs);
  PutValue(compile_db,module,newmodule);
}

void AFwriteAsfixFile(int cid,ATerm modname)
{
  char *text, *fname;
  int len;
  FILE *output, *input;
  ATerm oldmod, element;
  ATbool write;

  ATerm amod = GetValue(compile_db,modname);

  if(ATmatchTerm(modname,pattern_asfix_id,&text)) {
    /* Check whether the C file exists. */
    len = strlen(output_path) + 1 + strlen(text) + strlen(".c");
    fname = malloc(len + 1);
    if(!fname) 
      ATerror("Not enough memory\n");
    sprintf(fname, "%s/%s.c", output_path, text);
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

    len = strlen(output_path) + 1 + strlen(text) + strlen(".asfix");
    fname = malloc(len + 1);
    if(!fname) 
      ATerror("Not enough memory\n");
    sprintf(fname, "%s/%s.asfix", output_path, text);
    /* Check whether it is necessary to generate new C code
     * because of a modified AsFix file. */
    input = fopen(fname,"r");
    if(input) {
      oldmod = ATreadFromTextFile(input);
      if(!write)
        write = !ATisEqual(oldmod,amod);
      fclose(input);
    }
    else
      write = ATtrue;
    if(write) {
      output = fopen(fname,"w");
      if(!output)
        ATfprintf(stderr,"Cannot open file %s\n",fname);
      else {   
        ATfprintf(output,"%t",amod);
        ATfprintf(output, "\n");
        fclose(output);
      }
      /* write full path name instead of only module name */
      ATfprintf(stderr,"Writing: %s\n", fname);
      element = ATmake("snd-event(generate-code(<term>,<term>))",
                       modname,amod);
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
void AFreshuffleLexicalConstructorFunctions(int cid,
                                             ATerm modname, ATerm newmod,
                                             ATermList orgmods)
{
  ATerm prod, amod, sort, newsection, newsubsection, newmodname;
  ATermList sorts, funcs, eqs;

  amod = GetValue(modules_db,modname);
  sorts = AFgetModuleSorts(amod);
  sorts = asfix_filter_layout(sorts);
  while(!ATisEmpty(sorts)) {
    sort = ATgetFirst(sorts);
    funcs = AFgetLexFuncsSort(sort,orgmods);
    if(!ATisEmpty(funcs)) {
      newsubsection = AFinitLexicalSyntaxSection();
      newsubsection = AFputSectionArgs(newsubsection,funcs);
      newsection = AFinitExportSection();
      newsection = AFputSectionArgs(newsection,
                                    ATmakeList1(newsubsection));
      prod = make_caller_prod(sort);
      eqs = AFgetEquationsFunc(prod,orgmods);
      if(!ATisEmpty(eqs)) {
/* There are equations for the lexical constructor of sort SORT.
 * So, a new module has to be created containing these lexical functions
 * and the corresponding equations.
 */
        newmodname = ATcreateNewModule(modname);
        AFaddSection(newmodname,newsection);
        AFaddEquations(newmodname,eqs);
        AFwriteAsfixFile(cid,newmodname);
      }
      else
/* There are no equations for the lexical constructor of sort SORT.
 * So, this function is to be added to the module containing no
 * equations.
 */
        AFaddSection(newmod,newsection);
    }
    sorts = ATgetNext(sorts);
  }
}

void gen_makefile(ATerm name);

void AFreshuffleModules(int cid,ATermList mods)
{
  ATerm mod, newmod, newmodname, oldamod, cffunc;
  ATermList cffuncs, eqs, orgmods;
  ATerm newsubsection, newsection;

  compile_db = CreateValueStore(500,75);
  orgmods = mods;
  reshuffling = ATtrue;
  while(!ATisEmpty(mods)) {
    mod = ATgetFirst(mods); 
    newmod = ATcreateNewModule(mod);
    AFreshuffleLexicalConstructorFunctions(cid,mod,newmod,orgmods);
    oldamod = GetValue(modules_db,mod);
    cffuncs = AFgetModuleCFfuncs(oldamod);
    cffuncs = asfix_filter_layout(cffuncs);
    while(!ATisEmpty(cffuncs)) {
      cffunc = ATgetFirst(cffuncs);
      newsubsection = AFinitContextFreeSyntaxSection();
      newsubsection = AFputSectionArgs(newsubsection,
                                       ATmakeList1(cffunc));
      newsection = AFinitExportSection();
      newsection = AFputSectionArgs(newsection,
                                    ATmakeList1(newsubsection));
      eqs = AFgetEquationsFunc(cffunc,orgmods);
      if(!ATisEmpty(eqs)) {
        newmodname = ATcreateNewModule(mod);
        AFaddSection(newmodname,newsection);
        AFaddEquations(newmodname,eqs);
        AFwriteAsfixFile(cid,newmodname);
      } else {
        AFaddSection(newmod,newsection);
      }
      cffuncs = ATgetNext(cffuncs);
    }
    AFwriteAsfixFile(cid,newmod);
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





