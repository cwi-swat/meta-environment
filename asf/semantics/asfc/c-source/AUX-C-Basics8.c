#include  "support.h"
static Symbol lf_AUX_C_Basics8_1sym ;
static ATerm lf_AUX_C_Basics8_1 ( ATerm arg1 , ATerm arg2 ) ;
static Symbol ef1sym ;
static funcptr ef1 ;
static Symbol lf2sym ;
static ATerm lf2 ( ATerm arg1 ) ;
void register_AUX_C_Basics8 ( ) {
lf_AUX_C_Basics8_1sym = ATmakeSymbol ( "prod(id(\"C-Basics\"),w(\"\"),[sort(\"Parameter-declaration\"),w(\"\"),ql(\"++\"),w(\"\"),sort(\"Parameter-list\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Parameter-list\"),w(\"\"),no-attrs)"
 , 2 , ATtrue ) ;
ATprotectSymbol ( lf_AUX_C_Basics8_1sym ) ;
lf2sym = ATmakeSymbol ( "listtype(sort(\"Parameter-declaration\"),ql(\",\"))" , 1 , ATtrue ) ;
ATprotectSymbol ( lf2sym ) ;
register_prod ( ATparse ( "prod(id(\"C-Basics\"),w(\"\"),[sort(\"Parameter-declaration\"),w(\"\"),ql(\"++\"),w(\"\"),sort(\"Parameter-list\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Parameter-list\"),w(\"\"),no-attrs)" ) , lf_AUX_C_Basics8_1 , lf_AUX_C_Basics8_1sym ) ;
register_prod ( ATparse ( "listtype(sort(\"Parameter-declaration\"),ql(\",\"))" ) , lf2 , lf2sym ) ;
}
void resolve_AUX_C_Basics8 ( ) {
ef1 = lookup_func ( ATreadFromString ( "prod(id(\"Pure-C\"),w(\"\"),[iter-sep(l(\"{\"),w(\"\"),sort(\"Parameter-declaration\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\"))],w(\"\"),l(\"->\"),w(\"\"),sort(\"Parameter-list\"),w(\"\"),no-attrs)" ) ) ;
ef1sym = lookup_sym ( ATreadFromString ( "prod(id(\"Pure-C\"),w(\"\"),[iter-sep(l(\"{\"),w(\"\"),sort(\"Parameter-declaration\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\"))],w(\"\"),l(\"->\"),w(\"\"),sort(\"Parameter-list\"),w(\"\"),no-attrs)" ) ) ;
}
void init_AUX_C_Basics8 ( ) {
}
ATerm lf_AUX_C_Basics8_1 ( ATerm arg0 , ATerm arg1 ) {
PROF ( prof_lf_AUX_C_Basics8_1 ) ;
if ( check_sym ( arg1 , ef1sym ) ) {
{
ATerm atmp10 = arg_0 ( arg1 ) ;
if ( check_sym ( atmp10 , lf2sym ) ) {
{
ATerm atmp100 = arg_0 ( atmp10 ) ;
if ( not_empty_list ( atmp100 ) ) {
return ( * ef1 ) ( lf2 ( cons ( make_list ( arg0 ) , make_list ( atmp100 ) ) ) ) ;
}
}
}
}
}
return make_nf2 ( lf_AUX_C_Basics8_1sym , arg0 , arg1 ) ;
}
ATerm lf2 ( ATerm arg0 ) {
PROF ( prof_lf2 ) ;
return make_nf1 ( lf2sym , arg0 ) ;
}

