#include  "asc-support.h"
static Symbol lf_AUX_Check_List_Pats27_2sym ;
static ATerm lf_AUX_Check_List_Pats27_2 ( ATerm arg1 ) ;
static Symbol ef2sym ;
static funcptr ef2 ;
static Symbol ef1sym ;
static funcptr ef1 ;
static Symbol lf_AUX_Check_List_Pats27_1sym ;
static ATerm lf_AUX_Check_List_Pats27_1 ( ATerm arg1 ) ;
void register_AUX_Check_List_Pats27 ( ) {
lf_AUX_Check_List_Pats27_2sym = ATmakeSymbol ( "prod(id(\"Check-List-Pats\"),w(\"\"),[l(\"contains-zero-or-one-list-vars-in-conds\"),w(\"\"),l(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Cond\"),w(\"\"),ql(\"&\"),w(\"\"),l(\"}\"),w(\"\"),l(\"+\")),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)"
 , 1 , ATtrue ) ;
ATprotectSymbol ( lf_AUX_Check_List_Pats27_2sym ) ;
lf_AUX_Check_List_Pats27_1sym = ATmakeSymbol ( "listtype(sort(\"Cond\"),ql(\"&\"))" , 1 , ATtrue ) ;
ATprotectSymbol ( lf_AUX_Check_List_Pats27_1sym ) ;
register_prod ( ATparse ( "listtype(sort(\"Cond\"),ql(\"&\"))" ) , lf_AUX_Check_List_Pats27_1 , lf_AUX_Check_List_Pats27_1sym ) ;
register_prod ( ATparse ( "prod(id(\"Check-List-Pats\"),w(\"\"),[l(\"contains-zero-or-one-list-vars-in-conds\"),w(\"\"),l(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Cond\"),w(\"\"),ql(\"&\"),w(\"\"),l(\"}\"),w(\"\"),l(\"+\")),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)" ) , lf_AUX_Check_List_Pats27_2 , lf_AUX_Check_List_Pats27_2sym ) ;
}
void resolve_AUX_Check_List_Pats27 ( ) {
ef1 = lookup_func ( ATreadFromString ( "prod(id(\"Check-List-Pats\"),w(\"\"),[l(\"contains-zero-or-one-list-vars-in-cond\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Cond\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)" ) ) ;
ef1sym = lookup_sym ( ATreadFromString ( "prod(id(\"Check-List-Pats\"),w(\"\"),[l(\"contains-zero-or-one-list-vars-in-cond\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Cond\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)" ) ) ;
ef2 = lookup_func ( ATreadFromString ( "prod(id(\"ATerm-Booleans\"),w(\"\"),[sort(\"Bool\"),w(\"\"),ql(\"\\\\\\\\/\"),w(\"\"),sort(\"Bool\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),attrs(l(\"{\"),w(\"\"),[l(\"assoc\")],w(\"\"),l(\"}\")))" ) ) ;
ef2sym = lookup_sym ( ATreadFromString ( "prod(id(\"ATerm-Booleans\"),w(\"\"),[sort(\"Bool\"),w(\"\"),ql(\"\\\\\\\\/\"),w(\"\"),sort(\"Bool\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),attrs(l(\"{\"),w(\"\"),[l(\"assoc\")],w(\"\"),l(\"}\")))" ) ) ;
}
void init_AUX_Check_List_Pats27 ( ) {
}
ATerm lf_AUX_Check_List_Pats27_2 ( ATerm arg0 ) {
{
ATerm tmp [ 2 ] ;
FUNC_ENTRY ( lf_AUX_Check_List_Pats27_2sym , ATmakeAppl ( lf_AUX_Check_List_Pats27_2sym , arg0 ) ) ;
if ( check_sym ( arg0 , lf_AUX_Check_List_Pats27_1sym ) ) {
{
ATerm atmp00 = arg_0 ( arg0 ) ;
if ( is_single_element ( atmp00 ) ) {
( tmp [ 0 ] = list_head ( atmp00 ) ) ;
FUNC_EXIT ( ( * ef1 ) ( tmp [ 0 ] ) ) ;
}
if ( not_empty_list ( atmp00 ) ) {
( tmp [ 0 ] = list_head ( atmp00 ) ) ;
( tmp [ 1 ] = list_tail ( atmp00 ) ) ;
if ( not_empty_list ( tmp [ 1 ] ) ) {
FUNC_EXIT ( ( * ef2 ) ( ( * ef1 ) ( tmp [ 0 ] ) , lf_AUX_Check_List_Pats27_2 ( lf_AUX_Check_List_Pats27_1 ( make_list ( tmp [ 1 ] ) ) ) ) ) ;
}
}
}
}
FUNC_EXIT ( make_nf1 ( lf_AUX_Check_List_Pats27_2sym , arg0 ) ) ;
}
}
ATerm lf_AUX_Check_List_Pats27_1 ( ATerm arg0 ) {
CONS_ENTRY ( lf_AUX_Check_List_Pats27_1sym , ATmakeAppl ( lf_AUX_Check_List_Pats27_1sym , arg0 ) ) ;
CONS_EXIT ( make_nf1 ( lf_AUX_Check_List_Pats27_1sym , arg0 ) ) ;
}

