#include  "support.h"
static Symbol lf_AUX_Locate_Constants3_1sym ;
static ATerm lf_AUX_Locate_Constants3_1 ( ATerm arg1 , ATerm arg2 ) ;
static Symbol ef1sym ;
static funcptr ef1 ;
static Symbol ef6sym ;
static funcptr ef6 ;
static Symbol ef3sym ;
static funcptr ef3 ;
static Symbol ef4sym ;
static funcptr ef4 ;
static Symbol ef2sym ;
static funcptr ef2 ;
static Symbol ef5sym ;
static funcptr ef5 ;
static Symbol lf2sym ;
static ATerm lf2 ( ATerm arg1 ) ;
void register_AUX_Locate_Constants3 ( ) {
lf_AUX_Locate_Constants3_1sym = ATmakeSymbol ( "prod(id(\"Locate-Constants\"),w(\"\"),[l(\"locate-constants-in-decllist\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Declaration-list\"),w(\"\"),l(\",\"),w(\"\"),sort(\"CEI-tuple\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"CEDLI-tuple\"),w(\"\"),no-attrs)"
 , 2 , ATtrue ) ;
ATprotectSymbol ( lf_AUX_Locate_Constants3_1sym ) ;
lf2sym = ATmakeSymbol ( "listtype(sort(\"CE-pair\"),ql(\",\"))" , 1 , ATtrue ) ;
ATprotectSymbol ( lf2sym ) ;
register_prod ( ATparse ( "prod(id(\"Locate-Constants\"),w(\"\"),[l(\"locate-constants-in-decllist\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Declaration-list\"),w(\"\"),l(\",\"),w(\"\"),sort(\"CEI-tuple\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"CEDLI-tuple\"),w(\"\"),no-attrs)" ) , lf_AUX_Locate_Constants3_1 , lf_AUX_Locate_Constants3_1sym ) ;
register_prod ( ATparse ( "listtype(sort(\"CE-pair\"),ql(\",\"))" ) , lf2 , lf2sym ) ;
}
void resolve_AUX_Locate_Constants3 ( ) {
ef1 = lookup_func ( ATreadFromString ( "prod(id(\"Pure-C\"),w(\"\"),[sort(\"Declaration\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Declaration-list\"),w(\"\"),no-attrs)" ) ) ;
ef1sym = lookup_sym ( ATreadFromString ( "prod(id(\"Pure-C\"),w(\"\"),[sort(\"Declaration\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Declaration-list\"),w(\"\"),no-attrs)" ) ) ;
ef2 = lookup_func ( ATreadFromString ( "prod(id(\"Locate-Constants\"),w(\"\"),[ql(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"CE-pair\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\",\"),w(\"\"),sort(\"IntCon\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"CEI-tuple\"),w(\"\"),no-attrs)" ) ) ;
ef2sym = lookup_sym ( ATreadFromString ( "prod(id(\"Locate-Constants\"),w(\"\"),[ql(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"CE-pair\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\",\"),w(\"\"),sort(\"IntCon\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"CEI-tuple\"),w(\"\"),no-attrs)" ) ) ;
ef3 = lookup_func ( ATreadFromString ( "prod(id(\"Locate-Constants\"),w(\"\"),[ql(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"CE-pair\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\",\"),w(\"\"),sort(\"Declaration-list\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"IntCon\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"CEDLI-tuple\"),w(\"\"),no-attrs)" ) ) ;
ef3sym = lookup_sym ( ATreadFromString ( "prod(id(\"Locate-Constants\"),w(\"\"),[ql(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"CE-pair\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\",\"),w(\"\"),sort(\"Declaration-list\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"IntCon\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"CEDLI-tuple\"),w(\"\"),no-attrs)" ) ) ;
ef4 = lookup_func ( ATreadFromString ( "prod(id(\"Locate-Constants\"),w(\"\"),[l(\"locate-constants-in-decl\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Declaration\"),w(\"\"),l(\",\"),w(\"\"),sort(\"CEI-tuple\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"CEDI-tuple\"),w(\"\"),no-attrs)" ) ) ;
ef4sym = lookup_sym ( ATreadFromString ( "prod(id(\"Locate-Constants\"),w(\"\"),[l(\"locate-constants-in-decl\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Declaration\"),w(\"\"),l(\",\"),w(\"\"),sort(\"CEI-tuple\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"CEDI-tuple\"),w(\"\"),no-attrs)" ) ) ;
ef5 = lookup_func ( ATreadFromString ( "prod(id(\"Locate-Constants\"),w(\"\"),[ql(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"CE-pair\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\",\"),w(\"\"),sort(\"Declaration\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"IntCon\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"CEDI-tuple\"),w(\"\"),no-attrs)" ) ) ;
ef5sym = lookup_sym ( ATreadFromString ( "prod(id(\"Locate-Constants\"),w(\"\"),[ql(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"CE-pair\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\",\"),w(\"\"),sort(\"Declaration\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"IntCon\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"CEDI-tuple\"),w(\"\"),no-attrs)" ) ) ;
ef6 = lookup_func ( ATreadFromString ( "prod(id(\"Pure-C\"),w(\"\"),[sort(\"Declaration-list\"),w(\"\"),sort(\"Declaration\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Declaration-list\"),w(\"\"),no-attrs)" ) ) ;
ef6sym = lookup_sym ( ATreadFromString ( "prod(id(\"Pure-C\"),w(\"\"),[sort(\"Declaration-list\"),w(\"\"),sort(\"Declaration\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Declaration-list\"),w(\"\"),no-attrs)" ) ) ;
}
void init_AUX_Locate_Constants3 ( ) {
}
ATerm lf_AUX_Locate_Constants3_1 ( ATerm arg0 , ATerm arg1 ) {
{
ATerm tmp [ 10 ] ;
PROF ( prof_lf_AUX_Locate_Constants3_1 ) ;
if ( check_sym ( arg0 , ef1sym ) ) {
{
ATerm atmp00 = arg_0 ( arg0 ) ;
if ( check_sym ( arg1 , ef2sym ) ) {
{
ATerm atmp10 = arg_0 ( arg1 ) ;
if ( check_sym ( atmp10 , lf2sym ) ) {
{
ATerm atmp100 = arg_0 ( atmp10 ) ;
{
ATerm atmp11 = arg_1 ( arg1 ) ;
tmp [ 0 ] = ( * ef4 ) ( atmp00 , ( * ef2 ) ( lf2 ( make_list ( atmp100 ) ) , atmp11 ) ) ;
if ( check_sym ( tmp [ 0 ] , ef5sym ) ) {
tmp [ 1 ] = arg_0 ( tmp [ 0 ] ) ;
tmp [ 2 ] = arg_1 ( tmp [ 0 ] ) ;
tmp [ 3 ] = arg_2 ( tmp [ 0 ] ) ;
if ( check_sym ( tmp [ 1 ] , lf2sym ) ) {
tmp [ 4 ] = arg_0 ( tmp [ 1 ] ) ;
return ( * ef3 ) ( lf2 ( make_list ( tmp [ 4 ] ) ) , ( * ef1 ) ( tmp [ 2 ] ) , tmp [ 3 ] ) ;
}
}
}
}
}
}
}
}
}
if ( check_sym ( arg0 , ef6sym ) ) {
{
ATerm atmp00 = arg_0 ( arg0 ) ;
{
ATerm atmp01 = arg_1 ( arg0 ) ;
if ( check_sym ( arg1 , ef2sym ) ) {
{
ATerm atmp10 = arg_0 ( arg1 ) ;
if ( check_sym ( atmp10 , lf2sym ) ) {
{
ATerm atmp100 = arg_0 ( atmp10 ) ;
{
ATerm atmp11 = arg_1 ( arg1 ) ;
tmp [ 0 ] = lf_AUX_Locate_Constants3_1 ( atmp00 , ( * ef2 ) ( lf2 ( make_list ( atmp100 ) ) , atmp11 ) ) ;
if ( check_sym ( tmp [ 0 ] , ef3sym ) ) {
tmp [ 1 ] = arg_0 ( tmp [ 0 ] ) ;
tmp [ 2 ] = arg_1 ( tmp [ 0 ] ) ;
tmp [ 3 ] = arg_2 ( tmp [ 0 ] ) ;
if ( check_sym ( tmp [ 1 ] , lf2sym ) ) {
tmp [ 4 ] = arg_0 ( tmp [ 1 ] ) ;
tmp [ 5 ] = ( * ef4 ) ( atmp01 , ( * ef2 ) ( lf2 ( make_list ( tmp [ 4 ] ) ) , tmp [ 3 ] ) ) ;
if ( check_sym ( tmp [ 5 ] , ef5sym ) ) {
tmp [ 6 ] = arg_0 ( tmp [ 5 ] ) ;
tmp [ 7 ] = arg_1 ( tmp [ 5 ] ) ;
tmp [ 8 ] = arg_2 ( tmp [ 5 ] ) ;
if ( check_sym ( tmp [ 6 ] , lf2sym ) ) {
tmp [ 9 ] = arg_0 ( tmp [ 6 ] ) ;
return ( * ef3 ) ( lf2 ( make_list ( tmp [ 9 ] ) ) , ( * ef6 ) ( tmp [ 2 ] , tmp [ 7 ] ) , tmp [ 8 ] ) ;
}
}
}
}
}
}
}
}
}
}
}
}
return make_nf2 ( lf_AUX_Locate_Constants3_1sym , arg0 , arg1 ) ;
}
}
ATerm lf2 ( ATerm arg0 ) {
PROF ( prof_lf2 ) ;
return make_nf1 ( lf2sym , arg0 ) ;
}

