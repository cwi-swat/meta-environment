#include  "asc-support.h"
static Symbol lf_AUX_MuASF_Equations_Ops25_1sym ;
static ATerm lf_AUX_MuASF_Equations_Ops25_1 ( ATerm arg1 ) ;
static Symbol ef1sym ;
static funcptr ef1 ;
static Symbol ef2sym ;
static funcptr ef2 ;
static Symbol ef3sym ;
static funcptr ef3 ;
static Symbol ef4sym ;
static funcptr ef4 ;
void register_AUX_MuASF_Equations_Ops25 ( ) {
lf_AUX_MuASF_Equations_Ops25_1sym = ATmakeSymbol ( "prod(id(\"MuASF-Equations-Ops\"),w(\"\"),[l(\"is-plus-var\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Term\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)"
 , 1 , ATtrue ) ;
ATprotectSymbol ( lf_AUX_MuASF_Equations_Ops25_1sym ) ;
register_prod ( ATparse ( "prod(id(\"MuASF-Equations-Ops\"),w(\"\"),[l(\"is-plus-var\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Term\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)" ) , lf_AUX_MuASF_Equations_Ops25_1 , lf_AUX_MuASF_Equations_Ops25_1sym ) ;
}
void resolve_AUX_MuASF_Equations_Ops25 ( ) {
ef1 = lookup_func ( ATreadFromString ( "prod(id(\"MuASF\"),w(\"\"),[sort(\"Var\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Term\"),w(\"\"),no-attrs)" ) ) ;
ef1sym = lookup_sym ( ATreadFromString ( "prod(id(\"MuASF\"),w(\"\"),[sort(\"Var\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Term\"),w(\"\"),no-attrs)" ) ) ;
ef2 = lookup_func ( ATreadFromString ( "prod(id(\"MuASF\"),w(\"\"),[ql(\"+\"),w(\"\"),sort(\"VarId\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Var\"),w(\"\"),no-attrs)" ) ) ;
ef2sym = lookup_sym ( ATreadFromString ( "prod(id(\"MuASF\"),w(\"\"),[ql(\"+\"),w(\"\"),sort(\"VarId\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Var\"),w(\"\"),no-attrs)" ) ) ;
ef3 = lookup_func ( ATreadFromString ( "prod(id(\"ATerm-Booleans\"),w(\"\"),[ql(\"true\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)" ) ) ;
ef3sym = lookup_sym ( ATreadFromString ( "prod(id(\"ATerm-Booleans\"),w(\"\"),[ql(\"true\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)" ) ) ;
ef4 = lookup_func ( ATreadFromString ( "prod(id(\"ATerm-Booleans\"),w(\"\"),[ql(\"false\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)" ) ) ;
ef4sym = lookup_sym ( ATreadFromString ( "prod(id(\"ATerm-Booleans\"),w(\"\"),[ql(\"false\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)" ) ) ;
}
static ATerm constant0 = NULL ;
static ATerm constant1 = NULL ;
void init_AUX_MuASF_Equations_Ops25 ( ) {
ATprotect ( & constant0 ) ;
ATprotect ( & constant1 ) ;
}
ATerm lf_AUX_MuASF_Equations_Ops25_1 ( ATerm arg0 ) {
FUNC_ENTRY ( lf_AUX_MuASF_Equations_Ops25_1sym , ATmakeAppl ( lf_AUX_MuASF_Equations_Ops25_1sym , arg0 ) ) ;
if ( check_sym ( arg0 , ef1sym ) ) {
{
ATerm atmp00 = arg_0 ( arg0 ) ;
if ( check_sym ( atmp00 , ef2sym ) ) {
{
ATerm atmp000 = arg_0 ( atmp00 ) ;
FUNC_EXIT_CONST ( constant0 , ( * ef3 ) ( ) ) ;
}
}
}
}
FUNC_EXIT_CONST ( constant1 , ( * ef4 ) ( ) ) ;
FUNC_EXIT ( make_nf1 ( lf_AUX_MuASF_Equations_Ops25_1sym , arg0 ) ) ;
}

