#include  "support.h"
static Symbol lf_AUX_Table_to_Dot13_1sym ;
static ATerm lf_AUX_Table_to_Dot13_1 ( ATerm arg1 , ATerm arg2 ) ;
static Symbol ef1sym ;
static funcptr ef1 ;
static Symbol lf2sym ;
static ATerm lf2 ( ATerm arg1 ) ;
void register_AUX_Table_to_Dot13 ( ) {
lf_AUX_Table_to_Dot13_1sym = ATmakeSymbol ( "prod(id(\"Table-to-Dot\"),w(\"\"),[sort(\"Stmt-List\"),w(\"\"),ql(\"++\"),w(\"\"),sort(\"Stmt-List\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Stmt-List\"),w(\"\"),attrs(l(\"{\"),w(\"\"),[l(\"right\")],w(\"\"),l(\"}\")))"
 , 2 , ATtrue ) ;
ATprotectSymbol ( lf_AUX_Table_to_Dot13_1sym ) ;
lf2sym = ATmakeSymbol ( "listtype(sort(\"Stmt\"),ql(\";\"))" , 1 , ATtrue ) ;
ATprotectSymbol ( lf2sym ) ;
register_prod ( ATparse ( "prod(id(\"Table-to-Dot\"),w(\"\"),[sort(\"Stmt-List\"),w(\"\"),ql(\"++\"),w(\"\"),sort(\"Stmt-List\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Stmt-List\"),w(\"\"),attrs(l(\"{\"),w(\"\"),[l(\"right\")],w(\"\"),l(\"}\")))" ) , lf_AUX_Table_to_Dot13_1 , lf_AUX_Table_to_Dot13_1sym ) ;
register_prod ( ATparse ( "listtype(sort(\"Stmt\"),ql(\";\"))" ) , lf2 , lf2sym ) ;
}
void resolve_AUX_Table_to_Dot13 ( ) {
ef1 = lookup_func ( ATreadFromString ( "prod(id(\"Dot-Graphs\"),w(\"\"),[iter-sep(l(\"{\"),w(\"\"),sort(\"Stmt\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\";\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Stmt-List\"),w(\"\"),no-attrs)" ) ) ;
ef1sym = lookup_sym ( ATreadFromString ( "prod(id(\"Dot-Graphs\"),w(\"\"),[iter-sep(l(\"{\"),w(\"\"),sort(\"Stmt\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\";\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Stmt-List\"),w(\"\"),no-attrs)" ) ) ;
}
void init_AUX_Table_to_Dot13 ( ) {
}
ATerm lf_AUX_Table_to_Dot13_1 ( ATerm arg0 , ATerm arg1 ) {
FUNC_ENTRY ( lf_AUX_Table_to_Dot13_1sym , ATmakeAppl ( lf_AUX_Table_to_Dot13_1sym , arg0 , arg1 ) ) ;
if ( check_sym ( arg0 , ef1sym ) ) {
{
ATerm atmp00 = arg_0 ( arg0 ) ;
if ( check_sym ( atmp00 , lf2sym ) ) {
{
ATerm atmp000 = arg_0 ( atmp00 ) ;
if ( check_sym ( arg1 , ef1sym ) ) {
{
ATerm atmp10 = arg_0 ( arg1 ) ;
if ( check_sym ( atmp10 , lf2sym ) ) {
{
ATerm atmp100 = arg_0 ( atmp10 ) ;
FUNC_EXIT ( ( * ef1 ) ( lf2 ( cons ( make_list ( atmp000 ) , make_list ( atmp100 ) ) ) ) ) ;
}
}
}
}
}
}
}
}
FUNC_EXIT ( make_nf2 ( lf_AUX_Table_to_Dot13_1sym , arg0 , arg1 ) ) ;
}
ATerm lf2 ( ATerm arg0 ) {
CONS_ENTRY ( lf2sym , ATmakeAppl ( lf2sym , arg0 ) ) ;
CONS_EXIT ( make_nf1 ( lf2sym , arg0 ) ) ;
}

