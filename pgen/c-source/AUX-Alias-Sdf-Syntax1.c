#include  "support.h"
static Symbol lf_AUX_Alias_Sdf_Syntax1_1sym ;
static ATerm lf_AUX_Alias_Sdf_Syntax1_1 ( ATerm arg1 , ATerm arg2 ) ;
static Symbol lf_AUX_Alias_Sdf_Syntax1_3sym ;
static ATerm lf_AUX_Alias_Sdf_Syntax1_3 ( ATerm arg1 ) ;
static Symbol lf_AUX_Alias_Sdf_Syntax1_2sym ;
static ATerm lf_AUX_Alias_Sdf_Syntax1_2 ( ATerm arg1 ) ;
void register_AUX_Alias_Sdf_Syntax1 ( ) {
lf_AUX_Alias_Sdf_Syntax1_1sym = ATmakeSymbol ( "prod(id(\"Alias-Sdf-Syntax\"),w(\"\"),[sort(\"Symbol\"),w(\"\"),ql(\"->\"),w(\"\"),sort(\"Symbol\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Alias\"),w(\"\"),no-attrs)"
 , 2 , ATtrue ) ;
ATprotectSymbol ( lf_AUX_Alias_Sdf_Syntax1_1sym ) ;
lf_AUX_Alias_Sdf_Syntax1_3sym = ATmakeSymbol ( "prod(id(\"Alias-Sdf-Syntax\"),w(\"\"),[iter(sort(\"Alias\"),w(\"\"),l(\"*\"))],w(\"\"),l(\"->\"),w(\"\"),sort(\"Aliases\"),w(\"\"),no-attrs)" , 1 , ATtrue ) ;
ATprotectSymbol ( lf_AUX_Alias_Sdf_Syntax1_3sym ) ;
lf_AUX_Alias_Sdf_Syntax1_2sym = ATmakeSymbol ( "listtype(sort(\"Alias\"))" , 1 , ATtrue ) ;
ATprotectSymbol ( lf_AUX_Alias_Sdf_Syntax1_2sym ) ;
register_prod ( ATparse ( "prod(id(\"Alias-Sdf-Syntax\"),w(\"\"),[sort(\"Symbol\"),w(\"\"),ql(\"->\"),w(\"\"),sort(\"Symbol\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Alias\"),w(\"\"),no-attrs)" ) , lf_AUX_Alias_Sdf_Syntax1_1 , lf_AUX_Alias_Sdf_Syntax1_1sym ) ;
register_prod ( ATparse ( "listtype(sort(\"Alias\"))" ) , lf_AUX_Alias_Sdf_Syntax1_2 , lf_AUX_Alias_Sdf_Syntax1_2sym ) ;
register_prod ( ATparse ( "prod(id(\"Alias-Sdf-Syntax\"),w(\"\"),[iter(sort(\"Alias\"),w(\"\"),l(\"*\"))],w(\"\"),l(\"->\"),w(\"\"),sort(\"Aliases\"),w(\"\"),no-attrs)" ) , lf_AUX_Alias_Sdf_Syntax1_3 , lf_AUX_Alias_Sdf_Syntax1_3sym ) ;
}
void resolve_AUX_Alias_Sdf_Syntax1 ( ) {
}
void init_AUX_Alias_Sdf_Syntax1 ( ) {
}
ATerm lf_AUX_Alias_Sdf_Syntax1_2 ( ATerm arg0 ) {
CONS_ENTRY ( lf_AUX_Alias_Sdf_Syntax1_2sym , ATmakeAppl ( lf_AUX_Alias_Sdf_Syntax1_2sym , arg0 ) ) ;
CONS_EXIT ( make_nf1 ( lf_AUX_Alias_Sdf_Syntax1_2sym , arg0 ) ) ;
}
ATerm lf_AUX_Alias_Sdf_Syntax1_3 ( ATerm arg0 ) {
CONS_ENTRY ( lf_AUX_Alias_Sdf_Syntax1_3sym , ATmakeAppl ( lf_AUX_Alias_Sdf_Syntax1_3sym , arg0 ) ) ;
CONS_EXIT ( make_nf1 ( lf_AUX_Alias_Sdf_Syntax1_3sym , arg0 ) ) ;
}
ATerm lf_AUX_Alias_Sdf_Syntax1_1 ( ATerm arg0 , ATerm arg1 ) {
CONS_ENTRY ( lf_AUX_Alias_Sdf_Syntax1_1sym , ATmakeAppl ( lf_AUX_Alias_Sdf_Syntax1_1sym , arg0 , arg1 ) ) ;
CONS_EXIT ( make_nf2 ( lf_AUX_Alias_Sdf_Syntax1_1sym , arg0 , arg1 ) ) ;
}

