#ifndef ASC_SUPPORT_H
#define ASC_SUPPORT_H

#include <aterm2.h> 
#include <asc-builtins.h>

#ifdef TOOLBUS
#include <atb-tool.h>
#endif

#define INITIAL_TABLE_SIZE 8191
#define MAX_LOAD 75

#define MEMO_OFF
#define MEMO_MEM_INFO

/*{{{  profiling */

#define PROF(var)

#ifdef MEMO_PROFILING

extern ATermTable prof_table;
extern Symbol record_sym;

#define CONS_ENTRY(sym,appl) ++rewrite_steps
#define CONS_EXIT(rhs)		 return rhs
#define CONS_EXIT_CONST(constant,rhs) return ( constant ? constant : ( constant = rhs)) ;

#define FUNC_ENTRY(sym,appl) \
  unsigned int steps, count, start = rewrite_steps++; \
  ATerm result, record, term_steps; \
  ATermAppl term = appl

#define FUNC_EXIT(rhs) \
  result = rhs;                          \
  steps = rewrite_steps - start;         \
                                         \
  if(steps > 2) {                        \
    record = get_result(prof_table, (ATerm)term); \
    if(record) {                           \
		  count = ATgetInt((ATermInt)ATgetArgument(record, 0))+1; \
		  term_steps = ATgetArgument(record, 1); \
    } else {                               \
		  count = 1;                           \
		  term_steps = (ATerm)ATmakeInt(steps);\
	  } \
    record = (ATerm)ATmakeAppl2(record_sym, (ATerm)ATmakeInt(count), term_steps); \
    put_result(prof_table, (ATerm)term, record); \
  } \
  return result;

#define FUNC_EXIT_CONST(constant,rhs) \
  return ( constant ? constant : ( constant = rhs)) ;  \

#else

#define CONS_ENTRY(sym,appl)
#define CONS_EXIT(rhs) return rhs
#define CONS_EXIT_CONST(constant,rhs) return ( constant ? constant : ( constant = rhs)) ;
#define FUNC_ENTRY(sym,appl)
#define FUNC_EXIT(rhs) return rhs;
#define FUNC_EXIT_CONST(constant,rhs) return ( constant ? constant : ( constant = rhs)) ;

#endif


  /*}}}  */

  /*{{{ muasf terms  */

#define term_equal(t1,t2) (ATisEqual(t1,t2))
/*#define ok(t) (ATmakeAppl1(oksym,t))*/
#define is_char(t,c) (ATgetType(t) == AT_INT && ATgetInt((ATermInt) t) == (c))
#define make_char(c) (char_table[c])
#define make_list_char(c) ((ATerm)(ATmakeList1(char_table[c])))
#define singleton(t) (ATerm)(ATmakeList1((t)))
#define get_sym(t) ATgetSymbol((ATermAppl) t)
#define check_sym(t,s) (get_sym(t) == (s))
#define check_sort(t,sort) (ATisEqual(get_sort(t),sort))
#define remove_list(t) (make_list(ATgetArgument((ATermAppl) t,0)))
#define parse_sort(s)  (ATparse(s))

#define accutrafo_tuple_first(t)    (ATgetArgument((ATermAppl) t,0))
#define accutrafo_tuple_second(t)   (ATgetArgument((ATermAppl) t,1))
#define make_accutrafo_tuple(t0,t1) ((ATerm)(ATmakeAppl2(tuplesym,t0,t1)))
/*}}}  */

  /*{{{  memo functionality */

/* Macros to access the database */
#ifndef MEMO_OFF
#define get_result(db,k) (ATtableGet(db,k))
#define put_result(db,k,v) (ATtablePut(db,k,v))
#define get_table(db) (db)
#ifdef MEMO_MEM_INFO
#define create_table(db,v) (db = ATtableCreate(500,75), reg_memo_table(&db, #db))
extern void reg_memo_table(ATermTable *db, char *name);
extern void print_memo_table_sizes();
#else
#define create_table(db,v) (db = ATtableCreate(500,75))
#endif
#else
#define get_result(db,k) (NULL)
#define put_result(db,k,v)
#define get_table(db) (db)
#define create_table(db,v) (db = ATtableCreate(10,75))
#endif


/*}}}  */

/*{{{  nametable interface */

typedef ATerm (*funcptr)();

void c_rehash(int newsize);
unsigned int calc_hash(ATerm t);
void register_prod(ATerm prod, funcptr func, Symbol sym);

funcptr lookup_func_given_sym(Symbol sym);
funcptr basic_lookup_func(ATerm prod);
funcptr lookup_func(ATerm prod);
Symbol lookup_sym(ATerm prod);
ATerm lookup_prod(Symbol sym);

/*}}}  */

/*{{{  tail_n */

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


/*}}}  */
/*{{{  arg_n */

#define arg_0(t) (ATgetArgument(t,0))
#define arg_1(t) (ATgetArgument(t,1))
#define arg_2(t) (ATgetArgument(t,2))
#define arg_3(t)  (ATgetArgument(t,3))
#define arg_4(t)  (ATgetArgument(t,4))
#define arg_5(t)  (ATgetArgument(t,5))
#define arg_6(t)  (ATgetArgument(t,6))
#define arg_7(t)  (ATgetArgument(t,7))
#define arg_8(t)  (ATgetArgument(t,8))
#define arg_9(t)  (ATgetArgument(t,9))
#define arg_10(t)  (ATgetArgument(t,10))
#define arg_11(t)  (ATgetArgument(t,11))
#define arg_12(t)  (ATgetArgument(t,12))
#define arg_13(t)  (ATgetArgument(t,13))
#define arg_14(t)  (ATgetArgument(t,14))
#define arg_15(t)  (ATgetArgument(t,15))
#define arg_16(t)  (ATgetArgument(t,16))
#define arg_17(t)  (ATgetArgument(t,17))
#define arg_18(t)  (ATgetArgument(t,18))
#define arg_19(t)  (ATgetArgument(t,19))


/*}}}  */
/*{{{  make_nf */

#define make_nf0(s) (ATerm)(ATmakeAppl0((Symbol)s))
#define make_nf1(s,t0) ((ATerm)(ATmakeAppl1((Symbol)s,t0)))
#define make_nf2(s,t0,t1) (ATerm)(ATmakeAppl2((Symbol)s,t0,t1))
#define make_nf3(s,t0,t1,t2) (ATerm)(ATmakeAppl3((Symbol)s,t0,t1,t2))
#define make_nf4(s,t0,t1,t2,t3) (ATerm)(ATmakeAppl4((Symbol)s,t0,t1,t2,t3))
#define make_nf5(s,t0,t1,t2,t3,t4) (ATerm)(ATmakeAppl5((Symbol)s,t0,t1,t2,t3,t4))
#define make_nf6(s,t0,t1,t2,t3,t4,t5) (ATerm)(ATmakeAppl6((Symbol)s,t0,t1,t2,t3,t4,t5))
#define make_nf7(s,t0,t1,t2,t3,t4,t5,t6) (ATerm)(ATmakeAppl((Symbol)s,t0,t1,t2,t3,t4,t5,t6))
#define make_nf8(s,t0,t1,t2,t3,t4,t5,t6,t7) (ATerm)(ATmakeAppl((Symbol)s,t0,t1,t2,t3,t4,t5,\
						t6,t7))
#define make_nf9(s,t0,t1,t2,t3,t4,t5,t6,t7,t8) (ATerm)(ATmakeAppl((Symbol)s,t0,t1,t2,t3,t4,\
						t5,t6,t7,t8))
#define make_nf10(s,t0,t1,t2,t3,t4,t5,t6,t7,t8,t9) (ATerm)(ATmakeAppl((Symbol)s,t0,t1,t2,t3,\
						t4,t5,t6,t7,t8,t9))
#define make_nf11(s,t0,t1,t2,t3,t4,t5,t6,t7,t8,t9,t10) (ATerm)(ATmakeAppl((Symbol)s,t0,t1,t2,t3,t4,t5,t6,t7,t8,t9,t10))
#define make_nf12(s,t0,t1,t2,t3,t4,t5,t6,t7,t8,t9,t10,t11) (ATerm)(ATmakeAppl((Symbol)s,t0,t1,t2,t3,t4,t5,t6,t7,t8,t9,t10,t11))
#define make_nf13(s,t0,t1,t2,t3,t4,t5,t6,t7,t8,t9,t10,t11,t12) (ATerm)(ATmakeAppl((Symbol)s,t0,t1,t2,t3,t4,t5,t6,t7,t8,t9,t10,t11,t12))
#define make_nf14(s,t0,t1,t2,t3,t4,t5,t6,t7,t8,t9,t10,t11,t12,t13) (ATerm)(ATmakeAppl((Symbol)s,t0,t1,t2,t3,t4,t5,t6,t7,t8,t9,t10,t11,t12,t13))
#define make_nf15(s,t0,t1,t2,t3,t4,t5,t6,t7,t8,t9,t10,t11,t12,t13,t14) (ATerm)(ATmakeAppl((Symbol)s,t0,t1,t2,t3,t4,t5,t6,t7,t8,t9,t10,t11,t12,t13,t14))

#define make_nf16(s,t0,t1,t2,t3,t4,t5,t6,t7,t8,t9,t10,t11,t12,t13,t14,t15) (ATerm)(ATmakeAppl((Symbol)s,t0,t1,t2,t3,t4,t5,t6,t7,t8,t9,t10,t11,t12,t13,t14,t15))
#define make_nf17(s,t0,t1,t2,t3,t4,t5,t6,t7,t8,t9,t10,t11,t12,t13,t14,t15,t16) (ATerm)(ATmakeAppl((Symbol)s,t0,t1,t2,t3,t4,t5,t6,t7,t8,t9,t10,t11,t12,t13,t14,t15,t16))
#define make_nf18(s,t0,t1,t2,t3,t4,t5,t6,t7,t8,t9,t10,t11,t12,t13,t14,t15,t16,t17) (ATerm)(ATmakeAppl((Symbol)s,t0,t1,t2,t3,t4,t5,t6,t7,t8,t9,t10,t11,t12,t13,t14,t15,t16,t17))
#define make_nf19(s,t0,t1,t2,t3,t4,t5,t6,t7,t8,t9,t10,t11,t12,t13,t14,t15,t16,t17,t18) (ATerm)(ATmakeAppl((Symbol)s,t0,t1,t2,t3,t4,t5,t6,t7,t8,t9,t10,t11,t12,t13,t14,t15,t16,t17,t18))
#define make_nf20(s,t0,t1,t2,t3,t4,t5,t6,t7,t8,t9,t10,t11,t12,t13,t14,t15,t16,t17,t18,t19) (ATerm)(ATmakeAppl((Symbol)s,t0,t1,t2,t3,t4,t5,t6,t7,t8,t9,t10,t11,t12,t13,t14,t15,t16,t17,t18,t19))
#define make_nf21(s,t0,t1,t2,t3,t4,t5,t6,t7,t8,t9,t10,t11,t12,t13,t14,t15,t16,t17,t18,t19,t20) (ATerm)(ATmakeAppl((Symbol)s,t0,t1,t2,t3,t4,t5,t6,t7,t8,t9,t10,t11,t12,t13,t14,t15,t16,t17,t18,t19,t20))
#define make_nf22(s,t0,t1,t2,t3,t4,t5,t6,t7,t8,t9,t10,t11,t12,t13,t14,t15,t16,t17,t18,t19,t20,t21) (ATerm)(ATmakeAppl((Symbol)s,t0,t1,t2,t3,t4,t5,t6,t7,t8,t9,t10,t11,t12,t13,t14,t15,t16,t17,t18,t19,t20,t21))
#define make_nf23(s,t0,t1,t2,t3,t4,t5,t6,t7,t8,t9,t10,t11,t12,t13,t14,t15,t16,t17,t18,t19,t20,t21,t22) (ATerm)(ATmakeAppl((Symbol)s,t0,t1,t2,t3,t4,t5,t6,t7,t8,t9,t10,t11,t12,t13,t14,t15,t16,t17,t18,t19,t20,t21,t22))
#define make_nf24(s,t0,t1,t2,t3,t4,t5,t6,t7,t8,t9,t10,t11,t12,t13,t14,t15,t16,t17,t18,t19,t20,t21,t22,t23) (ATerm)(ATmakeAppl((Symbol)s,t0,t1,t2,t3,t4,t5,t6,t7,t8,t9,t10,t11,t12,t13,t14,t15,t16,t17,t18,t19,t20,t21,t22,t23))
#define make_nf25(s,t0,t1,t2,t3,t4,t5,t6,t7,t8,t9,t10,t11,t12,t13,t14,t15,t16,t17,t18,t19,t20,t21,t22,t23,t24) (ATerm)(ATmakeAppl((Symbol)s,t0,t1,t2,t3,t4,t5,t6,t7,t8,t9,t10,t11,t12,t13,t14,t15,t16,t17,t18,t19,t20,t21,t22,t23,t24))
#define make_nf26(s,t0,t1,t2,t3,t4,t5,t6,t7,t8,t9,t10,t11,t12,t13,t14,t15,t16,t17,t18,t19,t20,t21,t22,t23,t24,t25) (ATerm)(ATmakeAppl((Symbol)s,t0,t1,t2,t3,t4,t5,t6,t7,t8,t9,t10,t11,t12,t13,t14,t15,t16,t17,t18,t19,t20,t21,t22,t23,t24,t25))
#define make_nf27(s,t0,t1,t2,t3,t4,t5,t6,t7,t8,t9,t10,t11,t12,t13,t14,t15,t16,t17,t18,t19,t20,t21,t22,t23,t24,t25,t26) (ATerm)(ATmakeAppl((Symbol)s,t0,t1,t2,t3,t4,t5,t6,t7,t8,t9,t10,t11,t12,t13,t14,t15,t16,t17,t18,t19,t20,t21,t22,t23,t24,t25,t26))
#define make_nf28(s,t0,t1,t2,t3,t4,t5,t6,t7,t8,t9,t10,t11,t12,t13,t14,t15,t16,t17,t18,t19,t20,t21,t22,t23,t24,t25,t26,t27) (ATerm)(ATmakeAppl((Symbol)s,t0,t1,t2,t3,t4,t5,t6,t7,t8,t9,t10,t11,t12,t13,t14,t15,t16,t17,t18,t19,t20,t21,t22,t23,t24,t25,t26,t27))
#define make_nf29(s,t0,t1,t2,t3,t4,t5,t6,t7,t8,t9,t10,t11,t12,t13,t14,t15,t16,t17,t18,t19,t20,t21,t22,t23,t24,t25,t26,t27,t28) (ATerm)(ATmakeAppl((Symbol)s,t0,t1,t2,t3,t4,t5,t6,t7,t8,t9,t10,t11,t12,t13,t14,t15,t16,t17,t18,t19,t20,t21,t22,t23,t24,t25,t26,t27,t28))
#define make_nf30(s,t0,t1,t2,t3,t4,t5,t6,t7,t8,t9,t10,t11,t12,t13,t14,t15,t16,t17,t18,t19,t20,t21,t22,t23,t24,t25,t26,t27,t28,t29) (ATerm)(ATmakeAppl((Symbol)s,t0,t1,t2,t3,t4,t5,t6,t7,t8,t9,t10,t11,t12,t13,t14,t15,t16,t17,t18,t19,t20,t21,t22,t23,t24,t25,t26,t27,t28,t29))
#define make_nf31(s,t0,t1,t2,t3,t4,t5,t6,t7,t8,t9,t10,t11,t12,t13,t14,t15,t16,t17,t18,t19,t20,t21,t22,t23,t24,t25,t26,t27,t28,t29,t30) (ATerm)(ATmakeAppl((Symbol)s,t0,t1,t2,t3,t4,t5,t6,t7,t8,t9,t10,t11,t12,t13,t14,t15,t16,t17,t18,t19,t20,t21,t22,t23,t24,t25,t26,t27,t28,t29,t30))
#define make_nf32(s,t0,t1,t2,t3,t4,t5,t6,t7,t8,t9,t10,t11,t12,t13,t14,t15,t16,t17,t18,t19,t20,t21,t22,t23,t24,t25,t26,t27,t28,t29,t30,t31) (ATerm)(ATmakeAppl((Symbol)s,t0,t1,t2,t3,t4,t5,t6,t7,t8,t9,t10,t11,t12,t13,t14,t15,t16,t17,t18,t19,t20,t21,t22,t23,t24,t25,t26,t27,t28,t29,t30,t31))


/*}}}  */
/*{{{  quote */

#define quote0(s) (ATerm)(ATmakeAppl1(sym_quote0, (ATerm) ATmakeInt((int)s)))
#define quote1(s,t1) (ATerm)(ATmakeAppl2(sym_quote1, (ATerm) ATmakeInt((int)s), t1))
#define quote2(s,t1,t2) (ATerm)(ATmakeAppl3(sym_quote2, (ATerm) ATmakeInt((int)s), t1, t2))
#define quote3(s,t1,t2,t3) (ATerm)(ATmakeAppl4(sym_quote3, (ATerm) ATmakeInt((int)s), t1, t2, t3))
#define quote4(s,t1,t2,t3,t4) (ATerm)(ATmakeAppl5(sym_quote4, (ATerm) ATmakeInt((int)s), t1, t2, t3, t4))
#define quote5(s,t1,t2,t3,t4,t5) (ATerm)(ATmakeAppl6(sym_quote5, (ATerm) ATmakeInt((int)s), t1, t2, t3, t4, t5))
#define quote6(s,t1,t2,t3,t4,t5,t6) (ATerm)(ATmakeAppl(sym_quote6, (ATerm) ATmakeInt((int)s), t1, t2, t3, t4, t5, t6))
#define quote7(s,t1,t2,t3,t4,t5,t6, t7) (ATerm)(ATmakeAppl(sym_quote7, (ATerm) ATmakeInt((int)s), t1, t2, t3, t4, t5, t6, t7))


/*}}}  */
/*{{{  make_tuple */

#define make_tuple1(t0) (ATerm)(t0)
#define make_tuple2(t0,t1) (ATerm)(ATmakeList2(t0,t1))
#define make_tuple3(t0,t1,t2) (ATerm)(ATmakeList3(t0,t1,t2))
#define make_tuple4(t0,t1,t2,t3) (ATerm)(ATmakeList4(t0,t1,t2,t3))


/*}}}  */

/*{{{  list functions */

#define null() (ATerm)(ATempty)
#define list_head(l) (ATgetFirst((ATermList)l))
#define list_tail(l) (ATerm)(ATgetNext((ATermList)l))
/*#define conc(l1,l2) (ATerm)(ATconcat((ATermList)l1,(ATermList)l2))*/
#define cons(l1,l2) (ATerm)(ATconcat((ATermList)l1,(ATermList)l2))
#define append(l,t) (ATerm)(ATappend((ATermList)l,t))
#define insert(t,l) (ATerm)(ATinsert((ATermList)l,t))
#define list_last(l) (ATgetLast((ATermList)l))
#define list_prefix(l) (ATerm)(ATgetPrefix((ATermList)l))
#define not_empty_list(l) (!ATisEmpty((ATermList)l))
#define is_single_element(l) (ATgetType(l) == AT_LIST && \
                              (!ATisEmpty((ATermList)l) && \
                              ATisEmpty(ATgetNext((ATermList)l))))
#define slice_length(l1,l2) (ATgetLength(l1) - ATgetLength(l2))


  /*}}}  */

/*{{{  external functions and globals */

extern unsigned int rewrite_steps;
extern ATerm char_table[];
extern Symbol sym_quote0;
extern Symbol sym_quote1;
extern Symbol sym_quote2;
extern Symbol sym_quote3;
extern Symbol sym_quote4;
extern Symbol sym_quote5;
extern Symbol sym_quote6;
extern Symbol sym_quote7;
extern Symbol make_listsym;
extern Symbol concsym;
extern Symbol conssym;
extern Symbol tuplesym;

extern ATerm list_equal(ATerm t1, ATerm t2);
extern ATerm slice(ATerm l1, ATerm l2);
extern ATerm make_list(ATerm t);
extern ATerm get_sort(ATerm tree);
extern ATerm unquote(ATerm t);
extern ATerm call_kids_trafo(funcptr trav, ATerm arg, ATermList extra_args);
extern ATerm call_kids_accu(funcptr trav, ATerm arg, ATerm accu, 
			    ATermList extra_args);
extern ATerm call_kids_accutrafo(funcptr trav, ATerm arg, ATerm accu, 
				 ATermList extra_args);

extern ATerm correct_tuple(ATerm arg, ATerm rhs);


int asc_support_main(ATerm *bottom, int argc, char *argv[],
                     void (*register_all)(void),
                     void (*resolve_all)(void),
                     void (*init_all)(void)
#ifdef TOOLBUS
		     , ATBhandler handler
#endif
		     );

/*}}}  */

ATerm innermost(PT_Tree tree);

#endif  /* ASC_SUPPORT_H */
