#include  "asc-support.h"
static Symbol lf_AUX_RenameVars1_1sym ;
static ATerm lf_AUX_RenameVars1_1 ( ATerm arg1 , ATerm arg2 ) ;
static Symbol lf_AUX_RenameVars1_3sym ;
static ATerm lf_AUX_RenameVars1_3 ( ATerm arg1 , ATerm arg2 ) ;
static Symbol lf_AUX_RenameVars1_2sym ;
static ATerm lf_AUX_RenameVars1_2 ( ATerm arg1 ) ;
static Symbol lf_AUX_RenameVars1_4sym ;
static ATerm lf_AUX_RenameVars1_4 ( ATerm arg1 , ATerm arg2 ) ;
static Symbol lf_AUX_RenameVars1_6sym ;
static ATerm lf_AUX_RenameVars1_6 ( ATerm arg1 , ATerm arg2 ) ;
static Symbol lf_AUX_RenameVars1_5sym ;
static ATerm lf_AUX_RenameVars1_5 ( ATerm arg1 ) ;
void register_AUX_RenameVars1 ( ) {
lf_AUX_RenameVars1_1sym = ATmakeSymbol ( "prod(id(\"RenameVars\"),w(\"\"),[ql(\"[\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"IntVVarEnv\"),w(\"\"),ql(\"]\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"TIVE\"),w(\"\"),no-attrs)"
 , 2 , ATtrue ) ;
ATprotectSymbol ( lf_AUX_RenameVars1_1sym ) ;
lf_AUX_RenameVars1_3sym = ATmakeSymbol ( "prod(id(\"RenameVars\"),w(\"\"),[ql(\"[\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\",\"),w(\"\"),sort(\"IntVVarEnv\"),w(\"\"),ql(\"]\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"TIVEs\"),w(\"\"),no-attrs)" , 2 , ATtrue ) ;
ATprotectSymbol ( lf_AUX_RenameVars1_3sym ) ;
lf_AUX_RenameVars1_2sym = ATmakeSymbol ( "listtype(sort(\"Term\"),ql(\",\"))" , 1 , ATtrue ) ;
ATprotectSymbol ( lf_AUX_RenameVars1_2sym ) ;
lf_AUX_RenameVars1_4sym = ATmakeSymbol ( "prod(id(\"RenameVars\"),w(\"\"),[ql(\"[\"),w(\"\"),sort(\"Cond\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"IntVVarEnv\"),w(\"\"),ql(\"]\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"CIVE\"),w(\"\"),no-attrs)" , 2 , ATtrue ) ;
ATprotectSymbol ( lf_AUX_RenameVars1_4sym ) ;
lf_AUX_RenameVars1_6sym = ATmakeSymbol ( "prod(id(\"RenameVars\"),w(\"\"),[ql(\"[\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Cond\"),w(\"\"),ql(\"&\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\",\"),w(\"\"),sort(\"IntVVarEnv\"),w(\"\"),ql(\"]\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"CIVEs\"),w(\"\"),no-attrs)" , 2 , ATtrue ) ;
ATprotectSymbol ( lf_AUX_RenameVars1_6sym ) ;
lf_AUX_RenameVars1_5sym = ATmakeSymbol ( "listtype(sort(\"Cond\"),ql(\"&\"))" , 1 , ATtrue ) ;
ATprotectSymbol ( lf_AUX_RenameVars1_5sym ) ;
register_prod ( ATparse ( "prod(id(\"RenameVars\"),w(\"\"),[ql(\"[\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"IntVVarEnv\"),w(\"\"),ql(\"]\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"TIVE\"),w(\"\"),no-attrs)" ) , lf_AUX_RenameVars1_1 , lf_AUX_RenameVars1_1sym ) ;
register_prod ( ATparse ( "listtype(sort(\"Term\"),ql(\",\"))" ) , lf_AUX_RenameVars1_2 , lf_AUX_RenameVars1_2sym ) ;
register_prod ( ATparse ( "prod(id(\"RenameVars\"),w(\"\"),[ql(\"[\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\",\"),w(\"\"),sort(\"IntVVarEnv\"),w(\"\"),ql(\"]\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"TIVEs\"),w(\"\"),no-attrs)" ) , lf_AUX_RenameVars1_3 , lf_AUX_RenameVars1_3sym ) ;
register_prod ( ATparse ( "prod(id(\"RenameVars\"),w(\"\"),[ql(\"[\"),w(\"\"),sort(\"Cond\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"IntVVarEnv\"),w(\"\"),ql(\"]\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"CIVE\"),w(\"\"),no-attrs)" ) , lf_AUX_RenameVars1_4 , lf_AUX_RenameVars1_4sym ) ;
register_prod ( ATparse ( "listtype(sort(\"Cond\"),ql(\"&\"))" ) , lf_AUX_RenameVars1_5 , lf_AUX_RenameVars1_5sym ) ;
register_prod ( ATparse ( "prod(id(\"RenameVars\"),w(\"\"),[ql(\"[\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Cond\"),w(\"\"),ql(\"&\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\",\"),w(\"\"),sort(\"IntVVarEnv\"),w(\"\"),ql(\"]\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"CIVEs\"),w(\"\"),no-attrs)" ) , lf_AUX_RenameVars1_6 , lf_AUX_RenameVars1_6sym ) ;
}
void resolve_AUX_RenameVars1 ( ) {
}
void init_AUX_RenameVars1 ( ) {
}
ATerm lf_AUX_RenameVars1_5 ( ATerm arg0 ) {
CONS_ENTRY ( lf_AUX_RenameVars1_5sym , ATmakeAppl ( lf_AUX_RenameVars1_5sym , arg0 ) ) ;
CONS_EXIT ( make_nf1 ( lf_AUX_RenameVars1_5sym , arg0 ) ) ;
}
ATerm lf_AUX_RenameVars1_6 ( ATerm arg0 , ATerm arg1 ) {
CONS_ENTRY ( lf_AUX_RenameVars1_6sym , ATmakeAppl ( lf_AUX_RenameVars1_6sym , arg0 , arg1 ) ) ;
CONS_EXIT ( make_nf2 ( lf_AUX_RenameVars1_6sym , arg0 , arg1 ) ) ;
}
ATerm lf_AUX_RenameVars1_4 ( ATerm arg0 , ATerm arg1 ) {
CONS_ENTRY ( lf_AUX_RenameVars1_4sym , ATmakeAppl ( lf_AUX_RenameVars1_4sym , arg0 , arg1 ) ) ;
CONS_EXIT ( make_nf2 ( lf_AUX_RenameVars1_4sym , arg0 , arg1 ) ) ;
}
ATerm lf_AUX_RenameVars1_2 ( ATerm arg0 ) {
CONS_ENTRY ( lf_AUX_RenameVars1_2sym , ATmakeAppl ( lf_AUX_RenameVars1_2sym , arg0 ) ) ;
CONS_EXIT ( make_nf1 ( lf_AUX_RenameVars1_2sym , arg0 ) ) ;
}
ATerm lf_AUX_RenameVars1_3 ( ATerm arg0 , ATerm arg1 ) {
CONS_ENTRY ( lf_AUX_RenameVars1_3sym , ATmakeAppl ( lf_AUX_RenameVars1_3sym , arg0 , arg1 ) ) ;
CONS_EXIT ( make_nf2 ( lf_AUX_RenameVars1_3sym , arg0 , arg1 ) ) ;
}
ATerm lf_AUX_RenameVars1_1 ( ATerm arg0 , ATerm arg1 ) {
CONS_ENTRY ( lf_AUX_RenameVars1_1sym , ATmakeAppl ( lf_AUX_RenameVars1_1sym , arg0 , arg1 ) ) ;
CONS_EXIT ( make_nf2 ( lf_AUX_RenameVars1_1sym , arg0 , arg1 ) ) ;
}

