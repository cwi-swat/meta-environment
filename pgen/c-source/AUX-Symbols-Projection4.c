#include  "asc-support.h"
static Symbol lf_AUX_Symbols_Projection4_1sym ;
static ATerm lf_AUX_Symbols_Projection4_1 ( ATerm arg1 , ATerm arg2 ) ;
static Symbol ef2sym ;
static funcptr ef2 ;
static Symbol ef1sym ;
static funcptr ef1 ;
static Symbol lf2sym ;
static ATerm lf2 ( ATerm arg1 ) ;
void register_AUX_Symbols_Projection4 ( ) {
lf_AUX_Symbols_Projection4_1sym = ATmakeSymbol ( "prod(id(\"Symbols-Projection\"),w(\"\"),[sort(\"Symbol\"),w(\"\"),ql(\"(-\"),w(\"\"),sort(\"Symbols\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),attrs(l(\"{\"),w(\"\"),[l(\"memo\")],w(\"\"),l(\"}\")))"
 , 2 , ATtrue ) ;
ATprotectSymbol ( lf_AUX_Symbols_Projection4_1sym ) ;
lf2sym = ATmakeSymbol ( "listtype(sort(\"Symbol\"))" , 1 , ATtrue ) ;
ATprotectSymbol ( lf2sym ) ;
register_prod ( ATparse ( "prod(id(\"Symbols-Projection\"),w(\"\"),[sort(\"Symbol\"),w(\"\"),ql(\"(-\"),w(\"\"),sort(\"Symbols\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),attrs(l(\"{\"),w(\"\"),[l(\"memo\")],w(\"\"),l(\"}\")))" ) , lf_AUX_Symbols_Projection4_1 , lf_AUX_Symbols_Projection4_1sym ) ;
register_prod ( ATparse ( "listtype(sort(\"Symbol\"))" ) , lf2 , lf2sym ) ;
}
void resolve_AUX_Symbols_Projection4 ( ) {
ef1 = lookup_func ( ATreadFromString ( "prod(id(\"Symbols\"),w(\"\"),[iter(sort(\"Symbol\"),w(\"\"),l(\"*\"))],w(\"\"),l(\"->\"),w(\"\"),sort(\"Symbols\"),w(\"\"),no-attrs)" ) ) ;
ef1sym = lookup_sym ( ATreadFromString ( "prod(id(\"Symbols\"),w(\"\"),[iter(sort(\"Symbol\"),w(\"\"),l(\"*\"))],w(\"\"),l(\"->\"),w(\"\"),sort(\"Symbols\"),w(\"\"),no-attrs)" ) ) ;
ef2 = lookup_func ( ATreadFromString ( "prod(id(\"Symbols-Projection\"),w(\"\"),[sort(\"Symbol\"),w(\"\"),ql(\"nm-(-\"),w(\"\"),sort(\"Symbols\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)" ) ) ;
ef2sym = lookup_sym ( ATreadFromString ( "prod(id(\"Symbols-Projection\"),w(\"\"),[sort(\"Symbol\"),w(\"\"),ql(\"nm-(-\"),w(\"\"),sort(\"Symbols\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)" ) ) ;
}
static ATermTable table_lf_AUX_Symbols_Projection4_1 ;
void init_AUX_Symbols_Projection4 ( ) {
create_table ( table_lf_AUX_Symbols_Projection4_1 , 0 ) ;
}
ATerm lf_AUX_Symbols_Projection4_1 ( ATerm arg0 , ATerm arg1 ) {
ATerm interm = make_tuple2 ( arg0 , arg1 ) ;
ATermTable table = get_table ( table_lf_AUX_Symbols_Projection4_1 ) ;
ATerm result = get_result ( table , interm ) ;
if ( result ) return result ;
else {
if ( check_sym ( arg1 , ef1sym ) ) {
{
ATerm atmp10 = arg_0 ( arg1 ) ;
if ( check_sym ( atmp10 , lf2sym ) ) {
{
ATerm atmp100 = arg_0 ( atmp10 ) ;
result = ( * ef2 ) ( arg0 , ( * ef1 ) ( lf2 ( make_list ( atmp100 ) ) ) ) ;
put_result ( table , interm , result ) ;
return result ;
}
}
}
}
FUNC_EXIT ( make_nf2 ( lf_AUX_Symbols_Projection4_1sym , arg0 , arg1 ) ) ;
}
}
ATerm lf2 ( ATerm arg0 ) {
CONS_ENTRY ( lf2sym , ATmakeAppl ( lf2sym , arg0 ) ) ;
CONS_EXIT ( make_nf1 ( lf2sym , arg0 ) ) ;
}

