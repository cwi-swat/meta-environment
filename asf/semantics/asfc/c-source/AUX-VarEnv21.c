#include  "asc-support.h"
static Symbol lf_AUX_VarEnv21_2sym ;
static ATerm lf_AUX_VarEnv21_2 ( ATerm arg1 , ATerm arg2 ) ;
static Symbol ef1sym ;
static funcptr ef1 ;
static Symbol lf3sym ;
static ATerm lf3 ( ATerm arg1 ) ;
static Symbol ef2sym ;
static funcptr ef2 ;
static Symbol lf4sym ;
static ATerm lf4 ( ATerm arg1 ) ;
static Symbol lf_AUX_VarEnv21_1sym ;
static ATerm lf_AUX_VarEnv21_1 ( ATerm arg1 ) ;
void register_AUX_VarEnv21 ( ) {
lf_AUX_VarEnv21_2sym = ATmakeSymbol ( "prod(id(\"VarEnv\"),w(\"\"),[l(\"pn-lookup\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"FunId\"),w(\"\"),l(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"NamePair\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FunId\"),w(\"\"),no-attrs)"
 , 2 , ATtrue ) ;
ATprotectSymbol ( lf_AUX_VarEnv21_2sym ) ;
lf3sym = ATmakeSymbol ( "listtype(sort(\"CHAR\"))" , 1 , ATtrue ) ;
ATprotectSymbol ( lf3sym ) ;
lf4sym = ATmakeSymbol ( "listtype(sort(\"Term\"),ql(\",\"))" , 1 , ATtrue ) ;
ATprotectSymbol ( lf4sym ) ;
lf_AUX_VarEnv21_1sym = ATmakeSymbol ( "listtype(sort(\"NamePair\"),ql(\",\"))" , 1 , ATtrue ) ;
ATprotectSymbol ( lf_AUX_VarEnv21_1sym ) ;
register_prod ( ATparse ( "listtype(sort(\"NamePair\"),ql(\",\"))" ) , lf_AUX_VarEnv21_1 , lf_AUX_VarEnv21_1sym ) ;
register_prod ( ATparse ( "prod(id(\"VarEnv\"),w(\"\"),[l(\"pn-lookup\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"FunId\"),w(\"\"),l(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"NamePair\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FunId\"),w(\"\"),no-attrs)" ) , lf_AUX_VarEnv21_2 , lf_AUX_VarEnv21_2sym ) ;
register_prod ( ATparse ( "listtype(sort(\"CHAR\"))" ) , lf3 , lf3sym ) ;
register_prod ( ATparse ( "listtype(sort(\"Term\"),ql(\",\"))" ) , lf4 , lf4sym ) ;
}
void resolve_AUX_VarEnv21 ( ) {
ef1 = lookup_func ( ATreadFromString ( "prod(id(\"caller\"),w(\"\"),[l(\"funid\"),w(\"\"),ql(\"(\"),w(\"\"),iter(sort(\"CHAR\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FunId\"),w(\"\"),no-attrs)" ) ) ;
ef1sym = lookup_sym ( ATreadFromString ( "prod(id(\"caller\"),w(\"\"),[l(\"funid\"),w(\"\"),ql(\"(\"),w(\"\"),iter(sort(\"CHAR\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FunId\"),w(\"\"),no-attrs)" ) ) ;
ef2 = lookup_func ( ATreadFromString ( "prod(id(\"VarEnv\"),w(\"\"),[ql(\"(\"),w(\"\"),sort(\"FunId\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"FunId\"),w(\"\"),ql(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"NamePair\"),w(\"\"),no-attrs)" ) ) ;
ef2sym = lookup_sym ( ATreadFromString ( "prod(id(\"VarEnv\"),w(\"\"),[ql(\"(\"),w(\"\"),sort(\"FunId\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"FunId\"),w(\"\"),ql(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"NamePair\"),w(\"\"),no-attrs)" ) ) ;
}
void init_AUX_VarEnv21 ( ) {
}
ATerm lf_AUX_VarEnv21_2 ( ATerm arg0 , ATerm arg1 ) {
{
ATerm tmp [ 6 ] ;
FUNC_ENTRY ( lf_AUX_VarEnv21_2sym , ATmakeAppl ( lf_AUX_VarEnv21_2sym , arg0 , arg1 ) ) ;
{
ATerm ltmp [ 2 ] ;
lbl_lf_AUX_VarEnv21_2 : ltmp [ 0 ] = arg0 ;
ltmp [ 1 ] = arg1 ;
if ( check_sym ( ltmp [ 0 ] , ef1sym ) ) {
{
ATerm atmp00 = arg_0 ( arg0 ) ;
if ( check_sym ( atmp00 , lf3sym ) ) {
{
ATerm atmp000 = arg_0 ( atmp00 ) ;
if ( check_sym ( ltmp [ 1 ] , lf_AUX_VarEnv21_1sym ) ) {
{
ATerm atmp10 = arg_0 ( arg1 ) ;
if ( ! not_empty_list ( atmp10 ) ) {
FUNC_EXIT ( ( * ef1 ) ( lf3 ( cons ( make_list_char ( 34 ) , cons ( make_list ( atmp000 ) , make_list ( make_char ( 34 ) ) ) ) ) ) ) ;
}
}
}
}
}
}
}
if ( check_sym ( ltmp [ 1 ] , lf_AUX_VarEnv21_1sym ) ) {
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
if ( check_sym ( tmp [ 4 ] , lf4sym ) ) {
tmp [ 5 ] = arg_0 ( tmp [ 4 ] ) ;
if ( ! term_equal ( ltmp [ 0 ] , tmp [ 2 ] ) ) {
arg1 = lf_AUX_VarEnv21_1 ( make_list ( tmp [ 1 ] ) ) ;
goto lbl_lf_AUX_VarEnv21_2 ;
}
else {
FUNC_EXIT ( tmp [ 3 ] ) ;
}
}
}
}
}
}
}
}
}
FUNC_EXIT ( make_nf2 ( lf_AUX_VarEnv21_2sym , ltmp [ 0 ] , ltmp [ 1 ] ) ) ;
}
}
}
ATerm lf_AUX_VarEnv21_1 ( ATerm arg0 ) {
CONS_ENTRY ( lf_AUX_VarEnv21_1sym , ATmakeAppl ( lf_AUX_VarEnv21_1sym , arg0 ) ) ;
CONS_EXIT ( make_nf1 ( lf_AUX_VarEnv21_1sym , arg0 ) ) ;
}
ATerm lf4 ( ATerm arg0 ) {
CONS_ENTRY ( lf4sym , ATmakeAppl ( lf4sym , arg0 ) ) ;
CONS_EXIT ( make_nf1 ( lf4sym , arg0 ) ) ;
}
ATerm lf3 ( ATerm arg0 ) {
CONS_ENTRY ( lf3sym , ATmakeAppl ( lf3sym , arg0 ) ) ;
CONS_EXIT ( make_nf1 ( lf3sym , arg0 ) ) ;
}

