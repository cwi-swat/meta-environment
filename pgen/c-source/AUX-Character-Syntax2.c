#include  "support.h"
static Symbol lf_AUX_Character_Syntax2_2sym ;
static ATerm lf_AUX_Character_Syntax2_2 ( ATerm arg1 ) ;
static Symbol lf_AUX_Character_Syntax2_1sym ;
static ATerm lf_AUX_Character_Syntax2_1 ( ATerm arg1 ) ;
void register_AUX_Character_Syntax2 ( ) {
lf_AUX_Character_Syntax2_2sym = ATmakeSymbol ( "prod(id(\"caller\"),w(\"\"),[l(\"numchar\"),w(\"\"),ql(\"(\"),w(\"\"),iter(sort(\"CHAR\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"NumChar\"),w(\"\"),no-attrs)"
 , 1 , ATtrue ) ;
ATprotectSymbol ( lf_AUX_Character_Syntax2_2sym ) ;
lf_AUX_Character_Syntax2_1sym = ATmakeSymbol ( "listtype(sort(\"CHAR\"))" , 1 , ATtrue ) ;
ATprotectSymbol ( lf_AUX_Character_Syntax2_1sym ) ;
register_prod ( ATparse ( "listtype(sort(\"CHAR\"))" ) , lf_AUX_Character_Syntax2_1 , lf_AUX_Character_Syntax2_1sym ) ;
register_prod ( ATparse ( "prod(id(\"caller\"),w(\"\"),[l(\"numchar\"),w(\"\"),ql(\"(\"),w(\"\"),iter(sort(\"CHAR\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"NumChar\"),w(\"\"),no-attrs)" ) , lf_AUX_Character_Syntax2_2 , lf_AUX_Character_Syntax2_2sym ) ;
}
void resolve_AUX_Character_Syntax2 ( ) {
}
void init_AUX_Character_Syntax2 ( ) {
}
ATerm lf_AUX_Character_Syntax2_2 ( ATerm arg0 ) {
{
ATerm tmp [ 2 ] ;
FUNC_ENTRY ( lf_AUX_Character_Syntax2_2sym , ATmakeAppl ( lf_AUX_Character_Syntax2_2sym , arg0 ) ) ;
if ( check_sym ( arg0 , lf_AUX_Character_Syntax2_1sym ) ) {
{
ATerm atmp00 = arg_0 ( arg0 ) ;
if ( not_empty_list ( atmp00 ) ) {
if ( term_equal ( list_head ( atmp00 ) , make_char ( 92 ) ) ) {
tmp [ 0 ] = list_tail ( atmp00 ) ;
if ( not_empty_list ( tmp [ 0 ] ) ) {
if ( term_equal ( list_head ( tmp [ 0 ] ) , make_char ( 48 ) ) ) {
tmp [ 1 ] = list_tail ( tmp [ 0 ] ) ;
if ( not_empty_list ( tmp [ 1 ] ) ) {
FUNC_EXIT ( lf_AUX_Character_Syntax2_2 ( lf_AUX_Character_Syntax2_1 ( cons ( make_list_char ( 92 ) , make_list ( tmp [ 1 ] ) ) ) ) ) ;
}
}
}
}
}
}
}
FUNC_EXIT ( make_nf1 ( lf_AUX_Character_Syntax2_2sym , arg0 ) ) ;
}
}
ATerm lf_AUX_Character_Syntax2_1 ( ATerm arg0 ) {
CONS_ENTRY ( lf_AUX_Character_Syntax2_1sym , ATmakeAppl ( lf_AUX_Character_Syntax2_1sym , arg0 ) ) ;
CONS_EXIT ( make_nf1 ( lf_AUX_Character_Syntax2_1sym , arg0 ) ) ;
}

