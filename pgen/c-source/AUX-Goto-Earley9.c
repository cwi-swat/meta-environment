#include  "asc-support.h"
static Symbol lf_AUX_Goto_Earley9_1sym ;
static ATerm lf_AUX_Goto_Earley9_1 ( ATerm arg1 , ATerm arg2 , ATerm arg3 ) ;
static Symbol ef2sym ;
static funcptr ef2 ;
static Symbol ef3sym ;
static funcptr ef3 ;
static Symbol ef4sym ;
static funcptr ef4 ;
static Symbol ef5sym ;
static funcptr ef5 ;
static Symbol ef1sym ;
static funcptr ef1 ;
static Symbol lf2sym ;
static ATerm lf2 ( ATerm arg1 ) ;
void register_AUX_Goto_Earley9 ( ) {
lf_AUX_Goto_Earley9_1sym = ATmakeSymbol ( "prod(id(\"Goto-Earley\"),w(\"\"),[l(\"closure\"),w(\"\"),ql(\"[[\"),w(\"\"),sort(\"Grammar\"),w(\"\"),ql(\"]]\"),w(\"\"),ql(\"(\"),w(\"\"),sort(\"ItemSet\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"ItemSet\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ItemSet\"),w(\"\"),no-attrs)"
 , 3 , ATtrue ) ;
ATprotectSymbol ( lf_AUX_Goto_Earley9_1sym ) ;
lf2sym = ATmakeSymbol ( "listtype(sort(\"Item\"))" , 1 , ATtrue ) ;
ATprotectSymbol ( lf2sym ) ;
register_prod ( ATparse ( "prod(id(\"Goto-Earley\"),w(\"\"),[l(\"closure\"),w(\"\"),ql(\"[[\"),w(\"\"),sort(\"Grammar\"),w(\"\"),ql(\"]]\"),w(\"\"),ql(\"(\"),w(\"\"),sort(\"ItemSet\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"ItemSet\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ItemSet\"),w(\"\"),no-attrs)" ) , lf_AUX_Goto_Earley9_1 , lf_AUX_Goto_Earley9_1sym ) ;
register_prod ( ATparse ( "listtype(sort(\"Item\"))" ) , lf2 , lf2sym ) ;
}
void resolve_AUX_Goto_Earley9 ( ) {
ef1 = lookup_func ( ATreadFromString ( "prod(id(\"Earley-Items\"),w(\"\"),[ql(\"{\"),w(\"\"),iter(sort(\"Item\"),w(\"\"),l(\"*\")),w(\"\"),ql(\"}\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ItemSet\"),w(\"\"),no-attrs)" ) ) ;
ef1sym = lookup_sym ( ATreadFromString ( "prod(id(\"Earley-Items\"),w(\"\"),[ql(\"{\"),w(\"\"),iter(sort(\"Item\"),w(\"\"),l(\"*\")),w(\"\"),ql(\"}\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ItemSet\"),w(\"\"),no-attrs)" ) ) ;
ef2 = lookup_func ( ATreadFromString ( "prod(id(\"Earley-Items\"),w(\"\"),[sort(\"Item\"),w(\"\"),ql(\"(-\"),w(\"\"),sort(\"ItemSet\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)" ) ) ;
ef2sym = lookup_sym ( ATreadFromString ( "prod(id(\"Earley-Items\"),w(\"\"),[sort(\"Item\"),w(\"\"),ql(\"(-\"),w(\"\"),sort(\"ItemSet\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)" ) ) ;
ef3 = lookup_func ( ATreadFromString ( "prod(id(\"Booleans\"),w(\"\"),[ql(\"true\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)" ) ) ;
ef3sym = lookup_sym ( ATreadFromString ( "prod(id(\"Booleans\"),w(\"\"),[ql(\"true\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)" ) ) ;
ef4 = lookup_func ( ATreadFromString ( "prod(id(\"Earley-Items\"),w(\"\"),[sort(\"ItemSet\"),w(\"\"),ql(\"||\"),w(\"\"),sort(\"ItemSet\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ItemSet\"),w(\"\"),attrs(l(\"{\"),w(\"\"),[l(\"right\")],w(\"\"),l(\"}\")))" ) ) ;
ef4sym = lookup_sym ( ATreadFromString ( "prod(id(\"Earley-Items\"),w(\"\"),[sort(\"ItemSet\"),w(\"\"),ql(\"||\"),w(\"\"),sort(\"ItemSet\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ItemSet\"),w(\"\"),attrs(l(\"{\"),w(\"\"),[l(\"right\")],w(\"\"),l(\"}\")))" ) ) ;
ef5 = lookup_func ( ATreadFromString ( "prod(id(\"Goto-Earley\"),w(\"\"),[l(\"pred\"),w(\"\"),ql(\"[[\"),w(\"\"),sort(\"Grammar\"),w(\"\"),ql(\"]]\"),w(\"\"),ql(\"(\"),w(\"\"),sort(\"Item\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ItemSet\"),w(\"\"),attrs(l(\"{\"),w(\"\"),[l(\"parameter\")],w(\"\"),l(\"}\")))" ) ) ;
ef5sym = lookup_sym ( ATreadFromString ( "prod(id(\"Goto-Earley\"),w(\"\"),[l(\"pred\"),w(\"\"),ql(\"[[\"),w(\"\"),sort(\"Grammar\"),w(\"\"),ql(\"]]\"),w(\"\"),ql(\"(\"),w(\"\"),sort(\"Item\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ItemSet\"),w(\"\"),attrs(l(\"{\"),w(\"\"),[l(\"parameter\")],w(\"\"),l(\"}\")))" ) ) ;
}
static ATerm constant0 = NULL ;
void init_AUX_Goto_Earley9 ( ) {
ATprotect ( & constant0 ) ;
}
ATerm lf_AUX_Goto_Earley9_1 ( ATerm arg0 , ATerm arg1 , ATerm arg2 ) {
{
ATerm tmp [ 2 ] ;
FUNC_ENTRY ( lf_AUX_Goto_Earley9_1sym , ATmakeAppl ( lf_AUX_Goto_Earley9_1sym , arg0 , arg1 , arg2 ) ) ;
{
ATerm ltmp [ 3 ] ;
lbl_lf_AUX_Goto_Earley9_1 : ltmp [ 0 ] = arg0 ;
ltmp [ 1 ] = arg1 ;
ltmp [ 2 ] = arg2 ;
if ( check_sym ( ltmp [ 2 ] , ef1sym ) ) {
{
ATerm atmp20 = arg_0 ( arg2 ) ;
if ( check_sym ( atmp20 , lf2sym ) ) {
{
ATerm atmp200 = arg_0 ( atmp20 ) ;
if ( not_empty_list ( atmp200 ) ) {
tmp [ 0 ] = list_head ( atmp200 ) ;
tmp [ 1 ] = list_tail ( atmp200 ) ;
if ( term_equal ( ( * ef2 ) ( tmp [ 0 ] , ltmp [ 1 ] ) , ( constant0 ? constant0 : ( constant0 = ( * ef3 ) ( ) ) ) ) ) {
arg2 = ( * ef1 ) ( lf2 ( make_list ( tmp [ 1 ] ) ) ) ;
goto lbl_lf_AUX_Goto_Earley9_1 ;
}
}
else {
FUNC_EXIT ( ltmp [ 1 ] ) ;
}
}
}
}
}
if ( check_sym ( ltmp [ 2 ] , ef1sym ) ) {
{
ATerm atmp20 = arg_0 ( arg2 ) ;
if ( check_sym ( atmp20 , lf2sym ) ) {
{
ATerm atmp200 = arg_0 ( atmp20 ) ;
if ( not_empty_list ( atmp200 ) ) {
tmp [ 0 ] = list_head ( atmp200 ) ;
tmp [ 1 ] = list_tail ( atmp200 ) ;
arg1 = ( * ef4 ) ( ( * ef1 ) ( lf2 ( make_list ( tmp [ 0 ] ) ) ) , ltmp [ 1 ] ) ;
arg2 = ( * ef4 ) ( ( * ef5 ) ( ltmp [ 0 ] , tmp [ 0 ] ) , ( * ef1 ) ( lf2 ( make_list ( tmp [ 1 ] ) ) ) ) ;
goto lbl_lf_AUX_Goto_Earley9_1 ;
}
}
}
}
}
FUNC_EXIT ( make_nf3 ( lf_AUX_Goto_Earley9_1sym , ltmp [ 0 ] , ltmp [ 1 ] , ltmp [ 2 ] ) ) ;
}
}
}
ATerm lf2 ( ATerm arg0 ) {
CONS_ENTRY ( lf2sym , ATmakeAppl ( lf2sym , arg0 ) ) ;
CONS_EXIT ( make_nf1 ( lf2sym , arg0 ) ) ;
}

