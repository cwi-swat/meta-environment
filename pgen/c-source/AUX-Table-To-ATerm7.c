#include  "asc-support.h"
static Symbol lf_AUX_Table_To_ATerm7_1sym ;
static ATerm lf_AUX_Table_To_ATerm7_1 ( ATerm arg1 ) ;
static Symbol ef2sym ;
static funcptr ef2 ;
static Symbol ef3sym ;
static funcptr ef3 ;
static Symbol ef4sym ;
static funcptr ef4 ;
static Symbol lf3sym ;
static ATerm lf3 ( ATerm arg1 ) ;
static Symbol ef5sym ;
static funcptr ef5 ;
static Symbol ef7sym ;
static funcptr ef7 ;
static Symbol ef8sym ;
static funcptr ef8 ;
static Symbol ef9sym ;
static funcptr ef9 ;
static Symbol ef10sym ;
static funcptr ef10 ;
static Symbol ef11sym ;
static funcptr ef11 ;
static Symbol ef6sym ;
static funcptr ef6 ;
static Symbol ef12sym ;
static funcptr ef12 ;
static Symbol ef13sym ;
static funcptr ef13 ;
static Symbol ef14sym ;
static funcptr ef14 ;
static Symbol ef15sym ;
static funcptr ef15 ;
static Symbol ef1sym ;
static funcptr ef1 ;
static Symbol lf2sym ;
static ATerm lf2 ( ATerm arg1 ) ;
void register_AUX_Table_To_ATerm7 ( ) {
lf_AUX_Table_To_ATerm7_1sym = ATmakeSymbol ( "prod(id(\"Table-To-ATerm\"),w(\"\"),[l(\"atermlist\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Action-Entries\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATermList\"),w(\"\"),no-attrs)"
 , 1 , ATtrue ) ;
ATprotectSymbol ( lf_AUX_Table_To_ATerm7_1sym ) ;
lf3sym = ATmakeSymbol ( "listtype(sort(\"Label\"))" , 1 , ATtrue ) ;
ATprotectSymbol ( lf3sym ) ;
lf2sym = ATmakeSymbol ( "listtype(sort(\"Action-Entry\"),ql(\",\"))" , 1 , ATtrue ) ;
ATprotectSymbol ( lf2sym ) ;
register_prod ( ATparse ( "prod(id(\"Table-To-ATerm\"),w(\"\"),[l(\"atermlist\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Action-Entries\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATermList\"),w(\"\"),no-attrs)" ) , lf_AUX_Table_To_ATerm7_1 , lf_AUX_Table_To_ATerm7_1sym ) ;
register_prod ( ATparse ( "listtype(sort(\"Action-Entry\"),ql(\",\"))" ) , lf2 , lf2sym ) ;
register_prod ( ATparse ( "listtype(sort(\"Label\"))" ) , lf3 , lf3sym ) ;
}
void resolve_AUX_Table_To_ATerm7 ( ) {
ef1 = lookup_func ( ATreadFromString ( "prod(id(\"Parse-Table\"),w(\"\"),[ql(\"[\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Action-Entry\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\"]\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Action-Entries\"),w(\"\"),no-attrs)" ) ) ;
ef1sym = lookup_sym ( ATreadFromString ( "prod(id(\"Parse-Table\"),w(\"\"),[ql(\"[\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Action-Entry\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\"]\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Action-Entries\"),w(\"\"),no-attrs)" ) ) ;
ef2 = lookup_func ( ATreadFromString ( "prod(id(\"Parse-Table\"),w(\"\"),[l(\"action\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"LabelSet\"),w(\"\"),l(\",\"),w(\"\"),sort(\"ActionSet\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Action-Entry\"),w(\"\"),no-attrs)" ) ) ;
ef2sym = lookup_sym ( ATreadFromString ( "prod(id(\"Parse-Table\"),w(\"\"),[l(\"action\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"LabelSet\"),w(\"\"),l(\",\"),w(\"\"),sort(\"ActionSet\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Action-Entry\"),w(\"\"),no-attrs)" ) ) ;
ef3 = lookup_func ( ATreadFromString ( "prod(id(\"Labels\"),w(\"\"),[ql(\"{\"),w(\"\"),sort(\"Labels\"),w(\"\"),ql(\"}\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"LabelSet\"),w(\"\"),no-attrs)" ) ) ;
ef3sym = lookup_sym ( ATreadFromString ( "prod(id(\"Labels\"),w(\"\"),[ql(\"{\"),w(\"\"),sort(\"Labels\"),w(\"\"),ql(\"}\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"LabelSet\"),w(\"\"),no-attrs)" ) ) ;
ef4 = lookup_func ( ATreadFromString ( "prod(id(\"Labels\"),w(\"\"),[iter(sort(\"Label\"),w(\"\"),l(\"*\"))],w(\"\"),l(\"->\"),w(\"\"),sort(\"Labels\"),w(\"\"),no-attrs)" ) ) ;
ef4sym = lookup_sym ( ATreadFromString ( "prod(id(\"Labels\"),w(\"\"),[iter(sort(\"Label\"),w(\"\"),l(\"*\"))],w(\"\"),l(\"->\"),w(\"\"),sort(\"Labels\"),w(\"\"),no-attrs)" ) ) ;
ef5 = lookup_func ( ATreadFromString ( "prod(id(\"Earley-Graphs\"),w(\"\"),[sort(\"Symbol\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Label\"),w(\"\"),no-attrs)" ) ) ;
ef5sym = lookup_sym ( ATreadFromString ( "prod(id(\"Earley-Graphs\"),w(\"\"),[sort(\"Symbol\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Label\"),w(\"\"),no-attrs)" ) ) ;
ef6 = lookup_func ( ATreadFromString ( "prod(id(\"CC-Sdf-Syntax\"),w(\"\"),[sort(\"CharClass\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Symbol\"),w(\"\"),no-attrs)" ) ) ;
ef6sym = lookup_sym ( ATreadFromString ( "prod(id(\"CC-Sdf-Syntax\"),w(\"\"),[sort(\"CharClass\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Symbol\"),w(\"\"),no-attrs)" ) ) ;
ef7 = lookup_func ( ATreadFromString ( "prod(id(\"ATerm-Lists\"),w(\"\"),[sort(\"ATerm\"),w(\"\"),ql(\":\"),w(\"\"),sort(\"ATermList\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATermList\"),w(\"\"),no-attrs)" ) ) ;
ef7sym = lookup_sym ( ATreadFromString ( "prod(id(\"ATerm-Lists\"),w(\"\"),[sort(\"ATerm\"),w(\"\"),ql(\":\"),w(\"\"),sort(\"ATermList\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATermList\"),w(\"\"),no-attrs)" ) ) ;
ef8 = lookup_func ( ATreadFromString ( "prod(id(\"ATerms\"),w(\"\"),[sort(\"AFun\"),w(\"\"),ql(\"(\"),w(\"\"),sort(\"ATerms\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerm\"),w(\"\"),no-attrs)" ) ) ;
ef8sym = lookup_sym ( ATreadFromString ( "prod(id(\"ATerms\"),w(\"\"),[sort(\"AFun\"),w(\"\"),ql(\"(\"),w(\"\"),sort(\"ATerms\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerm\"),w(\"\"),no-attrs)" ) ) ;
ef9 = lookup_func ( ATreadFromString ( "prod(id(\"Parse-Table-Constructors\"),w(\"\"),[ql(\"action\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)" ) ) ;
ef9sym = lookup_sym ( ATreadFromString ( "prod(id(\"Parse-Table-Constructors\"),w(\"\"),[ql(\"action\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)" ) ) ;
ef10 = lookup_func ( ATreadFromString ( "prod(id(\"ATerms\"),w(\"\"),[sort(\"ATerm\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"ATerms\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerms\"),w(\"\"),no-attrs)" ) ) ;
ef10sym = lookup_sym ( ATreadFromString ( "prod(id(\"ATerms\"),w(\"\"),[sort(\"ATerm\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"ATerms\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerms\"),w(\"\"),no-attrs)" ) ) ;
ef11 = lookup_func ( ATreadFromString ( "prod(id(\"Symbols-ATerms\"),w(\"\"),[l(\"aterm\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Symbol\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerm\"),w(\"\"),no-attrs)" ) ) ;
ef11sym = lookup_sym ( ATreadFromString ( "prod(id(\"Symbols-ATerms\"),w(\"\"),[l(\"aterm\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Symbol\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerm\"),w(\"\"),no-attrs)" ) ) ;
ef12 = lookup_func ( ATreadFromString ( "prod(id(\"ATerms\"),w(\"\"),[sort(\"ATerm\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerms\"),w(\"\"),no-attrs)" ) ) ;
ef12sym = lookup_sym ( ATreadFromString ( "prod(id(\"ATerms\"),w(\"\"),[sort(\"ATerm\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerms\"),w(\"\"),no-attrs)" ) ) ;
ef13 = lookup_func ( ATreadFromString ( "prod(id(\"ATerms\"),w(\"\"),[sort(\"ATermList\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerm\"),w(\"\"),no-attrs)" ) ) ;
ef13sym = lookup_sym ( ATreadFromString ( "prod(id(\"ATerms\"),w(\"\"),[sort(\"ATermList\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerm\"),w(\"\"),no-attrs)" ) ) ;
ef14 = lookup_func ( ATreadFromString ( "prod(id(\"Table-To-ATerm\"),w(\"\"),[l(\"aterm\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"ActionSet\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATermList\"),w(\"\"),no-attrs)" ) ) ;
ef14sym = lookup_sym ( ATreadFromString ( "prod(id(\"Table-To-ATerm\"),w(\"\"),[l(\"aterm\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"ActionSet\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATermList\"),w(\"\"),no-attrs)" ) ) ;
ef15 = lookup_func ( ATreadFromString ( "prod(id(\"ATerms\"),w(\"\"),[ql(\"[\"),w(\"\"),ql(\"]\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATermList\"),w(\"\"),no-attrs)" ) ) ;
ef15sym = lookup_sym ( ATreadFromString ( "prod(id(\"ATerms\"),w(\"\"),[ql(\"[\"),w(\"\"),ql(\"]\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATermList\"),w(\"\"),no-attrs)" ) ) ;
}
static ATerm constant0 = NULL ;
static ATerm constant1 = NULL ;
void init_AUX_Table_To_ATerm7 ( ) {
ATprotect ( & constant0 ) ;
ATprotect ( & constant1 ) ;
}
ATerm lf_AUX_Table_To_ATerm7_1 ( ATerm arg0 ) {
{
ATerm tmp [ 10 ] ;
FUNC_ENTRY ( lf_AUX_Table_To_ATerm7_1sym , ATmakeAppl ( lf_AUX_Table_To_ATerm7_1sym , arg0 ) ) ;
if ( check_sym ( arg0 , ef1sym ) ) {
{
ATerm atmp00 = arg_0 ( arg0 ) ;
if ( check_sym ( atmp00 , lf2sym ) ) {
{
ATerm atmp000 = arg_0 ( atmp00 ) ;
if ( not_empty_list ( atmp000 ) ) {
tmp [ 0 ] = list_head ( atmp000 ) ;
tmp [ 1 ] = list_tail ( atmp000 ) ;
if ( check_sym ( tmp [ 0 ] , ef2sym ) ) {
tmp [ 2 ] = arg_0 ( tmp [ 0 ] ) ;
tmp [ 3 ] = arg_1 ( tmp [ 0 ] ) ;
if ( check_sym ( tmp [ 2 ] , ef3sym ) ) {
tmp [ 4 ] = arg_0 ( tmp [ 2 ] ) ;
if ( check_sym ( tmp [ 4 ] , ef4sym ) ) {
tmp [ 5 ] = arg_0 ( tmp [ 4 ] ) ;
if ( check_sym ( tmp [ 5 ] , lf3sym ) ) {
tmp [ 6 ] = arg_0 ( tmp [ 5 ] ) ;
if ( is_single_element ( tmp [ 6 ] ) ) {
tmp [ 7 ] = list_head ( tmp [ 6 ] ) ;
if ( check_sym ( tmp [ 7 ] , ef5sym ) ) {
tmp [ 8 ] = arg_0 ( tmp [ 7 ] ) ;
if ( check_sym ( tmp [ 8 ] , ef6sym ) ) {
tmp [ 9 ] = arg_0 ( tmp [ 8 ] ) ;
FUNC_EXIT ( ( * ef7 ) ( ( * ef8 ) ( ( * ef9 ) ( ) , ( * ef10 ) ( ( * ef11 ) ( ( * ef6 ) ( tmp [ 9 ] ) ) , ( * ef12 ) ( ( * ef13 ) ( ( * ef14 ) ( tmp [ 3 ] ) ) ) ) ) , lf_AUX_Table_To_ATerm7_1 ( ( * ef1 ) ( lf2 ( make_list ( tmp [ 1 ] ) ) ) ) ) ) ;
}
}
}
}
}
}
}
}
if ( term_equal ( ( * ef1 ) ( lf2 ( make_list ( atmp000 ) ) ) , ( constant0 ? constant0 : ( constant0 = ( * ef1 ) ( lf2 ( make_list ( null ( ) ) ) ) ) ) ) ) {
FUNC_EXIT_CONST ( constant1 , ( * ef15 ) ( ) ) ;
}
}
}
}
}
FUNC_EXIT ( make_nf1 ( lf_AUX_Table_To_ATerm7_1sym , arg0 ) ) ;
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

