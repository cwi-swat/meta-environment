#include <string.h>
#include <asfix.h>
#include <term-list.h>
#include <abbrevs.h>

#define TABLE_SIZE 2048

static aterm *term_w_appl;

void init_expansion_terms()
{
  arena local;
  aterm *tmp;

  TinitArena(NULL, &local);

  /* Building a white-space appl */
  tmp = AFmakeProd(&local, TmakeSimple(&local, "id(\"ParseTrees\")"),
                        TmkList_n(&local,1,TmakeSimple(&local, "ql(\"w\")")), 
                        TmakeSimple(&local, "sort(\"AFun\")"),
                        TmakeSimple(&local, "no-attrs"));
  term_w_appl = AFmakeAppl(&local, tmp, 
                   TmkList_n(&local, 1, TmakeSimple(&local, "l(\"w\")")));

  Tprotect(term_w_appl);
  TdestroyArena(&local);
}

typedef struct prodbucket
{
  struct prodbucket *next;
  aterm *prod;
  aterm *result;
} prodbucket;

static prodbucket *table[TABLE_SIZE] = { NULL };

static prodbucket *find_bucket(aterm *prod)
{
  int idx = prod->hnr % TABLE_SIZE;
  
  prodbucket *cur = table[idx];
  while(cur && !t_equal(cur->prod, prod))
    cur = cur->next;

  return cur;
}

static void enter_prod(aterm *prod, aterm *result)
{
  int idx = prod->hnr % TABLE_SIZE;
  prodbucket *b = malloc(sizeof(prodbucket));
  if(!b)
    fatal_error("out of memory in enter_prod");
  b->next = table[idx];
  table[idx] = b;
  b->prod = prod;
  b->result = result;
  Tprotect(prod);
  Tprotect(result);
}

int is_sep(aterm *sep)
{
  char *text;
  return Tmatch(sep,"sep(<str>)",&text);
}

aterm *make_l_appl(arena *ar)
{
  aterm *prod;

  prod = AFmakeProd(ar, TmakeSimple(ar, "id(\"ParseTrees\")"),
                        TmkList_n(ar,1,TmakeSimple(ar, "ql(\"l\")")),
                        TmakeSimple(ar, "sort(\"AFun\")"),
                        TmakeSimple(ar, "no-attrs"));
  return AFmakeAppl(ar, prod, TmkList_n(ar,1,TmakeSimple(ar, "l(\"l\")")));
}

aterm *make_ql_appl(arena *ar)
{
  aterm *prod;

  prod = AFmakeProd(ar, TmakeSimple(ar, "id(\"AsFixParseTrees\")"),
                        TmkList_n(ar,1,TmakeSimple(ar, "ql(\"ql\")")),
                        TmakeSimple(ar, "sort(\"AFun\")"),
                        TmakeSimple(ar, "no-attrs"));
  return AFmakeAppl(ar, prod, TmkList_n(ar,1,TmakeSimple(ar, "l(\"ql\")")));
}

aterm *make_sep_appl(arena *ar)
{
  aterm *prod;

  prod = AFmakeProd(ar, TmakeSimple(ar, "id(\"ParseTrees\")"),
                        TmkList_n(ar,1,TmakeSimple(ar, "ql(\"sep\")")),
                        TmakeSimple(ar, "sort(\"AFun\")"),
                        TmakeSimple(ar, "no-attrs"));
  return AFmakeAppl(ar, prod, TmkList_n(ar,1,TmakeSimple(ar, "l(\"sep\")")));
}

aterm *make_id_appl(arena *ar)
{
  aterm *prod;

  prod = AFmakeProd(ar, TmakeSimple(ar, "id(\"AsFixParseTrees\")"),
                        TmkList_n(ar,1,TmakeSimple(ar, "ql(\"id\")")),
                        TmakeSimple(ar, "sort(\"AFun\")"),
                        TmakeSimple(ar, "no-attrs"));
  return AFmakeAppl(ar,
                    prod,
                    TmkList_n(ar,
                              1,
                              TmakeSimple(ar, "l(\"id\")")));
}

aterm *make_exports_appl(arena *ar)
{
  aterm *prod;

  prod = AFmakeProd(ar, TmakeSimple(ar, "id(\"AsFixParseTrees\")"),
                        TmkList_n(ar,1,TmakeSimple(ar, "ql(\"exports\")")),
                        TmakeSimple(ar, "sort(\"AFun\")"),
                        TmakeSimple(ar, "no-attrs"));
  return AFmakeAppl(ar,
                    prod,
                    TmkList_n(ar,
                              1,
                              TmakeSimple(ar, "l(\"exports\")")));
}

aterm *make_imports_appl(arena *ar)
{
  aterm *prod;

  prod = AFmakeProd(ar, TmakeSimple(ar, "id(\"AsFixParseTrees\")"),
                        TmkList_n(ar,1,TmakeSimple(ar, "ql(\"imports\")")),
                        TmakeSimple(ar, "sort(\"AFun\")"),
                        TmakeSimple(ar, "no-attrs"));
  return AFmakeAppl(ar,
                    prod,
                    TmkList_n(ar,
                              1,
                              TmakeSimple(ar, "l(\"imports\")")));
}

aterm *make_hiddens_appl(arena *ar)
{
  aterm *prod;

  prod = AFmakeProd(ar, TmakeSimple(ar, "id(\"AsFixParseTrees\")"),
                        TmkList_n(ar,1,TmakeSimple(ar, "ql(\"hiddens\")")),
                        TmakeSimple(ar, "sort(\"AFun\")"),
                        TmakeSimple(ar, "no-attrs"));
  return AFmakeAppl(ar,
                    prod,
                    TmkList_n(ar,
                              1,
                              TmakeSimple(ar, "l(\"hiddens\")")));
}

aterm *make_lexicalsyntax_appl(arena *ar)
{
  aterm *prod;

  prod = AFmakeProd(ar, TmakeSimple(ar, "id(\"AsFixParseTrees\")"),
                        TmkList_n(ar,1,TmakeSimple(ar, "ql(\"lexical-syntax\")")),
                        TmakeSimple(ar, "sort(\"AFun\")"),
                        TmakeSimple(ar, "no-attrs"));
  return AFmakeAppl(ar,
                    prod,
                    TmkList_n(ar,
                              1,
                              TmakeSimple(ar, "l(\"lexical-syntax\")")));
}

aterm *make_contextfreesyntax_appl(arena *ar)
{
  aterm *prod;

  prod = AFmakeProd(ar, TmakeSimple(ar, "id(\"AsFixParseTrees\")"),
                        TmkList_n(ar,1,TmakeSimple(ar, "ql(\"context-free-syntax\")")
),
                        TmakeSimple(ar, "sort(\"AFun\")"),
                        TmakeSimple(ar, "no-attrs"));
  return AFmakeAppl(ar,
                    prod,
                    TmkList_n(ar,
                              1,
                              TmakeSimple(ar, "l(\"context-free-syntax\")")));
}

aterm *make_variables_appl(arena *ar)
{
  aterm *prod;

  prod = AFmakeProd(ar, TmakeSimple(ar, "id(\"AsFixParseTrees\")"),
                        TmkList_n(ar,1,TmakeSimple(ar, "ql(\"variables\")")),
                        TmakeSimple(ar, "sort(\"AFun\")"),
                        TmakeSimple(ar, "no-attrs"));
  return AFmakeAppl(ar,
                    prod,
                    TmkList_n(ar,
                              1,
                              TmakeSimple(ar, "l(\"variables\")")));
}

aterm *make_sorts_appl(arena *ar)
{
  aterm *prod;

  prod = AFmakeProd(ar, TmakeSimple(ar, "id(\"AsFixParseTrees\")"),
                        TmkList_n(ar,1,TmakeSimple(ar, "ql(\"sorts\")")),
                        TmakeSimple(ar, "sort(\"AFun\")"),
                        TmakeSimple(ar, "no-attrs"));
  return AFmakeAppl(ar,
                    prod,
                    TmkList_n(ar,
                              1,
                              TmakeSimple(ar, "l(\"sorts\")")));
}

aterm *make_sort_appl(arena *ar)
{
  aterm *prod;

  prod = AFmakeProd(ar, TmakeSimple(ar, "id(\"ParseTrees\")"),
                        TmkList_n(ar,1,TmakeSimple(ar, "ql(\"sort\")")),
                        TmakeSimple(ar, "sort(\"AFun\")"),
                        TmakeSimple(ar, "no-attrs"));
  return AFmakeAppl(ar,
                    prod,
                    TmkList_n(ar,
                              1,
                              TmakeSimple(ar, "l(\"sort\")")));
}

aterm *make_priorities_appl(arena *ar)
{
  aterm *prod;

  prod = AFmakeProd(ar, TmakeSimple(ar, "id(\"AsFixParseTrees\")"),
                        TmkList_n(ar,1,TmakeSimple(ar, "ql(\"priorities\")")),
                        TmakeSimple(ar, "sort(\"AFun\")"),
                        TmakeSimple(ar, "no-attrs"));
  return AFmakeAppl(ar,
                    prod,
                    TmkList_n(ar,
                              1,
                              TmakeSimple(ar, "l(\"priorities\")")));
}

aterm *make_incrchain_appl(arena *ar)
{
  aterm *prod;

  prod = AFmakeProd(ar, TmakeSimple(ar, "id(\"AsFixParseTrees\")"),
                        TmkList_n(ar,1,TmakeSimple(ar, "ql(\"incr-chain\")")),
                        TmakeSimple(ar, "sort(\"AFun\")"),
                        TmakeSimple(ar, "no-attrs"));
  return AFmakeAppl(ar,
                    prod,
                    TmkList_n(ar,
                              1,
                              TmakeSimple(ar, "l(\"incr-chain\")")));
}

aterm *make_decrchain_appl(arena *ar)
{
  aterm *prod;

  prod = AFmakeProd(ar, TmakeSimple(ar, "id(\"AsFixParseTrees\")"),
                        TmkList_n(ar,1,TmakeSimple(ar, "ql(\"decr-chain\")")),
                        TmakeSimple(ar, "sort(\"AFun\")"),
                        TmakeSimple(ar, "no-attrs"));
  return AFmakeAppl(ar,
                    prod,
                    TmkList_n(ar,
                              1,
                              TmakeSimple(ar, "l(\"decr-chain\")")));
}

aterm *make_prodskel_appl(arena *ar)
{
  aterm *prod;

  prod = AFmakeProd(ar, TmakeSimple(ar, "id(\"AsFixParseTrees\")"),
                        TmkList_n(ar,1,TmakeSimple(ar, "ql(\"prod-skel\")")),
                        TmakeSimple(ar, "sort(\"AFun\")"),
                        TmakeSimple(ar, "no-attrs"));
  return AFmakeAppl(ar,
                    prod,
                    TmkList_n(ar,
                              1,
                              TmakeSimple(ar, "l(\"prod-skel\")")));
}

aterm *make_group_appl(arena *ar)
{
  aterm *prod;

  prod = AFmakeProd(ar, TmakeSimple(ar, "id(\"AsFixParseTrees\")"),
                        TmkList_n(ar,1,TmakeSimple(ar, "ql(\"group\")")),
                        TmakeSimple(ar, "sort(\"AFun\")"),
                        TmakeSimple(ar, "no-attrs"));
  return AFmakeAppl(ar,
                    prod,
                    TmkList_n(ar,
                              1,
                              TmakeSimple(ar, "l(\"group\")")));
}

aterm *make_agroup_appl(arena *ar)
{
  aterm *prod;

  prod = AFmakeProd(ar, TmakeSimple(ar, "id(\"AsFixParseTrees\")"),
                        TmkList_n(ar,1,TmakeSimple(ar, "ql(\"agroup\")")),
                        TmakeSimple(ar, "sort(\"AFun\")"),
                        TmakeSimple(ar, "no-attrs"));
  return AFmakeAppl(ar,
                    prod,
                    TmkList_n(ar,
                              1,
                              TmakeSimple(ar, "l(\"agroup\")")));
}

aterm *make_noattrs_appl(arena *ar)
{
  aterm *prod;

  prod = AFmakeProd(ar, TmakeSimple(ar, "id(\"AsFixParseTrees\")"),
                        TmkList_n(ar,1,TmakeSimple(ar, "ql(\"no-attrs\")")),
                        TmakeSimple(ar, "sort(\"AFun\")"),
                        TmakeSimple(ar, "no-attrs"));
  return AFmakeAppl(ar,
                    prod,
                    TmkList_n(ar,
                              1,
                              TmakeSimple(ar, "l(\"no-attrs\")")));
}

aterm *make_attrs_appl(arena *ar)
{
  aterm *prod;

  prod = AFmakeProd(ar, TmakeSimple(ar, "id(\"AsFixParseTrees\")"),
                        TmkList_n(ar,1,TmakeSimple(ar, "ql(\"attrs\")")),
                        TmakeSimple(ar, "sort(\"AFun\")"),
                        TmakeSimple(ar, "no-attrs"));
  return AFmakeAppl(ar,
                    prod,
                    TmkList_n(ar,
                              1,
                              TmakeSimple(ar, "l(\"attrs\")")));
}

aterm *make_noequations_appl(arena *ar)
{
  aterm *prod;

  prod = AFmakeProd(ar, TmakeSimple(ar, "id(\"AsFixParseTrees\")"),
                        TmkList_n(ar,1,TmakeSimple(ar, "ql(\"no-equations\")")),
                        TmakeSimple(ar, "sort(\"AFun\")"),
                        TmakeSimple(ar, "no-attrs"));
  return AFmakeAppl(ar,
                    prod,
                    TmkList_n(ar,
                              1,
                              TmakeSimple(ar, "l(\"no-equations\")")));
}

aterm *make_equations_appl(arena *ar)
{
  aterm *prod;

  prod = AFmakeProd(ar, TmakeSimple(ar, "id(\"AsFixParseTrees\")"),
                        TmkList_n(ar,1,TmakeSimple(ar, "ql(\"equations\")")),
                        TmakeSimple(ar, "sort(\"AFun\")"),
                        TmakeSimple(ar, "no-attrs"));
  return AFmakeAppl(ar,
                    prod,
                    TmkList_n(ar,
                              1,
                              TmakeSimple(ar, "l(\"equations\")")));
}

aterm *make_ceqequ_appl(arena *ar)
{
  aterm *prod;

  prod = AFmakeProd(ar, TmakeSimple(ar, "id(\"AsFixParseTrees\")"),
                        TmkList_n(ar,1,TmakeSimple(ar, "ql(\"ceq-equ\")")),
                        TmakeSimple(ar, "sort(\"AFun\")"),
                        TmakeSimple(ar, "no-attrs"));
  return AFmakeAppl(ar,
                    prod,
                    TmkList_n(ar,
                              1,
                              TmakeSimple(ar, "l(\"ceq-equ\")")));
}

aterm *make_ceqimpl_appl(arena *ar)
{
  aterm *prod;

  prod = AFmakeProd(ar, TmakeSimple(ar, "id(\"AsFixParseTrees\")"),
                        TmkList_n(ar,1,TmakeSimple(ar, "ql(\"ceq-impl\")")),
                        TmakeSimple(ar, "sort(\"AFun\")"),
                        TmakeSimple(ar, "no-attrs"));
  return AFmakeAppl(ar,
                    prod,
                    TmkList_n(ar,
                              1,
                              TmakeSimple(ar, "l(\"ceq-impl\")")));
}

aterm *make_ceqwhen_appl(arena *ar)
{
  aterm *prod;

  prod = AFmakeProd(ar, TmakeSimple(ar, "id(\"AsFixParseTrees\")"),
                        TmkList_n(ar,1,TmakeSimple(ar, "ql(\"ceq-when\")")),
                        TmakeSimple(ar, "sort(\"AFun\")"),
                        TmakeSimple(ar, "no-attrs"));
  return AFmakeAppl(ar,
                    prod,
                    TmkList_n(ar,
                              1,
                              TmakeSimple(ar, "l(\"ceq-when\")")));
}

aterm *make_condition_appl(arena *ar)
{
  aterm *prod;

  prod = AFmakeProd(ar, TmakeSimple(ar, "id(\"AsFixParseTrees\")"),
                        TmkList_n(ar,1,TmakeSimple(ar, "ql(\"condition\")")),
                        TmakeSimple(ar, "sort(\"AFun\")"),
                        TmakeSimple(ar, "no-attrs"));
  return AFmakeAppl(ar,
                    prod,
                    TmkList_n(ar,
                              1,
                              TmakeSimple(ar, "l(\"condition\")")));
}

aterm *make_iter_appl(arena *ar)
{
  aterm *prod;

  prod = AFmakeProd(ar, TmakeSimple(ar, "id(\"ParseTrees\")"),
                        TmkList_n(ar,1,TmakeSimple(ar, "ql(\"iter\")")),
                        TmakeSimple(ar, "sort(\"AFun\")"),
                        TmakeSimple(ar, "no-attrs"));
  return AFmakeAppl(ar,
                    prod,
                    TmkList_n(ar,
                              1,
                              TmakeSimple(ar, "l(\"iter\")")));
}

aterm *make_itersep_appl(arena *ar)
{
  aterm *prod;

  prod = AFmakeProd(ar, TmakeSimple(ar, "id(\"ParseTrees\")"),
                        TmkList_n(ar,1,TmakeSimple(ar, "ql(\"iter-sep\")")),
                        TmakeSimple(ar, "sort(\"AFun\")"),
                        TmakeSimple(ar, "no-attrs"));
  return AFmakeAppl(ar,
                    prod,
                    TmkList_n(ar,
                              1,
                              TmakeSimple(ar, "l(\"iter-sep\")")));
}

aterm *make_module_appl(arena *ar)
{
  aterm *prod;

  prod = AFmakeProd(ar, TmakeSimple(ar, "id(\"AsFixParseTrees\")"),
                        TmkList_n(ar,1,TmakeSimple(ar, "ql(\"module\")")),
                        TmakeSimple(ar, "sort(\"AFun\")"),
                        TmakeSimple(ar, "no-attrs"));
  return AFmakeAppl(ar,
                    prod,
                    TmkList_n(ar,
                              1,
                              TmakeSimple(ar, "l(\"module\")")));
}

aterm *make_abbreviations_appl(arena *ar)
{
  aterm *prod;

  prod = AFmakeProd(ar, TmakeSimple(ar, "id(\"AsFixParseTrees\")"),
                        TmkList_n(ar,1,TmakeSimple(ar, "ql(\"abbreviations\")")),
                        TmakeSimple(ar, "sort(\"AFun\")"),
                        TmakeSimple(ar, "no-attrs"));
  return AFmakeAppl(ar,
                    prod,
                    TmkList_n(ar,
                              1,
                              TmakeSimple(ar, "l(\"abbreviations\")")));
}

aterm *make_prod_appl(arena *ar)
{
  aterm *prod;

  prod = AFmakeProd(ar, TmakeSimple(ar, "id(\"AsFixParseTrees\")"),
                        TmkList_n(ar,1,TmakeSimple(ar, "ql(\"prod\")")),
                        TmakeSimple(ar, "sort(\"AFun\")"),
                        TmakeSimple(ar, "no-attrs"));
  return AFmakeAppl(ar,
                    prod,
                    TmkList_n(ar,
                              1,
                              TmakeSimple(ar, "l(\"prod\")")));
}

aterm *make_appl_appl(arena *ar)
{
  aterm *prod;

  prod = AFmakeProd(ar, TmakeSimple(ar, "id(\"AsFixParseTrees\")"),
                        TmkList_n(ar,1,TmakeSimple(ar, "ql(\"appl\")")),
                        TmakeSimple(ar, "sort(\"AFun\")"),
                        TmakeSimple(ar, "no-attrs"));
  return AFmakeAppl(ar,
                    prod,
                    TmkList_n(ar,
                              1,
                              TmakeSimple(ar, "l(\"appl\")")));
}

aterm *make_list_appl(arena *ar)
{
  aterm *prod;

  prod = AFmakeProd(ar, TmakeSimple(ar, "id(\"AsFixParseTrees\")"),
                        TmkList_n(ar,1,TmakeSimple(ar, "ql(\"list\")")),
                        TmakeSimple(ar, "sort(\"AFun\")"),
                        TmakeSimple(ar, "no-attrs"));
  return AFmakeAppl(ar,
                    prod,
                    TmkList_n(ar,
                              1,
                              TmakeSimple(ar, "l(\"list\")")));
}

aterm *make_var_appl(arena *ar)
{
  aterm *prod;

  prod = AFmakeProd(ar, TmakeSimple(ar, "id(\"AsFixParseTrees\")"),
                        TmkList_n(ar,1,TmakeSimple(ar, "ql(\"var\")")),
                        TmakeSimple(ar, "sort(\"AFun\")"),
                        TmakeSimple(ar, "no-attrs"));
  return AFmakeAppl(ar,
                    prod,
                    TmkList_n(ar,
                              1,
                              TmakeSimple(ar, "l(\"var\")")));
}

aterm *make_lex_appl(arena *ar)
{
  aterm *prod;

  prod = AFmakeProd(ar, TmakeSimple(ar, "id(\"AsFixParseTrees\")"),
                        TmkList_n(ar,1,TmakeSimple(ar, "ql(\"lex\")")),
                        TmakeSimple(ar, "sort(\"AFun\")"),
                        TmakeSimple(ar, "no-attrs"));
  return AFmakeAppl(ar,
                    prod,
                    TmkList_n(ar,
                              1,
                              TmakeSimple(ar, "l(\"lex\")")));
}

aterm *make_neg_appl(arena *ar)
{
  aterm *prod;

  prod = AFmakeProd(ar, TmakeSimple(ar, "id(\"AsFixParseTrees\")"),
                        TmkList_n(ar,1,TmakeSimple(ar, "ql(\"neg\")")),
                        TmakeSimple(ar, "sort(\"AFun\")"),
                        TmakeSimple(ar, "no-attrs"));
  return AFmakeAppl(ar,
                    prod,
                    TmkList_n(ar,
                              1,
                              TmakeSimple(ar, "l(\"neg\")")));
}

aterm *make_charclass_appl(arena *ar)
{
  aterm *prod;

  prod = AFmakeProd(ar, TmakeSimple(ar, "id(\"AsFixParseTrees\")"),
                        TmkList_n(ar,1,TmakeSimple(ar, "ql(\"char-class\")")),
                        TmakeSimple(ar, "sort(\"AFun\")"),
                        TmakeSimple(ar, "no-attrs"));
  return AFmakeAppl(ar,
                    prod,
                    TmkList_n(ar,
                              1,
                              TmakeSimple(ar, "l(\"char-class\")")));
}

aterm *make_literal_to_afun_prod(arena *ar)
{
  return AFmakeProd(ar, TmakeSimple(ar, "id(\"ATerms\")"),
                        TmkList_n(ar,1,TmakeSimple(ar, "sort(\"Literal\")")),
                        TmakeSimple(ar, "sort(\"AFun\")"),
                        TmakeSimple(ar, "no-attrs"));
}

aterm *make_literal_to_afun_appl(arena *ar,aterm *arg)
{
  return AFmakeAppl(ar,
                    make_literal_to_afun_prod(ar),
                    TmkList_n(ar,1,arg));
}

aterm *make_afun_to_aterm_prod(arena *ar)
{
  return AFmakeProd(ar, TmakeSimple(ar, "id(\"ATerms\")"),
                        TmkList_n(ar,1,TmakeSimple(ar, "sort(\"AFun\")")),
                        TmakeSimple(ar, "sort(\"ATerm\")"),
                        TmakeSimple(ar, "no-attrs"));
}

aterm *make_afun_to_aterm_appl(arena *ar,aterm *arg)
{
  return AFmakeAppl(ar,
                    make_afun_to_aterm_prod(ar),
                    TmkList_n(ar,1,arg));
}

aterm *make_aterm_to_aterms_prod(arena *ar)
{
  return AFmakeProd(ar, TmakeSimple(ar, "id(\"ATerms\")"),
                        TmkList_n(ar,1,TmakeSimple(ar, "sort(\"ATerm\")")),
                        TmakeSimple(ar, "sort(\"ATerms\")"),
                        TmakeSimple(ar, "no-attrs"));
}

aterm *make_aterm_to_aterms_appl(arena *ar,aterm *arg)
{
  return AFmakeAppl(ar,
                    make_aterm_to_aterms_prod(ar),
                    TmkList_n(ar,1,arg));
}

aterm *make_afun_aterms_to_aterm_prod(arena *ar)
{
  return AFmakeProd(ar, TmakeSimple(ar, "id(\"ATerms\")"),
                        TmkList_n(ar,7,TmakeSimple(ar, "sort(\"AFun\")"),
                                       TmakeSimple(ar, "w(\"\")"),
                                       TmakeSimple(ar, "ql(\"(\")"),
                                       TmakeSimple(ar, "w(\"\")"),
                                       TmakeSimple(ar, "sort(\"ATerms\")"),
                                       TmakeSimple(ar, "w(\"\")"),
                                       TmakeSimple(ar, "ql(\")\")")),
                        TmakeSimple(ar, "sort(\"ATerm\")"),
                        TmakeSimple(ar, "no-attrs"));
}

aterm *make_afun_aterms_to_aterm_appl(arena *ar,aterm *fun,aterm *arg)
{
  return AFmakeAppl(ar,make_afun_aterms_to_aterm_prod(ar),
                    TmkList_n(ar,7,
                              fun,
                              TmakeSimple(ar, "w(\"\")"),
                              TmakeSimple(ar, "l(\"(\")"),
                              TmakeSimple(ar, "w(\"\")"),
                              arg,
                              TmakeSimple(ar, "w(\"\")"),
                              TmakeSimple(ar, "l(\")\")")));
}

/* <PO> wordt vaak aangeroepen + constant */
aterm *make_aterm_aterms_to_aterms_prod(arena *ar)
{
  return AFmakeProd(ar, TmakeSimple(ar, "id(\"ATerms\")"),
                        TmkList_n(ar,5,TmakeSimple(ar, "sort(\"ATerm\")"),
                                       TmakeSimple(ar, "w(\"\")"),
                                       TmakeSimple(ar, "ql(\",\")"),
                                       TmakeSimple(ar, "w(\"\n\")"),
                                       TmakeSimple(ar, "sort(\"ATerms\")")),
                        TmakeSimple(ar, "sort(\"ATerms\")"),
                        TmakeSimple(ar, "no-attrs"));
}

aterm *make_aterm_aterms_to_aterms_appl(arena *ar,aterm *term, aterm *terms)
{
  return AFmakeAppl(ar,make_aterm_aterms_to_aterms_prod(ar),
                    TmkList_n(ar,5,
                              term,
                              TmakeSimple(ar, "w(\"\")"),
                              TmakeSimple(ar, "l(\",\")"),
                              TmakeSimple(ar, "w(\"\")"),
                              terms));
}

aterm *make_atermlist_to_aterm_prod(arena *ar)
{
  return AFmakeProd(ar, TmakeSimple(ar, "id(\"ATerms\")"),
                        TmkList_n(ar,1,TmakeSimple(ar, "sort(\"ATermList\")")),
                        TmakeSimple(ar, "sort(\"ATerm\")"),
                        TmakeSimple(ar, "no-attrs"));
}

aterm *make_atermlist_to_aterm_appl(arena *ar,aterm *arg)
{
  return AFmakeAppl(ar,make_atermlist_to_aterm_prod(ar),
                    TmkList_n(ar,1,arg));
}

aterm *make_aterms_to_atermlist_prod(arena *ar)
{
  return AFmakeProd(ar, TmakeSimple(ar, "id(\"ATerms\")"),
                        TmkList_n(ar,5,TmakeSimple(ar, "ql(\"[\")"),
                                       TmakeSimple(ar, "w(\"\")"),
                                       TmakeSimple(ar, "sort(\"ATerms\")"),
                                       TmakeSimple(ar, "w(\"\")"),
                                       TmakeSimple(ar, "ql(\"]\")")),
                        TmakeSimple(ar, "sort(\"ATermList\")"),
                        TmakeSimple(ar, "no-attrs"));
}

aterm *make_aterms_to_atermlist_appl(arena *ar, aterm *args)
{
  return AFmakeAppl(ar,
                    make_aterms_to_atermlist_prod(ar),
                    TmkList_n(ar,5,
                              TmakeSimple(ar, "l(\"[\")"),
                              TmakeSimple(ar, "w(\"\")"),
                              args,
                              TmakeSimple(ar, "w(\"\")"),
                              TmakeSimple(ar, "l(\"]\")")));
}

aterm *make_empty_to_atermlist_prod(arena *ar)
{
  return AFmakeProd(ar, TmakeSimple(ar, "id(\"ATerms\")"),
                        TmkList_n(ar,3,TmakeSimple(ar, "ql(\"[\")"),
                                       TmakeSimple(ar, "w(\"\")"),
                                       TmakeSimple(ar, "ql(\"]\")")),
                        TmakeSimple(ar, "sort(\"ATermList\")"),
                        TmakeSimple(ar, "no-attrs"));
}

aterm *make_empty_to_atermlist_appl(arena *ar)
{
  return AFmakeAppl(ar,
                    make_empty_to_atermlist_prod(ar),
                    TmkList_n(ar,3,TmakeSimple(ar, "l(\"[\")"),
                                   TmakeSimple(ar, "w(\"\")"),
                                   TmakeSimple(ar, "l(\"]\")")));
}

aterm *make_lex(arena *ar,char *lsym)
{
  return AFmakeLex(ar,lsym,TmakeSimple(ar, "sort(\"Literal\")"));
}

aterm *make_empty_abbreviations(arena *ar)
{
  return make_afun_aterms_to_aterm_appl(ar,
           make_abbreviations_appl(ar),
           make_aterm_to_aterms_appl(ar,
             make_atermlist_to_aterm_appl(ar,
               make_empty_to_atermlist_appl(ar))));
}

aterm *expand_asfix_ws(arena *ar, aterm *ws)
{
  char *text;
  aterm *appl;

  assertp(Tmatch(ws,"w(<str>)",&text));
  appl = make_afun_to_aterm_appl(ar,
                                 make_literal_to_afun_appl(ar,
                                                           make_lex(ar,text)));
  return make_afun_aterms_to_aterm_appl(ar,
                                        term_w_appl,
                                        make_aterm_to_aterms_appl(ar,appl));
}

aterm *expand_asfix_literal(arena *ar, aterm *l)
{
  char *text;
  aterm *appl;

  assertp(Tmatch(l,"l(<str>)",&text));
  appl = make_afun_to_aterm_appl(ar,
                                 make_literal_to_afun_appl(ar,
                                                           make_lex(ar,text)));
  return make_afun_aterms_to_aterm_appl(ar,
                                        make_l_appl(ar),
                                        make_aterm_to_aterms_appl(ar,appl));
}

aterm *expand_asfix_qliteral(arena *ar, aterm *ql)
{
  char *text;
  aterm *appl;

  assertp(Tmatch(ql,"ql(<str>)",&text));
  appl = make_afun_to_aterm_appl(ar,
                                 make_literal_to_afun_appl(ar,
                                                           make_lex(ar,text)));
  return make_afun_aterms_to_aterm_appl(ar,
                                        make_ql_appl(ar),
                                        make_aterm_to_aterms_appl(ar,appl));
}

aterm *expand_asfix_sep(arena *ar, aterm *s)
{
  char *text;
  aterm *appl;

  assertp(Tmatch(s,"sep(<str>)",&text));
  appl = make_afun_to_aterm_appl(ar,
                                 make_literal_to_afun_appl(ar,
                                                           make_lex(ar,text)));
  return make_afun_aterms_to_aterm_appl(ar,
                                        make_sep_appl(ar),
                                        make_aterm_to_aterms_appl(ar,appl));
}

aterm *expand_asfix_term(arena *ar, aterm *term);
aterm *expand_asfix_sort(arena *ar, aterm *sort);

aterm *expand_asfix_iter(arena *ar, aterm *iter)
{
  aterm *term, *w, *l;
  aterm *args;

  assertp(Tmatch(iter,"iter(<term>,<term>,<term>)",
                 &term,&w,&l));
  args = make_aterm_aterms_to_aterms_appl(ar,
           expand_asfix_term(ar,term),
           make_aterm_aterms_to_aterms_appl(ar,
             expand_asfix_ws(ar,w),
             make_aterm_to_aterms_appl(ar,
               expand_asfix_literal(ar,l))));
  return make_afun_aterms_to_aterm_appl(ar,
                                        make_iter_appl(ar),
                                        args);
}

aterm *expand_asfix_itersep(arena *ar, aterm *itersep)
{
  aterm *term, *w[4], *l[3], *ql;
  aterm *args;

  assertp(Tmatch(itersep,"iter-sep(<term>,<term>,<term>,<term>,<term>,<term>," \
                                "<term>,<term>,<term>)",
                 &l[0],&w[0],&term,&w[1],&ql,&w[2],&l[1],&w[3],&l[2]));
  args = make_aterm_aterms_to_aterms_appl(ar,
           expand_asfix_literal(ar,l[0]),
           make_aterm_aterms_to_aterms_appl(ar,
             expand_asfix_ws(ar,w[0]),
             make_aterm_aterms_to_aterms_appl(ar,
               expand_asfix_term(ar,term),
               make_aterm_aterms_to_aterms_appl(ar,
                 expand_asfix_ws(ar,w[1]),
                 make_aterm_aterms_to_aterms_appl(ar,
                   expand_asfix_qliteral(ar,ql),
                   make_aterm_aterms_to_aterms_appl(ar,
                     expand_asfix_ws(ar,w[2]),
                     make_aterm_aterms_to_aterms_appl(ar,
                       expand_asfix_literal(ar,l[1]),
                       make_aterm_aterms_to_aterms_appl(ar,
                         expand_asfix_ws(ar,w[3]),
                         make_aterm_to_aterms_appl(ar,
                           expand_asfix_literal(ar,l[2]))))))))));
  return make_afun_aterms_to_aterm_appl(ar,
                                        make_itersep_appl(ar),
                                        args);
}

aterm *expand_asfix_neg(arena *ar, aterm *neg)
{
  aterm *term, *w, *l;
  aterm *args;

  assertp(Tmatch(neg,"neg(<term>,<term>,<term>)",
                 &l,&w,&term));
  args = make_aterm_aterms_to_aterms_appl(ar,
           expand_asfix_literal(ar,l),
           make_aterm_aterms_to_aterms_appl(ar,
             expand_asfix_ws(ar,w),
             make_aterm_to_aterms_appl(ar,
               expand_asfix_term(ar,term))));
  return make_afun_aterms_to_aterm_appl(ar,
                                        make_neg_appl(ar),
                                        args);
}

aterm *expand_asfix_charclass(arena *ar, aterm *cc)
{
  char *text;
  aterm *appl;

  assertp(Tmatch(cc,"char-class(<str>)",&text));
  appl = make_afun_to_aterm_appl(ar,
                                 make_literal_to_afun_appl(ar,
                                                           make_lex(ar,text)));
  return make_afun_aterms_to_aterm_appl(ar,
                                        make_charclass_appl(ar),
                                        make_aterm_to_aterms_appl(ar,appl));
}

aterm *expand_asfix_id(arena *ar, aterm *id)
{
  char *text;
  aterm *appl;

  assertp(Tmatch(id,"id(<str>)",&text));
  appl = make_afun_to_aterm_appl(ar,
                                 make_literal_to_afun_appl(ar,
                                                           make_lex(ar,text)));
  return make_afun_aterms_to_aterm_appl(ar,
                                        make_id_appl(ar),
                                        make_aterm_to_aterms_appl(ar,appl));
}

aterm *expand_asfix_ids(arena *ar, aterm *ids)
{
  aterm *id;
  aterm *expid;
  aterm *expids;

  if(!t_is_empty(ids)) {
    id = t_list_first(ids);
    ids = t_list_next(ids);
    if(AFisLayout(id))
      expid = expand_asfix_ws(ar,id);
    else
      expid = expand_asfix_id(ar,id);
    if(!t_is_empty(ids)) {
      expids = make_aterm_aterms_to_aterms_appl(ar,
                         expid,
                         expand_asfix_ids(ar,ids));
    }
    else
      expids = make_aterm_to_aterms_appl(ar,expid);
  }
  return expids;
}

aterm *expand_asfix_idlist(arena *ar, aterm *idlist)
{
  aterm_list *ids;

  assertp(Tmatch(idlist,"<list>",&ids));
  if(t_is_empty(ids))
    return  make_atermlist_to_aterm_appl(ar,make_empty_to_atermlist_appl(ar));
  else
    return make_atermlist_to_aterm_appl(ar,
             make_aterms_to_atermlist_appl(ar,
               expand_asfix_ids(ar,ids)));
}

aterm *expand_asfix_attrs(arena *ar, aterm_list *attrs)
{
  aterm *attr;
  aterm *expattr;
  aterm *expattrs;

  if(!t_is_empty(attrs)) {
    attr = t_list_first(attrs);
    attrs = t_list_next(attrs);
    if(AFisLayout(attr))
      expattr = expand_asfix_ws(ar,attr);
    else
      expattr = expand_asfix_literal(ar,attr);
    if(!t_is_empty(attrs)) {
      expattrs = make_aterm_aterms_to_aterms_appl(ar,
                         expattr,
                         expand_asfix_attrs(ar,attrs));
    }
    else
      expattrs = make_aterm_to_aterms_appl(ar,expattr);
  }
  return expattrs;
}

aterm *expand_asfix_attributes(arena *ar, aterm *attrlist)
{
  aterm_list *attrs;
  aterm *w[2],*l[2],*args;

  if(Tmatch(attrlist,"no-attrs")) {
    return make_afun_to_aterm_appl(ar,make_noattrs_appl(ar));
  }
  else {
    assertp(Tmatch(attrlist,"attrs(<term>,<term>,<list>,<term>,<term>)",
                   &l[0],&w[0],&attrs,&w[1],&l[1]));
    args = make_aterm_aterms_to_aterms_appl(ar,
             expand_asfix_literal(ar,l[0]),
             make_aterm_aterms_to_aterms_appl(ar,
               expand_asfix_ws(ar,w[0]),
               make_aterm_aterms_to_aterms_appl(ar,
                 make_atermlist_to_aterm_appl(ar,
                 make_aterms_to_atermlist_appl(ar,
                 expand_asfix_attrs(ar,attrs))),
                   make_aterm_aterms_to_aterms_appl(ar,
                   expand_asfix_ws(ar,w[1]),
                     make_aterm_to_aterms_appl(ar,
                     expand_asfix_literal(ar,l[1]))))));
    return make_afun_aterms_to_aterm_appl(ar,
                                          make_attrs_appl(ar),
                                          args);
  }
}

aterm *expand_asfix_argslist(arena *ar, aterm *arglist);
aterm *expand_asfix_prod(arena *ar, aterm *prod);

aterm *expand_asfix_appl(arena *ar, aterm *appl)
{
  aterm *prod, *w, *applargs;
  aterm *args;

  assertp(Tmatch(appl,"appl(<term>,<term>,<term>)",
                   &prod,&w,&applargs));
  args = make_aterm_aterms_to_aterms_appl(ar,
             expand_asfix_prod(ar,prod),
             make_aterm_aterms_to_aterms_appl(ar,
               expand_asfix_ws(ar,w),
               make_aterm_to_aterms_appl(ar,
                 expand_asfix_argslist(ar,applargs))));
  return make_afun_aterms_to_aterm_appl(ar,
                                          make_appl_appl(ar),
                                          args);
}

aterm *expand_asfix_list(arena *ar, aterm *list)
{
  aterm *term,*w,*listargs;
  aterm *args;

  assertp(Tmatch(list,"list(<term>,<term>,<term>)",
                   &term,&w,&listargs));
  args = make_aterm_aterms_to_aterms_appl(ar,
           expand_asfix_term(ar,term),
           make_aterm_aterms_to_aterms_appl(ar,
             expand_asfix_ws(ar,w),
             make_aterm_to_aterms_appl(ar,
               expand_asfix_argslist(ar,listargs))));
  return make_afun_aterms_to_aterm_appl(ar,
                                          make_list_appl(ar),
                                          args);
}

aterm *expand_asfix_var(arena *ar, aterm *var)
{
  char *text;
  aterm *t;
  aterm *args;
  
  assertp(Tmatch(var,"var(<term>,<term>)",
                   &text,&t));
  args = make_aterm_aterms_to_aterms_appl(ar,
           make_afun_to_aterm_appl(ar,
           make_literal_to_afun_appl(ar,
           make_lex(ar,text))),
             make_aterm_to_aterms_appl(ar,
               expand_asfix_term(ar,t)));
  return make_afun_aterms_to_aterm_appl(ar,
                                        make_var_appl(ar),
                                        args);
}

aterm *expand_asfix_lex(arena *ar, aterm *lex)
{
  char *text;
  aterm *t;
  aterm *args;

  assertp(Tmatch(lex,"lex(<term>,<term>)",
                   &text,&t));
  args = make_aterm_aterms_to_aterms_appl(ar,
           make_afun_to_aterm_appl(ar,
           make_literal_to_afun_appl(ar,
           make_lex(ar,text))),
             make_aterm_to_aterms_appl(ar,
               expand_asfix_term(ar,t)));
  return make_afun_aterms_to_aterm_appl(ar,
                                        make_lex_appl(ar),
                                        args);
}

aterm *expand_asfix_term(arena *ar, aterm *term)
{
  char *text;
  aterm *t[9];

  if(Tmatch(term,"sort(<str>)",&text))
    return expand_asfix_sort(ar,term);
  else if(Tmatch(term,"l(<str>)",&text))
    return expand_asfix_literal(ar,term);
  else if(Tmatch(term,"ql(<str>)",&text))
    return expand_asfix_qliteral(ar,term);
  else if(Tmatch(term,"iter(<term>,<term>,<term>)",
                 &t[0],&t[1],&t[2]))
    return expand_asfix_iter(ar,term);
  else if(Tmatch(term,"iter-sep(<term>,<term>,<term>,<term>,<term>,<term>," \
                                "<term>,<term>,<term>)",
                 &t[0],&t[1],&t[2],&t[3],&t[4],&t[5],&t[6],&t[7],&t[8]))
    return expand_asfix_itersep(ar,term);
  else if(Tmatch(term,"neg(<term>,<term>,<term>)",
                 &t[0],&t[1],&t[2]))
    return expand_asfix_neg(ar,term);
  else if(Tmatch(term,"char-class(<str>)",&text))
    return expand_asfix_charclass(ar,term);
  else if(Tmatch(term,"appl(<term>,<term>,<term>)",
                 &t[0],&t[1],&t[2]))
    return expand_asfix_appl(ar,term);
  else if(Tmatch(term,"var(<str>,<term>)",
                 &text,&t[0]))
    return expand_asfix_var(ar,term);
  else if(Tmatch(term,"list(<term>,<term>,<term>)",
                 &t[0],&t[1],&t[2]))
    return expand_asfix_list(ar,term);
  else if(Tmatch(term,"lex(<str>,<term>)",
                 &text,&t[0]))
    return expand_asfix_lex(ar,term);
  else {
    Tprintf(stderr,"\n\nUnknown term type: %t", term);
    exit(1);
  }
}

aterm *expand_asfix_args(arena *ar, aterm *args)
{
  aterm *arg;
  aterm *exparg;
  aterm *expargs;

  if(!t_is_empty(args)) {
    arg = t_list_first(args);
    args = t_list_next(args);
    if(AFisLayout(arg))
      exparg = expand_asfix_ws(ar,arg);
    else if(is_sep(arg))
      exparg = expand_asfix_sep(ar,arg);
    else
      exparg = expand_asfix_term(ar,arg);
    if(!t_is_empty(args)) {
      expargs = make_aterm_aterms_to_aterms_appl(ar,
                         exparg,
                         expand_asfix_args(ar,args));
    }
    else
      expargs = make_aterm_to_aterms_appl(ar,exparg);
  }
  return expargs;
}

aterm *expand_asfix_argslist(arena *ar, aterm *arglist)
{
  aterm_list *args;

  assertp(Tmatch(arglist,"<list>",&args));
  if(t_is_empty(args))
    return make_atermlist_to_aterm_appl(ar,make_empty_to_atermlist_appl(ar));
  else
    return make_atermlist_to_aterm_appl(ar,
             make_aterms_to_atermlist_appl(ar,
               expand_asfix_args(ar,args)));
}


aterm *expand_asfix_prodskel(arena *ar, aterm *prodskel)
{
  aterm *args,*w,*prod;
  assertp(Tmatch(prodskel,"prod-skel(<term>,<term>,<term>)",
                  &args,&w,&prod));
  args = make_aterm_aterms_to_aterms_appl(ar,
           expand_asfix_argslist(ar,args),
           make_aterm_aterms_to_aterms_appl(ar,
             expand_asfix_ws(ar,w),
             make_aterm_to_aterms_appl(ar,
               expand_asfix_prod(ar,prod))));
  return make_afun_aterms_to_aterm_appl(ar,
                                        make_prodskel_appl(ar),
                                        args);
}

aterm *expand_asfix_prodskels(arena *ar, aterm *prodskels)
{
  aterm *prodskel;
  aterm *expprodskel;
  aterm *expprodskels;

  if(!t_is_empty(prodskels)) {
    prodskel = t_list_first(prodskels);
    prodskels = t_list_next(prodskels);
    if(AFisLayout(prodskel))
      expprodskel = expand_asfix_ws(ar,prodskel);
    else if(is_sep(prodskel))
      expprodskel = expand_asfix_sep(ar,prodskel);
    else
      expprodskel = expand_asfix_prodskel(ar,prodskel);
    if(!t_is_empty(prodskels)) {
      expprodskels = make_aterm_aterms_to_aterms_appl(ar,
                         expprodskel,
                         expand_asfix_prodskels(ar,prodskels));
    }
    else
      expprodskels = make_aterm_to_aterms_appl(ar,expprodskel);
  }
  return expprodskels;
}

aterm *expand_asfix_prodskellist(arena *ar, aterm *prodskellist)
{
  aterm_list *prodskels;

  assertp(Tmatch(prodskellist,"<list>",&prodskels));
  if(t_is_empty(prodskels))
    return make_atermlist_to_aterm_appl(ar,make_empty_to_atermlist_appl(ar));
  else
    return make_atermlist_to_aterm_appl(ar,
             make_aterms_to_atermlist_appl(ar,
               expand_asfix_prodskels(ar,prodskels)));
}

aterm *expand_asfix_chain(arena *ar, aterm *chain)
{
  aterm *args,*w[4],*prod,*l[4],*prods;
  if(Tmatch(chain,"prod-skel(<term>,<term>,<term>)",
                  &args,&w[0],&prod)) {
    args = make_aterm_aterms_to_aterms_appl(ar,
             expand_asfix_argslist(ar,args),
             make_aterm_aterms_to_aterms_appl(ar,
               expand_asfix_ws(ar,w[0]),
               make_aterm_to_aterms_appl(ar,
                 expand_asfix_prod(ar,prod))));
    return make_afun_aterms_to_aterm_appl(ar,
                                          make_prodskel_appl(ar),
                                          args);
  }
  else if(Tmatch(chain,"group(<term>,<term>,<term>,<term>,<term>)",
                 &l[0],&w[0],&prods,&w[1],&l[1])) {
    args = make_aterm_aterms_to_aterms_appl(ar,
             expand_asfix_literal(ar,l[0]),
             make_aterm_aterms_to_aterms_appl(ar,
               expand_asfix_ws(ar,w[0]),
               make_aterm_aterms_to_aterms_appl(ar, 
                 expand_asfix_prodskellist(ar,prods),
                 make_aterm_aterms_to_aterms_appl(ar, 
                   expand_asfix_ws(ar,w[1]),
                   make_aterm_to_aterms_appl(ar, 
                     expand_asfix_literal(ar,l[1]))))));
    return make_afun_aterms_to_aterm_appl(ar,
                                          make_group_appl(ar),
                                          args);
  }
  else {
    assertp(Tmatch(chain,"agroup(<term>,<term>,<term>,<term>,<term>," \
                                 "<term>,<term>,<term>,<term>)",
                   &l[0],&w[0],&l[1],&w[1],&l[2],&w[2],&prods,&w[3],&l[3]));
    args = make_aterm_aterms_to_aterms_appl(ar,
             expand_asfix_literal(ar,l[0]),
             make_aterm_aterms_to_aterms_appl(ar, 
               expand_asfix_ws(ar,w[0]),
               make_aterm_aterms_to_aterms_appl(ar,
                 expand_asfix_literal(ar,l[1]),
                 make_aterm_aterms_to_aterms_appl(ar,
                   expand_asfix_ws(ar,w[1]),
                   make_aterm_aterms_to_aterms_appl(ar,
                     expand_asfix_literal(ar,l[2]),
                     make_aterm_aterms_to_aterms_appl(ar,
                       expand_asfix_ws(ar,w[2]),
                       make_aterm_aterms_to_aterms_appl(ar,
                         expand_asfix_prodskellist(ar,prods),
                         make_aterm_aterms_to_aterms_appl(ar,
                           expand_asfix_ws(ar,w[3]),
                           make_aterm_to_aterms_appl(ar,
                             expand_asfix_literal(ar,l[3]))))))))));
    return make_afun_aterms_to_aterm_appl(ar,
                                          make_agroup_appl(ar),
                                          args);
  }
}

aterm *expand_asfix_chains(arena *ar, aterm *chains)
{
  aterm *chain;
  aterm *expchain;
  aterm *expchains;

  if(!t_is_empty(chains)) {
    chain = t_list_first(chains);
    chains = t_list_next(chains);
    if(AFisLayout(chain))
      expchain = expand_asfix_ws(ar,chain);
    else if(is_sep(chain))
      expchain = expand_asfix_sep(ar,chain);
    else
      expchain = expand_asfix_chain(ar,chain);
    if(!t_is_empty(chains)) {
      expchains = make_aterm_aterms_to_aterms_appl(ar,
                         expchain,
                         expand_asfix_chains(ar,chains));
    }
    else
      expchains = make_aterm_to_aterms_appl(ar,expchain);
  }
  return expchains;
}

aterm *expand_asfix_chainlist(arena *ar, aterm *chainlist)
{
  aterm_list *chains;

  assertp(Tmatch(chainlist,"<list>",&chains));
  if(t_is_empty(chains))
    return make_atermlist_to_aterm_appl(ar,make_empty_to_atermlist_appl(ar));
  else
    return make_atermlist_to_aterm_appl(ar,
             make_aterms_to_atermlist_appl(ar,
               expand_asfix_chains(ar,chains)));
}

aterm *expand_asfix_prio(arena *ar, aterm *prio)
{
  aterm *chainlist;

  if(Tmatch(prio,"incr-chain(<term>)",&chainlist)) {
    return make_afun_aterms_to_aterm_appl(ar,
               make_incrchain_appl(ar),
               expand_asfix_chainlist(ar,chainlist));
  }
  else {
    assertp(Tmatch(prio,"decr-chain(<term>)",&chainlist));
    return make_afun_aterms_to_aterm_appl(ar,
               make_decrchain_appl(ar),
               expand_asfix_chainlist(ar,chainlist));
  }
}

aterm *expand_asfix_prios(arena *ar, aterm *prios)
{
  aterm *prio;
  aterm *expprio;
  aterm *expprios;

  if(!t_is_empty(prios)) {
    prio = t_list_first(prios);
    prios = t_list_next(prios);
    if(AFisLayout(prio))
      expprio = expand_asfix_ws(ar,prio);
    else if(is_sep(prio))
      expprio = expand_asfix_sep(ar,prio);
    else
      expprio = expand_asfix_prio(ar,prio);
    if(!t_is_empty(prios)) {
      expprios = make_aterm_aterms_to_aterms_appl(ar,
                         expprio,
                         expand_asfix_prios(ar,prios));
    }
    else
      expprios = make_aterm_to_aterms_appl(ar,expprio);
  }
  return expprios;
}

aterm *expand_asfix_prioslist(arena *ar, aterm *priolist)
{
  aterm_list *prios;

  assertp(Tmatch(priolist,"<list>",&prios));
  if(t_is_empty(prios))
    return make_atermlist_to_aterm_appl(ar,make_empty_to_atermlist_appl(ar));
  else
    return make_atermlist_to_aterm_appl(ar,
             make_aterms_to_atermlist_appl(ar,
               expand_asfix_prios(ar,prios)));
}

aterm *expand_asfix_sort(arena *ar, aterm *sort)
{
  char *text;
  aterm *appl;

  assertp(Tmatch(sort,"sort(<str>)",&text));
  appl = make_afun_to_aterm_appl(ar,
             make_literal_to_afun_appl(ar,make_lex(ar,text)));
  return make_afun_aterms_to_aterm_appl(ar,
             make_sort_appl(ar),make_aterm_to_aterms_appl(ar,appl));
}

aterm *expand_asfix_sorts(arena *ar, aterm *sorts)
{
  aterm *sort;
  aterm *expsort;
  aterm *expsorts;

  if(!t_is_empty(sorts)) {
    sort = t_list_first(sorts);
    sorts = t_list_next(sorts);
    if(AFisLayout(sort))
      expsort = expand_asfix_ws(ar,sort);
    else
      expsort = expand_asfix_sort(ar,sort);
    if(!t_is_empty(sorts)) {
      expsorts = make_aterm_aterms_to_aterms_appl(ar,
                         expsort,
                         expand_asfix_sorts(ar,sorts));
    }
    else
      expsorts = make_aterm_to_aterms_appl(ar,expsort);
  }
  return expsorts;
}

aterm *expand_asfix_sortlist(arena *ar, aterm *sortlist)
{
  aterm_list *sorts;

  assertp(Tmatch(sortlist,"<list>",&sorts));
  if(t_is_empty(sorts))
    return make_atermlist_to_aterm_appl(ar,make_empty_to_atermlist_appl(ar));
  else
    return make_atermlist_to_aterm_appl(ar,
             make_aterms_to_atermlist_appl(ar,
               expand_asfix_sorts(ar,sorts)));
}

aterm *expand_asfix_prod(arena *ar, aterm *prod)
{
  aterm *w[4],*id,*prodargs,*lit,*term,*attrs;
  aterm *args, *result;

  prodbucket *b = find_bucket(prod);
  if(b)
    return b->result;

  assertp(Tmatch(prod,
                 "prod(<term>,<term>,<term>,<term>,<term>," \
                       "<term>,<term>,<term>,<term>)",
                 &id,&w[0],&prodargs,&w[1],&lit,&w[2],&term,&w[3],&attrs));
  args = make_aterm_aterms_to_aterms_appl(ar,
           expand_asfix_id(ar,id),
           make_aterm_aterms_to_aterms_appl(ar,
             expand_asfix_ws(ar,w[0]),
             make_aterm_aterms_to_aterms_appl(ar,
               expand_asfix_argslist(ar,prodargs),
               make_aterm_aterms_to_aterms_appl(ar,
                 expand_asfix_ws(ar,w[1]),
                 make_aterm_aterms_to_aterms_appl(ar,
                   expand_asfix_literal(ar,lit),
                   make_aterm_aterms_to_aterms_appl(ar,
                     expand_asfix_ws(ar,w[2]),
                     make_aterm_aterms_to_aterms_appl(ar,
                       expand_asfix_term(ar,term),
                       make_aterm_aterms_to_aterms_appl(ar,
                         expand_asfix_ws(ar,w[3]),
                           make_aterm_to_aterms_appl(ar,
                             expand_asfix_attributes(ar,attrs))))))))));
  result = make_afun_aterms_to_aterm_appl(ar,
                                        make_prod_appl(ar),
                                        args);

  enter_prod(prod, result);
  return result;
}

aterm *expand_asfix_prods(arena *ar, aterm *prods)
{
  aterm *prod;
  aterm *expprod;
  aterm *expprods;

  if(!t_is_empty(prods)) {
    prod = t_list_first(prods);
    prods = t_list_next(prods);
    if(AFisLayout(prod))
      expprod = expand_asfix_ws(ar,prod);
    else
      expprod = expand_asfix_prod(ar,prod);
    if(!t_is_empty(prods)) {
      expprods = make_aterm_aterms_to_aterms_appl(ar,
                         expprod,
                         expand_asfix_prods(ar,prods));
    }
    else
      expprods = make_aterm_to_aterms_appl(ar,expprod);
  }
  return expprods;
}

aterm *expand_asfix_prodlist(arena *ar, aterm *prodlist)
{
  aterm_list *prods;

  assertp(Tmatch(prodlist,"<list>",&prods));
  if(t_is_empty(prods))
    return make_atermlist_to_aterm_appl(ar,make_empty_to_atermlist_appl(ar));
  else
    return make_atermlist_to_aterm_appl(ar,
             make_aterms_to_atermlist_appl(ar,
               expand_asfix_prods(ar,prods)));
}

aterm *expand_asfix_subsection(arena *ar, aterm *subsection)
{
  aterm *lit, *w, *prods, *sorts, *prios;
  aterm *args;

  if(Tmatch(subsection, "lexical-syntax(<term>,<term>,<term>)",
            &lit,&w,&prods)) {
    args = make_aterm_aterms_to_aterms_appl(ar,
               expand_asfix_literal(ar,lit),
               make_aterm_aterms_to_aterms_appl(ar,
                 expand_asfix_ws(ar,w),
                 make_aterm_to_aterms_appl(ar,
                   expand_asfix_prodlist(ar,prods))));
    return make_afun_aterms_to_aterm_appl(ar,
                                          make_lexicalsyntax_appl(ar),
                                          args);
  }
  else if(Tmatch(subsection, "context-free-syntax(<term>,<term>,<term>)",
            &lit,&w,&prods)) {
    args = make_aterm_aterms_to_aterms_appl(ar,
               expand_asfix_literal(ar,lit),
               make_aterm_aterms_to_aterms_appl(ar,
                 expand_asfix_ws(ar,w),
                 make_aterm_to_aterms_appl(ar,
                   expand_asfix_prodlist(ar,prods))));
    return make_afun_aterms_to_aterm_appl(ar,
                                          make_contextfreesyntax_appl(ar),
                                          args);
  }
  else if(Tmatch(subsection, "variables(<term>,<term>,<term>)",
            &lit,&w,&prods)) {
    args = make_aterm_aterms_to_aterms_appl(ar,
               expand_asfix_literal(ar,lit),
               make_aterm_aterms_to_aterms_appl(ar,
                 expand_asfix_ws(ar,w),
                 make_aterm_to_aterms_appl(ar,
                   expand_asfix_prodlist(ar,prods))));
    return make_afun_aterms_to_aterm_appl(ar,
                                          make_variables_appl(ar),
                                          args);
  }
  else if(Tmatch(subsection, "sorts(<term>,<term>,<term>)",
            &lit,&w,&sorts)) {
    args = make_aterm_aterms_to_aterms_appl(ar,
               expand_asfix_literal(ar,lit),
               make_aterm_aterms_to_aterms_appl(ar,
                 expand_asfix_ws(ar,w),
                 make_aterm_to_aterms_appl(ar,
                   expand_asfix_sortlist(ar,sorts))));
    return make_afun_aterms_to_aterm_appl(ar,
                                          make_sorts_appl(ar),
                                          args);
  }
  else {
    assertp(Tmatch(subsection, "priorities(<term>,<term>,<term>)",
            &lit,&w,&prios));
    args = make_aterm_aterms_to_aterms_appl(ar,
               expand_asfix_literal(ar,lit),
               make_aterm_aterms_to_aterms_appl(ar,
                 expand_asfix_ws(ar,w),
                 make_aterm_to_aterms_appl(ar,
                   expand_asfix_prioslist(ar,prios))));
    return make_afun_aterms_to_aterm_appl(ar,
                                          make_priorities_appl(ar),
                                          args);
  }
}

aterm_list *expand_asfix_subsections(arena *ar, aterm_list *subsections)
{
  aterm *subsection;
  aterm *expsubsection;
  aterm *expsubsections;

  if(!t_is_empty(subsections)) {
    subsection = t_list_first(subsections);
    subsections = t_list_next(subsections);
    if(AFisLayout(subsection))
      expsubsection = expand_asfix_ws(ar,subsection);
    else
      expsubsection = expand_asfix_subsection(ar,subsection);
    if(!t_is_empty(subsections)) {
      expsubsections = make_aterm_aterms_to_aterms_appl(ar,
                           expsubsection,
                           expand_asfix_subsections(ar,subsections));
    }
    else
      expsubsections = make_aterm_to_aterms_appl(ar,expsubsection);
  }
  return expsubsections;
}

aterm *expand_asfix_subsectionlist(arena *ar, aterm *subsectionlist)
{
  aterm_list *subsections;

  assertp(Tmatch(subsectionlist,"<list>",&subsections));
  if(t_is_empty(subsections))
    return make_atermlist_to_aterm_appl(ar,make_empty_to_atermlist_appl(ar));
  else 
    return make_atermlist_to_aterm_appl(ar,
             make_aterms_to_atermlist_appl(ar,
                expand_asfix_subsections(ar,subsections)));
}

aterm *expand_asfix_section(arena *ar, aterm *section)
{
  aterm *lit, *w, *args;
  aterm *subsections, *ids;

  if(Tmatch(section, "exports(<term>,<term>,<term>)",
            &lit,&w,&subsections)) {
    args = make_aterm_aterms_to_aterms_appl(ar,
               expand_asfix_literal(ar,lit),
               make_aterm_aterms_to_aterms_appl(ar,
                 expand_asfix_ws(ar,w),
                 make_aterm_to_aterms_appl(ar,
                   expand_asfix_subsectionlist(ar,subsections))));
    return make_afun_aterms_to_aterm_appl(ar,
                                          make_exports_appl(ar),
                                          args);
  }
  else if(Tmatch(section, "imports(<term>,<term>,<term>)",
            &lit,&w,&ids)) {
    args = make_aterm_aterms_to_aterms_appl(ar,
               expand_asfix_literal(ar,lit),
               make_aterm_aterms_to_aterms_appl(ar,
                 expand_asfix_ws(ar,w),
                 make_aterm_to_aterms_appl(ar,
                   expand_asfix_idlist(ar,ids))));
    return make_afun_aterms_to_aterm_appl(ar,
                                          make_imports_appl(ar),
                                          args);
  }
  else {
    assertp(Tmatch(section, "hiddens(<term>,<term>,<term>)",
            &lit,&w,&subsections));
    args = make_aterm_aterms_to_aterms_appl(ar,
               expand_asfix_literal(ar,lit),
               make_aterm_aterms_to_aterms_appl(ar,
                 expand_asfix_ws(ar,w),
                 make_aterm_to_aterms_appl(ar,
                   expand_asfix_subsectionlist(ar,subsections))));
    return make_afun_aterms_to_aterm_appl(ar,
                                          make_imports_appl(ar),
                                          args);
  }
}

aterm *expand_asfix_sections(arena *ar, aterm_list *sections)
{
  aterm *section;
  aterm *expsection;
  aterm *expsections;

  if(!t_is_empty(sections)) {
    section = t_list_first(sections);
    sections = t_list_next(sections);
    if(AFisLayout(section))
      expsection = expand_asfix_ws(ar,section);
    else
      expsection = expand_asfix_section(ar,section);
    if(!t_is_empty(sections)) {
      expsections = make_aterm_aterms_to_aterms_appl(ar,
                         expsection,
                         expand_asfix_sections(ar,sections));
    }
    else
      expsections = make_aterm_to_aterms_appl(ar,expsection);
  }
  return expsections;
}

aterm *expand_asfix_sectionlist(arena *ar, aterm *sectionlist)
{
  aterm_list *sections;

  assertp(Tmatch(sectionlist,"<list>",&sections));
  if(t_is_empty(sections))
    return make_atermlist_to_aterm_appl(ar,make_empty_to_atermlist_appl(ar));
  else 
    return make_atermlist_to_aterm_appl(ar,
             make_aterms_to_atermlist_appl(ar,
               expand_asfix_sections(ar,sections)));
}

aterm *expand_asfix_cond(arena *ar, aterm *cond)
{
  aterm *lhs,*rhs,*w[2],*l;
  aterm *args;

  assertp(Tmatch(cond,"condition(<term>,<term>,<term>,<term>,<term>)",
                 &lhs,&w[0],&l,&w[1],&rhs));
  args = make_aterm_aterms_to_aterms_appl(ar,
           expand_asfix_term(ar,lhs),
           make_aterm_aterms_to_aterms_appl(ar,
             expand_asfix_ws(ar,w[0]),
             make_aterm_aterms_to_aterms_appl(ar,
               expand_asfix_literal(ar,l),
               make_aterm_aterms_to_aterms_appl(ar,
                 expand_asfix_ws(ar,w[1]),
                 make_aterm_to_aterms_appl(ar,
                   expand_asfix_term(ar,rhs))))));
  return make_afun_aterms_to_aterm_appl(ar,
                                        make_condition_appl(ar),
                                        args);
}

aterm *expand_asfix_conds(arena *ar, aterm_list *conds)
{
  aterm *cond;
  aterm *expcond;
  aterm *expconds;

  if(!t_is_empty(conds)) {
    cond = t_list_first(conds);
    conds = t_list_next(conds);
    if(AFisLayout(cond))
      expcond = expand_asfix_ws(ar,cond);
    else if(is_sep(cond))
      expcond = expand_asfix_sep(ar,cond);
    else
      expcond = expand_asfix_cond(ar,cond);
    if(!t_is_empty(conds)) {
      expconds = make_aterm_aterms_to_aterms_appl(ar,
                         expcond,
                         expand_asfix_conds(ar,conds));
    }
    else
      expconds = make_aterm_to_aterms_appl(ar,expcond);
  }
  return expconds;
}

aterm *expand_asfix_condslist(arena *ar, aterm *condslist)
{
  aterm_list *conds;

  assertp(Tmatch(condslist,"<list>",&conds));
  if(t_is_empty(conds))
    return make_atermlist_to_aterm_appl(ar,make_empty_to_atermlist_appl(ar));
  else
    return make_atermlist_to_aterm_appl(ar,
             make_aterms_to_atermlist_appl(ar,
               expand_asfix_conds(ar,conds)));
}

aterm *expand_asfix_equation(arena *ar, aterm *equation)
{
  aterm *id,*l[3],*w[6],*lhs,*rhs,*conds;
  aterm *args,*res;
  arena local;

  TinitArena(t_world(*ar), &local); 
  if(Tmatch(equation, "ceq-equ(<term>,<term>,<term>,<term>,<term>,<term>," \
                               "<term>,<term>,<term>)",
            &id,&w[0],&l[0],&w[1],&lhs,&w[2],&l[1],&w[3],&rhs)) {
    args = make_aterm_aterms_to_aterms_appl(&local,
             expand_asfix_id(&local,id),
             make_aterm_aterms_to_aterms_appl(&local,
               expand_asfix_ws(&local,w[0]),
               make_aterm_aterms_to_aterms_appl(&local,
                 expand_asfix_literal(&local,l[0]),
                 make_aterm_aterms_to_aterms_appl(&local,
                   expand_asfix_ws(&local,w[1]),
                   make_aterm_aterms_to_aterms_appl(&local,
                     expand_asfix_term(&local,lhs),
                     make_aterm_aterms_to_aterms_appl(&local,
                       expand_asfix_ws(&local,w[2]),
                       make_aterm_aterms_to_aterms_appl(&local,
                         expand_asfix_literal(&local,l[1]),
                         make_aterm_aterms_to_aterms_appl(&local,
                           expand_asfix_ws(&local,w[3]),
                           make_aterm_to_aterms_appl(&local,
                             expand_asfix_term(&local,rhs))))))))));
    res = make_afun_aterms_to_aterm_appl(&local,
                                         make_ceqequ_appl(&local),
                                         args);
  }
  else if(Tmatch(equation,"ceq-impl(<term>,<term>,<term>,<term>,<term>," \
                                    "<term>,<term>,<term>,<term>,<term>," \
                                    "<term>,<term>,<term>)",
                 &id,&w[0],&l[0],&w[1],&conds,
                 &w[2],&l[1],&w[3],&lhs,&w[4],
                 &l[2],&w[5],&rhs)) {
    args = make_aterm_aterms_to_aterms_appl(&local,
             expand_asfix_id(&local,id),
             make_aterm_aterms_to_aterms_appl(&local,
               expand_asfix_ws(&local,w[0]),
               make_aterm_aterms_to_aterms_appl(&local,
                 expand_asfix_literal(&local,l[0]),
                 make_aterm_aterms_to_aterms_appl(&local,
                   expand_asfix_ws(&local,w[1]),
                   make_aterm_aterms_to_aterms_appl(&local,
                     expand_asfix_condslist(&local,conds),
                     make_aterm_aterms_to_aterms_appl(&local,
                       expand_asfix_ws(&local,w[2]),
                       make_aterm_aterms_to_aterms_appl(&local,
                         expand_asfix_literal(&local,l[1]),
                         make_aterm_aterms_to_aterms_appl(&local,
                           expand_asfix_ws(&local,w[3]),
                           make_aterm_aterms_to_aterms_appl(&local,
                             expand_asfix_term(&local,lhs),
                             make_aterm_aterms_to_aterms_appl(&local,
                               expand_asfix_ws(&local,w[4]),
                               make_aterm_aterms_to_aterms_appl(&local,
                                 expand_asfix_literal(&local,l[2]),
                                 make_aterm_aterms_to_aterms_appl(&local,
                                   expand_asfix_ws(&local,w[5]),
                                   make_aterm_to_aterms_appl(&local,
                                     expand_asfix_term(&local,rhs))))))))))))));
    res = make_afun_aterms_to_aterm_appl(&local,
                                         make_ceqimpl_appl(&local),
                                         args);
  }
  else {
    assertp(Tmatch(equation,"ceq-when(<term>,<term>,<term>,<term>,<term>," \
                                    "<term>,<term>,<term>,<term>,<term>," \
                                    "<term>,<term>,<term>)",
                 &id,&w[0],&l[0],&w[1],&lhs,
                 &w[2],&l[1],&w[3],&rhs,&w[4],
                 &l[2],&w[5],&conds));
    args = make_aterm_aterms_to_aterms_appl(&local,
             expand_asfix_id(&local,id),
             make_aterm_aterms_to_aterms_appl(&local,
               expand_asfix_ws(&local,w[0]),
               make_aterm_aterms_to_aterms_appl(&local,
                 expand_asfix_literal(&local,l[0]),
                 make_aterm_aterms_to_aterms_appl(&local,
                   expand_asfix_ws(&local,w[1]),
                   make_aterm_aterms_to_aterms_appl(&local,
                    expand_asfix_term(&local,lhs),
                     make_aterm_aterms_to_aterms_appl(&local,
                       expand_asfix_ws(&local,w[2]),
                       make_aterm_aterms_to_aterms_appl(&local,
                         expand_asfix_literal(&local,l[1]),
                         make_aterm_aterms_to_aterms_appl(&local,
                           expand_asfix_ws(&local,w[3]),
                           make_aterm_aterms_to_aterms_appl(&local,
                             expand_asfix_term(&local,rhs),
                             make_aterm_aterms_to_aterms_appl(&local,
                               expand_asfix_ws(&local,w[4]),
                               make_aterm_aterms_to_aterms_appl(&local,
                                 expand_asfix_literal(&local,l[2]),
                                 make_aterm_aterms_to_aterms_appl(&local,
                                   expand_asfix_ws(&local,w[5]),
                                   make_aterm_to_aterms_appl(&local,
                                     expand_asfix_condslist(&local,conds))))))))))))));
    res = make_afun_aterms_to_aterm_appl(&local,
                                         make_ceqwhen_appl(&local),
                                         args);
  }
  Tadd2Arena(ar,res);
  TdestroyArena(&local);
  return res;
}

aterm *expand_asfix_equations(arena *ar, aterm_list *equations)
{
  aterm *equation;
  aterm *expequation;
  aterm *expequations;

  if(!t_is_empty(equations)) {
    equation = t_list_first(equations);
    equations = t_list_next(equations);
    if(AFisLayout(equation))
      expequation = expand_asfix_ws(ar,equation);
    else
      expequation = expand_asfix_equation(ar,equation);
    if(!t_is_empty(equations)) {
      expequations = make_aterm_aterms_to_aterms_appl(ar,
                         expequation,
                         expand_asfix_equations(ar,equations));
    }
    else
      expequations = make_aterm_to_aterms_appl(ar,expequation);
  }
  return expequations;
}

aterm *expand_asfix_equationlist(arena *ar, aterm *equationlist)
{
  aterm_list *equations;

  assertp(Tmatch(equationlist,"<list>",&equations));
  if(t_is_empty(equations))
    return make_atermlist_to_aterm_appl(ar,make_empty_to_atermlist_appl(ar));
  else
    return make_atermlist_to_aterm_appl(ar,
             make_aterms_to_atermlist_appl(ar,
               expand_asfix_equations(ar,equations)));
}

aterm *expand_asfix_equationssection(arena *ar, aterm *equations)
{
  aterm *l,*w,*eqs;
  aterm *args;

  if(Tmatch(equations,"no-equations"))
    return make_afun_to_aterm_appl(ar,make_noequations_appl(ar));
  else {
    assertp(Tmatch(equations,"equations(<term>,<term>,<term>)",
                   &l,&w,&eqs));
    args = make_aterm_aterms_to_aterms_appl(ar,
             expand_asfix_literal(ar,l),
             make_aterm_aterms_to_aterms_appl(ar,
               expand_asfix_ws(ar,w),
               make_aterm_to_aterms_appl(ar,
                 expand_asfix_equationlist(ar,eqs))));
    return make_afun_aterms_to_aterm_appl(ar,
                                          make_equations_appl(ar),
                                          args);
  }
}

aterm *expand_asfix_module(arena *ar, aterm *mod)
{
  aterm *lit, *w[4], *id, *equations, *sections;
  aterm *args;

  assertp(Tmatch(mod,
                 "module(<term>,<term>,<term>,<term>,<term>," \
                         "<term>,<term>,<term>,<term>)",
                 &lit,&w[0],&id,&w[1],&sections,&w[2],&equations,&w[3],NULL));
  args = make_aterm_aterms_to_aterms_appl(ar,
           expand_asfix_literal(ar,lit),
           make_aterm_aterms_to_aterms_appl(ar,
             expand_asfix_ws(ar,w[0]),
             make_aterm_aterms_to_aterms_appl(ar,
               expand_asfix_id(ar,id),
               make_aterm_aterms_to_aterms_appl(ar,
                 expand_asfix_ws(ar,w[1]),
                 make_aterm_aterms_to_aterms_appl(ar,
                   expand_asfix_sectionlist(ar,sections),
                   make_aterm_aterms_to_aterms_appl(ar,
                     expand_asfix_ws(ar,w[2]),
                     make_aterm_aterms_to_aterms_appl(ar,
                       expand_asfix_equationssection(ar,equations),
                       make_aterm_aterms_to_aterms_appl(ar,
                         expand_asfix_ws(ar,w[3]),
                           make_aterm_to_aterms_appl(ar,
                             make_empty_abbreviations(ar))))))))));
  return make_afun_aterms_to_aterm_appl(ar,
                                        make_module_appl(ar),
                                        args);
}

aterm *make_term(arena *ar,char *name,aterm *mod)
{
  aterm *esp, *aname, *idname, *fname, *osym, *csym, *cprod, *cappl;

  esp = TmakeSimple(ar, "w(\"\")");
  aname  = Tmake(ar,"l(<str>)",name);
  idname = TmakeSimple(ar,"id(\"AsFix2Epic\")");
  fname = TmakeSimple(ar,"l(\"asfix2epic\")");
  osym = TmakeSimple(ar,"l(\"(\")");
  csym = TmakeSimple(ar,"l(\")\")");
  cprod = AFmakeProd(ar,idname,
                     TmkList_n(ar,7,fname,
                                    esp,
                                    osym,
                                    esp,
                                    TmakeSimple(ar,"sort(\"ATerm\")"),
                                    esp,
                                    csym),
                     TmakeSimple(ar, "sort(\"EpModule\")"),
                     TmakeSimple(ar, "no-attrs"));
  cappl = AFmakeAppl(ar,cprod,
                     TmkList_n(ar,7,fname,
                                    esp,
                                    osym,
                                    esp,
                                    mod,
                                    esp,
                                    csym));
  return Tmake(ar,"term(<term>,<term>,<term>,<term>,<term>,<term>," \
                        "<term>,<term>,<term>)",
               TmakeSimple(ar,"l(\"term\")"),
               esp,
               aname,
               esp,
               idname,
               esp,
               cappl,
               esp,
               TmakeSimple(ar,"abbreviations([])"));
}

aterm *expand_to_asfix(arena *ar, aterm *mod, char *name)
{
  aterm *args;
  args = expand_asfix_module(ar,mod);
  return make_term(ar,name,args);
}
