#include  "asc-support.h"
static Symbol lf_AUX_Restrictions_Sdf_Syntax6_2sym ;
static ATerm lf_AUX_Restrictions_Sdf_Syntax6_2 ( ATerm arg1 ) ;
static Symbol ef3sym ;
static funcptr ef3 ;
static Symbol ef1sym ;
static funcptr ef1 ;
static Symbol ef2sym ;
static funcptr ef2 ;
static Symbol lf3sym ;
static ATerm lf3 ( ATerm arg1 ) ;
static Symbol lf_AUX_Restrictions_Sdf_Syntax6_1sym ;
static ATerm lf_AUX_Restrictions_Sdf_Syntax6_1 ( ATerm arg1 ) ;
void register_AUX_Restrictions_Sdf_Syntax6 ( ) {
lf_AUX_Restrictions_Sdf_Syntax6_2sym = ATmakeSymbol ( "prod(id(\"Restrictions-Sdf-Syntax\"),w(\"\"),[iter(sort(\"Restriction\"),w(\"\"),l(\"*\"))],w(\"\"),l(\"->\"),w(\"\"),sort(\"Restrictions\"),w(\"\"),no-attrs)"
 , 1 , ATtrue ) ;
ATprotectSymbol ( lf_AUX_Restrictions_Sdf_Syntax6_2sym ) ;
lf3sym = ATmakeSymbol ( "listtype(sort(\"Symbol\"))" , 1 , ATtrue ) ;
ATprotectSymbol ( lf3sym ) ;
lf_AUX_Restrictions_Sdf_Syntax6_1sym = ATmakeSymbol ( "listtype(sort(\"Restriction\"))" , 1 , ATtrue ) ;
ATprotectSymbol ( lf_AUX_Restrictions_Sdf_Syntax6_1sym ) ;
register_prod ( ATparse ( "listtype(sort(\"Restriction\"))" ) , lf_AUX_Restrictions_Sdf_Syntax6_1 , lf_AUX_Restrictions_Sdf_Syntax6_1sym ) ;
register_prod ( ATparse ( "prod(id(\"Restrictions-Sdf-Syntax\"),w(\"\"),[iter(sort(\"Restriction\"),w(\"\"),l(\"*\"))],w(\"\"),l(\"->\"),w(\"\"),sort(\"Restrictions\"),w(\"\"),no-attrs)" ) , lf_AUX_Restrictions_Sdf_Syntax6_2 , lf_AUX_Restrictions_Sdf_Syntax6_2sym ) ;
register_prod ( ATparse ( "listtype(sort(\"Symbol\"))" ) , lf3 , lf3sym ) ;
}
void resolve_AUX_Restrictions_Sdf_Syntax6 ( ) {
ef1 = lookup_func ( ATreadFromString ( "prod(id(\"Restrictions-Sdf-Syntax\"),w(\"\"),[sort(\"Symbols\"),w(\"\"),ql(\"-/-\"),w(\"\"),sort(\"Lookaheads\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Restriction\"),w(\"\"),no-attrs)" ) ) ;
ef1sym = lookup_sym ( ATreadFromString ( "prod(id(\"Restrictions-Sdf-Syntax\"),w(\"\"),[sort(\"Symbols\"),w(\"\"),ql(\"-/-\"),w(\"\"),sort(\"Lookaheads\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Restriction\"),w(\"\"),no-attrs)" ) ) ;
ef2 = lookup_func ( ATreadFromString ( "prod(id(\"Symbols\"),w(\"\"),[iter(sort(\"Symbol\"),w(\"\"),l(\"*\"))],w(\"\"),l(\"->\"),w(\"\"),sort(\"Symbols\"),w(\"\"),no-attrs)" ) ) ;
ef2sym = lookup_sym ( ATreadFromString ( "prod(id(\"Symbols\"),w(\"\"),[iter(sort(\"Symbol\"),w(\"\"),l(\"*\"))],w(\"\"),l(\"->\"),w(\"\"),sort(\"Symbols\"),w(\"\"),no-attrs)" ) ) ;
ef3 = lookup_func ( ATreadFromString ( "prod(id(\"Restrictions-Sdf-Syntax\"),w(\"\"),[sort(\"Lookaheads\"),w(\"\"),ql(\"|\"),w(\"\"),sort(\"Lookaheads\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Lookaheads\"),w(\"\"),attrs(l(\"{\"),w(\"\"),[l(\"right\")],w(\"\"),l(\"}\")))" ) ) ;
ef3sym = lookup_sym ( ATreadFromString ( "prod(id(\"Restrictions-Sdf-Syntax\"),w(\"\"),[sort(\"Lookaheads\"),w(\"\"),ql(\"|\"),w(\"\"),sort(\"Lookaheads\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Lookaheads\"),w(\"\"),attrs(l(\"{\"),w(\"\"),[l(\"right\")],w(\"\"),l(\"}\")))" ) ) ;
}
void init_AUX_Restrictions_Sdf_Syntax6 ( ) {
}
ATerm lf_AUX_Restrictions_Sdf_Syntax6_2 ( ATerm arg0 ) {
{
ATerm tmp [ 19 ] ;
FUNC_ENTRY ( lf_AUX_Restrictions_Sdf_Syntax6_2sym , ATmakeAppl ( lf_AUX_Restrictions_Sdf_Syntax6_2sym , arg0 ) ) ;
{
ATerm ltmp [ 1 ] ;
lbl_lf_AUX_Restrictions_Sdf_Syntax6_2 : ltmp [ 0 ] = arg0 ;
if ( check_sym ( ltmp [ 0 ] , lf_AUX_Restrictions_Sdf_Syntax6_1sym ) ) {
tmp [ 0 ] = arg_0 ( ltmp [ 0 ] ) ;
{
ATerm atmp001110 ;
ATerm atmp00110 [ 2 ] ;
ATerm atmp0010 ;
ATerm atmp000 [ 2 ] ;
atmp000 [ 0 ] = tmp [ 0 ] ;
atmp000 [ 1 ] = tmp [ 0 ] ;
while ( not_empty_list ( tmp [ 0 ] ) ) {
atmp0010 = list_head ( tmp [ 0 ] ) ;
tmp [ 0 ] = list_tail ( tmp [ 0 ] ) ;
atmp00110 [ 0 ] = tmp [ 0 ] ;
atmp00110 [ 1 ] = tmp [ 0 ] ;
while ( not_empty_list ( tmp [ 0 ] ) ) {
atmp001110 = list_head ( tmp [ 0 ] ) ;
tmp [ 0 ] = list_tail ( tmp [ 0 ] ) ;
if ( check_sym ( atmp0010 , ef1sym ) ) {
tmp [ 1 ] = arg_0 ( atmp0010 ) ;
tmp [ 2 ] = arg_1 ( atmp0010 ) ;
if ( check_sym ( tmp [ 1 ] , ef2sym ) ) {
tmp [ 3 ] = arg_0 ( tmp [ 1 ] ) ;
if ( check_sym ( tmp [ 3 ] , lf3sym ) ) {
tmp [ 4 ] = arg_0 ( tmp [ 3 ] ) ;
tmp [ 5 ] = tmp [ 4 ] ;
tmp [ 6 ] = tmp [ 4 ] ;
while ( not_empty_list ( tmp [ 4 ] ) ) {
tmp [ 7 ] = list_head ( tmp [ 4 ] ) ;
tmp [ 4 ] = list_tail ( tmp [ 4 ] ) ;
if ( check_sym ( atmp001110 , ef1sym ) ) {
tmp [ 8 ] = arg_0 ( atmp001110 ) ;
tmp [ 9 ] = arg_1 ( atmp001110 ) ;
if ( check_sym ( tmp [ 8 ] , ef2sym ) ) {
tmp [ 10 ] = arg_0 ( tmp [ 8 ] ) ;
if ( check_sym ( tmp [ 10 ] , lf3sym ) ) {
tmp [ 11 ] = arg_0 ( tmp [ 10 ] ) ;
tmp [ 12 ] = tmp [ 11 ] ;
tmp [ 13 ] = tmp [ 11 ] ;
while ( not_empty_list ( tmp [ 11 ] ) ) {
tmp [ 14 ] = list_head ( tmp [ 11 ] ) ;
tmp [ 11 ] = list_tail ( tmp [ 11 ] ) ;
if ( term_equal ( tmp [ 7 ] , tmp [ 14 ] ) ) {
arg0 = lf_AUX_Restrictions_Sdf_Syntax6_1 ( cons ( slice ( atmp000 [ 0 ] , atmp000 [ 1 ] ) , cons ( make_list ( ( * ef1 ) ( ( * ef2 ) ( lf3 ( make_list ( tmp [ 7 ] ) ) ) , ( * ef3 ) ( tmp [ 2 ] , tmp [ 9 ] ) ) ) , cons ( make_list ( ( * ef1 ) ( ( * ef2 ) ( lf3 ( cons ( slice ( tmp [ 5 ] , tmp [ 6 ] ) , tmp [ 4 ] ) ) ) , tmp [ 2 ] ) ) , cons ( slice ( atmp00110 [ 0 ] , atmp00110 [ 1 ] ) , cons ( make_list ( ( * ef1 ) ( ( * ef2 ) ( lf3 ( cons ( slice ( tmp [ 12 ] , tmp [ 13 ] ) , tmp [ 11 ] ) ) ) , tmp [ 9 ] ) ) , tmp [ 0 ] ) ) ) ) ) ) ;
goto lbl_lf_AUX_Restrictions_Sdf_Syntax6_2 ;
}
tmp [ 13 ] = list_tail ( tmp [ 13 ] ) ;
tmp [ 11 ] = tmp [ 13 ] ;
}
}
}
}
tmp [ 6 ] = list_tail ( tmp [ 6 ] ) ;
tmp [ 4 ] = tmp [ 6 ] ;
}
}
}
}
atmp00110 [ 1 ] = list_tail ( atmp00110 [ 1 ] ) ;
tmp [ 0 ] = atmp00110 [ 1 ] ;
}
atmp000 [ 1 ] = list_tail ( atmp000 [ 1 ] ) ;
tmp [ 0 ] = atmp000 [ 1 ] ;
}
}
tmp [ 0 ] = arg_0 ( ltmp [ 0 ] ) ;
{
ATerm atmp0010 ;
ATerm atmp000 [ 2 ] ;
atmp000 [ 0 ] = tmp [ 0 ] ;
atmp000 [ 1 ] = tmp [ 0 ] ;
while ( not_empty_list ( tmp [ 0 ] ) ) {
atmp0010 = list_head ( tmp [ 0 ] ) ;
tmp [ 0 ] = list_tail ( tmp [ 0 ] ) ;
if ( check_sym ( atmp0010 , ef1sym ) ) {
tmp [ 15 ] = arg_0 ( atmp0010 ) ;
tmp [ 16 ] = arg_1 ( atmp0010 ) ;
if ( check_sym ( tmp [ 15 ] , ef2sym ) ) {
tmp [ 17 ] = arg_0 ( tmp [ 15 ] ) ;
if ( check_sym ( tmp [ 17 ] , lf3sym ) ) {
tmp [ 18 ] = arg_0 ( tmp [ 17 ] ) ;
if ( ! not_empty_list ( tmp [ 18 ] ) ) {
arg0 = lf_AUX_Restrictions_Sdf_Syntax6_1 ( cons ( slice ( atmp000 [ 0 ] , atmp000 [ 1 ] ) , tmp [ 0 ] ) ) ;
goto lbl_lf_AUX_Restrictions_Sdf_Syntax6_2 ;
}
}
}
}
atmp000 [ 1 ] = list_tail ( atmp000 [ 1 ] ) ;
tmp [ 0 ] = atmp000 [ 1 ] ;
}
}
}
FUNC_EXIT ( make_nf1 ( lf_AUX_Restrictions_Sdf_Syntax6_2sym , ltmp [ 0 ] ) ) ;
}
}
}
ATerm lf_AUX_Restrictions_Sdf_Syntax6_1 ( ATerm arg0 ) {
CONS_ENTRY ( lf_AUX_Restrictions_Sdf_Syntax6_1sym , ATmakeAppl ( lf_AUX_Restrictions_Sdf_Syntax6_1sym , arg0 ) ) ;
CONS_EXIT ( make_nf1 ( lf_AUX_Restrictions_Sdf_Syntax6_1sym , arg0 ) ) ;
}
ATerm lf3 ( ATerm arg0 ) {
CONS_ENTRY ( lf3sym , ATmakeAppl ( lf3sym , arg0 ) ) ;
CONS_EXIT ( make_nf1 ( lf3sym , arg0 ) ) ;
}

