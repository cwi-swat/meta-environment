#include  "asc-support.h"
static Symbol lf_AUX_Priority_Sdf_Syntax1_1sym ;
static ATerm lf_AUX_Priority_Sdf_Syntax1_1 ( ) ;
static Symbol lf_AUX_Priority_Sdf_Syntax1_2sym ;
static ATerm lf_AUX_Priority_Sdf_Syntax1_2 ( ) ;
static Symbol lf_AUX_Priority_Sdf_Syntax1_3sym ;
static ATerm lf_AUX_Priority_Sdf_Syntax1_3 ( ) ;
static Symbol lf_AUX_Priority_Sdf_Syntax1_4sym ;
static ATerm lf_AUX_Priority_Sdf_Syntax1_4 ( ) ;
static Symbol lf_AUX_Priority_Sdf_Syntax1_5sym ;
static ATerm lf_AUX_Priority_Sdf_Syntax1_5 ( ) ;
static Symbol lf_AUX_Priority_Sdf_Syntax1_6sym ;
static ATerm lf_AUX_Priority_Sdf_Syntax1_6 ( ATerm arg1 ) ;
static Symbol lf_AUX_Priority_Sdf_Syntax1_7sym ;
static ATerm lf_AUX_Priority_Sdf_Syntax1_7 ( ATerm arg1 ) ;
static Symbol lf_AUX_Priority_Sdf_Syntax1_8sym ;
static ATerm lf_AUX_Priority_Sdf_Syntax1_8 ( ATerm arg1 ) ;
static Symbol lf_AUX_Priority_Sdf_Syntax1_9sym ;
static ATerm lf_AUX_Priority_Sdf_Syntax1_9 ( ATerm arg1 , ATerm arg2 ) ;
static Symbol lf_AUX_Priority_Sdf_Syntax1_11sym ;
static ATerm lf_AUX_Priority_Sdf_Syntax1_11 ( ATerm arg1 ) ;
static Symbol lf_AUX_Priority_Sdf_Syntax1_10sym ;
static ATerm lf_AUX_Priority_Sdf_Syntax1_10 ( ATerm arg1 ) ;
static Symbol lf_AUX_Priority_Sdf_Syntax1_12sym ;
static ATerm lf_AUX_Priority_Sdf_Syntax1_12 ( ATerm arg1 , ATerm arg2 , ATerm arg3 ) ;
static Symbol lf_AUX_Priority_Sdf_Syntax1_14sym ;
static ATerm lf_AUX_Priority_Sdf_Syntax1_14 ( ATerm arg1 ) ;
static Symbol lf_AUX_Priority_Sdf_Syntax1_13sym ;
static ATerm lf_AUX_Priority_Sdf_Syntax1_13 ( ATerm arg1 ) ;
void register_AUX_Priority_Sdf_Syntax1 ( ) {
lf_AUX_Priority_Sdf_Syntax1_1sym = ATmakeSymbol ( "prod(id(\"Priority-Sdf-Syntax\"),w(\"\"),[ql(\"left\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Associativity\"),w(\"\"),no-attrs)"
 , 0 , ATtrue ) ;
ATprotectSymbol ( lf_AUX_Priority_Sdf_Syntax1_1sym ) ;
lf_AUX_Priority_Sdf_Syntax1_2sym = ATmakeSymbol ( "prod(id(\"Priority-Sdf-Syntax\"),w(\"\"),[ql(\"right\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Associativity\"),w(\"\"),no-attrs)" , 0 , ATtrue ) ;
ATprotectSymbol ( lf_AUX_Priority_Sdf_Syntax1_2sym ) ;
lf_AUX_Priority_Sdf_Syntax1_3sym = ATmakeSymbol ( "prod(id(\"Priority-Sdf-Syntax\"),w(\"\"),[ql(\"non-assoc\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Associativity\"),w(\"\"),no-attrs)" , 0 , ATtrue ) ;
ATprotectSymbol ( lf_AUX_Priority_Sdf_Syntax1_3sym ) ;
lf_AUX_Priority_Sdf_Syntax1_4sym = ATmakeSymbol ( "prod(id(\"Priority-Sdf-Syntax\"),w(\"\"),[ql(\"assoc\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Associativity\"),w(\"\"),no-attrs)" , 0 , ATtrue ) ;
ATprotectSymbol ( lf_AUX_Priority_Sdf_Syntax1_4sym ) ;
lf_AUX_Priority_Sdf_Syntax1_5sym = ATmakeSymbol ( "prod(id(\"Priority-Sdf-Syntax\"),w(\"\"),[ql(\"bracket\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Attribute\"),w(\"\"),no-attrs)" , 0 , ATtrue ) ;
ATprotectSymbol ( lf_AUX_Priority_Sdf_Syntax1_5sym ) ;
lf_AUX_Priority_Sdf_Syntax1_6sym = ATmakeSymbol ( "prod(id(\"Priority-Sdf-Syntax\"),w(\"\"),[sort(\"Associativity\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Attribute\"),w(\"\"),no-attrs)" , 1 , ATtrue ) ;
ATprotectSymbol ( lf_AUX_Priority_Sdf_Syntax1_6sym ) ;
lf_AUX_Priority_Sdf_Syntax1_7sym = ATmakeSymbol ( "prod(id(\"Priority-Sdf-Syntax\"),w(\"\"),[sort(\"Production\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Group\"),w(\"\"),no-attrs)" , 1 , ATtrue ) ;
ATprotectSymbol ( lf_AUX_Priority_Sdf_Syntax1_7sym ) ;
lf_AUX_Priority_Sdf_Syntax1_8sym = ATmakeSymbol ( "prod(id(\"Priority-Sdf-Syntax\"),w(\"\"),[ql(\"{\"),w(\"\"),sort(\"Productions\"),w(\"\"),ql(\"}\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Group\"),w(\"\"),no-attrs)" , 1 , ATtrue ) ;
ATprotectSymbol ( lf_AUX_Priority_Sdf_Syntax1_8sym ) ;
lf_AUX_Priority_Sdf_Syntax1_9sym = ATmakeSymbol ( "prod(id(\"Priority-Sdf-Syntax\"),w(\"\"),[ql(\"{\"),w(\"\"),sort(\"Associativity\"),w(\"\"),ql(\":\"),w(\"\"),sort(\"Productions\"),w(\"\"),ql(\"}\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Group\"),w(\"\"),no-attrs)" , 2 , ATtrue ) ;
ATprotectSymbol ( lf_AUX_Priority_Sdf_Syntax1_9sym ) ;
lf_AUX_Priority_Sdf_Syntax1_11sym = ATmakeSymbol ( "prod(id(\"Priority-Sdf-Syntax\"),w(\"\"),[iter-sep(l(\"{\"),w(\"\"),sort(\"Group\"),w(\"\"),ql(\">\"),w(\"\"),l(\"}\"),w(\"\"),l(\"+\"))],w(\"\"),l(\"->\"),w(\"\"),sort(\"Priority\"),w(\"\"),no-attrs)" , 1 , ATtrue ) ;
ATprotectSymbol ( lf_AUX_Priority_Sdf_Syntax1_11sym ) ;
lf_AUX_Priority_Sdf_Syntax1_10sym = ATmakeSymbol ( "listtype(sort(\"Group\"),ql(\">\"))" , 1 , ATtrue ) ;
ATprotectSymbol ( lf_AUX_Priority_Sdf_Syntax1_10sym ) ;
lf_AUX_Priority_Sdf_Syntax1_12sym = ATmakeSymbol ( "prod(id(\"Priority-Sdf-Syntax\"),w(\"\"),[sort(\"Group\"),w(\"\"),sort(\"Associativity\"),w(\"\"),sort(\"Group\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Priority\"),w(\"\"),no-attrs)" , 3 , ATtrue ) ;
ATprotectSymbol ( lf_AUX_Priority_Sdf_Syntax1_12sym ) ;
lf_AUX_Priority_Sdf_Syntax1_14sym = ATmakeSymbol ( "prod(id(\"Priority-Sdf-Syntax\"),w(\"\"),[iter-sep(l(\"{\"),w(\"\"),sort(\"Priority\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\"))],w(\"\"),l(\"->\"),w(\"\"),sort(\"Priorities\"),w(\"\"),no-attrs)" , 1 , ATtrue ) ;
ATprotectSymbol ( lf_AUX_Priority_Sdf_Syntax1_14sym ) ;
lf_AUX_Priority_Sdf_Syntax1_13sym = ATmakeSymbol ( "listtype(sort(\"Priority\"),ql(\",\"))" , 1 , ATtrue ) ;
ATprotectSymbol ( lf_AUX_Priority_Sdf_Syntax1_13sym ) ;
register_prod ( ATparse ( "prod(id(\"Priority-Sdf-Syntax\"),w(\"\"),[ql(\"left\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Associativity\"),w(\"\"),no-attrs)" ) , lf_AUX_Priority_Sdf_Syntax1_1 , lf_AUX_Priority_Sdf_Syntax1_1sym ) ;
register_prod ( ATparse ( "prod(id(\"Priority-Sdf-Syntax\"),w(\"\"),[ql(\"right\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Associativity\"),w(\"\"),no-attrs)" ) , lf_AUX_Priority_Sdf_Syntax1_2 , lf_AUX_Priority_Sdf_Syntax1_2sym ) ;
register_prod ( ATparse ( "prod(id(\"Priority-Sdf-Syntax\"),w(\"\"),[ql(\"non-assoc\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Associativity\"),w(\"\"),no-attrs)" ) , lf_AUX_Priority_Sdf_Syntax1_3 , lf_AUX_Priority_Sdf_Syntax1_3sym ) ;
register_prod ( ATparse ( "prod(id(\"Priority-Sdf-Syntax\"),w(\"\"),[ql(\"assoc\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Associativity\"),w(\"\"),no-attrs)" ) , lf_AUX_Priority_Sdf_Syntax1_4 , lf_AUX_Priority_Sdf_Syntax1_4sym ) ;
register_prod ( ATparse ( "prod(id(\"Priority-Sdf-Syntax\"),w(\"\"),[ql(\"bracket\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Attribute\"),w(\"\"),no-attrs)" ) , lf_AUX_Priority_Sdf_Syntax1_5 , lf_AUX_Priority_Sdf_Syntax1_5sym ) ;
register_prod ( ATparse ( "prod(id(\"Priority-Sdf-Syntax\"),w(\"\"),[sort(\"Associativity\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Attribute\"),w(\"\"),no-attrs)" ) , lf_AUX_Priority_Sdf_Syntax1_6 , lf_AUX_Priority_Sdf_Syntax1_6sym ) ;
register_prod ( ATparse ( "prod(id(\"Priority-Sdf-Syntax\"),w(\"\"),[sort(\"Production\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Group\"),w(\"\"),no-attrs)" ) , lf_AUX_Priority_Sdf_Syntax1_7 , lf_AUX_Priority_Sdf_Syntax1_7sym ) ;
register_prod ( ATparse ( "prod(id(\"Priority-Sdf-Syntax\"),w(\"\"),[ql(\"{\"),w(\"\"),sort(\"Productions\"),w(\"\"),ql(\"}\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Group\"),w(\"\"),no-attrs)" ) , lf_AUX_Priority_Sdf_Syntax1_8 , lf_AUX_Priority_Sdf_Syntax1_8sym ) ;
register_prod ( ATparse ( "prod(id(\"Priority-Sdf-Syntax\"),w(\"\"),[ql(\"{\"),w(\"\"),sort(\"Associativity\"),w(\"\"),ql(\":\"),w(\"\"),sort(\"Productions\"),w(\"\"),ql(\"}\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Group\"),w(\"\"),no-attrs)" ) , lf_AUX_Priority_Sdf_Syntax1_9 , lf_AUX_Priority_Sdf_Syntax1_9sym ) ;
register_prod ( ATparse ( "listtype(sort(\"Group\"),ql(\">\"))" ) , lf_AUX_Priority_Sdf_Syntax1_10 , lf_AUX_Priority_Sdf_Syntax1_10sym ) ;
register_prod ( ATparse ( "prod(id(\"Priority-Sdf-Syntax\"),w(\"\"),[iter-sep(l(\"{\"),w(\"\"),sort(\"Group\"),w(\"\"),ql(\">\"),w(\"\"),l(\"}\"),w(\"\"),l(\"+\"))],w(\"\"),l(\"->\"),w(\"\"),sort(\"Priority\"),w(\"\"),no-attrs)" ) , lf_AUX_Priority_Sdf_Syntax1_11 , lf_AUX_Priority_Sdf_Syntax1_11sym ) ;
register_prod ( ATparse ( "prod(id(\"Priority-Sdf-Syntax\"),w(\"\"),[sort(\"Group\"),w(\"\"),sort(\"Associativity\"),w(\"\"),sort(\"Group\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Priority\"),w(\"\"),no-attrs)" ) , lf_AUX_Priority_Sdf_Syntax1_12 , lf_AUX_Priority_Sdf_Syntax1_12sym ) ;
register_prod ( ATparse ( "listtype(sort(\"Priority\"),ql(\",\"))" ) , lf_AUX_Priority_Sdf_Syntax1_13 , lf_AUX_Priority_Sdf_Syntax1_13sym ) ;
register_prod ( ATparse ( "prod(id(\"Priority-Sdf-Syntax\"),w(\"\"),[iter-sep(l(\"{\"),w(\"\"),sort(\"Priority\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\"))],w(\"\"),l(\"->\"),w(\"\"),sort(\"Priorities\"),w(\"\"),no-attrs)" ) , lf_AUX_Priority_Sdf_Syntax1_14 , lf_AUX_Priority_Sdf_Syntax1_14sym ) ;
}
void resolve_AUX_Priority_Sdf_Syntax1 ( ) {
}
static ATerm constant0 = NULL ;
static ATerm constant1 = NULL ;
static ATerm constant2 = NULL ;
static ATerm constant3 = NULL ;
static ATerm constant4 = NULL ;
void init_AUX_Priority_Sdf_Syntax1 ( ) {
ATprotect ( & constant0 ) ;
ATprotect ( & constant1 ) ;
ATprotect ( & constant2 ) ;
ATprotect ( & constant3 ) ;
ATprotect ( & constant4 ) ;
}
ATerm lf_AUX_Priority_Sdf_Syntax1_13 ( ATerm arg0 ) {
CONS_ENTRY ( lf_AUX_Priority_Sdf_Syntax1_13sym , ATmakeAppl ( lf_AUX_Priority_Sdf_Syntax1_13sym , arg0 ) ) ;
CONS_EXIT ( make_nf1 ( lf_AUX_Priority_Sdf_Syntax1_13sym , arg0 ) ) ;
}
ATerm lf_AUX_Priority_Sdf_Syntax1_14 ( ATerm arg0 ) {
CONS_ENTRY ( lf_AUX_Priority_Sdf_Syntax1_14sym , ATmakeAppl ( lf_AUX_Priority_Sdf_Syntax1_14sym , arg0 ) ) ;
CONS_EXIT ( make_nf1 ( lf_AUX_Priority_Sdf_Syntax1_14sym , arg0 ) ) ;
}
ATerm lf_AUX_Priority_Sdf_Syntax1_12 ( ATerm arg0 , ATerm arg1 , ATerm arg2 ) {
CONS_ENTRY ( lf_AUX_Priority_Sdf_Syntax1_12sym , ATmakeAppl ( lf_AUX_Priority_Sdf_Syntax1_12sym , arg0 , arg1 , arg2 ) ) ;
CONS_EXIT ( make_nf3 ( lf_AUX_Priority_Sdf_Syntax1_12sym , arg0 , arg1 , arg2 ) ) ;
}
ATerm lf_AUX_Priority_Sdf_Syntax1_10 ( ATerm arg0 ) {
CONS_ENTRY ( lf_AUX_Priority_Sdf_Syntax1_10sym , ATmakeAppl ( lf_AUX_Priority_Sdf_Syntax1_10sym , arg0 ) ) ;
CONS_EXIT ( make_nf1 ( lf_AUX_Priority_Sdf_Syntax1_10sym , arg0 ) ) ;
}
ATerm lf_AUX_Priority_Sdf_Syntax1_11 ( ATerm arg0 ) {
CONS_ENTRY ( lf_AUX_Priority_Sdf_Syntax1_11sym , ATmakeAppl ( lf_AUX_Priority_Sdf_Syntax1_11sym , arg0 ) ) ;
CONS_EXIT ( make_nf1 ( lf_AUX_Priority_Sdf_Syntax1_11sym , arg0 ) ) ;
}
ATerm lf_AUX_Priority_Sdf_Syntax1_9 ( ATerm arg0 , ATerm arg1 ) {
CONS_ENTRY ( lf_AUX_Priority_Sdf_Syntax1_9sym , ATmakeAppl ( lf_AUX_Priority_Sdf_Syntax1_9sym , arg0 , arg1 ) ) ;
CONS_EXIT ( make_nf2 ( lf_AUX_Priority_Sdf_Syntax1_9sym , arg0 , arg1 ) ) ;
}
ATerm lf_AUX_Priority_Sdf_Syntax1_8 ( ATerm arg0 ) {
CONS_ENTRY ( lf_AUX_Priority_Sdf_Syntax1_8sym , ATmakeAppl ( lf_AUX_Priority_Sdf_Syntax1_8sym , arg0 ) ) ;
CONS_EXIT ( make_nf1 ( lf_AUX_Priority_Sdf_Syntax1_8sym , arg0 ) ) ;
}
ATerm lf_AUX_Priority_Sdf_Syntax1_7 ( ATerm arg0 ) {
CONS_ENTRY ( lf_AUX_Priority_Sdf_Syntax1_7sym , ATmakeAppl ( lf_AUX_Priority_Sdf_Syntax1_7sym , arg0 ) ) ;
CONS_EXIT ( make_nf1 ( lf_AUX_Priority_Sdf_Syntax1_7sym , arg0 ) ) ;
}
ATerm lf_AUX_Priority_Sdf_Syntax1_6 ( ATerm arg0 ) {
CONS_ENTRY ( lf_AUX_Priority_Sdf_Syntax1_6sym , ATmakeAppl ( lf_AUX_Priority_Sdf_Syntax1_6sym , arg0 ) ) ;
CONS_EXIT ( make_nf1 ( lf_AUX_Priority_Sdf_Syntax1_6sym , arg0 ) ) ;
}
ATerm lf_AUX_Priority_Sdf_Syntax1_5 ( ) {
CONS_ENTRY ( lf_AUX_Priority_Sdf_Syntax1_5sym , ATmakeAppl0 ( lf_AUX_Priority_Sdf_Syntax1_5sym ) ) ;
CONS_EXIT_CONST ( constant0 , make_nf0 ( lf_AUX_Priority_Sdf_Syntax1_5sym ) ) ;
}
ATerm lf_AUX_Priority_Sdf_Syntax1_4 ( ) {
CONS_ENTRY ( lf_AUX_Priority_Sdf_Syntax1_4sym , ATmakeAppl0 ( lf_AUX_Priority_Sdf_Syntax1_4sym ) ) ;
CONS_EXIT_CONST ( constant1 , make_nf0 ( lf_AUX_Priority_Sdf_Syntax1_4sym ) ) ;
}
ATerm lf_AUX_Priority_Sdf_Syntax1_3 ( ) {
CONS_ENTRY ( lf_AUX_Priority_Sdf_Syntax1_3sym , ATmakeAppl0 ( lf_AUX_Priority_Sdf_Syntax1_3sym ) ) ;
CONS_EXIT_CONST ( constant2 , make_nf0 ( lf_AUX_Priority_Sdf_Syntax1_3sym ) ) ;
}
ATerm lf_AUX_Priority_Sdf_Syntax1_2 ( ) {
CONS_ENTRY ( lf_AUX_Priority_Sdf_Syntax1_2sym , ATmakeAppl0 ( lf_AUX_Priority_Sdf_Syntax1_2sym ) ) ;
CONS_EXIT_CONST ( constant3 , make_nf0 ( lf_AUX_Priority_Sdf_Syntax1_2sym ) ) ;
}
ATerm lf_AUX_Priority_Sdf_Syntax1_1 ( ) {
CONS_ENTRY ( lf_AUX_Priority_Sdf_Syntax1_1sym , ATmakeAppl0 ( lf_AUX_Priority_Sdf_Syntax1_1sym ) ) ;
CONS_EXIT_CONST ( constant4 , make_nf0 ( lf_AUX_Priority_Sdf_Syntax1_1sym ) ) ;
}

