#include <tb-tool.h>
#include <string.h>
#include <asfix.h>
#include <term-list.h>
#include <abbrevs.h>
#include <ctype.h>

aterm *pattern_asfix_prod;
aterm *pattern_asfix_appl;
aterm *pattern_asfix_list;
aterm *pattern_asfix_iter;
aterm *pattern_asfix_itersep;
aterm *pattern_asfix_lex;
aterm *pattern_asfix_term;
aterm *pattern_asfix_asfcons;
aterm *pattern_asfix_cat;
aterm *pattern_asfix_str;
aterm *pattern_asfix_int;
aterm *pattern_asfix_sort;
aterm *pattern_asfix_l;
aterm *pattern_asfix_ql;
aterm *pattern_asfix_noattrs;
aterm *pattern_asfix_attrs;
aterm *pattern_asfix_contextfreesyntax;
aterm *pattern_asfix_exports;
aterm *pattern_asfix_hiddens;
aterm *pattern_asfix_id;

void init_asfix_patterns()
{
  arena local;

  TinitArena(NULL, &local);
  pattern_asfix_prod = TmakeSimple(&local,
                              "prod(<term>,<term>,<list>,<term>,<term>," \
                                   "<term>,<term>,<term>,<term>)");
  pattern_asfix_appl = TmakeSimple(&local,
                                   "appl(<term>,<term>,<list>)");
  pattern_asfix_list = TmakeSimple(&local,
                                   "list(<term>,<term>,<list>)");
  pattern_asfix_iter = TmakeSimple(&local,
                                   "iter(<term>,<term>,<term>)");
  pattern_asfix_itersep = TmakeSimple(&local,
                                      "iter-sep(<term>,<term>,<term>," \
                                               "<term>,<term>,<term>," \
                                               "<term>,<term>,<term>)");
  pattern_asfix_lex = TmakeSimple(&local,
                                  "lex(<str>,<term>)");
  pattern_asfix_term = TmakeSimple(&local,
                                   "term(<term>,<term>,<term>," \
                                        "<term>,<term>,<term>," \
                                        "<term>,<term>,<term>)");
  pattern_asfix_asfcons = TmakeSimple(&local,
                                   "asf-cons(<term>,<term>)");
  pattern_asfix_cat = TmakeSimple(&local,"cat(<int>,<term>)");
  pattern_asfix_str = TmakeSimple(&local,"<str>");
  pattern_asfix_int = TmakeSimple(&local,"<int>");
  pattern_asfix_sort = TmakeSimple(&local,"sort(<str>)");
  pattern_asfix_l = TmakeSimple(&local,"l(<str>)");
  pattern_asfix_ql = TmakeSimple(&local,"ql(<str>)");
  pattern_asfix_noattrs = TmakeSimple(&local,"no-attrs");
  pattern_asfix_attrs = TmakeSimple(&local,
                                    "attrs(l(\"{\"),<term>,<list>," \
                                           "<term>,l(\"}\"))");
  pattern_asfix_contextfreesyntax = TmakeSimple(&local,
                                                "context-free-syntax(<term>," \
                                                "<term>,<list>)");
  pattern_asfix_exports = TmakeSimple(&local,
                                      "exports(<term>,<term>,<list>)");
  pattern_asfix_hiddens = TmakeSimple(&local,
                                      "hiddens(<term>,<term>,<list>)");
  pattern_asfix_id = TmakeSimple(&local,"id(<str>)");

  Tprotect(pattern_asfix_prod);
  Tprotect(pattern_asfix_appl);
  Tprotect(pattern_asfix_list);
  Tprotect(pattern_asfix_iter);
  Tprotect(pattern_asfix_itersep);
  Tprotect(pattern_asfix_lex);
  Tprotect(pattern_asfix_term);
  Tprotect(pattern_asfix_asfcons);
  Tprotect(pattern_asfix_cat);
  Tprotect(pattern_asfix_str);
  Tprotect(pattern_asfix_int);
  Tprotect(pattern_asfix_sort);
  Tprotect(pattern_asfix_l);
  Tprotect(pattern_asfix_ql);
  Tprotect(pattern_asfix_noattrs);
  Tprotect(pattern_asfix_attrs);
  Tprotect(pattern_asfix_contextfreesyntax);
  Tprotect(pattern_asfix_exports);
  Tprotect(pattern_asfix_hiddens);
  Tprotect(pattern_asfix_id);
  TdestroyArena(&local);
}

char *iter2qid(aterm *iter);

aterm *term2rnx(arena *ar, aterm *t);

aterm_list *args2rnx(arena *ar, aterm_list *args)
{
  aterm_list *result = t_empty(NULL);
  aterm *el;

  while(!t_is_empty(args)) {
    el = term2rnx(ar, t_list_first(args));
    if(!t_is_empty(el))
      result = TlistAppend(ar,result, el);
    args = t_list_next(args);    
  }
  return result;
}

aterm *elems2rnx(arena *ar, char *type, aterm_list *elems)
{
  if(t_is_empty(elems))
    return TmakeTerm(ar,pattern_asfix_str,"null");

  if(t_list_next(elems)) {
    aterm_list *tail;

    if(streq(type, "iter-sep"))
      tail = t_list_next(t_list_next(t_list_next(t_list_next(elems))));
    else {
      assert(streq(type, "iter"));
      tail = t_list_next(t_list_next(elems));
    }
    return TmakeTerm(ar,pattern_asfix_asfcons, 
	             term2rnx(ar,t_list_first(elems)), 
		     elems2rnx(ar,type, tail));
  }
  return term2rnx(ar,t_list_first(elems));
}

aterm *chars2rnx(arena *ar, char *text)
{
  if(strlen(text) == 0)
    return TmakeTerm(ar,pattern_asfix_str,"null");
  if(strlen(text) == 1)
    return TmakeTerm(ar,pattern_asfix_int,text[0]);
  else {
    return TmakeTerm(ar,pattern_asfix_cat,
                     text[0],
                     chars2rnx(ar,++text));
  }
}

aterm *term2rnx(arena *ar,aterm *t)
{
  asymbol *rnxid;
  char *lex;
  aterm *sort, *itype, *prod, *ws;
  aterm_list *args, *elems;
  aterm *result;
 
  if(TmatchTerm(t,pattern_asfix_appl, &prod,&ws,&args)) {
    if(AFisBracketFunc(prod)) {
      result = term2rnx(ar,TlistIndex(args, 3));
    }
    else {
      rnxid = AFprod2RNxSymbol(prod);
      result = TmkAppl_s(ar,rnxid, args2rnx(ar,args));
    }
  }
  else if(TmatchTerm(t,pattern_asfix_list, &itype, &ws, &elems)) {
    if(TmatchTerm(itype,pattern_asfix_iter,NULL,NULL,NULL)) {
      rnxid = AFiter2RNxSymbol(itype);
      result = TmkAppl_s(ar, rnxid, TmkList_n(ar,1,
                                              elems2rnx(ar,"iter", elems)));
    }
    else {
      assertp(TmatchTerm(itype,pattern_asfix_itersep,
                         NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL));
      rnxid = AFiter2RNxSymbol(itype);
      result = TmkAppl_s(ar, rnxid, TmkList_n(ar,1,
                                              elems2rnx(ar,"itersep", elems)));
    }
  }
  else if(TmatchTerm(t,pattern_asfix_lex, &lex, &sort)) {
    rnxid = AFsort2RNxSymbol(sort);
    result = TmkAppl_s(ar,rnxid,
                       Tmake(ar,"[\"{CHAR}\"(<term>)]",chars2rnx(ar,lex)));
  }
  else 
    result = t_empty(NULL);
  return result;
}

aterm *asfix2rnx(arena *ar,aterm *asfix)
{
  aterm *trm;

  if(TmatchTerm(asfix, pattern_asfix_term,
            NULL, NULL, NULL, NULL, NULL, NULL, &trm, NULL, NULL)) {
    return term2rnx(ar,trm);
  } else {
    Tprintf(stderr, "not an asfix term: %t\n", asfix);
    exit(1);
  }
}

static char *rnx_char[256] = 
{
  "\\000", "\\001", "\\002", "\\003", "\\004", "\\005", "\\006", "\\007", 
  "\\008", "\\t",   "\\n",
  "\\011", "\\012", "\\r", "\\014", "\\015", "\\016", "\\017", "\\018",
  "\\019", "\\020", "\\021", "\\022", "\\023", "\\024", "\\025", "\\026", 
  "\\027", 
  "\\028", "\\029", "\\030", "\\031",
  "' ", "'!", "'\"", "'#", "'$", "'%", "'&", "''", "'(", "')", "'*", "'+", 
  "',", "'-", "'.", "'/", 
  "'0", "'1", "'2", "'3",  "'4", "'5", "'6", "'7", "'8", "'9",
  "':", "';", "'<", "'=",  "'>", "'?", "'@", 
  "'A", "'B", "'C", "'D",  "'E", "'F", "'G", "'H", "'I", "'J", 
  "'K", "'L", "'M", "'N", "'O", "'P", 
  "'Q", "'R", "'S", "'T",  "'U", "'V", "'W", "'X", "'Y", "'Z",
  "'[", "\\\\", "']", "'^", "'_",  "'`", 
  "'a", "'b", "'c", "'d",  "'e", "'f", "'g", "'h", "'i", "'j", 
  "'k", "'l", "'m", "'n", "'o", "'p", 
  "'q", "'r", "'s", "'t",  "'u", "'v", "'w", "'x", "'y", "'z",
  "'{", "'|", "'}", "'~", 
  "--",  "--",  "--",  "--",  "--",  "--",  "--",  "--",
  "--",  "--",  "--",  "--",  "--",  "--",  "--",  "--",
  "--",  "--",  "--",  "--",  "--",  "--",  "--",  "--",
  "--",  "--",  "--",  "--",  "--",  "--",  "--",  "--",
  "--",  "--",  "--",  "--",  "--",  "--",  "--",  "--",
  "--",  "--",  "--",  "--",  "--",  "--",  "--",  "--",
  "--",  "--",  "--",  "--",  "--",  "--",  "--",  "--",
  "--",  "--",  "--",  "--",  "--",  "--",  "--",  "--",
  "--",  "--",  "--",  "--",  "--",  "--",  "--",  "--",
  "--",  "--",  "--",  "--",  "--",  "--",  "--",  "--",
  "--",  "--",  "--",  "--",  "--",  "--",  "--",  "--",
  "--",  "--",  "--",  "--",  "--",  "--",  "--",  "--",
  "--",  "--",  "--",  "--",  "--",  "--",  "--",  "--",
  "--",  "--",  "--",  "--",  "--",  "--",  "--",  "--",
  "--",  "--",  "--",  "--",  "--",  "--",  "--",  "--",
  "--",  "--",  "--",  "--",  "--",  "--",  "--",  "--"
};

void pp_rnx(FILE *f, aterm *t, int indent);

void pp_list(FILE *f, aterm_list *l, int indent)
{
    while(!t_is_empty(l)) {
      pp_rnx(f, t_list_first(l), indent);
      l = t_list_next(l);
      if(!t_is_empty(l))
        Tprintf(f, ",\n");
    }
}

void pp_rnx(FILE *f, aterm *t, int indent)
{
  aterm_list *args;
  char *text;
  int i;

  if(t_is_appl(t)) {
    args = t_appl_args(t);
    text = t_sym_name(t_appl_sym(t));
    if(t_sym_string(t_appl_sym(t))) {
      fprintf(f,"\"");
      for(i=0; text[i]; i++) {
        switch(text[i]) {
          case '"': 
          case '\\': 
            fprintf(f,"%c",'\\');
          default:
            fprintf(f,"%c",text[i]);
        }
      }
      fprintf(f,"\"");
    }
    else 
      Tprintf(f,"%s",text);
    if(!t_is_empty(args)) {
      Tprintf(f,"(\n");
      pp_list(f, t_appl_args(t),indent++);
      Tprintf(f,")");
    } 
  }
  else if(t_is_int(t)) {
    char *ch = rnx_char[t_int_val(t)];
    Tprintf(f,"%s",ch);
  }
  else Tprintf(f,"Illegal term: %t\n",t);
}
