#include  "asc-support.h"
static Symbol lf_AUX_Substitution2_1sym ;
static ATerm lf_AUX_Substitution2_1 ( ATerm arg1 , ATerm arg2 ) ;
static Symbol ef1sym ;
static funcptr ef1 ;
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
static Symbol ef10sym ;
static funcptr ef10 ;
static Symbol ef11sym ;
static funcptr ef11 ;
static Symbol ef12sym ;
static funcptr ef12 ;
static Symbol ef13sym ;
static funcptr ef13 ;
static Symbol ef14sym ;
static funcptr ef14 ;
static Symbol ef8sym ;
static funcptr ef8 ;
static Symbol ef2sym ;
static funcptr ef2 ;
static Symbol ef9sym ;
static funcptr ef9 ;
void register_AUX_Substitution2 ( ) {
lf_AUX_Substitution2_1sym = ATmakeSymbol ( "prod(id(\"Substitution\"),w(\"\"),[l(\"value\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"AVar\"),w(\"\"),l(\",\"),w(\"\"),sort(\"ATermList\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerm\"),w(\"\"),no-attrs)"
 , 2 , ATtrue ) ;
ATprotectSymbol ( lf_AUX_Substitution2_1sym ) ;
register_prod ( ATparse ( "prod(id(\"Substitution\"),w(\"\"),[l(\"value\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"AVar\"),w(\"\"),l(\",\"),w(\"\"),sort(\"ATermList\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerm\"),w(\"\"),no-attrs)" ) , lf_AUX_Substitution2_1 , lf_AUX_Substitution2_1sym ) ;
}
void resolve_AUX_Substitution2 ( ) {
ef1 = lookup_func ( ATreadFromString ( "prod(id(\"ATerms\"),w(\"\"),[ql(\"[\"),w(\"\"),ql(\"]\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATermList\"),w(\"\"),no-attrs)" ) ) ;
ef1sym = lookup_sym ( ATreadFromString ( "prod(id(\"ATerms\"),w(\"\"),[ql(\"[\"),w(\"\"),ql(\"]\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATermList\"),w(\"\"),no-attrs)" ) ) ;
ef2 = lookup_func ( ATreadFromString ( "prod(id(\"AVars\"),w(\"\"),[sort(\"AVar\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerm\"),w(\"\"),no-attrs)" ) ) ;
ef2sym = lookup_sym ( ATreadFromString ( "prod(id(\"AVars\"),w(\"\"),[sort(\"AVar\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerm\"),w(\"\"),no-attrs)" ) ) ;
ef3 = lookup_func ( ATreadFromString ( "prod(id(\"ATerm-Operations\"),w(\"\"),[l(\"if\"),w(\"\"),sort(\"Bool\"),w(\"\"),l(\"then\"),w(\"\"),sort(\"ATerm\"),w(\"\"),l(\"else\"),w(\"\"),sort(\"ATerm\"),w(\"\"),l(\"fi\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerm\"),w(\"\"),no-attrs)" ) ) ;
ef3sym = lookup_sym ( ATreadFromString ( "prod(id(\"ATerm-Operations\"),w(\"\"),[l(\"if\"),w(\"\"),sort(\"Bool\"),w(\"\"),l(\"then\"),w(\"\"),sort(\"ATerm\"),w(\"\"),l(\"else\"),w(\"\"),sort(\"ATerm\"),w(\"\"),l(\"fi\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerm\"),w(\"\"),no-attrs)" ) ) ;
ef4 = lookup_func ( ATreadFromString ( "prod(id(\"ATerm-Booleans\"),w(\"\"),[sort(\"Bool\"),w(\"\"),ql(\"\\\\\\\\/\"),w(\"\"),sort(\"Bool\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),attrs(l(\"{\"),w(\"\"),[l(\"assoc\")],w(\"\"),l(\"}\")))" ) ) ;
ef4sym = lookup_sym ( ATreadFromString ( "prod(id(\"ATerm-Booleans\"),w(\"\"),[sort(\"Bool\"),w(\"\"),ql(\"\\\\\\\\/\"),w(\"\"),sort(\"Bool\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),attrs(l(\"{\"),w(\"\"),[l(\"assoc\")],w(\"\"),l(\"}\")))" ) ) ;
ef5 = lookup_func ( ATreadFromString ( "prod(id(\"AVars\"),w(\"\"),[l(\"is-avar\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"ATerm\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)" ) ) ;
ef5sym = lookup_sym ( ATreadFromString ( "prod(id(\"AVars\"),w(\"\"),[l(\"is-avar\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"ATerm\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)" ) ) ;
ef6 = lookup_func ( ATreadFromString ( "prod(id(\"AVars\"),w(\"\"),[l(\"is-result-avar\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"ATerm\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)" ) ) ;
ef6sym = lookup_sym ( ATreadFromString ( "prod(id(\"AVars\"),w(\"\"),[l(\"is-result-avar\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"ATerm\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)" ) ) ;
ef7 = lookup_func ( ATreadFromString ( "prod(id(\"AVars\"),w(\"\"),[sort(\"AName\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AVar\"),w(\"\"),no-attrs)" ) ) ;
ef7sym = lookup_sym ( ATreadFromString ( "prod(id(\"AVars\"),w(\"\"),[sort(\"AName\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AVar\"),w(\"\"),no-attrs)" ) ) ;
ef8 = lookup_func ( ATreadFromString ( "prod(id(\"AVars\"),w(\"\"),[l(\"avar-name\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"ATerm\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AName\"),w(\"\"),no-attrs)" ) ) ;
ef8sym = lookup_sym ( ATreadFromString ( "prod(id(\"AVars\"),w(\"\"),[l(\"avar-name\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"ATerm\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AName\"),w(\"\"),no-attrs)" ) ) ;
ef9 = lookup_func ( ATreadFromString ( "prod(id(\"ATerm-Lists\"),w(\"\"),[l(\"rest\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"ATermList\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATermList\"),w(\"\"),no-attrs)" ) ) ;
ef9sym = lookup_sym ( ATreadFromString ( "prod(id(\"ATerm-Lists\"),w(\"\"),[l(\"rest\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"ATermList\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATermList\"),w(\"\"),no-attrs)" ) ) ;
ef10 = lookup_func ( ATreadFromString ( "prod(id(\"ATerm-Lists\"),w(\"\"),[l(\"first\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"ATermList\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerm\"),w(\"\"),no-attrs)" ) ) ;
ef10sym = lookup_sym ( ATreadFromString ( "prod(id(\"ATerm-Lists\"),w(\"\"),[l(\"first\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"ATermList\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerm\"),w(\"\"),no-attrs)" ) ) ;
ef11 = lookup_func ( ATreadFromString ( "prod(id(\"ATerms\"),w(\"\"),[sort(\"ATermList\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerm\"),w(\"\"),no-attrs)" ) ) ;
ef11sym = lookup_sym ( ATreadFromString ( "prod(id(\"ATerms\"),w(\"\"),[sort(\"ATermList\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerm\"),w(\"\"),no-attrs)" ) ) ;
ef12 = lookup_func ( ATreadFromString ( "prod(id(\"ATerms\"),w(\"\"),[ql(\"[\"),w(\"\"),sort(\"ATerms\"),w(\"\"),ql(\"]\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATermList\"),w(\"\"),no-attrs)" ) ) ;
ef12sym = lookup_sym ( ATreadFromString ( "prod(id(\"ATerms\"),w(\"\"),[ql(\"[\"),w(\"\"),sort(\"ATerms\"),w(\"\"),ql(\"]\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATermList\"),w(\"\"),no-attrs)" ) ) ;
ef13 = lookup_func ( ATreadFromString ( "prod(id(\"ATerms\"),w(\"\"),[sort(\"ATerm\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"ATerms\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerms\"),w(\"\"),no-attrs)" ) ) ;
ef13sym = lookup_sym ( ATreadFromString ( "prod(id(\"ATerms\"),w(\"\"),[sort(\"ATerm\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"ATerms\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerms\"),w(\"\"),no-attrs)" ) ) ;
ef14 = lookup_func ( ATreadFromString ( "prod(id(\"ATerms\"),w(\"\"),[sort(\"ATerm\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerms\"),w(\"\"),no-attrs)" ) ) ;
ef14sym = lookup_sym ( ATreadFromString ( "prod(id(\"ATerms\"),w(\"\"),[sort(\"ATerm\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerms\"),w(\"\"),no-attrs)" ) ) ;
}
void init_AUX_Substitution2 ( ) {
}
ATerm lf_AUX_Substitution2_1 ( ATerm arg0 , ATerm arg1 ) {
{
ATerm tmp [ 7 ] ;
FUNC_ENTRY ( lf_AUX_Substitution2_1sym , ATmakeAppl ( lf_AUX_Substitution2_1sym , arg0 , arg1 ) ) ;
{
ATerm ltmp [ 2 ] ;
lbl_lf_AUX_Substitution2_1 : ltmp [ 0 ] = arg0 ;
( ltmp [ 1 ] = arg1 ) ;
if ( check_sym ( ltmp [ 1 ] , ef1sym ) ) {
FUNC_EXIT ( ( * ef2 ) ( ltmp [ 0 ] ) ) ;
}
( tmp [ 0 ] = ( * ef10 ) ( ltmp [ 1 ] ) ) ;
if ( check_sym ( tmp [ 0 ] , ef11sym ) ) {
( tmp [ 1 ] = arg_0 ( tmp [ 0 ] ) ) ;
if ( check_sym ( tmp [ 1 ] , ef12sym ) ) {
( tmp [ 2 ] = arg_0 ( tmp [ 1 ] ) ) ;
if ( check_sym ( tmp [ 2 ] , ef13sym ) ) {
( tmp [ 3 ] = arg_0 ( tmp [ 2 ] ) ) ;
( tmp [ 4 ] = arg_1 ( tmp [ 2 ] ) ) ;
if ( check_sym ( tmp [ 3 ] , ef2sym ) ) {
( tmp [ 5 ] = arg_0 ( tmp [ 3 ] ) ) ;
if ( check_sym ( tmp [ 4 ] , ef14sym ) ) {
( tmp [ 6 ] = arg_0 ( tmp [ 4 ] ) ) ;
if ( term_equal ( ( * ef8 ) ( ( * ef2 ) ( tmp [ 5 ] ) ) , ( * ef8 ) ( ( * ef2 ) ( ltmp [ 0 ] ) ) ) ) {
FUNC_EXIT ( ( * ef3 ) ( ( * ef4 ) ( ( * ef5 ) ( tmp [ 6 ] ) , ( * ef6 ) ( tmp [ 6 ] ) ) , lf_AUX_Substitution2_1 ( ( * ef7 ) ( ( * ef8 ) ( tmp [ 6 ] ) ) , ( * ef9 ) ( ltmp [ 1 ] ) ) , tmp [ 6 ] ) ) ;
}
}
}
}
}
}
( arg1 = ( * ef9 ) ( ltmp [ 1 ] ) ) ;
goto lbl_lf_AUX_Substitution2_1 ;
FUNC_EXIT ( make_nf2 ( lf_AUX_Substitution2_1sym , ltmp [ 0 ] , ltmp [ 1 ] ) ) ;
}
}
}

