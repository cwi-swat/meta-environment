#include <string.h>
#include <asfix.h>
#include <term-list.h>
#include <abbrevs.h>

#define TABLE_SIZE 2048

static aterm *term_ws;
static aterm *term_comma;
static aterm *term_open;
static aterm *term_close;
static aterm *term_square_open;
static aterm *term_square_close;
static aterm *term_sort_literal;
static aterm *term_w_appl;
static aterm *term_l_appl;
static aterm *term_ql_appl;
static aterm *term_sep_appl;
static aterm *term_id_appl;
static aterm *term_exports_appl;
static aterm *term_imports_appl;
static aterm *term_hiddens_appl;
static aterm *term_sorts_appl;
static aterm *term_sort_appl;
static aterm *term_lexicalsyntax_appl;
static aterm *term_contextfreesyntax_appl;
static aterm *term_variables_appl;
static aterm *term_priorities_appl;
static aterm *term_incrchain_appl;
static aterm *term_decrchain_appl;
static aterm *term_prodskel_appl;
static aterm *term_agroup_appl;
static aterm *term_group_appl;
static aterm *term_noequations_appl;
static aterm *term_equations_appl;
static aterm *term_ceqequ_appl;
static aterm *term_ceqimpl_appl;
static aterm *term_ceqwhen_appl;
static aterm *term_condition_appl;
static aterm *term_appl_appl;
static aterm *term_list_appl;
static aterm *term_var_appl;
static aterm *term_lex_appl;
static aterm *term_prod_appl;
static aterm *term_iter_appl;
static aterm *term_itersep_appl;
static aterm *term_neg_appl;
static aterm *term_charclass_appl;
static aterm *term_noattrs_appl;
static aterm *term_attrs_appl;
static aterm *term_module_appl;
static aterm *term_abbreviations_appl;
static aterm *term_literal_to_afun_prod;
static aterm *term_afun_to_aterm_prod;
static aterm *term_aterm_to_aterms_prod;
static aterm *term_afun_aterms_to_aterm_prod;
static aterm *term_aterm_aterms_to_aterms_prod;
static aterm *term_atermlist_to_aterm_prod;
static aterm *term_aterms_to_atermlist_prod;
static aterm *term_empty_to_atermlist_appl;

void init_expansion_terms()
{
  arena local;
  aterm *tmp;

  TinitArena(NULL, &local);

  /* Building a white-space */
  term_ws = TmakeSimple(&local, "w(\"\")");

  /* Building a comma */
  term_comma = TmakeSimple(&local, "l(\",\")");

  /* Building an open */
  term_open = TmakeSimple(&local, "l(\"(\")");

  /* Building a close */
  term_close = TmakeSimple(&local, "l(\")\")");

  /* Building a square open */
  term_square_open = TmakeSimple(&local, "l(\"[\")");

  /* Building a square close */
  term_square_close = TmakeSimple(&local, "l(\"]\")");

  /* Building a sort Literal */
  term_sort_literal = TmakeSimple(&local, "sort(\"Literal\")");

  /* Building a white-space appl */
  tmp = AFmakeProd(&local, TmakeSimple(&local, "id(\"ParseTrees\")"),
                           TmkList_n(&local,1,
                                     TmakeSimple(&local, "ql(\"w\")")), 
                           TmakeSimple(&local, "sort(\"AFun\")"),
                           TmakeSimple(&local, "no-attrs"));
  term_w_appl = AFmakeAppl(&local, tmp, 
                           TmkList_n(&local, 1,
                                     TmakeSimple(&local, "l(\"w\")")));
 
  /* Building a literal appl */
  tmp = AFmakeProd(&local, TmakeSimple(&local, "id(\"ParseTrees\")"),
                           TmkList_n(&local,1,
                                     TmakeSimple(&local, "ql(\"l\")")),
                           TmakeSimple(&local, "sort(\"AFun\")"),
                           TmakeSimple(&local, "no-attrs"));
  term_l_appl = AFmakeAppl(&local, tmp,
                           TmkList_n(&local, 1,
                                     TmakeSimple(&local, "l(\"l\")")));

  /* Building a qliteral appl */
  tmp = AFmakeProd(&local, TmakeSimple(&local, "id(\"AsFixParseTrees\")"),
                           TmkList_n(&local,1,
                                     TmakeSimple(&local, "ql(\"ql\")")),
                           TmakeSimple(&local, "sort(\"AFun\")"),
                           TmakeSimple(&local, "no-attrs"));
  term_ql_appl = AFmakeAppl(&local, tmp,
                           TmkList_n(&local, 1,
                                     TmakeSimple(&local, "l(\"ql\")")));

  /* Building a separator appl */
  tmp = AFmakeProd(&local, TmakeSimple(&local, "id(\"ParseTrees\")"),
                           TmkList_n(&local,1,
                                     TmakeSimple(&local, "ql(\"sep\")")),
                           TmakeSimple(&local, "sort(\"AFun\")"),
                           TmakeSimple(&local, "no-attrs"));
  term_sep_appl = AFmakeAppl(&local, tmp,
                           TmkList_n(&local, 1,
                                     TmakeSimple(&local, "l(\"sep\")")));

  /* Building an identifier appl */
  tmp = AFmakeProd(&local, TmakeSimple(&local, "id(\"AsFixParseTrees\")"),
                           TmkList_n(&local,1,
                                     TmakeSimple(&local, "ql(\"id\")")),
                           TmakeSimple(&local, "sort(\"AFun\")"),
                           TmakeSimple(&local, "no-attrs"));
  term_id_appl = AFmakeAppl(&local, tmp,
                           TmkList_n(&local, 1,
                                     TmakeSimple(&local, "l(\"id\")")));

  /* Building an exports appl */
  tmp = AFmakeProd(&local, TmakeSimple(&local, "id(\"AsFixParseTrees\")"),
                           TmkList_n(&local,1,
                                     TmakeSimple(&local, "ql(\"exports\")")),
                           TmakeSimple(&local, "sort(\"AFun\")"),
                           TmakeSimple(&local, "no-attrs"));
  term_exports_appl = AFmakeAppl(&local, tmp,
                           TmkList_n(&local, 1,
                                     TmakeSimple(&local, "l(\"exports\")")));

  /* Building an imports appl */
  tmp = AFmakeProd(&local, TmakeSimple(&local, "id(\"AsFixParseTrees\")"),
                           TmkList_n(&local,1,
                                     TmakeSimple(&local, "ql(\"imports\")")),
                           TmakeSimple(&local, "sort(\"AFun\")"),
                           TmakeSimple(&local, "no-attrs"));
  term_imports_appl = AFmakeAppl(&local, tmp,
                           TmkList_n(&local, 1,
                                     TmakeSimple(&local, "l(\"imports\")")));

  /* Building a hiddens appl */
  tmp = AFmakeProd(&local, TmakeSimple(&local, "id(\"AsFixParseTrees\")"),
                           TmkList_n(&local,1,
                                     TmakeSimple(&local, "ql(\"hiddens\")")),
                           TmakeSimple(&local, "sort(\"AFun\")"),
                           TmakeSimple(&local, "no-attrs"));
  term_hiddens_appl = AFmakeAppl(&local, tmp,
                           TmkList_n(&local, 1,
                                     TmakeSimple(&local, "l(\"hiddens\")")));

  /* Building a sorts appl */
  tmp = AFmakeProd(&local, TmakeSimple(&local, "id(\"AsFixParseTrees\")"),
                           TmkList_n(&local,1,
                                     TmakeSimple(&local, "ql(\"sorts\")")),
                           TmakeSimple(&local, "sort(\"AFun\")"),
                           TmakeSimple(&local, "no-attrs"));
  term_sorts_appl = AFmakeAppl(&local, tmp,
                           TmkList_n(&local, 1,
                                     TmakeSimple(&local, "l(\"sorts\")")));

  /* Building a sort appl */
  tmp = AFmakeProd(&local, TmakeSimple(&local, "id(\"ParseTrees\")"),
                           TmkList_n(&local,1,
                                     TmakeSimple(&local, "ql(\"sort\")")),
                           TmakeSimple(&local, "sort(\"AFun\")"),
                           TmakeSimple(&local, "no-attrs"));
  term_sort_appl = AFmakeAppl(&local, tmp,
                           TmkList_n(&local, 1,
                                     TmakeSimple(&local, "l(\"sort\")")));

  /* Building a lexical-syntax appl */
  tmp = AFmakeProd(&local, TmakeSimple(&local, "id(\"AsFixParseTrees\")"),
                           TmkList_n(&local,1,
                                     TmakeSimple(&local, "ql(\"lexical-syntax\")")),
                           TmakeSimple(&local, "sort(\"AFun\")"),
                           TmakeSimple(&local, "no-attrs"));
  term_lexicalsyntax_appl = AFmakeAppl(&local, tmp,
                           TmkList_n(&local, 1,
                                     TmakeSimple(&local, "l(\"lexical-syntax\")")));

  /* Building a context-free syntax appl */
  tmp = AFmakeProd(&local, TmakeSimple(&local, "id(\"AsFixParseTrees\")"),
                           TmkList_n(&local,1,
                                     TmakeSimple(&local, "ql(\"context-free-syntax\")")),
                           TmakeSimple(&local, "sort(\"AFun\")"),
                           TmakeSimple(&local, "no-attrs"));
  term_contextfreesyntax_appl = AFmakeAppl(&local, tmp,
                           TmkList_n(&local, 1,
                                     TmakeSimple(&local, "l(\"context-free-syntax\")")));

  /* Building a variables appl */
  tmp = AFmakeProd(&local, TmakeSimple(&local, "id(\"AsFixParseTrees\")"),
                           TmkList_n(&local,1,
                                     TmakeSimple(&local, "ql(\"variables\")")),
                           TmakeSimple(&local, "sort(\"AFun\")"),
                           TmakeSimple(&local, "no-attrs"));
  term_variables_appl = AFmakeAppl(&local, tmp,
                           TmkList_n(&local, 1,
                                     TmakeSimple(&local, "l(\"variables\")")));

  /* Building a priorities appl */
  tmp = AFmakeProd(&local, TmakeSimple(&local, "id(\"AsFixParseTrees\")"),
                           TmkList_n(&local,1,
                                     TmakeSimple(&local, "ql(\"priorities\")")),
                           TmakeSimple(&local, "sort(\"AFun\")"),
                           TmakeSimple(&local, "no-attrs"));
  term_priorities_appl = AFmakeAppl(&local, tmp,
                           TmkList_n(&local, 1,
                                     TmakeSimple(&local, "l(\"priorities\")")));
  
  /* Building an incrchain appl */
  tmp = AFmakeProd(&local, TmakeSimple(&local, "id(\"AsFixParseTrees\")"),
                           TmkList_n(&local,1,
                                     TmakeSimple(&local, "ql(\"incr-chain\")")),
                           TmakeSimple(&local, "sort(\"AFun\")"),
                           TmakeSimple(&local, "no-attrs"));
  term_incrchain_appl = AFmakeAppl(&local, tmp,
                           TmkList_n(&local, 1,
                                     TmakeSimple(&local, "l(\"incr-chain\")")));
  
  /* Building a decrchain appl */ 
  tmp = AFmakeProd(&local, TmakeSimple(&local, "id(\"AsFixParseTrees\")"),
                           TmkList_n(&local,1,
                                     TmakeSimple(&local, "ql(\"decr-chain\")")),
                           TmakeSimple(&local, "sort(\"AFun\")"),
                           TmakeSimple(&local, "no-attrs"));
  term_decrchain_appl = AFmakeAppl(&local, tmp,
                           TmkList_n(&local, 1,
                                     TmakeSimple(&local, "l(\"decr-chain\")")));
  
  /* Building a prodskel appl */ 
  tmp = AFmakeProd(&local, TmakeSimple(&local, "id(\"AsFixParseTrees\")"),
                           TmkList_n(&local,1,
                                     TmakeSimple(&local, "ql(\"prod-skel\")")),
                           TmakeSimple(&local, "sort(\"AFun\")"),
                           TmakeSimple(&local, "no-attrs"));
  term_prodskel_appl = AFmakeAppl(&local, tmp,
                           TmkList_n(&local, 1,
                                     TmakeSimple(&local, "l(\"prod-skel\")")));
  
  /* Building an agroup appl */ 
  tmp = AFmakeProd(&local, TmakeSimple(&local, "id(\"AsFixParseTrees\")"),
                           TmkList_n(&local,1,
                                     TmakeSimple(&local, "ql(\"agroup\")")),
                           TmakeSimple(&local, "sort(\"AFun\")"),
                           TmakeSimple(&local, "no-attrs"));
  term_agroup_appl = AFmakeAppl(&local, tmp,
                           TmkList_n(&local, 1,
                                     TmakeSimple(&local, "l(\"agroup\")")));
  
  /* Building a group appl */ 
  tmp = AFmakeProd(&local, TmakeSimple(&local, "id(\"AsFixParseTrees\")"),
                           TmkList_n(&local,1,
                                     TmakeSimple(&local, "ql(\"group\")")),
                           TmakeSimple(&local, "sort(\"AFun\")"),
                           TmakeSimple(&local, "no-attrs"));
  term_group_appl = AFmakeAppl(&local, tmp,
                           TmkList_n(&local, 1,
                                     TmakeSimple(&local, "l(\"group\")")));
  
  /* Building a noequations appl */
  tmp = AFmakeProd(&local, TmakeSimple(&local, "id(\"AsFixParseTrees\")"),
                           TmkList_n(&local,1,
                                     TmakeSimple(&local, "ql(\"no-equations\")")),
                           TmakeSimple(&local, "sort(\"AFun\")"),
                           TmakeSimple(&local, "no-attrs"));
  term_noequations_appl = AFmakeAppl(&local, tmp,
                           TmkList_n(&local, 1,
                                     TmakeSimple(&local, "l(\"no-equations\")")));
  
  /* Building an equations appl */
  tmp = AFmakeProd(&local, TmakeSimple(&local, "id(\"AsFixParseTrees\")"),
                           TmkList_n(&local,1,
                                     TmakeSimple(&local, "ql(\"equations\")")),
                           TmakeSimple(&local, "sort(\"AFun\")"),
                           TmakeSimple(&local, "no-attrs"));
  term_equations_appl = AFmakeAppl(&local, tmp,
                           TmkList_n(&local, 1,
                                     TmakeSimple(&local, "l(\"equations\")")));
  
  /* Building a ceqequ appl */
  tmp = AFmakeProd(&local, TmakeSimple(&local, "id(\"AsFixParseTrees\")"),
                           TmkList_n(&local,1,
                                     TmakeSimple(&local, "ql(\"ceq-equ\")")),
                           TmakeSimple(&local, "sort(\"AFun\")"),
                           TmakeSimple(&local, "no-attrs"));
  term_ceqequ_appl = AFmakeAppl(&local, tmp,
                           TmkList_n(&local, 1,
                                     TmakeSimple(&local, "l(\"ceq-equ\")")));
  
  /* Building a ceqimpl appl */
  tmp = AFmakeProd(&local, TmakeSimple(&local, "id(\"AsFixParseTrees\")"),
                           TmkList_n(&local,1,
                                     TmakeSimple(&local, "ql(\"ceq-impl\")")),
                           TmakeSimple(&local, "sort(\"AFun\")"),
                           TmakeSimple(&local, "no-attrs"));
  term_ceqimpl_appl = AFmakeAppl(&local, tmp,
                           TmkList_n(&local, 1,
                                     TmakeSimple(&local, "l(\"ceq-impl\")")));
  
  /* Building a ceqwhen appl */
  tmp = AFmakeProd(&local, TmakeSimple(&local, "id(\"AsFixParseTrees\")"),
                           TmkList_n(&local,1,
                                     TmakeSimple(&local, "ql(\"ceq-when\")")),
                           TmakeSimple(&local, "sort(\"AFun\")"),
                           TmakeSimple(&local, "no-attrs"));
  term_ceqwhen_appl = AFmakeAppl(&local, tmp,
                           TmkList_n(&local, 1,
                                     TmakeSimple(&local, "l(\"ceq-when\")")));
  
  /* Building a condition appl */
  tmp = AFmakeProd(&local, TmakeSimple(&local, "id(\"AsFixParseTrees\")"),
                           TmkList_n(&local,1,
                                     TmakeSimple(&local, "ql(\"condition\")")),
                           TmakeSimple(&local, "sort(\"AFun\")"),
                           TmakeSimple(&local, "no-attrs"));
  term_condition_appl = AFmakeAppl(&local, tmp,
                           TmkList_n(&local, 1,
                                     TmakeSimple(&local, "l(\"condition\")")));

  /* Building an appl appl */
  tmp = AFmakeProd(&local, TmakeSimple(&local, "id(\"AsFixParseTrees\")"),
                           TmkList_n(&local,1,
                                     TmakeSimple(&local, "ql(\"appl\")")),
                           TmakeSimple(&local, "sort(\"AFun\")"),
                           TmakeSimple(&local, "no-attrs"));
  term_appl_appl = AFmakeAppl(&local, tmp,
                           TmkList_n(&local, 1,
                                     TmakeSimple(&local, "l(\"appl\")")));

  /* Building a list appl */
  tmp = AFmakeProd(&local, TmakeSimple(&local, "id(\"AsFixParseTrees\")"),
                           TmkList_n(&local,1,
                                     TmakeSimple(&local, "ql(\"list\")")),
                           TmakeSimple(&local, "sort(\"AFun\")"),
                           TmakeSimple(&local, "no-attrs"));
  term_list_appl = AFmakeAppl(&local, tmp,
                           TmkList_n(&local, 1,
                                     TmakeSimple(&local, "l(\"list\")")));

  /* Building a var appl */
  tmp = AFmakeProd(&local, TmakeSimple(&local, "id(\"AsFixParseTrees\")"),
                           TmkList_n(&local,1,
                                     TmakeSimple(&local, "ql(\"var\")")),
                           TmakeSimple(&local, "sort(\"AFun\")"),
                           TmakeSimple(&local, "no-attrs"));
  term_var_appl = AFmakeAppl(&local, tmp,
                           TmkList_n(&local, 1,
                                     TmakeSimple(&local, "l(\"var\")")));

  /* Building a lex appl */
  tmp = AFmakeProd(&local, TmakeSimple(&local, "id(\"AsFixParseTrees\")"),
                           TmkList_n(&local,1,
                                     TmakeSimple(&local, "ql(\"lex\")")),
                           TmakeSimple(&local, "sort(\"AFun\")"),
                           TmakeSimple(&local, "no-attrs"));
  term_lex_appl = AFmakeAppl(&local, tmp,
                           TmkList_n(&local, 1,
                                     TmakeSimple(&local, "l(\"lex\")")));

  /* Building a prod appl */
  tmp = AFmakeProd(&local, TmakeSimple(&local, "id(\"AsFixParseTrees\")"),
                           TmkList_n(&local,1,
                                     TmakeSimple(&local, "ql(\"prod\")")),
                           TmakeSimple(&local, "sort(\"AFun\")"),
                           TmakeSimple(&local, "no-attrs"));
  term_prod_appl = AFmakeAppl(&local, tmp,
                           TmkList_n(&local, 1,
                                     TmakeSimple(&local, "l(\"prod\")")));

  /* Building an iter appl */
  tmp = AFmakeProd(&local, TmakeSimple(&local, "id(\"ParseTrees\")"),
                           TmkList_n(&local,1,
                                     TmakeSimple(&local, "ql(\"iter\")")),
                           TmakeSimple(&local, "sort(\"AFun\")"),
                           TmakeSimple(&local, "no-attrs"));
  term_iter_appl = AFmakeAppl(&local, tmp,
                           TmkList_n(&local, 1,
                                     TmakeSimple(&local, "l(\"iter\")")));

  /* Building an itersep appl */
  tmp = AFmakeProd(&local, TmakeSimple(&local, "id(\"ParseTrees\")"),
                           TmkList_n(&local,1,
                                     TmakeSimple(&local, "ql(\"iter-sep\")")),
                           TmakeSimple(&local, "sort(\"AFun\")"),
                           TmakeSimple(&local, "no-attrs"));
  term_itersep_appl = AFmakeAppl(&local, tmp,
                           TmkList_n(&local, 1,
                                     TmakeSimple(&local, "l(\"iter-sep\")")));

  /* Building a neg appl */
  tmp = AFmakeProd(&local, TmakeSimple(&local, "id(\"AsFixParseTrees\")"),
                           TmkList_n(&local,1,
                                     TmakeSimple(&local, "ql(\"neg\")")),
                           TmakeSimple(&local, "sort(\"AFun\")"),
                           TmakeSimple(&local, "no-attrs"));
  term_neg_appl = AFmakeAppl(&local, tmp,
                           TmkList_n(&local, 1,
                                     TmakeSimple(&local, "l(\"neg\")")));

  /* Building a charclass appl */
  tmp = AFmakeProd(&local, TmakeSimple(&local, "id(\"AsFixParseTrees\")"),
                           TmkList_n(&local,1,
                                     TmakeSimple(&local, "ql(\"char-class\")")),
                           TmakeSimple(&local, "sort(\"AFun\")"),
                           TmakeSimple(&local, "no-attrs"));
  term_charclass_appl = AFmakeAppl(&local, tmp,
                           TmkList_n(&local, 1,
                                     TmakeSimple(&local, "l(\"char-class\")")));

  /* Building a noattrs appl */
  tmp = AFmakeProd(&local, TmakeSimple(&local, "id(\"AsFixParseTrees\")"),
                           TmkList_n(&local,1,
                                     TmakeSimple(&local, "ql(\"no-attrs\")")),
                           TmakeSimple(&local, "sort(\"AFun\")"),
                           TmakeSimple(&local, "no-attrs"));
  term_noattrs_appl = AFmakeAppl(&local, tmp,
                           TmkList_n(&local, 1,
                                     TmakeSimple(&local, "l(\"no-attrs\")")));

  /* Building an attrs appl */
  tmp = AFmakeProd(&local, TmakeSimple(&local, "id(\"AsFixParseTrees\")"),
                           TmkList_n(&local,1,
                                     TmakeSimple(&local, "ql(\"attrs\")")),
                           TmakeSimple(&local, "sort(\"AFun\")"),
                           TmakeSimple(&local, "no-attrs"));
  term_attrs_appl = AFmakeAppl(&local, tmp,
                           TmkList_n(&local, 1,
                                     TmakeSimple(&local, "l(\"attrs\")")));

  /* Building a module appl */
  tmp = AFmakeProd(&local, TmakeSimple(&local, "id(\"AsFixParseTrees\")"),
                           TmkList_n(&local,1,
                                     TmakeSimple(&local, "ql(\"module\")")),
                           TmakeSimple(&local, "sort(\"AFun\")"),
                           TmakeSimple(&local, "no-attrs"));
  term_module_appl = AFmakeAppl(&local, tmp,
                           TmkList_n(&local, 1,
                                     TmakeSimple(&local, "l(\"module\")")));

  /* Building an abbreviations appl */
  tmp = AFmakeProd(&local, TmakeSimple(&local, "id(\"AsFixParseTrees\")"),
                           TmkList_n(&local,1,
                                     TmakeSimple(&local, "ql(\"abbreviations\")")),
                           TmakeSimple(&local, "sort(\"AFun\")"),
                           TmakeSimple(&local, "no-attrs"));
  term_abbreviations_appl = AFmakeAppl(&local, tmp,
                           TmkList_n(&local, 1,
                                     TmakeSimple(&local, "l(\"abbreviations\")")));

  /* Building a literal_to_afun prod */
  term_literal_to_afun_prod = 
         AFmakeProd(&local, TmakeSimple(&local, "id(\"ATerms\")"),
                        TmkList_n(&local,1,TmakeSimple(&local, "sort(\"Literal\")")),
                        TmakeSimple(&local, "sort(\"AFun\")"),
                        TmakeSimple(&local, "no-attrs"));

  /* Building an afun_to_aterm prod */
  term_afun_to_aterm_prod = 
         AFmakeProd(&local, TmakeSimple(&local, "id(\"ATerms\")"),
                        TmkList_n(&local,1,TmakeSimple(&local, "sort(\"AFun\")")),
                        TmakeSimple(&local, "sort(\"ATerm\")"),
                        TmakeSimple(&local, "no-attrs"));

  /* Building an aterm_to_aterms prod */
  term_aterm_to_aterms_prod = 
         AFmakeProd(&local, TmakeSimple(&local, "id(\"ATerms\")"),
                        TmkList_n(&local,1,TmakeSimple(&local, "sort(\"ATerm\")")),
                        TmakeSimple(&local, "sort(\"ATerms\")"),
                        TmakeSimple(&local, "no-attrs"));

  /* Building an afun_aterms_to_aterm prod */
  term_afun_aterms_to_aterm_prod = 
         AFmakeProd(&local, TmakeSimple(&local, "id(\"ATerms\")"),
                        TmkList_n(&local,7,TmakeSimple(&local, "sort(\"AFun\")"),
                                       TmakeSimple(&local, "w(\"\")"),
                                       TmakeSimple(&local, "ql(\"(\")"),
                                       TmakeSimple(&local, "w(\"\")"),
                                       TmakeSimple(&local, "sort(\"ATerms\")"),
                                       TmakeSimple(&local, "w(\"\")"),
                                       TmakeSimple(&local, "ql(\")\")")),
                        TmakeSimple(&local, "sort(\"ATerm\")"),
                        TmakeSimple(&local, "no-attrs"));

  /* Building an aterm_aterms_to_aterms prod */
  term_aterm_aterms_to_aterms_prod = 
         AFmakeProd(&local, TmakeSimple(&local, "id(\"ATerms\")"),
                        TmkList_n(&local,5,TmakeSimple(&local, "sort(\"ATerm\")"),
                                       TmakeSimple(&local, "w(\"\")"),
                                       TmakeSimple(&local, "ql(\",\")"),
                                       TmakeSimple(&local, "w(\"\n\")"),
                                       TmakeSimple(&local, "sort(\"ATerms\")")),
                        TmakeSimple(&local, "sort(\"ATerms\")"),
                        TmakeSimple(&local, "no-attrs"));

  /* Building an atermlist_to_aterm prod */
  term_atermlist_to_aterm_prod = 
         AFmakeProd(&local, TmakeSimple(&local, "id(\"ATerms\")"),
                        TmkList_n(&local,1,TmakeSimple(&local, "sort(\"ATermList\")")),
                        TmakeSimple(&local, "sort(\"ATerm\")"),
                        TmakeSimple(&local, "no-attrs"));

  /* Building an aterms_to_atermlist prod */
  term_aterms_to_atermlist_prod = 
         AFmakeProd(&local, TmakeSimple(&local, "id(\"ATerms\")"),
                        TmkList_n(&local,5,TmakeSimple(&local, "ql(\"[\")"),
                                       TmakeSimple(&local, "w(\"\")"),
                                       TmakeSimple(&local, "sort(\"ATerms\")"),
                                       TmakeSimple(&local, "w(\"\")"),
                                       TmakeSimple(&local, "ql(\"]\")")),
                        TmakeSimple(&local, "sort(\"ATermList\")"),
                        TmakeSimple(&local, "no-attrs"));

  /* Building an empty_to_atermlist appl */
  tmp = AFmakeProd(&local, TmakeSimple(&local, "id(\"ATerms\")"),
                        TmkList_n(&local,3,TmakeSimple(&local, "ql(\"[\")"),
                                       TmakeSimple(&local, "w(\"\")"),
                                       TmakeSimple(&local, "ql(\"]\")")),
                        TmakeSimple(&local, "sort(\"ATermList\")"),
                        TmakeSimple(&local, "no-attrs"));

  term_empty_to_atermlist_appl = 
         AFmakeAppl(&local,
                    tmp,
                    TmkList_n(&local,3,TmakeSimple(&local, "l(\"[\")"),
                                   TmakeSimple(&local, "w(\"\")"),
                                   TmakeSimple(&local, "l(\"]\")")));
  Tprotect(term_ws);
  Tprotect(term_comma);
  Tprotect(term_open);
  Tprotect(term_close);
  Tprotect(term_square_open);
  Tprotect(term_square_close);
  Tprotect(term_sort_literal);
  Tprotect(term_w_appl);
  Tprotect(term_l_appl);
  Tprotect(term_ql_appl);
  Tprotect(term_sep_appl);
  Tprotect(term_id_appl);
  Tprotect(term_exports_appl);
  Tprotect(term_imports_appl);
  Tprotect(term_hiddens_appl);
  Tprotect(term_sorts_appl);
  Tprotect(term_sort_appl);
  Tprotect(term_lexicalsyntax_appl);
  Tprotect(term_contextfreesyntax_appl);
  Tprotect(term_variables_appl);
  Tprotect(term_priorities_appl);
  Tprotect(term_decrchain_appl);
  Tprotect(term_incrchain_appl);
  Tprotect(term_prodskel_appl);
  Tprotect(term_agroup_appl);
  Tprotect(term_group_appl);
  Tprotect(term_noequations_appl);
  Tprotect(term_equations_appl);
  Tprotect(term_ceqequ_appl);
  Tprotect(term_ceqwhen_appl);
  Tprotect(term_ceqimpl_appl);
  Tprotect(term_condition_appl);
  Tprotect(term_appl_appl);
  Tprotect(term_list_appl);
  Tprotect(term_var_appl);
  Tprotect(term_lex_appl);
  Tprotect(term_prod_appl);
  Tprotect(term_iter_appl);
  Tprotect(term_itersep_appl);
  Tprotect(term_neg_appl);
  Tprotect(term_charclass_appl);
  Tprotect(term_noattrs_appl);
  Tprotect(term_attrs_appl);
  Tprotect(term_module_appl);
  Tprotect(term_abbreviations_appl);
  Tprotect(term_literal_to_afun_prod);
  Tprotect(term_afun_to_aterm_prod);
  Tprotect(term_aterm_to_aterms_prod);
  Tprotect(term_afun_aterms_to_aterm_prod);
  Tprotect(term_aterm_aterms_to_aterms_prod);
  Tprotect(term_atermlist_to_aterm_prod);
  Tprotect(term_aterms_to_atermlist_prod);
  Tprotect(term_empty_to_atermlist_appl);
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

aterm *make_literal_to_afun_appl(arena *ar,aterm *arg)
{
  return AFmakeAppl(ar,
                    term_literal_to_afun_prod,
                    TmkList_n(ar,1,arg));
}

aterm *make_afun_to_aterm_appl(arena *ar,aterm *arg)
{
  return AFmakeAppl(ar,
                    term_afun_to_aterm_prod,
                    TmkList_n(ar,1,arg));
}

aterm *make_aterm_to_aterms_appl(arena *ar,aterm *arg)
{
  return AFmakeAppl(ar,
                    term_aterm_to_aterms_prod,
                    TmkList_n(ar,1,arg));
}

aterm *make_afun_aterms_to_aterm_appl(arena *ar,aterm *fun,aterm *arg)
{
  return AFmakeAppl(ar,term_afun_aterms_to_aterm_prod,
                    TmkList_n(ar,7,
                              fun,
                              term_ws,
                              term_open,
                              term_ws,
                              arg,
                              term_ws,
                              term_close));
}

aterm *make_aterm_aterms_to_aterms_appl(arena *ar,aterm *term, aterm *terms)
{
  return AFmakeAppl(ar,term_aterm_aterms_to_aterms_prod,
                    TmkList_n(ar,5,
                              term,
                              term_ws,
                              term_comma,
                              term_ws,
                              terms));
}

aterm *make_atermlist_to_aterm_appl(arena *ar,aterm *arg)
{
  return AFmakeAppl(ar,term_atermlist_to_aterm_prod,
                    TmkList_n(ar,1,arg));
}

aterm *make_aterms_to_atermlist_appl(arena *ar, aterm *args)
{
  return AFmakeAppl(ar,term_aterms_to_atermlist_prod,
                    TmkList_n(ar,5,
                              term_square_open,
                              term_ws,
                              args,
                              term_ws,
                              term_square_close));
}

aterm *make_lex(arena *ar,char *lsym)
{
  return AFmakeLex(ar,lsym,term_sort_literal);
}

aterm *make_empty_abbreviations(arena *ar)
{
  return make_afun_aterms_to_aterm_appl(ar,
           term_abbreviations_appl,
           make_aterm_to_aterms_appl(ar,
             make_atermlist_to_aterm_appl(ar,
               term_empty_to_atermlist_appl)));
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
                                        term_l_appl,
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
                                        term_ql_appl,
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
                                        term_sep_appl,
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
                                        term_iter_appl,
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
                                        term_itersep_appl,
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
                                        term_neg_appl,
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
                                        term_charclass_appl,
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
                                        term_id_appl,
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
    return  make_atermlist_to_aterm_appl(ar,term_empty_to_atermlist_appl);
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
    return make_afun_to_aterm_appl(ar,term_noattrs_appl);
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
                                          term_attrs_appl,
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
                                          term_appl_appl,
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
                                          term_list_appl,
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
                                        term_var_appl,
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
                                        term_lex_appl,
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
    return make_atermlist_to_aterm_appl(ar,term_empty_to_atermlist_appl);
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
                                        term_prodskel_appl,
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
    return make_atermlist_to_aterm_appl(ar,term_empty_to_atermlist_appl);
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
                                          term_prodskel_appl,
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
                                          term_group_appl,
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
                                          term_agroup_appl,
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
    return make_atermlist_to_aterm_appl(ar,term_empty_to_atermlist_appl);
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
               term_incrchain_appl,
               expand_asfix_chainlist(ar,chainlist));
  }
  else {
    assertp(Tmatch(prio,"decr-chain(<term>)",&chainlist));
    return make_afun_aterms_to_aterm_appl(ar,
               term_decrchain_appl,
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
    return make_atermlist_to_aterm_appl(ar,term_empty_to_atermlist_appl);
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
             term_sort_appl,make_aterm_to_aterms_appl(ar,appl));
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
    return make_atermlist_to_aterm_appl(ar,term_empty_to_atermlist_appl);
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
  result = make_afun_aterms_to_aterm_appl(ar, term_prod_appl, args);

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
    return make_atermlist_to_aterm_appl(ar,term_empty_to_atermlist_appl);
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
                                          term_lexicalsyntax_appl,
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
                                          term_contextfreesyntax_appl,
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
                                          term_variables_appl,
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
                                          term_sorts_appl,
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
                                          term_priorities_appl,
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
    return make_atermlist_to_aterm_appl(ar,term_empty_to_atermlist_appl);
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
                                          term_exports_appl,
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
                                          term_imports_appl,
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
                                          term_hiddens_appl,
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
    return make_atermlist_to_aterm_appl(ar,term_empty_to_atermlist_appl);
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
                                        term_condition_appl,
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
    return make_atermlist_to_aterm_appl(ar,term_empty_to_atermlist_appl);
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
                                         term_ceqequ_appl,
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
                                         term_ceqimpl_appl,
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
                                         term_ceqwhen_appl,
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
    return make_atermlist_to_aterm_appl(ar,term_empty_to_atermlist_appl);
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
    return make_afun_to_aterm_appl(ar,term_noequations_appl);
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
                                          term_equations_appl,
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
  return make_afun_aterms_to_aterm_appl(ar, term_module_appl, args);
}

aterm *make_term(arena *ar,char *name,aterm *mod)
{
  aterm *esp, *aname, *idname, *fname, *osym, *csym, *cprod, *cappl;

  esp = term_ws;
  aname  = Tmake(ar,"l(<str>)",name);
  idname = TmakeSimple(ar,"id(\"AsFix2Epic\")");
  fname = TmakeSimple(ar,"l(\"asfix2epic\")");
  osym = term_open;
  csym = term_close;
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
