#include  "asc-support.h"
static Symbol lf_AUX_Goto_PCC5_1sym ;
static ATerm lf_AUX_Goto_PCC5_1 ( ATerm arg1 , ATerm arg2 , ATerm arg3 ) ;
static Symbol ef4sym ;
static funcptr ef4 ;
static Symbol ef8sym ;
static funcptr ef8 ;
static Symbol ef7sym ;
static funcptr ef7 ;
static Symbol ef5sym ;
static funcptr ef5 ;
static Symbol ef6sym ;
static funcptr ef6 ;
static Symbol lf5sym ;
static ATerm lf5 ( ATerm arg1 ) ;
static Symbol ef9sym ;
static funcptr ef9 ;
static Symbol ef1sym ;
static funcptr ef1 ;
static Symbol lf2sym ;
static ATerm lf2 ( ATerm arg1 ) ;
static Symbol ef2sym ;
static funcptr ef2 ;
static Symbol lf3sym ;
static ATerm lf3 ( ATerm arg1 ) ;
static Symbol ef3sym ;
static funcptr ef3 ;
static Symbol lf4sym ;
static ATerm lf4 ( ATerm arg1 ) ;
void register_AUX_Goto_PCC5 ( ) {
lf_AUX_Goto_PCC5_1sym = ATmakeSymbol ( "prod(id(\"Goto-PCC\"),w(\"\"),[l(\"pred\"),w(\"\"),ql(\"[[\"),w(\"\"),sort(\"Priorities\"),w(\"\"),ql(\"]]\"),w(\"\"),ql(\"(\"),w(\"\"),sort(\"Productions\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"Item\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ItemSet\"),w(\"\"),no-attrs)"
 , 3 , ATtrue ) ;
ATprotectSymbol ( lf_AUX_Goto_PCC5_1sym ) ;
lf5sym = ATmakeSymbol ( "listtype(sort(\"Symbol\"))" , 1 , ATtrue ) ;
ATprotectSymbol ( lf5sym ) ;
lf2sym = ATmakeSymbol ( "listtype(sort(\"Priority\"),ql(\",\"))" , 1 , ATtrue ) ;
ATprotectSymbol ( lf2sym ) ;
lf3sym = ATmakeSymbol ( "listtype(sort(\"Production\"))" , 1 , ATtrue ) ;
ATprotectSymbol ( lf3sym ) ;
lf4sym = ATmakeSymbol ( "listtype(sort(\"Item\"))" , 1 , ATtrue ) ;
ATprotectSymbol ( lf4sym ) ;
register_prod ( ATparse ( "prod(id(\"Goto-PCC\"),w(\"\"),[l(\"pred\"),w(\"\"),ql(\"[[\"),w(\"\"),sort(\"Priorities\"),w(\"\"),ql(\"]]\"),w(\"\"),ql(\"(\"),w(\"\"),sort(\"Productions\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"Item\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ItemSet\"),w(\"\"),no-attrs)" ) , lf_AUX_Goto_PCC5_1 , lf_AUX_Goto_PCC5_1sym ) ;
register_prod ( ATparse ( "listtype(sort(\"Priority\"),ql(\",\"))" ) , lf2 , lf2sym ) ;
register_prod ( ATparse ( "listtype(sort(\"Production\"))" ) , lf3 , lf3sym ) ;
register_prod ( ATparse ( "listtype(sort(\"Item\"))" ) , lf4 , lf4sym ) ;
register_prod ( ATparse ( "listtype(sort(\"Symbol\"))" ) , lf5 , lf5sym ) ;
}
void resolve_AUX_Goto_PCC5 ( ) {
ef1 = lookup_func ( ATreadFromString ( "prod(id(\"Priority-Sdf-Syntax\"),w(\"\"),[iter-sep(l(\"{\"),w(\"\"),sort(\"Priority\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\"))],w(\"\"),l(\"->\"),w(\"\"),sort(\"Priorities\"),w(\"\"),no-attrs)" ) ) ;
ef1sym = lookup_sym ( ATreadFromString ( "prod(id(\"Priority-Sdf-Syntax\"),w(\"\"),[iter-sep(l(\"{\"),w(\"\"),sort(\"Priority\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\"))],w(\"\"),l(\"->\"),w(\"\"),sort(\"Priorities\"),w(\"\"),no-attrs)" ) ) ;
ef2 = lookup_func ( ATreadFromString ( "prod(id(\"Kernel-Sdf-Syntax\"),w(\"\"),[iter(sort(\"Production\"),w(\"\"),l(\"*\"))],w(\"\"),l(\"->\"),w(\"\"),sort(\"Productions\"),w(\"\"),no-attrs)" ) ) ;
ef2sym = lookup_sym ( ATreadFromString ( "prod(id(\"Kernel-Sdf-Syntax\"),w(\"\"),[iter(sort(\"Production\"),w(\"\"),l(\"*\"))],w(\"\"),l(\"->\"),w(\"\"),sort(\"Productions\"),w(\"\"),no-attrs)" ) ) ;
ef3 = lookup_func ( ATreadFromString ( "prod(id(\"Earley-Items\"),w(\"\"),[ql(\"{\"),w(\"\"),iter(sort(\"Item\"),w(\"\"),l(\"*\")),w(\"\"),ql(\"}\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ItemSet\"),w(\"\"),no-attrs)" ) ) ;
ef3sym = lookup_sym ( ATreadFromString ( "prod(id(\"Earley-Items\"),w(\"\"),[ql(\"{\"),w(\"\"),iter(sort(\"Item\"),w(\"\"),l(\"*\")),w(\"\"),ql(\"}\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ItemSet\"),w(\"\"),no-attrs)" ) ) ;
ef4 = lookup_func ( ATreadFromString ( "prod(id(\"Earley-Items\"),w(\"\"),[sort(\"ItemSet\"),w(\"\"),ql(\"||\"),w(\"\"),sort(\"ItemSet\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ItemSet\"),w(\"\"),attrs(l(\"{\"),w(\"\"),[l(\"right\")],w(\"\"),l(\"}\")))" ) ) ;
ef4sym = lookup_sym ( ATreadFromString ( "prod(id(\"Earley-Items\"),w(\"\"),[sort(\"ItemSet\"),w(\"\"),ql(\"||\"),w(\"\"),sort(\"ItemSet\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ItemSet\"),w(\"\"),attrs(l(\"{\"),w(\"\"),[l(\"right\")],w(\"\"),l(\"}\")))" ) ) ;
ef5 = lookup_func ( ATreadFromString ( "prod(id(\"Kernel-Sdf-Syntax\"),w(\"\"),[sort(\"Symbols\"),w(\"\"),ql(\"->\"),w(\"\"),sort(\"Symbol\"),w(\"\"),sort(\"Attributes\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Production\"),w(\"\"),no-attrs)" ) ) ;
ef5sym = lookup_sym ( ATreadFromString ( "prod(id(\"Kernel-Sdf-Syntax\"),w(\"\"),[sort(\"Symbols\"),w(\"\"),ql(\"->\"),w(\"\"),sort(\"Symbol\"),w(\"\"),sort(\"Attributes\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Production\"),w(\"\"),no-attrs)" ) ) ;
ef6 = lookup_func ( ATreadFromString ( "prod(id(\"Symbols\"),w(\"\"),[iter(sort(\"Symbol\"),w(\"\"),l(\"*\"))],w(\"\"),l(\"->\"),w(\"\"),sort(\"Symbols\"),w(\"\"),no-attrs)" ) ) ;
ef6sym = lookup_sym ( ATreadFromString ( "prod(id(\"Symbols\"),w(\"\"),[iter(sort(\"Symbol\"),w(\"\"),l(\"*\"))],w(\"\"),l(\"->\"),w(\"\"),sort(\"Symbols\"),w(\"\"),no-attrs)" ) ) ;
ef7 = lookup_func ( ATreadFromString ( "prod(id(\"Earley-Items\"),w(\"\"),[ql(\"[\"),w(\"\"),sort(\"Symbols\"),w(\"\"),ql(\".\"),w(\"\"),sort(\"Production\"),w(\"\"),ql(\"]\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Item\"),w(\"\"),no-attrs)" ) ) ;
ef7sym = lookup_sym ( ATreadFromString ( "prod(id(\"Earley-Items\"),w(\"\"),[ql(\"[\"),w(\"\"),sort(\"Symbols\"),w(\"\"),ql(\".\"),w(\"\"),sort(\"Production\"),w(\"\"),ql(\"]\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Item\"),w(\"\"),no-attrs)" ) ) ;
ef8 = lookup_func ( ATreadFromString ( "prod(id(\"Priority-Conflict\"),w(\"\"),[l(\"cnf\"),w(\"\"),ql(\"[[\"),w(\"\"),sort(\"Priorities\"),w(\"\"),ql(\"]]\"),w(\"\"),ql(\"(\"),w(\"\"),sort(\"Item\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"Production\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),attrs(l(\"{\"),w(\"\"),[l(\"memo\")],w(\"\"),l(\"}\")))" ) ) ;
ef8sym = lookup_sym ( ATreadFromString ( "prod(id(\"Priority-Conflict\"),w(\"\"),[l(\"cnf\"),w(\"\"),ql(\"[[\"),w(\"\"),sort(\"Priorities\"),w(\"\"),ql(\"]]\"),w(\"\"),ql(\"(\"),w(\"\"),sort(\"Item\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"Production\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),attrs(l(\"{\"),w(\"\"),[l(\"memo\")],w(\"\"),l(\"}\")))" ) ) ;
ef9 = lookup_func ( ATreadFromString ( "prod(id(\"Booleans\"),w(\"\"),[ql(\"false\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)" ) ) ;
ef9sym = lookup_sym ( ATreadFromString ( "prod(id(\"Booleans\"),w(\"\"),[ql(\"false\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)" ) ) ;
}
static ATerm constant0 = NULL ;
static ATerm constant1 = NULL ;
void init_AUX_Goto_PCC5 ( ) {
ATprotect ( & constant0 ) ;
ATprotect ( & constant1 ) ;
}
ATerm lf_AUX_Goto_PCC5_1 ( ATerm arg0 , ATerm arg1 , ATerm arg2 ) {
{
ATerm tmp [ 8 ] ;
FUNC_ENTRY ( lf_AUX_Goto_PCC5_1sym , ATmakeAppl ( lf_AUX_Goto_PCC5_1sym , arg0 , arg1 , arg2 ) ) ;
if ( check_sym ( arg0 , ef1sym ) ) {
{
ATerm atmp00 = arg_0 ( arg0 ) ;
if ( check_sym ( atmp00 , lf2sym ) ) {
{
ATerm atmp000 = arg_0 ( atmp00 ) ;
if ( check_sym ( arg1 , ef2sym ) ) {
{
ATerm atmp10 = arg_0 ( arg1 ) ;
if ( check_sym ( atmp10 , lf3sym ) ) {
{
ATerm atmp100 = arg_0 ( atmp10 ) ;
if ( check_sym ( arg2 , ef7sym ) ) {
{
ATerm atmp20 = arg_0 ( arg2 ) ;
if ( check_sym ( atmp20 , ef6sym ) ) {
{
ATerm atmp200 = arg_0 ( atmp20 ) ;
if ( check_sym ( atmp200 , lf5sym ) ) {
{
ATerm atmp2000 = arg_0 ( atmp200 ) ;
{
ATerm atmp21 = arg_1 ( arg2 ) ;
if ( check_sym ( atmp21 , ef5sym ) ) {
{
ATerm atmp210 = arg_0 ( atmp21 ) ;
if ( check_sym ( atmp210 , ef6sym ) ) {
{
ATerm atmp2100 = arg_0 ( atmp210 ) ;
if ( check_sym ( atmp2100 , lf5sym ) ) {
{
ATerm atmp21000 = arg_0 ( atmp2100 ) ;
{
ATerm atmp211 = arg_1 ( atmp21 ) ;
{
ATerm atmp212 = arg_2 ( atmp21 ) ;
if ( is_single_element ( atmp100 ) ) {
tmp [ 0 ] = list_head ( atmp100 ) ;
if ( not_empty_list ( atmp21000 ) ) {
tmp [ 1 ] = list_head ( atmp21000 ) ;
tmp [ 2 ] = list_tail ( atmp21000 ) ;
if ( check_sym ( tmp [ 0 ] , ef5sym ) ) {
tmp [ 3 ] = arg_0 ( tmp [ 0 ] ) ;
tmp [ 4 ] = arg_1 ( tmp [ 0 ] ) ;
tmp [ 5 ] = arg_2 ( tmp [ 0 ] ) ;
if ( check_sym ( tmp [ 3 ] , ef6sym ) ) {
tmp [ 6 ] = arg_0 ( tmp [ 3 ] ) ;
if ( check_sym ( tmp [ 6 ] , lf5sym ) ) {
tmp [ 7 ] = arg_0 ( tmp [ 6 ] ) ;
if ( term_equal ( tmp [ 4 ] , tmp [ 1 ] ) ) {
if ( term_equal ( ( * ef8 ) ( ( * ef1 ) ( lf2 ( make_list ( atmp000 ) ) ) , ( * ef7 ) ( ( * ef6 ) ( lf5 ( make_list ( atmp2000 ) ) ) , ( * ef5 ) ( ( * ef6 ) ( lf5 ( cons ( make_list ( tmp [ 4 ] ) , make_list ( tmp [ 2 ] ) ) ) ) , atmp211 , atmp212 ) ) , ( * ef5 ) ( ( * ef6 ) ( lf5 ( make_list ( tmp [ 7 ] ) ) ) , tmp [ 4 ] , tmp [ 5 ] ) ) , ( constant0 ? constant0 : ( constant0 = ( * ef9 ) ( ) ) ) ) ) {
FUNC_EXIT ( ( * ef3 ) ( lf4 ( make_list ( ( * ef7 ) ( ( * ef6 ) ( lf5 ( make_list ( null ( ) ) ) ) , ( * ef5 ) ( ( * ef6 ) ( lf5 ( make_list ( tmp [ 7 ] ) ) ) , tmp [ 4 ] , tmp [ 5 ] ) ) ) ) ) ) ;
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
if ( not_empty_list ( atmp100 ) ) {
tmp [ 0 ] = list_head ( atmp100 ) ;
tmp [ 1 ] = list_tail ( atmp100 ) ;
if ( not_empty_list ( tmp [ 1 ] ) ) {
FUNC_EXIT ( ( * ef4 ) ( lf_AUX_Goto_PCC5_1 ( ( * ef1 ) ( lf2 ( make_list ( atmp000 ) ) ) , ( * ef2 ) ( lf3 ( make_list ( tmp [ 0 ] ) ) ) , arg2 ) , lf_AUX_Goto_PCC5_1 ( ( * ef1 ) ( lf2 ( make_list ( atmp000 ) ) ) , ( * ef2 ) ( lf3 ( make_list ( tmp [ 1 ] ) ) ) , arg2 ) ) ) ;
}
}
else {
FUNC_EXIT_CONST ( constant1 , ( * ef3 ) ( lf4 ( make_list ( null ( ) ) ) ) ) ;
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
if ( check_sym ( atmp00 , lf2sym ) ) {
{
ATerm atmp000 = arg_0 ( atmp00 ) ;
if ( check_sym ( arg1 , ef2sym ) ) {
{
ATerm atmp10 = arg_0 ( arg1 ) ;
if ( check_sym ( atmp10 , lf3sym ) ) {
{
ATerm atmp100 = arg_0 ( atmp10 ) ;
if ( is_single_element ( atmp100 ) ) {
tmp [ 0 ] = list_head ( atmp100 ) ;
FUNC_EXIT_CONST ( constant1 , ( * ef3 ) ( lf4 ( make_list ( null ( ) ) ) ) ) ;
}
}
}
}
}
}
}
}
}
FUNC_EXIT ( make_nf3 ( lf_AUX_Goto_PCC5_1sym , arg0 , arg1 , arg2 ) ) ;
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
ATerm lf5 ( ATerm arg0 ) {
CONS_ENTRY ( lf5sym , ATmakeAppl ( lf5sym , arg0 ) ) ;
CONS_EXIT ( make_nf1 ( lf5sym , arg0 ) ) ;
}

