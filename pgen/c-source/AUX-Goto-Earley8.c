#include  "asc-support.h"
static Symbol lf_AUX_Goto_Earley8_1sym ;
static ATerm lf_AUX_Goto_Earley8_1 ( ATerm arg1 , ATerm arg2 ) ;
static Symbol ef2sym ;
static funcptr ef2 ;
static Symbol ef3sym ;
static funcptr ef3 ;
static Symbol lf3sym ;
static ATerm lf3 ( ATerm arg1 ) ;
static Symbol ef5sym ;
static funcptr ef5 ;
static Symbol ef4sym ;
static funcptr ef4 ;
static Symbol ef1sym ;
static funcptr ef1 ;
static Symbol lf2sym ;
static ATerm lf2 ( ATerm arg1 ) ;
void register_AUX_Goto_Earley8 ( ) {
lf_AUX_Goto_Earley8_1sym = ATmakeSymbol ( "prod(id(\"Goto-Earley\"),w(\"\"),[l(\"predicted\"),w(\"\"),ql(\"[[\"),w(\"\"),sort(\"Grammar\"),w(\"\"),ql(\"]]\"),w(\"\"),ql(\"(\"),w(\"\"),sort(\"ItemSet\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"LabelSet\"),w(\"\"),no-attrs)"
 , 2 , ATtrue ) ;
ATprotectSymbol ( lf_AUX_Goto_Earley8_1sym ) ;
lf3sym = ATmakeSymbol ( "listtype(sort(\"Label\"))" , 1 , ATtrue ) ;
ATprotectSymbol ( lf3sym ) ;
lf2sym = ATmakeSymbol ( "listtype(sort(\"Item\"))" , 1 , ATtrue ) ;
ATprotectSymbol ( lf2sym ) ;
register_prod ( ATparse ( "prod(id(\"Goto-Earley\"),w(\"\"),[l(\"predicted\"),w(\"\"),ql(\"[[\"),w(\"\"),sort(\"Grammar\"),w(\"\"),ql(\"]]\"),w(\"\"),ql(\"(\"),w(\"\"),sort(\"ItemSet\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"LabelSet\"),w(\"\"),no-attrs)" ) , lf_AUX_Goto_Earley8_1 , lf_AUX_Goto_Earley8_1sym ) ;
register_prod ( ATparse ( "listtype(sort(\"Item\"))" ) , lf2 , lf2sym ) ;
register_prod ( ATparse ( "listtype(sort(\"Label\"))" ) , lf3 , lf3sym ) ;
}
void resolve_AUX_Goto_Earley8 ( ) {
ef1 = lookup_func ( ATreadFromString ( "prod(id(\"Earley-Items\"),w(\"\"),[ql(\"{\"),w(\"\"),iter(sort(\"Item\"),w(\"\"),l(\"*\")),w(\"\"),ql(\"}\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ItemSet\"),w(\"\"),no-attrs)" ) ) ;
ef1sym = lookup_sym ( ATreadFromString ( "prod(id(\"Earley-Items\"),w(\"\"),[ql(\"{\"),w(\"\"),iter(sort(\"Item\"),w(\"\"),l(\"*\")),w(\"\"),ql(\"}\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ItemSet\"),w(\"\"),no-attrs)" ) ) ;
ef2 = lookup_func ( ATreadFromString ( "prod(id(\"Labels\"),w(\"\"),[ql(\"{\"),w(\"\"),sort(\"Labels\"),w(\"\"),ql(\"}\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"LabelSet\"),w(\"\"),no-attrs)" ) ) ;
ef2sym = lookup_sym ( ATreadFromString ( "prod(id(\"Labels\"),w(\"\"),[ql(\"{\"),w(\"\"),sort(\"Labels\"),w(\"\"),ql(\"}\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"LabelSet\"),w(\"\"),no-attrs)" ) ) ;
ef3 = lookup_func ( ATreadFromString ( "prod(id(\"Labels\"),w(\"\"),[iter(sort(\"Label\"),w(\"\"),l(\"*\"))],w(\"\"),l(\"->\"),w(\"\"),sort(\"Labels\"),w(\"\"),no-attrs)" ) ) ;
ef3sym = lookup_sym ( ATreadFromString ( "prod(id(\"Labels\"),w(\"\"),[iter(sort(\"Label\"),w(\"\"),l(\"*\"))],w(\"\"),l(\"->\"),w(\"\"),sort(\"Labels\"),w(\"\"),no-attrs)" ) ) ;
ef4 = lookup_func ( ATreadFromString ( "prod(id(\"Goto-Earley\"),w(\"\"),[l(\"predicted\"),w(\"\"),ql(\"[[\"),w(\"\"),sort(\"Grammar\"),w(\"\"),ql(\"]]\"),w(\"\"),ql(\"(\"),w(\"\"),sort(\"Item\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"LabelSet\"),w(\"\"),attrs(l(\"{\"),w(\"\"),[l(\"parameter\")],w(\"\"),l(\"}\")))" ) ) ;
ef4sym = lookup_sym ( ATreadFromString ( "prod(id(\"Goto-Earley\"),w(\"\"),[l(\"predicted\"),w(\"\"),ql(\"[[\"),w(\"\"),sort(\"Grammar\"),w(\"\"),ql(\"]]\"),w(\"\"),ql(\"(\"),w(\"\"),sort(\"Item\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"LabelSet\"),w(\"\"),attrs(l(\"{\"),w(\"\"),[l(\"parameter\")],w(\"\"),l(\"}\")))" ) ) ;
ef5 = lookup_func ( ATreadFromString ( "prod(id(\"Labels\"),w(\"\"),[sort(\"LabelSet\"),w(\"\"),ql(\"+\"),w(\"\"),sort(\"LabelSet\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"LabelSet\"),w(\"\"),attrs(l(\"{\"),w(\"\"),[l(\"right\"),w(\"\"),sep(\",\"),w(\"\"),l(\"memo\")],w(\"\"),l(\"}\")))" ) ) ;
ef5sym = lookup_sym ( ATreadFromString ( "prod(id(\"Labels\"),w(\"\"),[sort(\"LabelSet\"),w(\"\"),ql(\"+\"),w(\"\"),sort(\"LabelSet\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"LabelSet\"),w(\"\"),attrs(l(\"{\"),w(\"\"),[l(\"right\"),w(\"\"),sep(\",\"),w(\"\"),l(\"memo\")],w(\"\"),l(\"}\")))" ) ) ;
}
static ATerm constant0 = NULL ;
void init_AUX_Goto_Earley8 ( ) {
ATprotect ( & constant0 ) ;
}
ATerm lf_AUX_Goto_Earley8_1 ( ATerm arg0 , ATerm arg1 ) {
{
ATerm tmp [ 2 ] ;
FUNC_ENTRY ( lf_AUX_Goto_Earley8_1sym , ATmakeAppl ( lf_AUX_Goto_Earley8_1sym , arg0 , arg1 ) ) ;
if ( check_sym ( arg1 , ef1sym ) ) {
{
ATerm atmp10 = arg_0 ( arg1 ) ;
if ( check_sym ( atmp10 , lf2sym ) ) {
{
ATerm atmp100 = arg_0 ( atmp10 ) ;
if ( not_empty_list ( atmp100 ) ) {
tmp [ 0 ] = list_head ( atmp100 ) ;
tmp [ 1 ] = list_tail ( atmp100 ) ;
if ( not_empty_list ( tmp [ 1 ] ) ) {
FUNC_EXIT ( ( * ef5 ) ( ( * ef4 ) ( arg0 , tmp [ 0 ] ) , lf_AUX_Goto_Earley8_1 ( arg0 , ( * ef1 ) ( lf2 ( make_list ( tmp [ 1 ] ) ) ) ) ) ) ;
}
}
else {
FUNC_EXIT_CONST ( constant0 , ( * ef2 ) ( ( * ef3 ) ( lf3 ( make_list ( null ( ) ) ) ) ) ) ;
}
if ( is_single_element ( atmp100 ) ) {
tmp [ 0 ] = list_head ( atmp100 ) ;
FUNC_EXIT ( ( * ef4 ) ( arg0 , tmp [ 0 ] ) ) ;
}
}
}
}
}
FUNC_EXIT ( make_nf2 ( lf_AUX_Goto_Earley8_1sym , arg0 , arg1 ) ) ;
}
}
ATerm lf2 ( ATerm arg0 ) {
CONS_ENTRY ( lf2sym , ATmakeAppl ( lf2sym , arg0 ) ) ;
CONS_EXIT ( make_nf1 ( lf2sym , arg0 ) ) ;
}
ATerm lf3 ( ATerm arg0 ) {
CONS_ENTRY ( lf3sym , ATmakeAppl ( lf3sym , arg0 ) ) ;
CONS_EXIT ( make_nf1 ( lf3sym , arg0 ) ) ;
}

