#include  "asc-support.h"
static Symbol lf_AUX_Goto_Computation4_1sym ;
static ATerm lf_AUX_Goto_Computation4_1 ( ATerm arg1 ) ;
static Symbol ef1sym ;
static funcptr ef1 ;
static Symbol ef2sym ;
static funcptr ef2 ;
static Symbol ef3sym ;
static funcptr ef3 ;
static Symbol ef4sym ;
static funcptr ef4 ;
static Symbol ef5sym ;
static funcptr ef5 ;
static Symbol ef6sym ;
static funcptr ef6 ;
void register_AUX_Goto_Computation4 ( ) {
lf_AUX_Goto_Computation4_1sym = ATmakeSymbol ( "prod(id(\"Goto-Computation\"),w(\"\"),[l(\"init-table\"),w(\"\"),ql(\"[[\"),w(\"\"),sort(\"Grammar\"),w(\"\"),ql(\"]]\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Parse-Table\"),w(\"\"),attrs(l(\"{\"),w(\"\"),[l(\"parameter\")],w(\"\"),l(\"}\")))"
 , 1 , ATtrue ) ;
ATprotectSymbol ( lf_AUX_Goto_Computation4_1sym ) ;
register_prod ( ATparse ( "prod(id(\"Goto-Computation\"),w(\"\"),[l(\"init-table\"),w(\"\"),ql(\"[[\"),w(\"\"),sort(\"Grammar\"),w(\"\"),ql(\"]]\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Parse-Table\"),w(\"\"),attrs(l(\"{\"),w(\"\"),[l(\"parameter\")],w(\"\"),l(\"}\")))" ) , lf_AUX_Goto_Computation4_1 , lf_AUX_Goto_Computation4_1sym ) ;
}
void resolve_AUX_Goto_Computation4 ( ) {
ef1 = lookup_func ( ATreadFromString ( "prod(id(\"Parse-Table\"),w(\"\"),[sort(\"Parse-Table\"),w(\"\"),ql(\"[\"),w(\"\"),l(\"labels\"),w(\"\"),ql(\":=\"),w(\"\"),sort(\"Label-Table\"),w(\"\"),ql(\"]\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Parse-Table\"),w(\"\"),no-attrs)" ) ) ;
ef1sym = lookup_sym ( ATreadFromString ( "prod(id(\"Parse-Table\"),w(\"\"),[sort(\"Parse-Table\"),w(\"\"),ql(\"[\"),w(\"\"),l(\"labels\"),w(\"\"),ql(\":=\"),w(\"\"),sort(\"Label-Table\"),w(\"\"),ql(\"]\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Parse-Table\"),w(\"\"),no-attrs)" ) ) ;
ef2 = lookup_func ( ATreadFromString ( "prod(id(\"Parse-Table\"),w(\"\"),[sort(\"Parse-Table\"),w(\"\"),ql(\"[\"),w(\"\"),l(\"follow\"),w(\"\"),ql(\":=\"),w(\"\"),sort(\"Symbol-Table\"),w(\"\"),ql(\"]\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Parse-Table\"),w(\"\"),no-attrs)" ) ) ;
ef2sym = lookup_sym ( ATreadFromString ( "prod(id(\"Parse-Table\"),w(\"\"),[sort(\"Parse-Table\"),w(\"\"),ql(\"[\"),w(\"\"),l(\"follow\"),w(\"\"),ql(\":=\"),w(\"\"),sort(\"Symbol-Table\"),w(\"\"),ql(\"]\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Parse-Table\"),w(\"\"),no-attrs)" ) ) ;
ef3 = lookup_func ( ATreadFromString ( "prod(id(\"Parse-Table\"),w(\"\"),[sort(\"Parse-Table\"),w(\"\"),ql(\"[\"),w(\"\"),l(\"grammar\"),w(\"\"),ql(\":=\"),w(\"\"),sort(\"Grammar\"),w(\"\"),ql(\"]\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Parse-Table\"),w(\"\"),no-attrs)" ) ) ;
ef3sym = lookup_sym ( ATreadFromString ( "prod(id(\"Parse-Table\"),w(\"\"),[sort(\"Parse-Table\"),w(\"\"),ql(\"[\"),w(\"\"),l(\"grammar\"),w(\"\"),ql(\":=\"),w(\"\"),sort(\"Grammar\"),w(\"\"),ql(\"]\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Parse-Table\"),w(\"\"),no-attrs)" ) ) ;
ef4 = lookup_func ( ATreadFromString ( "prod(id(\"Parse-Table\"),w(\"\"),[l(\"new-table\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Parse-Table\"),w(\"\"),no-attrs)" ) ) ;
ef4sym = lookup_sym ( ATreadFromString ( "prod(id(\"Parse-Table\"),w(\"\"),[l(\"new-table\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Parse-Table\"),w(\"\"),no-attrs)" ) ) ;
ef5 = lookup_func ( ATreadFromString ( "prod(id(\"Action-Earley\"),w(\"\"),[l(\"filter-follow\"),w(\"\"),ql(\"[[\"),w(\"\"),sort(\"Grammar\"),w(\"\"),ql(\"]]\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Symbol-Table\"),w(\"\"),attrs(l(\"{\"),w(\"\"),[l(\"parameter\")],w(\"\"),l(\"}\")))" ) ) ;
ef5sym = lookup_sym ( ATreadFromString ( "prod(id(\"Action-Earley\"),w(\"\"),[l(\"filter-follow\"),w(\"\"),ql(\"[[\"),w(\"\"),sort(\"Grammar\"),w(\"\"),ql(\"]]\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Symbol-Table\"),w(\"\"),attrs(l(\"{\"),w(\"\"),[l(\"parameter\")],w(\"\"),l(\"}\")))" ) ) ;
ef6 = lookup_func ( ATreadFromString ( "prod(id(\"Action-Earley\"),w(\"\"),[l(\"init-labels\"),w(\"\"),ql(\"[[\"),w(\"\"),sort(\"Grammar\"),w(\"\"),ql(\"]]\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Label-Table\"),w(\"\"),no-attrs)" ) ) ;
ef6sym = lookup_sym ( ATreadFromString ( "prod(id(\"Action-Earley\"),w(\"\"),[l(\"init-labels\"),w(\"\"),ql(\"[[\"),w(\"\"),sort(\"Grammar\"),w(\"\"),ql(\"]]\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Label-Table\"),w(\"\"),no-attrs)" ) ) ;
}
void init_AUX_Goto_Computation4 ( ) {
}
ATerm lf_AUX_Goto_Computation4_1 ( ATerm arg0 ) {
FUNC_ENTRY ( lf_AUX_Goto_Computation4_1sym , ATmakeAppl ( lf_AUX_Goto_Computation4_1sym , arg0 ) ) ;
FUNC_EXIT ( ( * ef1 ) ( ( * ef2 ) ( ( * ef3 ) ( ( * ef4 ) ( ) , arg0 ) , ( * ef5 ) ( arg0 ) ) , ( * ef6 ) ( arg0 ) ) ) ;
FUNC_EXIT ( make_nf1 ( lf_AUX_Goto_Computation4_1sym , arg0 ) ) ;
}

