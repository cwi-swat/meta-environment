#include  "asc-support.h"
static Symbol lf_AUX_VarEnv23_2sym ;
static ATerm lf_AUX_VarEnv23_2 ( ATerm arg1 , ATerm arg2 ) ;
static Symbol ef1sym ;
static funcptr ef1 ;
static Symbol ef3sym ;
static funcptr ef3 ;
static Symbol ef5sym ;
static funcptr ef5 ;
static Symbol ef4sym ;
static funcptr ef4 ;
static Symbol lf4sym ;
static ATerm lf4 ( ATerm arg1 ) ;
static Symbol ef2sym ;
static funcptr ef2 ;
static Symbol lf3sym ;
static ATerm lf3 ( ATerm arg1 ) ;
static Symbol lf_AUX_VarEnv23_1sym ;
static ATerm lf_AUX_VarEnv23_1 ( ATerm arg1 ) ;
void register_AUX_VarEnv23 ( ) {
lf_AUX_VarEnv23_2sym = ATmakeSymbol ( "prod(id(\"VarEnv\"),w(\"\"),[l(\"is-memo\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"FunId\"),w(\"\"),l(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"NamePair\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)"
 , 2 , ATtrue ) ;
ATprotectSymbol ( lf_AUX_VarEnv23_2sym ) ;
lf4sym = ATmakeSymbol ( "listtype(sort(\"CHAR\"))" , 1 , ATtrue ) ;
ATprotectSymbol ( lf4sym ) ;
lf3sym = ATmakeSymbol ( "listtype(sort(\"Term\"),ql(\",\"))" , 1 , ATtrue ) ;
ATprotectSymbol ( lf3sym ) ;
lf_AUX_VarEnv23_1sym = ATmakeSymbol ( "listtype(sort(\"NamePair\"),ql(\",\"))" , 1 , ATtrue ) ;
ATprotectSymbol ( lf_AUX_VarEnv23_1sym ) ;
register_prod ( ATparse ( "listtype(sort(\"NamePair\"),ql(\",\"))" ) , lf_AUX_VarEnv23_1 , lf_AUX_VarEnv23_1sym ) ;
register_prod ( ATparse ( "prod(id(\"VarEnv\"),w(\"\"),[l(\"is-memo\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"FunId\"),w(\"\"),l(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"NamePair\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)" ) , lf_AUX_VarEnv23_2 , lf_AUX_VarEnv23_2sym ) ;
register_prod ( ATparse ( "listtype(sort(\"Term\"),ql(\",\"))" ) , lf3 , lf3sym ) ;
register_prod ( ATparse ( "listtype(sort(\"CHAR\"))" ) , lf4 , lf4sym ) ;
}
void resolve_AUX_VarEnv23 ( ) {
ef1 = lookup_func ( ATreadFromString ( "prod(id(\"Booleans\"),w(\"\"),[ql(\"false\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)" ) ) ;
ef1sym = lookup_sym ( ATreadFromString ( "prod(id(\"Booleans\"),w(\"\"),[ql(\"false\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)" ) ) ;
ef2 = lookup_func ( ATreadFromString ( "prod(id(\"VarEnv\"),w(\"\"),[ql(\"(\"),w(\"\"),sort(\"FunId\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"FunId\"),w(\"\"),ql(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"NamePair\"),w(\"\"),no-attrs)" ) ) ;
ef2sym = lookup_sym ( ATreadFromString ( "prod(id(\"VarEnv\"),w(\"\"),[ql(\"(\"),w(\"\"),sort(\"FunId\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"FunId\"),w(\"\"),ql(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"NamePair\"),w(\"\"),no-attrs)" ) ) ;
ef3 = lookup_func ( ATreadFromString ( "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[sort(\"FunId\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Term\"),w(\"\"),no-attrs)" ) ) ;
ef3sym = lookup_sym ( ATreadFromString ( "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[sort(\"FunId\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Term\"),w(\"\"),no-attrs)" ) ) ;
ef4 = lookup_func ( ATreadFromString ( "prod(id(\"caller\"),w(\"\"),[l(\"funid\"),w(\"\"),ql(\"(\"),w(\"\"),iter(sort(\"CHAR\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FunId\"),w(\"\"),no-attrs)" ) ) ;
ef4sym = lookup_sym ( ATreadFromString ( "prod(id(\"caller\"),w(\"\"),[l(\"funid\"),w(\"\"),ql(\"(\"),w(\"\"),iter(sort(\"CHAR\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FunId\"),w(\"\"),no-attrs)" ) ) ;
ef5 = lookup_func ( ATreadFromString ( "prod(id(\"Booleans\"),w(\"\"),[ql(\"true\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)" ) ) ;
ef5sym = lookup_sym ( ATreadFromString ( "prod(id(\"Booleans\"),w(\"\"),[ql(\"true\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)" ) ) ;
}
static ATerm constant0 = NULL ;
static ATerm constant1 = NULL ;
void init_AUX_VarEnv23 ( ) {
ATprotect ( & constant0 ) ;
ATprotect ( & constant1 ) ;
}
ATerm lf_AUX_VarEnv23_2 ( ATerm arg0 , ATerm arg1 ) {
{
ATerm tmp [ 24 ] ;
FUNC_ENTRY ( lf_AUX_VarEnv23_2sym , ATmakeAppl ( lf_AUX_VarEnv23_2sym , arg0 , arg1 ) ) ;
{
ATerm ltmp [ 2 ] ;
lbl_lf_AUX_VarEnv23_2 : ltmp [ 0 ] = arg0 ;
ltmp [ 1 ] = arg1 ;
if ( check_sym ( ltmp [ 1 ] , lf_AUX_VarEnv23_1sym ) ) {
{
ATerm atmp10 = arg_0 ( arg1 ) ;
if ( not_empty_list ( atmp10 ) ) {
tmp [ 0 ] = list_head ( atmp10 ) ;
{
tmp [ 1 ] = list_tail ( atmp10 ) ;
{
if ( check_sym ( tmp [ 0 ] , ef2sym ) ) {
tmp [ 2 ] = arg_0 ( tmp [ 0 ] ) ;
tmp [ 3 ] = arg_1 ( tmp [ 0 ] ) ;
tmp [ 4 ] = arg_2 ( tmp [ 0 ] ) ;
{
if ( check_sym ( tmp [ 4 ] , lf3sym ) ) {
tmp [ 5 ] = arg_0 ( tmp [ 4 ] ) ;
tmp [ 6 ] = tmp [ 5 ] ;
tmp [ 7 ] = tmp [ 5 ] ;
while ( not_empty_list ( tmp [ 5 ] ) ) {
tmp [ 8 ] = list_head ( tmp [ 5 ] ) ;
tmp [ 5 ] = list_tail ( tmp [ 5 ] ) ;
{
if ( check_sym ( tmp [ 8 ] , ef3sym ) ) {
tmp [ 9 ] = arg_0 ( tmp [ 8 ] ) ;
{
if ( check_sym ( tmp [ 9 ] , ef4sym ) ) {
tmp [ 10 ] = arg_0 ( tmp [ 9 ] ) ;
{
if ( check_sym ( tmp [ 10 ] , lf4sym ) ) {
tmp [ 11 ] = arg_0 ( tmp [ 10 ] ) ;
{
if ( not_empty_list ( tmp [ 11 ] ) ) {
tmp [ 12 ] = list_head ( tmp [ 11 ] ) ;
if ( term_equal ( tmp [ 12 ] , make_char ( 109 ) ) ) {
tmp [ 13 ] = list_tail ( tmp [ 11 ] ) ;
{
if ( not_empty_list ( tmp [ 13 ] ) ) {
tmp [ 14 ] = list_head ( tmp [ 13 ] ) ;
if ( term_equal ( tmp [ 14 ] , make_char ( 101 ) ) ) {
tmp [ 15 ] = list_tail ( tmp [ 13 ] ) ;
{
if ( not_empty_list ( tmp [ 15 ] ) ) {
tmp [ 16 ] = list_head ( tmp [ 15 ] ) ;
if ( term_equal ( tmp [ 16 ] , make_char ( 109 ) ) ) {
tmp [ 17 ] = list_tail ( tmp [ 15 ] ) ;
{
if ( is_single_element ( tmp [ 17 ] ) ) {
tmp [ 18 ] = list_head ( tmp [ 17 ] ) ;
if ( term_equal ( tmp [ 18 ] , make_char ( 111 ) ) ) {
if ( check_sym ( ltmp [ 0 ] , ef4sym ) ) {
tmp [ 19 ] = arg_0 ( ltmp [ 0 ] ) ;
if ( check_sym ( tmp [ 19 ] , lf4sym ) ) {
tmp [ 20 ] = arg_0 ( tmp [ 19 ] ) ;
if ( check_sym ( tmp [ 3 ] , ef4sym ) ) {
tmp [ 21 ] = arg_0 ( tmp [ 3 ] ) ;
if ( check_sym ( tmp [ 21 ] , lf4sym ) ) {
tmp [ 22 ] = arg_0 ( tmp [ 21 ] ) ;
if ( not_empty_list ( tmp [ 22 ] ) ) {
if ( term_equal ( list_head ( tmp [ 22 ] ) , make_char ( 95 ) ) ) {
tmp [ 23 ] = list_tail ( tmp [ 22 ] ) ;
if ( term_equal ( ( * ef4 ) ( lf4 ( make_list ( tmp [ 20 ] ) ) ) , ( * ef4 ) ( lf4 ( make_list ( tmp [ 23 ] ) ) ) ) ) {
FUNC_EXIT_CONST ( constant0 , ( * ef5 ) ( ) ) ;
}
}
}
}
}
}
}
if ( term_equal ( ltmp [ 0 ] , tmp [ 3 ] ) ) {
FUNC_EXIT_CONST ( constant0 , ( * ef5 ) ( ) ) ;
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
}
}
}
}
}
}
}
tmp [ 7 ] = list_tail ( tmp [ 7 ] ) ;
tmp [ 5 ] = tmp [ 7 ] ;
}
}
}
}
}
}
}
else {
FUNC_EXIT_CONST ( constant1 , ( * ef1 ) ( ) ) ;
}
}
}
if ( check_sym ( ltmp [ 1 ] , lf_AUX_VarEnv23_1sym ) ) {
{
ATerm atmp10 = arg_0 ( arg1 ) ;
if ( not_empty_list ( atmp10 ) ) {
tmp [ 0 ] = list_head ( atmp10 ) ;
tmp [ 1 ] = list_tail ( atmp10 ) ;
if ( check_sym ( tmp [ 0 ] , ef2sym ) ) {
tmp [ 2 ] = arg_0 ( tmp [ 0 ] ) ;
tmp [ 3 ] = arg_1 ( tmp [ 0 ] ) ;
tmp [ 4 ] = arg_2 ( tmp [ 0 ] ) ;
if ( check_sym ( tmp [ 4 ] , lf3sym ) ) {
tmp [ 5 ] = arg_0 ( tmp [ 4 ] ) ;
arg1 = lf_AUX_VarEnv23_1 ( make_list ( tmp [ 1 ] ) ) ;
goto lbl_lf_AUX_VarEnv23_2 ;
}
}
}
}
}
FUNC_EXIT ( make_nf2 ( lf_AUX_VarEnv23_2sym , ltmp [ 0 ] , ltmp [ 1 ] ) ) ;
}
}
}
ATerm lf_AUX_VarEnv23_1 ( ATerm arg0 ) {
CONS_ENTRY ( lf_AUX_VarEnv23_1sym , ATmakeAppl ( lf_AUX_VarEnv23_1sym , arg0 ) ) ;
CONS_EXIT ( make_nf1 ( lf_AUX_VarEnv23_1sym , arg0 ) ) ;
}
ATerm lf3 ( ATerm arg0 ) {
CONS_ENTRY ( lf3sym , ATmakeAppl ( lf3sym , arg0 ) ) ;
CONS_EXIT ( make_nf1 ( lf3sym , arg0 ) ) ;
}
ATerm lf4 ( ATerm arg0 ) {
CONS_ENTRY ( lf4sym , ATmakeAppl ( lf4sym , arg0 ) ) ;
CONS_EXIT ( make_nf1 ( lf4sym , arg0 ) ) ;
}

