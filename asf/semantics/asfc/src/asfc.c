/* A first version of the MODULE-MANAGER (or better TREE-MANAGER) in ToolBus C. 
   This program is written by Mark van den Brand and
   improved by Tobias Kuipers.

   The following functions are available:
   void rec_terminate(aterm *t)
   aterm *exists(aterm *name)
   aterm *get_section(aterm *name,aterm *module)
   void create_module_db()
   aterm_list *clear_module_db(aterm_list *db)
   aterm_list *add_module(term *asfix)
   void delete_module(aterm *name)
*/

#include <tb-tool.h>
#include <string.h>
#include <asfix.h>
#include <term-list.h>
#include <abbrevs.h>
#include <sys/times.h>
#include <limits.h>
#include "compiler.tif.c"

#define TICK2SEC(t)		(((double)(t))/CLK_TCK)

aterm *expand_to_asfix(arena *ar,aterm *mod,char *name);
int print_source(FILE *f, aterm *term);
void pp_rnx(FILE *f, aterm *t, int indent);
aterm *asfix2rnx(arena *ar,aterm *asfix);
void init_expansion_terms();

aterm_list *modules_db;

FATAL_ERROR

void change_modules_db(aterm *new_db)
{
  /*aterm *tmp = modules_db;
  modules_db = new_db;
  if(modules_db)
    Tprotect(modules_db);
  if(tmp)
    Tunprotect(tmp);*/
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

  if(Tmatch(term1,"sort(<str>)",&text1) &&
     Tmatch(term2,"sort(<str>)",&text2))
    return t_equal(term1,term2);
  else if(Tmatch(term1,"l(<str>)",&text1) &&
          Tmatch(term2,"l(<str>)",&text2))
    return t_equal(term1,term2);
  else if(Tmatch(term1,"ql(<str>)",&text1) &&
          Tmatch(term2,"ql(<str>)",&text2))
    return t_equal(term1,term2);
  else if(Tmatch(term1,"iter(<term>,<term>,<term>)",
                 &t1[0],&t1[1],&t1[2]) &&
          Tmatch(term2,"iter(<term>,<term>,<term>)",
                 &t2[0],&t2[1],&t2[2]))
    return equal_term(t1[0],t2[0]) &&
           equal_term(t1[2],t2[2]);
  else if(Tmatch(term1,"iter-sep(<term>,<term>,<term>,<term>,<term>,<term>," \
                                "<term>,<term>,<term>)",
                 &t1[0],&t1[1],&t1[2],&t1[3],&t1[4],
                 &t1[5],&t1[6],&t1[7],&t1[8]) &&
          Tmatch(term2,"iter-sep(<term>,<term>,<term>,<term>,<term>,<term>," \
                                "<term>,<term>,<term>)",
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
  return equal;
}

int equal_attrs(aterm *attrs1,aterm *attrs2)
{
  aterm *w1[2],*w2[2];
  aterm_list *args1,*args2;

  if(Tmatch(attrs1,"no-attrs") && Tmatch(attrs2,"no-attrs")) 
    return Ttrue;
  else if(!Tmatch(attrs1,"no-attrs") && !Tmatch(attrs2,"no-attrs")) {
    if(Tmatch(attrs1,
              "attrs(l(\"{\"),<term>,<list>,<term>,l(\"}\"))",
              &w1[0],&args1,&w1[1])) {
      if(Tmatch(attrs2,
                "attrs(l(\"{\"),<term>,<list>,<term>,l(\"}\"))",
                &w2[0],&args2,&w2[1]))
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

  if(Tmatch(prod1,
     "prod(<term>,<term>,<list>,<term>,<term>,<term>,<term>,<term>,<term>)",
     &mname1,&w1[0],&args1,&w1[1],&lit1,&w1[2],&sort1,&w1[3],&attrs1)) {
    if(Tmatch(prod2,
       "prod(<term>,<term>,<list>,<term>,<term>,<term>,<term>,<term>,<term>)",
       &mname2,&w2[0],&args2,&w2[1],&lit2,&w2[2],&sort2,&w2[3],&attrs2)) {
      if(t_equal(mname1,mname2) && equal_args(args1,args2) &&
         t_equal(sort1,sort2) && equal_attrs(attrs1,attrs2)) 
        return Ttrue;
    }
  }
  return Tfalse;
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
  
/* The function {\tt get_equations_for_cffunc} traverse a list
   of modules and looks for all equations with the given
   context-free function as outermost function symbol in the
   left-hand side. */
aterm_list *get_equations_for_cffunc(arena *ar,aterm *cffunc, aterm_list *mods)
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
      if(equal_prod(cffunc,ofs)) {
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

aterm *remove_cffunc_from_cffuncs(arena *ar,aterm *cffunc, aterm *cffuncs)
{
  Tbool found;
  aterm *cffunc2;
  arena local;
  aterm_list *newcffuncs = t_empty(NULL);

  TinitArena(t_world(*ar), &local);
  
  found = Tfalse;
  while(!found && !t_is_empty(cffuncs)) {
    cffunc2 = t_list_first(cffuncs);
    if(AFnotLayout(cffunc2)) {
      if(equal_prod(cffunc,cffunc2)) {
        found = Ttrue;
        cffuncs = t_list_next(cffuncs);
        if(!t_is_empty(cffuncs)) {
          cffuncs = t_list_next(cffuncs); /* Skip the next layout */
          newcffuncs = TlistConcat(&local,newcffuncs,cffuncs);
        }
        else { /* The last element of the list was removed */
          if(!t_is_empty(newcffuncs))
            newcffuncs = TlistInit(&local,newcffuncs);
        }
        Tadd2Arena(ar,newcffuncs);
        TdestroyArena(&local);
        return newcffuncs;
      }
    }
    newcffuncs = TlistAppend(&local,newcffuncs,cffunc2);
    cffuncs = t_list_next(cffuncs);
  }
  Tadd2Arena(ar,newcffuncs);
  TdestroyArena(&local);
  return newcffuncs;
}

aterm *remove_cffunc_from_subsections(arena *ar,aterm *cffunc, aterm *subsections)
{
  aterm *subsection,*newsubsection;
  aterm_list *cffuncs, *newcffuncs;
  aterm *t[2];
  arena local;
  aterm_list *newsubsections = t_empty(NULL);

  TinitArena(t_world(*ar), &local);
  
  while(!t_is_empty(subsections)) {
    subsection = t_list_first(subsections);
    if(Tmatch(subsection, "context-free-syntax(<term>,<term>,<list>)",
              &t[0], &t[1], &cffuncs)) {
      newcffuncs = remove_cffunc_from_cffuncs(&local,cffunc,cffuncs);
      if(!t_is_empty(newcffuncs)) {
        newsubsection = Tmake(&local,"context-free-syntax(<term>,<term>,<list>)",
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
    else 
      newsubsections = TlistAppend(&local,newsubsections,subsection);
    if(!t_is_empty(subsections)) 
      subsections = t_list_next(subsections);
  }
  Tadd2Arena(ar,newsubsections);
  TdestroyArena(&local);
  return newsubsections;
}

aterm *remove_cffunc_from_sections(arena *ar,aterm *cffunc, aterm *sections)
{
  aterm *section,*newsection;
  aterm_list *subsections, *newsubsections;
  aterm *t[2];
  arena local;
  aterm_list *newsections = t_empty(NULL);

  TinitArena(t_world(*ar), &local);
  
  while(!t_is_empty(sections)) {
    section = t_list_first(sections);
    if(Tmatch(section, "exports(<term>,<term>,<list>)",
              &t[0], &t[1], &subsections)) {
      newsubsections =
         remove_cffunc_from_subsections(&local,cffunc,subsections);
/*Tprintf(stderr,"remove_cffunc_from_sections: %t\n",cffunc);*/
      if(!t_is_empty(newsubsections)) {
        newsection = Tmake(&local,"exports(<term>,<term>,<list>)",
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
    else if(Tmatch(section, "hiddens(<term>,<term>,<list>)",
                   &t[0], &t[1], &subsections)) {
      newsubsections = 
        remove_cffunc_from_subsections(&local,cffunc,subsections);
      if(!t_is_empty(newsubsections)) {
        newsection = Tmake(&local,"hiddens(<term>,<term>,<list>)",
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

aterm *remove_cffunc_from_module(arena *ar,aterm *cffunc, aterm *amod)
{
  aterm *result;
  aterm_list *sections, *newsections;
  arena local;

  TinitArena(t_world(*ar), &local);
  
  sections = AFgetModuleSections(amod);
  newsections = remove_cffunc_from_sections(&local,cffunc,sections);
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

  assertp(Tmatch(name,"id(<str>)",&text));
  newtext = malloc(strlen(text)+6);
  sprintf(newtext,"%s%d",text,n);
  newname = Tmake(ar,"id(<str>)",newtext);
  while(TdictGet(modules_db,newname)) {
    n++;
    sprintf(newtext,"%s%d",text,n);
    newname = Tmake(ar,"id(<str>)",newtext);
  }
  free(newtext);
  return newname;
}

aterm_list *reshuffle_modules(arena *ar,aterm_list *mods)
{
  arena local;

  aterm *mod, *newmod, *oldamod, *amod, *newamod, *cffunc;
  aterm_list *orgmods, *cffuncs, *eqs;
  aterm *newsubsection,*newsection;
  aterm *result;
  aterm_list *newmods = t_empty(NULL);

  TinitArena(t_world(*ar), &local);

  orgmods = mods;
  while(!t_is_empty(mods)) {
    mod = t_list_first(mods);
Tprintf(stderr,"Reshuffling module: %t\n",mod);
    oldamod = TdictGet(modules_db,mod);
    cffuncs = AFgetModuleCFfuncs(&local, oldamod);
    cffuncs = asfix_filter_layout(&local,cffuncs);
    while(!t_is_empty(cffuncs)) {
      cffunc = t_list_first(cffuncs);
      eqs = get_equations_for_cffunc(&local,cffunc,orgmods);
      if(!t_is_empty(eqs)) {
        oldamod = TdictGet(modules_db,mod);
        amod = remove_cffunc_from_module(&local,cffunc,oldamod);
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
  result = TlistConcat(&local,orgmods,newmods);
  Tadd2Arena(ar,result);
  TdestroyArena(&local);
  return result;
}

aterm *compile_modules(int cid,aterm_list *mods)
{
  char *text;
  char *fname;
  aterm *mod, *amod, *expmod, *result, *rnx;
  aterm_list *newmods, *modlist;
  FILE *output;
  int len;
  arena local;
  struct tms start, compiling;
  clock_t user, system;

  TinitArena(t_world(mods), &local);

  Tprintf(stderr,"Compiling ... %t\n",mods);
  times(&start);
  newmods = reshuffle_modules(&local,mods);
  modlist = newmods;
  Tprotect(modlist);
  while(!t_is_empty(newmods)) {
    mod = t_list_first(newmods);
    amod = TdictGet(modules_db,mod);
    assertp(Tmatch(mod,"id(<str>)",&text));
    len = strlen("/home/markvdb/NEW-META/new-meta/pico/") + 
    /* len = strlen("/home/markvdb/AsFix2EP/muASF2/asfixfiles/reshuffle/") + */
          strlen(text) + strlen(".rnx");
    fname = malloc(len + 1);
    if(!fname) {
      fprintf(stderr,"Not enough memory\n");
      exit(1);
    }
    fname = strcpy(fname,"/home/markvdb/NEW-META/new-meta/pico/");
    /* fname = strcpy(fname,"/home/markvdb/AsFix2EP/muASF2/asfixfiles/reshuffle/"); */
    fname = strcat(fname,text);
    fname = strcat(fname,".rnx");
    expmod = expand_to_asfix(&local,amod,fname);
    rnx = asfix2rnx(&local,expmod);
    output = fopen(fname,"w");
    free(fname);
    if(!output) 
      Tprintf(stderr,"Cannot open file\n");
    else {
      pp_rnx(output,rnx,0);
      Tprintf(output, "\n");
      /*Tprintf(output,"%t\n",expmod);*/
      fclose(output);
    }
    print_source(stderr,amod);
    newmods = t_list_next(newmods);
    TflushArena(&local);
  }
  result = Tmake(TBgetArena(cid), "snd-value(ok)");
  Tunprotect(modlist);
  TdestroyArena(&local);
  /*print_source(stderr,expmod);*/
  times(&compiling);

  user = compiling.tms_utime - start.tms_utime;
  system = compiling.tms_stime - start.tms_stime;
  fprintf(stderr, "compilation: %f user, %f system\n", 
	 TICK2SEC(user), TICK2SEC(system));
  return result;
}

void create_module_db(int cid)
{
  change_modules_db(t_empty(NULL));
}

void clear_module_db(int cid)
{
  change_modules_db(t_empty(NULL));
}

aterm *get_import_section(aterm_list *sections);

aterm_list *add_module(int cid, aterm *asfix)
{
  aterm *t[7]; 
  aterm *modname,*pair;
  aterm_list *sections;
  aterm *newasfix;
  aterm *result;
  arena local;

  TinitArena(t_world(asfix), &local);

  if(Tmatch(asfix,
     "module(<term>,<term>,<term>,<term>,<list>,<term>,<term>,<term>,<term>)",
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
  cid = TBnewConnection(NULL, NULL, NULL, -1, 
			 compiler_handler, compiler_check_in_sign);
  TBconnect(cid);
  init_expansion_terms();
  TBeventloop();

  return 0;
}
