#include  "support.h"
static Symbol lf_AUX_MuASF_Term2C10_4sym ;
static ATerm lf_AUX_MuASF_Term2C10_4 ( ATerm arg1 , ATerm arg2 , ATerm arg3 , ATerm arg4 ) ;
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
static Symbol lf5sym ;
static ATerm lf5 ( ATerm arg1 ) ;
static Symbol ef7sym ;
static funcptr ef7 ;
static Symbol lf_AUX_MuASF_Term2C10_1sym ;
static ATerm lf_AUX_MuASF_Term2C10_1 ( ATerm arg1 ) ;
static Symbol lf_AUX_MuASF_Term2C10_3sym ;
static ATerm lf_AUX_MuASF_Term2C10_3 ( ATerm arg1 ) ;
static Symbol ef1sym ;
static funcptr ef1 ;
static Symbol lf_AUX_MuASF_Term2C10_2sym ;
static ATerm lf_AUX_MuASF_Term2C10_2 ( ATerm arg1 ) ;
void register_AUX_MuASF_Term2C10 ( ) {
lf_AUX_MuASF_Term2C10_4sym = ATmakeSymbol ( "prod(id(\"MuASF-Term2C\"),w(\"\"),[l(\"delay-args\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Int\"),w(\"\"),l(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),l(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Expression\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),l(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"NamePair\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Argument-expression-list\"),w(\"\"),no-attrs)"
 , 4 , ATtrue ) ;
ATprotectSymbol ( lf_AUX_MuASF_Term2C10_4sym ) ;
lf5sym = ATmakeSymbol ( "listtype(sort(\"CHAR\"))" , 1 , ATtrue ) ;
ATprotectSymbol ( lf5sym ) ;
lf_AUX_MuASF_Term2C10_1sym = ATmakeSymbol ( "listtype(sort(\"Term\"),ql(\",\"))" , 1 , ATtrue ) ;
ATprotectSymbol ( lf_AUX_MuASF_Term2C10_1sym ) ;
lf_AUX_MuASF_Term2C10_3sym = ATmakeSymbol ( "listtype(sort(\"NamePair\"),ql(\",\"))" , 1 , ATtrue ) ;
ATprotectSymbol ( lf_AUX_MuASF_Term2C10_3sym ) ;
lf_AUX_MuASF_Term2C10_2sym = ATmakeSymbol ( "listtype(sort(\"Expression\"),ql(\",\"))" , 1 , ATtrue ) ;
ATprotectSymbol ( lf_AUX_MuASF_Term2C10_2sym ) ;
register_prod ( ATparse ( "listtype(sort(\"Term\"),ql(\",\"))" ) , lf_AUX_MuASF_Term2C10_1 , lf_AUX_MuASF_Term2C10_1sym ) ;
register_prod ( ATparse ( "listtype(sort(\"Expression\"),ql(\",\"))" ) , lf_AUX_MuASF_Term2C10_2 , lf_AUX_MuASF_Term2C10_2sym ) ;
register_prod ( ATparse ( "listtype(sort(\"NamePair\"),ql(\",\"))" ) , lf_AUX_MuASF_Term2C10_3 , lf_AUX_MuASF_Term2C10_3sym ) ;
register_prod ( ATparse ( "prod(id(\"MuASF-Term2C\"),w(\"\"),[l(\"delay-args\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Int\"),w(\"\"),l(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),l(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Expression\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),l(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"NamePair\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Argument-expression-list\"),w(\"\"),no-attrs)" ) , lf_AUX_MuASF_Term2C10_4 , lf_AUX_MuASF_Term2C10_4sym ) ;
register_prod ( ATparse ( "listtype(sort(\"CHAR\"))" ) , lf5 , lf5sym ) ;
}
void resolve_AUX_MuASF_Term2C10 ( ) {
ef1 = lookup_func ( ATreadFromString ( "prod(id(\"Pure-C\"),w(\"\"),[iter-sep(l(\"{\"),w(\"\"),sort(\"Expression\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\"))],w(\"\"),l(\"->\"),w(\"\"),sort(\"Argument-expression-list\"),w(\"\"),no-attrs)" ) ) ;
ef1sym = lookup_sym ( ATreadFromString ( "prod(id(\"Pure-C\"),w(\"\"),[iter-sep(l(\"{\"),w(\"\"),sort(\"Expression\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\"))],w(\"\"),l(\"->\"),w(\"\"),sort(\"Argument-expression-list\"),w(\"\"),no-attrs)" ) ) ;
ef2 = lookup_func ( ATreadFromString ( "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[sort(\"Int\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Term\"),w(\"\"),no-attrs)" ) ) ;
ef2sym = lookup_sym ( ATreadFromString ( "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[sort(\"Int\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Term\"),w(\"\"),no-attrs)" ) ) ;
ef3 = lookup_func ( ATreadFromString ( "prod(id(\"MuASF-Term2C\"),w(\"\"),[l(\"delay-term\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Expression\"),w(\"\"),l(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"NamePair\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Expression\"),w(\"\"),no-attrs)" ) ) ;
ef3sym = lookup_sym ( ATreadFromString ( "prod(id(\"MuASF-Term2C\"),w(\"\"),[l(\"delay-term\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Expression\"),w(\"\"),l(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"NamePair\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Expression\"),w(\"\"),no-attrs)" ) ) ;
ef4 = lookup_func ( ATreadFromString ( "prod(id(\"Basic-Integers\"),w(\"\"),[sort(\"Int\"),w(\"\"),ql(\"+\"),w(\"\"),sort(\"Int\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Int\"),w(\"\"),attrs(l(\"{\"),w(\"\"),[l(\"left\")],w(\"\"),l(\"}\")))" ) ) ;
ef4sym = lookup_sym ( ATreadFromString ( "prod(id(\"Basic-Integers\"),w(\"\"),[sort(\"Int\"),w(\"\"),ql(\"+\"),w(\"\"),sort(\"Int\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Int\"),w(\"\"),attrs(l(\"{\"),w(\"\"),[l(\"left\")],w(\"\"),l(\"}\")))" ) ) ;
ef5 = lookup_func ( ATreadFromString ( "prod(id(\"Basic-Integers\"),w(\"\"),[sort(\"IntCon\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Int\"),w(\"\"),no-attrs)" ) ) ;
ef5sym = lookup_sym ( ATreadFromString ( "prod(id(\"Basic-Integers\"),w(\"\"),[sort(\"IntCon\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Int\"),w(\"\"),no-attrs)" ) ) ;
ef6 = lookup_func ( ATreadFromString ( "prod(id(\"IntCon\"),w(\"\"),[sort(\"NatCon\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"IntCon\"),w(\"\"),no-attrs)" ) ) ;
ef6sym = lookup_sym ( ATreadFromString ( "prod(id(\"IntCon\"),w(\"\"),[sort(\"NatCon\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"IntCon\"),w(\"\"),no-attrs)" ) ) ;
ef7 = lookup_func ( ATreadFromString ( "prod(id(\"caller\"),w(\"\"),[l(\"natcon\"),w(\"\"),ql(\"(\"),w(\"\"),iter(sort(\"CHAR\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"NatCon\"),w(\"\"),no-attrs)" ) ) ;
ef7sym = lookup_sym ( ATreadFromString ( "prod(id(\"caller\"),w(\"\"),[l(\"natcon\"),w(\"\"),ql(\"(\"),w(\"\"),iter(sort(\"CHAR\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"NatCon\"),w(\"\"),no-attrs)" ) ) ;
}
static ATerm constant0 = NULL ;
void init_AUX_MuASF_Term2C10 ( ) {
ATprotect ( & constant0 ) ;
}
ATerm lf_AUX_MuASF_Term2C10_4 ( ATerm arg0 , ATerm arg1 , ATerm arg2 , ATerm arg3 ) {
{
ATerm tmp [ 8 ] ;
PROF ( prof_lf_AUX_MuASF_Term2C10_4 ) ;
if ( check_sym ( arg1 , lf_AUX_MuASF_Term2C10_1sym ) ) {
{
ATerm atmp10 = arg_0 ( arg1 ) ;
if ( check_sym ( arg2 , lf_AUX_MuASF_Term2C10_2sym ) ) {
{
ATerm atmp20 = arg_0 ( arg2 ) ;
if ( check_sym ( arg3 , lf_AUX_MuASF_Term2C10_3sym ) ) {
{
ATerm atmp30 = arg_0 ( arg3 ) ;
if ( ! not_empty_list ( atmp10 ) ) {
return ( * ef1 ) ( lf_AUX_MuASF_Term2C10_2 ( make_list ( atmp20 ) ) ) ;
}
}
}
}
}
}
}
if ( check_sym ( arg1 , lf_AUX_MuASF_Term2C10_1sym ) ) {
tmp [ 0 ] = arg_0 ( arg1 ) ;
{
ATerm atmp1010 ;
ATerm atmp100 [ 2 ] ;
atmp100 [ 0 ] = tmp [ 0 ] ;
atmp100 [ 1 ] = tmp [ 0 ] ;
while ( not_empty_list ( tmp [ 0 ] ) ) {
atmp1010 = list_head ( tmp [ 0 ] ) ;
tmp [ 0 ] = list_tail ( tmp [ 0 ] ) ;
if ( check_sym ( arg2 , lf_AUX_MuASF_Term2C10_2sym ) ) {
tmp [ 1 ] = arg_0 ( arg2 ) ;
{
ATerm atmp200 ;
if ( not_empty_list ( tmp [ 1 ] ) ) {
atmp200 = list_head ( tmp [ 1 ] ) ;
tmp [ 1 ] = list_tail ( tmp [ 1 ] ) ;
if ( check_sym ( arg3 , lf_AUX_MuASF_Term2C10_3sym ) ) {
tmp [ 2 ] = arg_0 ( arg3 ) ;
if ( check_sym ( atmp1010 , ef2sym ) ) {
tmp [ 3 ] = arg_0 ( atmp1010 ) ;
if ( term_equal ( arg0 , tmp [ 3 ] ) ) {
tmp [ 4 ] = ( * ef3 ) ( atmp200 , arg3 ) ;
tmp [ 5 ] = lf_AUX_MuASF_Term2C10_4 ( ( * ef4 ) ( ( constant0 ? constant0 : ( constant0 = ( * ef5 ) ( ( * ef6 ) ( ( * ef7 ) ( lf5 ( make_list ( make_char ( 49 ) ) ) ) ) ) ) ) , arg0 ) , lf_AUX_MuASF_Term2C10_1 ( cons ( slice ( atmp100 [ 0 ] , atmp100 [ 1 ] ) , tmp [ 0 ] ) ) , lf_AUX_MuASF_Term2C10_2 ( tmp [ 1 ] ) , arg3 ) ;
if ( check_sym ( tmp [ 5 ] , ef1sym ) ) {
tmp [ 6 ] = arg_0 ( tmp [ 5 ] ) ;
if ( check_sym ( tmp [ 6 ] , lf_AUX_MuASF_Term2C10_2sym ) ) {
tmp [ 7 ] = arg_0 ( tmp [ 6 ] ) ;
return ( * ef1 ) ( lf_AUX_MuASF_Term2C10_2 ( cons ( make_list ( tmp [ 4 ] ) , tmp [ 7 ] ) ) ) ;
}
}
}
}
}
}
}
}
atmp100 [ 1 ] = list_tail ( atmp100 [ 1 ] ) ;
tmp [ 0 ] = atmp100 [ 1 ] ;
}
}
}
if ( check_sym ( arg1 , lf_AUX_MuASF_Term2C10_1sym ) ) {
{
ATerm atmp10 = arg_0 ( arg1 ) ;
if ( check_sym ( arg2 , lf_AUX_MuASF_Term2C10_2sym ) ) {
{
ATerm atmp20 = arg_0 ( arg2 ) ;
if ( check_sym ( arg3 , lf_AUX_MuASF_Term2C10_3sym ) ) {
{
ATerm atmp30 = arg_0 ( arg3 ) ;
if ( not_empty_list ( atmp20 ) ) {
tmp [ 0 ] = list_head ( atmp20 ) ;
tmp [ 1 ] = list_tail ( atmp20 ) ;
tmp [ 2 ] = lf_AUX_MuASF_Term2C10_4 ( ( * ef4 ) ( ( constant0 ? constant0 : ( constant0 = ( * ef5 ) ( ( * ef6 ) ( ( * ef7 ) ( lf5 ( make_list ( make_char ( 49 ) ) ) ) ) ) ) ) , arg0 ) , lf_AUX_MuASF_Term2C10_1 ( make_list ( atmp10 ) ) , lf_AUX_MuASF_Term2C10_2 ( make_list ( tmp [ 1 ] ) ) , lf_AUX_MuASF_Term2C10_3 ( make_list ( atmp30 ) ) ) ;
if ( check_sym ( tmp [ 2 ] , ef1sym ) ) {
tmp [ 3 ] = arg_0 ( tmp [ 2 ] ) ;
if ( check_sym ( tmp [ 3 ] , lf_AUX_MuASF_Term2C10_2sym ) ) {
tmp [ 4 ] = arg_0 ( tmp [ 3 ] ) ;
return ( * ef1 ) ( lf_AUX_MuASF_Term2C10_2 ( cons ( make_list ( tmp [ 0 ] ) , make_list ( tmp [ 4 ] ) ) ) ) ;
}
}
}
}
}
}
}
}
}
return make_nf4 ( lf_AUX_MuASF_Term2C10_4sym , arg0 , arg1 , arg2 , arg3 ) ;
}
}
ATerm lf_AUX_MuASF_Term2C10_2 ( ATerm arg0 ) {
PROF ( prof_lf_AUX_MuASF_Term2C10_2 ) ;
return make_nf1 ( lf_AUX_MuASF_Term2C10_2sym , arg0 ) ;
}
ATerm lf_AUX_MuASF_Term2C10_3 ( ATerm arg0 ) {
PROF ( prof_lf_AUX_MuASF_Term2C10_3 ) ;
return make_nf1 ( lf_AUX_MuASF_Term2C10_3sym , arg0 ) ;
}
ATerm lf_AUX_MuASF_Term2C10_1 ( ATerm arg0 ) {
PROF ( prof_lf_AUX_MuASF_Term2C10_1 ) ;
return make_nf1 ( lf_AUX_MuASF_Term2C10_1sym , arg0 ) ;
}
ATerm lf5 ( ATerm arg0 ) {
PROF ( prof_lf5 ) ;
return make_nf1 ( lf5sym , arg0 ) ;
}

