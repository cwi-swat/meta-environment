#include <tb-tool.h>
#include <string.h>
#include <asfix.h>
#include <term-list.h>
#include <abbrevs.h>
#include <ctype.h>

char *iter2qid(aterm *iter);
Tbool isbracket(aterm *prod);

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
    return Tmake(ar,"<str>","null");

  if(t_list_next(elems)) {
    aterm_list *tail;

    if(streq(type, "iter-sep"))
      tail = t_list_next(t_list_next(t_list_next(t_list_next(elems))));
    else {
      assert(streq(type, "iter"));
      tail = t_list_next(t_list_next(elems));
    }
    return Tmake(ar,"asf-cons(<term>,<term>)", 
	                      term2rnx(ar,t_list_first(elems)), 
		              elems2rnx(ar,type, tail));
  }
  return term2rnx(ar,t_list_first(elems));
}

aterm *chars2rnx(arena *ar, char *text)
{
  if(strlen(text) == 0)
    return Tmake(ar,"<str>","null");
  if(strlen(text) == 1)
    return Tmake(ar,"<int>",text[0]);
  else {
    return Tmake(ar,"cat(<int>,<term>)",
                         text[0],
                         chars2rnx(ar,++text));
  }
}
Tbool isbracket(aterm *prod)
{
  aterm *attribs;
  aterm_list *attrs;

  assertp(Tmatch(prod,
                 "prod(<term>,<term>,<list>,<term>,<term>,<term>," \
                       "<term>,<term>,<term>)", 
                 NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,&attribs));
  if(Tmatch(attribs,"attrs(<term>,<term>,<list>,<term>,<term>)",
            NULL,NULL,&attrs,NULL,NULL)) {
    while(attrs) {
      if(Tmatch(t_list_first(attrs), "l(\"bracket\")"))
        return Ttrue;
      attrs = t_list_next(attrs);
    }
  }
  return Tfalse;
}

aterm *term2rnx(arena *ar,aterm *t)
{
  asymbol *rnxid;
  char *lex;
  aterm *sort, *itype, *prod, *ws, *ts[9];
  aterm_list *args, *elems;
  aterm *result;
 
  if(Tmatch(t,"appl(<term>,<term>,<list>)", &prod,&ws,&args)) {
    if(isbracket(prod)) {
      result = term2rnx(ar,TlistIndex(args, 3));
    }
    else {
      rnxid = AFprod2RNxSymbol(prod);
      result = TmkAppl_s(ar,rnxid, args2rnx(ar,args));
    }
  }
  else if(Tmatch(t,"list(<term>,<term>,<list>)", &itype, &ws, &elems)) {
    if(Tmatch(itype,"iter(<term>,<term>,<term>)",&ts[0],&ts[1],&ts[2])) {
      rnxid = AFiter2RNxSymbol(itype);
      result = TmkAppl_s(ar, rnxid, TmkList_n(ar,1,
                                              elems2rnx(ar,"iter", elems)));
    }
    else {
      assertp(Tmatch(itype,
                     "iter-sep(<term>,<term>,<term>,<term>,<term>,<term>," \
                               "<term>,<term>,<term>)",
              &ts[0],&ts[1],&ts[2],&ts[3],&ts[4],&ts[5],&ts[6],&ts[7],&ts[8]));
      rnxid = AFiter2RNxSymbol(itype);
      result = TmkAppl_s(ar, rnxid, TmkList_n(ar,1,
                                              elems2rnx(ar,"itersep", elems)));
    }
  }
  else if(Tmatch(t, "lex(<str>,<term>)", &lex, &sort)) {
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
  aterm *t[8], *trm;

  if(Tmatch(asfix, 
     "term(<term>,<term>,<term>,<term>,<term>,<term>,<term>,<term>,<term>)",
     &t[0], &t[1], &t[2], &t[3], &t[4], &t[5], &trm, &t[6], &t[7])) {
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
