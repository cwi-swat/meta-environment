#line 67 "arm-adapter.c.nw"
/*#include <arm.h>*/
#include <codemem.h>
#include <TB.h>
#include "arm.tif.c"

#define MAX_SYMBOL_SIZE 4096
static char buf[MAX_SYMBOL_SIZE];

int TBcid;
unsigned long MAXSIZE = 20*1024*1024;
static fun v_pair;

typedef struct variable
{
  struct variable *next;
  term *var;
  term *val;
} variable;

variable *vars = NULL;

#line 120 "arm-adapter.c.nw"
char *char_table[] =
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
  "'{", "'|", "'}", "'~", "-"
};
#line 147 "arm-adapter.c.nw"
term_list *mappings = NULL;
term_list *reverse_mappings = NULL;

#line 733 "arm-adapter.c.nw"
void assign(term *var, term *val)
{
  variable *cur = vars;

  while(cur) {
    if(term_equal(cur->var, var)) {
      cur->val = val;
      return;
    }
    cur = cur->next;
  }
  cur = malloc(sizeof(variable));
  if(!cur) {
    fprintf(stderr, "out of memory in assign\n");
    exit(1);
  }
  cur->next = vars;
  vars = cur;
  cur->var = var;
  cur->val = val;
  TBprotect(&cur->var);
  TBprotect(&cur->val);
}
#line 921 "arm-adapter.c.nw"
term *value(term *var)
{
  variable *cur = vars;

  while(cur) {
    if(term_equal(cur->var, var))
      return cur->val;
    cur = cur->next;
  }
  return NULL;
}
#line 859 "arm-adapter.c.nw"
term_list *substitute_list(term_list *l);

term *substitute(term *t)
{
  term *t2;

  if(tkind(t) == t_placeholder)
    return value(t);
  
  switch(tkind(t))
  {
    case t_bool:
    case t_int:
    case t_real:
    case t_str:
    case t_bstr:	return t;


    case t_var:		return mk_var_idx(var_sym(t), substitute(var_type(t)));
			break;
    case t_appl:	t2 = mk_appl(fun_sym(t), substitute_list(fun_args(t)));
			fun_str_sym(t2) = fun_str_sym(t);
			break;
    case t_anno:	return mk_anno(substitute(anno_term(t)), substitute(anno_val(t)));
			break;
    case t_list:	return substitute_list(t);
			break;

    default:		TBmsg("term type not supported: %t\n", t);
			break;
  }
}
#line 900 "arm-adapter.c.nw"
term_list *substitute_list(term_list *l)
{
  term_list *result = l;

  while(l) {
    list_first(l) = substitute(list_first(l));
    l = list_next(l);
  }

  return result;
}
#line 941 "arm-adapter.c.nw"
TBbool del_var(term *var)
{
  variable *cur = vars, *prev = NULL;

  while(cur) {
    if(term_equal(cur->var, var)) {
      if(prev)
        prev->next = cur->next;
      else
        vars = cur->next;
      TBunprotect(&cur->var);
      TBunprotect(&cur->val);
      free(cur);
      return TBtrue;
    }
    cur = cur->next;
  }
  return TBfalse;
}
#line 763 "arm-adapter.c.nw"
term *apply_mappings(term *t, term_list *mappings);

#line 785 "arm-adapter.c.nw"
term *str_apply_mappings(term *t, term_list *mappings)
{
  term *val;

  val = list_get(mappings, t);
  if(!val)
    return t;
  return val;
}
#line 802 "arm-adapter.c.nw"
term *list_apply_mappings(term_list *l, term_list *mappings);
term *appl_apply_mappings(term *t, term_list *mappings)
{
  sym_idx fun = fun_sym(t);
  term_list *args = fun_args(t);
  TBbool str_sym = fun_str_sym(t);
  term *key, *val;

  assert(tkind(t) == t_appl);

  key = mk_appl(fun, NULL);
  fun_str_sym(key) = str_sym;
  val = list_get(mappings, key);
  if(val) {
    args = list_apply_mappings(args, mappings);
    if(tkind(val) == t_appl) {
      t = mk_appl(fun_sym(val), args);
      fun_str_sym(t) = fun_str_sym(val);
    } else {
      assert(tkind(val) == t_str);
      t = TB_make("<appl>", str_val(val), args);
      fun_str_sym(t) = TBtrue;      
    }
  }
  return t;
}
#line 836 "arm-adapter.c.nw"
term *list_apply_mappings(term_list *l, term_list *mappings)
{
  term *el, *tail, *result;

  if(l) {
    el = apply_mappings(list_first(l), mappings);
    tail = list_apply_mappings(list_next(l), mappings);
    if(el != list_first(l) || tail != list_next(l))
      return mk_list(el, tail);
  }
  return l;
}

#line 769 "arm-adapter.c.nw"
term *apply_mappings(term *t, term_list *mappings)
{
  switch(tkind(t)) {
    case t_str:		return str_apply_mappings(t, mappings);
    case t_appl:	return appl_apply_mappings(t, mappings);
    case t_list:	return list_apply_mappings(t, mappings);
    default: assert(0);
  }
}

#line 183 "arm-adapter.c.nw"
void clear_arm(int cid)
{
  ARM_clear();
}
#line 193 "arm-adapter.c.nw"
void load_mappings(int cid, term_list *maps)
{
  term *map;

  mappings = maps;
  reverse_mappings = NULL;

  while(maps) {
    map = list_first(maps);
    maps = list_next(maps);
    reverse_mappings = list_concat_term(reverse_mappings, 
					list_reverse(list_copy(map)));
  }

  TBprintf(stderr, "mappings = %t, reverse = %t\n", mappings, reverse_mappings);
}
#line 263 "arm-adapter.c.nw"
int try_load_arm(char *path)
{
  FILE *f;

  f = fopen(path, "r");
  fclose(f);
  if(f) {
    ARM_load_arm_file(path);
    /*fprintf(stderr, "ARM file %s loaded\n", path);*/
    return 1;
  }
  return 0;
}

#line 220 "arm-adapter.c.nw"
term *load_arm(int cid, term_list *files, term_list *dirs)
{
  term *file, *dir;
  term_list *filelist, *dirlist;
  char *filename, *dirname;
  TBbool loaded;

  filelist = files;
  while(filelist) {
    file = list_first(filelist);
    filelist = list_next(filelist);
    if(!TB_match(file, "<str>", &filename))
      return TB_make("snd-value(load-arm(<list>,<list>,failure(<str>)))",
		files, dirs, "list of filenames expected");
    if(filename[0] == '/') {
      if(try_load_arm(filename) < 0)
        return TB_make("snd-value(load-arm(<list>,<list>,failure(<str>)))",
		files, dirs, TBsprintf("couldn't load file: %s", filename));
    } else {
      dirlist = dirs;
      loaded = TBfalse;
      while(dirlist && !loaded) {
        dir = list_first(dirlist);
        dirlist = list_next(dirlist);
        if(!TB_match(dir, "<str>", &dirname))
	  return TB_make("snd-value(load-arm(<list>,<list>,failure(<str>)))",
			files, dirs, "list of directories expected");
        if(try_load_arm(TBsprintf("%s/%s", dirname, filename)) > 0)
          loaded = TBtrue;
      }
      if(!loaded) {
        static char error[256];
	sprintf(error, "couldn't load file: %s\n", filename);
        return TB_make("snd-value(load-arm(<list>,<list>,failure(<str>)))",
						        files, dirs, error);
      }
    }
  }
  return TB_make("snd-value(load-arm(<list>,<list>,ok))", files, dirs);
}
#line 284 "arm-adapter.c.nw"
void link_arm(int cid)
{
  ARM_link();
}
#line 365 "arm-adapter.c.nw"
void push_symbol(char *fun)
{
  int i = 1;

  buf[0] = '"';
  while(*fun) {
    switch(*fun) {
      case '"':
      case '\\':
		buf[i++] = '\\';
    }
    buf[i++] = *fun++;
  }
  buf[i++] = '"';
  buf[i++] = '\0';
  ARM_push(buf);
}
#line 459 "arm-adapter.c.nw"
term *tb_term(char *id, term_list *args)
{
  int i;

/*  TBprintf(stderr, "tb_term: %s\n", id);*/
  if(!args) {
    if(id[2] == '\0' && id[0] == '\'' || id[0] == '\\')
      return TB_make("<int>", id[1]);
    if(id[0] == '\\' && strlen(id) == 4)
      return TB_make("<int>", atoi(&id[1]));
  }
  if(id[0] != '"')
    return TB_make("<appl>", id, args);
  id++;
  for(i=0; *id != '"'; i++, id++) {
    if(*id == '\\')
      id++;
    buf[i] = *id;
  }
  buf[i] = '\0';
/*  TBprintf(stderr, "result: %s\n", buf);*/
  return TB_make("<appl>", buf, args);
}
#line 332 "arm-adapter.c.nw"
void push_term(term *t)
{
  char *fun;
  term_list *args = NULL;
  int c;

  if(TB_match(t, "<str>", &fun)) {
    push_symbol(fun);
  } else
  if(TB_match(t, "<appl>", &fun, &args)) {
       if(fun_str_sym(t))
         push_symbol(fun);
       else
         ARM_push(fun);
       /*args = list_reverse(args);*/
       while(args) {
         push_term(list_first(args));
         args = list_next(args);
       }
  } else {
    if(TB_match(t, "<int>", &c)) {
      assert(c >= 0 && c < 128);
      ARM_push(char_table[c]);
    } else
      TBmsg("not an application or char (int): %t\n", t);
  }
}
#line 389 "arm-adapter.c.nw"
term_list *reftag_to_term(ARM_ref r);

term *ref_to_term(ARM_ref r)
{
  term *t;

  switch(tag(r)) {
    case reftag: t = list_first(reftag_to_term(r));
      break;
    case tkntag: t = tb_term(fun2hdr(tkn2fun((fun)r))->name, NULL);
      break;
    case funtag: t = tb_term(fun2hdr((fun)r)->name, NULL);
      break;
    case numtag: t = TB_make("<int>", detag(r));
      break;
    case opqtag: t = TB_make("opaque(<int>)", r);
      break;
    case nultag: t = TB_make("nul");
      break;
  }
  return t;
}
#line 417 "arm-adapter.c.nw"
term_list *reftag_to_term(ARM_ref r)
{
  char *ptr;
  term_list *args = NULL;
  int len;

  /* Descent the lhs */
  if(r->car != NUL)
    args = list_concat_term(args, ref_to_term(r->car));

  /* Descent the rhs */
  if(r->cdr != NUL) {
    if(tag(r->cdr) == reftag && r->cdr->fsym == v_pair)
      args = list_concat(args, reftag_to_term(r->cdr));
    else
      list_concat_term(args, ref_to_term(r->cdr));
    if(r->fsym == v_pair)
      return args;
  }

  /* Build an application */
  return TB_make("[<term>]", tb_term(fun2hdr(r->fsym)->name, args));
}
#line 306 "arm-adapter.c.nw"
term *reduce(int cid, term *trm)
{
  ARM_ref r;
  term *t;

  if(!TB_match(trm, "term(<term>)", &t)) {
    TBprintf(stderr, "malformed term in reduce: %t\n", t);
    exit(1);
  }
  t = apply_mappings(substitute(t), mappings);

  TBprintf(stderr, "reducing term: %t, after subst and maps: %t\n", trm, t);

  ARM_ready();
  push_term(t);
  r = ARM_reduce();
  /*ARM_display(0,r,0);*/
  t = apply_mappings(ref_to_term(r), reverse_mappings);
  return TB_make("snd-value(reduct(<term>))", t);
}

#line 535 "arm-adapter.c.nw"
TBbool check_match_list(term_list *m, term_list *l);

TBbool check_match_term(term *m, term *t)
{
  if(tkind(m) == t_placeholder) {
    return TBtrue;
  }

  if(tkind(m) != tkind(t)) {
    return TBfalse;
  }

  if(m==t)
    return TBtrue;

  switch(tkind(m)) {
    case t_bool:	return (bool_val(m) == bool_val(t));
    case t_int:		return (int_val(m) == int_val(t));
    case t_real:	return (real_val(m) == real_val(t));
    case t_str:		return streq(str_val(m), str_val(t));
    case t_bstr:	return bstr_len(m) == bstr_len(t) && 
			  memcmp(bstr_val(m), bstr_val(t), bstr_len(m)) == 0;
    case t_var:		return (var_sym(m) == var_sym(t) &&
				var_formal(m) == var_formal(t) &&
				var_result(m) == var_result(t) &&
				check_match_term(var_type(m), var_type(t)));
    case t_appl:	if(fun_sym(m) != fun_sym(t))
			  return TBfalse;
			return check_match_list(fun_args(m), fun_args(t));
    case t_anno:	return check_match_term(anno_term(m), anno_term(t))&&
			  check_match_term(anno_val(m), anno_val(t));
    case t_list:	return check_match_list(m, t);

    default:		TBmsg("term type not supported: %t\n", m);
			return TBfalse;
  }
}
#line 580 "arm-adapter.c.nw"
TBbool check_match_list(term_list *m, term_list *l)
{
  if(m == l)
    return TBtrue;
  if(m == NULL || l == NULL)
    return TBfalse;

  return check_match_term(list_first(m), list_first(l)) &&
	 check_match_list(list_next(m), list_next(l));
}
#line 596 "arm-adapter.c.nw"
void do_match_list(term_list *m, term_list *l);

void do_match_term(term *m, term *t)
{
  if(tkind(m) == t_placeholder) {
    assign(m, t);
    return;
  }

  assert(tkind(m) == tkind(t));

  switch(tkind(m)) {
    case t_bool:
    case t_int:
    case t_real:
    case t_str:
    case t_bstr:	break;

    case t_var:		do_match_term(var_type(m), var_type(t));
			break;
    case t_appl:	do_match_list(fun_args(m), fun_args(t));
			break;
    case t_anno:	do_match_term(anno_term(m), anno_term(t));
			do_match_term(anno_val(m), anno_val(t));
			break;
    case t_list:	do_match_list(m, t);
			break;

    default:		TBmsg("term type not supported: %t\n", m);
			break;
  }
}
#line 636 "arm-adapter.c.nw"
void do_match_list(term_list *m, term_list *l)
{
  if(m == NULL || l == NULL) {
    assert(m==NULL && l==NULL);
    return;
  }

  do_match_term(list_first(m), list_first(l));
  do_match_list(list_next(m), list_next(l));
}
#line 500 "arm-adapter.c.nw"
term *match(int cid, term *m, term *t)
{
  term *t2;

  t = substitute(t);

  if(TB_match(t, "reduce(<term>)", &t2)) {
    ARM_ref r;

    ARM_ready();
    push_term(t2);
    r = ARM_reduce();
    t = ref_to_term(r);
  } else if(!TB_match(t, "term(<term>)", &t)) {
    TBprintf(stderr, "malformed term in match: %t\n", t);
  }

  if(!TB_match(m, "term(<term>)", &m)) {
    TBprintf(stderr, "malformed match term: %t\n", m);
  }

  if(check_match_term(m, t)) {
    do_match_term(m, t);
    return TB_make("snd-value(match(ok))");
  } else {
    return TB_make("snd-value(match(failure))");
  } 
}
#line 656 "arm-adapter.c.nw"
term *get_value(int cid, term *t)
{
  int result;
  term *trm;

  assert(TB_match(t, "term(<term>)", &trm));
  return TB_make("snd-value(value(<term>))", substitute(t));
}
#line 671 "arm-adapter.c.nw"
void delete_value(int cid, term *v)
{
  del_var(v);
}

#line 685 "arm-adapter.c.nw"
term *arm_backdoor_handler(int cid, term *t)
{
  term *trm;
  ARM_ref r;

  if(TB_match(t, "rec-eval(<term>)", &trm)) {
    trm = apply_mappings(substitute(trm), mappings);

    ARM_ready();
    push_term(trm);
    r = ARM_reduce();
    trm = apply_mappings(ref_to_term(r), reverse_mappings);
    return TB_make("snd-value(<term>)", trm);
  }
}
#line 706 "arm-adapter.c.nw"
term *arm_backdoor_check_in_sign(int cid, term *t)
{
  return NULL;
}
#line 719 "arm-adapter.c.nw"
void rec_terminate(int cid, term *arg)
{
  exit(1);
}

#line 159 "arm-adapter.c.nw"
int main(int argc, char *argv[])
{
  extern int ARM_DBGMSK;

  /*ARM_DBGMSK = 16;  Tracing on */
  TB_init();
  TBprotect(&mappings);
  TBprotect(&reverse_mappings);

  ARM_set_up();

  xfunuse("pair",v_pair);

  TBcid = TB_parseArgs(argc, argv, arm_handler, arm_check_in_sign);
  TB_connect(TBcid);
  TB_eventloop();
}
