#include  "asc-support.h"
static Symbol lf_AUX_Priority_Sdf_Normalization6_1sym ;
static ATerm lf_AUX_Priority_Sdf_Normalization6_1 ( ATerm arg1 ) ;
static Symbol ef5sym ;
static funcptr ef5 ;
static Symbol ef6sym ;
static funcptr ef6 ;
static Symbol ef1sym ;
static funcptr ef1 ;
static Symbol lf2sym ;
static ATerm lf2 ( ATerm arg1 ) ;
static Symbol ef4sym ;
static funcptr ef4 ;
static Symbol ef3sym ;
static funcptr ef3 ;
static Symbol ef2sym ;
static funcptr ef2 ;
static Symbol lf3sym ;
static ATerm lf3 ( ATerm arg1 ) ;
static Symbol ef8sym ;
static funcptr ef8 ;
static Symbol ef7sym ;
static funcptr ef7 ;
static Symbol lf4sym ;
static ATerm lf4 ( ATerm arg1 ) ;
void register_AUX_Priority_Sdf_Normalization6 ( ) {
lf_AUX_Priority_Sdf_Normalization6_1sym = ATmakeSymbol ( "prod(id(\"Priority-Sdf-Normalization\"),w(\"\"),[ql(\"norm\"),w(\"\"),ql(\"[[\"),w(\"\"),sort(\"Priorities\"),w(\"\"),ql(\"]]\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Priorities\"),w(\"\"),no-attrs)"
 , 1 , ATtrue ) ;
ATprotectSymbol ( lf_AUX_Priority_Sdf_Normalization6_1sym ) ;
lf2sym = ATmakeSymbol ( "listtype(sort(\"Priority\"),ql(\",\"))" , 1 , ATtrue ) ;
ATprotectSymbol ( lf2sym ) ;
lf3sym = ATmakeSymbol ( "listtype(sort(\"Group\"),ql(\">\"))" , 1 , ATtrue ) ;
ATprotectSymbol ( lf3sym ) ;
lf4sym = ATmakeSymbol ( "listtype(sort(\"Production\"))" , 1 , ATtrue ) ;
ATprotectSymbol ( lf4sym ) ;
register_prod ( ATparse ( "prod(id(\"Priority-Sdf-Normalization\"),w(\"\"),[ql(\"norm\"),w(\"\"),ql(\"[[\"),w(\"\"),sort(\"Priorities\"),w(\"\"),ql(\"]]\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Priorities\"),w(\"\"),no-attrs)" ) , lf_AUX_Priority_Sdf_Normalization6_1 , lf_AUX_Priority_Sdf_Normalization6_1sym ) ;
register_prod ( ATparse ( "listtype(sort(\"Priority\"),ql(\",\"))" ) , lf2 , lf2sym ) ;
register_prod ( ATparse ( "listtype(sort(\"Group\"),ql(\">\"))" ) , lf3 , lf3sym ) ;
register_prod ( ATparse ( "listtype(sort(\"Production\"))" ) , lf4 , lf4sym ) ;
}
void resolve_AUX_Priority_Sdf_Normalization6 ( ) {
ef1 = lookup_func ( ATreadFromString ( "prod(id(\"Priority-Sdf-Syntax\"),w(\"\"),[iter-sep(l(\"{\"),w(\"\"),sort(\"Priority\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\"))],w(\"\"),l(\"->\"),w(\"\"),sort(\"Priorities\"),w(\"\"),no-attrs)" ) ) ;
ef1sym = lookup_sym ( ATreadFromString ( "prod(id(\"Priority-Sdf-Syntax\"),w(\"\"),[iter-sep(l(\"{\"),w(\"\"),sort(\"Priority\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\"))],w(\"\"),l(\"->\"),w(\"\"),sort(\"Priorities\"),w(\"\"),no-attrs)" ) ) ;
ef2 = lookup_func ( ATreadFromString ( "prod(id(\"Priority-Sdf-Syntax\"),w(\"\"),[iter-sep(l(\"{\"),w(\"\"),sort(\"Group\"),w(\"\"),ql(\">\"),w(\"\"),l(\"}\"),w(\"\"),l(\"+\"))],w(\"\"),l(\"->\"),w(\"\"),sort(\"Priority\"),w(\"\"),no-attrs)" ) ) ;
ef2sym = lookup_sym ( ATreadFromString ( "prod(id(\"Priority-Sdf-Syntax\"),w(\"\"),[iter-sep(l(\"{\"),w(\"\"),sort(\"Group\"),w(\"\"),ql(\">\"),w(\"\"),l(\"}\"),w(\"\"),l(\"+\"))],w(\"\"),l(\"->\"),w(\"\"),sort(\"Priority\"),w(\"\"),no-attrs)" ) ) ;
ef3 = lookup_func ( ATreadFromString ( "prod(id(\"Priority-Sdf-Syntax\"),w(\"\"),[sort(\"Production\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Group\"),w(\"\"),no-attrs)" ) ) ;
ef3sym = lookup_sym ( ATreadFromString ( "prod(id(\"Priority-Sdf-Syntax\"),w(\"\"),[sort(\"Production\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Group\"),w(\"\"),no-attrs)" ) ) ;
ef4 = lookup_func ( ATreadFromString ( "prod(id(\"Priority-Sdf-Syntax\"),w(\"\"),[sort(\"Group\"),w(\"\"),sort(\"Associativity\"),w(\"\"),sort(\"Group\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Priority\"),w(\"\"),no-attrs)" ) ) ;
ef4sym = lookup_sym ( ATreadFromString ( "prod(id(\"Priority-Sdf-Syntax\"),w(\"\"),[sort(\"Group\"),w(\"\"),sort(\"Associativity\"),w(\"\"),sort(\"Group\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Priority\"),w(\"\"),no-attrs)" ) ) ;
ef5 = lookup_func ( ATreadFromString ( "prod(id(\"Priority-Sdf-Projection\"),w(\"\"),[sort(\"Priorities\"),w(\"\"),ql(\"++\"),w(\"\"),sort(\"Priorities\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Priorities\"),w(\"\"),attrs(l(\"{\"),w(\"\"),[l(\"assoc\")],w(\"\"),l(\"}\")))" ) ) ;
ef5sym = lookup_sym ( ATreadFromString ( "prod(id(\"Priority-Sdf-Projection\"),w(\"\"),[sort(\"Priorities\"),w(\"\"),ql(\"++\"),w(\"\"),sort(\"Priorities\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Priorities\"),w(\"\"),attrs(l(\"{\"),w(\"\"),[l(\"assoc\")],w(\"\"),l(\"}\")))" ) ) ;
ef6 = lookup_func ( ATreadFromString ( "prod(id(\"Priority-Sdf-Syntax\"),w(\"\"),[ql(\"{\"),w(\"\"),sort(\"Productions\"),w(\"\"),ql(\"}\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Group\"),w(\"\"),no-attrs)" ) ) ;
ef6sym = lookup_sym ( ATreadFromString ( "prod(id(\"Priority-Sdf-Syntax\"),w(\"\"),[ql(\"{\"),w(\"\"),sort(\"Productions\"),w(\"\"),ql(\"}\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Group\"),w(\"\"),no-attrs)" ) ) ;
ef7 = lookup_func ( ATreadFromString ( "prod(id(\"Kernel-Sdf-Syntax\"),w(\"\"),[iter(sort(\"Production\"),w(\"\"),l(\"*\"))],w(\"\"),l(\"->\"),w(\"\"),sort(\"Productions\"),w(\"\"),no-attrs)" ) ) ;
ef7sym = lookup_sym ( ATreadFromString ( "prod(id(\"Kernel-Sdf-Syntax\"),w(\"\"),[iter(sort(\"Production\"),w(\"\"),l(\"*\"))],w(\"\"),l(\"->\"),w(\"\"),sort(\"Productions\"),w(\"\"),no-attrs)" ) ) ;
ef8 = lookup_func ( ATreadFromString ( "prod(id(\"Priority-Sdf-Syntax\"),w(\"\"),[ql(\"{\"),w(\"\"),sort(\"Associativity\"),w(\"\"),ql(\":\"),w(\"\"),sort(\"Productions\"),w(\"\"),ql(\"}\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Group\"),w(\"\"),no-attrs)" ) ) ;
ef8sym = lookup_sym ( ATreadFromString ( "prod(id(\"Priority-Sdf-Syntax\"),w(\"\"),[ql(\"{\"),w(\"\"),sort(\"Associativity\"),w(\"\"),ql(\":\"),w(\"\"),sort(\"Productions\"),w(\"\"),ql(\"}\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Group\"),w(\"\"),no-attrs)" ) ) ;
}
static ATerm constant0 = NULL ;
void init_AUX_Priority_Sdf_Normalization6 ( ) {
ATprotect ( & constant0 ) ;
}
ATerm lf_AUX_Priority_Sdf_Normalization6_1 ( ATerm arg0 ) {
{
ATerm tmp [ 12 ] ;
FUNC_ENTRY ( lf_AUX_Priority_Sdf_Normalization6_1sym , ATmakeAppl ( lf_AUX_Priority_Sdf_Normalization6_1sym , arg0 ) ) ;
{
ATerm ltmp [ 1 ] ;
lbl_lf_AUX_Priority_Sdf_Normalization6_1 : ltmp [ 0 ] = arg0 ;
if ( check_sym ( ltmp [ 0 ] , ef1sym ) ) {
{
ATerm atmp00 = arg_0 ( arg0 ) ;
if ( check_sym ( atmp00 , lf2sym ) ) {
{
ATerm atmp000 = arg_0 ( atmp00 ) ;
if ( is_single_element ( atmp000 ) ) {
tmp [ 0 ] = list_head ( atmp000 ) ;
if ( check_sym ( tmp [ 0 ] , ef2sym ) ) {
tmp [ 1 ] = arg_0 ( tmp [ 0 ] ) ;
if ( check_sym ( tmp [ 1 ] , lf3sym ) ) {
tmp [ 2 ] = arg_0 ( tmp [ 1 ] ) ;
{
if ( not_empty_list ( tmp [ 2 ] ) ) {
tmp [ 3 ] = list_head ( tmp [ 2 ] ) ;
{
tmp [ 4 ] = list_tail ( tmp [ 2 ] ) ;
{
if ( is_single_element ( tmp [ 4 ] ) ) {
tmp [ 5 ] = list_head ( tmp [ 4 ] ) ;
if ( check_sym ( tmp [ 3 ] , ef8sym ) ) {
tmp [ 6 ] = arg_0 ( tmp [ 3 ] ) ;
tmp [ 7 ] = arg_1 ( tmp [ 3 ] ) ;
if ( check_sym ( tmp [ 7 ] , ef7sym ) ) {
tmp [ 8 ] = arg_0 ( tmp [ 7 ] ) ;
if ( check_sym ( tmp [ 8 ] , lf4sym ) ) {
tmp [ 9 ] = arg_0 ( tmp [ 8 ] ) ;
arg0 = ( * ef1 ) ( lf2 ( cons ( make_list ( ( * ef2 ) ( lf3 ( make_list ( ( * ef8 ) ( tmp [ 6 ] , ( * ef7 ) ( lf4 ( make_list ( tmp [ 9 ] ) ) ) ) ) ) ) ) , make_list ( ( * ef2 ) ( lf3 ( cons ( make_list ( ( * ef6 ) ( ( * ef7 ) ( lf4 ( make_list ( tmp [ 9 ] ) ) ) ) ) , make_list ( tmp [ 5 ] ) ) ) ) ) ) ) ) ;
goto lbl_lf_AUX_Priority_Sdf_Normalization6_1 ;
}
}
}
if ( check_sym ( tmp [ 3 ] , ef3sym ) ) {
tmp [ 6 ] = arg_0 ( tmp [ 3 ] ) ;
if ( check_sym ( tmp [ 5 ] , ef3sym ) ) {
tmp [ 7 ] = arg_0 ( tmp [ 5 ] ) ;
FUNC_EXIT ( ( * ef1 ) ( lf2 ( make_list ( ( * ef2 ) ( lf3 ( cons ( make_list ( ( * ef3 ) ( tmp [ 6 ] ) ) , make_list ( ( * ef3 ) ( tmp [ 7 ] ) ) ) ) ) ) ) ) ) ;
}
}
if ( check_sym ( tmp [ 3 ] , ef6sym ) ) {
tmp [ 6 ] = arg_0 ( tmp [ 3 ] ) ;
{
if ( check_sym ( tmp [ 6 ] , ef7sym ) ) {
tmp [ 7 ] = arg_0 ( tmp [ 6 ] ) ;
if ( check_sym ( tmp [ 7 ] , lf4sym ) ) {
tmp [ 8 ] = arg_0 ( tmp [ 7 ] ) ;
tmp [ 9 ] = tmp [ 8 ] ;
if ( not_empty_list ( tmp [ 8 ] ) ) {
tmp [ 8 ] = list_tail ( tmp [ 8 ] ) ;
tmp [ 10 ] = tmp [ 8 ] ;
while ( not_empty_list ( tmp [ 8 ] ) ) {
if ( not_empty_list ( tmp [ 8 ] ) ) {
arg0 = ( * ef1 ) ( lf2 ( cons ( make_list ( ( * ef2 ) ( lf3 ( cons ( make_list ( ( * ef6 ) ( ( * ef7 ) ( lf4 ( slice ( tmp [ 9 ] , tmp [ 10 ] ) ) ) ) ) , make_list ( tmp [ 5 ] ) ) ) ) ) , make_list ( ( * ef2 ) ( lf3 ( cons ( make_list ( ( * ef6 ) ( ( * ef7 ) ( lf4 ( tmp [ 8 ] ) ) ) ) , make_list ( tmp [ 5 ] ) ) ) ) ) ) ) ) ;
goto lbl_lf_AUX_Priority_Sdf_Normalization6_1 ;
}
tmp [ 10 ] = list_tail ( tmp [ 10 ] ) ;
tmp [ 8 ] = tmp [ 10 ] ;
}
}
}
if ( check_sym ( tmp [ 7 ] , lf4sym ) ) {
tmp [ 8 ] = arg_0 ( tmp [ 7 ] ) ;
{
if ( ! not_empty_list ( tmp [ 8 ] ) ) {
FUNC_EXIT_CONST ( constant0 , ( * ef1 ) ( lf2 ( make_list ( null ( ) ) ) ) ) ;
}
if ( is_single_element ( tmp [ 8 ] ) ) {
tmp [ 9 ] = list_head ( tmp [ 8 ] ) ;
arg0 = ( * ef1 ) ( lf2 ( make_list ( ( * ef2 ) ( lf3 ( cons ( make_list ( ( * ef3 ) ( tmp [ 9 ] ) ) , make_list ( tmp [ 5 ] ) ) ) ) ) ) ) ;
goto lbl_lf_AUX_Priority_Sdf_Normalization6_1 ;
}
}
}
}
}
}
if ( check_sym ( tmp [ 5 ] , ef8sym ) ) {
tmp [ 6 ] = arg_0 ( tmp [ 5 ] ) ;
tmp [ 7 ] = arg_1 ( tmp [ 5 ] ) ;
if ( check_sym ( tmp [ 7 ] , ef7sym ) ) {
tmp [ 8 ] = arg_0 ( tmp [ 7 ] ) ;
if ( check_sym ( tmp [ 8 ] , lf4sym ) ) {
tmp [ 9 ] = arg_0 ( tmp [ 8 ] ) ;
arg0 = ( * ef1 ) ( lf2 ( cons ( make_list ( ( * ef2 ) ( lf3 ( make_list ( ( * ef8 ) ( tmp [ 6 ] , ( * ef7 ) ( lf4 ( make_list ( tmp [ 9 ] ) ) ) ) ) ) ) ) , make_list ( ( * ef2 ) ( lf3 ( cons ( make_list ( tmp [ 3 ] ) , make_list ( ( * ef6 ) ( ( * ef7 ) ( lf4 ( make_list ( tmp [ 9 ] ) ) ) ) ) ) ) ) ) ) ) ) ;
goto lbl_lf_AUX_Priority_Sdf_Normalization6_1 ;
}
}
}
if ( check_sym ( tmp [ 5 ] , ef6sym ) ) {
tmp [ 6 ] = arg_0 ( tmp [ 5 ] ) ;
{
if ( check_sym ( tmp [ 6 ] , ef7sym ) ) {
tmp [ 7 ] = arg_0 ( tmp [ 6 ] ) ;
if ( check_sym ( tmp [ 7 ] , lf4sym ) ) {
tmp [ 8 ] = arg_0 ( tmp [ 7 ] ) ;
tmp [ 9 ] = tmp [ 8 ] ;
if ( not_empty_list ( tmp [ 8 ] ) ) {
tmp [ 8 ] = list_tail ( tmp [ 8 ] ) ;
tmp [ 10 ] = tmp [ 8 ] ;
while ( not_empty_list ( tmp [ 8 ] ) ) {
if ( not_empty_list ( tmp [ 8 ] ) ) {
arg0 = ( * ef1 ) ( lf2 ( cons ( make_list ( ( * ef2 ) ( lf3 ( cons ( make_list ( tmp [ 3 ] ) , make_list ( ( * ef6 ) ( ( * ef7 ) ( lf4 ( slice ( tmp [ 9 ] , tmp [ 10 ] ) ) ) ) ) ) ) ) ) , make_list ( ( * ef2 ) ( lf3 ( cons ( make_list ( tmp [ 3 ] ) , make_list ( ( * ef6 ) ( ( * ef7 ) ( lf4 ( tmp [ 8 ] ) ) ) ) ) ) ) ) ) ) ) ;
goto lbl_lf_AUX_Priority_Sdf_Normalization6_1 ;
}
tmp [ 10 ] = list_tail ( tmp [ 10 ] ) ;
tmp [ 8 ] = tmp [ 10 ] ;
}
}
}
if ( check_sym ( tmp [ 7 ] , lf4sym ) ) {
tmp [ 8 ] = arg_0 ( tmp [ 7 ] ) ;
{
if ( ! not_empty_list ( tmp [ 8 ] ) ) {
FUNC_EXIT_CONST ( constant0 , ( * ef1 ) ( lf2 ( make_list ( null ( ) ) ) ) ) ;
}
if ( is_single_element ( tmp [ 8 ] ) ) {
tmp [ 9 ] = list_head ( tmp [ 8 ] ) ;
arg0 = ( * ef1 ) ( lf2 ( make_list ( ( * ef2 ) ( lf3 ( cons ( make_list ( tmp [ 3 ] ) , make_list ( ( * ef3 ) ( tmp [ 9 ] ) ) ) ) ) ) ) ) ;
goto lbl_lf_AUX_Priority_Sdf_Normalization6_1 ;
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
{
if ( is_single_element ( tmp [ 2 ] ) ) {
tmp [ 3 ] = list_head ( tmp [ 2 ] ) ;
if ( check_sym ( tmp [ 3 ] , ef8sym ) ) {
tmp [ 4 ] = arg_0 ( tmp [ 3 ] ) ;
tmp [ 5 ] = arg_1 ( tmp [ 3 ] ) ;
{
if ( check_sym ( tmp [ 5 ] , ef7sym ) ) {
tmp [ 6 ] = arg_0 ( tmp [ 5 ] ) ;
{
if ( check_sym ( tmp [ 6 ] , lf4sym ) ) {
tmp [ 7 ] = arg_0 ( tmp [ 6 ] ) ;
{
if ( not_empty_list ( tmp [ 7 ] ) ) {
tmp [ 8 ] = list_head ( tmp [ 7 ] ) ;
{
tmp [ 9 ] = list_tail ( tmp [ 7 ] ) ;
{
if ( not_empty_list ( tmp [ 9 ] ) ) {
tmp [ 10 ] = list_head ( tmp [ 9 ] ) ;
tmp [ 11 ] = list_tail ( tmp [ 9 ] ) ;
if ( not_empty_list ( tmp [ 11 ] ) ) {
arg0 = ( * ef1 ) ( lf2 ( cons ( make_list ( ( * ef4 ) ( ( * ef3 ) ( tmp [ 8 ] ) , tmp [ 4 ] , ( * ef3 ) ( tmp [ 10 ] ) ) ) , cons ( make_list ( ( * ef2 ) ( lf3 ( make_list ( ( * ef8 ) ( tmp [ 4 ] , ( * ef7 ) ( lf4 ( cons ( make_list ( tmp [ 8 ] ) , make_list ( tmp [ 11 ] ) ) ) ) ) ) ) ) ) , make_list ( ( * ef2 ) ( lf3 ( make_list ( ( * ef8 ) ( tmp [ 4 ] , ( * ef7 ) ( lf4 ( cons ( make_list ( tmp [ 10 ] ) , make_list ( tmp [ 11 ] ) ) ) ) ) ) ) ) ) ) ) ) ) ;
goto lbl_lf_AUX_Priority_Sdf_Normalization6_1 ;
}
}
if ( is_single_element ( tmp [ 9 ] ) ) {
tmp [ 10 ] = list_head ( tmp [ 9 ] ) ;
FUNC_EXIT ( ( * ef1 ) ( lf2 ( make_list ( ( * ef4 ) ( ( * ef3 ) ( tmp [ 8 ] ) , tmp [ 4 ] , ( * ef3 ) ( tmp [ 10 ] ) ) ) ) ) ) ;
}
}
}
}
if ( is_single_element ( tmp [ 7 ] ) ) {
tmp [ 8 ] = list_head ( tmp [ 7 ] ) ;
FUNC_EXIT ( ( * ef1 ) ( lf2 ( make_list ( ( * ef4 ) ( ( * ef3 ) ( tmp [ 8 ] ) , tmp [ 4 ] , ( * ef3 ) ( tmp [ 8 ] ) ) ) ) ) ) ;
}
}
}
}
}
}
}
if ( check_sym ( tmp [ 3 ] , ef3sym ) ) {
tmp [ 4 ] = arg_0 ( tmp [ 3 ] ) ;
FUNC_EXIT_CONST ( constant0 , ( * ef1 ) ( lf2 ( make_list ( null ( ) ) ) ) ) ;
}
if ( check_sym ( tmp [ 3 ] , ef6sym ) ) {
tmp [ 4 ] = arg_0 ( tmp [ 3 ] ) ;
if ( check_sym ( tmp [ 4 ] , ef7sym ) ) {
tmp [ 5 ] = arg_0 ( tmp [ 4 ] ) ;
if ( check_sym ( tmp [ 5 ] , lf4sym ) ) {
tmp [ 6 ] = arg_0 ( tmp [ 5 ] ) ;
if ( is_single_element ( tmp [ 6 ] ) ) {
tmp [ 7 ] = list_head ( tmp [ 6 ] ) ;
FUNC_EXIT_CONST ( constant0 , ( * ef1 ) ( lf2 ( make_list ( null ( ) ) ) ) ) ;
}
}
}
}
}
}
}
}
if ( check_sym ( tmp [ 1 ] , lf3sym ) ) {
tmp [ 2 ] = arg_0 ( tmp [ 1 ] ) ;
tmp [ 3 ] = tmp [ 2 ] ;
if ( not_empty_list ( tmp [ 2 ] ) ) {
tmp [ 2 ] = list_tail ( tmp [ 2 ] ) ;
tmp [ 4 ] = tmp [ 2 ] ;
while ( not_empty_list ( tmp [ 2 ] ) ) {
tmp [ 5 ] = tmp [ 2 ] ;
if ( not_empty_list ( tmp [ 2 ] ) ) {
tmp [ 2 ] = list_tail ( tmp [ 2 ] ) ;
tmp [ 6 ] = tmp [ 2 ] ;
while ( not_empty_list ( tmp [ 2 ] ) ) {
if ( not_empty_list ( tmp [ 2 ] ) ) {
arg0 = ( * ef1 ) ( lf2 ( cons ( make_list ( ( * ef2 ) ( lf3 ( cons ( slice ( tmp [ 3 ] , tmp [ 4 ] ) , slice ( tmp [ 5 ] , tmp [ 6 ] ) ) ) ) ) , make_list ( ( * ef2 ) ( lf3 ( cons ( slice ( tmp [ 5 ] , tmp [ 6 ] ) , tmp [ 2 ] ) ) ) ) ) ) ) ;
goto lbl_lf_AUX_Priority_Sdf_Normalization6_1 ;
}
tmp [ 6 ] = list_tail ( tmp [ 6 ] ) ;
tmp [ 2 ] = tmp [ 6 ] ;
}
}
tmp [ 4 ] = list_tail ( tmp [ 4 ] ) ;
tmp [ 2 ] = tmp [ 4 ] ;
}
}
}
}
if ( check_sym ( tmp [ 0 ] , ef4sym ) ) {
tmp [ 1 ] = arg_0 ( tmp [ 0 ] ) ;
tmp [ 2 ] = arg_1 ( tmp [ 0 ] ) ;
tmp [ 3 ] = arg_2 ( tmp [ 0 ] ) ;
if ( check_sym ( tmp [ 1 ] , ef8sym ) ) {
tmp [ 4 ] = arg_0 ( tmp [ 1 ] ) ;
tmp [ 5 ] = arg_1 ( tmp [ 1 ] ) ;
if ( check_sym ( tmp [ 5 ] , ef7sym ) ) {
tmp [ 6 ] = arg_0 ( tmp [ 5 ] ) ;
if ( check_sym ( tmp [ 6 ] , lf4sym ) ) {
tmp [ 7 ] = arg_0 ( tmp [ 6 ] ) ;
arg0 = ( * ef1 ) ( lf2 ( cons ( make_list ( ( * ef2 ) ( lf3 ( make_list ( ( * ef8 ) ( tmp [ 4 ] , ( * ef7 ) ( lf4 ( make_list ( tmp [ 7 ] ) ) ) ) ) ) ) ) , make_list ( ( * ef4 ) ( ( * ef6 ) ( ( * ef7 ) ( lf4 ( make_list ( tmp [ 7 ] ) ) ) ) , tmp [ 2 ] , tmp [ 3 ] ) ) ) ) ) ;
goto lbl_lf_AUX_Priority_Sdf_Normalization6_1 ;
}
}
}
if ( check_sym ( tmp [ 1 ] , ef3sym ) ) {
tmp [ 4 ] = arg_0 ( tmp [ 1 ] ) ;
if ( check_sym ( tmp [ 3 ] , ef3sym ) ) {
tmp [ 5 ] = arg_0 ( tmp [ 3 ] ) ;
FUNC_EXIT ( ( * ef1 ) ( lf2 ( cons ( make_list ( ( * ef4 ) ( ( * ef3 ) ( tmp [ 4 ] ) , tmp [ 2 ] , ( * ef3 ) ( tmp [ 5 ] ) ) ) , make_list ( ( * ef4 ) ( ( * ef3 ) ( tmp [ 5 ] ) , tmp [ 2 ] , ( * ef3 ) ( tmp [ 4 ] ) ) ) ) ) ) ) ;
}
}
if ( check_sym ( tmp [ 1 ] , ef6sym ) ) {
tmp [ 4 ] = arg_0 ( tmp [ 1 ] ) ;
{
if ( check_sym ( tmp [ 4 ] , ef7sym ) ) {
tmp [ 5 ] = arg_0 ( tmp [ 4 ] ) ;
{
if ( check_sym ( tmp [ 5 ] , lf4sym ) ) {
tmp [ 6 ] = arg_0 ( tmp [ 5 ] ) ;
{
if ( ! not_empty_list ( tmp [ 6 ] ) ) {
arg0 = ( * ef1 ) ( lf2 ( make_list ( ( * ef2 ) ( lf3 ( make_list ( tmp [ 3 ] ) ) ) ) ) ) ;
goto lbl_lf_AUX_Priority_Sdf_Normalization6_1 ;
}
else {
tmp [ 7 ] = list_head ( tmp [ 6 ] ) ;
tmp [ 8 ] = list_tail ( tmp [ 6 ] ) ;
arg0 = ( * ef1 ) ( lf2 ( cons ( make_list ( ( * ef4 ) ( ( * ef3 ) ( tmp [ 7 ] ) , tmp [ 2 ] , tmp [ 3 ] ) ) , make_list ( ( * ef4 ) ( ( * ef6 ) ( ( * ef7 ) ( lf4 ( make_list ( tmp [ 8 ] ) ) ) ) , tmp [ 2 ] , tmp [ 3 ] ) ) ) ) ) ;
goto lbl_lf_AUX_Priority_Sdf_Normalization6_1 ;
}
}
}
}
}
}
}
if ( check_sym ( tmp [ 3 ] , ef6sym ) ) {
tmp [ 4 ] = arg_0 ( tmp [ 3 ] ) ;
{
if ( check_sym ( tmp [ 4 ] , ef7sym ) ) {
tmp [ 5 ] = arg_0 ( tmp [ 4 ] ) ;
{
if ( check_sym ( tmp [ 5 ] , lf4sym ) ) {
tmp [ 6 ] = arg_0 ( tmp [ 5 ] ) ;
{
if ( not_empty_list ( tmp [ 6 ] ) ) {
tmp [ 7 ] = list_head ( tmp [ 6 ] ) ;
tmp [ 8 ] = list_tail ( tmp [ 6 ] ) ;
arg0 = ( * ef1 ) ( lf2 ( cons ( make_list ( ( * ef4 ) ( tmp [ 1 ] , tmp [ 2 ] , ( * ef3 ) ( tmp [ 7 ] ) ) ) , make_list ( ( * ef4 ) ( tmp [ 1 ] , tmp [ 2 ] , ( * ef6 ) ( ( * ef7 ) ( lf4 ( make_list ( tmp [ 8 ] ) ) ) ) ) ) ) ) ) ;
goto lbl_lf_AUX_Priority_Sdf_Normalization6_1 ;
}
else {
arg0 = ( * ef1 ) ( lf2 ( make_list ( ( * ef2 ) ( lf3 ( make_list ( tmp [ 1 ] ) ) ) ) ) ) ;
goto lbl_lf_AUX_Priority_Sdf_Normalization6_1 ;
}
}
}
}
}
}
}
if ( check_sym ( tmp [ 3 ] , ef8sym ) ) {
tmp [ 4 ] = arg_0 ( tmp [ 3 ] ) ;
tmp [ 5 ] = arg_1 ( tmp [ 3 ] ) ;
if ( check_sym ( tmp [ 5 ] , ef7sym ) ) {
tmp [ 6 ] = arg_0 ( tmp [ 5 ] ) ;
if ( check_sym ( tmp [ 6 ] , lf4sym ) ) {
tmp [ 7 ] = arg_0 ( tmp [ 6 ] ) ;
arg0 = ( * ef1 ) ( lf2 ( cons ( make_list ( ( * ef2 ) ( lf3 ( make_list ( ( * ef8 ) ( tmp [ 4 ] , ( * ef7 ) ( lf4 ( make_list ( tmp [ 7 ] ) ) ) ) ) ) ) ) , make_list ( ( * ef4 ) ( tmp [ 1 ] , tmp [ 2 ] , ( * ef6 ) ( ( * ef7 ) ( lf4 ( make_list ( tmp [ 7 ] ) ) ) ) ) ) ) ) ) ;
goto lbl_lf_AUX_Priority_Sdf_Normalization6_1 ;
}
}
}
}
}
if ( ! not_empty_list ( atmp000 ) ) {
FUNC_EXIT_CONST ( constant0 , ( * ef1 ) ( lf2 ( make_list ( null ( ) ) ) ) ) ;
}
}
}
{
ATerm atmp00 = arg_0 ( arg0 ) ;
if ( check_sym ( atmp00 , lf2sym ) ) {
tmp [ 0 ] = arg_0 ( atmp00 ) ;
{
ATerm atmp0000 [ 2 ] ;
atmp0000 [ 0 ] = tmp [ 0 ] ;
if ( not_empty_list ( tmp [ 0 ] ) ) {
tmp [ 0 ] = list_tail ( tmp [ 0 ] ) ;
atmp0000 [ 1 ] = tmp [ 0 ] ;
while ( not_empty_list ( tmp [ 0 ] ) ) {
if ( not_empty_list ( tmp [ 0 ] ) ) {
FUNC_EXIT ( ( * ef5 ) ( lf_AUX_Priority_Sdf_Normalization6_1 ( ( * ef1 ) ( lf2 ( slice ( atmp0000 [ 0 ] , atmp0000 [ 1 ] ) ) ) ) , lf_AUX_Priority_Sdf_Normalization6_1 ( ( * ef1 ) ( lf2 ( tmp [ 0 ] ) ) ) ) ) ;
}
atmp0000 [ 1 ] = list_tail ( atmp0000 [ 1 ] ) ;
tmp [ 0 ] = atmp0000 [ 1 ] ;
}
}
}
}
}
}
}
FUNC_EXIT ( make_nf1 ( lf_AUX_Priority_Sdf_Normalization6_1sym , ltmp [ 0 ] ) ) ;
}
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

