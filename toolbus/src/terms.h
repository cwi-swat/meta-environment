#ifndef __TERMS_H__
#define __TERMS_H__

typedef enum tkind
{
  t_term=0, t_bool, t_int, t_real, t_str, t_bstr, 
  t_var, t_placeholder, t_appl, t_env, t_list
} tkind;

#define N_TERM_KINDS t_list+1

typedef int sym_idx;

typedef struct term
{
  enum tkind     trm_kind;       /* type of term */
  TBbool         trm_mark;       /* mark bit for garbage collector */
  TBbool         trm_has_conds;  /* condition flag for atoms */
  union {
    TBbool trm_bool_val;         /* a Boolean value */
    int    trm_int_val;          /* an integer value */
    double trm_real_val;         /* a real value */
    char   *trm_str_val;         /* a string value */
    struct bstr {                /* a binary string value */
      int  trm_bstr_len;
      char *trm_bstr_val;
    } bstr;
    struct trm_var {                /* a variable */
      sym_idx    sym;           /* its symbol */
      TBbool     formal;        /* a formal? */
      TBbool     result;        /* a result variable? */
      struct term *type;        /* its type */
    } var;
    struct term *type;          /* a type */
    struct appl {               /* an application */
      sym_idx  sym;             /* its function symbol */
      struct term *args;        /* list of arguments */
    } appl;
    struct list {               /* a list */
      struct term *lst_first;
      struct term *lst_next;
    } list;
    struct env {                /* an environment entry */
      sym_idx    sym;           /* symbol of variable */
      struct term *var;         /* the variable */
      struct term *val;         /* its value */
      struct term *trm_next;        /* next entry */
    } env;
  } u;
} term;

typedef term term_list;
typedef term var;
typedef term bstr;
typedef term placeholder;
typedef term type;
typedef term env;

#define contains_pointers(t)  ((t) && ((t)->trm_kind > t_bstr))

#define tkind(t)        ((t) ? (t)->trm_kind : t_list)
#define mark(t)         (t)->trm_mark
#define has_conds(t)    (t)->trm_has_conds
#define bool_val(t)     (t)->u.trm_bool_val
#define int_val(t)      (t)->u.trm_int_val
#define real_val(t)     (t)->u.trm_real_val
#define str_val(t)      (t)->u.trm_str_val
#define bstr_val(t)     (t)->u.bstr.trm_bstr_val
#define bstr_len(t)     (t)->u.bstr.trm_bstr_len
#define var_sym(t)      (t)->u.var.sym
#define var_type(t)     (t)->u.var.type
#define var_formal(t)   (t)->u.var.formal
#define var_result(t)   (t)->u.var.result
#define placeholder_type(t) (t)->u.type
#define first(t)        (t)->u.list.lst_first
#define next(t)         (t)->u.list.lst_next
#define fun_sym(t)      (t)->u.appl.sym
#define fun_args(t)     (t)->u.appl.args
#define env_sym(t)      (t)->u.env.sym
#define env_var(t)      (t)->u.env.var
#define env_val(t)      (t)->u.env.val
#define env_next(t)     (t)->u.env.trm_next

#define is_bool(t)      (tkind(t) == t_bool)
#define is_int(t)       (tkind(t) == t_int)
#define is_real(t)      (tkind(t) == t_real)
#define is_str(t)       (tkind(t) == t_str)
#define is_bstr(t)      (tkind(t) == t_bstr)
#define is_var(t)       (tkind(t) == t_var)
#define is_result_var(t)((tkind(t) == t_var) && var_result(t))
#define is_formal(t)    ((tkind(t) == t_var) && var_formal(t))
#define is_placeholder(t)(tkind(t) == t_placeholder)
#define is_env(t)       ((t == NULL) || (tkind(t) == t_env))

#define is_appl(t)      (tkind(t) == t_appl)
#define is_list(t)      (tkind(t) == t_list)   

#define LENSPEC 8          /* size of length field for binary strings */
#define STRING_MARK '\377' /* marker for binary strings */

term      *mk_bool(TBbool);
term      *mk_int(int);
term      *mk_real(double);
term      *mk_str(char *);
term      *mk_bstr(char *, int);
var       *mk_var(char *, char *, type *);
var       *mk_var_idx(sym_idx, type *);
term      *mk_result_var(char *, char *, type *);
term      *mk_result_var_idx(sym_idx, type *);
term      *mk_formal(char *, char *, type *);
term      *mk_appl(sym_idx, term *);
term      *mk_placeholder(type *);
env       *mk_env(var *, term *, env *);

#define mk_list1(a1)                         mk_list(a1, NULL)
#define mk_list2(a1, a2)                     mk_list(a1, mk_list1(a2))
#define mk_list3(a1, a2, a3)                 mk_list(a1, mk_list2(a2, a3))
#define mk_list4(a1, a2, a3, a4)             mk_list(a1, mk_list3(a2, a3, a4))
#define mk_list5(a1, a2, a3, a4, a5)         mk_list(a1, mk_list4(a2, a3, a4, a5))
#define mk_list6(a1, a2, a3, a4, a5, a6)     mk_list(a1, mk_list5(a2, a3, a4, a5, a6))
#define mk_list7(a1, a2, a3, a4, a5, a6, a7) mk_list(a1, mk_list6(a2, a3, a4, a5, a6, a7))

#define elm1(l) first(l)
#define elm2(l) first(next(l))
#define elm3(l) first(next(next(l)))
#define elm4(l) first(next(next(next(l))))
#define elm5(l) first(next(next(next(next(l)))))
#define elm6(l) first(next(next(next(next(next(l))))))
#define elm7(l) first(next(next(next(next(next(next(l)))))))

#define mk_appl1(sym, a1)                    mk_appl(sym, mk_list1(a1))
#define mk_appl2(sym, a1, a2)                mk_appl(sym, mk_list2(a1, a2))
#define mk_appl3(sym, a1, a2, a3)            mk_appl(sym, mk_list3(a1,a2,a3))
#define mk_appl4(sym, a1, a2, a3, a4)        mk_appl(sym, mk_list4(a1, a2, a3, a4))
#define mk_appl5(sym, a1, a2, a3, a4, a5)    mk_appl(sym, mk_list5(a1, a2, a3, a4, a5))
#define mk_appl6(sym, a1, a2, a3, a4, a5, a6) \
            mk_appl(sym, mk_list6(a1, a2, a3, a4, a5, a6))
#define mk_appl7(sym, a1, a2, a3, a4, a5, a6, a7) \
            mk_appl(sym, mk_list7(a1, a2, a3, a4, a5, a6, a7))


term      *mk_list(term *, term_list *);
void      convert_form_to_var(var *);
void      convert_form_to_mvar(var *);
char      *strndup(char *, char *);
void      print_str(const char *);
void      print_bstr(const char *, int);
char      *resolve(char *, const char *);
void      pr_term(const term *);
void      pr_env(const env *);
void      pr_term_unquoted(const term *);

void       pr_term_list(const term_list *);
term_list *append_list(term_list *, term *);
term_list *append_list_list(term_list *, term_list *);
int        length_list(term_list *);
term_list *join(term *, term *);

term_list *copy_list(term_list *);

TBbool    streq(const char *, const char *);
TBbool    streq_unres(char *, char *);
TBbool    bstreq(bstr *, bstr *);
char *    strdup(const char *);

term      *index_term_list(term_list *, int);
term_list *replace_term_list(term_list *, int, term *);

TBbool     elem(term *, term_list *);
term       *del_term(term *, term_list *);
TBbool     subset(term_list *, term_list *);
term_list  *diff(term_list *, term_list *);
term_list  *inter(term_list *, term_list *);
term       *get_list(term_list *, term*);
term       *get_list_as_env(term_list *, term *);
term_list  *put_list(term_list *, term *, term *);
TBbool     equal_term(term *, term *);
TBbool     equal_list(term_list *, term_list *);
term_list *reverse(term_list *);

extern void printn(const char *, int);

void TBprotect(term **);
void TBunprotect(term **);
void add_free_list(term_list *);

extern int nterm;
extern int nfree;

#define mark_and_collect()   if(nfree < nterm/20) do_mark_and_collect();

void do_mark_and_collect(void);

extern term *True;
extern term *False;

extern term *Bool;
extern term *Int;
extern term *Real;
extern term *Str;
extern term *Bstr;
extern term *List;
extern term *Term;
extern term *Undefined;

/* --------------- expressions --------------------------------*/

/* symbol.h needs term to be defined */
#include "symbol.h"

TBbool require_type(type *, term *);
TBbool comp_type(type *, type *);
type *type_of(term *);
TBbool has_no_vars(term *);
TBbool has_result_vars(term *);
term * convert_to_sign(term *);

void init_terms(void);

#endif /* __TERMS_H__ */
