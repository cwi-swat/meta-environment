#ifndef ASC_SUPPORT_H
#define ASC_SUPPORT_H

#include <aterm2.h> 
#include <atb-tool.h>
#include <sglrInterface.h>
#include <MEPT-utils.h>
#include <asc-muasf2pt.h>

#include "asc-builtins.h"

#define INITIAL_TABLE_SIZE 8191
#define MAX_LOAD 75

#define debug_term(t) (PT_yieldTree(muASFToTree(t)))

#define remove_list(t) (make_list(ATgetArgument((ATermAppl) t,0)))

/*{{{  profiling */

#define PROF(var)

#ifdef MEMO_PROFILING

extern ATermTable prof_table;
extern AFun record_sym;

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

#ifdef ASF_WITH_ANNOS
#define pt_get_annos(t1) (PT_getTreeAnnotations((PT_Tree) t1))
#define term_equal(t1,t2) (ATisEqualModuloAnnotations(t1,t2))
#else
#define term_equal(t1,t2) (ATisEqual(t1,t2))
#define pt_get_annos(t1) ((ATerm) NULL)
#endif

/*#define ok(t) (ATmakeAppl1(oksym,t))*/
#define is_char(t,c) (ATgetType(t) == AT_INT && ATgetInt((ATermInt) t) == (c))
#define make_char(c) (char_table[c])
#define make_list_char(c) ((ATerm)(ATmakeList1(char_table[c])))
#define singleton(t) (ATerm)(ATmakeList1((t)))
#define get_sym(t) ATgetAFun((ATermAppl) t)
#define check_sym(t,s) (get_sym(t) == (s))
#define check_sort(t,sort) (ATisEqual(get_sort(t),sort))
#define parse_sort(s)  (ATparse(s))
#define parse_cc(s) (ATparse(s))
#define is_elem(a,b) (PT_elementOfCharClass((PT_Tree) (a), (PT_Symbol) (b)))

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
void unregister_all();
unsigned int calc_hash(ATerm t);
void register_prod(ATerm prod, funcptr func, AFun sym);

funcptr lookup_func_given_sym(AFun sym);
funcptr prefix_lookup_func(PT_Symbols lhs);
funcptr basic_lookup_func(ATerm prod);
funcptr lookup_func(ATerm prod);
AFun lookup_sym(ATerm prod);
ATerm lookup_prod(AFun sym);

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
#define arg_20(t) (ATgetArgument(t,20))
#define arg_21(t) (ATgetArgument(t,21))
#define arg_22(t) (ATgetArgument(t,22))
#define arg_23(t) (ATgetArgument(t,23))
#define arg_24(t) (ATgetArgument(t,24))
#define arg_25(t) (ATgetArgument(t,25))
#define arg_26(t) (ATgetArgument(t,26))
#define arg_27(t) (ATgetArgument(t,27))
#define arg_28(t) (ATgetArgument(t,28))
#define arg_29(t) (ATgetArgument(t,29))
#define arg_30(t) (ATgetArgument(t,30))
#define arg_31(t) (ATgetArgument(t,31))
#define arg_32(t) (ATgetArgument(t,32))
#define arg_33(t) (ATgetArgument(t,33))
#define arg_34(t) (ATgetArgument(t,34))
#define arg_35(t) (ATgetArgument(t,35))
#define arg_36(t) (ATgetArgument(t,36))
#define arg_37(t) (ATgetArgument(t,37))
#define arg_38(t) (ATgetArgument(t,38))
#define arg_39(t) (ATgetArgument(t,39))
#define arg_40(t) (ATgetArgument(t,40))
#define arg_41(t) (ATgetArgument(t,41))
#define arg_42(t) (ATgetArgument(t,42))
#define arg_43(t) (ATgetArgument(t,43))
#define arg_44(t) (ATgetArgument(t,44))
#define arg_45(t) (ATgetArgument(t,45))
#define arg_46(t) (ATgetArgument(t,46))
#define arg_47(t) (ATgetArgument(t,47))
#define arg_48(t) (ATgetArgument(t,48))
#define arg_49(t) (ATgetArgument(t,49))
#define arg_50(t) (ATgetArgument(t,50))


/*}}}  */
/*{{{  make_nf */

#define make_nf0(s) (ATerm)(ATmakeAppl0((AFun)s))
#define make_nf1(s,t0) ((ATerm)(ATmakeAppl1((AFun)s,t0)))
#define make_nf2(s,t0,t1) (ATerm)(ATmakeAppl2((AFun)s,t0,t1))
#define make_nf3(s,t0,t1,t2) (ATerm)(ATmakeAppl3((AFun)s,t0,t1,t2))
#define make_nf4(s,t0,t1,t2,t3) (ATerm)(ATmakeAppl4((AFun)s,t0,t1,t2,t3))
#define make_nf5(s,t0,t1,t2,t3,t4) (ATerm)(ATmakeAppl5((AFun)s,t0,t1,t2,t3,t4))
#define make_nf6(s,t0,t1,t2,t3,t4,t5) (ATerm)(ATmakeAppl6((AFun)s,t0,t1,t2,t3,t4,t5))
#define make_nf7(s,t0,t1,t2,t3,t4,t5,t6) (ATerm)(ATmakeAppl((AFun)s,t0,t1,t2,t3,t4,t5,t6))
#define make_nf8(s,t0,t1,t2,t3,t4,t5,t6,t7) (ATerm)(ATmakeAppl((AFun)s,t0,t1,t2,t3,t4,t5,\
						t6,t7))
#define make_nf9(s,t0,t1,t2,t3,t4,t5,t6,t7,t8) (ATerm)(ATmakeAppl((AFun)s,t0,t1,t2,t3,t4,\
						t5,t6,t7,t8))
#define make_nf10(s,t0,t1,t2,t3,t4,t5,t6,t7,t8,t9) (ATerm)(ATmakeAppl((AFun)s,t0,t1,t2,t3,\
						t4,t5,t6,t7,t8,t9))
#define make_nf11(s,t0,t1,t2,t3,t4,t5,t6,t7,t8,t9,t10) (ATerm)(ATmakeAppl((AFun)s,t0,t1,t2,t3,t4,t5,t6,t7,t8,t9,t10))
#define make_nf12(s,t0,t1,t2,t3,t4,t5,t6,t7,t8,t9,t10,t11) (ATerm)(ATmakeAppl((AFun)s,t0,t1,t2,t3,t4,t5,t6,t7,t8,t9,t10,t11))
#define make_nf13(s,t0,t1,t2,t3,t4,t5,t6,t7,t8,t9,t10,t11,t12) (ATerm)(ATmakeAppl((AFun)s,t0,t1,t2,t3,t4,t5,t6,t7,t8,t9,t10,t11,t12))
#define make_nf14(s,t0,t1,t2,t3,t4,t5,t6,t7,t8,t9,t10,t11,t12,t13) (ATerm)(ATmakeAppl((AFun)s,t0,t1,t2,t3,t4,t5,t6,t7,t8,t9,t10,t11,t12,t13))
#define make_nf15(s,t0,t1,t2,t3,t4,t5,t6,t7,t8,t9,t10,t11,t12,t13,t14) (ATerm)(ATmakeAppl((AFun)s,t0,t1,t2,t3,t4,t5,t6,t7,t8,t9,t10,t11,t12,t13,t14))

#define make_nf16(s,t0,t1,t2,t3,t4,t5,t6,t7,t8,t9,t10,t11,t12,t13,t14,t15) (ATerm)(ATmakeAppl((AFun)s,t0,t1,t2,t3,t4,t5,t6,t7,t8,t9,t10,t11,t12,t13,t14,t15))
#define make_nf17(s,t0,t1,t2,t3,t4,t5,t6,t7,t8,t9,t10,t11,t12,t13,t14,t15,t16) (ATerm)(ATmakeAppl((AFun)s,t0,t1,t2,t3,t4,t5,t6,t7,t8,t9,t10,t11,t12,t13,t14,t15,t16))
#define make_nf18(s,t0,t1,t2,t3,t4,t5,t6,t7,t8,t9,t10,t11,t12,t13,t14,t15,t16,t17) (ATerm)(ATmakeAppl((AFun)s,t0,t1,t2,t3,t4,t5,t6,t7,t8,t9,t10,t11,t12,t13,t14,t15,t16,t17))
#define make_nf19(s,t0,t1,t2,t3,t4,t5,t6,t7,t8,t9,t10,t11,t12,t13,t14,t15,t16,t17,t18) (ATerm)(ATmakeAppl((AFun)s,t0,t1,t2,t3,t4,t5,t6,t7,t8,t9,t10,t11,t12,t13,t14,t15,t16,t17,t18))
#define make_nf20(s,t0,t1,t2,t3,t4,t5,t6,t7,t8,t9,t10,t11,t12,t13,t14,t15,t16,t17,t18,t19) (ATerm)(ATmakeAppl((AFun)s,t0,t1,t2,t3,t4,t5,t6,t7,t8,t9,t10,t11,t12,t13,t14,t15,t16,t17,t18,t19))
#define make_nf21(s,t0,t1,t2,t3,t4,t5,t6,t7,t8,t9,t10,t11,t12,t13,t14,t15,t16,t17,t18,t19,t20) (ATerm)(ATmakeAppl((AFun)s,t0,t1,t2,t3,t4,t5,t6,t7,t8,t9,t10,t11,t12,t13,t14,t15,t16,t17,t18,t19,t20))
#define make_nf22(s,t0,t1,t2,t3,t4,t5,t6,t7,t8,t9,t10,t11,t12,t13,t14,t15,t16,t17,t18,t19,t20,t21) (ATerm)(ATmakeAppl((AFun)s,t0,t1,t2,t3,t4,t5,t6,t7,t8,t9,t10,t11,t12,t13,t14,t15,t16,t17,t18,t19,t20,t21))
#define make_nf23(s,t0,t1,t2,t3,t4,t5,t6,t7,t8,t9,t10,t11,t12,t13,t14,t15,t16,t17,t18,t19,t20,t21,t22) (ATerm)(ATmakeAppl((AFun)s,t0,t1,t2,t3,t4,t5,t6,t7,t8,t9,t10,t11,t12,t13,t14,t15,t16,t17,t18,t19,t20,t21,t22))
#define make_nf24(s,t0,t1,t2,t3,t4,t5,t6,t7,t8,t9,t10,t11,t12,t13,t14,t15,t16,t17,t18,t19,t20,t21,t22,t23) (ATerm)(ATmakeAppl((AFun)s,t0,t1,t2,t3,t4,t5,t6,t7,t8,t9,t10,t11,t12,t13,t14,t15,t16,t17,t18,t19,t20,t21,t22,t23))
#define make_nf25(s,t0,t1,t2,t3,t4,t5,t6,t7,t8,t9,t10,t11,t12,t13,t14,t15,t16,t17,t18,t19,t20,t21,t22,t23,t24) (ATerm)(ATmakeAppl((AFun)s,t0,t1,t2,t3,t4,t5,t6,t7,t8,t9,t10,t11,t12,t13,t14,t15,t16,t17,t18,t19,t20,t21,t22,t23,t24))
#define make_nf26(s,t0,t1,t2,t3,t4,t5,t6,t7,t8,t9,t10,t11,t12,t13,t14,t15,t16,t17,t18,t19,t20,t21,t22,t23,t24,t25) (ATerm)(ATmakeAppl((AFun)s,t0,t1,t2,t3,t4,t5,t6,t7,t8,t9,t10,t11,t12,t13,t14,t15,t16,t17,t18,t19,t20,t21,t22,t23,t24,t25))
#define make_nf27(s,t0,t1,t2,t3,t4,t5,t6,t7,t8,t9,t10,t11,t12,t13,t14,t15,t16,t17,t18,t19,t20,t21,t22,t23,t24,t25,t26) (ATerm)(ATmakeAppl((AFun)s,t0,t1,t2,t3,t4,t5,t6,t7,t8,t9,t10,t11,t12,t13,t14,t15,t16,t17,t18,t19,t20,t21,t22,t23,t24,t25,t26))
#define make_nf28(s,t0,t1,t2,t3,t4,t5,t6,t7,t8,t9,t10,t11,t12,t13,t14,t15,t16,t17,t18,t19,t20,t21,t22,t23,t24,t25,t26,t27) (ATerm)(ATmakeAppl((AFun)s,t0,t1,t2,t3,t4,t5,t6,t7,t8,t9,t10,t11,t12,t13,t14,t15,t16,t17,t18,t19,t20,t21,t22,t23,t24,t25,t26,t27))
#define make_nf29(s,t0,t1,t2,t3,t4,t5,t6,t7,t8,t9,t10,t11,t12,t13,t14,t15,t16,t17,t18,t19,t20,t21,t22,t23,t24,t25,t26,t27,t28) (ATerm)(ATmakeAppl((AFun)s,t0,t1,t2,t3,t4,t5,t6,t7,t8,t9,t10,t11,t12,t13,t14,t15,t16,t17,t18,t19,t20,t21,t22,t23,t24,t25,t26,t27,t28))
#define make_nf30(s,t0,t1,t2,t3,t4,t5,t6,t7,t8,t9,t10,t11,t12,t13,t14,t15,t16,t17,t18,t19,t20,t21,t22,t23,t24,t25,t26,t27,t28,t29) (ATerm)(ATmakeAppl((AFun)s,t0,t1,t2,t3,t4,t5,t6,t7,t8,t9,t10,t11,t12,t13,t14,t15,t16,t17,t18,t19,t20,t21,t22,t23,t24,t25,t26,t27,t28,t29))
#define make_nf31(s,t0,t1,t2,t3,t4,t5,t6,t7,t8,t9,t10,t11,t12,t13,t14,t15,t16,t17,t18,t19,t20,t21,t22,t23,t24,t25,t26,t27,t28,t29,t30) (ATerm)(ATmakeAppl((AFun)s,t0,t1,t2,t3,t4,t5,t6,t7,t8,t9,t10,t11,t12,t13,t14,t15,t16,t17,t18,t19,t20,t21,t22,t23,t24,t25,t26,t27,t28,t29,t30))
#define make_nf32(s,t0,t1,t2,t3,t4,t5,t6,t7,t8,t9,t10,t11,t12,t13,t14,t15,t16,t17,t18,t19,t20,t21,t22,t23,t24,t25,t26,t27,t28,t29,t30,t31) (ATerm)(ATmakeAppl((AFun)s,t0,t1,t2,t3,t4,t5,t6,t7,t8,t9,t10,t11,t12,t13,t14,t15,t16,t17,t18,t19,t20,t21,t22,t23,t24,t25,t26,t27,t28,t29,t30,t31))
#define make_nf33(s,t0,t1,t2,t3,t4,t5,t6,t7,t8,t9,t10,t11,t12,t13,t14,t15,t16,t17,t18,t19,t20,t21,t22,t23,t24,t25,t26,t27,t28,t29,t30,t31,t32) (ATerm)(ATmakeAppl((AFun) s,t0,t1,t2,t3,t4,t5,t6,t7,t8,t9,t10,t11,t12,t13,t14,t15,t16,t17,t18,t19,t20,t21,t22,t23,t24,t25,t26,t27,t28,t29,t30,t31,t32))
#define make_nf34(s,t0,t1,t2,t3,t4,t5,t6,t7,t8,t9,t10,t11,t12,t13,t14,t15,t16,t17,t18,t19,t20,t21,t22,t23,t24,t25,t26,t27,t28,t29,t30,t31,t32,t33) (ATerm)(ATmakeAppl((AFun) s,t0,t1,t2,t3,t4,t5,t6,t7,t8,t9,t10,t11,t12,t13,t14,t15,t16,t17,t18,t19,t20,t21,t22,t23,t24,t25,t26,t27,t28,t29,t30,t31,t32,t33))
#define make_nf35(s,t0,t1,t2,t3,t4,t5,t6,t7,t8,t9,t10,t11,t12,t13,t14,t15,t16,t17,t18,t19,t20,t21,t22,t23,t24,t25,t26,t27,t28,t29,t30,t31,t32,t33,t34) (ATerm)(ATmakeAppl((AFun) s,t0,t1,t2,t3,t4,t5,t6,t7,t8,t9,t10,t11,t12,t13,t14,t15,t16,t17,t18,t19,t20,t21,t22,t23,t24,t25,t26,t27,t28,t29,t30,t31,t32,t33,t34))
#define make_nf36(s,t0,t1,t2,t3,t4,t5,t6,t7,t8,t9,t10,t11,t12,t13,t14,t15,t16,t17,t18,t19,t20,t21,t22,t23,t24,t25,t26,t27,t28,t29,t30,t31,t32,t33,t34,t35) (ATerm)(ATmakeAppl((AFun) s,t0,t1,t2,t3,t4,t5,t6,t7,t8,t9,t10,t11,t12,t13,t14,t15,t16,t17,t18,t19,t20,t21,t22,t23,t24,t25,t26,t27,t28,t29,t30,t31,t32,t33,t34,t35))
#define make_nf37(s,t0,t1,t2,t3,t4,t5,t6,t7,t8,t9,t10,t11,t12,t13,t14,t15,t16,t17,t18,t19,t20,t21,t22,t23,t24,t25,t26,t27,t28,t29,t30,t31,t32,t33,t34,t35,t36) (ATerm)(ATmakeAppl((AFun) s,t0,t1,t2,t3,t4,t5,t6,t7,t8,t9,t10,t11,t12,t13,t14,t15,t16,t17,t18,t19,t20,t21,t22,t23,t24,t25,t26,t27,t28,t29,t30,t31,t32,t33,t34,t35,t36))
#define make_nf38(s,t0,t1,t2,t3,t4,t5,t6,t7,t8,t9,t10,t11,t12,t13,t14,t15,t16,t17,t18,t19,t20,t21,t22,t23,t24,t25,t26,t27,t28,t29,t30,t31,t32,t33,t34,t35,t36,t37) (ATerm)(ATmakeAppl((AFun) s,t0,t1,t2,t3,t4,t5,t6,t7,t8,t9,t10,t11,t12,t13,t14,t15,t16,t17,t18,t19,t20,t21,t22,t23,t24,t25,t26,t27,t28,t29,t30,t31,t32,t33,t34,t35,t36,t37))
#define make_nf39(s,t0,t1,t2,t3,t4,t5,t6,t7,t8,t9,t10,t11,t12,t13,t14,t15,t16,t17,t18,t19,t20,t21,t22,t23,t24,t25,t26,t27,t28,t29,t30,t31,t32,t33,t34,t35,t36,t37,t38) (ATerm)(ATmakeAppl((AFun) s,t0,t1,t2,t3,t4,t5,t6,t7,t8,t9,t10,t11,t12,t13,t14,t15,t16,t17,t18,t19,t20,t21,t22,t23,t24,t25,t26,t27,t28,t29,t30,t31,t32,t33,t34,t35,t36,t37,t38))
#define make_nf40(s,t0,t1,t2,t3,t4,t5,t6,t7,t8,t9,t10,t11,t12,t13,t14,t15,t16,t17,t18,t19,t20,t21,t22,t23,t24,t25,t26,t27,t28,t29,t30,t31,t32,t33,t34,t35,t36,t37,t38,t39) (ATerm)(ATmakeAppl((AFun) s,t0,t1,t2,t3,t4,t5,t6,t7,t8,t9,t10,t11,t12,t13,t14,t15,t16,t17,t18,t19,t20,t21,t22,t23,t24,t25,t26,t27,t28,t29,t30,t31,t32,t33,t34,t35,t36,t37,t38,t39))
#define make_nf41(s,t0,t1,t2,t3,t4,t5,t6,t7,t8,t9,t10,t11,t12,t13,t14,t15,t16,t17,t18,t19,t20,t21,t22,t23,t24,t25,t26,t27,t28,t29,t30,t31,t32,t33,t34,t35,t36,t37,t38,t39,t40) (ATerm)(ATmakeAppl((AFun) s,t0,t1,t2,t3,t4,t5,t6,t7,t8,t9,t10,t11,t12,t13,t14,t15,t16,t17,t18,t19,t20,t21,t22,t23,t24,t25,t26,t27,t28,t29,t30,t31,t32,t33,t34,t35,t36,t37,t38,t39,t40))
#define make_nf42(s,t0,t1,t2,t3,t4,t5,t6,t7,t8,t9,t10,t11,t12,t13,t14,t15,t16,t17,t18,t19,t20,t21,t22,t23,t24,t25,t26,t27,t28,t29,t30,t31,t32,t33,t34,t35,t36,t37,t38,t39,t40,t41) (ATerm)(ATmakeAppl((AFun) s,t0,t1,t2,t3,t4,t5,t6,t7,t8,t9,t10,t11,t12,t13,t14,t15,t16,t17,t18,t19,t20,t21,t22,t23,t24,t25,t26,t27,t28,t29,t30,t31,t32,t33,t34,t35,t36,t37,t38,t39,t40,t41))
#define make_nf43(s,t0,t1,t2,t3,t4,t5,t6,t7,t8,t9,t10,t11,t12,t13,t14,t15,t16,t17,t18,t19,t20,t21,t22,t23,t24,t25,t26,t27,t28,t29,t30,t31,t32,t33,t34,t35,t36,t37,t38,t39,t40,t41,t42) (ATerm)(ATmakeAppl((AFun) s,t0,t1,t2,t3,t4,t5,t6,t7,t8,t9,t10,t11,t12,t13,t14,t15,t16,t17,t18,t19,t20,t21,t22,t23,t24,t25,t26,t27,t28,t29,t30,t31,t32,t33,t34,t35,t36,t37,t38,t39,t40,t41,t42))
#define make_nf44(s,t0,t1,t2,t3,t4,t5,t6,t7,t8,t9,t10,t11,t12,t13,t14,t15,t16,t17,t18,t19,t20,t21,t22,t23,t24,t25,t26,t27,t28,t29,t30,t31,t32,t33,t34,t35,t36,t37,t38,t39,t40,t41,t42,t43) (ATerm)(ATmakeAppl((AFun) s,t0,t1,t2,t3,t4,t5,t6,t7,t8,t9,t10,t11,t12,t13,t14,t15,t16,t17,t18,t19,t20,t21,t22,t23,t24,t25,t26,t27,t28,t29,t30,t31,t32,t33,t34,t35,t36,t37,t38,t39,t40,t41,t42,t43))
#define make_nf45(s,t0,t1,t2,t3,t4,t5,t6,t7,t8,t9,t10,t11,t12,t13,t14,t15,t16,t17,t18,t19,t20,t21,t22,t23,t24,t25,t26,t27,t28,t29,t30,t31,t32,t33,t34,t35,t36,t37,t38,t39,t40,t41,t42,t43,t44) (ATerm)(ATmakeAppl((AFun) s,t0,t1,t2,t3,t4,t5,t6,t7,t8,t9,t10,t11,t12,t13,t14,t15,t16,t17,t18,t19,t20,t21,t22,t23,t24,t25,t26,t27,t28,t29,t30,t31,t32,t33,t34,t35,t36,t37,t38,t39,t40,t41,t42,t43,t44))
#define make_nf46(s,t0,t1,t2,t3,t4,t5,t6,t7,t8,t9,t10,t11,t12,t13,t14,t15,t16,t17,t18,t19,t20,t21,t22,t23,t24,t25,t26,t27,t28,t29,t30,t31,t32,t33,t34,t35,t36,t37,t38,t39,t40,t41,t42,t43,t44,t45) (ATerm)(ATmakeAppl((AFun) s,t0,t1,t2,t3,t4,t5,t6,t7,t8,t9,t10,t11,t12,t13,t14,t15,t16,t17,t18,t19,t20,t21,t22,t23,t24,t25,t26,t27,t28,t29,t30,t31,t32,t33,t34,t35,t36,t37,t38,t39,t40,t41,t42,t43,t44,t45))
#define make_nf47(s,t0,t1,t2,t3,t4,t5,t6,t7,t8,t9,t10,t11,t12,t13,t14,t15,t16,t17,t18,t19,t20,t21,t22,t23,t24,t25,t26,t27,t28,t29,t30,t31,t32,t33,t34,t35,t36,t37,t38,t39,t40,t41,t42,t43,t44,t45,t46) (ATerm)(ATmakeAppl((AFun) s,t0,t1,t2,t3,t4,t5,t6,t7,t8,t9,t10,t11,t12,t13,t14,t15,t16,t17,t18,t19,t20,t21,t22,t23,t24,t25,t26,t27,t28,t29,t30,t31,t32,t33,t34,t35,t36,t37,t38,t39,t40,t41,t42,t43,t44,t45,t46))
#define make_nf48(s,t0,t1,t2,t3,t4,t5,t6,t7,t8,t9,t10,t11,t12,t13,t14,t15,t16,t17,t18,t19,t20,t21,t22,t23,t24,t25,t26,t27,t28,t29,t30,t31,t32,t33,t34,t35,t36,t37,t38,t39,t40,t41,t42,t43,t44,t45,t46,t47) (ATerm)(ATmakeAppl((AFun) s,t0,t1,t2,t3,t4,t5,t6,t7,t8,t9,t10,t11,t12,t13,t14,t15,t16,t17,t18,t19,t20,t21,t22,t23,t24,t25,t26,t27,t28,t29,t30,t31,t32,t33,t34,t35,t36,t37,t38,t39,t40,t41,t42,t43,t44,t45,t46,t47))
#define make_nf49(s,t0,t1,t2,t3,t4,t5,t6,t7,t8,t9,t10,t11,t12,t13,t14,t15,t16,t17,t18,t19,t20,t21,t22,t23,t24,t25,t26,t27,t28,t29,t30,t31,t32,t33,t34,t35,t36,t37,t38,t39,t40,t41,t42,t43,t44,t45,t46,t47,t48) (ATerm)(ATmakeAppl((AFun) s,t0,t1,t2,t3,t4,t5,t6,t7,t8,t9,t10,t11,t12,t13,t14,t15,t16,t17,t18,t19,t20,t21,t22,t23,t24,t25,t26,t27,t28,t29,t30,t31,t32,t33,t34,t35,t36,t37,t38,t39,t40,t41,t42,t43,t44,t45,t46,t47,t48))
#define make_nf50(s,t0,t1,t2,t3,t4,t5,t6,t7,t8,t9,t10,t11,t12,t13,t14,t15,t16,t17,t18,t19,t20,t21,t22,t23,t24,t25,t26,t27,t28,t29,t30,t31,t32,t33,t34,t35,t36,t37,t38,t39,t40,t41,t42,t43,t44,t45,t46,t47,t48,t49) (ATerm)(ATmakeAppl((AFun) s,t0,t1,t2,t3,t4,t5,t6,t7,t8,t9,t10,t11,t12,t13,t14,t15,t16,t17,t18,t19,t20,t21,t22,t23,t24,t25,t26,t27,t28,t29,t30,t31,t32,t33,t34,t35,t36,t37,t38,t39,t40,t41,t42,t43,t44,t45,t46,t47,t48,t49))
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
#define cons(l1,l2) (ATerm)(ATconcat((ATermList)l1,(ATermList)l2))
#define cons_sep_1(l1,s1,l2) ((ATerm) ((ATisEmpty((ATermList) l1) || ATisEmpty((ATermList) l2)) ? ATconcat((ATermList) l1,(ATermList) l2) : ATconcat((ATermList) l1,ATinsert((ATermList) l2,s1))))
#define cons_sep_3(l1,s1,s2,s3,l2) ((ATerm) ((ATisEmpty((ATermList) l1) || ATisEmpty((ATermList) l2)) ? ATconcat((ATermList) l1,(ATermList) l2) : ATconcat((ATermList) l1,ATinsert(ATinsert(ATinsert((ATermList) l2,s3),s2),s1))))
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
extern AFun make_listsym;
extern AFun concsym;
extern AFun conssym;
extern AFun tuplesym;

extern ATerm list_equal(ATerm t1, ATerm t2);
extern ATerm slice(ATerm l1, ATerm l2);
extern ATerm make_list(ATerm t);
extern ATerm get_sort(ATerm tree);
extern ATerm unquote(ATerm t);
extern ATerm call_using_list(funcptr func, ATermList args);
extern ATerm call_kids_trafo(funcptr trav, ATerm arg, ATermList extra_args);
extern ATerm call_kids_accu(funcptr trav, ATerm arg, ATerm accu, 
			    ATermList extra_args);
extern ATerm call_kids_accutrafo(funcptr trav, ATerm arg, ATerm accu, 
				 ATermList extra_args);
extern ATerm call_kids_trafo_with_fail(funcptr trav, ATerm arg, 
				       ATermList extra_args);
extern ATerm call_kids_accu_with_fail(funcptr trav, ATerm arg, ATerm accu, 
				      ATermList extra_args);
extern ATerm call_kids_accutrafo_with_fail(funcptr trav, ATerm arg, ATerm accu, 
					   ATermList extra_args);

extern ATerm correct_tuple(ATerm arg, ATerm rhs);


int asc_support_main(ATerm *bottom, int argc, char *argv[],
                     void (*register_all)(void),
                     void (*resolve_all)(void),
                     void (*init_all)(void),
		     unsigned const char *tableBaf,
		     size_t tableSize, 
		     ATbool parseInput,
		     ATBhandler handler
		     );

/*}}}  */


void setKeepLayout(ATbool on) ;
ATerm callLiteralConstructor(PT_Symbol symbol);
ATerm innermost(PT_Tree tree);
PTBL_ParseTable getParseTable();
void setParseTable(PTBL_ParseTable tbl);
const char *getParseTableID();
ATbool loadParseTable(); 
void initParser(const char *toolname, const char *filename);
void setKeepAnnotations(ATbool on);
void setCid(int cur_cid);
int getCid();

#endif  /* ASC_SUPPORT_H */
