#include  "asc-support.h"
static Symbol lf_AUX_Sdf2_Normalization6_1sym ;
static ATerm lf_AUX_Sdf2_Normalization6_1 ( ATerm arg1 ) ;
static Symbol ef2sym ;
static funcptr ef2 ;
static Symbol ef3sym ;
static funcptr ef3 ;
static Symbol lf3sym ;
static ATerm lf3 ( ATerm arg1 ) ;
static Symbol ef1sym ;
static funcptr ef1 ;
static Symbol lf2sym ;
static ATerm lf2 ( ATerm arg1 ) ;
static Symbol ef6sym ;
static funcptr ef6 ;
static Symbol ef4sym ;
static funcptr ef4 ;
static Symbol ef5sym ;
static funcptr ef5 ;
void register_AUX_Sdf2_Normalization6 ( ) {
lf_AUX_Sdf2_Normalization6_1sym = ATmakeSymbol ( "prod(id(\"Sdf2-Normalization\"),w(\"\"),[ql(\"<\"),w(\"\"),sort(\"Priorities\"),w(\"\"),ql(\"-CFp\"),w(\"\"),ql(\">\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Priorities\"),w(\"\"),no-attrs)"
 , 1 , ATtrue ) ;
ATprotectSymbol ( lf_AUX_Sdf2_Normalization6_1sym ) ;
lf3sym = ATmakeSymbol ( "listtype(sort(\"Group\"),ql(\">\"))" , 1 , ATtrue ) ;
ATprotectSymbol ( lf3sym ) ;
lf2sym = ATmakeSymbol ( "listtype(sort(\"Priority\"),ql(\",\"))" , 1 , ATtrue ) ;
ATprotectSymbol ( lf2sym ) ;
register_prod ( ATparse ( "prod(id(\"Sdf2-Normalization\"),w(\"\"),[ql(\"<\"),w(\"\"),sort(\"Priorities\"),w(\"\"),ql(\"-CFp\"),w(\"\"),ql(\">\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Priorities\"),w(\"\"),no-attrs)" ) , lf_AUX_Sdf2_Normalization6_1 , lf_AUX_Sdf2_Normalization6_1sym ) ;
register_prod ( ATparse ( "listtype(sort(\"Priority\"),ql(\",\"))" ) , lf2 , lf2sym ) ;
register_prod ( ATparse ( "listtype(sort(\"Group\"),ql(\">\"))" ) , lf3 , lf3sym ) ;
}
void resolve_AUX_Sdf2_Normalization6 ( ) {
ef1 = lookup_func ( ATreadFromString ( "prod(id(\"Priority-Sdf-Syntax\"),w(\"\"),[iter-sep(l(\"{\"),w(\"\"),sort(\"Priority\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\"))],w(\"\"),l(\"->\"),w(\"\"),sort(\"Priorities\"),w(\"\"),no-attrs)" ) ) ;
ef1sym = lookup_sym ( ATreadFromString ( "prod(id(\"Priority-Sdf-Syntax\"),w(\"\"),[iter-sep(l(\"{\"),w(\"\"),sort(\"Priority\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\"))],w(\"\"),l(\"->\"),w(\"\"),sort(\"Priorities\"),w(\"\"),no-attrs)" ) ) ;
ef2 = lookup_func ( ATreadFromString ( "prod(id(\"Priority-Sdf-Projection\"),w(\"\"),[sort(\"Priorities\"),w(\"\"),ql(\"++\"),w(\"\"),sort(\"Priorities\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Priorities\"),w(\"\"),attrs(l(\"{\"),w(\"\"),[l(\"assoc\")],w(\"\"),l(\"}\")))" ) ) ;
ef2sym = lookup_sym ( ATreadFromString ( "prod(id(\"Priority-Sdf-Projection\"),w(\"\"),[sort(\"Priorities\"),w(\"\"),ql(\"++\"),w(\"\"),sort(\"Priorities\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Priorities\"),w(\"\"),attrs(l(\"{\"),w(\"\"),[l(\"assoc\")],w(\"\"),l(\"}\")))" ) ) ;
ef3 = lookup_func ( ATreadFromString ( "prod(id(\"Priority-Sdf-Syntax\"),w(\"\"),[iter-sep(l(\"{\"),w(\"\"),sort(\"Group\"),w(\"\"),ql(\">\"),w(\"\"),l(\"}\"),w(\"\"),l(\"+\"))],w(\"\"),l(\"->\"),w(\"\"),sort(\"Priority\"),w(\"\"),no-attrs)" ) ) ;
ef3sym = lookup_sym ( ATreadFromString ( "prod(id(\"Priority-Sdf-Syntax\"),w(\"\"),[iter-sep(l(\"{\"),w(\"\"),sort(\"Group\"),w(\"\"),ql(\">\"),w(\"\"),l(\"}\"),w(\"\"),l(\"+\"))],w(\"\"),l(\"->\"),w(\"\"),sort(\"Priority\"),w(\"\"),no-attrs)" ) ) ;
ef4 = lookup_func ( ATreadFromString ( "prod(id(\"Priority-Sdf-Syntax\"),w(\"\"),[sort(\"Production\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Group\"),w(\"\"),no-attrs)" ) ) ;
ef4sym = lookup_sym ( ATreadFromString ( "prod(id(\"Priority-Sdf-Syntax\"),w(\"\"),[sort(\"Production\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Group\"),w(\"\"),no-attrs)" ) ) ;
ef5 = lookup_func ( ATreadFromString ( "prod(id(\"Basic-Sdf-Normalization\"),w(\"\"),[ql(\"<\"),w(\"\"),sort(\"Production\"),w(\"\"),ql(\"-CF\"),w(\"\"),ql(\">\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Production\"),w(\"\"),no-attrs)" ) ) ;
ef5sym = lookup_sym ( ATreadFromString ( "prod(id(\"Basic-Sdf-Normalization\"),w(\"\"),[ql(\"<\"),w(\"\"),sort(\"Production\"),w(\"\"),ql(\"-CF\"),w(\"\"),ql(\">\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Production\"),w(\"\"),no-attrs)" ) ) ;
ef6 = lookup_func ( ATreadFromString ( "prod(id(\"Priority-Sdf-Syntax\"),w(\"\"),[sort(\"Group\"),w(\"\"),sort(\"Associativity\"),w(\"\"),sort(\"Group\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Priority\"),w(\"\"),no-attrs)" ) ) ;
ef6sym = lookup_sym ( ATreadFromString ( "prod(id(\"Priority-Sdf-Syntax\"),w(\"\"),[sort(\"Group\"),w(\"\"),sort(\"Associativity\"),w(\"\"),sort(\"Group\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Priority\"),w(\"\"),no-attrs)" ) ) ;
}
static ATerm constant0 = NULL ;
void init_AUX_Sdf2_Normalization6 ( ) {
ATprotect ( & constant0 ) ;
}
ATerm lf_AUX_Sdf2_Normalization6_1 ( ATerm arg0 ) {
{
ATerm tmp [ 8 ] ;
FUNC_ENTRY ( lf_AUX_Sdf2_Normalization6_1sym , ATmakeAppl ( lf_AUX_Sdf2_Normalization6_1sym , arg0 ) ) ;
if ( check_sym ( arg0 , ef1sym ) ) {
{
ATerm atmp00 = arg_0 ( arg0 ) ;
if ( check_sym ( atmp00 , lf2sym ) ) {
{
ATerm atmp000 = arg_0 ( atmp00 ) ;
if ( term_equal ( ( * ef1 ) ( lf2 ( make_list ( atmp000 ) ) ) , ( constant0 ? constant0 : ( constant0 = ( * ef1 ) ( lf2 ( make_list ( null ( ) ) ) ) ) ) ) ) {
FUNC_EXIT_CONST ( constant0 , ( * ef1 ) ( lf2 ( make_list ( null ( ) ) ) ) ) ;
}
{
if ( is_single_element ( atmp000 ) ) {
tmp [ 0 ] = list_head ( atmp000 ) ;
if ( check_sym ( tmp [ 0 ] , ef6sym ) ) {
tmp [ 1 ] = arg_0 ( tmp [ 0 ] ) ;
tmp [ 2 ] = arg_1 ( tmp [ 0 ] ) ;
tmp [ 3 ] = arg_2 ( tmp [ 0 ] ) ;
if ( check_sym ( tmp [ 1 ] , ef4sym ) ) {
tmp [ 4 ] = arg_0 ( tmp [ 1 ] ) ;
if ( check_sym ( tmp [ 3 ] , ef4sym ) ) {
tmp [ 5 ] = arg_0 ( tmp [ 3 ] ) ;
FUNC_EXIT ( ( * ef1 ) ( lf2 ( make_list ( ( * ef6 ) ( ( * ef4 ) ( ( * ef5 ) ( tmp [ 4 ] ) ) , tmp [ 2 ] , ( * ef4 ) ( ( * ef5 ) ( tmp [ 5 ] ) ) ) ) ) ) ) ;
}
}
}
if ( check_sym ( tmp [ 0 ] , ef3sym ) ) {
tmp [ 1 ] = arg_0 ( tmp [ 0 ] ) ;
if ( check_sym ( tmp [ 1 ] , lf3sym ) ) {
tmp [ 2 ] = arg_0 ( tmp [ 1 ] ) ;
if ( not_empty_list ( tmp [ 2 ] ) ) {
tmp [ 3 ] = list_head ( tmp [ 2 ] ) ;
tmp [ 4 ] = list_tail ( tmp [ 2 ] ) ;
if ( is_single_element ( tmp [ 4 ] ) ) {
tmp [ 5 ] = list_head ( tmp [ 4 ] ) ;
if ( check_sym ( tmp [ 3 ] , ef4sym ) ) {
tmp [ 6 ] = arg_0 ( tmp [ 3 ] ) ;
if ( check_sym ( tmp [ 5 ] , ef4sym ) ) {
tmp [ 7 ] = arg_0 ( tmp [ 5 ] ) ;
FUNC_EXIT ( ( * ef1 ) ( lf2 ( make_list ( ( * ef3 ) ( lf3 ( cons ( make_list ( ( * ef4 ) ( ( * ef5 ) ( tmp [ 6 ] ) ) ) , make_list ( ( * ef4 ) ( ( * ef5 ) ( tmp [ 7 ] ) ) ) ) ) ) ) ) ) ) ;
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
FUNC_EXIT ( ( * ef2 ) ( lf_AUX_Sdf2_Normalization6_1 ( ( * ef1 ) ( lf2 ( slice ( atmp0000 [ 0 ] , atmp0000 [ 1 ] ) ) ) ) , lf_AUX_Sdf2_Normalization6_1 ( ( * ef1 ) ( lf2 ( tmp [ 0 ] ) ) ) ) ) ;
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
FUNC_EXIT ( make_nf1 ( lf_AUX_Sdf2_Normalization6_1sym , arg0 ) ) ;
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

