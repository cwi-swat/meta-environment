#include  "support.h"
static Symbol lf_AUX_Character_Class_Sets2_2sym ;
static ATerm lf_AUX_Character_Class_Sets2_2 ( ATerm arg1 ) ;
static Symbol ef1sym ;
static funcptr ef1 ;
static Symbol ef2sym ;
static funcptr ef2 ;
static Symbol lf_AUX_Character_Class_Sets2_1sym ;
static ATerm lf_AUX_Character_Class_Sets2_1 ( ATerm arg1 ) ;
void register_AUX_Character_Class_Sets2 ( ) {
lf_AUX_Character_Class_Sets2_2sym = ATmakeSymbol ( "prod(id(\"Character-Class-Sets\"),w(\"\"),[ql(\"{\"),w(\"\"),iter(sort(\"CharClass\"),w(\"\"),l(\"*\")),w(\"\"),ql(\"}\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"CharClassSet\"),w(\"\"),no-attrs)"
 , 1 , ATtrue ) ;
ATprotectSymbol ( lf_AUX_Character_Class_Sets2_2sym ) ;
lf_AUX_Character_Class_Sets2_1sym = ATmakeSymbol ( "listtype(sort(\"CharClass\"))" , 1 , ATtrue ) ;
ATprotectSymbol ( lf_AUX_Character_Class_Sets2_1sym ) ;
register_prod ( ATparse ( "listtype(sort(\"CharClass\"))" ) , lf_AUX_Character_Class_Sets2_1 , lf_AUX_Character_Class_Sets2_1sym ) ;
register_prod ( ATparse ( "prod(id(\"Character-Class-Sets\"),w(\"\"),[ql(\"{\"),w(\"\"),iter(sort(\"CharClass\"),w(\"\"),l(\"*\")),w(\"\"),ql(\"}\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"CharClassSet\"),w(\"\"),no-attrs)" ) , lf_AUX_Character_Class_Sets2_2 , lf_AUX_Character_Class_Sets2_2sym ) ;
}
void resolve_AUX_Character_Class_Sets2 ( ) {
ef1 = lookup_func ( ATreadFromString ( "prod(id(\"Character-Class-Syntax\"),w(\"\"),[ql(\"[\"),w(\"\"),sort(\"OptCharRanges\"),w(\"\"),ql(\"]\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"CharClass\"),w(\"\"),no-attrs)" ) ) ;
ef1sym = lookup_sym ( ATreadFromString ( "prod(id(\"Character-Class-Syntax\"),w(\"\"),[ql(\"[\"),w(\"\"),sort(\"OptCharRanges\"),w(\"\"),ql(\"]\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"CharClass\"),w(\"\"),no-attrs)" ) ) ;
ef2 = lookup_func ( ATreadFromString ( "prod(id(\"Character-Class-Syntax\"),w(\"\"),[],w(\"\"),l(\"->\"),w(\"\"),sort(\"OptCharRanges\"),w(\"\"),no-attrs)" ) ) ;
ef2sym = lookup_sym ( ATreadFromString ( "prod(id(\"Character-Class-Syntax\"),w(\"\"),[],w(\"\"),l(\"->\"),w(\"\"),sort(\"OptCharRanges\"),w(\"\"),no-attrs)" ) ) ;
}
void init_AUX_Character_Class_Sets2 ( ) {
}
ATerm lf_AUX_Character_Class_Sets2_2 ( ATerm arg0 ) {
{
ATerm tmp [ 2 ] ;
FUNC_ENTRY ( lf_AUX_Character_Class_Sets2_2sym , ATmakeAppl ( lf_AUX_Character_Class_Sets2_2sym , arg0 ) ) ;
lbl_lf_AUX_Character_Class_Sets2_2 : if ( check_sym ( arg0 , lf_AUX_Character_Class_Sets2_1sym ) ) {
tmp [ 0 ] = arg_0 ( arg0 ) ;
{
ATerm atmp0010 ;
ATerm atmp000 [ 2 ] ;
atmp000 [ 0 ] = tmp [ 0 ] ;
atmp000 [ 1 ] = tmp [ 0 ] ;
while ( not_empty_list ( tmp [ 0 ] ) ) {
atmp0010 = list_head ( tmp [ 0 ] ) ;
tmp [ 0 ] = list_tail ( tmp [ 0 ] ) ;
if ( check_sym ( atmp0010 , ef1sym ) ) {
tmp [ 1 ] = arg_0 ( atmp0010 ) ;
if ( term_equal ( tmp [ 1 ] , ( * ef2 ) ( ) ) ) {
arg0 = lf_AUX_Character_Class_Sets2_1 ( cons ( slice ( atmp000 [ 0 ] , atmp000 [ 1 ] ) , tmp [ 0 ] ) ) ;
goto lbl_lf_AUX_Character_Class_Sets2_2 ;
}
}
atmp000 [ 1 ] = list_tail ( atmp000 [ 1 ] ) ;
tmp [ 0 ] = atmp000 [ 1 ] ;
}
}
}
FUNC_EXIT ( make_nf1 ( lf_AUX_Character_Class_Sets2_2sym , arg0 ) ) ;
}
}
ATerm lf_AUX_Character_Class_Sets2_1 ( ATerm arg0 ) {
CONS_ENTRY ( lf_AUX_Character_Class_Sets2_1sym , ATmakeAppl ( lf_AUX_Character_Class_Sets2_1sym , arg0 ) ) ;
CONS_EXIT ( make_nf1 ( lf_AUX_Character_Class_Sets2_1sym , arg0 ) ) ;
}

