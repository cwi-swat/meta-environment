
#ifndef SUPPORT_H
#define SUPPORT_H

#include <aterm.h>

#define INITIAL_TABLE_SIZE 8191
#define MAX_LOAD 75

#define PROF(var)

#define is_char(t,c) (t_is_int(t) && t_int_val(t) == (c))
#define make_char(c) (t_sharing(char_table[c])++, char_table[c])
#define singleton(t) (TbuildList(w, (t), t_empty(w)))
#define check_sym(t,s) (t_appl_sym(t) == (s))

#define m_term_equal(t1,t2) t_equal(t1,t2)
#define m_not_empty_list(l) (!t_is_empty(l))
#define m_is_single_element(l) (t_is_list(l) && (!t_is_empty(l) && \
                                                 t_is_empty(t_list_next(l))))
#define m_list_head(l) (t_sharing(t_list_first(l))++,t_list_first(l))
#define m_list_tail(l) (t_sharing(t_list_next(l))++,t_list_next(l))

#define tail_1(l) (t_list_next(l))
#define tail_2(l) (t_list_next(tail_1(l)))
#define tail_3(l) (t_list_next(tail_2(l)))
#define tail_4(l) (t_list_next(tail_3(l)))
#define tail_5(l) (t_list_next(tail_4(l)))
#define tail_6(l) (t_list_next(tail_5(l)))
#define tail_7(l) (t_list_next(tail_6(l)))
#define tail_8(l) (t_list_next(tail_7(l)))
#define tail_9(l) (t_list_next(tail_8(l)))
#define tail_10(l) (t_list_next(tail_9(l)))
#define tail_11(l) (t_list_next(tail_10(l)))
#define tail_12(l) (t_list_next(tail_11(l)))
#define tail_13(l) (t_list_next(tail_12(l)))
#define tail_14(l) (t_list_next(tail_13(l)))
#define tail_15(l) (t_list_next(tail_14(l)))

#define arg_0(t) (t_list_first(t_appl_args(t)))
#define arg_1(t) (t_list_first(tail_1(t_appl_args(t))))
#define arg_2(t) (t_list_first(tail_2(t_appl_args(t))))
#define arg_3(t) (t_list_first(tail_3(t_appl_args(t))))
#define arg_4(t) (t_list_first(tail_4(t_appl_args(t))))
#define arg_5(t) (t_list_first(tail_5(t_appl_args(t))))
#define arg_6(t) (t_list_first(tail_6(t_appl_args(t))))
#define arg_7(t) (t_list_first(tail_7(t_appl_args(t))))
#define arg_8(t) (t_list_first(tail_8(t_appl_args(t))))
#define arg_9(t) (t_list_first(tail_9(t_appl_args(t))))
#define arg_10(t) (t_list_first(tail_10(t_appl_args(t))))
#define arg_11(t) (t_list_first(tail_11(t_appl_args(t))))
#define arg_12(t) (t_list_first(tail_12(t_appl_args(t))))
#define arg_14(t) (t_list_first(tail_13(t_appl_args(t))))
#define arg_15(t) (t_list_first(tail_14(t_appl_args(t))))

typedef aterm *(*funcptr)();

extern aterm *char_table[];

extern asymbol *oksym;
extern asymbol *tuplesym;
extern asymbol *tuple2sym;
extern asymbol *tuple3sym;
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
extern aterm *t();
extern aterm *f();
extern aterm *or(aterm *t0, aterm *t1);
extern Tbool term_equal(aterm *t1, aterm *t2);
extern Tbool not_empty_list(aterm *l);
extern Tbool is_single_element(aterm_list *l);
extern aterm_list *make_list(aterm *t);
extern aterm *ok(aterm *t);
extern aterm *tuple(aterm *t0, aterm *t1);
extern aterm *tuple2(aterm *t0, aterm *t1);
extern aterm *tuple3(aterm *t0, aterm *t1, aterm *t2);
extern aterm_list *slice(aterm_list *l1, aterm_list *l2);

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


extern void ToC_code(aterm *asfix, FILE *file);

extern void register_all();
extern void resolve_all();

#endif
