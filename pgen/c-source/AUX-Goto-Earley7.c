#include  "support.h"
static Symbol lf_AUX_Goto_Earley7_1sym ;
static ATerm lf_AUX_Goto_Earley7_1 ( ATerm arg1 , ATerm arg2 ) ;
static Symbol ef5sym ;
static funcptr ef5 ;
static Symbol ef2sym ;
static funcptr ef2 ;
static Symbol lf3sym ;
static ATerm lf3 ( ATerm arg1 ) ;
static Symbol ef6sym ;
static funcptr ef6 ;
static Symbol ef3sym ;
static funcptr ef3 ;
static Symbol ef4sym ;
static funcptr ef4 ;
static Symbol lf4sym ;
static ATerm lf4 ( ATerm arg1 ) ;
static Symbol ef1sym ;
static funcptr ef1 ;
static Symbol lf2sym ;
static ATerm lf2 ( ATerm arg1 ) ;
void register_AUX_Goto_Earley7 ( ) {
lf_AUX_Goto_Earley7_1sym = ATmakeSymbol ( "prod(id(\"Goto-Earley\"),w(\"\"),[l(\"initial\"),w(\"\"),ql(\"[[\"),w(\"\"),sort(\"Productions\"),w(\"\"),ql(\"]]\"),w(\"\"),ql(\"(\"),w(\"\"),sort(\"Symbol\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ItemSet\"),w(\"\"),no-attrs)"
 , 2 , ATtrue ) ;
ATprotectSymbol ( lf_AUX_Goto_Earley7_1sym ) ;
lf3sym = ATmakeSymbol ( "listtype(sort(\"Item\"))" , 1 , ATtrue ) ;
ATprotectSymbol ( lf3sym ) ;
lf4sym = ATmakeSymbol ( "listtype(sort(\"Symbol\"))" , 1 , ATtrue ) ;
ATprotectSymbol ( lf4sym ) ;
lf2sym = ATmakeSymbol ( "listtype(sort(\"Production\"))" , 1 , ATtrue ) ;
ATprotectSymbol ( lf2sym ) ;
register_prod ( ATparse ( "prod(id(\"Goto-Earley\"),w(\"\"),[l(\"initial\"),w(\"\"),ql(\"[[\"),w(\"\"),sort(\"Productions\"),w(\"\"),ql(\"]]\"),w(\"\"),ql(\"(\"),w(\"\"),sort(\"Symbol\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ItemSet\"),w(\"\"),no-attrs)" ) , lf_AUX_Goto_Earley7_1 , lf_AUX_Goto_Earley7_1sym ) ;
register_prod ( ATparse ( "listtype(sort(\"Production\"))" ) , lf2 , lf2sym ) ;
register_prod ( ATparse ( "listtype(sort(\"Item\"))" ) , lf3 , lf3sym ) ;
register_prod ( ATparse ( "listtype(sort(\"Symbol\"))" ) , lf4 , lf4sym ) ;
}
void resolve_AUX_Goto_Earley7 ( ) {
ef1 = lookup_func ( ATreadFromString ( "prod(id(\"Kernel-Sdf-Syntax\"),w(\"\"),[iter(sort(\"Production\"),w(\"\"),l(\"*\"))],w(\"\"),l(\"->\"),w(\"\"),sort(\"Productions\"),w(\"\"),no-attrs)" ) ) ;
ef1sym = lookup_sym ( ATreadFromString ( "prod(id(\"Kernel-Sdf-Syntax\"),w(\"\"),[iter(sort(\"Production\"),w(\"\"),l(\"*\"))],w(\"\"),l(\"->\"),w(\"\"),sort(\"Productions\"),w(\"\"),no-attrs)" ) ) ;
ef2 = lookup_func ( ATreadFromString ( "prod(id(\"Earley-Items\"),w(\"\"),[ql(\"{\"),w(\"\"),iter(sort(\"Item\"),w(\"\"),l(\"*\")),w(\"\"),ql(\"}\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ItemSet\"),w(\"\"),no-attrs)" ) ) ;
ef2sym = lookup_sym ( ATreadFromString ( "prod(id(\"Earley-Items\"),w(\"\"),[ql(\"{\"),w(\"\"),iter(sort(\"Item\"),w(\"\"),l(\"*\")),w(\"\"),ql(\"}\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ItemSet\"),w(\"\"),no-attrs)" ) ) ;
ef3 = lookup_func ( ATreadFromString ( "prod(id(\"Kernel-Sdf-Syntax\"),w(\"\"),[sort(\"Symbols\"),w(\"\"),ql(\"->\"),w(\"\"),sort(\"Symbol\"),w(\"\"),sort(\"Attributes\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Production\"),w(\"\"),no-attrs)" ) ) ;
ef3sym = lookup_sym ( ATreadFromString ( "prod(id(\"Kernel-Sdf-Syntax\"),w(\"\"),[sort(\"Symbols\"),w(\"\"),ql(\"->\"),w(\"\"),sort(\"Symbol\"),w(\"\"),sort(\"Attributes\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Production\"),w(\"\"),no-attrs)" ) ) ;
ef4 = lookup_func ( ATreadFromString ( "prod(id(\"Symbols\"),w(\"\"),[iter(sort(\"Symbol\"),w(\"\"),l(\"*\"))],w(\"\"),l(\"->\"),w(\"\"),sort(\"Symbols\"),w(\"\"),no-attrs)" ) ) ;
ef4sym = lookup_sym ( ATreadFromString ( "prod(id(\"Symbols\"),w(\"\"),[iter(sort(\"Symbol\"),w(\"\"),l(\"*\"))],w(\"\"),l(\"->\"),w(\"\"),sort(\"Symbols\"),w(\"\"),no-attrs)" ) ) ;
ef5 = lookup_func ( ATreadFromString ( "prod(id(\"Earley-Items\"),w(\"\"),[sort(\"ItemSet\"),w(\"\"),ql(\"||\"),w(\"\"),sort(\"ItemSet\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ItemSet\"),w(\"\"),attrs(l(\"{\"),w(\"\"),[l(\"right\")],w(\"\"),l(\"}\")))" ) ) ;
ef5sym = lookup_sym ( ATreadFromString ( "prod(id(\"Earley-Items\"),w(\"\"),[sort(\"ItemSet\"),w(\"\"),ql(\"||\"),w(\"\"),sort(\"ItemSet\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ItemSet\"),w(\"\"),attrs(l(\"{\"),w(\"\"),[l(\"right\")],w(\"\"),l(\"}\")))" ) ) ;
ef6 = lookup_func ( ATreadFromString ( "prod(id(\"Earley-Items\"),w(\"\"),[ql(\"[\"),w(\"\"),sort(\"Symbols\"),w(\"\"),ql(\".\"),w(\"\"),sort(\"Production\"),w(\"\"),ql(\"]\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Item\"),w(\"\"),no-attrs)" ) ) ;
ef6sym = lookup_sym ( ATreadFromString ( "prod(id(\"Earley-Items\"),w(\"\"),[ql(\"[\"),w(\"\"),sort(\"Symbols\"),w(\"\"),ql(\".\"),w(\"\"),sort(\"Production\"),w(\"\"),ql(\"]\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Item\"),w(\"\"),no-attrs)" ) ) ;
}
void init_AUX_Goto_Earley7 ( ) {
}
ATerm lf_AUX_Goto_Earley7_1 ( ATerm arg0 , ATerm arg1 ) {
{
ATerm tmp [ 7 ] ;
FUNC_ENTRY ( lf_AUX_Goto_Earley7_1sym , ATmakeAppl ( lf_AUX_Goto_Earley7_1sym , arg0 , arg1 ) ) ;
lbl_lf_AUX_Goto_Earley7_1 : if ( check_sym ( arg0 , ef1sym ) ) {
{
ATerm atmp00 = arg_0 ( arg0 ) ;
if ( check_sym ( atmp00 , lf2sym ) ) {
{
ATerm atmp000 = arg_0 ( atmp00 ) ;
if ( not_empty_list ( atmp000 ) ) {
tmp [ 0 ] = list_head ( atmp000 ) ;
tmp [ 1 ] = list_tail ( atmp000 ) ;
if ( check_sym ( tmp [ 0 ] , ef3sym ) ) {
tmp [ 2 ] = arg_0 ( tmp [ 0 ] ) ;
tmp [ 3 ] = arg_1 ( tmp [ 0 ] ) ;
tmp [ 4 ] = arg_2 ( tmp [ 0 ] ) ;
if ( check_sym ( tmp [ 2 ] , ef4sym ) ) {
tmp [ 5 ] = arg_0 ( tmp [ 2 ] ) ;
if ( check_sym ( tmp [ 5 ] , lf4sym ) ) {
tmp [ 6 ] = arg_0 ( tmp [ 5 ] ) ;
if ( term_equal ( tmp [ 3 ] , arg1 ) ) {
FUNC_EXIT ( ( * ef5 ) ( ( * ef2 ) ( lf3 ( make_list ( ( * ef6 ) ( ( * ef4 ) ( lf4 ( make_list ( null ( ) ) ) ) , ( * ef3 ) ( ( * ef4 ) ( lf4 ( make_list ( tmp [ 6 ] ) ) ) , tmp [ 3 ] , tmp [ 4 ] ) ) ) ) ) , lf_AUX_Goto_Earley7_1 ( ( * ef1 ) ( lf2 ( make_list ( tmp [ 1 ] ) ) ) , tmp [ 3 ] ) ) ) ;
}
}
}
}
}
else {
FUNC_EXIT ( ( * ef2 ) ( lf3 ( make_list ( null ( ) ) ) ) ) ;
}
}
}
}
}
if ( check_sym ( arg0 , ef1sym ) ) {
{
ATerm atmp00 = arg_0 ( arg0 ) ;
if ( check_sym ( atmp00 , lf2sym ) ) {
{
ATerm atmp000 = arg_0 ( atmp00 ) ;
if ( not_empty_list ( atmp000 ) ) {
tmp [ 0 ] = list_head ( atmp000 ) ;
tmp [ 1 ] = list_tail ( atmp000 ) ;
arg0 = ( * ef1 ) ( lf2 ( make_list ( tmp [ 1 ] ) ) ) ;
arg1 = arg1 ;
goto lbl_lf_AUX_Goto_Earley7_1 ;
}
}
}
}
}
FUNC_EXIT ( make_nf2 ( lf_AUX_Goto_Earley7_1sym , arg0 , arg1 ) ) ;
}
}
ATerm lf2 ( ATerm arg0 ) {
CONS_ENTRY ( lf2sym , ATmakeAppl ( lf2sym , arg0 ) ) ;
CONS_EXIT ( make_nf1 ( lf2sym , arg0 ) ) ;
}
ATerm lf4 ( ATerm arg0 ) {
CONS_ENTRY ( lf4sym , ATmakeAppl ( lf4sym , arg0 ) ) ;
CONS_EXIT ( make_nf1 ( lf4sym , arg0 ) ) ;
}
ATerm lf3 ( ATerm arg0 ) {
CONS_ENTRY ( lf3sym , ATmakeAppl ( lf3sym , arg0 ) ) ;
CONS_EXIT ( make_nf1 ( lf3sym , arg0 ) ) ;
}

