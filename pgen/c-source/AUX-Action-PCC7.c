#include  "support.h"
static Symbol lf_AUX_Action_PCC7_1sym ;
static ATerm lf_AUX_Action_PCC7_1 ( ATerm arg1 ) ;
static Symbol ef3sym ;
static funcptr ef3 ;
static Symbol ef8sym ;
static funcptr ef8 ;
static Symbol ef19sym ;
static funcptr ef19 ;
static Symbol ef20sym ;
static funcptr ef20 ;
static Symbol ef6sym ;
static funcptr ef6 ;
static Symbol ef7sym ;
static funcptr ef7 ;
static Symbol ef21sym ;
static funcptr ef21 ;
static Symbol ef9sym ;
static funcptr ef9 ;
static Symbol lf3sym ;
static ATerm lf3 ( ATerm arg1 ) ;
static Symbol ef10sym ;
static funcptr ef10 ;
static Symbol ef22sym ;
static funcptr ef22 ;
static Symbol ef5sym ;
static funcptr ef5 ;
static Symbol ef23sym ;
static funcptr ef23 ;
static Symbol ef12sym ;
static funcptr ef12 ;
static Symbol ef13sym ;
static funcptr ef13 ;
static Symbol ef14sym ;
static funcptr ef14 ;
static Symbol lf4sym ;
static ATerm lf4 ( ATerm arg1 ) ;
static Symbol ef15sym ;
static funcptr ef15 ;
static Symbol ef16sym ;
static funcptr ef16 ;
static Symbol ef17sym ;
static funcptr ef17 ;
static Symbol ef18sym ;
static funcptr ef18 ;
static Symbol lf5sym ;
static ATerm lf5 ( ATerm arg1 ) ;
static Symbol ef24sym ;
static funcptr ef24 ;
static Symbol ef4sym ;
static funcptr ef4 ;
static Symbol ef11sym ;
static funcptr ef11 ;
static Symbol ef1sym ;
static funcptr ef1 ;
static Symbol ef2sym ;
static funcptr ef2 ;
static Symbol lf2sym ;
static ATerm lf2 ( ATerm arg1 ) ;
void register_AUX_Action_PCC7 ( ) {
lf_AUX_Action_PCC7_1sym = ATmakeSymbol ( "prod(id(\"Action-PCC\"),w(\"\"),[l(\"nm-shifts\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Goto-Table\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Action-Table\"),w(\"\"),no-attrs)"
 , 1 , ATtrue ) ;
ATprotectSymbol ( lf_AUX_Action_PCC7_1sym ) ;
lf3sym = ATmakeSymbol ( "listtype(sort(\"CHAR\"))" , 1 , ATtrue ) ;
ATprotectSymbol ( lf3sym ) ;
lf4sym = ATmakeSymbol ( "listtype(sort(\"Label\"))" , 1 , ATtrue ) ;
ATprotectSymbol ( lf4sym ) ;
lf5sym = ATmakeSymbol ( "listtype(sort(\"Action\"))" , 1 , ATtrue ) ;
ATprotectSymbol ( lf5sym ) ;
lf2sym = ATmakeSymbol ( "listtype(sort(\"Goto-Entry\"),ql(\",\"))" , 1 , ATtrue ) ;
ATprotectSymbol ( lf2sym ) ;
register_prod ( ATparse ( "prod(id(\"Action-PCC\"),w(\"\"),[l(\"nm-shifts\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Goto-Table\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Action-Table\"),w(\"\"),no-attrs)" ) , lf_AUX_Action_PCC7_1 , lf_AUX_Action_PCC7_1sym ) ;
register_prod ( ATparse ( "listtype(sort(\"Goto-Entry\"),ql(\",\"))" ) , lf2 , lf2sym ) ;
register_prod ( ATparse ( "listtype(sort(\"CHAR\"))" ) , lf3 , lf3sym ) ;
register_prod ( ATparse ( "listtype(sort(\"Label\"))" ) , lf4 , lf4sym ) ;
register_prod ( ATparse ( "listtype(sort(\"Action\"))" ) , lf5 , lf5sym ) ;
}
void resolve_AUX_Action_PCC7 ( ) {
ef1 = lookup_func ( ATreadFromString ( "prod(id(\"Parse-Table\"),w(\"\"),[l(\"gotos\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Goto-Entries\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Goto-Table\"),w(\"\"),no-attrs)" ) ) ;
ef1sym = lookup_sym ( ATreadFromString ( "prod(id(\"Parse-Table\"),w(\"\"),[l(\"gotos\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Goto-Entries\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Goto-Table\"),w(\"\"),no-attrs)" ) ) ;
ef2 = lookup_func ( ATreadFromString ( "prod(id(\"Parse-Table\"),w(\"\"),[ql(\"[\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Goto-Entry\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\"]\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Goto-Entries\"),w(\"\"),no-attrs)" ) ) ;
ef2sym = lookup_sym ( ATreadFromString ( "prod(id(\"Parse-Table\"),w(\"\"),[ql(\"[\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Goto-Entry\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\"]\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Goto-Entries\"),w(\"\"),no-attrs)" ) ) ;
ef3 = lookup_func ( ATreadFromString ( "prod(id(\"Parse-Table\"),w(\"\"),[l(\"new-action-table\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Action-Table\"),w(\"\"),no-attrs)" ) ) ;
ef3sym = lookup_sym ( ATreadFromString ( "prod(id(\"Parse-Table\"),w(\"\"),[l(\"new-action-table\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Action-Table\"),w(\"\"),no-attrs)" ) ) ;
ef4 = lookup_func ( ATreadFromString ( "prod(id(\"Parse-Table\"),w(\"\"),[l(\"goto\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"CharClass\"),w(\"\"),l(\",\"),w(\"\"),sort(\"Int\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Goto-Entry\"),w(\"\"),no-attrs)" ) ) ;
ef4sym = lookup_sym ( ATreadFromString ( "prod(id(\"Parse-Table\"),w(\"\"),[l(\"goto\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"CharClass\"),w(\"\"),l(\",\"),w(\"\"),sort(\"Int\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Goto-Entry\"),w(\"\"),no-attrs)" ) ) ;
ef5 = lookup_func ( ATreadFromString ( "prod(id(\"Character-Class-Syntax\"),w(\"\"),[ql(\"[\"),w(\"\"),sort(\"OptCharRanges\"),w(\"\"),ql(\"]\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"CharClass\"),w(\"\"),no-attrs)" ) ) ;
ef5sym = lookup_sym ( ATreadFromString ( "prod(id(\"Character-Class-Syntax\"),w(\"\"),[ql(\"[\"),w(\"\"),sort(\"OptCharRanges\"),w(\"\"),ql(\"]\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"CharClass\"),w(\"\"),no-attrs)" ) ) ;
ef6 = lookup_func ( ATreadFromString ( "prod(id(\"Character-Class-Syntax\"),w(\"\"),[sort(\"CharRanges\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"OptCharRanges\"),w(\"\"),no-attrs)" ) ) ;
ef6sym = lookup_sym ( ATreadFromString ( "prod(id(\"Character-Class-Syntax\"),w(\"\"),[sort(\"CharRanges\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"OptCharRanges\"),w(\"\"),no-attrs)" ) ) ;
ef7 = lookup_func ( ATreadFromString ( "prod(id(\"Character-Class-Syntax\"),w(\"\"),[sort(\"CharRange\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"CharRanges\"),w(\"\"),no-attrs)" ) ) ;
ef7sym = lookup_sym ( ATreadFromString ( "prod(id(\"Character-Class-Syntax\"),w(\"\"),[sort(\"CharRange\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"CharRanges\"),w(\"\"),no-attrs)" ) ) ;
ef8 = lookup_func ( ATreadFromString ( "prod(id(\"Character-Class-Syntax\"),w(\"\"),[sort(\"Character\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"CharRange\"),w(\"\"),no-attrs)" ) ) ;
ef8sym = lookup_sym ( ATreadFromString ( "prod(id(\"Character-Class-Syntax\"),w(\"\"),[sort(\"Character\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"CharRange\"),w(\"\"),no-attrs)" ) ) ;
ef9 = lookup_func ( ATreadFromString ( "prod(id(\"Character-Syntax\"),w(\"\"),[sort(\"NumChar\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Character\"),w(\"\"),no-attrs)" ) ) ;
ef9sym = lookup_sym ( ATreadFromString ( "prod(id(\"Character-Syntax\"),w(\"\"),[sort(\"NumChar\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Character\"),w(\"\"),no-attrs)" ) ) ;
ef10 = lookup_func ( ATreadFromString ( "prod(id(\"caller\"),w(\"\"),[l(\"numchar\"),w(\"\"),ql(\"(\"),w(\"\"),iter(sort(\"CHAR\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"NumChar\"),w(\"\"),no-attrs)" ) ) ;
ef10sym = lookup_sym ( ATreadFromString ( "prod(id(\"caller\"),w(\"\"),[l(\"numchar\"),w(\"\"),ql(\"(\"),w(\"\"),iter(sort(\"CHAR\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"NumChar\"),w(\"\"),no-attrs)" ) ) ;
ef11 = lookup_func ( ATreadFromString ( "prod(id(\"Basic-Integers\"),w(\"\"),[sort(\"IntCon\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Int\"),w(\"\"),no-attrs)" ) ) ;
ef11sym = lookup_sym ( ATreadFromString ( "prod(id(\"Basic-Integers\"),w(\"\"),[sort(\"IntCon\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Int\"),w(\"\"),no-attrs)" ) ) ;
ef12 = lookup_func ( ATreadFromString ( "prod(id(\"Parse-Table\"),w(\"\"),[sort(\"Action-Table\"),w(\"\"),ql(\"[\"),w(\"\"),sort(\"LabelSet\"),w(\"\"),ql(\":=\"),w(\"\"),sort(\"ActionSet\"),w(\"\"),ql(\"]\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Action-Table\"),w(\"\"),attrs(l(\"{\"),w(\"\"),[l(\"memo\")],w(\"\"),l(\"}\")))" ) ) ;
ef12sym = lookup_sym ( ATreadFromString ( "prod(id(\"Parse-Table\"),w(\"\"),[sort(\"Action-Table\"),w(\"\"),ql(\"[\"),w(\"\"),sort(\"LabelSet\"),w(\"\"),ql(\":=\"),w(\"\"),sort(\"ActionSet\"),w(\"\"),ql(\"]\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Action-Table\"),w(\"\"),attrs(l(\"{\"),w(\"\"),[l(\"memo\")],w(\"\"),l(\"}\")))" ) ) ;
ef13 = lookup_func ( ATreadFromString ( "prod(id(\"Labels\"),w(\"\"),[ql(\"{\"),w(\"\"),sort(\"Labels\"),w(\"\"),ql(\"}\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"LabelSet\"),w(\"\"),no-attrs)" ) ) ;
ef13sym = lookup_sym ( ATreadFromString ( "prod(id(\"Labels\"),w(\"\"),[ql(\"{\"),w(\"\"),sort(\"Labels\"),w(\"\"),ql(\"}\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"LabelSet\"),w(\"\"),no-attrs)" ) ) ;
ef14 = lookup_func ( ATreadFromString ( "prod(id(\"Labels\"),w(\"\"),[iter(sort(\"Label\"),w(\"\"),l(\"*\"))],w(\"\"),l(\"->\"),w(\"\"),sort(\"Labels\"),w(\"\"),no-attrs)" ) ) ;
ef14sym = lookup_sym ( ATreadFromString ( "prod(id(\"Labels\"),w(\"\"),[iter(sort(\"Label\"),w(\"\"),l(\"*\"))],w(\"\"),l(\"->\"),w(\"\"),sort(\"Labels\"),w(\"\"),no-attrs)" ) ) ;
ef15 = lookup_func ( ATreadFromString ( "prod(id(\"Earley-Graphs\"),w(\"\"),[sort(\"Symbol\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Label\"),w(\"\"),no-attrs)" ) ) ;
ef15sym = lookup_sym ( ATreadFromString ( "prod(id(\"Earley-Graphs\"),w(\"\"),[sort(\"Symbol\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Label\"),w(\"\"),no-attrs)" ) ) ;
ef16 = lookup_func ( ATreadFromString ( "prod(id(\"CC-Sdf-Syntax\"),w(\"\"),[sort(\"CharClass\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Symbol\"),w(\"\"),no-attrs)" ) ) ;
ef16sym = lookup_sym ( ATreadFromString ( "prod(id(\"CC-Sdf-Syntax\"),w(\"\"),[sort(\"CharClass\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Symbol\"),w(\"\"),no-attrs)" ) ) ;
ef17 = lookup_func ( ATreadFromString ( "prod(id(\"Actions\"),w(\"\"),[ql(\"{\"),w(\"\"),sort(\"Actions\"),w(\"\"),ql(\"}\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ActionSet\"),w(\"\"),no-attrs)" ) ) ;
ef17sym = lookup_sym ( ATreadFromString ( "prod(id(\"Actions\"),w(\"\"),[ql(\"{\"),w(\"\"),sort(\"Actions\"),w(\"\"),ql(\"}\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ActionSet\"),w(\"\"),no-attrs)" ) ) ;
ef18 = lookup_func ( ATreadFromString ( "prod(id(\"Actions\"),w(\"\"),[iter(sort(\"Action\"),w(\"\"),l(\"*\"))],w(\"\"),l(\"->\"),w(\"\"),sort(\"Actions\"),w(\"\"),no-attrs)" ) ) ;
ef18sym = lookup_sym ( ATreadFromString ( "prod(id(\"Actions\"),w(\"\"),[iter(sort(\"Action\"),w(\"\"),l(\"*\"))],w(\"\"),l(\"->\"),w(\"\"),sort(\"Actions\"),w(\"\"),no-attrs)" ) ) ;
ef19 = lookup_func ( ATreadFromString ( "prod(id(\"Actions\"),w(\"\"),[l(\"accept\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Action\"),w(\"\"),no-attrs)" ) ) ;
ef19sym = lookup_sym ( ATreadFromString ( "prod(id(\"Actions\"),w(\"\"),[l(\"accept\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Action\"),w(\"\"),no-attrs)" ) ) ;
ef20 = lookup_func ( ATreadFromString ( "prod(id(\"Character-Class-Syntax\"),w(\"\"),[sort(\"CharClass\"),w(\"\"),ql(\"/\\\\\\\\\"),w(\"\"),sort(\"CharClass\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"CharClass\"),w(\"\"),attrs(l(\"{\"),w(\"\"),[l(\"left\"),w(\"\"),sep(\",\"),w(\"\"),l(\"memo\")],w(\"\"),l(\"}\")))" ) ) ;
ef20sym = lookup_sym ( ATreadFromString ( "prod(id(\"Character-Class-Syntax\"),w(\"\"),[sort(\"CharClass\"),w(\"\"),ql(\"/\\\\\\\\\"),w(\"\"),sort(\"CharClass\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"CharClass\"),w(\"\"),attrs(l(\"{\"),w(\"\"),[l(\"left\"),w(\"\"),sep(\",\"),w(\"\"),l(\"memo\")],w(\"\"),l(\"}\")))" ) ) ;
ef21 = lookup_func ( ATreadFromString ( "prod(id(\"Character-Class-Syntax\"),w(\"\"),[sort(\"Character\"),w(\"\"),ql(\"-\"),w(\"\"),sort(\"Character\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"CharRange\"),w(\"\"),no-attrs)" ) ) ;
ef21sym = lookup_sym ( ATreadFromString ( "prod(id(\"Character-Class-Syntax\"),w(\"\"),[sort(\"Character\"),w(\"\"),ql(\"-\"),w(\"\"),sort(\"Character\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"CharRange\"),w(\"\"),no-attrs)" ) ) ;
ef22 = lookup_func ( ATreadFromString ( "prod(id(\"Character-Syntax\"),w(\"\"),[ql(\"\\\\\\\\TOP\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Character\"),w(\"\"),no-attrs)" ) ) ;
ef22sym = lookup_sym ( ATreadFromString ( "prod(id(\"Character-Syntax\"),w(\"\"),[ql(\"\\\\\\\\TOP\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Character\"),w(\"\"),no-attrs)" ) ) ;
ef23 = lookup_func ( ATreadFromString ( "prod(id(\"Character-Class-Syntax\"),w(\"\"),[],w(\"\"),l(\"->\"),w(\"\"),sort(\"OptCharRanges\"),w(\"\"),no-attrs)" ) ) ;
ef23sym = lookup_sym ( ATreadFromString ( "prod(id(\"Character-Class-Syntax\"),w(\"\"),[],w(\"\"),l(\"->\"),w(\"\"),sort(\"OptCharRanges\"),w(\"\"),no-attrs)" ) ) ;
ef24 = lookup_func ( ATreadFromString ( "prod(id(\"Actions\"),w(\"\"),[l(\"shift\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Int\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Action\"),w(\"\"),no-attrs)" ) ) ;
ef24sym = lookup_sym ( ATreadFromString ( "prod(id(\"Actions\"),w(\"\"),[l(\"shift\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Int\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Action\"),w(\"\"),no-attrs)" ) ) ;
}
static ATerm constant0 = NULL ;
static ATerm constant1 = NULL ;
static ATerm constant2 = NULL ;
static ATerm constant3 = NULL ;
void init_AUX_Action_PCC7 ( ) {
ATprotect ( & constant0 ) ;
ATprotect ( & constant1 ) ;
ATprotect ( & constant2 ) ;
ATprotect ( & constant3 ) ;
}
ATerm lf_AUX_Action_PCC7_1 ( ATerm arg0 ) {
{
ATerm tmp [ 15 ] ;
FUNC_ENTRY ( lf_AUX_Action_PCC7_1sym , ATmakeAppl ( lf_AUX_Action_PCC7_1sym , arg0 ) ) ;
if ( check_sym ( arg0 , ef1sym ) ) {
{
ATerm atmp00 = arg_0 ( arg0 ) ;
if ( check_sym ( atmp00 , ef2sym ) ) {
{
ATerm atmp000 = arg_0 ( atmp00 ) ;
if ( check_sym ( atmp000 , lf2sym ) ) {
{
ATerm atmp0000 = arg_0 ( atmp000 ) ;
if ( not_empty_list ( atmp0000 ) ) {
tmp [ 0 ] = list_head ( atmp0000 ) ;
{
tmp [ 1 ] = list_tail ( atmp0000 ) ;
{
if ( check_sym ( tmp [ 0 ] , ef4sym ) ) {
tmp [ 2 ] = arg_0 ( tmp [ 0 ] ) ;
tmp [ 3 ] = arg_1 ( tmp [ 0 ] ) ;
{
if ( check_sym ( tmp [ 3 ] , ef11sym ) ) {
tmp [ 4 ] = arg_0 ( tmp [ 3 ] ) ;
tmp [ 5 ] = ( * ef20 ) ( ( constant0 ? constant0 : ( constant0 = ( * ef5 ) ( ( * ef6 ) ( ( * ef7 ) ( ( * ef21 ) ( ( * ef9 ) ( ( * ef10 ) ( lf3 ( cons ( make_list ( make_char ( 92 ) ) , make_list ( make_char ( 49 ) ) ) ) ) ) , ( * ef22 ) ( ) ) ) ) ) ) ) , tmp [ 2 ] ) ;
if ( ! term_equal ( tmp [ 5 ] , ( * ef5 ) ( ( * ef23 ) ( ) ) ) ) {
tmp [ 6 ] = lf_AUX_Action_PCC7_1 ( ( * ef1 ) ( ( * ef2 ) ( lf2 ( make_list ( tmp [ 1 ] ) ) ) ) ) ;
tmp [ 7 ] = ( * ef12 ) ( tmp [ 6 ] , ( * ef13 ) ( ( * ef14 ) ( lf4 ( make_list ( ( * ef15 ) ( ( * ef16 ) ( tmp [ 5 ] ) ) ) ) ) ) , ( * ef17 ) ( ( * ef18 ) ( lf5 ( make_list ( ( * ef24 ) ( ( * ef11 ) ( tmp [ 4 ] ) ) ) ) ) ) ) ;
tmp [ 6 ] = NULL;
FUNC_EXIT ( tmp [ 7 ] ) ;
}
}
if ( check_sym ( tmp [ 2 ] , ef5sym ) ) {
tmp [ 4 ] = arg_0 ( tmp [ 2 ] ) ;
if ( check_sym ( tmp [ 4 ] , ef6sym ) ) {
tmp [ 5 ] = arg_0 ( tmp [ 4 ] ) ;
if ( check_sym ( tmp [ 5 ] , ef7sym ) ) {
tmp [ 6 ] = arg_0 ( tmp [ 5 ] ) ;
if ( check_sym ( tmp [ 6 ] , ef8sym ) ) {
tmp [ 7 ] = arg_0 ( tmp [ 6 ] ) ;
if ( check_sym ( tmp [ 7 ] , ef9sym ) ) {
tmp [ 8 ] = arg_0 ( tmp [ 7 ] ) ;
if ( check_sym ( tmp [ 8 ] , ef10sym ) ) {
tmp [ 9 ] = arg_0 ( tmp [ 8 ] ) ;
if ( check_sym ( tmp [ 9 ] , lf3sym ) ) {
tmp [ 10 ] = arg_0 ( tmp [ 9 ] ) ;
if ( check_sym ( tmp [ 3 ] , ef11sym ) ) {
tmp [ 11 ] = arg_0 ( tmp [ 3 ] ) ;
if ( not_empty_list ( tmp [ 10 ] ) ) {
if ( term_equal ( list_head ( tmp [ 10 ] ) , make_char ( 92 ) ) ) {
tmp [ 12 ] = list_tail ( tmp [ 10 ] ) ;
if ( is_single_element ( tmp [ 12 ] ) ) {
if ( term_equal ( list_head ( tmp [ 12 ] ) , make_char ( 48 ) ) ) {
tmp [ 13 ] = lf_AUX_Action_PCC7_1 ( ( * ef1 ) ( ( * ef2 ) ( lf2 ( make_list ( tmp [ 1 ] ) ) ) ) ) ;
tmp [ 14 ] = ( * ef12 ) ( tmp [ 13 ] , ( constant1 ? constant1 : ( constant1 = ( * ef13 ) ( ( * ef14 ) ( lf4 ( make_list ( ( * ef15 ) ( ( * ef16 ) ( ( * ef5 ) ( ( * ef6 ) ( ( * ef7 ) ( ( * ef8 ) ( ( * ef9 ) ( ( * ef10 ) ( lf3 ( cons ( make_list ( make_char ( 92 ) ) , make_list ( make_char ( 48 ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) , ( constant2 ? constant2 : ( constant2 = ( * ef17 ) ( ( * ef18 ) ( lf5 ( make_list ( ( * ef19 ) ( ) ) ) ) ) ) ) ) ;
tmp [ 13 ] = NULL;
FUNC_EXIT ( tmp [ 14 ] ) ;
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
else {
FUNC_EXIT_CONST ( constant3 , ( * ef3 ) ( ) ) ;
}
}
}
}
}
}
}
if ( check_sym ( arg0 , ef1sym ) ) {
{
ATerm atmp00 = arg_0 ( arg0 ) ;
if ( check_sym ( atmp00 , ef2sym ) ) {
{
ATerm atmp000 = arg_0 ( atmp00 ) ;
if ( check_sym ( atmp000 , lf2sym ) ) {
{
ATerm atmp0000 = arg_0 ( atmp000 ) ;
if ( not_empty_list ( atmp0000 ) ) {
tmp [ 0 ] = list_head ( atmp0000 ) ;
tmp [ 1 ] = list_tail ( atmp0000 ) ;
if ( check_sym ( tmp [ 0 ] , ef4sym ) ) {
tmp [ 2 ] = arg_0 ( tmp [ 0 ] ) ;
tmp [ 3 ] = arg_1 ( tmp [ 0 ] ) ;
if ( check_sym ( tmp [ 3 ] , ef11sym ) ) {
tmp [ 4 ] = arg_0 ( tmp [ 3 ] ) ;
FUNC_EXIT ( lf_AUX_Action_PCC7_1 ( ( * ef1 ) ( ( * ef2 ) ( lf2 ( make_list ( tmp [ 1 ] ) ) ) ) ) ) ;
}
}
}
}
}
}
}
}
}
FUNC_EXIT ( make_nf1 ( lf_AUX_Action_PCC7_1sym , arg0 ) ) ;
}
}
ATerm lf2 ( ATerm arg0 ) {
CONS_ENTRY ( lf2sym , ATmakeAppl ( lf2sym , arg0 ) ) ;
CONS_EXIT ( make_nf1 ( lf2sym , arg0 ) ) ;
}
ATerm lf5 ( ATerm arg0 ) {
CONS_ENTRY ( lf5sym , ATmakeAppl ( lf5sym , arg0 ) ) ;
CONS_EXIT ( make_nf1 ( lf5sym , arg0 ) ) ;
}
ATerm lf4 ( ATerm arg0 ) {
CONS_ENTRY ( lf4sym , ATmakeAppl ( lf4sym , arg0 ) ) ;
CONS_EXIT ( make_nf1 ( lf4sym , arg0 ) ) ;
}
ATerm lf3 ( ATerm arg0 ) {
CONS_ENTRY ( lf3sym , ATmakeAppl ( lf3sym , arg0 ) ) ;
CONS_EXIT ( make_nf1 ( lf3sym , arg0 ) ) ;
}

