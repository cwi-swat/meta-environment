/* A first version of the COMPILER in ToolBus C. 
   This program is written by Mark van den Brand and
   improved by Pieter Olivier.

   The following functions are available:
   void rec_terminate(aterm *t)
   aterm *get_section(aterm *name,aterm *module)
   void create_module_db()
   aterm_list *clear_module_db(aterm_list *db)
   aterm_list *add_module(term *asfix)
   void delete_module(aterm *name)
*/

#include <tb-tool.h>
#include <string.h>
#include <ctype.h>
#include <asfix.h>
#include <term-list.h>
#include <abbrevs.h>
#include <sys/times.h>
#include <limits.h>
#include "compiler.tif.c"
#include "support/support.h"

extern aterm *pattern_asfix_iter;
extern aterm *pattern_asfix_itersep;
extern aterm *pattern_asfix_sort;
extern aterm *pattern_asfix_prod;
extern aterm *pattern_asfix_l;
extern aterm *pattern_asfix_ql;
extern aterm *pattern_asfix_nlws;
extern aterm *pattern_asfix_noattrs;
extern aterm *pattern_asfix_attrs;
extern aterm *pattern_asfix_contextfreesyntax;
extern aterm *pattern_asfix_lexicalsyntax;
extern aterm *pattern_asfix_exports;
extern aterm *pattern_asfix_hiddens;
extern aterm *pattern_asfix_id;
extern aterm *pattern_asfix_module;
extern aterm *pattern_asfix_lexcaller;
extern aterm *pattern_asfix_term;

#define TICK2SEC(t)		(((double)(t))/CLK_TCK)

aterm *expand_to_asfix(arena *ar,aterm *mod,char *name);
int print_source(FILE *f, aterm *term);
void pp_rnx(FILE *f, aterm *t, int indent);
aterm *asfix2rnx(arena *ar,aterm *asfix);
aterm *asfix_trans(arena *ar,aterm *mod);
void init_expansion_terms();
void init_asfix_patterns();
aterm_list *get_equations_for_func(arena *ar,aterm *func,aterm_list *mods);
aterm *AFcollapseModule(arena *ar, aterm *module);

aterm *make_caller_prod(arena *ar,aterm *sort);
aterm *innermost(arena *ar, aterm *t);
aterm *toasfix(arena *ar, aterm *t, aterm *f, aterm *n);
void init_patterns(arena *ar);

int print_term_source(FILE *f, aterm *term);

aterm_list *modules_db;

FATAL_ERROR

void change_modules_db(aterm *new_db)
{
  if(!t_equal(new_db, modules_db)) {
    if(modules_db)
      Tunprotect(modules_db);
    modules_db = new_db;
    if(modules_db)
      Tprotect(modules_db);
  }
}

void rec_terminate(int cid, aterm *t) 
{
  exit(0);
}

int equal_term(aterm *term1,aterm *term2)
{
  char *text1, *text2;
  aterm *t1[9], *t2[9];

  if(TmatchTerm(term1,pattern_asfix_sort,&text1) &&
     TmatchTerm(term2,pattern_asfix_sort,&text2))
    return t_equal(term1,term2);
  else if(TmatchTerm(term1,pattern_asfix_l,&text1) &&
          TmatchTerm(term2,pattern_asfix_l,&text2))
    return t_equal(term1,term2);
  else if(TmatchTerm(term1,pattern_asfix_ql,&text1) &&
          TmatchTerm(term2,pattern_asfix_ql,&text2))
    return t_equal(term1,term2);
  else if(TmatchTerm(term1,pattern_asfix_iter,
                     &t1[0],&t1[1],&t1[2]) &&
          TmatchTerm(term2,pattern_asfix_iter,
                     &t2[0],&t2[1],&t2[2]))
    return equal_term(t1[0],t2[0]) &&
           equal_term(t1[2],t2[2]);
  else if(TmatchTerm(term1,pattern_asfix_itersep,
                     &t1[0],&t1[1],&t1[2],&t1[3],&t1[4],
                     &t1[5],&t1[6],&t1[7],&t1[8]) &&
          TmatchTerm(term2,pattern_asfix_itersep,
                     &t2[0],&t2[1],&t2[2],&t2[3],&t2[4],
                     &t2[5],&t2[6],&t2[7],&t2[8]))
    return equal_term(t1[2],t2[2]) &&
           equal_term(t1[4],t2[4]) &&
           equal_term(t1[8],t2[8]);
  else return Tfalse;
}

int equal_args(aterm_list *args1,aterm_list *args2)
{
  aterm *arg1,*arg2;
  Tbool equal;

  equal = Ttrue;
  while(equal && !t_is_empty(args1) && !t_is_empty(args2)) {
    arg1 = t_list_first(args1);
    arg2 = t_list_first(args2);
    if(!asfix_is_whitespace(arg1) && !asfix_is_whitespace(arg2)) {
      equal = equal_term(arg1,arg2);
    }
    args1 = t_list_next(args1);
    args2 = t_list_next(args2);
  }
  return equal && t_is_empty(args1) && t_is_empty(args2);
}

int equal_attrs(aterm *attrs1,aterm *attrs2)
{
  aterm *w1[2],*w2[2], *l1[2],*l2[2];
  aterm_list *args1,*args2;

  if(TmatchTerm(attrs1,pattern_asfix_noattrs) &&
     TmatchTerm(attrs2,pattern_asfix_noattrs)) 
    return Ttrue;
  else if(!TmatchTerm(attrs1,pattern_asfix_noattrs) &&
          !TmatchTerm(attrs2,pattern_asfix_noattrs)) {
    if(TmatchTerm(attrs1, pattern_asfix_attrs,
                  &l1[0],&w1[0],&args1,&w1[1],&l1[1])) {
      if(TmatchTerm(attrs2, pattern_asfix_attrs,
                    &l2[0],&w2[0],&args2,&w2[1],&l2[1]))
        return equal_args(args1,args2);
      else
        return Tfalse;
    }
    else
      return Tfalse;
  }
  else
    return Tfalse;
}

int equal_prod(aterm *prod1,aterm *prod2)
{
  aterm *mname1,*lit1,*sort1,*w1[4],*attrs1;
  aterm *mname2,*lit2,*sort2,*w2[4],*attrs2;
  aterm_list *args1,*args2;

  if(TmatchTerm(prod1, pattern_asfix_prod,
                &mname1,&w1[0],&args1,&w1[1],&lit1,&w1[2],
                &sort1,&w1[3],&attrs1)) {
    if(TmatchTerm(prod2, pattern_asfix_prod,
                  &mname2,&w2[0],&args2,&w2[1],&lit2,&w2[2],
                  &sort2,&w2[3],&attrs2)) {
      if(t_equal(mname1,mname2) && equal_args(args1,args2) &&
         t_equal(sort1,sort2) && equal_attrs(attrs1,attrs2)) 
        return Ttrue;
    }
  }
  return Tfalse;
}

/*aterm *make_caller_prod(arena *ar,aterm *sort)
{
  aterm *prod;
  char *text;
  int i;

  assertp(TmatchTerm(sort, pattern_asfix_sort, &text));
  text = strdup(text);
  if(!text) {
    fprintf(stderr,"Not enough memory\n");
    exit(1);
  }
  for(i=0; text[i]; i++)
    text[i] = tolower(text[i]);
  prod = TmakeTerm(ar, pattern_asfix_lexcaller,
                   TmakeTerm(ar, pattern_asfix_l,text), sort);
  free(text);
  return prod;
}*/

aterm *remove_func_from_module(arena *ar,aterm *func, aterm *amod);
/* The function {\tt get_lex_funcs_for_sort} traverse a list
   of modules and looks for all lexical functions
   with the given sorts as result sort. */
aterm_list *get_lex_funcs_for_sort(arena *ar,aterm *sort, 
                                   aterm_list *mods)
{
  aterm *lmod,*amod,*oldamod,*lexfunc,*rsort;
  aterm_list *lexfuncs, *orgmods;
  aterm_list *functions = t_empty(NULL);
  arena local;

  TinitArena(t_world(*ar), &local);
  orgmods = mods;
  while(!t_is_empty(mods)) {
    lmod = t_list_first(mods);
    amod = TdictGet(modules_db,lmod);
    lexfuncs = AFgetModuleLexfuncs(&local,amod);
    lexfuncs = asfix_filter_layout(&local,lexfuncs);
    while(!t_is_empty(lexfuncs)) {
      lexfunc = t_list_first(lexfuncs);
      rsort = AFgetProdSort(lexfunc);
      if(equal_term(sort,rsort)) {
        oldamod = TdictGet(modules_db,lmod);
        amod = remove_func_from_module(&local,lexfunc,oldamod);
        change_modules_db(TdictPut(&local,modules_db,lmod,amod));
        if(!t_is_empty(functions))
          functions = TlistAppend(&local,
                                  functions,
                                  TmakeSimple(&local, "w(\"\\n\")"));
        functions = TlistAppend(&local, functions, lexfunc);
      }
      lexfuncs = t_list_next(lexfuncs);
    }
    mods = t_list_next(mods);
  }
  Tadd2Arena(ar,functions);
  TdestroyArena(&local);
  return functions;
}

aterm_list *get_cf_funcs_for_sort(arena *ar,aterm *sort,
                                   aterm_list *mods)
{
  aterm *lmod,*amod,*oldamod,*cffunc,*rsort;
  aterm_list *cffuncs, *orgmods, *neweqs, *eqs;
  aterm_list *functions = t_empty(NULL);
  arena local;

  TinitArena(t_world(*ar), &local);
  orgmods = mods;
  while(!t_is_empty(mods)) {
    lmod = t_list_first(mods);
    amod = TdictGet(modules_db,lmod);
    cffuncs = AFgetModuleCFfuncs(&local,amod);
    cffuncs = asfix_filter_layout(&local,cffuncs);
    while(!t_is_empty(cffuncs)) {
      cffunc = t_list_first(cffuncs);
      rsort = AFgetProdSort(cffunc);
      if(equal_term(sort,rsort)) {
        oldamod = TdictGet(modules_db,lmod);
        amod = remove_func_from_module(&local,cffunc,oldamod);
        change_modules_db(TdictPut(&local,modules_db,lmod,amod));
        if(!t_is_empty(functions))
          functions = TlistAppend(&local,
                                  functions,
                                  TmakeSimple(&local, "w(\"\\n\")"));
        functions = TlistAppend(&local, functions, cffunc);
        neweqs = get_equations_for_func(&local,cffunc,mods);
        if(!t_is_empty(neweqs)) {
          oldamod = TdictGet(modules_db,lmod);
          eqs = AFgetModuleEqs(oldamod);
          eqs = TlistConcat(&local,
                            TlistAppend(&local,eqs,pattern_asfix_nlws),
                            neweqs);
          amod = AFputModuleEqs(&local,amod,eqs);
          change_modules_db(TdictPut(&local,modules_db,lmod,amod));
        }
      }
      cffuncs = t_list_next(cffuncs);
    }
    mods = t_list_next(mods);
  }
  Tadd2Arena(ar,functions);
  TdestroyArena(&local);
  return functions;
}

aterm_list *remove_equation(arena *ar,aterm *eq,aterm_list *eqs)
{
  aterm *eq2;
  Tbool found;
  arena local;
  aterm_list *neweqs = t_empty(NULL);

  TinitArena(t_world(*ar), &local);

  found = Tfalse;
  while(!found && !t_is_empty(eqs)) {
    eq2 = t_list_first(eqs);
    if(AFnotLayout(eq2)) { /* No layout */
      if(t_equal(eq,eq2)) {
        found = Ttrue;
        eqs = t_list_next(eqs); /* Skip over element */
        if(!t_is_empty(eqs)) {
          eqs = t_list_next(eqs); /* Skip over layout */
          neweqs = TlistConcat(&local,neweqs,eqs); /* Concatenate lists */
        }
        else {  /* Last element is removed */
          if(!t_is_empty(neweqs)) {
            /* Remove previous layout element */
            neweqs = TlistInit(&local,neweqs);
          }
        }
        Tadd2Arena(ar,neweqs);
        TdestroyArena(&local);
        return neweqs;
      }
    }
    neweqs = TlistAppend(&local,neweqs,eq2);
    eqs = t_list_next(eqs);
  }
  Tadd2Arena(ar,neweqs);
  TdestroyArena(&local);
  return neweqs;
}
  
/* The function {\tt get_equations_for_func} traverse a list
   of modules and looks for all equations with the given
   context-free function as outermost function symbol in the
   left-hand side. */
aterm_list *get_equations_for_func(arena *ar,aterm *func,aterm_list *mods)
{
  aterm *mod,*amod, *eq, *lhs, *ofs;
  aterm_list *eqs, *neweqs;
  aterm_list *equations = t_empty(NULL);
  arena local;

  TinitArena(t_world(*ar), &local);
  while(!t_is_empty(mods)) {
    mod = t_list_first(mods);
    amod = TdictGet(modules_db,mod);
    eqs = asfix_get_module_eqs(amod);
    eqs = asfix_filter_layout(&local,eqs);
    while(!t_is_empty(eqs)) {
      eq = t_list_first(eqs);
      lhs = asfix_get_equ_lhs(eq);
      ofs = asfix_get_appl_prod(lhs);
      if(equal_prod(func,ofs)) {
/* This equation should also be removed from the list of equations
   of the given module. */
        neweqs = asfix_get_module_eqs(amod);
        neweqs = remove_equation(&local,eq,neweqs);
        amod = asfix_put_module_eqs(&local, amod, neweqs);
        if(!t_is_empty(equations))
          equations = TlistAppend(&local, equations, TmakeSimple(&local, "w(\"\\n\")"));
        equations = TlistAppend(&local, equations, eq);
      }
      eqs = t_list_next(eqs);
    }
    change_modules_db(TdictPut(&local,modules_db,mod,amod));
    mods = t_list_next(mods);
  };
  Tadd2Arena(ar,equations);
  TdestroyArena(&local);
  return equations;
}

aterm *remove_func_from_funcs(arena *ar,aterm *func, aterm *funcs)
{
  Tbool found;
  aterm *func2;
  arena local;
  aterm_list *newfuncs = t_empty(NULL);

  TinitArena(t_world(*ar), &local);
  
  found = Tfalse;
  while(!found && !t_is_empty(funcs)) {
    func2 = t_list_first(funcs);
    if(AFnotLayout(func2)) {
      if(equal_prod(func,func2)) {
        found = Ttrue;
        funcs = t_list_next(funcs);
        if(!t_is_empty(funcs)) {
          funcs = t_list_next(funcs); /* Skip the next layout */
          newfuncs = TlistConcat(&local,newfuncs,funcs);
        }
        else { /* The last element of the list was removed */
          if(!t_is_empty(newfuncs))
            newfuncs = TlistInit(&local,newfuncs);
        }
        Tadd2Arena(ar,newfuncs);
        TdestroyArena(&local);
        return newfuncs;
      }
    }
    newfuncs = TlistAppend(&local,newfuncs,func2);
    funcs = t_list_next(funcs);
  }
  Tadd2Arena(ar,newfuncs);
  TdestroyArena(&local);
  return newfuncs;
}

aterm *remove_func_from_subsections(arena *ar,aterm *func, aterm *subsections)
{
  aterm *subsection,*newsubsection;
  aterm_list *cffuncs, *newcffuncs;
  aterm_list *lexfuncs, *newlexfuncs;
  aterm *t[2];
  arena local;
  aterm_list *newsubsections = t_empty(NULL);

  TinitArena(t_world(*ar), &local);
  
  while(!t_is_empty(subsections)) {
    subsection = t_list_first(subsections);
    if(TmatchTerm(subsection, pattern_asfix_contextfreesyntax,
                  &t[0], &t[1], &cffuncs)) {
      newcffuncs = remove_func_from_funcs(&local,func,cffuncs);
      if(!t_is_empty(newcffuncs)) {
        newsubsection = TmakeTerm(&local, pattern_asfix_contextfreesyntax,
                                  t[0], t[1], newcffuncs);
        newsubsections = TlistAppend(&local,newsubsections,newsubsection);
      }
      else {
        subsections = t_list_next(subsections);
        if(!t_is_empty(subsections)) {
          subsection = t_list_first(subsections);
        } 
        else {
          if(!t_is_empty(newsubsections)) {
            newsubsections = TlistInit(&local,newsubsections);
          }
        }
      }
    }
    else if(TmatchTerm(subsection, pattern_asfix_lexicalsyntax,
                  &t[0], &t[1], &lexfuncs)) {
      newlexfuncs = remove_func_from_funcs(&local,func,lexfuncs);
      if(!t_is_empty(newlexfuncs)) {
        newsubsection = TmakeTerm(&local, pattern_asfix_lexicalsyntax,
                                  t[0], t[1], newlexfuncs);
        newsubsections = TlistAppend(&local,newsubsections,newsubsection);
      }
      else {
        subsections = t_list_next(subsections);
        if(!t_is_empty(subsections)) {
          subsection = t_list_first(subsections);
        }
        else {
          if(!t_is_empty(newsubsections)) {
            newsubsections = TlistInit(&local,newsubsections);
          }
        }
      }
    }
    else 
      newsubsections = TlistAppend(&local,newsubsections,subsection);
    if(!t_is_empty(subsections)) 
      subsections = t_list_next(subsections);
  }
  Tadd2Arena(ar,newsubsections);
  TdestroyArena(&local);
  return newsubsections;
}

aterm *remove_func_from_sections(arena *ar,aterm *func, aterm *sections)
{
  aterm *section,*newsection;
  aterm_list *subsections, *newsubsections;
  aterm *t[2];
  arena local;
  aterm_list *newsections = t_empty(NULL);

  TinitArena(t_world(*ar), &local);
  
  while(!t_is_empty(sections)) {
    section = t_list_first(sections);
    if(TmatchTerm(section, pattern_asfix_exports,
              &t[0], &t[1], &subsections)) {
      newsubsections =
         remove_func_from_subsections(&local,func,subsections);
/*Tprintf(stderr,"remove_func_from_sections: %t\n",func);*/
      if(!t_is_empty(newsubsections)) {
        newsection = TmakeTerm(&local, pattern_asfix_exports,
                           t[0], t[1], newsubsections);
        newsections = TlistAppend(&local,newsections,newsection);
      }
      else {
        sections = t_list_next(sections);
        if(!t_is_empty(sections)) {
          section = t_list_first(sections);
        } 
        else {
          if(!t_is_empty(newsections)) { /* Remove the last added layout */
            newsections = TlistInit(&local,newsections);
          }
        }
      }
    }
    else if(TmatchTerm(section, pattern_asfix_hiddens,
                       &t[0], &t[1], &subsections)) {
      newsubsections = 
        remove_func_from_subsections(&local,func,subsections);
      if(!t_is_empty(newsubsections)) {
        newsection = TmakeTerm(&local, pattern_asfix_hiddens,
                               t[0], t[1], newsubsections);
        newsections = TlistAppend(&local,newsections,newsection);
      }
      else {
        sections = t_list_next(sections);
        if(!t_is_empty(sections)) {
          section = t_list_first(sections);
        } 
        else {
          if(!t_is_empty(newsections)) {
            newsections = TlistInit(&local,newsections);
          }
        }
      }
    }
    else 
      newsections = TlistAppend(&local,newsections,section);
    if(!t_is_empty(sections))
      sections = t_list_next(sections);
  }
  Tadd2Arena(ar,newsections);
  TdestroyArena(&local);
  return newsections;
}

aterm *remove_func_from_module(arena *ar,aterm *func, aterm *amod)
{
  aterm *result;
  aterm_list *sections, *newsections;
  arena local;

  TinitArena(t_world(*ar), &local);
  
  sections = AFgetModuleSections(amod);
  newsections = remove_func_from_sections(&local,func,sections);
  result = AFputModuleSections(&local,amod,newsections);
  Tadd2Arena(ar,result);
  TdestroyArena(&local);
  return result;
}

aterm *unique_new_name(arena *ar,aterm *name)
{
  char *text, *newtext;
  aterm *newname;
  int n = 1;

  assertp(TmatchTerm(name,pattern_asfix_id,&text));
  newtext = malloc(strlen(text)+16);
  sprintf(newtext,"AUX-%s%d",text,n);
  newname = TmakeTerm(ar,pattern_asfix_id,newtext);
  while(TdictGet(modules_db,newname)) {
    n++;
    sprintf(newtext,"AUX-%s%d",text,n);
    newname = TmakeTerm(ar,pattern_asfix_id,newtext);
  }
  free(newtext);
  return newname;
}

void reshuffle_per_sort(arena *ar,aterm *mod,aterm_list *orgmods)
{
  arena local;

  aterm *prod, *amod, *oldamod, *sort, *newsection, *newsubsection;
  aterm_list *sorts, *mods, *funcs, *sections, *eqs, *neweqs;

  TinitArena(t_world(*ar), &local);

Tprintf(stderr,"Reshuffling module per sort: %t\n",mod);
  amod = TdictGet(modules_db,mod);
  sorts = AFgetModuleSorts(&local, amod);
  sorts = asfix_filter_layout(&local,sorts);
  while(!t_is_empty(sorts)) {
    sort = t_list_first(sorts);
Tprintf(stderr,"Reshuffling sort: %t\n",sort);
    mods = TlistDeleteAll(&local,orgmods,mod);
    funcs = get_lex_funcs_for_sort(&local,sort,mods);
    if(!t_is_empty(funcs)) {
      newsubsection = AFinitLexicalSyntaxSection(&local);
      newsubsection = AFputSectionArgs(&local,newsubsection,funcs);
      newsection = AFinitExportSection(&local);
      newsection = AFputSectionArgs(&local,newsection,
                                    TmkList_n(&local,1,newsubsection));
      oldamod = TdictGet(modules_db,mod);
      sections = AFgetModuleSections(oldamod);
      sections = TlistConcat(&local,sections,
                             TmkList_n(&local,2,
                                       pattern_asfix_nlws,
                                       newsection));
      amod = AFputModuleSections(&local,amod,sections);
      change_modules_db(TdictPut(&local,modules_db,mod,amod));
    }
    prod = make_caller_prod(&local,sort);
    neweqs = get_equations_for_func(&local,prod,mods);
    if(!t_is_empty(neweqs)) {
      oldamod = TdictGet(modules_db,mod);
      eqs = AFgetModuleEqs(oldamod);
      eqs = TlistConcat(&local,
                        TlistAppend(&local,eqs,pattern_asfix_nlws),
                        neweqs);
      amod = AFputModuleEqs(&local,amod,eqs);
      change_modules_db(TdictPut(&local,modules_db,mod,amod));
    }
    sorts = t_list_next(sorts);
  }
}

aterm_list *reshuffle_modules(arena *ar,aterm_list *mods)
{
  arena local;

  aterm *mod, *newmod, *oldamod, *newamod, *cffunc, *amod;
  aterm_list *orgmods, *cffuncs, *eqs;
  aterm *newsubsection,*newsection;
  aterm *result;
  aterm_list *newmods = t_empty(NULL);

  TinitArena(t_world(*ar), &local);

  orgmods = mods;
  while(!t_is_empty(mods)) {
    mod = t_list_first(mods);
    reshuffle_per_sort(&local,mod,orgmods);
Tprintf(stderr,"reshuffle_per_sort finished\n");
    oldamod = TdictGet(modules_db,mod);
    cffuncs = AFgetModuleCFfuncs(&local, oldamod);
    cffuncs = asfix_filter_layout(&local,cffuncs);
    while(!t_is_empty(cffuncs)) {
      cffunc = t_list_first(cffuncs);
      eqs = get_equations_for_func(&local,cffunc,orgmods);
      if(!t_is_empty(eqs)) {
        oldamod = TdictGet(modules_db,mod);
        amod = remove_func_from_module(&local,cffunc,oldamod);
        change_modules_db(TdictPut(&local,modules_db,mod,amod));
        newamod = AFinitModule(&local);
        newmod = unique_new_name(&local,mod);
Tprintf(stderr,"Creating new module: %t\n",newmod);
        newamod = AFputModuleName(&local,newamod,newmod);
        newamod = AFputModuleEqs(&local,newamod,eqs);
        newsubsection = AFinitContextFreeSyntaxSection(&local);
        newsubsection = AFputSectionArgs(&local,newsubsection,
                                         TmkList_n(&local,1,cffunc));
        newsection = AFinitExportSection(&local);
        newsection = AFputSectionArgs(&local,newsection,
                                         TmkList_n(&local,1,newsubsection));
        newamod = AFputModuleSections(&local,newamod,
                                      TmkList_n(&local,1,newsection));
        change_modules_db(TdictPut(&local,modules_db,newmod,newamod));
        newmods = TlistAppend(&local,newmods,newmod);
      }
      cffuncs = t_list_next(cffuncs);
    }
    mods = t_list_next(mods);
  };
  mods = orgmods;
  while(!t_is_empty(mods)) {
    mod = t_list_first(mods);
    newamod = TdictGet(modules_db,mod);
    newmod = unique_new_name(&local,mod);
Tprintf(stderr,"Creating new module: %t\n",newmod);
    newamod = AFputModuleName(&local,newamod,newmod);
    change_modules_db(TdictPut(&local,modules_db,newmod,newamod));
    newmods = TlistAppend(&local,newmods,newmod);
    mods = t_list_next(mods);
  };
  result = TlistConcat(&local,orgmods,newmods);
  Tadd2Arena(ar,result);
  TdestroyArena(&local);
  return result;
}

void compile_module(int cid,arena *ar,aterm_list *newmods)
{
  char *text, *fname;
  aterm *mod, *amod, *expmod, *reduct, *cmod;
  aterm *aname, *idname, *file, *modname, *trm;
  int len;
  FILE *output, *input;
  arena local, rewrite_arena;
  aterm *oldmod;
  Tbool write;

/*
  char *path = "/home/markvdb/AsFix2C/muASF/asfixfiles/";
  char *path = "/home/markvdb/AsFix2C/muASF/asfixfiles3/";
  char *path = "/home/markvdb/NEW-META/new-meta/pgen/cfiles/";
*/
  char *path = "/home/markvdb/AsFix2C/muASF/asfixfiles5/";

  TinitArena(NULL, &local);

Tprintf(stderr,"compile_module entered\n");
  if(!t_is_empty(newmods)) {
    do {
      mod = t_list_first(newmods);
      amod = TdictGet(modules_db,mod);
      assertp(TmatchTerm(mod,pattern_asfix_id,&text));
      newmods = t_list_next(newmods);
    } while (strncmp(text,"AUX-",4) != 0);
    if(strncmp(text,"AUX-",4) == 0) {
      len = strlen(path) + strlen(text) + strlen(".asfix");
      fname = malloc(len + 1);
      if(!fname) {
        fprintf(stderr,"Not enough memory\n");
        exit(1);
      }
      fname = strcpy(fname,path);
      fname = strcat(fname,text);
      fname = strcat(fname,".asfix");
/* Check whether it is necessary to generate new C code. */
      input = fopen(fname,"r");
      if(input) {
        TreadTermFile(input,&local,&oldmod);
        write = !t_equal(oldmod,amod);
      }
      else 
        write = Ttrue;
      if (write) {
        output = fopen(fname,"w");
        if(!output) 
          Tprintf(stderr,"Cannot open file %s\n",fname);
        else {
/*
          cmod = AFcollapseModule(&local,amod);
          Tprintf(output,"%t",cmod); 
*/
          Tprintf(output,"%t",amod);

          Tprintf(output, "\n");
          fclose(output);
        }
        Tprintf(stderr,"Writing: %s.asfix\n", text);

        expmod = expand_to_asfix(&local,amod,fname);

Tprintf(stderr,"Reducing ...\n");

        assertp(TmatchTerm(expmod, pattern_asfix_term, NULL, NULL,
                &file, NULL, &modname, NULL, &trm, NULL, NULL));
       
        TinitArena(w, &rewrite_arena);
        reduct = innermost(&rewrite_arena, trm);
	Tadd2Arena(&local, reduct);
	TdestroyArena(&rewrite_arena);

Tprintf(stderr,"Reducing finished.\n");

        aname  = Tmake(&local,"l(<str>)",fname);
        idname = TmakeSimple(&local,"id(\"AsFix2C\")");
        cmod = toasfix(&local, reduct, aname, idname);
Tprintf(stderr,"toasfix finished.\n");
        free(fname);
        len = strlen(path) + strlen(text) + strlen(".c");
        fname = malloc(len + 1);
        if(!fname) {
          fprintf(stderr,"Not enough memory\n");
          exit(1);
        }
        fname = strcpy(fname,path);
        fname = strcat(fname,text);
        fname = strcat(fname,".c");
        output = fopen(fname,"w");
        free(fname);
        if(!output) 
          Tprintf(stderr,"Cannot open file %s\n", fname);
        else {
          ToC_code(cmod,output);
Tprintf(stderr,"ToC_code finished.\n");
          Tprintf(output, "\n");
          fclose(output);
        }
        Tprintf(stderr,"Writing: %s.c\n", text);
        Tprintf(stderr,"Number of block allocated in rewrite world: %d\n", w->block_count);
        Tprintf(stderr,"Number of block allocated in other world: %d\n", the_world->block_count);

      }
      else
        free(fname);
      TdestroyArena(&local);
      TBsend(cid,Tmake(TBgetArena(cid),
                       "snd-event(compile(<term>,<list>))",
                       mod,newmods));
    }
  }
  else {
    TdestroyArena(&local);
    TBsend(cid,Tmake(TBgetArena(cid),"snd-event(done)"));
/*
    TpruneDeathRow();
    TprintAllTerms(stdout);
*/
  }
}

void compile_modules(int cid,aterm_list *mods)
{
  aterm_list *newmods;
  arena local;
/*  struct tms start, compiling;
  clock_t user, system;*/

  TinitArena(t_world(mods), &local);

  Tprintf(stderr,"Reshuffling ... %t\n",mods);
/*  times(&start);*/
  newmods = reshuffle_modules(&local,mods);
  Tprintf(stderr,"Compiling ... %t\n",newmods);
  compile_module(cid,&local,newmods);
  TdestroyArena(&local);
/*  times(&compiling);

  user = compiling.tms_utime - start.tms_utime;
  system = compiling.tms_stime - start.tms_stime;
  fprintf(stderr, "compilation: %f user, %f system\n", 
	 TICK2SEC(user), TICK2SEC(system));*/
  /* return result;*/
}

void rec_ack_event(int cid,aterm *cterm)
{
  aterm *mod;
  aterm_list *newmods;
  arena local;

  if(Tmatch(cterm,"compile(<term>,<list>)",&mod,&newmods)) {
    TinitArena(t_world(cterm), &local);
    compile_module(cid,&local,newmods);
    TdestroyArena(&local);
  }
  else if(Tmatch(cterm,"done")) {
    Tprintf(stderr,"Compilation completed\n");
  }
  else
    exit(1);
}

void create_module_db(int cid)
{
  change_modules_db(t_empty(NULL));
}

void clear_module_db(int cid)
{
  change_modules_db(t_empty(NULL));
}

aterm_list *add_module(int cid, aterm *asfix)
{
  aterm *t[7]; 
  aterm *modname,*pair;
  aterm_list *sections;
  aterm *newasfix;
  aterm *result;
  arena local;

  TinitArena(t_world(asfix), &local);

  if(TmatchTerm(asfix,pattern_asfix_module,
     &t[0], &t[1], &modname, &t[2], &sections, &t[3], &t[4], &t[5], &t[6])) {
    if(TdictGet(modules_db,modname) == Tfalse) {
      newasfix = AFexpandModule(&local, asfix);
      pair = Tmake(&local, "[<term>,<term>]",modname,newasfix);
      change_modules_db(TlistAppend(&local,modules_db,pair));
    };
    result = Tmake(TBgetArena(cid), "snd-value(ok(<term>))", modname);
    TdestroyArena(&local);
    return result;
  } else {
    TdestroyArena(&local);
    Tprintf(stderr, "not an asfix term: %t\n", asfix);
    exit(1);
  }
}

aterm *delete_module(int cid, aterm *name)
{
  aterm *result;
  arena local;

  TinitArena(t_world(name), &local);

  change_modules_db(TdictRemove(&local, modules_db,name));
  result = Tmake(TBgetArena(cid), "snd-value(deleted(<term>))",name);
  TdestroyArena(&local);
  return result;
}

int main(int argc, char **argv)
{
  int cid;

  TBinit(argc, argv);
  AFinit(NULL);
  w = TcreateWorld(4096, 1024, 1048573, 0);

  cid = TBnewConnection(NULL, NULL, NULL, -1, 
			 compiler_handler, compiler_check_in_sign);
  TBconnect(cid);
  init_expansion_terms();
  init_asfix_patterns();
  init_patterns(TBgetArena(cid));

  c_rehash(INITIAL_TABLE_SIZE);
  register_all();
  resolve_all();

  TBeventloop();

  return 0;
}
