#include  "support.h"
static Symbol lf_AUX_Make_Assign_Conds_C9_1sym ;
static ATerm lf_AUX_Make_Assign_Conds_C9_1 ( ATerm arg1 , ATerm arg2 ) ;
static Symbol ef1sym ;
static funcptr ef1 ;
static Symbol ef8sym ;
static funcptr ef8 ;
static Symbol ef5sym ;
static funcptr ef5 ;
static Symbol lf4sym ;
static ATerm lf4 ( ATerm arg1 ) ;
static Symbol ef7sym ;
static funcptr ef7 ;
static Symbol lf3sym ;
static ATerm lf3 ( ATerm arg1 ) ;
static Symbol ef6sym ;
static funcptr ef6 ;
static Symbol ef2sym ;
static funcptr ef2 ;
static Symbol lf2sym ;
static ATerm lf2 ( ATerm arg1 ) ;
static Symbol ef3sym ;
static funcptr ef3 ;
static Symbol ef4sym ;
static funcptr ef4 ;
void register_AUX_Make_Assign_Conds_C9 ( ) {
lf_AUX_Make_Assign_Conds_C9_1sym = ATmakeSymbol ( "prod(id(\"Make-Assign-Conds-C\"),w(\"\"),[l(\"make-mc-cond\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Cond\"),w(\"\"),l(\",\"),w(\"\"),sort(\"IntVarEnv\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"CList-VarEnv\"),w(\"\"),no-attrs)"
 , 2 , ATtrue ) ;
ATprotectSymbol ( lf_AUX_Make_Assign_Conds_C9_1sym ) ;
lf4sym = ATmakeSymbol ( "listtype(sort(\"Term\"),ql(\",\"))" , 1 , ATtrue ) ;
ATprotectSymbol ( lf4sym ) ;
lf3sym = ATmakeSymbol ( "listtype(sort(\"CHAR\"))" , 1 , ATtrue ) ;
ATprotectSymbol ( lf3sym ) ;
lf2sym = ATmakeSymbol ( "listtype(sort(\"Cond\"),ql(\"&\"))" , 1 , ATtrue ) ;
ATprotectSymbol ( lf2sym ) ;
register_prod ( ATparse ( "prod(id(\"Make-Assign-Conds-C\"),w(\"\"),[l(\"make-mc-cond\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Cond\"),w(\"\"),l(\",\"),w(\"\"),sort(\"IntVarEnv\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"CList-VarEnv\"),w(\"\"),no-attrs)" ) , lf_AUX_Make_Assign_Conds_C9_1 , lf_AUX_Make_Assign_Conds_C9_1sym ) ;
register_prod ( ATparse ( "listtype(sort(\"Cond\"),ql(\"&\"))" ) , lf2 , lf2sym ) ;
register_prod ( ATparse ( "listtype(sort(\"CHAR\"))" ) , lf3 , lf3sym ) ;
register_prod ( ATparse ( "listtype(sort(\"Term\"),ql(\",\"))" ) , lf4 , lf4sym ) ;
}
void resolve_AUX_Make_Assign_Conds_C9 ( ) {
ef1 = lookup_func ( ATreadFromString ( "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[sort(\"Term\"),w(\"\"),ql(\"==\"),w(\"\"),sort(\"Term\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Cond\"),w(\"\"),no-attrs)" ) ) ;
ef1sym = lookup_sym ( ATreadFromString ( "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[sort(\"Term\"),w(\"\"),ql(\"==\"),w(\"\"),sort(\"Term\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Cond\"),w(\"\"),no-attrs)" ) ) ;
ef2 = lookup_func ( ATreadFromString ( "prod(id(\"VarEnv\"),w(\"\"),[ql(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Cond\"),w(\"\"),ql(\"&\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\",\"),w(\"\"),sort(\"IntVarEnv\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"CList-VarEnv\"),w(\"\"),no-attrs)" ) ) ;
ef2sym = lookup_sym ( ATreadFromString ( "prod(id(\"VarEnv\"),w(\"\"),[ql(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Cond\"),w(\"\"),ql(\"&\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\",\"),w(\"\"),sort(\"IntVarEnv\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"CList-VarEnv\"),w(\"\"),no-attrs)" ) ) ;
ef3 = lookup_func ( ATreadFromString ( "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[sort(\"Term\"),w(\"\"),ql(\"=:\"),w(\"\"),sort(\"Term\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Cond\"),w(\"\"),no-attrs)" ) ) ;
ef3sym = lookup_sym ( ATreadFromString ( "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[sort(\"Term\"),w(\"\"),ql(\"=:\"),w(\"\"),sort(\"Term\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Cond\"),w(\"\"),no-attrs)" ) ) ;
ef4 = lookup_func ( ATreadFromString ( "prod(id(\"Make-Assign-Conds-C\"),w(\"\"),[l(\"inspect-term\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Term\"),w(\"\"),l(\",\"),w(\"\"),sort(\"IntVarEnv\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"IntVarEnv\"),w(\"\"),no-attrs)" ) ) ;
ef4sym = lookup_sym ( ATreadFromString ( "prod(id(\"Make-Assign-Conds-C\"),w(\"\"),[l(\"inspect-term\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Term\"),w(\"\"),l(\",\"),w(\"\"),sort(\"IntVarEnv\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"IntVarEnv\"),w(\"\"),no-attrs)" ) ) ;
ef5 = lookup_func ( ATreadFromString ( "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[sort(\"FunId\"),w(\"\"),ql(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Term\"),w(\"\"),no-attrs)" ) ) ;
ef5sym = lookup_sym ( ATreadFromString ( "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[sort(\"FunId\"),w(\"\"),ql(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Term\"),w(\"\"),no-attrs)" ) ) ;
ef6 = lookup_func ( ATreadFromString ( "prod(id(\"caller\"),w(\"\"),[l(\"funid\"),w(\"\"),ql(\"(\"),w(\"\"),iter(sort(\"CHAR\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FunId\"),w(\"\"),no-attrs)" ) ) ;
ef6sym = lookup_sym ( ATreadFromString ( "prod(id(\"caller\"),w(\"\"),[l(\"funid\"),w(\"\"),ql(\"(\"),w(\"\"),iter(sort(\"CHAR\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FunId\"),w(\"\"),no-attrs)" ) ) ;
ef7 = lookup_func ( ATreadFromString ( "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[sort(\"FunId\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Term\"),w(\"\"),no-attrs)" ) ) ;
ef7sym = lookup_sym ( ATreadFromString ( "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[sort(\"FunId\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Term\"),w(\"\"),no-attrs)" ) ) ;
ef8 = lookup_func ( ATreadFromString ( "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[sort(\"Term\"),w(\"\"),ql(\"!=\"),w(\"\"),sort(\"Term\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Cond\"),w(\"\"),no-attrs)" ) ) ;
ef8sym = lookup_sym ( ATreadFromString ( "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[sort(\"Term\"),w(\"\"),ql(\"!=\"),w(\"\"),sort(\"Term\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Cond\"),w(\"\"),no-attrs)" ) ) ;
}
static ATerm constant0 = NULL ;
static ATerm constant1 = NULL ;
static ATerm constant2 = NULL ;
void init_AUX_Make_Assign_Conds_C9 ( ) {
ATprotect ( & constant0 ) ;
ATprotect ( & constant1 ) ;
ATprotect ( & constant2 ) ;
}
ATerm lf_AUX_Make_Assign_Conds_C9_1 ( ATerm arg0 , ATerm arg1 ) {
{
ATerm tmp [ 2 ] ;
PROF ( prof_lf_AUX_Make_Assign_Conds_C9_1 ) ;
if ( check_sym ( arg0 , ef1sym ) ) {
{
ATerm atmp00 = arg_0 ( arg0 ) ;
{
ATerm atmp01 = arg_1 ( arg0 ) ;
tmp [ 0 ] = ( * ef4 ) ( atmp00 , arg1 ) ;
if ( term_equal ( arg1 , tmp [ 0 ] ) ) {
tmp [ 1 ] = ( * ef4 ) ( atmp01 , tmp [ 0 ] ) ;
if ( ! term_equal ( tmp [ 0 ] , tmp [ 1 ] ) ) {
return ( * ef2 ) ( lf2 ( make_list ( ( * ef3 ) ( atmp00 , atmp01 ) ) ) , tmp [ 1 ] ) ;
}
else {
return ( * ef2 ) ( lf2 ( make_list ( ( * ef3 ) ( ( * ef5 ) ( ( constant0 ? constant0 : ( constant0 = ( * ef6 ) ( lf3 ( ( ATerm ) ATmakeList ( 10 , char_table [ 116 ] , char_table [ 101 ] , char_table [ 114 ] , char_table [ 109 ] , char_table [ 45 ] , char_table [ 101 ] , char_table [ 113 ] , char_table [ 117 ] , char_table [ 97 ] , char_table [ 108 ] ) ) ) ) ) , lf4 ( cons ( make_list ( atmp00 ) , make_list ( atmp01 ) ) ) ) , ( constant1 ? constant1 : ( constant1 = ( * ef7 ) ( ( * ef6 ) ( lf3 ( make_list ( make_char ( 116 ) ) ) ) ) ) ) ) ) ) , tmp [ 1 ] ) ;
}
}
else {
tmp [ 1 ] = ( * ef4 ) ( atmp01 , tmp [ 0 ] ) ;
if ( term_equal ( tmp [ 0 ] , tmp [ 1 ] ) ) {
return ( * ef2 ) ( lf2 ( make_list ( ( * ef3 ) ( atmp01 , atmp00 ) ) ) , tmp [ 1 ] ) ;
}
}
}
}
}
if ( check_sym ( arg0 , ef8sym ) ) {
{
ATerm atmp00 = arg_0 ( arg0 ) ;
{
ATerm atmp01 = arg_1 ( arg0 ) ;
tmp [ 0 ] = ( * ef4 ) ( atmp00 , arg1 ) ;
if ( term_equal ( arg1 , tmp [ 0 ] ) ) {
tmp [ 1 ] = ( * ef4 ) ( atmp01 , tmp [ 0 ] ) ;
if ( term_equal ( tmp [ 0 ] , tmp [ 1 ] ) ) {
return ( * ef2 ) ( lf2 ( make_list ( ( * ef3 ) ( ( * ef5 ) ( ( constant0 ? constant0 : ( constant0 = ( * ef6 ) ( lf3 ( ( ATerm ) ATmakeList ( 10 , char_table [ 116 ] , char_table [ 101 ] , char_table [ 114 ] , char_table [ 109 ] , char_table [ 45 ] , char_table [ 101 ] , char_table [ 113 ] , char_table [ 117 ] , char_table [ 97 ] , char_table [ 108 ] ) ) ) ) ) , lf4 ( cons ( make_list ( atmp00 ) , make_list ( atmp01 ) ) ) ) , ( constant2 ? constant2 : ( constant2 = ( * ef7 ) ( ( * ef6 ) ( lf3 ( make_list ( make_char ( 102 ) ) ) ) ) ) ) ) ) ) , tmp [ 1 ] ) ;
}
}
}
}
}
if ( check_sym ( arg0 , ef3sym ) ) {
{
ATerm atmp00 = arg_0 ( arg0 ) ;
{
ATerm atmp01 = arg_1 ( arg0 ) ;
tmp [ 0 ] = ( * ef4 ) ( atmp01 , arg1 ) ;
return ( * ef2 ) ( lf2 ( make_list ( arg0 ) ) , tmp [ 0 ] ) ;
}
}
}
return make_nf2 ( lf_AUX_Make_Assign_Conds_C9_1sym , arg0 , arg1 ) ;
}
}
ATerm lf2 ( ATerm arg0 ) {
PROF ( prof_lf2 ) ;
return make_nf1 ( lf2sym , arg0 ) ;
}
ATerm lf3 ( ATerm arg0 ) {
PROF ( prof_lf3 ) ;
return make_nf1 ( lf3sym , arg0 ) ;
}
ATerm lf4 ( ATerm arg0 ) {
PROF ( prof_lf4 ) ;
return make_nf1 ( lf4sym , arg0 ) ;
}

