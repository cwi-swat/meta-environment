#include  "asc-support.h"
static Symbol lf_AUX_Parse_Table35_1sym ;
static ATerm lf_AUX_Parse_Table35_1 ( ATerm arg1 , ATerm arg2 , ATerm arg3 ) ;
static Symbol ef11sym ;
static funcptr ef11 ;
static Symbol ef15sym ;
static funcptr ef15 ;
static Symbol ef16sym ;
static funcptr ef16 ;
static Symbol ef12sym ;
static funcptr ef12 ;
static Symbol ef13sym ;
static funcptr ef13 ;
static Symbol ef14sym ;
static funcptr ef14 ;
static Symbol ef1sym ;
static funcptr ef1 ;
static Symbol ef2sym ;
static funcptr ef2 ;
static Symbol lf2sym ;
static ATerm lf2 ( ATerm arg1 ) ;
static Symbol ef9sym ;
static funcptr ef9 ;
static Symbol ef10sym ;
static funcptr ef10 ;
static Symbol ef3sym ;
static funcptr ef3 ;
static Symbol ef4sym ;
static funcptr ef4 ;
static Symbol lf3sym ;
static ATerm lf3 ( ATerm arg1 ) ;
static Symbol ef5sym ;
static funcptr ef5 ;
static Symbol ef6sym ;
static funcptr ef6 ;
static Symbol ef7sym ;
static funcptr ef7 ;
static Symbol ef8sym ;
static funcptr ef8 ;
static Symbol lf4sym ;
static ATerm lf4 ( ATerm arg1 ) ;
void register_AUX_Parse_Table35 ( ) {
lf_AUX_Parse_Table35_1sym = ATmakeSymbol ( "prod(id(\"Parse-Table\"),w(\"\"),[sort(\"Action-Table\"),w(\"\"),ql(\"[\"),w(\"\"),sort(\"LabelSet\"),w(\"\"),ql(\":=\"),w(\"\"),sort(\"ActionSet\"),w(\"\"),ql(\"]\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Action-Table\"),w(\"\"),no-attrs)"
 , 3 , ATtrue ) ;
ATprotectSymbol ( lf_AUX_Parse_Table35_1sym ) ;
lf2sym = ATmakeSymbol ( "listtype(sort(\"Action-Entry\"),ql(\",\"))" , 1 , ATtrue ) ;
ATprotectSymbol ( lf2sym ) ;
lf3sym = ATmakeSymbol ( "listtype(sort(\"Label\"))" , 1 , ATtrue ) ;
ATprotectSymbol ( lf3sym ) ;
lf4sym = ATmakeSymbol ( "listtype(sort(\"Action\"))" , 1 , ATtrue ) ;
ATprotectSymbol ( lf4sym ) ;
register_prod ( ATparse ( "prod(id(\"Parse-Table\"),w(\"\"),[sort(\"Action-Table\"),w(\"\"),ql(\"[\"),w(\"\"),sort(\"LabelSet\"),w(\"\"),ql(\":=\"),w(\"\"),sort(\"ActionSet\"),w(\"\"),ql(\"]\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Action-Table\"),w(\"\"),no-attrs)" ) , lf_AUX_Parse_Table35_1 , lf_AUX_Parse_Table35_1sym ) ;
register_prod ( ATparse ( "listtype(sort(\"Action-Entry\"),ql(\",\"))" ) , lf2 , lf2sym ) ;
register_prod ( ATparse ( "listtype(sort(\"Label\"))" ) , lf3 , lf3sym ) ;
register_prod ( ATparse ( "listtype(sort(\"Action\"))" ) , lf4 , lf4sym ) ;
}
void resolve_AUX_Parse_Table35 ( ) {
ef1 = lookup_func ( ATreadFromString ( "prod(id(\"Parse-Table\"),w(\"\"),[l(\"actions\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Action-Entries\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Action-Table\"),w(\"\"),no-attrs)" ) ) ;
ef1sym = lookup_sym ( ATreadFromString ( "prod(id(\"Parse-Table\"),w(\"\"),[l(\"actions\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Action-Entries\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Action-Table\"),w(\"\"),no-attrs)" ) ) ;
ef2 = lookup_func ( ATreadFromString ( "prod(id(\"Parse-Table\"),w(\"\"),[ql(\"[\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Action-Entry\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\"]\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Action-Entries\"),w(\"\"),no-attrs)" ) ) ;
ef2sym = lookup_sym ( ATreadFromString ( "prod(id(\"Parse-Table\"),w(\"\"),[ql(\"[\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Action-Entry\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\"]\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Action-Entries\"),w(\"\"),no-attrs)" ) ) ;
ef3 = lookup_func ( ATreadFromString ( "prod(id(\"Labels\"),w(\"\"),[ql(\"{\"),w(\"\"),sort(\"Labels\"),w(\"\"),ql(\"}\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"LabelSet\"),w(\"\"),no-attrs)" ) ) ;
ef3sym = lookup_sym ( ATreadFromString ( "prod(id(\"Labels\"),w(\"\"),[ql(\"{\"),w(\"\"),sort(\"Labels\"),w(\"\"),ql(\"}\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"LabelSet\"),w(\"\"),no-attrs)" ) ) ;
ef4 = lookup_func ( ATreadFromString ( "prod(id(\"Labels\"),w(\"\"),[iter(sort(\"Label\"),w(\"\"),l(\"*\"))],w(\"\"),l(\"->\"),w(\"\"),sort(\"Labels\"),w(\"\"),no-attrs)" ) ) ;
ef4sym = lookup_sym ( ATreadFromString ( "prod(id(\"Labels\"),w(\"\"),[iter(sort(\"Label\"),w(\"\"),l(\"*\"))],w(\"\"),l(\"->\"),w(\"\"),sort(\"Labels\"),w(\"\"),no-attrs)" ) ) ;
ef5 = lookup_func ( ATreadFromString ( "prod(id(\"Earley-Graphs\"),w(\"\"),[sort(\"Symbol\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Label\"),w(\"\"),no-attrs)" ) ) ;
ef5sym = lookup_sym ( ATreadFromString ( "prod(id(\"Earley-Graphs\"),w(\"\"),[sort(\"Symbol\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Label\"),w(\"\"),no-attrs)" ) ) ;
ef6 = lookup_func ( ATreadFromString ( "prod(id(\"CC-Sdf-Syntax\"),w(\"\"),[sort(\"CharClass\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Symbol\"),w(\"\"),no-attrs)" ) ) ;
ef6sym = lookup_sym ( ATreadFromString ( "prod(id(\"CC-Sdf-Syntax\"),w(\"\"),[sort(\"CharClass\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Symbol\"),w(\"\"),no-attrs)" ) ) ;
ef7 = lookup_func ( ATreadFromString ( "prod(id(\"Actions\"),w(\"\"),[ql(\"{\"),w(\"\"),sort(\"Actions\"),w(\"\"),ql(\"}\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ActionSet\"),w(\"\"),no-attrs)" ) ) ;
ef7sym = lookup_sym ( ATreadFromString ( "prod(id(\"Actions\"),w(\"\"),[ql(\"{\"),w(\"\"),sort(\"Actions\"),w(\"\"),ql(\"}\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ActionSet\"),w(\"\"),no-attrs)" ) ) ;
ef8 = lookup_func ( ATreadFromString ( "prod(id(\"Actions\"),w(\"\"),[iter(sort(\"Action\"),w(\"\"),l(\"*\"))],w(\"\"),l(\"->\"),w(\"\"),sort(\"Actions\"),w(\"\"),no-attrs)" ) ) ;
ef8sym = lookup_sym ( ATreadFromString ( "prod(id(\"Actions\"),w(\"\"),[iter(sort(\"Action\"),w(\"\"),l(\"*\"))],w(\"\"),l(\"->\"),w(\"\"),sort(\"Actions\"),w(\"\"),no-attrs)" ) ) ;
ef9 = lookup_func ( ATreadFromString ( "prod(id(\"Action-PCC\"),w(\"\"),[l(\"add-action\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Action-Entry\"),w(\"\"),l(\",\"),w(\"\"),sort(\"Action-Table\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Action-Table\"),w(\"\"),no-attrs)" ) ) ;
ef9sym = lookup_sym ( ATreadFromString ( "prod(id(\"Action-PCC\"),w(\"\"),[l(\"add-action\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Action-Entry\"),w(\"\"),l(\",\"),w(\"\"),sort(\"Action-Table\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Action-Table\"),w(\"\"),no-attrs)" ) ) ;
ef10 = lookup_func ( ATreadFromString ( "prod(id(\"Parse-Table\"),w(\"\"),[l(\"action\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"LabelSet\"),w(\"\"),l(\",\"),w(\"\"),sort(\"ActionSet\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Action-Entry\"),w(\"\"),no-attrs)" ) ) ;
ef10sym = lookup_sym ( ATreadFromString ( "prod(id(\"Parse-Table\"),w(\"\"),[l(\"action\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"LabelSet\"),w(\"\"),l(\",\"),w(\"\"),sort(\"ActionSet\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Action-Entry\"),w(\"\"),no-attrs)" ) ) ;
ef11 = lookup_func ( ATreadFromString ( "prod(id(\"Parse-Table\"),w(\"\"),[l(\"new-action-table\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Action-Table\"),w(\"\"),no-attrs)" ) ) ;
ef11sym = lookup_sym ( ATreadFromString ( "prod(id(\"Parse-Table\"),w(\"\"),[l(\"new-action-table\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Action-Table\"),w(\"\"),no-attrs)" ) ) ;
ef12 = lookup_func ( ATreadFromString ( "prod(id(\"Character-Class-Syntax\"),w(\"\"),[sort(\"CharClass\"),w(\"\"),ql(\"/\\\\\\\\\"),w(\"\"),sort(\"CharClass\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"CharClass\"),w(\"\"),attrs(l(\"{\"),w(\"\"),[l(\"left\"),w(\"\"),sep(\",\"),w(\"\"),l(\"memo\")],w(\"\"),l(\"}\")))" ) ) ;
ef12sym = lookup_sym ( ATreadFromString ( "prod(id(\"Character-Class-Syntax\"),w(\"\"),[sort(\"CharClass\"),w(\"\"),ql(\"/\\\\\\\\\"),w(\"\"),sort(\"CharClass\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"CharClass\"),w(\"\"),attrs(l(\"{\"),w(\"\"),[l(\"left\"),w(\"\"),sep(\",\"),w(\"\"),l(\"memo\")],w(\"\"),l(\"}\")))" ) ) ;
ef13 = lookup_func ( ATreadFromString ( "prod(id(\"Character-Class-Syntax\"),w(\"\"),[ql(\"[\"),w(\"\"),sort(\"OptCharRanges\"),w(\"\"),ql(\"]\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"CharClass\"),w(\"\"),no-attrs)" ) ) ;
ef13sym = lookup_sym ( ATreadFromString ( "prod(id(\"Character-Class-Syntax\"),w(\"\"),[ql(\"[\"),w(\"\"),sort(\"OptCharRanges\"),w(\"\"),ql(\"]\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"CharClass\"),w(\"\"),no-attrs)" ) ) ;
ef14 = lookup_func ( ATreadFromString ( "prod(id(\"Character-Class-Syntax\"),w(\"\"),[],w(\"\"),l(\"->\"),w(\"\"),sort(\"OptCharRanges\"),w(\"\"),no-attrs)" ) ) ;
ef14sym = lookup_sym ( ATreadFromString ( "prod(id(\"Character-Class-Syntax\"),w(\"\"),[],w(\"\"),l(\"->\"),w(\"\"),sort(\"OptCharRanges\"),w(\"\"),no-attrs)" ) ) ;
ef15 = lookup_func ( ATreadFromString ( "prod(id(\"Character-Class-Syntax\"),w(\"\"),[sort(\"CharClass\"),w(\"\"),ql(\"/\"),w(\"\"),sort(\"CharClass\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"CharClass\"),w(\"\"),attrs(l(\"{\"),w(\"\"),[l(\"left\"),w(\"\"),sep(\",\"),w(\"\"),l(\"memo\")],w(\"\"),l(\"}\")))" ) ) ;
ef15sym = lookup_sym ( ATreadFromString ( "prod(id(\"Character-Class-Syntax\"),w(\"\"),[sort(\"CharClass\"),w(\"\"),ql(\"/\"),w(\"\"),sort(\"CharClass\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"CharClass\"),w(\"\"),attrs(l(\"{\"),w(\"\"),[l(\"left\"),w(\"\"),sep(\",\"),w(\"\"),l(\"memo\")],w(\"\"),l(\"}\")))" ) ) ;
ef16 = lookup_func ( ATreadFromString ( "prod(id(\"Actions\"),w(\"\"),[sort(\"ActionSet\"),w(\"\"),ql(\"||\"),w(\"\"),sort(\"ActionSet\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ActionSet\"),w(\"\"),attrs(l(\"{\"),w(\"\"),[l(\"assoc\")],w(\"\"),l(\"}\")))" ) ) ;
ef16sym = lookup_sym ( ATreadFromString ( "prod(id(\"Actions\"),w(\"\"),[sort(\"ActionSet\"),w(\"\"),ql(\"||\"),w(\"\"),sort(\"ActionSet\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ActionSet\"),w(\"\"),attrs(l(\"{\"),w(\"\"),[l(\"assoc\")],w(\"\"),l(\"}\")))" ) ) ;
}
static ATerm constant0 = NULL ;
void init_AUX_Parse_Table35 ( ) {
ATprotect ( & constant0 ) ;
}
ATerm lf_AUX_Parse_Table35_1 ( ATerm arg0 , ATerm arg1 , ATerm arg2 ) {
{
ATerm tmp [ 20 ] ;
FUNC_ENTRY ( lf_AUX_Parse_Table35_1sym , ATmakeAppl ( lf_AUX_Parse_Table35_1sym , arg0 , arg1 , arg2 ) ) ;
if ( check_sym ( arg0 , ef1sym ) ) {
{
ATerm atmp00 = arg_0 ( arg0 ) ;
if ( check_sym ( atmp00 , ef2sym ) ) {
{
ATerm atmp000 = arg_0 ( atmp00 ) ;
if ( check_sym ( atmp000 , lf2sym ) ) {
{
ATerm atmp0000 = arg_0 ( atmp000 ) ;
if ( check_sym ( arg1 , ef3sym ) ) {
{
ATerm atmp10 = arg_0 ( arg1 ) ;
if ( check_sym ( atmp10 , ef4sym ) ) {
{
ATerm atmp100 = arg_0 ( atmp10 ) ;
if ( check_sym ( atmp100 , lf3sym ) ) {
{
ATerm atmp1000 = arg_0 ( atmp100 ) ;
if ( check_sym ( arg2 , ef7sym ) ) {
{
ATerm atmp20 = arg_0 ( arg2 ) ;
if ( check_sym ( atmp20 , ef8sym ) ) {
{
ATerm atmp200 = arg_0 ( atmp20 ) ;
if ( check_sym ( atmp200 , lf4sym ) ) {
{
ATerm atmp2000 = arg_0 ( atmp200 ) ;
if ( not_empty_list ( atmp0000 ) ) {
tmp [ 0 ] = list_head ( atmp0000 ) ;
{
tmp [ 1 ] = list_tail ( atmp0000 ) ;
{
if ( is_single_element ( atmp1000 ) ) {
tmp [ 2 ] = list_head ( atmp1000 ) ;
{
if ( check_sym ( tmp [ 0 ] , ef10sym ) ) {
tmp [ 3 ] = arg_0 ( tmp [ 0 ] ) ;
tmp [ 4 ] = arg_1 ( tmp [ 0 ] ) ;
{
if ( check_sym ( tmp [ 3 ] , ef3sym ) ) {
tmp [ 5 ] = arg_0 ( tmp [ 3 ] ) ;
{
if ( check_sym ( tmp [ 5 ] , ef4sym ) ) {
tmp [ 6 ] = arg_0 ( tmp [ 5 ] ) ;
{
if ( check_sym ( tmp [ 6 ] , lf3sym ) ) {
tmp [ 7 ] = arg_0 ( tmp [ 6 ] ) ;
{
if ( check_sym ( tmp [ 4 ] , ef7sym ) ) {
tmp [ 8 ] = arg_0 ( tmp [ 4 ] ) ;
{
if ( check_sym ( tmp [ 8 ] , ef8sym ) ) {
tmp [ 9 ] = arg_0 ( tmp [ 8 ] ) ;
{
if ( check_sym ( tmp [ 9 ] , lf4sym ) ) {
tmp [ 10 ] = arg_0 ( tmp [ 9 ] ) ;
{
if ( is_single_element ( tmp [ 7 ] ) ) {
tmp [ 11 ] = list_head ( tmp [ 7 ] ) ;
{
if ( check_sym ( tmp [ 11 ] , ef5sym ) ) {
tmp [ 12 ] = arg_0 ( tmp [ 11 ] ) ;
{
if ( check_sym ( tmp [ 12 ] , ef6sym ) ) {
tmp [ 13 ] = arg_0 ( tmp [ 12 ] ) ;
{
if ( check_sym ( tmp [ 2 ] , ef5sym ) ) {
tmp [ 14 ] = arg_0 ( tmp [ 2 ] ) ;
{
if ( check_sym ( tmp [ 14 ] , ef6sym ) ) {
tmp [ 15 ] = arg_0 ( tmp [ 14 ] ) ;
{
tmp [ 16 ] = ( * ef12 ) ( tmp [ 15 ] , tmp [ 13 ] ) ;
tmp [ 17 ] = ( constant0 ? constant0 : ( constant0 = ( * ef13 ) ( ( * ef14 ) ( ) ) ) ) ;
if ( term_equal ( tmp [ 16 ] , tmp [ 17 ] ) ) {
tmp [ 18 ] = lf_AUX_Parse_Table35_1 ( ( * ef1 ) ( ( * ef2 ) ( lf2 ( make_list ( tmp [ 1 ] ) ) ) ) , ( * ef3 ) ( ( * ef4 ) ( lf3 ( make_list ( ( * ef5 ) ( ( * ef6 ) ( tmp [ 15 ] ) ) ) ) ) ) , ( * ef7 ) ( ( * ef8 ) ( lf4 ( make_list ( atmp2000 ) ) ) ) ) ;
tmp [ 19 ] = ( * ef9 ) ( ( * ef10 ) ( ( * ef3 ) ( ( * ef4 ) ( lf3 ( make_list ( ( * ef5 ) ( ( * ef6 ) ( tmp [ 13 ] ) ) ) ) ) ) , ( * ef7 ) ( ( * ef8 ) ( lf4 ( make_list ( tmp [ 10 ] ) ) ) ) ) , tmp [ 18 ] ) ;
FUNC_EXIT ( tmp [ 19 ] ) ;
}
else {
tmp [ 18 ] = lf_AUX_Parse_Table35_1 ( ( * ef1 ) ( ( * ef2 ) ( lf2 ( make_list ( tmp [ 1 ] ) ) ) ) , ( * ef3 ) ( ( * ef4 ) ( lf3 ( make_list ( ( * ef5 ) ( ( * ef6 ) ( ( * ef15 ) ( tmp [ 15 ] , tmp [ 16 ] ) ) ) ) ) ) ) , ( * ef7 ) ( ( * ef8 ) ( lf4 ( make_list ( atmp2000 ) ) ) ) ) ;
tmp [ 19 ] = ( * ef9 ) ( ( * ef10 ) ( ( * ef3 ) ( ( * ef4 ) ( lf3 ( make_list ( ( * ef5 ) ( ( * ef6 ) ( ( * ef15 ) ( tmp [ 13 ] , tmp [ 16 ] ) ) ) ) ) ) ) , ( * ef7 ) ( ( * ef8 ) ( lf4 ( make_list ( tmp [ 10 ] ) ) ) ) ) , ( * ef9 ) ( ( * ef10 ) ( ( * ef3 ) ( ( * ef4 ) ( lf3 ( make_list ( ( * ef5 ) ( ( * ef6 ) ( tmp [ 16 ] ) ) ) ) ) ) , ( * ef16 ) ( ( * ef7 ) ( ( * ef8 ) ( lf4 ( make_list ( tmp [ 10 ] ) ) ) ) , ( * ef7 ) ( ( * ef8 ) ( lf4 ( make_list ( atmp2000 ) ) ) ) ) ) , tmp [ 18 ] ) ) ;
FUNC_EXIT ( tmp [ 19 ] ) ;
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
if ( is_single_element ( atmp1000 ) ) {
tmp [ 0 ] = list_head ( atmp1000 ) ;
if ( check_sym ( tmp [ 0 ] , ef5sym ) ) {
tmp [ 1 ] = arg_0 ( tmp [ 0 ] ) ;
if ( check_sym ( tmp [ 1 ] , ef6sym ) ) {
tmp [ 2 ] = arg_0 ( tmp [ 1 ] ) ;
FUNC_EXIT ( ( * ef9 ) ( ( * ef10 ) ( ( * ef3 ) ( ( * ef4 ) ( lf3 ( make_list ( ( * ef5 ) ( ( * ef6 ) ( tmp [ 2 ] ) ) ) ) ) ) , ( * ef7 ) ( ( * ef8 ) ( lf4 ( make_list ( atmp2000 ) ) ) ) ) , ( * ef11 ) ( ) ) ) ;
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
}
}
}
}
}
FUNC_EXIT ( make_nf3 ( lf_AUX_Parse_Table35_1sym , arg0 , arg1 , arg2 ) ) ;
}
}
ATerm lf4 ( ATerm arg0 ) {
CONS_ENTRY ( lf4sym , ATmakeAppl ( lf4sym , arg0 ) ) ;
CONS_EXIT ( make_nf1 ( lf4sym , arg0 ) ) ;
}
ATerm lf3 ( ATerm arg0 ) {
CONS_ENTRY ( lf3sym , ATmakeAppl ( lf3sym , arg0 ) ) ;
CONS_EXIT ( make_nf1 ( lf3sym , arg0 ) ) ;
}
ATerm lf2 ( ATerm arg0 ) {
CONS_ENTRY ( lf2sym , ATmakeAppl ( lf2sym , arg0 ) ) ;
CONS_EXIT ( make_nf1 ( lf2sym , arg0 ) ) ;
}

