#include  "support.h"
static Symbol lf_AUX_C_Basics16_1sym ;
static ATerm lf_AUX_C_Basics16_1 ( ATerm arg1 ) ;
static Symbol ef1sym ;
static funcptr ef1 ;
static Symbol ef2sym ;
static funcptr ef2 ;
static Symbol lf2sym ;
static ATerm lf2 ( ATerm arg1 ) ;
void register_AUX_C_Basics16 ( ) {
lf_AUX_C_Basics16_1sym = ATmakeSymbol ( "prod(id(\"C-Basics\"),w(\"\"),[l(\"make-id-name\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Identifier\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FunId\"),w(\"\"),no-attrs)"
 , 1 , ATtrue ) ;
ATprotectSymbol ( lf_AUX_C_Basics16_1sym ) ;
lf2sym = ATmakeSymbol ( "listtype(sort(\"CHAR\"))" , 1 , ATtrue ) ;
ATprotectSymbol ( lf2sym ) ;
register_prod ( ATparse ( "prod(id(\"C-Basics\"),w(\"\"),[l(\"make-id-name\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Identifier\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FunId\"),w(\"\"),no-attrs)" ) , lf_AUX_C_Basics16_1 , lf_AUX_C_Basics16_1sym ) ;
register_prod ( ATparse ( "listtype(sort(\"CHAR\"))" ) , lf2 , lf2sym ) ;
}
void resolve_AUX_C_Basics16 ( ) {
ef1 = lookup_func ( ATreadFromString ( "prod(id(\"caller\"),w(\"\"),[l(\"identifier\"),w(\"\"),ql(\"(\"),w(\"\"),iter(sort(\"CHAR\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Identifier\"),w(\"\"),no-attrs)" ) ) ;
ef1sym = lookup_sym ( ATreadFromString ( "prod(id(\"caller\"),w(\"\"),[l(\"identifier\"),w(\"\"),ql(\"(\"),w(\"\"),iter(sort(\"CHAR\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Identifier\"),w(\"\"),no-attrs)" ) ) ;
ef2 = lookup_func ( ATreadFromString ( "prod(id(\"caller\"),w(\"\"),[l(\"funid\"),w(\"\"),ql(\"(\"),w(\"\"),iter(sort(\"CHAR\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FunId\"),w(\"\"),no-attrs)" ) ) ;
ef2sym = lookup_sym ( ATreadFromString ( "prod(id(\"caller\"),w(\"\"),[l(\"funid\"),w(\"\"),ql(\"(\"),w(\"\"),iter(sort(\"CHAR\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FunId\"),w(\"\"),no-attrs)" ) ) ;
}
static ATerm constant0 = NULL ;
void init_AUX_C_Basics16 ( ) {
ATprotect ( & constant0 ) ;
}
ATerm lf_AUX_C_Basics16_1 ( ATerm arg0 ) {
{
ATerm tmp [ 5 ] ;
FUNC_ENTRY ( lf_AUX_C_Basics16_1sym , ATmakeAppl ( lf_AUX_C_Basics16_1sym , arg0 ) ) ;
if ( check_sym ( arg0 , ef1sym ) ) {
{
ATerm atmp00 = arg_0 ( arg0 ) ;
if ( check_sym ( atmp00 , lf2sym ) ) {
{
ATerm atmp000 = arg_0 ( atmp00 ) ;
if ( is_single_element ( atmp000 ) ) {
if ( term_equal ( list_head ( atmp000 ) , make_char ( 95 ) ) ) {
FUNC_EXIT_CONST ( constant0 , ( * ef2 ) ( lf2 ( make_list ( make_char ( 45 ) ) ) ) ) ;
}
tmp [ 0 ] = list_head ( atmp000 ) ;
if ( ! term_equal ( ( * ef1 ) ( lf2 ( make_list ( tmp [ 0 ] ) ) ) , ( * ef1 ) ( lf2 ( make_list ( make_char ( 95 ) ) ) ) ) ) {
FUNC_EXIT ( ( * ef2 ) ( lf2 ( make_list ( tmp [ 0 ] ) ) ) ) ;
}
}
{
if ( not_empty_list ( atmp000 ) ) {
if ( term_equal ( list_head ( atmp000 ) , make_char ( 95 ) ) ) {
tmp [ 0 ] = list_tail ( atmp000 ) ;
tmp [ 1 ] = lf_AUX_C_Basics16_1 ( ( * ef1 ) ( lf2 ( make_list ( tmp [ 0 ] ) ) ) ) ;
if ( check_sym ( tmp [ 1 ] , ef2sym ) ) {
tmp [ 2 ] = arg_0 ( tmp [ 1 ] ) ;
if ( check_sym ( tmp [ 2 ] , lf2sym ) ) {
tmp [ 3 ] = arg_0 ( tmp [ 2 ] ) ;
FUNC_EXIT ( ( * ef2 ) ( lf2 ( cons ( make_list_char ( 45 ) , make_list ( tmp [ 3 ] ) ) ) ) ) ;
}
}
}
tmp [ 0 ] = list_head ( atmp000 ) ;
tmp [ 1 ] = list_tail ( atmp000 ) ;
if ( ! term_equal ( ( * ef1 ) ( lf2 ( make_list ( tmp [ 0 ] ) ) ) , ( * ef1 ) ( lf2 ( make_list ( make_char ( 95 ) ) ) ) ) ) {
tmp [ 2 ] = lf_AUX_C_Basics16_1 ( ( * ef1 ) ( lf2 ( make_list ( tmp [ 1 ] ) ) ) ) ;
if ( check_sym ( tmp [ 2 ] , ef2sym ) ) {
tmp [ 3 ] = arg_0 ( tmp [ 2 ] ) ;
if ( check_sym ( tmp [ 3 ] , lf2sym ) ) {
tmp [ 4 ] = arg_0 ( tmp [ 3 ] ) ;
FUNC_EXIT ( ( * ef2 ) ( lf2 ( cons ( make_list ( tmp [ 0 ] ) , make_list ( tmp [ 4 ] ) ) ) ) ) ;
}
}
}
}
}
}
}
}
}
FUNC_EXIT ( make_nf1 ( lf_AUX_C_Basics16_1sym , arg0 ) ) ;
}
}
ATerm lf2 ( ATerm arg0 ) {
CONS_ENTRY ( lf2sym , ATmakeAppl ( lf2sym , arg0 ) ) ;
CONS_EXIT ( make_nf1 ( lf2sym , arg0 ) ) ;
}

