
#ifndef SUPPORT_H
#define SUPPORT_H

#include <aterm.h>

#define INITIAL_TABLE_SIZE 8191
#define MAX_LOAD 75

#define PROF(var)

#define is_char(t,c) (t_is_int(t) && t_int_val(t) == (c))
#define make_char(c) (TbuildInt(w, (c)))
#define singleton(t) (TbuildList(w, (t), t_empty(w)))
#define check_sym(t,s) (t_appl_sym(t) == (s))

typedef aterm *(*funcptr)();

extern asymbol *oksym;
extern asymbol *nullsym;

extern void c_rehash(int size);
extern void register_prod(aterm *pord, funcptr func, asymbol *sym);
extern funcptr lookup_func(aterm *prod);
extern asymbol *lookup_sym(aterm *prod);
extern aterm *lookup_prod(asymbol *sym);
extern aworld *w;
extern aterm *null();
extern aterm *list_equal(aterm *t1, aterm *t2);
extern aterm *list_head(aterm_list *l1);
extern aterm_list *list_tail(aterm_list *l1);
extern aterm_list *list_prefix(aterm_list *l1);
extern aterm *list_last(aterm_list *l1);
extern aterm_list *cons(aterm_list *l1, aterm_list *l2);
extern aterm *c_false;
extern aterm *c_true;
extern Tbool term_equal(aterm *t1, aterm *t2);
extern Tbool not_empty_list(aterm *l);
extern Tbool is_single_element(aterm_list *l);
extern aterm_list *make_list(aterm *t);
extern aterm *ok(aterm *t);

extern aterm *make_nf0(asymbol *s);
extern aterm *make_nf1(asymbol *s, aterm *t0);
extern aterm *make_nf2(asymbol *s, aterm *t0, aterm *t1);
extern aterm *make_nf3(asymbol *s, aterm *t0, aterm *t1, aterm *t2);
extern aterm *make_nf4(asymbol *s, aterm *t0, aterm *t1, aterm *t2, aterm *t3);
extern aterm *make_nf5(asymbol *s, aterm *t0, aterm *t1, aterm *t2, aterm *t3,
		       aterm *t4);
extern aterm *make_nf6(asymbol *s, aterm *t0, aterm *t1, aterm *t2, aterm *t3,
		       aterm *t4, aterm *t5);
extern aterm *make_nf7(asymbol *s, aterm *t0, aterm *t1, aterm *t2, aterm *t3,
		       aterm *t4, aterm *t5, aterm *t6);
extern aterm *make_nf8(asymbol *s, aterm *t0, aterm *t1, aterm *t2, aterm *t3,
		       aterm *t4, aterm *t5, aterm *t6, aterm *t7);
extern aterm *make_nf9(asymbol *s, aterm *t0, aterm *t1, aterm *t2, aterm *t3,
		       aterm *t4, aterm *t5, aterm *t6, aterm *t7, aterm *t8);
extern aterm *make_nf10(asymbol *s, aterm *t0, aterm *t1, aterm *t2, aterm *t3,
		       aterm *t4, aterm *t5, aterm *t6, aterm *t7, aterm *t8,
		       aterm *t9);
extern aterm *make_nf11(asymbol *s, aterm *t0, aterm *t1, aterm *t2, aterm *t3,
		       aterm *t4, aterm *t5, aterm *t6, aterm *t7, aterm *t8,
		       aterm *t9, aterm *t10);
extern aterm *make_nf12(asymbol *s, aterm *t0, aterm *t1, aterm *t2, aterm *t3,
		       aterm *t4, aterm *t5, aterm *t6, aterm *t7, aterm *t8,
		       aterm *t9, aterm *t10, aterm *t11);
extern aterm *make_nf13(asymbol *s, aterm *t0, aterm *t1, aterm *t2, aterm *t3,
		       aterm *t4, aterm *t5, aterm *t6, aterm *t7, aterm *t8,
		       aterm *t9, aterm *t10, aterm *t11, aterm *t12);
extern aterm *make_nf14(asymbol *s, aterm *t0, aterm *t1, aterm *t2, aterm *t3,
		       aterm *t4, aterm *t5, aterm *t6, aterm *t7, aterm *t8,
		       aterm *t9, aterm *t10, aterm *t11, aterm *t12,
		       aterm *t13);
extern aterm *make_nf15(asymbol *s, aterm *t0, aterm *t1, aterm *t2, aterm *t3,
		       aterm *t4, aterm *t5, aterm *t6, aterm *t7, aterm *t8,
		       aterm *t9, aterm *t10, aterm *t11, aterm *t12,
		       aterm *t13, aterm *t14);

extern aterm *arg_0(aterm *appl);
extern aterm *arg_1(aterm *appl);
extern aterm *arg_2(aterm *appl);
extern aterm *arg_3(aterm *appl);
extern aterm *arg_4(aterm *appl);
extern aterm *arg_5(aterm *appl);
extern aterm *arg_6(aterm *appl);
extern aterm *arg_7(aterm *appl);
extern aterm *arg_8(aterm *appl);
extern aterm *arg_9(aterm *appl);
extern aterm *arg_10(aterm *appl);
extern aterm *arg_11(aterm *appl);
extern aterm *arg_12(aterm *appl);
extern aterm *arg_13(aterm *appl);
extern aterm *arg_14(aterm *appl);
extern aterm *arg_15(aterm *appl);

extern void ToC_code(aterm *asfix, FILE *file);

extern void register_all();
extern void resolve_all();

#endif
