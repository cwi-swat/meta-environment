#include  "support.h"
static Symbol lf_AUX_Actions3_1sym ;
static ATerm lf_AUX_Actions3_1 ( ATerm arg1 ) ;
static Symbol ef1sym ;
static funcptr ef1 ;
static Symbol lf2sym ;
static ATerm lf2 ( ATerm arg1 ) ;
void register_AUX_Actions3 ( ) {
lf_AUX_Actions3_1sym = ATmakeSymbol ( "prod(id(\"Actions\"),w(\"\"),[ql(\"{\"),w(\"\"),sort(\"Actions\"),w(\"\"),ql(\"}\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ActionSet\"),w(\"\"),no-attrs)"
 , 1 , ATtrue ) ;
ATprotectSymbol ( lf_AUX_Actions3_1sym ) ;
lf2sym = ATmakeSymbol ( "listtype(sort(\"Action\"))" , 1 , ATtrue ) ;
ATprotectSymbol ( lf2sym ) ;
register_prod ( ATparse ( "prod(id(\"Actions\"),w(\"\"),[ql(\"{\"),w(\"\"),sort(\"Actions\"),w(\"\"),ql(\"}\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ActionSet\"),w(\"\"),no-attrs)" ) , lf_AUX_Actions3_1 , lf_AUX_Actions3_1sym ) ;
register_prod ( ATparse ( "listtype(sort(\"Action\"))" ) , lf2 , lf2sym ) ;
}
void resolve_AUX_Actions3 ( ) {
ef1 = lookup_func ( ATreadFromString ( "prod(id(\"Actions\"),w(\"\"),[iter(sort(\"Action\"),w(\"\"),l(\"*\"))],w(\"\"),l(\"->\"),w(\"\"),sort(\"Actions\"),w(\"\"),no-attrs)" ) ) ;
ef1sym = lookup_sym ( ATreadFromString ( "prod(id(\"Actions\"),w(\"\"),[iter(sort(\"Action\"),w(\"\"),l(\"*\"))],w(\"\"),l(\"->\"),w(\"\"),sort(\"Actions\"),w(\"\"),no-attrs)" ) ) ;
}
void init_AUX_Actions3 ( ) {
}
ATerm lf_AUX_Actions3_1 ( ATerm arg0 ) {
{
ATerm tmp [ 1 ] ;
FUNC_ENTRY ( lf_AUX_Actions3_1sym , ATmakeAppl ( lf_AUX_Actions3_1sym , arg0 ) ) ;
lbl_lf_AUX_Actions3_1 : if ( check_sym ( arg0 , ef1sym ) ) {
{
ATerm atmp00 = arg_0 ( arg0 ) ;
if ( check_sym ( atmp00 , lf2sym ) ) {
tmp [ 0 ] = arg_0 ( atmp00 ) ;
{
ATerm atmp0001110 ;
ATerm atmp000110 [ 2 ] ;
ATerm atmp00010 ;
ATerm atmp0000 [ 2 ] ;
atmp0000 [ 0 ] = tmp [ 0 ] ;
atmp0000 [ 1 ] = tmp [ 0 ] ;
while ( not_empty_list ( tmp [ 0 ] ) ) {
atmp00010 = list_head ( tmp [ 0 ] ) ;
tmp [ 0 ] = list_tail ( tmp [ 0 ] ) ;
atmp000110 [ 0 ] = tmp [ 0 ] ;
atmp000110 [ 1 ] = tmp [ 0 ] ;
while ( not_empty_list ( tmp [ 0 ] ) ) {
atmp0001110 = list_head ( tmp [ 0 ] ) ;
tmp [ 0 ] = list_tail ( tmp [ 0 ] ) ;
if ( term_equal ( atmp00010 , atmp0001110 ) ) {
arg0 = ( * ef1 ) ( lf2 ( cons ( slice ( atmp0000 [ 0 ] , atmp0000 [ 1 ] ) , cons ( make_list ( atmp00010 ) , cons ( slice ( atmp000110 [ 0 ] , atmp000110 [ 1 ] ) , tmp [ 0 ] ) ) ) ) ) ;
goto lbl_lf_AUX_Actions3_1 ;
}
atmp000110 [ 1 ] = list_tail ( atmp000110 [ 1 ] ) ;
tmp [ 0 ] = atmp000110 [ 1 ] ;
}
atmp0000 [ 1 ] = list_tail ( atmp0000 [ 1 ] ) ;
tmp [ 0 ] = atmp0000 [ 1 ] ;
}
}
}
}
}
FUNC_EXIT ( make_nf1 ( lf_AUX_Actions3_1sym , arg0 ) ) ;
}
}
ATerm lf2 ( ATerm arg0 ) {
CONS_ENTRY ( lf2sym , ATmakeAppl ( lf2sym , arg0 ) ) ;
CONS_EXIT ( make_nf1 ( lf2sym , arg0 ) ) ;
}

