#include  "asc-support.h"
static Symbol lf_AUX_VarEnv11_1sym ;
static ATerm lf_AUX_VarEnv11_1 ( ATerm arg1 ) ;
static Symbol ef2sym ;
static funcptr ef2 ;
static Symbol ef1sym ;
static funcptr ef1 ;
static Symbol ef4sym ;
static funcptr ef4 ;
static Symbol ef3sym ;
static funcptr ef3 ;
static Symbol lf2sym ;
static ATerm lf2 ( ATerm arg1 ) ;
void register_AUX_VarEnv11 ( ) {
lf_AUX_VarEnv11_1sym = ATmakeSymbol ( "prod(id(\"VarEnv\"),w(\"\"),[l(\"newlistvar\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Term\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"VarId\"),w(\"\"),no-attrs)"
 , 1 , ATtrue ) ;
ATprotectSymbol ( lf_AUX_VarEnv11_1sym ) ;
lf2sym = ATmakeSymbol ( "listtype(sort(\"CHAR\"))" , 1 , ATtrue ) ;
ATprotectSymbol ( lf2sym ) ;
register_prod ( ATparse ( "prod(id(\"VarEnv\"),w(\"\"),[l(\"newlistvar\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Term\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"VarId\"),w(\"\"),no-attrs)" ) , lf_AUX_VarEnv11_1 , lf_AUX_VarEnv11_1sym ) ;
register_prod ( ATparse ( "listtype(sort(\"CHAR\"))" ) , lf2 , lf2sym ) ;
}
void resolve_AUX_VarEnv11 ( ) {
ef1 = lookup_func ( ATreadFromString ( "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[sort(\"Var\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Term\"),w(\"\"),no-attrs)" ) ) ;
ef1sym = lookup_sym ( ATreadFromString ( "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[sort(\"Var\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Term\"),w(\"\"),no-attrs)" ) ) ;
ef2 = lookup_func ( ATreadFromString ( "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[ql(\"*\"),w(\"\"),sort(\"VarId\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Var\"),w(\"\"),no-attrs)" ) ) ;
ef2sym = lookup_sym ( ATreadFromString ( "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[ql(\"*\"),w(\"\"),sort(\"VarId\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Var\"),w(\"\"),no-attrs)" ) ) ;
ef3 = lookup_func ( ATreadFromString ( "prod(id(\"caller\"),w(\"\"),[l(\"varid\"),w(\"\"),ql(\"(\"),w(\"\"),iter(sort(\"CHAR\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"VarId\"),w(\"\"),no-attrs)" ) ) ;
ef3sym = lookup_sym ( ATreadFromString ( "prod(id(\"caller\"),w(\"\"),[l(\"varid\"),w(\"\"),ql(\"(\"),w(\"\"),iter(sort(\"CHAR\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"VarId\"),w(\"\"),no-attrs)" ) ) ;
ef4 = lookup_func ( ATreadFromString ( "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[ql(\"+\"),w(\"\"),sort(\"VarId\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Var\"),w(\"\"),no-attrs)" ) ) ;
ef4sym = lookup_sym ( ATreadFromString ( "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[ql(\"+\"),w(\"\"),sort(\"VarId\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Var\"),w(\"\"),no-attrs)" ) ) ;
}
void init_AUX_VarEnv11 ( ) {
}
ATerm lf_AUX_VarEnv11_1 ( ATerm arg0 ) {
FUNC_ENTRY ( lf_AUX_VarEnv11_1sym , ATmakeAppl ( lf_AUX_VarEnv11_1sym , arg0 ) ) ;
if ( check_sym ( arg0 , ef1sym ) ) {
{
ATerm atmp00 = arg_0 ( arg0 ) ;
if ( check_sym ( atmp00 , ef2sym ) ) {
{
ATerm atmp000 = arg_0 ( atmp00 ) ;
if ( check_sym ( atmp000 , ef3sym ) ) {
{
ATerm atmp0000 = arg_0 ( atmp000 ) ;
if ( check_sym ( atmp0000 , lf2sym ) ) {
{
ATerm atmp00000 = arg_0 ( atmp0000 ) ;
if ( not_empty_list ( atmp00000 ) ) {
FUNC_EXIT ( ( * ef3 ) ( lf2 ( cons ( make_list ( atmp00000 ) , ( ATerm ) ATmakeList ( 4 , char_table [ 108 ] , char_table [ 105 ] , char_table [ 115 ] , char_table [ 116 ] ) ) ) ) ) ;
}
}
}
}
}
}
}
{
ATerm atmp00 = arg_0 ( arg0 ) ;
if ( check_sym ( atmp00 , ef4sym ) ) {
{
ATerm atmp000 = arg_0 ( atmp00 ) ;
if ( check_sym ( atmp000 , ef3sym ) ) {
{
ATerm atmp0000 = arg_0 ( atmp000 ) ;
if ( check_sym ( atmp0000 , lf2sym ) ) {
{
ATerm atmp00000 = arg_0 ( atmp0000 ) ;
if ( not_empty_list ( atmp00000 ) ) {
FUNC_EXIT ( ( * ef3 ) ( lf2 ( cons ( make_list ( atmp00000 ) , ( ATerm ) ATmakeList ( 4 , char_table [ 108 ] , char_table [ 105 ] , char_table [ 115 ] , char_table [ 116 ] ) ) ) ) ) ;
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
FUNC_EXIT ( make_nf1 ( lf_AUX_VarEnv11_1sym , arg0 ) ) ;
}
ATerm lf2 ( ATerm arg0 ) {
CONS_ENTRY ( lf2sym , ATmakeAppl ( lf2sym , arg0 ) ) ;
CONS_EXIT ( make_nf1 ( lf2sym , arg0 ) ) ;
}

