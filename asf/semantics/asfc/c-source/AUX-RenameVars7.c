#include  "asc-support.h"
static Symbol lf_AUX_RenameVars7_1sym ;
static ATerm lf_AUX_RenameVars7_1 ( ATerm arg1 , ATerm arg2 ) ;
static Symbol ef1sym ;
static funcptr ef1 ;
static Symbol ef5sym ;
static funcptr ef5 ;
static Symbol ef2sym ;
static funcptr ef2 ;
static Symbol ef6sym ;
static funcptr ef6 ;
static Symbol ef3sym ;
static funcptr ef3 ;
static Symbol ef4sym ;
static funcptr ef4 ;
void register_AUX_RenameVars7 ( ) {
lf_AUX_RenameVars7_1sym = ATmakeSymbol ( "prod(id(\"RenameVars\"),w(\"\"),[l(\"rename-in-cond\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Cond\"),w(\"\"),l(\",\"),w(\"\"),sort(\"IntVVarEnv\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"CIVE\"),w(\"\"),no-attrs)"
 , 2 , ATtrue ) ;
ATprotectSymbol ( lf_AUX_RenameVars7_1sym ) ;
register_prod ( ATparse ( "prod(id(\"RenameVars\"),w(\"\"),[l(\"rename-in-cond\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Cond\"),w(\"\"),l(\",\"),w(\"\"),sort(\"IntVVarEnv\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"CIVE\"),w(\"\"),no-attrs)" ) , lf_AUX_RenameVars7_1 , lf_AUX_RenameVars7_1sym ) ;
}
void resolve_AUX_RenameVars7 ( ) {
ef1 = lookup_func ( ATreadFromString ( "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[sort(\"Term\"),w(\"\"),ql(\"==\"),w(\"\"),sort(\"Term\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Cond\"),w(\"\"),no-attrs)" ) ) ;
ef1sym = lookup_sym ( ATreadFromString ( "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[sort(\"Term\"),w(\"\"),ql(\"==\"),w(\"\"),sort(\"Term\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Cond\"),w(\"\"),no-attrs)" ) ) ;
ef2 = lookup_func ( ATreadFromString ( "prod(id(\"RenameVars\"),w(\"\"),[ql(\"[\"),w(\"\"),sort(\"Cond\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"IntVVarEnv\"),w(\"\"),ql(\"]\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"CIVE\"),w(\"\"),no-attrs)" ) ) ;
ef2sym = lookup_sym ( ATreadFromString ( "prod(id(\"RenameVars\"),w(\"\"),[ql(\"[\"),w(\"\"),sort(\"Cond\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"IntVVarEnv\"),w(\"\"),ql(\"]\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"CIVE\"),w(\"\"),no-attrs)" ) ) ;
ef3 = lookup_func ( ATreadFromString ( "prod(id(\"RenameVars\"),w(\"\"),[l(\"rename-in-term\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Term\"),w(\"\"),l(\",\"),w(\"\"),sort(\"IntVVarEnv\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"TIVE\"),w(\"\"),no-attrs)" ) ) ;
ef3sym = lookup_sym ( ATreadFromString ( "prod(id(\"RenameVars\"),w(\"\"),[l(\"rename-in-term\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Term\"),w(\"\"),l(\",\"),w(\"\"),sort(\"IntVVarEnv\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"TIVE\"),w(\"\"),no-attrs)" ) ) ;
ef4 = lookup_func ( ATreadFromString ( "prod(id(\"RenameVars\"),w(\"\"),[ql(\"[\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"IntVVarEnv\"),w(\"\"),ql(\"]\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"TIVE\"),w(\"\"),no-attrs)" ) ) ;
ef4sym = lookup_sym ( ATreadFromString ( "prod(id(\"RenameVars\"),w(\"\"),[ql(\"[\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"IntVVarEnv\"),w(\"\"),ql(\"]\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"TIVE\"),w(\"\"),no-attrs)" ) ) ;
ef5 = lookup_func ( ATreadFromString ( "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[sort(\"Term\"),w(\"\"),ql(\"!=\"),w(\"\"),sort(\"Term\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Cond\"),w(\"\"),no-attrs)" ) ) ;
ef5sym = lookup_sym ( ATreadFromString ( "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[sort(\"Term\"),w(\"\"),ql(\"!=\"),w(\"\"),sort(\"Term\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Cond\"),w(\"\"),no-attrs)" ) ) ;
ef6 = lookup_func ( ATreadFromString ( "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[sort(\"Term\"),w(\"\"),ql(\"=:\"),w(\"\"),sort(\"Term\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Cond\"),w(\"\"),no-attrs)" ) ) ;
ef6sym = lookup_sym ( ATreadFromString ( "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[sort(\"Term\"),w(\"\"),ql(\"=:\"),w(\"\"),sort(\"Term\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Cond\"),w(\"\"),no-attrs)" ) ) ;
}
void init_AUX_RenameVars7 ( ) {
}
ATerm lf_AUX_RenameVars7_1 ( ATerm arg0 , ATerm arg1 ) {
{
ATerm tmp [ 6 ] ;
FUNC_ENTRY ( lf_AUX_RenameVars7_1sym , ATmakeAppl ( lf_AUX_RenameVars7_1sym , arg0 , arg1 ) ) ;
if ( check_sym ( arg0 , ef1sym ) ) {
{
ATerm atmp00 = arg_0 ( arg0 ) ;
{
ATerm atmp01 = arg_1 ( arg0 ) ;
tmp [ 0 ] = ( * ef3 ) ( atmp00 , arg1 ) ;
if ( check_sym ( tmp [ 0 ] , ef4sym ) ) {
tmp [ 1 ] = arg_0 ( tmp [ 0 ] ) ;
tmp [ 2 ] = arg_1 ( tmp [ 0 ] ) ;
tmp [ 3 ] = ( * ef3 ) ( atmp01 , tmp [ 2 ] ) ;
if ( check_sym ( tmp [ 3 ] , ef4sym ) ) {
tmp [ 4 ] = arg_0 ( tmp [ 3 ] ) ;
tmp [ 5 ] = arg_1 ( tmp [ 3 ] ) ;
FUNC_EXIT ( ( * ef2 ) ( ( * ef1 ) ( tmp [ 1 ] , tmp [ 4 ] ) , tmp [ 5 ] ) ) ;
}
}
}
}
}
if ( check_sym ( arg0 , ef5sym ) ) {
{
ATerm atmp00 = arg_0 ( arg0 ) ;
{
ATerm atmp01 = arg_1 ( arg0 ) ;
tmp [ 0 ] = ( * ef3 ) ( atmp00 , arg1 ) ;
if ( check_sym ( tmp [ 0 ] , ef4sym ) ) {
tmp [ 1 ] = arg_0 ( tmp [ 0 ] ) ;
tmp [ 2 ] = arg_1 ( tmp [ 0 ] ) ;
tmp [ 3 ] = ( * ef3 ) ( atmp01 , tmp [ 2 ] ) ;
if ( check_sym ( tmp [ 3 ] , ef4sym ) ) {
tmp [ 4 ] = arg_0 ( tmp [ 3 ] ) ;
tmp [ 5 ] = arg_1 ( tmp [ 3 ] ) ;
FUNC_EXIT ( ( * ef2 ) ( ( * ef5 ) ( tmp [ 1 ] , tmp [ 4 ] ) , tmp [ 5 ] ) ) ;
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
tmp [ 0 ] = ( * ef3 ) ( atmp00 , arg1 ) ;
if ( check_sym ( tmp [ 0 ] , ef4sym ) ) {
tmp [ 1 ] = arg_0 ( tmp [ 0 ] ) ;
tmp [ 2 ] = arg_1 ( tmp [ 0 ] ) ;
tmp [ 3 ] = ( * ef3 ) ( atmp01 , tmp [ 2 ] ) ;
if ( check_sym ( tmp [ 3 ] , ef4sym ) ) {
tmp [ 4 ] = arg_0 ( tmp [ 3 ] ) ;
tmp [ 5 ] = arg_1 ( tmp [ 3 ] ) ;
FUNC_EXIT ( ( * ef2 ) ( ( * ef6 ) ( tmp [ 1 ] , tmp [ 4 ] ) , tmp [ 5 ] ) ) ;
}
}
}
}
}
FUNC_EXIT ( make_nf2 ( lf_AUX_RenameVars7_1sym , arg0 , arg1 ) ) ;
}
}

