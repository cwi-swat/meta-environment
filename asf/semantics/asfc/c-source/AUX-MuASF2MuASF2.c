#include  "asc-support.h"
static Symbol lf_AUX_MuASF2MuASF2_1sym ;
static ATerm lf_AUX_MuASF2MuASF2_1 ( ATerm arg1 ) ;
static Symbol ef1sym ;
static funcptr ef1 ;
static Symbol ef2sym ;
static funcptr ef2 ;
static Symbol ef3sym ;
static funcptr ef3 ;
static Symbol ef4sym ;
static funcptr ef4 ;
void register_AUX_MuASF2MuASF2 ( ) {
lf_AUX_MuASF2MuASF2_1sym = ATmakeSymbol ( "prod(id(\"MuASF2MuASF\"),w(\"\"),[l(\"muasf2muasf\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Module\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Module\"),w(\"\"),no-attrs)"
 , 1 , ATtrue ) ;
ATprotectSymbol ( lf_AUX_MuASF2MuASF2_1sym ) ;
register_prod ( ATparse ( "prod(id(\"MuASF2MuASF\"),w(\"\"),[l(\"muasf2muasf\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Module\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Module\"),w(\"\"),no-attrs)" ) , lf_AUX_MuASF2MuASF2_1 , lf_AUX_MuASF2MuASF2_1sym ) ;
}
void resolve_AUX_MuASF2MuASF2 ( ) {
ef1 = lookup_func ( ATreadFromString ( "prod(id(\"Make-Assign-Conds\"),w(\"\"),[l(\"make-matching-conds\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Module\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Module\"),w(\"\"),no-attrs)" ) ) ;
ef1sym = lookup_sym ( ATreadFromString ( "prod(id(\"Make-Assign-Conds\"),w(\"\"),[l(\"make-matching-conds\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Module\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Module\"),w(\"\"),no-attrs)" ) ) ;
ef2 = lookup_func ( ATreadFromString ( "prod(id(\"Make-Left-Linear\"),w(\"\"),[l(\"make-left-linear\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Module\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Module\"),w(\"\"),no-attrs)" ) ) ;
ef2sym = lookup_sym ( ATreadFromString ( "prod(id(\"Make-Left-Linear\"),w(\"\"),[l(\"make-left-linear\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Module\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Module\"),w(\"\"),no-attrs)" ) ) ;
ef3 = lookup_func ( ATreadFromString ( "prod(id(\"Remove-Lists\"),w(\"\"),[l(\"remove-list-matching\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Module\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Module\"),w(\"\"),no-attrs)" ) ) ;
ef3sym = lookup_sym ( ATreadFromString ( "prod(id(\"Remove-Lists\"),w(\"\"),[l(\"remove-list-matching\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Module\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Module\"),w(\"\"),no-attrs)" ) ) ;
ef4 = lookup_func ( ATreadFromString ( "prod(id(\"Normalize-Conds\"),w(\"\"),[l(\"normalize-conditions\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Module\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Module\"),w(\"\"),no-attrs)" ) ) ;
ef4sym = lookup_sym ( ATreadFromString ( "prod(id(\"Normalize-Conds\"),w(\"\"),[l(\"normalize-conditions\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Module\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Module\"),w(\"\"),no-attrs)" ) ) ;
}
void init_AUX_MuASF2MuASF2 ( ) {
}
ATerm lf_AUX_MuASF2MuASF2_1 ( ATerm arg0 ) {
{
ATerm tmp [ 4 ] ;
FUNC_ENTRY ( lf_AUX_MuASF2MuASF2_1sym , ATmakeAppl ( lf_AUX_MuASF2MuASF2_1sym , arg0 ) ) ;
( tmp [ 0 ] = ( * ef1 ) ( arg0 ) ) ;
( tmp [ 1 ] = ( * ef2 ) ( tmp [ 0 ] ) ) ;
( tmp [ 2 ] = ( * ef3 ) ( tmp [ 1 ] ) ) ;
( tmp [ 3 ] = ( * ef4 ) ( tmp [ 2 ] ) ) ;
FUNC_EXIT ( tmp [ 3 ] ) ;
FUNC_EXIT ( make_nf1 ( lf_AUX_MuASF2MuASF2_1sym , arg0 ) ) ;
}
}

