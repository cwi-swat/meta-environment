#include  "asc-support.h"
static Symbol lf_AUX_MuASF_Signature_Ops4_1sym ;
static ATerm lf_AUX_MuASF_Signature_Ops4_1 ( ATerm arg1 , ATerm arg2 ) ;
static Symbol ef2sym ;
static funcptr ef2 ;
static Symbol ef3sym ;
static funcptr ef3 ;
static Symbol ef1sym ;
static funcptr ef1 ;
static Symbol lf2sym ;
static ATerm lf2 ( ATerm arg1 ) ;
void register_AUX_MuASF_Signature_Ops4 ( ) {
lf_AUX_MuASF_Signature_Ops4_1sym = ATmakeSymbol ( "prod(id(\"MuASF-Signature-Ops\"),w(\"\"),[sort(\"FuncDef\"),w(\"\"),ql(\"in\"),w(\"\"),sort(\"FuncDefList\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)"
 , 2 , ATtrue ) ;
ATprotectSymbol ( lf_AUX_MuASF_Signature_Ops4_1sym ) ;
lf2sym = ATmakeSymbol ( "listtype(sort(\"FuncDef\"),ql(\";\"))" , 1 , ATtrue ) ;
ATprotectSymbol ( lf2sym ) ;
register_prod ( ATparse ( "prod(id(\"MuASF-Signature-Ops\"),w(\"\"),[sort(\"FuncDef\"),w(\"\"),ql(\"in\"),w(\"\"),sort(\"FuncDefList\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)" ) , lf_AUX_MuASF_Signature_Ops4_1 , lf_AUX_MuASF_Signature_Ops4_1sym ) ;
register_prod ( ATparse ( "listtype(sort(\"FuncDef\"),ql(\";\"))" ) , lf2 , lf2sym ) ;
}
void resolve_AUX_MuASF_Signature_Ops4 ( ) {
ef1 = lookup_func ( ATreadFromString ( "prod(id(\"MuASF\"),w(\"\"),[iter-sep(l(\"{\"),w(\"\"),sort(\"FuncDef\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\"))],w(\"\"),l(\"->\"),w(\"\"),sort(\"FuncDefList\"),w(\"\"),no-attrs)" ) ) ;
ef1sym = lookup_sym ( ATreadFromString ( "prod(id(\"MuASF\"),w(\"\"),[iter-sep(l(\"{\"),w(\"\"),sort(\"FuncDef\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\"))],w(\"\"),l(\"->\"),w(\"\"),sort(\"FuncDefList\"),w(\"\"),no-attrs)" ) ) ;
ef2 = lookup_func ( ATreadFromString ( "prod(id(\"ATerm-Booleans\"),w(\"\"),[ql(\"false\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)" ) ) ;
ef2sym = lookup_sym ( ATreadFromString ( "prod(id(\"ATerm-Booleans\"),w(\"\"),[ql(\"false\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)" ) ) ;
ef3 = lookup_func ( ATreadFromString ( "prod(id(\"ATerm-Booleans\"),w(\"\"),[ql(\"true\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)" ) ) ;
ef3sym = lookup_sym ( ATreadFromString ( "prod(id(\"ATerm-Booleans\"),w(\"\"),[ql(\"true\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)" ) ) ;
}
static ATerm constant0 = NULL ;
static ATerm constant1 = NULL ;
void init_AUX_MuASF_Signature_Ops4 ( ) {
ATprotect ( & constant0 ) ;
ATprotect ( & constant1 ) ;
}
ATerm lf_AUX_MuASF_Signature_Ops4_1 ( ATerm arg0 , ATerm arg1 ) {
{
ATerm tmp [ 2 ] ;
FUNC_ENTRY ( lf_AUX_MuASF_Signature_Ops4_1sym , ATmakeAppl ( lf_AUX_MuASF_Signature_Ops4_1sym , arg0 , arg1 ) ) ;
{
ATerm ltmp [ 2 ] ;
lbl_lf_AUX_MuASF_Signature_Ops4_1 : ltmp [ 0 ] = arg0 ;
( ltmp [ 1 ] = arg1 ) ;
if ( check_sym ( ltmp [ 1 ] , ef1sym ) ) {
{
ATerm atmp10 = arg_0 ( arg1 ) ;
if ( check_sym ( atmp10 , lf2sym ) ) {
{
ATerm atmp100 = arg_0 ( atmp10 ) ;
if ( not_empty_list ( atmp100 ) ) {
( tmp [ 0 ] = list_head ( atmp100 ) ) ;
{
( tmp [ 1 ] = list_tail ( atmp100 ) ) ;
if ( ! term_equal ( ltmp [ 0 ] , tmp [ 0 ] ) ) {
( arg1 = ( * ef1 ) ( lf2 ( make_list ( tmp [ 1 ] ) ) ) ) ;
goto lbl_lf_AUX_MuASF_Signature_Ops4_1 ;
}
else {
FUNC_EXIT_CONST ( constant0 , ( * ef3 ) ( ) ) ;
}
}
}
else {
FUNC_EXIT_CONST ( constant1 , ( * ef2 ) ( ) ) ;
}
}
}
}
}
FUNC_EXIT ( make_nf2 ( lf_AUX_MuASF_Signature_Ops4_1sym , ltmp [ 0 ] , ltmp [ 1 ] ) ) ;
}
}
}
ATerm lf2 ( ATerm arg0 ) {
CONS_ENTRY ( lf2sym , ATmakeAppl ( lf2sym , arg0 ) ) ;
CONS_EXIT ( make_nf1 ( lf2sym , arg0 ) ) ;
}

