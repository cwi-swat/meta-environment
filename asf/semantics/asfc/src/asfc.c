/* A first version of the COMPILER in ToolBus C. 
   This program is written by Mark van den Brand and
   improved by Pieter Olivier.

   The following functions are available:
   void rec_terminate(ATerm t)
   ATerm get_section(ATerm name,ATerm module)
   void create_module_db()
   ATermList clear_module_db(ATermList db)
   ATerm add_module(term *asfix)
   void delete_module(ATerm name)
*/

#include <assert.h>
#include <atb-tool.h>
#include <string.h>
#include <ctype.h>
#include <AsFix.h>
#include "aterm2.h"
#include "deprecated.h"

/*
#include <term-list.h>
#include <abbrevs.h>
*/
#include <sys/times.h>
#include <stdlib.h>
#include <limits.h>
#include "compiler.tif.h"
#include "support/support.h"

extern ATerm pattern_asfix_iter;
extern ATerm pattern_asfix_itersep;
extern ATerm pattern_asfix_sort;
extern ATerm pattern_asfix_prod;
extern ATerm pattern_asfix_l;
extern ATerm pattern_asfix_ql;
extern ATerm pattern_asfix_nlws;
extern ATerm pattern_asfix_noattrs;
extern ATerm pattern_asfix_attrs;
extern ATerm pattern_asfix_contextfreesyntax;
extern ATerm pattern_asfix_lexicalsyntax;
extern ATerm pattern_asfix_exports;
extern ATerm pattern_asfix_hiddens;
extern ATerm pattern_asfix_id;
extern ATerm pattern_asfix_module;
extern ATerm pattern_asfix_lexcaller;
extern ATerm pattern_asfix_term;
/*
extern Symbol oksym;
extern Symbol tuplesym;
extern Symbol nullsym;
*/

extern void resolve_all();
extern void register_all();
extern void init_all();

#define TICK2SEC(t)		(((double)(t))/CLK_TCK)

ATerm expand_to_asfix(ATerm mod, char *name);
int print_source(FILE *f, ATerm term);
/*
void pp_rnx(FILE *f, ATerm t, int indent);
ATerm asfix2rnx(ATerm asfix);
*/
ATerm asfix_trans(ATerm mod);
void AFinitExpansionTerms();
void AFinitAsFixPatterns();
ATermList get_equations_for_func(ATerm func, ATermList mods);
ATerm AFcollapseModule(ATerm module);

ATerm make_caller_prod(ATerm sort);
ATerm innermost(ATerm t);
ATerm toasfix(ATerm t, ATerm f, ATerm n);
void init_patterns();

int print_term_source(FILE *f, ATerm term);

ATerm modules_db = NULL;

void change_modules_db(ATerm new_db)
{
  if(!ATisEqual(new_db, modules_db))
    modules_db = new_db;
}

void rec_terminate(int cid, ATerm t) 
{
  exit(0);
}

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

/*ATerm make_caller_prod(ATerm sort)
{
  ATerm prod;
  char *text;
  int i;

  assertp(ATmatchTerm(sort, pattern_asfix_sort, &text));
  text = strdup(text);
  if(!text) {
    fprintf(stderr,"Not enough memory\n");
    exit(1);
  }
  for(i=0; text[i]; i++)
    text[i] = tolower(text[i]);
  prod = ATmakeTerm(ar, pattern_asfix_lexcaller,
                   ATmakeTerm(ar, pattern_asfix_l,text), sort);
  free(text);
  return prod;
}*/

ATerm remove_func_from_module(ATerm func, ATerm amod);
/* The function {\tt get_lex_funcs_for_sort} traverse a list
   of modules and looks for all lexical functions
   with the given sorts as result sort. */
ATermList get_lex_funcs_for_sort(ATerm sort, ATermList mods)
{
  ATerm lmod, amod, oldamod, lexfunc, rsort;
  ATermList lexfuncs, orgmods;
  ATermList functions = ATempty;

  orgmods = mods;
  while(!ATisEmpty(mods)) {
    lmod = ATgetFirst(mods);
    amod = ATdictGet(modules_db,lmod);
    lexfuncs = AFgetModuleLexfuncs(amod);
    lexfuncs = asfix_filter_layout(lexfuncs);
    while(!ATisEmpty(lexfuncs)) {
      lexfunc = ATgetFirst(lexfuncs);
      rsort = AFgetProdSort(lexfunc);
      if(equal_term(sort,rsort)) {
        oldamod = ATdictGet(modules_db,lmod);
        amod = remove_func_from_module(lexfunc,oldamod);
        change_modules_db(ATdictPut(modules_db,lmod,amod));
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

ATermList get_cf_funcs_for_sort(ATerm sort, ATermList mods)
{
  ATerm lmod, amod, oldamod, cffunc, rsort;
  ATermList cffuncs, orgmods, neweqs, eqs;
  ATermList functions = ATempty;

  orgmods = mods;
  while(!ATisEmpty(mods)) {
    lmod = ATgetFirst(mods);
    amod = ATdictGet(modules_db,lmod);
    cffuncs = AFgetModuleCFfuncs(amod);
    cffuncs = asfix_filter_layout(cffuncs);
    while(!ATisEmpty(cffuncs)) {
      cffunc = ATgetFirst(cffuncs);
      rsort = AFgetProdSort(cffunc);
      if(equal_term(sort,rsort)) {
        oldamod = ATdictGet(modules_db,lmod);
        amod = remove_func_from_module(cffunc,oldamod);
        change_modules_db(ATdictPut(modules_db,lmod,amod));
        if(!ATisEmpty(functions))
          functions = ATappend(functions,
                               ATreadFromString("w(\"\\n\")"));
        functions = ATappend(functions, cffunc);
        neweqs = get_equations_for_func(cffunc,mods);
        if(!ATisEmpty(neweqs)) {
          oldamod = ATdictGet(modules_db,lmod);
          eqs = (ATermList)AFgetModuleEqs(oldamod);
          eqs = ATconcat(ATappend(eqs,pattern_asfix_nlws),
                         neweqs);
          amod = AFputModuleEqs(amod,eqs);
          change_modules_db(ATdictPut(modules_db,lmod,amod));
        }
      }
      cffuncs = ATgetNext(cffuncs);
    }
    mods = ATgetNext(mods);
  }
  return functions;
}

ATermList remove_equation(ATerm eq,ATermList eqs)
{
  ATerm eq2;
  ATbool found;
  ATermList neweqs = ATempty;

  found = ATfalse;
  while(!found && !ATisEmpty(eqs)) {
    eq2 = ATgetFirst(eqs);
    if(AFnotLayout(eq2)) { /* No layout */
      if(ATisEqual(eq,eq2)) {
        found = ATtrue;
        eqs = ATgetNext(eqs); /* Skip over element */
        if(!ATisEmpty(eqs)) {
          eqs = ATgetNext(eqs); /* Skip over layout */
          neweqs = ATconcat(neweqs,eqs); /* Concatenate lists */
        }
        else {  /* Last element is removed */
          if(!ATisEmpty(neweqs)) {
            /* Remove previous layout element */
            neweqs = ATgetPrefix(neweqs);
          }
        }
        return neweqs;
      }
    }
    neweqs = ATappend(neweqs,eq2);
    eqs = ATgetNext(eqs);
  }
  return neweqs;
}
  
/* The function {\tt get_equations_for_func} traverse a list
   of modules and looks for all equations with the given
   context-free function as outermost function symbol in the
   left-hand side. */
ATermList get_equations_for_func(ATerm func,ATermList mods)
{
  ATerm mod, amod, eq, lhs, ofs;
  ATermList eqs, neweqs;
  ATermList equations = ATempty;

  while(!ATisEmpty(mods)) {
    mod = ATgetFirst(mods);
    amod = ATdictGet(modules_db,mod);
    eqs = (ATermList)asfix_get_module_eqs(amod);
    eqs = asfix_filter_layout(eqs);
    while(!ATisEmpty(eqs)) {
      eq = ATgetFirst(eqs);
      lhs = asfix_get_equ_lhs(eq);
      ofs = asfix_get_appl_prod(lhs);
      if(equal_prod(func,ofs)) {
/* This equation should also be removed from the list of equations
   of the given module. */
        neweqs = (ATermList)asfix_get_module_eqs(amod);
        neweqs = remove_equation(eq,neweqs);
        amod = asfix_put_module_eqs(amod, neweqs);
        if(!ATisEmpty(equations))
          equations = ATappend( equations, ATreadFromString( "w(\"\\n\")"));
        equations = ATappend( equations, eq);
      }
      eqs = ATgetNext(eqs);
    }
    change_modules_db(ATdictPut(modules_db,mod,amod));
    mods = ATgetNext(mods);
  };
  return equations;
}

ATermList remove_func_from_funcs(ATerm func, ATermList funcs)
{
  ATbool found;
  ATerm func2;
  ATermList newfuncs = ATempty;

  
  found = ATfalse;
  while(!found && !ATisEmpty(funcs)) {
    func2 = ATgetFirst(funcs);
    if(AFnotLayout(func2)) {
      if(equal_prod(func,func2)) {
        found = ATtrue;
        funcs = ATgetNext(funcs);
        if(!ATisEmpty(funcs)) {
          funcs = ATgetNext(funcs); /* Skip the next layout */
          newfuncs = ATconcat(newfuncs,funcs);
        }
        else { /* The last element of the list was removed */
          if(!ATisEmpty(newfuncs))
            newfuncs = ATgetPrefix(newfuncs);
        }
        return newfuncs;
      }
    }
    newfuncs = ATappend(newfuncs,func2);
    funcs = ATgetNext(funcs);
  }
  return newfuncs;
}

ATermList remove_func_from_subsections(ATerm func, ATermList subsections)
{
  ATerm subsection, newsubsection;
  ATermList cffuncs, newcffuncs;
  ATermList lexfuncs, newlexfuncs;
  ATerm t[2];
  ATermList newsubsections = ATempty;

  
  while(!ATisEmpty(subsections)) {
    subsection = ATgetFirst(subsections);
    if(ATmatchTerm(subsection, pattern_asfix_contextfreesyntax,
                   &t[0], &t[1], &cffuncs)) {
      newcffuncs = remove_func_from_funcs(func,cffuncs);
      if(!ATisEmpty(newcffuncs)) {
        newsubsection = ATmakeTerm(pattern_asfix_contextfreesyntax,
                                   t[0], t[1], newcffuncs);
        newsubsections = ATappend(newsubsections,newsubsection);
      }
      else {
        subsections = ATgetNext(subsections);
        if(!ATisEmpty(subsections)) {
          subsection = ATgetFirst(subsections);
        } 
        else {
          if(!ATisEmpty(newsubsections)) {
            newsubsections = ATgetPrefix(newsubsections);
          }
        }
      }
    }
    else if(ATmatchTerm(subsection, pattern_asfix_lexicalsyntax,
                  &t[0], &t[1], &lexfuncs)) {
      newlexfuncs = remove_func_from_funcs(func,lexfuncs);
      if(!ATisEmpty(newlexfuncs)) {
        newsubsection = ATmakeTerm( pattern_asfix_lexicalsyntax,
                                  t[0], t[1], newlexfuncs);
        newsubsections = ATappend(newsubsections,newsubsection);
      }
      else {
        subsections = ATgetNext(subsections);
        if(!ATisEmpty(subsections)) {
          subsection = ATgetFirst(subsections);
        }
        else {
          if(!ATisEmpty(newsubsections)) {
            newsubsections = ATgetPrefix(newsubsections);
          }
        }
      }
    }
    else 
      newsubsections = ATappend(newsubsections,subsection);
    if(!ATisEmpty(subsections)) 
      subsections = ATgetNext(subsections);
  }
  return newsubsections;
}

ATermList remove_func_from_sections(ATerm func, ATermList sections)
{
  ATerm section, newsection;
  ATermList subsections, newsubsections;
  ATerm t[2];
  ATermList newsections = ATempty;

  
  while(!ATisEmpty(sections)) {
    section = ATgetFirst(sections);
    if(ATmatchTerm(section, pattern_asfix_exports,
                   &t[0], &t[1], &subsections)) {
      newsubsections =
         remove_func_from_subsections(func,subsections);
/*ATfprintf(stderr,"remove_func_from_sections: %t\n",func);*/
      if(!ATisEmpty(newsubsections)) {
        newsection = ATmakeTerm(pattern_asfix_exports,
                                t[0], t[1], newsubsections);
        newsections = ATappend(newsections,newsection);
      }
      else {
        sections = ATgetNext(sections);
        if(!ATisEmpty(sections)) {
          section = ATgetFirst(sections);
        } 
        else {
          if(!ATisEmpty(newsections)) { /* Remove the last added layout */
            newsections = ATgetPrefix(newsections);
          }
        }
      }
    }
    else if(ATmatchTerm(section, pattern_asfix_hiddens,
                        &t[0], &t[1], &subsections)) {
      newsubsections = 
        remove_func_from_subsections(func,subsections);
      if(!ATisEmpty(newsubsections)) {
        newsection = ATmakeTerm(pattern_asfix_hiddens,
                                t[0], t[1], newsubsections);
        newsections = ATappend(newsections,newsection);
      }
      else {
        sections = ATgetNext(sections);
        if(!ATisEmpty(sections)) {
          section = ATgetFirst(sections);
        } 
        else {
          if(!ATisEmpty(newsections)) {
            newsections = ATgetPrefix(newsections);
          }
        }
      }
    }
    else 
      newsections = ATappend(newsections,section);
    if(!ATisEmpty(sections))
      sections = ATgetNext(sections);
  }
  return newsections;
}

ATerm remove_func_from_module(ATerm func, ATerm amod)
{
  ATerm result;
  ATermList sections, newsections;

  sections = AFgetModuleSections(amod);
  newsections = remove_func_from_sections(func,sections);
  result = AFputModuleSections(amod,newsections);
  return result;
}

ATerm unique_new_name(ATerm name)
{
  char *text, *newtext;
  ATerm newname;
  int n = 1;

  assert(ATmatchTerm(name,pattern_asfix_id,&text));
  newtext = malloc(strlen(text)+16);
  sprintf(newtext,"AUX-%s%d",text,n);
  newname = ATmakeTerm(pattern_asfix_id,newtext);
  while(ATdictGet(modules_db,newname)) {
    n++;
    sprintf(newtext,"AUX-%s%d",text,n);
    newname = ATmakeTerm(pattern_asfix_id,newtext);
  }
  free(newtext);
  return newname;
}

void reshuffle_per_sort(ATerm mod, ATermList orgmods)
{

  ATerm prod, amod, oldamod, sort, newsection, newsubsection;
  ATermList sorts, mods, funcs, sections, eqs, neweqs;


ATfprintf(stderr,"Reshuffling module per sort: %t\n",mod);
  amod = ATdictGet(modules_db,mod);
  sorts = AFgetModuleSorts( amod);
  sorts = asfix_filter_layout(sorts);
  while(!ATisEmpty(sorts)) {
    sort = ATgetFirst(sorts);
ATfprintf(stderr,"Reshuffling sort: %t\n",sort);
    mods = ATremoveAll(orgmods,mod);
    funcs = get_lex_funcs_for_sort(sort,mods);
    if(!ATisEmpty(funcs)) {
      newsubsection = AFinitLexicalSyntaxSection();
      newsubsection = AFputSectionArgs(newsubsection,funcs);
      newsection = AFinitExportSection();
      newsection = AFputSectionArgs(newsection,
                                    ATmakeList1(newsubsection));
      oldamod = ATdictGet(modules_db,mod);
      sections = AFgetModuleSections(oldamod);
      sections = ATconcat(sections,
                          ATmakeList2(pattern_asfix_nlws,
                                      newsection));
      amod = AFputModuleSections(amod,sections);
      change_modules_db(ATdictPut(modules_db,mod,amod));
    }
    prod = make_caller_prod(sort);
    neweqs = get_equations_for_func(prod,mods);
    if(!ATisEmpty(neweqs)) {
      oldamod = ATdictGet(modules_db,mod);
      eqs = (ATermList)AFgetModuleEqs(oldamod);
      if(!ATisEmpty(eqs))
        eqs = ATconcat(
                          ATappend(eqs,pattern_asfix_nlws),
                          neweqs);
      else
        eqs = neweqs;
      amod = AFputModuleEqs(amod,eqs);
      change_modules_db(ATdictPut(modules_db,mod,amod));
    }
    sorts = ATgetNext(sorts);
  }
}

ATermList reshuffle_modules(ATermList mods)
{
  ATerm mod, newmod, oldamod, newamod, cffunc, amod;
  ATermList orgmods, cffuncs, eqs;
  ATerm newsubsection, newsection;
  ATermList result;
  ATermList newmods = ATempty;


  orgmods = mods;
  while(!ATisEmpty(mods)) {
    mod = ATgetFirst(mods);
    reshuffle_per_sort(mod,orgmods);
ATfprintf(stderr,"reshuffle_per_sort finished\n");
    oldamod = ATdictGet(modules_db,mod);
    cffuncs = AFgetModuleCFfuncs( oldamod);
    cffuncs = asfix_filter_layout(cffuncs);
    while(!ATisEmpty(cffuncs)) {
      cffunc = ATgetFirst(cffuncs);
      eqs = get_equations_for_func(cffunc,orgmods);
      if(!ATisEmpty(eqs)) {
        oldamod = ATdictGet(modules_db,mod);
        amod = remove_func_from_module(cffunc,oldamod);
        change_modules_db(ATdictPut(modules_db,mod,amod));
        newamod = AFinitModule();
        newmod = unique_new_name(mod);
ATfprintf(stderr,"Creating new module: %t\n",newmod);
        newamod = AFputModuleName(newamod,newmod);
        newamod = AFputModuleEqs(newamod,eqs);
        newsubsection = AFinitContextFreeSyntaxSection();
        newsubsection = AFputSectionArgs(newsubsection,
                                         ATmakeList1(cffunc));
        newsection = AFinitExportSection();
        newsection = AFputSectionArgs(newsection,
                                      ATmakeList1(newsubsection));
        newamod = AFputModuleSections(newamod,
                                      ATmakeList1(newsection));
        change_modules_db(ATdictPut(modules_db,newmod,newamod));
        newmods = ATappend(newmods,newmod);
      }
      cffuncs = ATgetNext(cffuncs);
    }
    mods = ATgetNext(mods);
  };
  mods = orgmods;
  while(!ATisEmpty(mods)) {
    mod = ATgetFirst(mods);
    newamod = ATdictGet(modules_db,mod);
    newmod = unique_new_name(mod);
ATfprintf(stderr,"Creating new module: %t\n",newmod);
    newamod = AFputModuleName(newamod,newmod);
    change_modules_db(ATdictPut(modules_db,newmod,newamod));
    newmods = ATappend(newmods,newmod);
    mods = ATgetNext(mods);
  };
  result = ATconcat(orgmods,newmods);
  return result;
}

void compile_module(int cid, ATermList newmods)
{
  char *text, *fname;
  ATerm mod, amod, expmod, reduct, cmod;
  ATerm aname, idname, file, modname, trm;
  int len;
  FILE *output, *input;
  ATerm oldmod;
  ATbool write;

  /* Temporary solution to obtain path where generated C files should be
   * stored. We now use the environment variable "COMPILER_OUTPUT" to obtain
   * the directory. When this variable is not defined we use the original
   * value (so the compiler does not depend on this change).
   *
   * Merijn.
   */
  
  char *path = "/home/markvdb/AsFix2C/muASF-lists/asfixfiles3/";
  if( getenv( "COMPILER_OUTPUT" ) != NULL )
     path = getenv( "COMPILER_OUTPUT" );


ATfprintf(stderr,"compile_module entered\n");
  if(!ATisEmpty(newmods)) {
    do {
      mod = ATgetFirst(newmods);
      amod = ATdictGet(modules_db,mod);
      assert(ATmatchTerm(mod,pattern_asfix_id,&text));
      newmods = ATgetNext(newmods);
    } while (strncmp(text,"AUX-",4) != 0);
    if(strncmp(text,"AUX-",4) == 0) {
      len = strlen(path) + 1 + strlen(text) + strlen(".asfix");
      fname = malloc(len + 1);
      if(!fname) {
        fprintf(stderr,"Not enough memory\n");
        exit(1);
      }

      sprintf(fname, "%s/%s.asfix", path, text);

/* Check whether it is necessary to generate new C code. */
      input = fopen(fname,"r");
      if(input) {
        oldmod = ATreadFromTextFile(input);
        write = !ATisEqual(oldmod,amod);
        fclose(input);
      }
      else 
        write = ATtrue;
      if (write) {
        output = fopen(fname,"w");
        if(!output) 
          ATfprintf(stderr,"Cannot open file %s\n",fname);
        else {
/*
          cmod = AFcollapseModule(amod);
          ATfprintf(output,"%t",cmod); 
*/
          ATfprintf(output,"%t",amod);

          ATfprintf(output, "\n");
          fclose(output);
        }
        /* write full path name instead of only module name */
        ATfprintf(stderr,"Writing: %s\n", fname);

        expmod = expand_to_asfix(amod,fname);

ATfprintf(stderr,"Reducing ...\n");

        assert(ATmatchTerm(expmod, pattern_asfix_term, NULL, NULL,
               &file, NULL, &modname, NULL, &trm, NULL, NULL));
       
        reduct = innermost(trm);
ATfprintf(stderr,"Reducing finished.\n");

        aname  = ATmake("l(<str>)",fname);
        idname = ATreadFromString("id(\"AsFix2C\")");
        cmod = toasfix(reduct, aname, idname);
        free(fname);
        len = strlen(path) + 1 + strlen(text) + strlen(".c");
        fname = malloc(len + 1);
        if(!fname) {
          fprintf(stderr,"Not enough memory\n");
          exit(1);
        }
        sprintf(fname, "%s/%s.c", path, text );
        output = fopen(fname,"w");
        free(fname);
        if(!output) 
          ATfprintf(stderr,"Cannot open file %s\n", fname);
        else {
          ToC_code(cmod,output);
          ATfprintf(output, "\n");
          fclose(output);
        }
        ATfprintf(stderr,"Writing: %s.c\n", text);
      }
      else
        free(fname);
      ATBwriteTerm(cid,ATmake("snd-event(compile(<term>,[<list>]))",
                              mod,newmods));
    }
  }
  else 
    ATBwriteTerm(cid,ATmake("snd-event(done)"));
}

void compile_modules(int cid,ATerm mods)
{
  ATermList newmods;
/*  struct tms start, compiling;
  clock_t user, system;*/


  ATfprintf(stderr,"Reshuffling ... %t\n",mods);
/*  times(&start);*/
  newmods = reshuffle_modules((ATermList) mods);
  ATfprintf(stderr,"Compiling ... %t\n",newmods);
  compile_module(cid,newmods);
/*  times(&compiling);

  user = compiling.tms_utime - start.tms_utime;
  system = compiling.tms_stime - start.tms_stime;
  fprintf(stderr, "compilation: %f user, %f system\n", 
	 TICK2SEC(user), TICK2SEC(system));*/
  /* return result;*/
}

void rec_ack_event(int cid,ATerm cterm)
{
  ATerm mod;
  ATermList newmods;

  if(ATmatch(cterm,"compile(<term>,[<list>])",&mod,&newmods)) {
    compile_module(cid,newmods);
  }
  else if(ATmatch(cterm,"done")) {
    ATfprintf(stderr,"Compilation completed\n");
  }
  else
    exit(1);
}

void create_module_db(int cid)
{
  change_modules_db(ATdictCreate());
}

void clear_module_db(int cid)
{
  change_modules_db(ATdictCreate());
}

ATerm add_module(int cid, ATerm asfix)
{
  ATerm t[7]; 
  ATerm modname;
  ATermList sections;
  ATerm newasfix;
  ATerm result;


  if(ATmatchTerm(asfix,pattern_asfix_module,
     &t[0], &t[1], &modname, &t[2], &sections, &t[3], &t[4], &t[5], &t[6])) {
    if(ATdictGet(modules_db,modname) == ATfalse) {
      newasfix = AFexpandModule(asfix);
      change_modules_db(ATdictPut(modules_db,modname,newasfix));
    };
    result = ATmake("snd-value(ok(<term>))", modname);
    return result;
  } else {
    ATfprintf(stderr, "not an asfix term: %t\n", asfix);
    exit(1);
  }
}

ATerm delete_module(int cid, ATerm name)
{
  ATerm result;

  change_modules_db(ATdictRemove( modules_db,name));
  result = ATmake("snd-value(deleted(<term>))",name);
  return result;
}

int main(int argc, char **argv)
{
  int cid;
  ATerm bottomOfStack;

  ATBinit(argc, argv, &bottomOfStack);
  AFinit(argc, argv, &bottomOfStack);

  cid = ATBconnect(NULL, NULL, -1, compiler_handler);

  AFinitExpansionTerms();
  AFinitAsFixPatterns();
  init_patterns();

  c_rehash(INITIAL_TABLE_SIZE);
  register_all();
  resolve_all();
  init_all();

  ATprotect(&modules_db);
/*
  oksym = ATmakeSymbol("ok", 0, ATfalse);
  ATprotectSymbol(oksym);
  tuplesym = ATmakeSymbol("tuple", 0, ATfalse);
  ATprotectSymbol(tuplesym);
  nullsym = ATmakeSymbol("null", 0, ATfalse);
  ATprotectSymbol(nullsym);
*/

  ATBeventloop();

  return 0;
}
