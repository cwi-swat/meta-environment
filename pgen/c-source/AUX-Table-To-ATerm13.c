#include  "asc-support.h"
static Symbol lf_AUX_Table_To_ATerm13_1sym ;
static ATerm lf_AUX_Table_To_ATerm13_1 ( ATerm arg1 ) ;
static Symbol ef3sym ;
static funcptr ef3 ;
static Symbol ef4sym ;
static funcptr ef4 ;
static Symbol ef5sym ;
static funcptr ef5 ;
static Symbol ef10sym ;
static funcptr ef10 ;
static Symbol ef13sym ;
static funcptr ef13 ;
static Symbol ef14sym ;
static funcptr ef14 ;
static Symbol ef15sym ;
static funcptr ef15 ;
static Symbol ef16sym ;
static funcptr ef16 ;
static Symbol lf3sym ;
static ATerm lf3 ( ATerm arg1 ) ;
static Symbol ef20sym ;
static funcptr ef20 ;
static Symbol ef21sym ;
static funcptr ef21 ;
static Symbol ef17sym ;
static funcptr ef17 ;
static Symbol lf4sym ;
static ATerm lf4 ( ATerm arg1 ) ;
static Symbol ef24sym ;
static funcptr ef24 ;
static Symbol ef6sym ;
static funcptr ef6 ;
static Symbol ef9sym ;
static funcptr ef9 ;
static Symbol ef18sym ;
static funcptr ef18 ;
static Symbol ef19sym ;
static funcptr ef19 ;
static Symbol ef11sym ;
static funcptr ef11 ;
static Symbol ef12sym ;
static funcptr ef12 ;
static Symbol ef22sym ;
static funcptr ef22 ;
static Symbol ef23sym ;
static funcptr ef23 ;
static Symbol ef25sym ;
static funcptr ef25 ;
static Symbol ef27sym ;
static funcptr ef27 ;
static Symbol ef1sym ;
static funcptr ef1 ;
static Symbol ef2sym ;
static funcptr ef2 ;
static Symbol lf2sym ;
static ATerm lf2 ( ATerm arg1 ) ;
static Symbol ef28sym ;
static funcptr ef28 ;
static Symbol ef7sym ;
static funcptr ef7 ;
static Symbol ef8sym ;
static funcptr ef8 ;
static Symbol ef26sym ;
static funcptr ef26 ;
static Symbol ef29sym ;
static funcptr ef29 ;
void register_AUX_Table_To_ATerm13 ( ) {
lf_AUX_Table_To_ATerm13_1sym = ATmakeSymbol ( "prod(id(\"Table-To-ATerm\"),w(\"\"),[l(\"aterm\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"ActionSet\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATermList\"),w(\"\"),no-attrs)"
 , 1 , ATtrue ) ;
ATprotectSymbol ( lf_AUX_Table_To_ATerm13_1sym ) ;
lf3sym = ATmakeSymbol ( "listtype(sort(\"Symbol\"))" , 1 , ATtrue ) ;
ATprotectSymbol ( lf3sym ) ;
lf4sym = ATmakeSymbol ( "listtype(sort(\"Lookahead\"),ql(\",\"))" , 1 , ATtrue ) ;
ATprotectSymbol ( lf4sym ) ;
lf2sym = ATmakeSymbol ( "listtype(sort(\"Action\"))" , 1 , ATtrue ) ;
ATprotectSymbol ( lf2sym ) ;
register_prod ( ATparse ( "prod(id(\"Table-To-ATerm\"),w(\"\"),[l(\"aterm\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"ActionSet\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATermList\"),w(\"\"),no-attrs)" ) , lf_AUX_Table_To_ATerm13_1 , lf_AUX_Table_To_ATerm13_1sym ) ;
register_prod ( ATparse ( "listtype(sort(\"Action\"))" ) , lf2 , lf2sym ) ;
register_prod ( ATparse ( "listtype(sort(\"Symbol\"))" ) , lf3 , lf3sym ) ;
register_prod ( ATparse ( "listtype(sort(\"Lookahead\"),ql(\",\"))" ) , lf4 , lf4sym ) ;
}
void resolve_AUX_Table_To_ATerm13 ( ) {
ef1 = lookup_func ( ATreadFromString ( "prod(id(\"Actions\"),w(\"\"),[ql(\"{\"),w(\"\"),sort(\"Actions\"),w(\"\"),ql(\"}\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ActionSet\"),w(\"\"),no-attrs)" ) ) ;
ef1sym = lookup_sym ( ATreadFromString ( "prod(id(\"Actions\"),w(\"\"),[ql(\"{\"),w(\"\"),sort(\"Actions\"),w(\"\"),ql(\"}\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ActionSet\"),w(\"\"),no-attrs)" ) ) ;
ef2 = lookup_func ( ATreadFromString ( "prod(id(\"Actions\"),w(\"\"),[iter(sort(\"Action\"),w(\"\"),l(\"*\"))],w(\"\"),l(\"->\"),w(\"\"),sort(\"Actions\"),w(\"\"),no-attrs)" ) ) ;
ef2sym = lookup_sym ( ATreadFromString ( "prod(id(\"Actions\"),w(\"\"),[iter(sort(\"Action\"),w(\"\"),l(\"*\"))],w(\"\"),l(\"->\"),w(\"\"),sort(\"Actions\"),w(\"\"),no-attrs)" ) ) ;
ef3 = lookup_func ( ATreadFromString ( "prod(id(\"ATerms\"),w(\"\"),[ql(\"[\"),w(\"\"),ql(\"]\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATermList\"),w(\"\"),no-attrs)" ) ) ;
ef3sym = lookup_sym ( ATreadFromString ( "prod(id(\"ATerms\"),w(\"\"),[ql(\"[\"),w(\"\"),ql(\"]\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATermList\"),w(\"\"),no-attrs)" ) ) ;
ef4 = lookup_func ( ATreadFromString ( "prod(id(\"ATerm-Lists\"),w(\"\"),[sort(\"ATermList\"),w(\"\"),ql(\"++\"),w(\"\"),sort(\"ATermList\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATermList\"),w(\"\"),attrs(l(\"{\"),w(\"\"),[l(\"right\")],w(\"\"),l(\"}\")))" ) ) ;
ef4sym = lookup_sym ( ATreadFromString ( "prod(id(\"ATerm-Lists\"),w(\"\"),[sort(\"ATermList\"),w(\"\"),ql(\"++\"),w(\"\"),sort(\"ATermList\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATermList\"),w(\"\"),attrs(l(\"{\"),w(\"\"),[l(\"right\")],w(\"\"),l(\"}\")))" ) ) ;
ef5 = lookup_func ( ATreadFromString ( "prod(id(\"Actions\"),w(\"\"),[l(\"shift\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Int\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Action\"),w(\"\"),no-attrs)" ) ) ;
ef5sym = lookup_sym ( ATreadFromString ( "prod(id(\"Actions\"),w(\"\"),[l(\"shift\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Int\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Action\"),w(\"\"),no-attrs)" ) ) ;
ef6 = lookup_func ( ATreadFromString ( "prod(id(\"Basic-Integers\"),w(\"\"),[sort(\"IntCon\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Int\"),w(\"\"),no-attrs)" ) ) ;
ef6sym = lookup_sym ( ATreadFromString ( "prod(id(\"Basic-Integers\"),w(\"\"),[sort(\"IntCon\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Int\"),w(\"\"),no-attrs)" ) ) ;
ef7 = lookup_func ( ATreadFromString ( "prod(id(\"ATerms\"),w(\"\"),[ql(\"[\"),w(\"\"),sort(\"ATerms\"),w(\"\"),ql(\"]\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATermList\"),w(\"\"),no-attrs)" ) ) ;
ef7sym = lookup_sym ( ATreadFromString ( "prod(id(\"ATerms\"),w(\"\"),[ql(\"[\"),w(\"\"),sort(\"ATerms\"),w(\"\"),ql(\"]\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATermList\"),w(\"\"),no-attrs)" ) ) ;
ef8 = lookup_func ( ATreadFromString ( "prod(id(\"ATerms\"),w(\"\"),[sort(\"ATerm\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerms\"),w(\"\"),no-attrs)" ) ) ;
ef8sym = lookup_sym ( ATreadFromString ( "prod(id(\"ATerms\"),w(\"\"),[sort(\"ATerm\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerms\"),w(\"\"),no-attrs)" ) ) ;
ef9 = lookup_func ( ATreadFromString ( "prod(id(\"ATerms\"),w(\"\"),[sort(\"AFun\"),w(\"\"),ql(\"(\"),w(\"\"),sort(\"ATerms\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerm\"),w(\"\"),no-attrs)" ) ) ;
ef9sym = lookup_sym ( ATreadFromString ( "prod(id(\"ATerms\"),w(\"\"),[sort(\"AFun\"),w(\"\"),ql(\"(\"),w(\"\"),sort(\"ATerms\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerm\"),w(\"\"),no-attrs)" ) ) ;
ef10 = lookup_func ( ATreadFromString ( "prod(id(\"Parse-Table-Constructors\"),w(\"\"),[ql(\"shift\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)" ) ) ;
ef10sym = lookup_sym ( ATreadFromString ( "prod(id(\"Parse-Table-Constructors\"),w(\"\"),[ql(\"shift\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)" ) ) ;
ef11 = lookup_func ( ATreadFromString ( "prod(id(\"ATerms\"),w(\"\"),[sort(\"ACon\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerm\"),w(\"\"),no-attrs)" ) ) ;
ef11sym = lookup_sym ( ATreadFromString ( "prod(id(\"ATerms\"),w(\"\"),[sort(\"ACon\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerm\"),w(\"\"),no-attrs)" ) ) ;
ef12 = lookup_func ( ATreadFromString ( "prod(id(\"ATerms\"),w(\"\"),[sort(\"IntCon\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ACon\"),w(\"\"),no-attrs)" ) ) ;
ef12sym = lookup_sym ( ATreadFromString ( "prod(id(\"ATerms\"),w(\"\"),[sort(\"IntCon\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ACon\"),w(\"\"),no-attrs)" ) ) ;
ef13 = lookup_func ( ATreadFromString ( "prod(id(\"Actions\"),w(\"\"),[l(\"reduce\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Int\"),w(\"\"),l(\",\"),w(\"\"),sort(\"Int\"),w(\"\"),l(\",\"),w(\"\"),sort(\"Label\"),w(\"\"),l(\",\"),w(\"\"),sort(\"Lookaheads\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Action\"),w(\"\"),no-attrs)" ) ) ;
ef13sym = lookup_sym ( ATreadFromString ( "prod(id(\"Actions\"),w(\"\"),[l(\"reduce\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Int\"),w(\"\"),l(\",\"),w(\"\"),sort(\"Int\"),w(\"\"),l(\",\"),w(\"\"),sort(\"Label\"),w(\"\"),l(\",\"),w(\"\"),sort(\"Lookaheads\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Action\"),w(\"\"),no-attrs)" ) ) ;
ef14 = lookup_func ( ATreadFromString ( "prod(id(\"Earley-Graphs\"),w(\"\"),[sort(\"Production\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Label\"),w(\"\"),no-attrs)" ) ) ;
ef14sym = lookup_sym ( ATreadFromString ( "prod(id(\"Earley-Graphs\"),w(\"\"),[sort(\"Production\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Label\"),w(\"\"),no-attrs)" ) ) ;
ef15 = lookup_func ( ATreadFromString ( "prod(id(\"Kernel-Sdf-Syntax\"),w(\"\"),[sort(\"Symbols\"),w(\"\"),ql(\"->\"),w(\"\"),sort(\"Symbol\"),w(\"\"),sort(\"Attributes\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Production\"),w(\"\"),no-attrs)" ) ) ;
ef15sym = lookup_sym ( ATreadFromString ( "prod(id(\"Kernel-Sdf-Syntax\"),w(\"\"),[sort(\"Symbols\"),w(\"\"),ql(\"->\"),w(\"\"),sort(\"Symbol\"),w(\"\"),sort(\"Attributes\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Production\"),w(\"\"),no-attrs)" ) ) ;
ef16 = lookup_func ( ATreadFromString ( "prod(id(\"Symbols\"),w(\"\"),[iter(sort(\"Symbol\"),w(\"\"),l(\"*\"))],w(\"\"),l(\"->\"),w(\"\"),sort(\"Symbols\"),w(\"\"),no-attrs)" ) ) ;
ef16sym = lookup_sym ( ATreadFromString ( "prod(id(\"Symbols\"),w(\"\"),[iter(sort(\"Symbol\"),w(\"\"),l(\"*\"))],w(\"\"),l(\"->\"),w(\"\"),sort(\"Symbols\"),w(\"\"),no-attrs)" ) ) ;
ef17 = lookup_func ( ATreadFromString ( "prod(id(\"Restrictions-Sdf-Syntax\"),w(\"\"),[ql(\"[[\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Lookahead\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\"]]\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Lookaheads\"),w(\"\"),no-attrs)" ) ) ;
ef17sym = lookup_sym ( ATreadFromString ( "prod(id(\"Restrictions-Sdf-Syntax\"),w(\"\"),[ql(\"[[\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Lookahead\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\"]]\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Lookaheads\"),w(\"\"),no-attrs)" ) ) ;
ef18 = lookup_func ( ATreadFromString ( "prod(id(\"Parse-Table-Constructors\"),w(\"\"),[ql(\"reduce\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)" ) ) ;
ef18sym = lookup_sym ( ATreadFromString ( "prod(id(\"Parse-Table-Constructors\"),w(\"\"),[ql(\"reduce\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)" ) ) ;
ef19 = lookup_func ( ATreadFromString ( "prod(id(\"ATerms\"),w(\"\"),[sort(\"ATerm\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"ATerms\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerms\"),w(\"\"),no-attrs)" ) ) ;
ef19sym = lookup_sym ( ATreadFromString ( "prod(id(\"ATerms\"),w(\"\"),[sort(\"ATerm\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"ATerms\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerms\"),w(\"\"),no-attrs)" ) ) ;
ef20 = lookup_func ( ATreadFromString ( "prod(id(\"IntCon\"),w(\"\"),[sort(\"NatCon\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"IntCon\"),w(\"\"),no-attrs)" ) ) ;
ef20sym = lookup_sym ( ATreadFromString ( "prod(id(\"IntCon\"),w(\"\"),[sort(\"NatCon\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"IntCon\"),w(\"\"),no-attrs)" ) ) ;
ef21 = lookup_func ( ATreadFromString ( "prod(id(\"Table-To-ATerm\"),w(\"\"),[l(\"reject\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Attributes\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"NatCon\"),w(\"\"),no-attrs)" ) ) ;
ef21sym = lookup_sym ( ATreadFromString ( "prod(id(\"Table-To-ATerm\"),w(\"\"),[l(\"reject\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Attributes\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"NatCon\"),w(\"\"),no-attrs)" ) ) ;
ef22 = lookup_func ( ATreadFromString ( "prod(id(\"ATerms\"),w(\"\"),[sort(\"ATermList\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerm\"),w(\"\"),no-attrs)" ) ) ;
ef22sym = lookup_sym ( ATreadFromString ( "prod(id(\"ATerms\"),w(\"\"),[sort(\"ATermList\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerm\"),w(\"\"),no-attrs)" ) ) ;
ef23 = lookup_func ( ATreadFromString ( "prod(id(\"Table-To-ATerm\"),w(\"\"),[l(\"aterm-las\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Lookaheads\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATermList\"),w(\"\"),no-attrs)" ) ) ;
ef23sym = lookup_sym ( ATreadFromString ( "prod(id(\"Table-To-ATerm\"),w(\"\"),[l(\"aterm-las\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Lookaheads\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATermList\"),w(\"\"),no-attrs)" ) ) ;
ef24 = lookup_func ( ATreadFromString ( "prod(id(\"Actions\"),w(\"\"),[l(\"reduce\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Int\"),w(\"\"),l(\",\"),w(\"\"),sort(\"Int\"),w(\"\"),l(\",\"),w(\"\"),sort(\"Int\"),w(\"\"),l(\",\"),w(\"\"),sort(\"Lookaheads\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Action\"),w(\"\"),no-attrs)" ) ) ;
ef24sym = lookup_sym ( ATreadFromString ( "prod(id(\"Actions\"),w(\"\"),[l(\"reduce\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Int\"),w(\"\"),l(\",\"),w(\"\"),sort(\"Int\"),w(\"\"),l(\",\"),w(\"\"),sort(\"Int\"),w(\"\"),l(\",\"),w(\"\"),sort(\"Lookaheads\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Action\"),w(\"\"),no-attrs)" ) ) ;
ef25 = lookup_func ( ATreadFromString ( "prod(id(\"Actions\"),w(\"\"),[l(\"accept\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Action\"),w(\"\"),no-attrs)" ) ) ;
ef25sym = lookup_sym ( ATreadFromString ( "prod(id(\"Actions\"),w(\"\"),[l(\"accept\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Action\"),w(\"\"),no-attrs)" ) ) ;
ef26 = lookup_func ( ATreadFromString ( "prod(id(\"ATerms\"),w(\"\"),[sort(\"AFun\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerm\"),w(\"\"),no-attrs)" ) ) ;
ef26sym = lookup_sym ( ATreadFromString ( "prod(id(\"ATerms\"),w(\"\"),[sort(\"AFun\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerm\"),w(\"\"),no-attrs)" ) ) ;
ef27 = lookup_func ( ATreadFromString ( "prod(id(\"Parse-Table-Constructors\"),w(\"\"),[ql(\"accept\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)" ) ) ;
ef27sym = lookup_sym ( ATreadFromString ( "prod(id(\"Parse-Table-Constructors\"),w(\"\"),[ql(\"accept\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)" ) ) ;
ef28 = lookup_func ( ATreadFromString ( "prod(id(\"Actions\"),w(\"\"),[l(\"error\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Action\"),w(\"\"),no-attrs)" ) ) ;
ef28sym = lookup_sym ( ATreadFromString ( "prod(id(\"Actions\"),w(\"\"),[l(\"error\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Action\"),w(\"\"),no-attrs)" ) ) ;
ef29 = lookup_func ( ATreadFromString ( "prod(id(\"Parse-Table-Constructors\"),w(\"\"),[ql(\"error\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)" ) ) ;
ef29sym = lookup_sym ( ATreadFromString ( "prod(id(\"Parse-Table-Constructors\"),w(\"\"),[ql(\"error\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)" ) ) ;
}
static ATerm constant0 = NULL ;
static ATerm constant1 = NULL ;
static ATerm constant2 = NULL ;
static ATerm constant3 = NULL ;
static ATerm constant4 = NULL ;
static ATerm constant5 = NULL ;
void init_AUX_Table_To_ATerm13 ( ) {
ATprotect ( & constant0 ) ;
ATprotect ( & constant1 ) ;
ATprotect ( & constant2 ) ;
ATprotect ( & constant3 ) ;
ATprotect ( & constant4 ) ;
ATprotect ( & constant5 ) ;
}
ATerm lf_AUX_Table_To_ATerm13_1 ( ATerm arg0 ) {
{
ATerm tmp [ 15 ] ;
FUNC_ENTRY ( lf_AUX_Table_To_ATerm13_1sym , ATmakeAppl ( lf_AUX_Table_To_ATerm13_1sym , arg0 ) ) ;
if ( check_sym ( arg0 , ef1sym ) ) {
{
ATerm atmp00 = arg_0 ( arg0 ) ;
if ( check_sym ( atmp00 , ef2sym ) ) {
{
ATerm atmp000 = arg_0 ( atmp00 ) ;
if ( check_sym ( atmp000 , lf2sym ) ) {
{
ATerm atmp0000 = arg_0 ( atmp000 ) ;
if ( term_equal ( ( * ef1 ) ( ( * ef2 ) ( lf2 ( make_list ( atmp0000 ) ) ) ) , ( constant0 ? constant0 : ( constant0 = ( * ef1 ) ( ( * ef2 ) ( lf2 ( make_list ( null ( ) ) ) ) ) ) ) ) ) {
FUNC_EXIT_CONST ( constant1 , ( * ef3 ) ( ) ) ;
}
{
if ( not_empty_list ( atmp0000 ) ) {
tmp [ 0 ] = list_head ( atmp0000 ) ;
tmp [ 1 ] = list_tail ( atmp0000 ) ;
if ( not_empty_list ( tmp [ 1 ] ) ) {
FUNC_EXIT ( ( * ef4 ) ( lf_AUX_Table_To_ATerm13_1 ( ( * ef1 ) ( ( * ef2 ) ( lf2 ( make_list ( tmp [ 0 ] ) ) ) ) ) , lf_AUX_Table_To_ATerm13_1 ( ( * ef1 ) ( ( * ef2 ) ( lf2 ( make_list ( tmp [ 1 ] ) ) ) ) ) ) ) ;
}
}
{
if ( is_single_element ( atmp0000 ) ) {
tmp [ 0 ] = list_head ( atmp0000 ) ;
if ( check_sym ( tmp [ 0 ] , ef24sym ) ) {
tmp [ 1 ] = arg_0 ( tmp [ 0 ] ) ;
tmp [ 2 ] = arg_1 ( tmp [ 0 ] ) ;
tmp [ 3 ] = arg_2 ( tmp [ 0 ] ) ;
tmp [ 4 ] = arg_3 ( tmp [ 0 ] ) ;
if ( check_sym ( tmp [ 1 ] , ef6sym ) ) {
tmp [ 5 ] = arg_0 ( tmp [ 1 ] ) ;
if ( check_sym ( tmp [ 2 ] , ef6sym ) ) {
tmp [ 6 ] = arg_0 ( tmp [ 2 ] ) ;
if ( check_sym ( tmp [ 3 ] , ef6sym ) ) {
tmp [ 7 ] = arg_0 ( tmp [ 3 ] ) ;
if ( check_sym ( tmp [ 4 ] , ef17sym ) ) {
tmp [ 8 ] = arg_0 ( tmp [ 4 ] ) ;
if ( check_sym ( tmp [ 8 ] , lf4sym ) ) {
tmp [ 9 ] = arg_0 ( tmp [ 8 ] ) ;
if ( ! not_empty_list ( tmp [ 9 ] ) ) {
FUNC_EXIT ( ( * ef7 ) ( ( * ef8 ) ( ( * ef9 ) ( ( * ef18 ) ( ) , ( * ef19 ) ( ( * ef11 ) ( ( * ef12 ) ( tmp [ 5 ] ) ) , ( * ef19 ) ( ( * ef11 ) ( ( * ef12 ) ( tmp [ 6 ] ) ) , ( * ef8 ) ( ( * ef11 ) ( ( * ef12 ) ( tmp [ 7 ] ) ) ) ) ) ) ) ) ) ;
}
}
}
}
}
}
}
if ( check_sym ( tmp [ 0 ] , ef5sym ) ) {
tmp [ 1 ] = arg_0 ( tmp [ 0 ] ) ;
if ( check_sym ( tmp [ 1 ] , ef6sym ) ) {
tmp [ 2 ] = arg_0 ( tmp [ 1 ] ) ;
FUNC_EXIT ( ( * ef7 ) ( ( * ef8 ) ( ( * ef9 ) ( ( * ef10 ) ( ) , ( * ef8 ) ( ( * ef11 ) ( ( * ef12 ) ( tmp [ 2 ] ) ) ) ) ) ) ) ;
}
}
if ( check_sym ( tmp [ 0 ] , ef13sym ) ) {
tmp [ 1 ] = arg_0 ( tmp [ 0 ] ) ;
tmp [ 2 ] = arg_1 ( tmp [ 0 ] ) ;
tmp [ 3 ] = arg_2 ( tmp [ 0 ] ) ;
tmp [ 4 ] = arg_3 ( tmp [ 0 ] ) ;
if ( check_sym ( tmp [ 1 ] , ef6sym ) ) {
tmp [ 5 ] = arg_0 ( tmp [ 1 ] ) ;
if ( check_sym ( tmp [ 2 ] , ef6sym ) ) {
tmp [ 6 ] = arg_0 ( tmp [ 2 ] ) ;
if ( check_sym ( tmp [ 3 ] , ef14sym ) ) {
tmp [ 7 ] = arg_0 ( tmp [ 3 ] ) ;
if ( check_sym ( tmp [ 7 ] , ef15sym ) ) {
tmp [ 8 ] = arg_0 ( tmp [ 7 ] ) ;
tmp [ 9 ] = arg_1 ( tmp [ 7 ] ) ;
tmp [ 10 ] = arg_2 ( tmp [ 7 ] ) ;
if ( check_sym ( tmp [ 8 ] , ef16sym ) ) {
tmp [ 11 ] = arg_0 ( tmp [ 8 ] ) ;
if ( check_sym ( tmp [ 11 ] , lf3sym ) ) {
tmp [ 12 ] = arg_0 ( tmp [ 11 ] ) ;
if ( check_sym ( tmp [ 4 ] , ef17sym ) ) {
tmp [ 13 ] = arg_0 ( tmp [ 4 ] ) ;
if ( check_sym ( tmp [ 13 ] , lf4sym ) ) {
tmp [ 14 ] = arg_0 ( tmp [ 13 ] ) ;
if ( ! not_empty_list ( tmp [ 14 ] ) ) {
FUNC_EXIT ( ( * ef7 ) ( ( * ef8 ) ( ( * ef9 ) ( ( * ef18 ) ( ) , ( * ef19 ) ( ( * ef11 ) ( ( * ef12 ) ( tmp [ 5 ] ) ) , ( * ef19 ) ( ( * ef11 ) ( ( * ef12 ) ( tmp [ 6 ] ) ) , ( * ef8 ) ( ( * ef11 ) ( ( * ef12 ) ( ( * ef20 ) ( ( * ef21 ) ( tmp [ 10 ] ) ) ) ) ) ) ) ) ) ) ) ;
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
tmp [ 0 ] = list_head ( atmp0000 ) ;
if ( term_equal ( tmp [ 0 ] , ( constant2 ? constant2 : ( constant2 = ( * ef25 ) ( ) ) ) ) ) {
FUNC_EXIT_CONST ( constant3 , ( * ef7 ) ( ( * ef8 ) ( ( * ef26 ) ( ( * ef27 ) ( ) ) ) ) ) ;
}
if ( term_equal ( tmp [ 0 ] , ( constant4 ? constant4 : ( constant4 = ( * ef28 ) ( ) ) ) ) ) {
FUNC_EXIT_CONST ( constant5 , ( * ef7 ) ( ( * ef8 ) ( ( * ef26 ) ( ( * ef29 ) ( ) ) ) ) ) ;
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
if ( check_sym ( arg0 , ef1sym ) ) {
{
ATerm atmp00 = arg_0 ( arg0 ) ;
if ( check_sym ( atmp00 , ef2sym ) ) {
{
ATerm atmp000 = arg_0 ( atmp00 ) ;
if ( check_sym ( atmp000 , lf2sym ) ) {
{
ATerm atmp0000 = arg_0 ( atmp000 ) ;
if ( is_single_element ( atmp0000 ) ) {
tmp [ 0 ] = list_head ( atmp0000 ) ;
if ( check_sym ( tmp [ 0 ] , ef24sym ) ) {
tmp [ 1 ] = arg_0 ( tmp [ 0 ] ) ;
tmp [ 2 ] = arg_1 ( tmp [ 0 ] ) ;
tmp [ 3 ] = arg_2 ( tmp [ 0 ] ) ;
tmp [ 4 ] = arg_3 ( tmp [ 0 ] ) ;
if ( check_sym ( tmp [ 1 ] , ef6sym ) ) {
tmp [ 5 ] = arg_0 ( tmp [ 1 ] ) ;
if ( check_sym ( tmp [ 2 ] , ef6sym ) ) {
tmp [ 6 ] = arg_0 ( tmp [ 2 ] ) ;
if ( check_sym ( tmp [ 3 ] , ef6sym ) ) {
tmp [ 7 ] = arg_0 ( tmp [ 3 ] ) ;
FUNC_EXIT ( ( * ef7 ) ( ( * ef8 ) ( ( * ef9 ) ( ( * ef18 ) ( ) , ( * ef19 ) ( ( * ef11 ) ( ( * ef12 ) ( tmp [ 5 ] ) ) , ( * ef19 ) ( ( * ef11 ) ( ( * ef12 ) ( tmp [ 6 ] ) ) , ( * ef19 ) ( ( * ef11 ) ( ( * ef12 ) ( tmp [ 7 ] ) ) , ( * ef8 ) ( ( * ef22 ) ( ( * ef23 ) ( tmp [ 4 ] ) ) ) ) ) ) ) ) ) ) ;
}
}
}
}
if ( check_sym ( tmp [ 0 ] , ef13sym ) ) {
tmp [ 1 ] = arg_0 ( tmp [ 0 ] ) ;
tmp [ 2 ] = arg_1 ( tmp [ 0 ] ) ;
tmp [ 3 ] = arg_2 ( tmp [ 0 ] ) ;
tmp [ 4 ] = arg_3 ( tmp [ 0 ] ) ;
if ( check_sym ( tmp [ 1 ] , ef6sym ) ) {
tmp [ 5 ] = arg_0 ( tmp [ 1 ] ) ;
if ( check_sym ( tmp [ 2 ] , ef6sym ) ) {
tmp [ 6 ] = arg_0 ( tmp [ 2 ] ) ;
if ( check_sym ( tmp [ 3 ] , ef14sym ) ) {
tmp [ 7 ] = arg_0 ( tmp [ 3 ] ) ;
if ( check_sym ( tmp [ 7 ] , ef15sym ) ) {
tmp [ 8 ] = arg_0 ( tmp [ 7 ] ) ;
tmp [ 9 ] = arg_1 ( tmp [ 7 ] ) ;
tmp [ 10 ] = arg_2 ( tmp [ 7 ] ) ;
if ( check_sym ( tmp [ 8 ] , ef16sym ) ) {
tmp [ 11 ] = arg_0 ( tmp [ 8 ] ) ;
if ( check_sym ( tmp [ 11 ] , lf3sym ) ) {
tmp [ 12 ] = arg_0 ( tmp [ 11 ] ) ;
FUNC_EXIT ( ( * ef7 ) ( ( * ef8 ) ( ( * ef9 ) ( ( * ef18 ) ( ) , ( * ef19 ) ( ( * ef11 ) ( ( * ef12 ) ( tmp [ 5 ] ) ) , ( * ef19 ) ( ( * ef11 ) ( ( * ef12 ) ( tmp [ 6 ] ) ) , ( * ef19 ) ( ( * ef11 ) ( ( * ef12 ) ( ( * ef20 ) ( ( * ef21 ) ( tmp [ 10 ] ) ) ) ) , ( * ef8 ) ( ( * ef22 ) ( ( * ef23 ) ( tmp [ 4 ] ) ) ) ) ) ) ) ) ) ) ;
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
FUNC_EXIT ( make_nf1 ( lf_AUX_Table_To_ATerm13_1sym , arg0 ) ) ;
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

