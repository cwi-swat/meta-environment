#include  "support.h"
static Symbol lf_AUX_AsFix2C2_1sym ;
static ATerm lf_AUX_AsFix2C2_1 ( ATerm arg1 ) ;
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
static Symbol ef7sym ;
static funcptr ef7 ;
void register_AUX_AsFix2C2 ( ) {
lf_AUX_AsFix2C2_1sym = ATmakeSymbol ( "prod(id(\"AsFix2C\"),w(\"\"),[l(\"asfix2c\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"ATerm\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"CProgram\"),w(\"\"),no-attrs)"
 , 1 , ATtrue ) ;
ATprotectSymbol ( lf_AUX_AsFix2C2_1sym ) ;
register_prod ( ATparse ( "prod(id(\"AsFix2C\"),w(\"\"),[l(\"asfix2c\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"ATerm\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"CProgram\"),w(\"\"),no-attrs)" ) , lf_AUX_AsFix2C2_1 , lf_AUX_AsFix2C2_1sym ) ;
}
void resolve_AUX_AsFix2C2 ( ) {
ef1 = lookup_func ( ATreadFromString ( "prod(id(\"MuASF2C\"),w(\"\"),[l(\"muASF2C-internal\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Module\"),w(\"\"),l(\",\"),w(\"\"),sort(\"NameTable\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"CProgram\"),w(\"\"),no-attrs)" ) ) ;
ef1sym = lookup_sym ( ATreadFromString ( "prod(id(\"MuASF2C\"),w(\"\"),[l(\"muASF2C-internal\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Module\"),w(\"\"),l(\",\"),w(\"\"),sort(\"NameTable\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"CProgram\"),w(\"\"),no-attrs)" ) ) ;
ef2 = lookup_func ( ATreadFromString ( "prod(id(\"AsFix2muASF-C\"),w(\"\"),[l(\"asfix2muasf\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"ATerm\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"MN-struct\"),w(\"\"),no-attrs)" ) ) ;
ef2sym = lookup_sym ( ATreadFromString ( "prod(id(\"AsFix2muASF-C\"),w(\"\"),[l(\"asfix2muasf\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"ATerm\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"MN-struct\"),w(\"\"),no-attrs)" ) ) ;
ef3 = lookup_func ( ATreadFromString ( "prod(id(\"AsFix2muASF-C\"),w(\"\"),[ql(\"(\"),w(\"\"),sort(\"Module\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"NameTable\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"MN-struct\"),w(\"\"),no-attrs)" ) ) ;
ef3sym = lookup_sym ( ATreadFromString ( "prod(id(\"AsFix2muASF-C\"),w(\"\"),[ql(\"(\"),w(\"\"),sort(\"Module\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"NameTable\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"MN-struct\"),w(\"\"),no-attrs)" ) ) ;
ef4 = lookup_func ( ATreadFromString ( "prod(id(\"Make-Assign-Conds-C\"),w(\"\"),[l(\"make-matching-conds\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Module\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Module\"),w(\"\"),no-attrs)" ) ) ;
ef4sym = lookup_sym ( ATreadFromString ( "prod(id(\"Make-Assign-Conds-C\"),w(\"\"),[l(\"make-matching-conds\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Module\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Module\"),w(\"\"),no-attrs)" ) ) ;
ef5 = lookup_func ( ATreadFromString ( "prod(id(\"Make-Left-Linear\"),w(\"\"),[l(\"make-left-linear\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Module\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Module\"),w(\"\"),no-attrs)" ) ) ;
ef5sym = lookup_sym ( ATreadFromString ( "prod(id(\"Make-Left-Linear\"),w(\"\"),[l(\"make-left-linear\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Module\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Module\"),w(\"\"),no-attrs)" ) ) ;
ef6 = lookup_func ( ATreadFromString ( "prod(id(\"Remove-Lists-C\"),w(\"\"),[l(\"remove-list-matching\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Module\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Module\"),w(\"\"),no-attrs)" ) ) ;
ef6sym = lookup_sym ( ATreadFromString ( "prod(id(\"Remove-Lists-C\"),w(\"\"),[l(\"remove-list-matching\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Module\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Module\"),w(\"\"),no-attrs)" ) ) ;
ef7 = lookup_func ( ATreadFromString ( "prod(id(\"Normalize-Conds\"),w(\"\"),[l(\"normalize-conditions\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Module\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Module\"),w(\"\"),no-attrs)" ) ) ;
ef7sym = lookup_sym ( ATreadFromString ( "prod(id(\"Normalize-Conds\"),w(\"\"),[l(\"normalize-conditions\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Module\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Module\"),w(\"\"),no-attrs)" ) ) ;
}
void init_AUX_AsFix2C2 ( ) {
}
ATerm lf_AUX_AsFix2C2_1 ( ATerm arg0 ) {
{
ATerm tmp [ 7 ] ;
PROF ( prof_lf_AUX_AsFix2C2_1 ) ;
tmp [ 0 ] = ( * ef2 ) ( arg0 ) ;
if ( check_sym ( tmp [ 0 ] , ef3sym ) ) {
tmp [ 1 ] = arg_0 ( tmp [ 0 ] ) ;
tmp [ 2 ] = arg_1 ( tmp [ 0 ] ) ;
tmp [ 3 ] = ( * ef4 ) ( tmp [ 1 ] ) ;
tmp [ 4 ] = ( * ef5 ) ( tmp [ 3 ] ) ;
tmp [ 5 ] = ( * ef6 ) ( tmp [ 4 ] ) ;
tmp [ 6 ] = ( * ef7 ) ( tmp [ 5 ] ) ;
return ( * ef1 ) ( tmp [ 6 ] , tmp [ 2 ] ) ;
}
return make_nf1 ( lf_AUX_AsFix2C2_1sym , arg0 ) ;
}
}

