#include <stdio.h>
#include <tb-tool.h>
#include <string.h>
#include <asfix.h>
#include <term-list.h>
#include <abbrevs.h>
#include <ctype.h>

char *input = NULL;

extern aterm *pattern_asfix_cbo_symbol;
extern aterm *pattern_asfix_cbc_symbol;
extern aterm *pattern_asfix_plus_symbol;
extern aterm *pattern_asfix_star_symbol;
extern aterm *pattern_asfix_comma_symbol;
extern aterm *pattern_asfix_arrow_symbol;
extern aterm *pattern_asfix_ws;
extern aterm *pattern_asfix_ews;
extern aterm *pattern_asfix_nlws;
extern aterm *pattern_asfix_int;
extern aterm *pattern_asfix_cat2;
extern aterm *pattern_asfix_sort;
extern aterm *pattern_asfix_iter;
extern aterm *pattern_asfix_itersep;
extern aterm *pattern_asfix_ql;
extern aterm *pattern_asfix_l;
extern aterm *pattern_asfix_id;
extern aterm *pattern_asfix_str;
extern aterm *pattern_asfix_noattrs;
extern aterm *pattern_asfix_attrs;
extern aterm *pattern_asfix_prod;
extern aterm *pattern_asfix_asfcons;
extern aterm *pattern_asfix_list;
extern aterm *pattern_asfix_sep;
extern aterm *pattern_asfix_CHAR;
extern aterm *pattern_asfix_lex;
extern aterm *pattern_asfix_appl;

aterm *term2asfix(arena *ar, char *id, aterm_list *trms);
aterm_list *id2cfelems(arena *ar, char **elems);

void usage(char *prg)
{
  fprintf(stderr, "usage: %s [options] <inputfile> [-o <outputfile>]", prg);
  exit(1);
}

aterm_list *concat_term_with_ws(arena *ar, aterm_list *l, aterm *t)
{
  if(l)
    return TlistConcat(ar, l, TmkList_n(ar, 2, pattern_asfix_ws, t));
  else
    return TmkList_n(ar, 1, t);
}

aterm_list *concat_list_with_ws(arena *ar, aterm_list *l1, aterm_list *l2)
{
  if(l1) {
    if(l2)
      return TlistConcat(ar, l1,
                         TlistConcat(ar,
                                     TmkList_n(ar, 1, pattern_asfix_ws), l2));
    else
      return l1;
  } else
    return l2;
}

int catlen(aterm *cat)
{
  aterm *t1,*t2;
  int i;

  if(TmatchTerm(cat, pattern_asfix_cat2, &t1,&t2))
    return catlen(t1) + catlen(t2);
  if(TmatchTerm(cat, pattern_asfix_int, &i))
    return 1;

  Tprintf(stderr, "PARSE-ERROR: expected cat or <int>, got %t\n", cat);
  exit(1);
}

char *_cat2str(aterm *cat, char *ptr)
{
  int i;
  aterm *t1,*t2;

  if(TmatchTerm(cat, pattern_asfix_cat2, &t1,&t2))
    return _cat2str(t2, _cat2str(t1, ptr));
  if(TmatchTerm(cat, pattern_asfix_int, &i)) {
    *ptr++ = i;
    return ptr;
  }

  Tprintf(stderr, "PARSE-ERROR: expected cat or <int>, got %t\n", cat);
  exit(1);
}

char *cat2str(aterm *cat)
{
  int len;
  char *buf, *ptr;
  static char sbuf[1024];

  len = catlen(cat)+1;
  if(len < 1024)
    buf = sbuf;
  else
    buf = malloc(len);

  if(!buf) {
    fprintf(stderr, "out of memory (string to long?)!\n");
    exit(1);
  }
  ptr = _cat2str(cat, buf);
  *ptr = '\0';

  return buf;
}

Tbool is_cffunc(char *id)
{
  if(isupper(id[0]))
    return Ttrue;
  if(strncmp(id, "__default__", strlen("__default__")) == 0)
    return Ttrue;

  return Tfalse;
}

aterm_list *iter2cfelems(arena *ar, char **elems)
{
  char *sort_begin, c, iter, *ql_begin;
  aterm *sort, *ql, *iter_term;

  assert(**elems == '{');
  (*elems)++;
  sort_begin = *elems;  
  while(isalpha(**elems) || **elems == '-' || **elems == '_')
    (*elems)++;
  c = **elems;
  **elems = '\0';
  sort = TmakeTerm(ar, pattern_asfix_sort, sort_begin);
  **elems = c;
  if(c == '}') {
    (*elems)++;
    iter = **elems;
    (*elems)++;

    if(iter == '*')
      iter_term = TmakeTerm(ar,pattern_asfix_iter,
                            sort,
                            pattern_asfix_ws,
                            pattern_asfix_star_symbol);
    else {
      assert(iter == '+');
      iter_term = TmakeTerm(ar,pattern_asfix_iter,
                            sort,
                            pattern_asfix_ws,
                            pattern_asfix_plus_symbol);
    }
  }
  else {
    (*elems)++;
    ql_begin = *elems;
  
    while(**elems != '"') {
      if(**elems == '\\')
        (*elems)++;
      (*elems)++;
    }
    **elems = '\0';
  
    ql = TmakeTerm(ar, pattern_asfix_ql, ql_begin);

    (*elems)+=2;
    iter = **elems;

    (*elems)++;

    if(iter == '*') {
      iter_term = TmakeTerm(ar, pattern_asfix_itersep,
                            pattern_asfix_cbo_symbol, pattern_asfix_ws,
                            sort, pattern_asfix_ws,
                            ql, pattern_asfix_ws,
                            pattern_asfix_cbc_symbol, pattern_asfix_ws,
                            pattern_asfix_star_symbol);
    }
    else {
      assert(iter == '+');
      iter_term = TmakeTerm(ar, pattern_asfix_itersep,
                            pattern_asfix_cbo_symbol, pattern_asfix_ws,
                            sort, pattern_asfix_ws,
                            ql, pattern_asfix_ws,
                            pattern_asfix_cbc_symbol, pattern_asfix_ws,
                            pattern_asfix_plus_symbol);
    }
  }
  return iter_term;
}

aterm_list *qlit2cfelems(arena *ar, char **elems)
{
  aterm *lit;

  char *begin,*end = (*elems)+1;

  while(*end != '"') {
    if(*end == '\\')
      end++;
    end++;
  }
  end++;
  assert(*end == '#' || *end == '-');

  begin = end;
  end--;
  *end = '\0';
  lit = TmakeTerm(ar, pattern_asfix_ql, *elems+1);
  
  *elems = begin;

  return lit;
}

aterm_list *lit2cfelems(arena *ar,char **elems)
{
  char c;
  aterm *lit;

  char *begin,*end = strpbrk(*elems, "#>");
  begin = end;
  if(*end == '>') {
    begin--;
    end--;
  }
  c = *end;
  *end = '\0';
  lit = TmakeTerm(ar, pattern_asfix_l, *elems);
  *end = c;

  *elems = begin;

  return lit;
}

aterm_list *sort2cfelems(arena *ar, char **elems)
{
  aterm *sort;
  char c;

  char *begin,*end = strpbrk(*elems, "#>");
  begin = end;
  if(*end == '>') {
    begin--;
    end--;
  }
  c = *end;
  *end = '\0';
  sort = TmakeTerm(ar, pattern_asfix_sort, *elems);
  *end = c;

  *elems = begin;
  return sort;
}

aterm *id2sort(arena *ar, char **sort)
{
   aterm *sort_term;
   char *begin,*end = strchr(*sort, ':');
   begin = end+1;
   *end = '\0';
   sort_term = TmakeTerm(ar, pattern_asfix_sort, *sort);
   *sort = begin;
   return sort_term;
}
   
aterm *id2attrs(arena *ar, char **attrs)
{
  aterm_list *attr_list = t_empty(NULL);
  char *attr;

  if(streq(*attrs, "no-attrs")) {
    (*attrs)+=strlen("no-attrs");
    return TmakeTerm(ar, pattern_asfix_noattrs);
  }
  else {
    attr = strtok(*attrs, ",");
    do {
      if(attr_list)
	attr_list = TlistConcat(ar,attr_list, 
				TmkList_n(ar, 3,
                                          pattern_asfix_ws,
                                          pattern_asfix_comma_symbol,
                                          pattern_asfix_ws));
      attr_list = TlistAppend(ar, attr_list,
                              TmakeTerm(ar, pattern_asfix_l, attr));
    } while(attr = strtok(NULL, ","));
  }
  return TmakeTerm(ar, pattern_asfix_attrs,
                   pattern_asfix_cbo_symbol, pattern_asfix_ws,
                   attr_list,
                   pattern_asfix_ws, pattern_asfix_cbc_symbol);
}

aterm_list *id2cfelems(arena *ar, char **elems)
{
  aterm_list *result = t_empty(NULL);

  /* Check for empty alternative ( -> Sort) */
  if(**elems == '-')
    return result;

  do {
    if(!t_is_empty(result)) {
      (*elems)++;
      result = TlistAppend(ar, result, pattern_asfix_ws);
    }
    switch(**elems) {
      case '{':	result = TlistAppend(ar, result, iter2cfelems(ar, elems));
		break;

      case '"':	result = TlistAppend(ar, result, qlit2cfelems(ar, elems));
		break;

      default:	if(isupper(**elems))
		  result = TlistAppend(ar, result, sort2cfelems(ar, elems));
  	  	else
		  result = TlistAppend(ar, result, lit2cfelems(ar, elems));
    }
  } while(**elems == '#');
  return result;
}

aterm *id2cffunc(arena *ar, char *id)
{
  aterm_list *Members;
  aterm *Sort,*Attrs;
  aterm *cffunc = t_empty(NULL);
  char *mod, *Id = strdup(id);

  char *elems = strchr(Id, ':');
  *elems++ = '\0';

  if(strncmp(Id, "__default__", strlen("__default__")) == 0)
    mod = Id + strlen("__default__");
  else
    mod = Id;

  Members = id2cfelems(ar, &elems);
  *elems++;
  *elems++;
  Sort = id2sort(ar, &elems);
  Attrs = id2attrs(ar, &elems);
  cffunc = TmakeTerm(ar, pattern_asfix_prod,
                     TmakeTerm(ar, pattern_asfix_id, mod), pattern_asfix_ews,
                     Members, pattern_asfix_ews,
                     pattern_asfix_arrow_symbol, pattern_asfix_ews, 
                     Sort, pattern_asfix_ews, Attrs);

  free(Id);
  return cffunc;
}

aterm_list *asfcons2iterlist(arena *ar, aterm *asfcons, aterm *sep)
{
  aterm *t1,*t2;
  aterm_list *args = t_empty(NULL);
  char *func;

  if(Tmatch(asfcons, "null"))
    return args;

  if(TmatchTerm(asfcons, pattern_asfix_asfcons, &t1, &t2)) {
    aterm_list *result;

    result = TlistAppend(ar,
                         asfcons2iterlist(ar, t1, sep),
                         pattern_asfix_ws);
    if(sep) {
      result = TlistAppend(ar, result, sep);
      result = TlistAppend(ar, result, pattern_asfix_nlws);
    }
    result = TlistConcat(ar, result, asfcons2iterlist(ar, t2,sep));
    return result;
  } 
  else if(TmatchTerm(asfcons, pattern_asfix_str, &func)) {
    return TmkList_n(ar, 1, term2asfix(ar, func, args));
  }
  else {
    if(t_is_appl(asfcons)) {
      func = t_sym_name(t_appl_sym(asfcons));
      args = t_appl_args(asfcons);
      return TmkList_n(ar, 1, term2asfix(ar, func, args));
    }
    else {
      Tprintf(stderr, "asf-cons expected, got: %t\n", asfcons);
      exit(1);
    }
  }
}

aterm_list *trms2args(arena *ar, aterm_list *trms, aterm_list *formals)
{
  char *func, *lit;
  char *iter_func;
  aterm_list *iter_args;
  aterm_list *args = t_empty(NULL), *result = t_empty(NULL);
  aterm *arg, *formal, *term, *ws[4], *iter, *l[2], *ql, *sort;
  
  while(!t_is_empty(formals)) {
    formal = t_list_first(formals);
    if(TmatchTerm(formal, pattern_asfix_sort, &sort)) {
      term = t_list_first(trms);
      if(Tmatch(term,"<fun(<terms>)>", &func, &args) ||
         TmatchTerm(term, pattern_asfix_str, &func)) {
        arg = term2asfix(ar, func, args);
        if(arg)
          result = concat_term_with_ws(ar, result, arg);
      }
      else 
        assert(0);
      trms = t_list_next(trms);
    } 
    else if(TmatchTerm(formal, pattern_asfix_iter, &sort, &ws[0], &iter)) {

      term = t_list_first(trms);
      Tmatch(term, "<fun(<terms>)>", &iter_func, &iter_args);
      result = concat_term_with_ws(ar, result, 
		   TmakeTerm(ar, pattern_asfix_list,
                             formal, pattern_asfix_ews,
			     asfcons2iterlist(ar,
                                              t_list_first(iter_args), 
                                              t_empty(NULL))));
      trms = t_list_next(trms);
    }
    else if(TmatchTerm(formal, pattern_asfix_itersep,
                       &l[0],&ws[0],&sort,&ws[1],&ql,&ws[2],&l[1],&ws[3],&iter)) {
      char *sep;
      aterm *sep_term;
      TmatchTerm(ql, pattern_asfix_ql, &sep);
      sep_term = TmakeTerm(ar, pattern_asfix_sep, sep);

      term = t_list_first(trms);
      Tmatch(term, "<fun(<terms>)>", &iter_func, &iter_args);
      result = concat_term_with_ws(ar, result, 
                   TmakeTerm(ar, pattern_asfix_list,
                             formal, pattern_asfix_ews,
	                     asfcons2iterlist(ar,
                                              t_list_first(iter_args),
                                              sep_term)));
      trms = t_list_next(trms);
    }
    else if(TmatchTerm(formal, pattern_asfix_ql, &lit))
      result = concat_term_with_ws(ar, result,
                                   TmakeTerm(ar, pattern_asfix_l, lit));
    else if(TmatchTerm(formal, pattern_asfix_l, &lit))
      result = concat_term_with_ws(ar, result, formal);
    else {
      Tprintf(stderr, "expected application, got: %t\n", formal);
      exit(1);
    }
    formals = t_list_next(formals);
    if(!t_is_empty(formals))
      formals = t_list_next(formals);
  }
  return result;
}

aterm *lex2asfix(arena *ar, char *id, aterm_list *trms)
{
  aterm *sort, *cat, *term;
  char *lex;

  sort = TmakeTerm(ar, pattern_asfix_sort, strrchr(id, '>')+1);
  term = t_list_first(trms);
  if(TmatchTerm(term, pattern_asfix_CHAR, &cat)) {
    lex = cat2str(cat);
    return TmakeTerm(ar, pattern_asfix_lex, lex, sort);
  }
  Tprintf(stderr, "malformed term in lex2asfix: %s, %t\n", id, trms);
  exit(1);
}

aterm *term2asfix(arena *ar, char *id, aterm_list *trms)
{
  aterm *prod, *cffunc;
  aterm_list *prod_args;

  if(is_cffunc(id)) {
    cffunc = id2cffunc(ar, id);
    assertp(TmatchTerm(cffunc, pattern_asfix_prod,
                       NULL,NULL,&prod_args,NULL,NULL,NULL,NULL,NULL,NULL));
    prod = TmakeTerm(ar, pattern_asfix_appl,
                     cffunc, pattern_asfix_ews,
                     trms2args(ar, trms, prod_args));
  }
  else {
    if(streq(id, "null")) {
      prod = t_empty(NULL);
    }
    else if(islower(id[0])) {
      prod = lex2asfix(ar, id, trms);
    }
    else {
      Tprintf(stderr, "unknown term: %s(%l)\n", id, trms);
      assert(0);
    }
  }
  return prod;
}

aterm *rnx2asfix(arena *ar, aterm *rnx)
{
  char *func;
  aterm_list *args = t_empty(NULL);
  aterm *asfix;

  assertp(Tmatch(rnx, "<fun(<terms>)>", &func, &args) ||
     TmatchTerm(rnx, pattern_asfix_str, &func));
  asfix = term2asfix(ar, func, args);
  return Tmake(ar,"term(l(\"term\"),w(\" \"),l(<str>),w(\" \"),"
                  "id(\"Unknown\"),w(\" \"),<term>,w(\" \"),"
		  "abbreviations([]))", input ? input : "stdin", asfix);
}
