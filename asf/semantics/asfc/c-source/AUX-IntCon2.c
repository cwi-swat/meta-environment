#include  "support.h"
static Symbol lf_AUX_IntCon2_2sym ;
static ATerm lf_AUX_IntCon2_2 ( ATerm arg1 ) ;
static Symbol lf_AUX_IntCon2_1sym ;
static ATerm lf_AUX_IntCon2_1 ( ATerm arg1 ) ;
void register_AUX_IntCon2 ( ) {
lf_AUX_IntCon2_2sym = ATmakeSymbol ( "prod(id(\"caller\"),w(\"\"),[l(\"natcon\"),w(\"\"),ql(\"(\"),w(\"\"),iter(sort(\"CHAR\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"NatCon\"),w(\"\"),no-attrs)"
 , 1 , ATtrue ) ;
ATprotectSymbol ( lf_AUX_IntCon2_2sym ) ;
lf_AUX_IntCon2_1sym = ATmakeSymbol ( "listtype(sort(\"CHAR\"))" , 1 , ATtrue ) ;
ATprotectSymbol ( lf_AUX_IntCon2_1sym ) ;
register_prod ( ATparse ( "listtype(sort(\"CHAR\"))" ) , lf_AUX_IntCon2_1 , lf_AUX_IntCon2_1sym ) ;
register_prod ( ATparse ( "prod(id(\"caller\"),w(\"\"),[l(\"natcon\"),w(\"\"),ql(\"(\"),w(\"\"),iter(sort(\"CHAR\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"NatCon\"),w(\"\"),no-attrs)" ) , lf_AUX_IntCon2_2 , lf_AUX_IntCon2_2sym ) ;
}
void resolve_AUX_IntCon2 ( ) {
}
void init_AUX_IntCon2 ( ) {
}
ATerm lf_AUX_IntCon2_2 ( ATerm arg0 ) {
{
ATerm tmp [ 1 ] ;
PROF ( prof_lf_AUX_IntCon2_2 ) ;
if ( check_sym ( arg0 , lf_AUX_IntCon2_1sym ) ) {
{
ATerm atmp00 = arg_0 ( arg0 ) ;
if ( not_empty_list ( atmp00 ) ) {
if ( term_equal ( list_head ( atmp00 ) , make_char ( 48 ) ) ) {
tmp [ 0 ] = list_tail ( atmp00 ) ;
if ( not_empty_list ( tmp [ 0 ] ) ) {
return lf_AUX_IntCon2_2 ( lf_AUX_IntCon2_1 ( make_list ( tmp [ 0 ] ) ) ) ;
}
}
}
}
}
return make_nf1 ( lf_AUX_IntCon2_2sym , arg0 ) ;
}
}
ATerm lf_AUX_IntCon2_1 ( ATerm arg0 ) {
PROF ( prof_lf_AUX_IntCon2_1 ) ;
return make_nf1 ( lf_AUX_IntCon2_1sym , arg0 ) ;
}

