#include <tb-tool.h>
#include <string.h>
#include <asfix.h>
#include <term-list.h>
#include <abbrevs.h>

int print_asfix_literal(FILE *f, aterm *lit)
{
  char *text;

  Tmatch(lit,"l(<str>)",&text);
  Tprintf(f,"%s",text);
  return 0;
}

int print_asfix_ws(FILE *f, aterm *ws)
{
  char *text;

  Tmatch(ws,"w(<str>)",&text);
  Tprintf(f,"%s",text);
  return 0;
}

int print_asfix_sort(FILE *f, aterm *sort)
{
  char *text;

  Tmatch(sort,"sort(<str>)",&text);
  Tprintf(f,"%s",text);
  return 0;
}

int print_asfix_id(FILE *f, aterm *id)
{
  char *text;

  Tmatch(id,"id(<str>)",&text);
  Tprintf(f,"%s",text);
  return 0;
}

int print_asfix_args(FILE *f, aterm_list *args);
int print_asfix_list(FILE *f, aterm_list *args);

int print_asfix_term(FILE *f, aterm *arg)
{
  char *text;
  aterm *t[2], *w[4], *l[3];
  aterm_list *args;

  if(Tmatch(arg,"l(<str>)",&text)) 
    Tprintf(f,"%s",text);
  else if(Tmatch(arg,"ql(<str>)",&text)) 
    Tprintf(f,"\"%s\"",text);
  else if(Tmatch(arg,"sort(<str>)",&text))
    Tprintf(f,"%s",text);
  else if(Tmatch(arg,"id(<str>)",&text)) 
    Tprintf(f,"%s",text);
  else if(Tmatch(arg,"char-class(<str>)",&text))
    Tprintf(f,"%s",text);
  else if(Tmatch(arg,"appl(<term>,<term>,<list>)",
                 NULL,NULL,&args))
    print_asfix_args(f,args);
  else if(Tmatch(arg,"iter(<term>,<term>,<term>)",
                 &t[0],&w[0],&l[0])) {
    print_asfix_term(f,t[0]);
    print_asfix_ws(f,w[0]);
    print_asfix_literal(f,l[0]);
  }
  else if(Tmatch(arg,"iter-sep(<term>,<term>,<term>,<term>,<term>,<term>," \
                               "<term>,<term>,<term>)",
                 &l[0],&w[0],&t[0],&w[1],&t[1],&w[2],&l[1],&w[3],&l[2])) {
    print_asfix_literal(f,l[0]);
    print_asfix_ws(f,w[0]);
    print_asfix_term(f,t[0]);
    print_asfix_ws(f,w[1]);
    print_asfix_term(f,t[1]);
    print_asfix_ws(f,w[2]);
    print_asfix_literal(f,l[1]);
    print_asfix_ws(f,w[3]);
    print_asfix_literal(f,l[2]);
  }
  else if(Tmatch(arg,"neg(<term>,<term>,<term>)",
                 &t[0],&w[0],&t[1])) {
    print_asfix_term(f,t[0]);
    print_asfix_ws(f,w[0]);
    print_asfix_term(f,t[1]);
  }
  else if(Tmatch(arg,"var(<str>,<term>)",&text,NULL))
    Tprintf(f,"%s",text);
  else if(Tmatch(arg,"lex(<str>,<term>)",&text,NULL))
    Tprintf(f,"%s",text);
  else if(Tmatch(arg,"list(<term>,<term>,<list>)",
                 NULL,NULL,&args))
    print_asfix_list(f,args);
  return 0;
}

int print_asfix_cond(FILE *f, aterm *cond)
{
  aterm *t[2], *w[2], *lit;

  assertp(Tmatch(cond,"condition(<term>,<term>,<term>,<term>,<term>)",
            &t[0],&w[0],&lit,&w[1],&t[1]));
  print_asfix_term(f,t[0]);
  print_asfix_ws(f,w[0]);
  print_asfix_literal(f,lit);
  print_asfix_ws(f,w[1]);
  print_asfix_term(f,t[1]);
  return 0;
}

int print_asfix_conds(FILE *f, aterm_list *conds)
{
  char *text;
  aterm *cond;

  while(!t_is_empty(conds)) {
    cond = t_list_first(conds);
    if(AFisLayout(cond))
      print_asfix_ws(f,cond);
    else if(Tmatch(cond,"sep(<str>)",
                   &text))
      Tprintf(f,"%s",text);
    else
      print_asfix_cond(f,cond);
    conds = t_list_next(conds);
  }
  return 0;
}

int print_asfix_list(FILE *f, aterm_list *elems)
{
  char *text;
  aterm *elem;

  while(!t_is_empty(elems)) {
    elem = t_list_first(elems);
    if(AFisLayout(elem))
      print_asfix_ws(f,elem);
    else if(Tmatch(elem,"sep(<str>)",
                   &text))
      Tprintf(f,"%s",text);
    else
      print_asfix_term(f,elem);
    elems = t_list_next(elems);
  }
  return 0;
}

int print_asfix_args(FILE *f, aterm_list *args)
{
  aterm *arg;

  while(!t_is_empty(args)) {
    arg = t_list_first(args);
    if(AFisLayout(arg))
      print_asfix_ws(f,arg);
    else
      print_asfix_term(f,arg);
    args = t_list_next(args);
  }
  return 0;
}

int print_asfix_attrs(FILE *f, aterm *attrs)
{
  aterm *l[2], *w[2];
  aterm_list *args;

  if(Tmatch(attrs,"attrs(<term>,<term>,<list>,<term>,<term>)",
                           &l[0],&w[0],&args,&w[1],&l[1])) {
    print_asfix_literal(f,l[0]);
    print_asfix_ws(f,w[0]);
    print_asfix_args(f,args);
    print_asfix_ws(f,w[1]);
    print_asfix_literal(f,l[1]);
  }
  return 0;
}

int print_asfix_prod(FILE *f, aterm *prod)
{
  aterm *w[3], *lit, *term, *attrs;
  aterm_list *args;

  assertp(Tmatch(prod,"prod(<term>,<term>,<list>,<term>," \
                       "<term>,<term>,<term>,<term>,<term>)",
            NULL,NULL,&args,&w[0],&lit,&w[1],&term,&w[2],&attrs));
  print_asfix_args(f,args);
  print_asfix_ws(f,w[0]);
  print_asfix_literal(f,lit);
  print_asfix_ws(f,w[1]);
  print_asfix_term(f,term);
  print_asfix_ws(f,w[2]);
  print_asfix_attrs(f,attrs);
  return 0;
}

int print_asfix_chainlist(FILE *f, aterm_list *elems);

int print_asfix_chainelem(FILE *f, aterm *elem)
{
  aterm_list *skel,*chainlist;
  aterm *w[4],*l[4];

  if(Tmatch(elem,"prod-skel(<list>,<term>,<term>)",&skel,&w[0],NULL)) {
    print_asfix_args(f,skel);
    print_asfix_ws(f,w[0]);
  }
  else if(Tmatch(elem,"agroup(<term>,<term>,<term>,<term>," \
                              "<term>,<term>,<list>,<term>,<term>)",
                 &l[0],&w[0],&l[1],&w[1],&l[2],&w[2],&chainlist,&w[3],&l[3])) {
    print_asfix_literal(f,l[0]);
    print_asfix_ws(f,w[0]);
    print_asfix_literal(f,l[1]);
    print_asfix_ws(f,w[1]);
    print_asfix_literal(f,l[2]);
    print_asfix_ws(f,w[2]);
    print_asfix_chainlist(f,chainlist);
    print_asfix_ws(f,w[3]);
    print_asfix_literal(f,l[3]);
  }
  else {
    assertp(Tmatch(elem,"group(<term>,<term>,<list>,<term>,<term>)",
                        &l[0],&w[0],&chainlist,&w[1],&l[1]));
    print_asfix_literal(f,l[0]);
    print_asfix_ws(f,w[0]);
    print_asfix_chainlist(f,chainlist);
    print_asfix_ws(f,w[1]);
    print_asfix_literal(f,l[1]);
  }
  return 0;
}

int print_asfix_chainlist(FILE *f, aterm_list *elems)
{
  char *text;
  aterm *elem;

  while(!t_is_empty(elems)) {
    elem = t_list_first(elems);
    if(AFisLayout(elem))
      print_asfix_ws(f,elem);
    else if(Tmatch(elem,"sep(<str>)",&text))
      Tprintf(f,"%s",text);
    else
      print_asfix_chainelem(f,elem);
    elems = t_list_next(elems);
  }
  return 0;
}

int print_asfix_prio(FILE *f, aterm *prio)
{
  aterm_list *chainlist;

  if(Tmatch(prio,"incr-chain(<list>)",&chainlist))
    print_asfix_chainlist(f,chainlist);
  else {
    assertp(Tmatch(prio,"decr-chain(<list>)",&chainlist));
    print_asfix_chainlist(f,chainlist);
  }
  return 0;
}

int print_asfix_sections(FILE *f, aterm_list *sections);

int print_asfix_modulenames(FILE *f, aterm_list *mnames)
{
  aterm *mname;

  while(!t_is_empty(mnames)) {
    mname = t_list_first(mnames);
    if(AFisLayout(mname))
      print_asfix_ws(f,mname);
    else
      print_asfix_id(f,mname);
    mnames = t_list_next(mnames);
  }
  return 0;
}

int print_asfix_sorts(FILE *f, aterm_list *sorts)
{
  aterm *sort;

  while(!t_is_empty(sorts)) {
    sort = t_list_first(sorts);
    if(AFisLayout(sort))
      print_asfix_ws(f,sort);
    else
      print_asfix_sort(f,sort);
    sorts = t_list_next(sorts);
  }
  return 0;
}

int print_asfix_prios(FILE *f, aterm_list *prios)
{
  char *text;
  aterm *prio;

  while(!t_is_empty(prios)) {
    prio = t_list_first(prios);
    if(AFisLayout(prio))
      print_asfix_ws(f,prio);
    else if(Tmatch(prio,"sep(<str>)",&text))
      Tprintf(f,"%s",text);
    else
      print_asfix_prio(f,prio);
    prios = t_list_next(prios);
  }
  return 0;
}

int print_asfix_prods(FILE *f, aterm_list *prods)
{
  aterm *prod;

  while(!t_is_empty(prods)) {
    prod = t_list_first(prods);
    if(AFisLayout(prod))
      print_asfix_ws(f,prod);
    else
      print_asfix_prod(f,prod);
    prods = t_list_next(prods);
  }
  return 0;
}

int print_asfix_section(FILE *f, aterm *section)
{
  aterm *lit, *w;
  aterm_list *subsections,*prios,*prods;

  if(Tmatch(section, "imports(<term>,<term>,<list>)",
            &lit,&w,&subsections)) {
    print_asfix_literal(f,lit);
    print_asfix_ws(f,w);
    print_asfix_modulenames(f,subsections);
  }
  else if(Tmatch(section, "exports(<term>,<term>,<list>)",
            &lit,&w,&subsections)) {
    print_asfix_literal(f,lit);
    print_asfix_ws(f,w);
    print_asfix_sections(f,subsections);
  }
  else if(Tmatch(section, "hiddens(<term>,<term>,<list>)",
            &lit,&w,&subsections)) {
    print_asfix_literal(f,lit);
    print_asfix_ws(f,w);
    print_asfix_sections(f,subsections);
  }
  else if(Tmatch(section, "sorts(<term>,<term>,<list>)",
            &lit,&w,&subsections)) {
    print_asfix_literal(f,lit);
    print_asfix_ws(f,w);
    print_asfix_sorts(f,subsections);
  }
  else if(Tmatch(section, "lexical-syntax(<term>,<term>,<list>)",
            &lit,&w,&subsections)) {
    print_asfix_literal(f,lit);
    print_asfix_ws(f,w);
    print_asfix_prods(f,subsections);
  }
  else if(Tmatch(section, "context-free-syntax(<term>,<term>,<list>)",
            &lit,&w,&subsections)) {
    print_asfix_literal(f,lit);
    print_asfix_ws(f,w);
    print_asfix_prods(f,subsections);
  }
  else if(Tmatch(section, "priorities(<term>,<term>,<list>)",
            &lit,&w,&prios)) {
    print_asfix_literal(f,lit);
    print_asfix_ws(f,w);
    print_asfix_prios(f,prios);
  }
  else if(Tmatch(section, "variables(<term>,<term>,<list>)",
            &lit,&w,&prods)) {
    print_asfix_literal(f,lit);
    print_asfix_ws(f,w);
    print_asfix_prods(f,prods);
  }
  return 0;
}

int print_asfix_sections(FILE *f, aterm_list *sections)
{
  aterm *section;

  while(!t_is_empty(sections)) {
    section = t_list_first(sections);
    if(AFisLayout(section))
      print_asfix_ws(f,section);
    else
      print_asfix_section(f,section);
    sections = t_list_next(sections);
  }
  return 0;
}

int print_asfix_equation(FILE *f, aterm *equation)
{
  aterm *l[3], *t[2], *w[5];
  aterm_list *conds;

  if(Tmatch(equation,"ceq-equ(<term>,<term>,<term>,<term>,<term>,<term>," \
                              "<term>,<term>,<term>)",
            NULL,NULL,&l[0],&w[0],&t[0],&w[1],&l[1],&w[2],&t[1])) {
    print_asfix_literal(f,l[0]);
    print_asfix_ws(f,w[0]);
    print_asfix_term(f,t[0]);
    print_asfix_ws(f,w[1]);
    print_asfix_literal(f,l[1]);
    print_asfix_ws(f,w[2]);
    print_asfix_term(f,t[1]);
  }
  else if(Tmatch(equation,"ceq-impl(<term>,<term>,<term>," \
                                    "<term>,<list>,<term>,<term>," \
                                    "<term>,<term>,<term>,<term>,<term>," \
                                    "<term>)",
                 NULL,NULL,&l[0],&w[0],&conds,
                 &w[1],&l[1],&w[2],&t[0],&w[3],&l[2],&w[4],&t[1])) {
    print_asfix_literal(f,l[0]);
    print_asfix_ws(f,w[0]);
    print_asfix_conds(f,conds);
    print_asfix_ws(f,w[1]);
    print_asfix_literal(f,l[1]);
    print_asfix_ws(f,w[2]);
    print_asfix_term(f,t[0]);
    print_asfix_ws(f,w[3]);
    print_asfix_literal(f,l[2]);
    print_asfix_ws(f,w[4]);
    print_asfix_term(f,t[1]);
  }
  else if(Tmatch(equation,"ceq-when(<term>,<term>,<term>,<term>," \
                                    "<term>,<term>,<term>,<term>,<term>,<term>," \
                                    "<term>,<term>,<list>)",
                 NULL,NULL,&l[0],&w[0],&t[0],&w[1],&l[1],&w[2],&t[1],
                 &w[3],&l[2],&w[4],&conds)) {
    print_asfix_literal(f,l[0]);
    print_asfix_ws(f,w[0]);
    print_asfix_term(f,t[0]);
    print_asfix_ws(f,w[1]);
    print_asfix_literal(f,l[1]);
    print_asfix_ws(f,w[2]);
    print_asfix_term(f,t[1]);
    print_asfix_ws(f,w[3]);
    print_asfix_literal(f,l[2]);
    print_asfix_ws(f,w[4]);
    print_asfix_conds(f,conds);
  }
  return 0;
}
int print_asfix_equations(FILE *f, aterm *equations)
{
  aterm *l, *w, *eq;
  aterm_list *eqs;

  if(Tmatch(equations,"equations(<term>,<term>,<list>)",
            &l,&w,&eqs)) {
    print_asfix_literal(f,l);
    print_asfix_ws(f,w);
    while(!t_is_empty(eqs)) {
      eq = t_list_first(eqs);
      if(AFisLayout(eq))
        print_asfix_ws(f,eq);
      else
        print_asfix_equation(f,eq);
      eqs = t_list_next(eqs);
    }
  }
  return 0;
}

int print_asfix_module(FILE *f, aterm *mod)
{
  aterm *lit, *w[3], *id, *equations;
  aterm_list *sections;

  assertp(Tmatch(mod,
                 "module(<term>,<term>,<term>,<term>,<list>," \
                         "<term>,<term>,<term>,<term>)",
                 &lit,&w[0],&id,&w[1],&sections,&w[2],&equations,NULL,NULL));
  print_asfix_literal(f,lit);
  print_asfix_ws(f,w[0]);
  print_asfix_id(f,id);
  print_asfix_ws(f,w[1]);
  print_asfix_sections(f,sections);
  print_asfix_ws(f,w[2]);
  print_asfix_equations(f,equations);
  return 0;
}

int print_source(FILE *f, aterm *term)
{
  print_asfix_module(f,term);
  Tprintf(f,"\n");
  return 0;
}

int print_term_source(FILE *f, aterm *term)
{
  aterm *t;

  assertp(Tmatch(term,
                 "term(<term>,<term>,<term>,<term>,<term>," \
                         "<term>,<term>,<term>,<term>)",
                 NULL,NULL,NULL,NULL,NULL,NULL,&t,NULL,NULL));
  print_asfix_term(f,t);
  Tprintf(f,"\n");
  return 0;
}

