#include <tb-tool.h>
#include <string.h>
#include <asfix.h>
#include <term-list.h>
#include <abbrevs.h>
#include <ctype.h>

aterm *pattern_asfix_cbo_symbol;
aterm *pattern_asfix_cbc_symbol;
aterm *pattern_asfix_plus_symbol;
aterm *pattern_asfix_star_symbol;
aterm *pattern_asfix_comma_symbol;
aterm *pattern_asfix_arrow_symbol;
aterm *pattern_asfix_assign_symbol;
aterm *pattern_asfix_equal_symbol;
aterm *pattern_asfix_notequal_symbol;
aterm *pattern_asfix_ws;
aterm *pattern_asfix_ews;
aterm *pattern_asfix_nlws;
aterm *pattern_asfix_ws_pattern;
aterm *pattern_asfix_prod;
aterm *pattern_asfix_prodskel;
aterm *pattern_asfix_group;
aterm *pattern_asfix_agroup;
aterm *pattern_asfix_incrchain;
aterm *pattern_asfix_decrchain;
aterm *pattern_asfix_appl;
aterm *pattern_asfix_list;
aterm *pattern_asfix_simplelist;
aterm *pattern_asfix_iter;
aterm *pattern_asfix_itersep;
aterm *pattern_asfix_neg;
aterm *pattern_asfix_lex;
aterm *pattern_asfix_var;
/*aterm *pattern_asfix_term;*/
aterm *pattern_asfix_asfcons;
aterm *pattern_asfix_cat;
aterm *pattern_asfix_cat2;
aterm *pattern_asfix_str;
aterm *pattern_asfix_int;
aterm *pattern_asfix_sort;
aterm *pattern_asfix_l;
aterm *pattern_asfix_ql;
aterm *pattern_asfix_charclass;
aterm *pattern_asfix_sep;
aterm *pattern_asfix_noattrs;
aterm *pattern_asfix_attrs;
aterm *pattern_asfix_contextfreesyntax;
aterm *pattern_asfix_lexicalsyntax;
aterm *pattern_asfix_variables;
aterm *pattern_asfix_sorts;
aterm *pattern_asfix_priorities;
aterm *pattern_asfix_imports;
aterm *pattern_asfix_exports;
aterm *pattern_asfix_hiddens;
aterm *pattern_asfix_id;
aterm *pattern_asfix_CHAR;
aterm *pattern_asfix_ceqequ;
aterm *pattern_asfix_ceqimpl;
aterm *pattern_asfix_ceqwhen;
aterm *pattern_asfix_noequations;
aterm *pattern_asfix_equations;
aterm *pattern_asfix_condition;
aterm *pattern_asfix_module;
aterm *pattern_asfix_lexcaller;

void init_asfix_patterns()
{
  arena local;

  TinitArena(NULL, &local);
  pattern_asfix_cbo_symbol = TmakeSimple(&local,"l(\"{\")");
  pattern_asfix_cbc_symbol = TmakeSimple(&local,"l(\"}\")");
  pattern_asfix_plus_symbol = TmakeSimple(&local,"l(\"+\")");
  pattern_asfix_star_symbol = TmakeSimple(&local,"l(\"*\")");
  pattern_asfix_comma_symbol = TmakeSimple(&local,"l(\",\")");
  pattern_asfix_arrow_symbol = TmakeSimple(&local,"l(\"->\")");
  pattern_asfix_assign_symbol = TmakeSimple(&local,"l(\"=:\")");
  pattern_asfix_equal_symbol = TmakeSimple(&local,"l(\"=\")");
  pattern_asfix_notequal_symbol = TmakeSimple(&local,"l(\"!=\")");
  pattern_asfix_ws = TmakeSimple(&local,"w(\" \")");
  pattern_asfix_ews = TmakeSimple(&local,"w(\"\")");
  pattern_asfix_nlws = TmakeSimple(&local,"w(\"\n\")");
  pattern_asfix_ws_pattern = TmakeSimple(&local,"w(<str>)");
  pattern_asfix_prod = TmakeSimple(&local,
                              "prod(<term>,<term>,<list>,<term>,<term>," \
                                   "<term>,<term>,<term>,<term>)");
  pattern_asfix_prodskel = TmakeSimple(&local,
                              "prod-skel(<term>,<term>,<term>)");
  pattern_asfix_group = TmakeSimple(&local,
                              "group(<term>,<term>,<term>,<term>,<term>)");
  pattern_asfix_agroup = TmakeSimple(&local,
                              "agroup(<term>,<term>,<term>,<term>,<term>," \
                                 "<term>,<term>,<term>,<term>)");
  pattern_asfix_incrchain = TmakeSimple(&local,"incr-chain(<term>)");
  pattern_asfix_decrchain = TmakeSimple(&local,"decr-chain(<term>)");
  pattern_asfix_appl = TmakeSimple(&local,
                                   "appl(<term>,<term>,<list>)");
  pattern_asfix_list = TmakeSimple(&local,
                                   "list(<term>,<term>,<list>)");
  pattern_asfix_simplelist = TmakeSimple(&local,"<list>");
  pattern_asfix_iter = TmakeSimple(&local,
                                   "iter(<term>,<term>,<term>)");
  pattern_asfix_itersep = TmakeSimple(&local,
                                      "iter-sep(<term>,<term>,<term>," \
                                               "<term>,<term>,<term>," \
                                               "<term>,<term>,<term>)");
  pattern_asfix_neg = TmakeSimple(&local,"neg(<term>,<term>,<term>)");
  pattern_asfix_lex = TmakeSimple(&local,
                                  "lex(<str>,<term>)");
  pattern_asfix_var = TmakeSimple(&local,
                                  "var(<str>,<term>)");
/*  pattern_asfix_term = TmakeSimple(&local,
                                   "term(<term>,<term>,<term>," \
                                        "<term>,<term>,<term>," \
                                        "<term>,<term>,<term>)");*/
  pattern_asfix_asfcons = TmakeSimple(&local,
                                   "asf-cons(<term>,<term>)");
  pattern_asfix_cat = TmakeSimple(&local,"cat(<int>,<term>)");
  pattern_asfix_cat2 = TmakeSimple(&local,"cat(<term>,<term>)");
  pattern_asfix_str = TmakeSimple(&local,"<str>");
  pattern_asfix_int = TmakeSimple(&local,"<int>");
  pattern_asfix_sort = TmakeSimple(&local,"sort(<str>)");
  pattern_asfix_l = TmakeSimple(&local,"l(<str>)");
  pattern_asfix_ql = TmakeSimple(&local,"ql(<str>)");
  pattern_asfix_charclass = TmakeSimple(&local,"char-class(<str>)");
  pattern_asfix_sep = TmakeSimple(&local,"sep(<str>)");
  pattern_asfix_noattrs = TmakeSimple(&local,"no-attrs");
  pattern_asfix_attrs = TmakeSimple(&local,
                                    "attrs(<term>,<term>,<list>," \
                                           "<term>,<term>)");
  pattern_asfix_contextfreesyntax = TmakeSimple(&local,
                                                "context-free-syntax(<term>," \
                                                "<term>,<list>)");
  pattern_asfix_lexicalsyntax = TmakeSimple(&local,
                                       "lexical-syntax(<term>,<term>,<list>)");
  pattern_asfix_variables = TmakeSimple(&local,
                                       "variables(<term>,<term>,<list>)");
  pattern_asfix_sorts = TmakeSimple(&local,
                                    "sorts(<term>,<term>,<list>)");
  pattern_asfix_priorities = TmakeSimple(&local,
                                       "priorities(<term>,<term>,<list>)");
  pattern_asfix_imports = TmakeSimple(&local,
                                      "imports(<term>,<term>,<list>)");
  pattern_asfix_exports = TmakeSimple(&local,
                                      "exports(<term>,<term>,<list>)");
  pattern_asfix_hiddens = TmakeSimple(&local,
                                      "hiddens(<term>,<term>,<list>)");
  pattern_asfix_id = TmakeSimple(&local,"id(<str>)");
  pattern_asfix_CHAR = TmakeSimple(&local,"\"{CHAR}\"(<term>)");
  pattern_asfix_ceqequ = TmakeSimple(&local,
                                     "ceq-equ(<term>,<term>,<term>," \
                                     "<term>,<term>,<term>," \
                                     "<term>,<term>,<term>)");
  pattern_asfix_ceqimpl = TmakeSimple(&local,
                                     "ceq-impl(<term>,<term>,<term>," \
                                     "<term>,<term>,<term>," \
                                     "<term>,<term>,<term>,<term>," \
                                     "<term>,<term>,<term>)");
  pattern_asfix_ceqwhen = TmakeSimple(&local,
                                     "ceq-when(<term>,<term>,<term>," \
                                     "<term>,<term>,<term>," \
                                     "<term>,<term>,<term>,<term>," \
                                    "<term>,<term>,<term>)");
  pattern_asfix_noequations = TmakeSimple(&local,"no-equations");
  pattern_asfix_equations = TmakeSimple(&local,
                                        "equations(<term>,<term>,<term>)");
  pattern_asfix_condition = TmakeSimple(&local,
                                        "condition(<term>,<term>,<term>," \
                                        "<term>,<term>)");
  pattern_asfix_module = TmakeSimple(&local,
                                     "module(<term>,<term>,<term>," \
                                     "<term>,<term>,<term>," \
                                     "<term>,<term>,<term>)");
  pattern_asfix_lexcaller =
    TmakeSimple(&local,"prod(id(\"caller\"),w(\"\")," \
                             "[<term>,w(\"\"),ql(\"(\"),w(\"\")," \
                              "iter(sort(\"CHAR\"),w(\"\"),l(\"+\"))," \
                              "w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\")," \
                             "<term>,w(\"\"),no-attrs)");

  Tprotect(pattern_asfix_cbo_symbol);
  Tprotect(pattern_asfix_cbc_symbol);
  Tprotect(pattern_asfix_plus_symbol);
  Tprotect(pattern_asfix_star_symbol);
  Tprotect(pattern_asfix_comma_symbol);
  Tprotect(pattern_asfix_arrow_symbol);
  Tprotect(pattern_asfix_assign_symbol);
  Tprotect(pattern_asfix_equal_symbol);
  Tprotect(pattern_asfix_notequal_symbol);
  Tprotect(pattern_asfix_ws);
  Tprotect(pattern_asfix_ews);
  Tprotect(pattern_asfix_nlws);
  Tprotect(pattern_asfix_ws_pattern);
  Tprotect(pattern_asfix_prod);
  Tprotect(pattern_asfix_prodskel);
  Tprotect(pattern_asfix_group);
  Tprotect(pattern_asfix_agroup);
  Tprotect(pattern_asfix_incrchain);
  Tprotect(pattern_asfix_decrchain);
  Tprotect(pattern_asfix_appl);
  Tprotect(pattern_asfix_list);
  Tprotect(pattern_asfix_simplelist);
  Tprotect(pattern_asfix_iter);
  Tprotect(pattern_asfix_itersep);
  Tprotect(pattern_asfix_neg);
  Tprotect(pattern_asfix_lex);
  Tprotect(pattern_asfix_var);
  /*Tprotect(pattern_asfix_term);*/
  Tprotect(pattern_asfix_asfcons);
  Tprotect(pattern_asfix_cat);
  Tprotect(pattern_asfix_cat2);
  Tprotect(pattern_asfix_str);
  Tprotect(pattern_asfix_int);
  Tprotect(pattern_asfix_sort);
  Tprotect(pattern_asfix_l);
  Tprotect(pattern_asfix_ql);
  Tprotect(pattern_asfix_charclass);
  Tprotect(pattern_asfix_sep);
  Tprotect(pattern_asfix_noattrs);
  Tprotect(pattern_asfix_attrs);
  Tprotect(pattern_asfix_contextfreesyntax);
  Tprotect(pattern_asfix_lexicalsyntax);
  Tprotect(pattern_asfix_variables);
  Tprotect(pattern_asfix_sorts);
  Tprotect(pattern_asfix_priorities);
  Tprotect(pattern_asfix_imports);
  Tprotect(pattern_asfix_exports);
  Tprotect(pattern_asfix_hiddens);
  Tprotect(pattern_asfix_id);
  Tprotect(pattern_asfix_CHAR);
  Tprotect(pattern_asfix_condition);
  Tprotect(pattern_asfix_ceqequ);
  Tprotect(pattern_asfix_ceqimpl);
  Tprotect(pattern_asfix_ceqwhen);
  Tprotect(pattern_asfix_noequations);
  Tprotect(pattern_asfix_equations);
  Tprotect(pattern_asfix_module);
  Tprotect(pattern_asfix_lexcaller);
  TdestroyArena(&local);
}
